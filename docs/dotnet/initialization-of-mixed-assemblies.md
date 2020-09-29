---
title: Inicialização de assemblies mistos
description: Lidar com problemas que podem ocorrer durante o carregamento e a inicialização de assemblies mistos.
ms.date: 09/26/2020
helpviewer_keywords:
- mixed assemblies [C++], loader lock
- loader lock [C++]
- initializing mixed assemblies
- deadlocks [C++]
- .cctor [C++]
- custom locales [C++]
- mixed assemblies [C++], initilizing
ms.assetid: bfab7d9e-f323-4404-bcb8-712b15f831eb
ms.openlocfilehash: 6767e6087999138f8e62d3c5a58f972b4e2149ed
ms.sourcegitcommit: 94893973211d0b254c8bcdcf0779997dcc136b0c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/28/2020
ms.locfileid: "91413808"
---
# <a name="initialization-of-mixed-assemblies"></a>Inicialização de assemblies mistos

Os desenvolvedores do Windows sempre devem ter cuidado com o bloqueio do carregador durante a execução do código durante `DllMain` . No entanto, há alguns problemas adicionais a serem considerados ao lidar com assemblies de modo misto C++/CLI.

O código no [DllMain](/windows/win32/Dlls/dllmain) não deve acessar o CLR (Common Language Runtime) do .net. Isso significa que `DllMain` não deve fazer chamadas para funções gerenciadas, direta ou indiretamente; nenhum código gerenciado deve ser declarado ou implementado em `DllMain` ; e nenhuma coleta de lixo ou carregamento de biblioteca automático deve ocorrer no `DllMain` .

## <a name="causes-of-loader-lock"></a>Causas do bloqueio do carregador

Com a introdução da plataforma .NET, há dois mecanismos distintos para carregar um módulo de execução (EXE ou DLL): um para o Windows, que é usado para módulos não gerenciados e outro para o CLR, que carrega os assemblies .NET. O problema de carregamento de DLL misto é centralizado em todo o carregador de sistema operacional do Microsoft Windows.

Quando um assembly que contém apenas construções .NET é carregado em um processo, o carregador de CLR pode fazer todas as tarefas necessárias de carregamento e inicialização. No entanto, para carregar assemblies mistos que podem conter código nativo e dados, o carregador do Windows também deve ser usado.

O carregador do Windows garante que nenhum código possa acessar o código ou os dados nessa DLL antes que ele seja inicializado. E garante que nenhum código possa carregar a DLL com redundância enquanto ela é parcialmente inicializada. Para fazer isso, o carregador do Windows usa uma seção crítica de processo global (geralmente chamada de "bloqueio de carregador") que impede o acesso não seguro durante a inicialização do módulo. Como resultado, o processo de carregamento é vulnerável a muitos cenários de deadlock clássico. Para assemblies mistos, os dois cenários a seguir aumentam o risco de deadlock:

- Primeiro, se os usuários tentarem executar funções compiladas para a MSIL (Microsoft Intermediate Language) quando o bloqueio do carregador for mantido (de `DllMain` ou em inicializadores estáticos, por exemplo), isso poderá causar deadlock. Considere o caso em que a função MSIL faz referência a um tipo em um assembly que ainda não está carregado. O CLR tentará carregar automaticamente esse assembly, o que pode exigir que o carregador do Windows bloqueie o bloqueio do carregador. Ocorre um deadlock, pois o bloqueio do carregador já está sendo mantido pelo código anterior na sequência de chamadas. No entanto, a execução da MSIL sob o bloqueio do carregador não garante que ocorra um deadlock. É isso que torna esse cenário difícil de diagnosticar e corrigir. Em algumas circunstâncias, como quando a DLL do tipo referenciado não contém construções nativas e todas as suas dependências não contêm construções nativas, o carregador do Windows não é necessário para carregar o assembly .NET do tipo referenciado. Além disso, o assembly necessário ou suas dependências nativas/. NET mistas podem já ter sido carregados por outro código. Consequentemente, o deadlock pode ser difícil de prever e pode variar dependendo da configuração do computador de destino.

- Em segundo lugar, ao carregar DLLs nas versões 1,0 e 1,1 do .NET Framework, o CLR assumiu que o bloqueio do carregador não foi mantido e executou várias ações que são inválidas no bloqueio do carregador. Pressupondo que o bloqueio do carregador não seja mantido é uma suposição válida para as DLLs puramente .NET. Mas como DLLs mistas executam rotinas de inicialização nativas, elas exigem o carregador nativo do Windows e, consequentemente, o bloqueio do carregador. Portanto, mesmo que o desenvolvedor não estivesse tentando executar nenhuma função MSIL durante a inicialização da DLL, ainda havia uma pequena possibilidade de deadlock não determinístico no .NET Framework versões 1,0 e 1,1.

Todos os não determinantes foram removidos do processo de carregamento de DLL misto. Ele foi realizado com essas alterações:

- O CLR não faz mais suposições falsas ao carregar DLLs mistas.

- A inicialização gerenciada e não gerenciada é feita em dois estágios separados e distintos. A inicialização não gerenciada ocorre primeiro (via `DllMain` ), e a inicialização gerenciada ocorre posteriormente, por meio de um. Construção com suporte de rede `.cctor` . O último é completamente transparente para o usuário, a menos que **`/Zl`** ou **`/NODEFAULTLIB`** seja usado. Para obter mais informações, consulte[ `/NODEFAULTLIB` (ignorar bibliotecas)](../build/reference/nodefaultlib-ignore-libraries.md) e [ `/Zl` (omitir nome de biblioteca padrão)](../build/reference/zl-omit-default-library-name.md).

O bloqueio do carregador ainda pode ocorrer, mas agora ele ocorre reproduzido e é detectado. Se `DllMain` contiver instruções MSIL, o compilador gerará aviso [do compilador de aviso (nível 1) C4747](../error-messages/compiler-warnings/compiler-warning-level-1-c4747.md). Além disso, o CRT ou o CLR tentará detectar e relatar tentativas para executar o MSIL no bloqueio do carregador. Os resultados da detecção de CRT no erro de tempo de execução C R6033 de diagnóstico de tempo de execução.

O restante deste artigo descreve os cenários restantes para os quais a MSIL pode ser executada no bloqueio do carregador. Ele mostra como resolver o problema em cada um desses cenários e técnicas de depuração.

## <a name="scenarios-and-workarounds"></a>Cenários e soluções alternativas

Há várias situações diferentes sob as quais o código de usuário pode executar o MSIL em bloqueio de carregador. O desenvolvedor deve garantir que a implementação do código do usuário não tente executar instruções MSIL em cada uma dessas circunstâncias. As subseções a seguir descrevem todas as possibilidades com uma discussão sobre como resolver problemas nos casos mais comuns.

### <a name="dllmain"></a>DllMain

A `DllMain` função é um ponto de entrada definido pelo usuário para uma dll. A menos que o usuário especifique o contrário, `DllMain` é invocado toda vez que um processo ou thread é anexado ou desanexado da dll que o contém. Como essa invocação pode ocorrer enquanto o bloqueio do carregador é mantido, nenhuma função fornecida pelo usuário `DllMain` deve ser compilada para MSIL. Além disso, nenhuma função na árvore de chamada com raiz `DllMain` pode ser compilada para MSIL. Para resolver problemas aqui, o bloco de código que define `DllMain` deve ser modificado com `#pragma unmanaged` . O mesmo deve ser feito para cada função que `DllMain` chama.

Nos casos em que essas funções devem chamar uma função que requer uma implementação MSIL para outros contextos de chamada, você pode usar uma estratégia de duplicação na qual um .NET e uma versão nativa da mesma função são criados.

Como alternativa, se `DllMain` não for necessário ou se não precisar ser executado em um bloqueio de carregador, você poderá remover a implementação fornecida pelo usuário `DllMain` , o que elimina o problema.

Se `DllMain` tentar executar o MSIL diretamente, o [aviso do compilador (nível 1) C4747](../error-messages/compiler-warnings/compiler-warning-level-1-c4747.md) será resultado. No entanto, o compilador não pode detectar casos em que o `DllMain` chama uma função em outro módulo que, por sua vez, tenta executar o MSIL.

Para obter mais informações sobre esse cenário, consulte [impedimentos de diagnóstico](#impediments-to-diagnosis).

### <a name="initializing-static-objects"></a>Inicializando objetos estáticos

A inicialização de objetos estáticos pode resultar em deadlock se um inicializador dinâmico for necessário. Casos simples (como quando você atribui um valor conhecido em tempo de compilação a uma variável estática) não exigem inicialização dinâmica, portanto, não há risco de deadlock. No entanto, algumas variáveis estáticas são inicializadas por chamadas de função, invocações de construtor ou expressões que não podem ser avaliadas no momento da compilação. Todas essas variáveis exigem que o código seja executado durante a inicialização do módulo.

O código a seguir mostra exemplos de inicializadores estáticos que exigem inicialização dinâmica: uma chamada de função, construção de objeto e uma inicialização de ponteiro. (Esses exemplos não são estáticos, mas presumem que tenham definições no escopo global, que tem o mesmo efeito.)

```cpp
// dynamic initializer function generated
int a = init();
CObject o(arg1, arg2);
CObject* op = new CObject(arg1, arg2);
```

Esse risco de deadlock depende se o módulo recipiente é compilado com **`/clr`** e se MSIL será executado. Especificamente, se a variável estática for compilada sem **`/clr`** (ou estiver em um `#pragma unmanaged` bloco) e o inicializador dinâmico necessário para inicializá-la resultar na execução de instruções MSIL, o deadlock poderá ocorrer. É porque, para módulos compilados sem **`/clr`** , a inicialização de variáveis estáticas é executada pelo DllMain. Por outro lado, as variáveis estáticas compiladas com **`/clr`** são inicializadas pelo `.cctor` , após o estágio de inicialização não gerenciado ter sido concluído e o bloqueio do carregador ter sido liberado.

Há várias soluções para deadlock causadas pela inicialização dinâmica de variáveis estáticas. Eles são organizados aqui aproximadamente em ordem de tempo necessário para corrigir o problema:

- O arquivo de origem que contém a variável estática pode ser compilado com **`/clr`** .

- Todas as funções chamadas pela variável estática podem ser compiladas para o código nativo usando a `#pragma unmanaged` diretiva.

- Clone manualmente o código do qual a variável estática depende, fornecendo um .NET e uma versão nativa com nomes diferentes. Os desenvolvedores podem então chamar a versão nativa de inicializadores estáticos nativos e chamar a versão do .NET em outro lugar.

### <a name="user-supplied-functions-affecting-startup"></a>Funções fornecidas pelo usuário que afetam a inicialização

Há várias funções fornecidas pelo usuário nas quais as bibliotecas dependem da inicialização durante a inicialização. Por exemplo, ao sobrecarregar globalmente operadores em C++, como os **`new`** operadores e **`delete`** , as versões fornecidas pelo usuário são usadas em todos os lugares, incluindo na inicialização e na destruição da biblioteca padrão do C++. Como resultado, a biblioteca padrão C++ e inicializadores estáticos fornecidos pelo usuário invocarão todas as versões fornecidas pelo usuário desses operadores.

Se as versões fornecidas pelo usuário forem compiladas para MSIL, esses inicializadores tentarão executar instruções MSIL enquanto o bloqueio do carregador for mantido. Um usuário fornecido `malloc` tem as mesmas consequências. Para resolver esse problema, qualquer uma dessas sobrecargas ou definições fornecidas pelo usuário devem ser implementadas como código nativo usando a `#pragma unmanaged` diretiva.

Para obter mais informações sobre esse cenário, consulte [impedimentos de diagnóstico](#impediments-to-diagnosis).

### <a name="custom-locales"></a>Localidades personalizadas

Se o usuário fornecer uma localidade global personalizada, essa localidade será usada para inicializar todos os fluxos de e/s futuros, incluindo fluxos que são inicializados estaticamente. Se esse objeto de localidade global for compilado para MSIL, as funções de membros de objeto de localidade compiladas para MSIL poderão ser invocadas enquanto o bloqueio do carregador for mantido.

Há três opções para resolver esse problema:

Os arquivos de origem que contêm todas as definições de fluxo de e/s globais podem ser compilados usando a **`/clr`** opção. Ele impede que seus inicializadores estáticos sejam executados sob o bloqueio do carregador.

As definições da função de localidade personalizada podem ser compiladas para o código nativo usando a `#pragma unmanaged` diretiva.

Evite definir a localidade personalizada como a localidade global até que o bloqueio do carregador seja liberado. Em seguida, configure explicitamente os fluxos de e/s criados durante a inicialização com a localidade personalizada.

## <a name="impediments-to-diagnosis"></a>Impedimentos de diagnóstico

Em alguns casos, é difícil detectar a origem dos deadlocks. As subseções a seguir abordam esses cenários e maneiras de contornar esses problemas.

### <a name="implementation-in-headers"></a>Implementação em cabeçalhos

Em casos de seleção, as implementações de função dentro de arquivos de cabeçalho podem complicar o diagnóstico. As funções embutidas e o código do modelo exigem que as funções sejam especificadas em um arquivo de cabeçalho.  A linguagem C++ especifica a regra de uma definição, que força que todas as implementações de funções com o mesmo nome sejam semanticamente equivalentes. Consequentemente, o vinculador C++ não precisa fazer nenhuma consideração especial ao mesclar arquivos de objeto que têm implementações duplicadas de uma determinada função.

No Visual Studio versões anteriores ao Visual Studio 2005, o vinculador simplesmente escolhe o maior dessas definições semanticamente equivalentes. Isso é feito para acomodar declarações de avanço e cenários quando diferentes opções de otimização são usadas para arquivos de origem diferentes. Ele cria um problema para as DLLs do .NET e nativas mistas.

Como o mesmo cabeçalho pode ser incluído por arquivos C++ com **`/clr`** habilitado e desabilitado, ou um #include pode ser encapsulado dentro de um `#pragma unmanaged` bloco, é possível ter as versões MSIL e nativa das funções que fornecem implementações em cabeçalhos. As implementações MSIL e nativa têm semânticas diferentes para a inicialização no bloqueio do carregador, o que viola efetivamente a regra de uma definição. Consequentemente, quando o vinculador escolher a maior implementação, ele poderá escolher a versão MSIL de uma função, mesmo que tenha sido compilado explicitamente para código nativo em outro lugar usando a `#pragma unmanaged` diretiva. Para garantir que uma versão MSIL de um modelo ou função embutida nunca seja chamada sob o bloqueio do carregador, cada definição de cada função chamada sob o bloqueio do carregador deve ser modificada com a `#pragma unmanaged` diretiva. Se o arquivo de cabeçalho for de terceiros, a maneira mais fácil de fazer essa alteração é enviar por push e pop-la `#pragma unmanaged` sobre a diretiva de #include para o arquivo de cabeçalho incorreto. (Consulte [gerenciado, não gerenciado](../preprocessor/managed-unmanaged.md) por um exemplo.) No entanto, essa estratégia não funciona para cabeçalhos que contêm outro código que deve chamar diretamente as APIs do .NET.

Como uma conveniência para os usuários que lidam com o bloqueio de carregador, o vinculador escolherá a implementação nativa em relação ao gerenciado quando for apresentado. Esse padrão evita os problemas acima. No entanto, há duas exceções a essa regra nesta versão devido a dois problemas não resolvidos com o compilador:

- A chamada para uma função embutida é por meio de um ponteiro de função estática global. Esse cenário não é possível porque as funções virtuais são chamadas por meio de ponteiros de função global. Por exemplo,

```cpp
#include "definesmyObject.h"
#include "definesclassC.h"

typedef void (*function_pointer_t)();

function_pointer_t myObject_p = &myObject;

#pragma unmanaged
void DuringLoaderlock(C & c)
{
    // Either of these calls could resolve to a managed implementation,
    // at link-time, even if a native implementation also exists.
    c.VirtualMember();
    myObject_p();
}
```

### <a name="diagnosing-in-debug-mode"></a>Diagnosticando no modo de depuração

Todos os diagnósticos de problemas de bloqueio de carregador devem ser feitos com compilações de depuração. As compilações de versão podem não produzir diagnósticos. E as otimizações feitas no modo de liberação podem mascarar alguns dos MSIL em cenários de bloqueio de carregador.

## <a name="how-to-debug-loader-lock-issues"></a>Como depurar problemas de bloqueio de carregador

O diagnóstico que o CLR gera quando uma função MSIL é invocada faz com que o CLR suspenda a execução. Isso, por sua vez, faz com que o Visual C++ depurador de modo misto seja suspenso também ao executar o depurado em processo. No entanto, ao anexar ao processo, it'sn't possível obter uma pilha de chamadas gerenciada para o depurado usando o depurador misto.

Para identificar a função MSIL específica que foi chamada sob o bloqueio do carregador, os desenvolvedores devem concluir as seguintes etapas:

1. Verifique se os símbolos para mscoree.dll e mscorwks.dll estão disponíveis.

   Você pode disponibilizar os símbolos de duas maneiras. Primeiro, os PDBs para mscoree.dll e mscorwks.dll podem ser adicionados ao caminho de pesquisa de símbolos. Para adicioná-los, abra a caixa de diálogo opções de caminho de pesquisa de símbolo. (No menu **ferramentas** , escolha **Opções**. No painel esquerdo da caixa de diálogo **Opções** , abra o nó **depuração** e escolha **símbolos**.) Adicione o caminho para o mscoree.dll e mscorwks.dll arquivos PDB à lista de pesquisa. Esses PDBs são instalados no%VSINSTALLDIR%\SDK\v2.0\symbols. Selecione **OK**.

   Em segundo lugar, os PDBs para mscoree.dll e mscorwks.dll podem ser baixados do servidor de símbolos da Microsoft. Para configurar o servidor de símbolos, abra a caixa de diálogo opções de caminho de pesquisa de símbolo. (No menu **ferramentas** , escolha **Opções**. No painel esquerdo da caixa de diálogo **Opções** , abra o nó **depuração** e escolha **símbolos**.) Adicione este caminho de pesquisa à lista de pesquisa: `https://msdl.microsoft.com/download/symbols` . Adicione um diretório de cache de símbolo à caixa de texto cache do servidor de símbolos. Selecione **OK**.

1. Defina o modo do depurador como modo somente nativo.

   Abra a grade de **Propriedades** do projeto de inicialização na solução. Selecione depuração de **Propriedades de configuração**  >  **Debugging**. Defina a propriedade **tipo de depurador** como **somente nativo**.

1. Inicie o depurador (F5).

1. Quando o **`/clr`** diagnóstico for gerado, escolha **repetir** e, em seguida, escolha **interromper**.

1. Abra a janela pilha de chamadas. (Na barra de menus, escolha **depurar**  >  **Windows**  >  **Pilha de chamadas**.) O `DllMain` inicializador incorreto ou estático é identificado com uma seta verde. Se a função incorreta não for identificada, as etapas a seguir devem ser seguidas para encontrá-la.

1. Abra a janela **imediata** (na barra de menus, escolha **depurar**  >  **janelas**  >  **imediatas**).

1. Insira `.load sos.dll` na janela **imediata** para carregar o serviço de depuração SOS.

1. Entre na `!dumpstack` janela **imediata** para obter uma lista completa da **`/clr`** pilha interna.

1. Procure a primeira instância (mais próxima à parte inferior da pilha) de qualquer _CorDllMain (se `DllMain` causar o problema) ou _VTableBootstrapThunkInitHelperStub ou GetTargetForVTableEntry (se um inicializador estático causar o problema). A entrada de pilha logo abaixo dessa chamada é a invocação da função implementada MSIL que tentou executar sob o bloqueio do carregador.

1. Vá para o arquivo de origem e o número de linha identificados na etapa anterior e corrija o problema usando os cenários e soluções descritos na seção cenários.

## <a name="example"></a>Exemplo

### <a name="description"></a>Descrição

O exemplo a seguir mostra como evitar o bloqueio do carregador movendo o código de `DllMain` para o construtor de um objeto global.

Neste exemplo, há um objeto gerenciado global cujo construtor contém o objeto gerenciado que estava originalmente em `DllMain` . A segunda parte deste exemplo faz referência ao assembly, criando uma instância do objeto gerenciado para invocar o construtor de módulo que faz a inicialização.

### <a name="code"></a>Código

```cpp
// initializing_mixed_assemblies.cpp
// compile with: /clr /LD
#pragma once
#include <stdio.h>
#include <windows.h>
struct __declspec(dllexport) A {
   A() {
      System::Console::WriteLine("Module ctor initializing based on global instance of class.\n");
   }

   void Test() {
      printf_s("Test called so linker doesn't throw away unused object.\n");
   }
};

#pragma unmanaged
// Global instance of object
A obj;

extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved) {
   // Remove all managed code from here and put it in constructor of A.
   return true;
}
```

Este exemplo demonstra problemas na inicialização de assemblies mistos:

```cpp
// initializing_mixed_assemblies_2.cpp
// compile with: /clr initializing_mixed_assemblies.lib
#include <windows.h>
using namespace System;
#include <stdio.h>
#using "initializing_mixed_assemblies.dll"
struct __declspec(dllimport) A {
   void Test();
};

int main() {
   A obj;
   obj.Test();
}
```

Este código produz a seguinte saída:

```Output
Module ctor initializing based on global instance of class.

Test called so linker doesn't throw away unused object.
```

## <a name="see-also"></a>Confira também

[Assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md)
