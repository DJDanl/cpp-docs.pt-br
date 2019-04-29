---
title: Inicialização de assemblies mistos
ms.date: 03/09/2018
helpviewer_keywords:
- mixed assemblies [C++], loader lock
- loader lock [C++]
- initializing mixed assemblies
- deadlocks [C++]
- .cctor [C++]
- custom locales [C++]
- mixed assemblies [C++], initilizing
ms.assetid: bfab7d9e-f323-4404-bcb8-712b15f831eb
ms.openlocfilehash: 1f4ea7f5cfc6e99390c93ba9c2beadc46fce8584
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62339033"
---
# <a name="initialization-of-mixed-assemblies"></a>Inicialização de assemblies mistos

Os desenvolvedores do Windows sempre devem ter cautela ao bloqueio do carregador durante a execução de código durante `DllMain`. No entanto, há algumas considerações adicionais que entram em jogo ao lidar com C++/clr assemblies de modo misto.

Código dentro do [DllMain](/windows/desktop/Dlls/dllmain) não deve acessar o CLR. Isso significa que `DllMain` não deve fazer nenhuma chamada para funções gerenciadas, direta ou indiretamente; nenhum código gerenciado deve ser declarado ou implementado no `DllMain`; e nenhuma coleta de lixo ou o carregamento da biblioteca automática deve ocorrer dentro de `DllMain` .

## <a name="causes-of-loader-lock"></a>Causas de bloqueio do carregador

Com a introdução da plataforma .NET, há dois mecanismos distintos para carregar um módulo de execução (EXE ou DLL): um para Windows, que é usado para os módulos não gerenciados, e outro para o .NET em tempo de execução CLR (Common Language) que carrega os assemblies do .NET. O problema de carregamento de DLL misto gira em torno do carregador do sistema operacional do Microsoft Windows.

Quando um assembly que contém somente as construções de .NET é carregado em um processo, o carregador do CLR pode executar todas as tarefas necessárias de carregamento e inicialização em si. No entanto, para assemblies mistos, como eles podem conter código nativo e os dados, o carregador do Windows deve ser usado também.

O carregador do Windows garante que nenhum código pode acessar código ou dados nessa dll antes que ela foi inicializada e que nenhum código de forma redundante pode carregar a DLL enquanto ele está parcialmente inicializado. Para fazer isso, o carregador do Windows usa uma processo global seção crítica (geralmente chamada de "bloqueio do carregador") que impede o acesso não seguro durante a inicialização do módulo. Como resultado, o processo de carregamento é vulnerável a muitos cenários de deadlock clássico. Para assemblies mistos, dois cenários a seguir aumentam o risco de deadlock:

- Primeiro, se os usuários tentarem executar funções compiladas para Microsoft intermediate language (MSIL) quando o bloqueio do carregador é mantido (do `DllMain` ou em inicializadores estáticos, por exemplo), isso pode causar um deadlock. Considere o caso em que a função MSIL referencia um tipo em um assembly que não tenha sido carregado. O CLR tentará automaticamente carregará o assembly, que pode exigir o carregador do Windows para bloquear o bloqueio do carregador. Uma vez que o bloqueio do carregador já é mantido pelo código anteriormente na sequência de chamada, resultados de um deadlock. No entanto, a MSIL em execução em um bloqueio de carregador não garante que ocorrerá um deadlock, dificultando diagnosticar e corrigir a esse cenário. Em algumas circunstâncias, como em que a DLL do tipo referenciado contém construções não nativas e todas as suas dependências não conter nenhuma construções nativas, o Windows carregador não é necessário para carregar o assembly do .NET do tipo referenciado. Além disso, o assembly necessário ou suas dependências nativo misto/.NET talvez já foram carregadas por outro código. Consequentemente, o deadlock pode ser difícil de prever e pode variar dependendo da configuração da máquina de destino.

- Em segundo lugar, ao carregar DLLs nas versões 1.0 e 1.1 do .NET Framework, o CLR presume-se que o bloqueio do carregador não foi mantido e executadas várias ações que são inválidas em um bloqueio de carregador. Supondo que o bloqueio do carregador é mantido não é uma suposição válida para puramente DLLs do .NET, mas, como DLLs mistas executar rotinas de inicialização nativa, eles exigem o carregador nativo em Windows e, portanto, o bloqueio do carregador. Consequentemente, mesmo que o desenvolvedor não estava tentando executar todas as funções MSIL durante a inicialização da DLL, ainda havia uma possibilidade pequena de deadlock não determinística com as versões 1.0 e 1.1 do .NET Framework.

Todos os não-determinismo foi removido do processo de carregamento de DLLs mistas. Isso foi feito com essas alterações:

- O CLR não faz suposições falsas durante o carregamento de DLLs mistas.

- Inicialização gerenciada e não é executada em dois estágios separados e distintos. Inicialização não gerenciada ocorre pela primeira vez (por meio de DllMain) e gerenciado de inicialização ocorre posteriormente, por meio de um. Suporte para NET constructo chamado um *cctor*. O último é completamente transparente para o usuário, a menos que **/Zl** ou **/NODEFAULTLIB** são usados. Ver[/NODEFAULTLIB (ignorar bibliotecas)](../build/reference/nodefaultlib-ignore-libraries.md) e [/Zl (omitir nome da biblioteca padrão)](../build/reference/zl-omit-default-library-name.md) para obter mais informações.

Bloqueio do carregador ainda poderão ocorrer, mas agora ele ocorre reproduzíveis e é detectado. Se `DllMain` contém instruções MSIL, o compilador gera um aviso [aviso do compilador (nível 1) C4747](../error-messages/compiler-warnings/compiler-warning-level-1-c4747.md). Além disso, o CRT ou o CLR tentará detectar e relatar tentativas de executar o MSIL em um bloqueio de carregador. Detecção de CRT resulta em tempo de execução R6033 diagnóstico de erro de tempo de execução C.

O restante deste documento descreve os cenários restantes para o qual MSIL pode ser executado sob o bloqueio do carregador, resoluções para o problema em cada um desses cenários e técnicas de depuração.

## <a name="scenarios-and-workarounds"></a>Cenários e soluções alternativas

Há várias situações diferentes sob a qual o código do usuário pode executar MSIL sob bloqueio do carregador. O desenvolvedor deve assegurar que a implementação de código do usuário não tentou executar instruções MSIL em cada uma dessas circunstâncias. As subseções a seguir descrevem todas as possibilidades com uma discussão sobre como resolver problemas nos casos mais comuns.

### <a name="dllmain"></a>DllMain

O `DllMain` função é um ponto de entrada definido pelo usuário para uma DLL. A menos que o usuário especifique o contrário, `DllMain` é invocado sempre que um processo ou thread for anexado ou desanexado da DLL que contém. Como essa invocação pode ocorrer enquanto o bloqueio do carregador é mantido, não fornecido pelo usuário `DllMain` função deverá ser compilada em MSIL. Além disso, nenhuma função na árvore de chamadas enraizada em `DllMain` podem ser compilados para MSIL. Para resolver problemas aqui, o bloco de código que define `DllMain` deve ser modificado com #pragma `unmanaged`. O mesmo deve ser feito para todas as funções que `DllMain` chamadas.

Em casos em que essas funções devem chamar uma função que requer uma implementação de MSIL para outros contextos de chamada, uma estratégia de eliminação de duplicação pode ser usada onde um .NET e uma versão nativa da mesma função são criados.

Como alternativa, se `DllMain` não é necessária ou se ele não precisa ser executado no carregador de bloqueio, o usuário fornecido pelo `DllMain` implementação pode ser removida, o que eliminará o problema.

Se DllMain tenta executar diretamente, o MSIL [aviso do compilador (nível 1) C4747](../error-messages/compiler-warnings/compiler-warning-level-1-c4747.md) resultará. No entanto, o compilador não pode detectar os casos em que o DllMain chama uma função em outro módulo que por sua vez tenta executar o MSIL.

Consulte "Impedimentos para diagnóstico" para obter mais informações sobre esse cenário.

### <a name="initializing-static-objects"></a>Inicializando objetos estáticos

Inicializando objetos estáticos pode resultar em deadlock se um inicializador dinâmico é necessário. Para casos simples, como quando uma variável estática simplesmente é atribuída a um valor conhecido no tempo de compilação, nenhuma inicialização dinâmica é necessária, portanto, não há nenhum risco de deadlock. No entanto, as variáveis estáticas inicializadas por chamadas de função, invocações de construtor ou expressões que não podem ser avaliadas em todas exigem que o código seja executado durante a inicialização do módulo de tempo de compilação.

O código a seguir mostra exemplos de inicializadores estáticos que exigem inicialização dinâmica: uma chamada de função, construção de objeto e a inicialização de um ponteiro. (Esses exemplos não são estáticos, mas devem ser definidos no escopo global, que tem o mesmo efeito.)

```cpp
// dynamic initializer function generated
int a = init();
CObject o(arg1, arg2);
CObject* op = new CObject(arg1, arg2);
```

Esse risco de deadlock depende se o módulo recipiente é compilado com **/clr** e se MSIL será executado. Especificamente, se a variável estática é compilada sem **/clr** (ou reside em um #pragma `unmanaged` bloco), e o inicializador dinâmico necessário para inicializá-lo resultados na execução das instruções da MSIL, deadlock pode ocorrer. Isso ocorre porque, para módulos compilados sem **/clr**, a inicialização de variáveis estáticas é executada pelo DllMain. Em contraste, as variáveis estáticas são compilados com **/clr** são inicializados por cctor, depois que concluir o estágio de inicialização não gerenciado e o bloqueio do carregador foi lançado.

Há uma série de soluções para deadlock causada pela inicialização dinâmica de variáveis estáticas (aproximadamente organizadas em ordem de tempo necessária para corrigir o problema):

- O arquivo de origem que contém a variável estática pode ser compilado com **/clr**.

- Todas as funções chamadas pela variável estática podem ser compiladas para código nativo usando o #pragma `unmanaged` diretiva.

- Clone manualmente o código que a variável estática depende, fornecendo um .NET e uma versão nativa com nomes diferentes. Os desenvolvedores podem, em seguida, chamar a versão nativa de inicializadores estáticos nativos e chamar a versão do .NET em outro lugar.

### <a name="user-supplied-functions-affecting-startup"></a>Funções fornecidas pelo usuário que afetam a inicialização

Há várias funções fornecidas pelo usuário quais bibliotecas dependem de inicialização durante a inicialização. Por exemplo, ao globalmente sobrecarregar operadores em C++, como o `new` e `delete` operadores, as versões fornecidas pelo usuário são usados em qualquer lugar, incluindo na inicialização da biblioteca padrão C++ e a destruição. Como resultado, a biblioteca padrão C++ e inicializadores estáticos fornecido pelo usuário invocará quaisquer versões fornecido pelo usuário desses operadores.

Se as versões fornecidas pelo usuário são compiladas para MSIL, em seguida, esses inicializadores serão ser tentando executar instruções MSIL enquanto o bloqueio do carregador é mantido. Um usuário fornecido pelo `malloc` tem as mesmas consequências. Para resolver esse problema, qualquer uma dessas sobrecargas ou definições fornecido pelo usuário devem ser implementadas como código nativo usando o #pragma `unmanaged` diretiva.

Consulte "Impedimentos para diagnóstico" para obter mais informações sobre esse cenário.

### <a name="custom-locales"></a>Localidades personalizadas

Se o usuário fornece uma localidade global personalizada, essa localidade será usada para inicializar todos os fluxos de e/s futuros, incluindo aqueles que são inicializadas estaticamente. Se esse objeto de localidade global é compilado em MSIL, em seguida, funções de membro de objeto de localidade compiladas para MSIL podem ser invocadas enquanto o bloqueio do carregador é mantido.

Há três opções para resolver esse problema:

Os arquivos de origem que contém todas as definições de fluxo de e/s globais podem ser compilados usando o **/clr** opção. Isso impedirá que seus inicializadores estáticos que está sendo executado sob bloqueio do carregador.

As definições de função de localidades personalizadas podem ser compiladas para código nativo usando o #pragma `unmanaged` diretiva.

Evite definir a localidade personalizada como a localidade global até depois que o bloqueio do carregador é liberado. Em seguida, configure explicitamente criados durante a inicialização com a localidade personalizada de fluxos de e/s.

## <a name="impediments-to-diagnosis"></a>Impedimentos para diagnóstico

Em alguns casos, é difícil de detectar a origem de deadlocks. As subseções a seguir discutem esses cenários e as maneiras de contornar esses problemas.

### <a name="implementation-in-headers"></a>Implementação nos cabeçalhos

Em casos de select, implementações de função dentro de arquivos de cabeçalho podem complicar o diagnóstico. Funções embutidas e o código de modelo exigem que as funções de ser especificado em um arquivo de cabeçalho.  A linguagem C++ especifica uma regra de definição, que força todas as implementações das funções com o mesmo nome para ser semanticamente equivalentes. Consequentemente, o vinculador C++ não precisa fazer considerações especiais ao mesclar arquivos de objeto que têm implementações duplicadas de uma determinada função.

Antes do Visual Studio 2005, o vinculador simplesmente escolhe o maior dessas definições semanticamente equivalente, para acomodar cenários e declarações de encaminhamento quando as opções de otimização diferentes são usadas para arquivos de origem diferentes. Isso cria um problema para nativo misto/.NET DLLs.

Porque o mesmo cabeçalho pode ser incluídos por arquivos de C++ com **/clr** habilitados e desabilitados, ou um #include podem ser encapsulados dentro de um #pragma `unmanaged` bloco, é possível ter MSIL e as versões nativas de funções que fornecem implementações nos cabeçalhos. MSIL e implementações nativas têm semânticas diferentes em relação à inicialização sob o bloqueio do carregador, que efetivamente viola a regra de uma definição. Consequentemente, quando o vinculador escolherá a implementação maior, ela pode escolha a versão MSIL de uma função, mesmo se explicitamente, ele foi compilado para código nativo em outro lugar usando a diretiva de não gerenciado #pragma. Para garantir que uma versão MSIL de uma modelo ou uma função embutida nunca é chamada em bloqueio do carregador, cada definição de cada tal função chamada em um bloqueio de carregador deve ser modificada com a #pragma `unmanaged` diretiva. Se o arquivo de cabeçalho for de terceiros, a maneira mais fácil de fazer isso é enviar por push e pop a diretiva de #pragma não gerenciado em torno de #include diretiva para o arquivo de cabeçalho incorretos. (Consulte [gerenciado, não gerenciado](../preprocessor/managed-unmanaged.md) para obter um exemplo.) No entanto, essa estratégia não funcionará para os cabeçalhos que contêm a outro código que deve chamar diretamente as APIs do .NET.

Como uma conveniência para lidar com o bloqueio do carregador de usuários, o vinculador escolherá a implementação nativa sobre gerenciado quando apresentado com ambos. Isso evita os problemas acima. No entanto, há duas exceções a essa regra nesta versão devido a dois problemas não resolvidos com o compilador:

- A chamada é para um embutido função é através de um ponteiro de função estático global. Esse cenário é particularmente importante, como funções virtuais são chamadas por meio de ponteiros de função global. Por exemplo,

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

Todos os diagnósticos de bloqueio do carregador problemas devem ser feitos com compilações de depuração. Builds de versão podem não produzir o diagnóstico e as otimizações realizadas no modo de versão podem mascarar alguns do MSIL em cenários de bloqueio do carregador.

## <a name="how-to-debug-loader-lock-issues"></a>Como depurar problemas de bloqueio do carregador

O diagnóstico que o CLR gera quando uma função MSIL é invocada faz com que o CLR suspender a execução. Por sua vez, isso faz com que o depurador de modo misto do Visual C++ a ser suspensa também ao executar o elemento a ser depurado no processo. No entanto, ao anexar ao processo, não é possível obter uma pilha de chamadas gerenciada para o elemento a ser depurado usando o depurador misto.

Para identificar a função específica do MSIL que foi chamada em bloqueio do carregador, os desenvolvedores devem concluir as etapas a seguir:

1. Certifique-se de que os símbolos de mscoree. dll e mscorwks. dll estão disponíveis.

   Isso pode ser feito de duas maneiras. Primeiro, os PDBs para mscoree. dll e mscorwks. dll podem ser adicionados ao caminho de pesquisa de símbolo. Para fazer isso, abra a caixa de diálogo de opções de caminho de pesquisa de símbolo. (Da **ferramentas** menu, escolha **opções**. No painel esquerdo do **opções** caixa de diálogo, abra o **depuração** nó e escolha **símbolos**.) Adicione o caminho para os arquivos PDB mscoree. dll e mscorwks. dll para a lista de pesquisa. Esses PDBs são instalados em % VSINSTALLDIR%\SDK\v2.0\symbols. Escolha **OK**.

   Em segundo lugar, os PDBs para mscoree. dll e mscorwks. dll podem ser baixados do servidor de símbolo Microsoft. Para configurar o servidor de símbolos, abra a caixa de diálogo de opções de caminho de pesquisa de símbolo. (Da **ferramentas** menu, escolha **opções**. No painel esquerdo do **opções** caixa de diálogo, abra o **depuração** nó e escolha **símbolos**.) Adicione o seguinte caminho de pesquisa à lista de pesquisa: http://msdl.microsoft.com/download/symbols. Adicione um diretório de cache de símbolo para a caixa de texto de cache de servidor de símbolo. Escolha **OK**.

1. Definir o modo de depurador para o modo somente nativo.

   Para fazer isso, abra o **propriedades** grade para o projeto de inicialização na solução. Selecione **propriedades de configuração** > **depuração**. Defina as **tipo de depurador** à **somente nativo**.

1. Inicie o depurador (F5).

1. Quando o **/clr** diagnóstico é gerado, escolha **Repita** e, em seguida, escolha **quebrar**.

1. Abra a janela de pilha de chamadas. (Na barra de menus, escolha **Debug** > **Windows** > **pilha de chamadas**.) Problemático `DllMain` ou inicializador estático é identificado com uma seta verde. Se a função transgressor não for identificada, as etapas a seguir devem ficar para encontrá-lo.

1. Abra o **Immediate** janela (na barra de menus, escolha **Debug** > **Windows** > **imediato**.)

1. Digite. carregar SOS. dll para o **imediato** janela para carregar o serviço de depuração SOS.

1. Tipo! dumpstack para o **imediato** janela para obter uma lista completa de interno **/clr** pilha.

1. Procura a primeira instância (mais próxima à parte inferior da pilha) de qualquer um dos cordllmain (se `DllMain` faz com que o problema) ou _VTableBootstrapThunkInitHelperStub ou GetTargetForVTableEntry (se um inicializador estático faz com que o problema). A entrada da pilha logo abaixo dessa chamada é que a invocação do MSIL implementado a função que tentou executar em um bloqueio de carregador.

1. Vá para o arquivo de origem e a linha número identificado na etapa anterior e corrija o problema usando os cenários e as soluções descritas na seção cenários.

## <a name="example"></a>Exemplo

### <a name="description"></a>Descrição

O exemplo a seguir mostra como evitar o bloqueio do carregador movendo o código de `DllMain` para o construtor de um objeto global.

Neste exemplo, há um objeto gerenciado global cujo construtor contém o objeto gerenciado que foi originalmente no `DllMain`. A segunda parte deste exemplo referencia o assembly, criando uma instância do objeto gerenciado para invocar o construtor de módulo que faz a inicialização.

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
      printf_s("Test called so linker does not throw away unused object.\n");
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

Este exemplo demonstra os problemas de inicialização de assemblies mistos:

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

Esse código gera a seguinte saída:

```Output
Module ctor initializing based on global instance of class.

Test called so linker does not throw away unused object.
```

## <a name="see-also"></a>Consulte também

[Assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md)
