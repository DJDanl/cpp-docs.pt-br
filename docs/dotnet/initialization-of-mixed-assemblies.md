---
title: Inicialização de Assemblies mistos | Microsoft Docs
ms.custom: ''
ms.date: 03/09/2018
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- mixed assemblies [C++], loader lock
- loader lock [C++]
- initializing mixed assemblies
- deadlocks [C++]
- .cctor [C++]
- custom locales [C++]
- mixed assemblies [C++], initilizing
ms.assetid: bfab7d9e-f323-4404-bcb8-712b15f831eb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 389246b6b002204260170fb44680c2756cd7aa6b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33137885"
---
# <a name="initialization-of-mixed-assemblies"></a>Inicialização de assemblies mistos

Os desenvolvedores do Windows sempre devem ter cautela ao bloqueio do carregador ao executar o código durante a `DllMain`. No entanto, há algumas considerações adicionais a serem considerados ao lidar com C + + assemblies de modo misto do clr.

Código em [DllMain](http://msdn.microsoft.com/library/windows/desktop/ms682583) não deve acessar o CLR. Isso significa que `DllMain` não deve fazer nenhuma chamada para funções gerenciadas, direta ou indiretamente; nenhum código gerenciado deve ser declarado ou implementado em `DllMain`; e não coleta de lixo ou o carregamento da biblioteca automática deve ocorrer em `DllMain` .
  
## <a name="causes-of-loader-lock"></a>Causas de bloqueio do carregador

Há dois mecanismos distintos de carregamento de um módulo de execução (EXE ou DLL) com a introdução da plataforma .NET: um para Windows, que é usado para os módulos gerenciados, e outro para o .NET CLR Common Language Runtime () que carrega os assemblies do .NET. O problema de carregamento de DLL misto gira em torno do carregador do sistema operacional Microsoft Windows.

Quando um assembly que contém apenas as construções de .NET é carregado em um processo, o carregador do CLR pode executar todas as tarefas necessárias de carregamento e inicialização em si. No entanto, para assemblies mistos, porque podem conter código nativo e dados, o carregador do Windows deve ser usado também.

O carregador do Windows garante que nenhum código pode acessar código ou dados nessa dll antes que ela foi inicializada e que nenhum código redundante pode carregar a DLL enquanto ele for parcialmente inicializado. Para fazer isso, o carregador do Windows usa uma processo global seção crítica (geralmente chamada de "bloqueio do carregador") que impede o acesso não seguro durante a inicialização do módulo. Como resultado, o processo de carregamento é vulnerável a vários cenários de deadlock clássico. Para assemblies mistos, os dois cenários a seguir aumentam o risco de deadlock:

- Primeiro, se os usuários tentarem executar funções compiladas para Microsoft intermediate language (MSIL) quando o bloqueio do carregador é mantido (de `DllMain` ou em inicializadores estáticos, por exemplo), isso pode causar um deadlock. Considere o caso em que a função MSIL referencia um tipo em um assembly que não tenha sido carregado. O CLR tentará carregar automaticamente o assembly, que pode exigir o carregador do Windows para bloquear o bloqueio do carregador. Desde que o bloqueio de carregador já é mantido pelo código anteriormente na sequência de chamada, ocorre um deadlock. No entanto, a execução MSIL sob bloqueio do carregador não garante que ocorrerá um deadlock, dificultando neste cenário diagnosticar e corrigir. Em algumas circunstâncias, como em que a DLL do tipo referenciado contém construções não nativo e todas as suas dependências não conter nenhuma construções nativo, o Windows carregador não é necessário para carregar o assembly .NET do tipo referenciado. Além disso, o assembly necessário ou suas dependências nativo misto/.NET podem ter já foi carregadas por outro código. Consequentemente, o deadlock pode ser difícil de prever e pode variar dependendo da configuração do computador de destino.

- Em segundo lugar, ao carregar DLLs nas versões 1.0 e 1.1 do .NET Framework, o CLR assumido que o bloqueio do carregador não foi mantido e executada várias ações que são inválidas no bloqueio do carregador. Supondo que não possui o bloqueio do carregador é uma suposição válida para puramente DLLs do .NET, mas, como DLLs mistos executar rotinas de inicialização nativa, eles exigem o carregador do Windows nativo e, portanto, o bloqueio do carregador. Consequentemente, mesmo que o desenvolvedor não estava tentando executar todas as funções MSIL durante a inicialização da DLL, ainda havia uma possibilidade pequena de deadlock não determinística com as versões 1.0 e 1.1 do .NET Framework.

Todos os não-determinismo foi removido do processo de carregamento de DLL mistas. Isso foi feito com essas alterações:

- O CLR não faz mais suposições falsas quando mistos DLLs de carregamento.

- Inicialização gerenciada e não é executada em dois estágios separados e distintos. Não gerenciado a inicialização ocorre primeiro (via DllMain) e inicialização gerenciada ocorre posteriormente, por meio de um. Construção suporte NET chamada um *. cctor*. O segundo é completamente transparente para o usuário, a menos que **/Zl** ou **/NODEFAULTLIB** são usados. Consulte[/NODEFAULTLIB (ignorar bibliotecas)](../build/reference/nodefaultlib-ignore-libraries.md) e [/Zl (omitir a nome de biblioteca padrão)](../build/reference/zl-omit-default-library-name.md) para obter mais informações.

Bloqueio do carregador ainda pode ocorrer, mas agora ele ocorre reproducibly e é detectado. Se `DllMain` contém instruções da MSIL, o compilador gera o aviso [C4747 de aviso do compilador (nível 1)](../error-messages/compiler-warnings/compiler-warning-level-1-c4747.md). Além disso, CRT ou CLR tentará detectar e relatar tenta executar MSIL sob bloqueio do carregador. Detecção de CRT resulta em tempo de execução de diagnóstico R6033 de erro de tempo de execução C.

O restante deste documento descreve os cenários restantes para o qual MSIL pode executar sob o bloqueio do carregador, resoluções para o problema em cada um desses cenários e técnicas de depuração.

## <a name="scenarios-and-workarounds"></a>Cenários e soluções alternativas

Há várias situações diferentes sob a qual o código de usuário pode executar MSIL sob bloqueio do carregador. O desenvolvedor deve assegurar que a implementação de código do usuário não tentou executar instruções da MSIL em cada uma destas circunstâncias. As subseções a seguir descrevem todas as possibilidades com uma discussão sobre como resolver problemas nos casos mais comuns.

### <a name="dllmain"></a>DllMain

O `DllMain` função é um ponto de entrada definido pelo usuário para uma DLL. A menos que o usuário especifique o contrário, `DllMain` é invocado sempre que um processo ou thread anexado ou desanexado da DLL que contém. Como essa invocação pode ocorrer enquanto o bloqueio do carregador é mantido, não fornecidos pelo usuário `DllMain` função deve ser compilada para MSIL. Além disso, nenhuma função na árvore de chamadas com raiz em `DllMain` podem ser compilados para MSIL. Para resolver problemas aqui, o bloco de código que define `DllMain` devem ser modificados com #pragma `unmanaged`. O mesmo deve ser feito para cada função que `DllMain` chamadas.

Em casos em que essas funções devem chamar uma função que requer uma implementação de MSIL para outros contextos de chamada, uma estratégia de eliminação de duplicação pode ser usada onde .NET e uma versão nativa da mesma função são criados.

Como alternativa, se `DllMain` não é necessária ou se ele não precisa ser executado no carregador de bloqueio, o usuário fornecido `DllMain` implementação pode ser removida, o que eliminará o problema.

Se DllMain tenta executar MSIL diretamente, [C4747 de aviso do compilador (nível 1)](../error-messages/compiler-warnings/compiler-warning-level-1-c4747.md) resultará. No entanto, o compilador não pode detectar os casos onde DllMain chama uma função em outro módulo que por sua vez tenta executar MSIL.

Consulte "Impedimentos para diagnóstico" para obter mais informações sobre esse cenário.

### <a name="initializing-static-objects"></a>Inicializando objetos estáticos

Inicializando objetos estáticos pode resultar em deadlock, se um inicializador dinâmico é necessário. Para casos simples, como quando uma variável estática simplesmente é atribuída a um valor conhecido em tempo de compilação, sem inicialização dinâmica é necessária, portanto não há nenhum risco de deadlock. No entanto, variáveis estáticas inicializados por chamadas de função, chamadas de construtor ou expressões que não podem ser avaliadas em todos exigem o código a ser executado durante a inicialização do módulo de tempo de compilação.

O código a seguir mostra exemplos de inicializadores estáticos que requerem inicialização dinâmica: uma chamada de função, construção de objeto e a inicialização de um ponteiro. (Esses exemplos não são estáticos, mas devem ser definidas no escopo global, que tem o mesmo efeito.)

```cpp
// dynamic initializer function generated
int a = init();
CObject o(arg1, arg2);
CObject* op = new CObject(arg1, arg2);
```

Esse risco de deadlock depende se o módulo contendo é compilado com **/clr** e se MSIL será executado. Especificamente, se a variável estática é compilado sem **/clr** (ou reside em um #pragma `unmanaged` bloco), e o inicializador dinâmico necessário para inicializá-lo resultados na execução de instruções da MSIL, deadlock pode ocorrer. Isso ocorre porque, para módulos compilados sem **/clr**, a inicialização de variáveis estáticas é executada por DllMain. Por outro lado, as variáveis estáticas compilado com **/clr** são inicializadas pelo cctor, depois que o estágio de inicialização não gerenciado foi concluído e o bloqueio do carregador foi liberado.

Há várias soluções de bloqueio causados por inicialização dinâmica de variáveis estáticas (aproximadamente organizadas em ordem de tempo necessária para corrigir o problema):

- O arquivo de origem que contém a variável estática pode ser compilado com **/clr**.

- Todas as funções chamadas pela variável estática podem ser compiladas para código nativo usando o #pragma `unmanaged` diretiva.

- Clone manualmente o código que a variável estática depende, fornecendo um .NET e uma versão nativa com nomes diferentes. Os desenvolvedores podem, em seguida, chamar a versão nativa do native inicializadores estáticos e chamar a versão do .NET em outro lugar.

### <a name="user-supplied-functions-affecting-startup"></a>Funções fornecidas pelo usuário que afetam a inicialização

Há várias funções fornecidas pelo usuário que bibliotecas dependem de inicialização durante a inicialização. Por exemplo, ao sobrecarregar globalmente operadores em C++, como o `new` e `delete` as versões fornecido pelo usuário, os operadores são usados em qualquer lugar, incluindo na inicialização da biblioteca padrão C++ e destruição. Como resultado, os inicializadores estáticos fornecido pelo usuário e biblioteca padrão C++ invocará quaisquer versões fornecido pelo usuário desses operadores.

Se as versões fornecido pelo usuário são compiladas para MSIL, em seguida, esses inicializadores serão tentar executar instruções da MSIL enquanto o bloqueio do carregador é mantido. Um usuário forneceu `malloc` tem as mesmo consequências. Para resolver esse problema, essas sobrecargas ou definições fornecido pelo usuário devem ser implementados como código nativo usando o #pragma `unmanaged` diretiva.

Consulte "Impedimentos para diagnóstico" para obter mais informações sobre esse cenário.

### <a name="custom-locales"></a>Localidades personalizadas

Se o usuário fornece uma localidade global personalizada, este código de idioma será usado para inicializar todos os fluxos de e/s futuros, incluindo aqueles que são inicializadas estaticamente. Se esse objeto de localidade global é compilado para MSIL, em seguida, funções de membro de objeto de localidade compiladas para MSIL podem ser chamadas enquanto o bloqueio do carregador é mantido.

Há três opções para resolver esse problema:

Os arquivos de origem que contém todas as definições de fluxo de e/s global podem ser compilados usando o **/clr** opção. Isso impedirá que os seus inicializadores estáticos que está sendo executado sob bloqueio do carregador.

As definições de função localidade personalizados podem ser compiladas para código nativo usando o #pragma `unmanaged` diretiva.

Evite definir a localidade personalizada como a localidade global até depois que o bloqueio do carregador é liberado. Configure fluxos de e/s criados durante a inicialização com a localidade personalizada explicitamente.

## <a name="impediments-to-diagnosis"></a>Impedimentos diagnóstico

Em alguns casos, é difícil de detectar a origem de bloqueios. As subseções a seguir discutem esses cenários e maneiras de resolver esses problemas.

### <a name="implementation-in-headers"></a>Implementação nos cabeçalhos

Selecionados casos, as implementações de função nos arquivos de cabeçalho podem complicar a diagnóstico. Funções embutidas e o código de modelo exigem que as funções ser especificados em um arquivo de cabeçalho.  A linguagem C++ especifica uma regra de definição, que força todas as implementações de funções com o mesmo nome como semanticamente equivalente. Consequentemente, o vinculador C++ não precisa fazer considerações especiais ao mesclar arquivos de objeto que têm implementações duplicadas de uma determinada função.

Antes do Visual Studio 2005, o vinculador simplesmente escolhe o maior dessas definições semanticamente equivalente, para acomodar cenários e declarações de encaminhamento quando as opções de otimização diferentes são usadas para arquivos de origem diferente. Isso cria um problema para nativo misto/.NET DLLs.

Porque o mesmo cabeçalho pode ser incluído por arquivos C++ com **/clr** habilitados e desabilitados, ou um #include podem ser encapsulados em um #pragma `unmanaged` bloco, é possível ter MSIL e as versões nativas de funções que fornecem implementações nos cabeçalhos. MSIL e implementações nativas tem semânticas diferentes em relação à inicialização sob o bloqueio do carregador, que efetivamente viola a regra de uma definição. Consequentemente, quando o vinculador escolherá a implementação maior, ele pode escolha a versão do MSIL de uma função, mesmo se ele explicitamente foi compilado para código nativo em outro local usando a diretiva de #pragma não gerenciado. Para garantir que uma versão MSIL de uma função de modelo ou embutido nunca é chamada em bloqueio do carregador, cada definição de cada função chamada em bloqueio do carregador deve ser modificada com a #pragma `unmanaged` diretiva. Se o arquivo de cabeçalho é de terceiros, a maneira mais fácil de fazer isso é por push e pop a diretiva de #pragma não gerenciado em torno de #include diretiva para o arquivo de cabeçalho incorreto. (Consulte [gerenciado, não gerenciado](../preprocessor/managed-unmanaged.md) para obter um exemplo.) No entanto, essa estratégia não funcionará para os cabeçalhos que contêm a outro código que deve chamar diretamente APIs do .NET.

Como uma conveniência para lidar com o bloqueio do carregador de usuários, o vinculador escolherá a implementação nativa sobre gerenciado quando apresentado com ambos. Isso evita os problemas acima. No entanto, há duas exceções a essa regra nesta versão devido a dois problemas não resolvidos com o compilador:

- Em uma linha é chamada de função é através de um ponteiro de função estática global. Esse cenário é particularmente importante porque funções virtuais são chamadas através de ponteiros de função global. Por exemplo,
  
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

Todos os diagnósticos do bloqueio do carregador problemas devem ser feitos com compilações de depuração. Compilações de versão não podem produzir o diagnóstico e as otimizações executadas no modo de liberação podem mascarar alguns MSIL em cenários de bloqueio do carregador.

## <a name="how-to-debug-loader-lock-issues"></a>Como depurar problemas de bloqueio do carregador

O diagnóstico que o CLR gera quando uma função MSIL é invocada faz com que o CLR suspender a execução. Por sua vez, isso faz com que o depurador de modo misto do Visual C++ deve ser suspensa bem ao executar o depurador em processo. No entanto, ao anexar ao processo, não é possível obter uma pilha de chamadas gerenciada para o depurador usando o depurador misto.

Para identificar a função específica do MSIL que foi chamada em bloqueio do carregador, os desenvolvedores devem concluir as etapas a seguir:

1. Certifique-se de que os símbolos de mscoree. dll e o arquivo mscorwks.dll estão disponíveis.

   Isso pode ser feito de duas maneiras. Primeiro, PDBs para mscoree. dll e o arquivo mscorwks.dll podem ser adicionados ao caminho de pesquisa de símbolo. Para fazer isso, abra a caixa de diálogo de opções de caminho de pesquisa de símbolo. (Da **ferramentas** menu, escolha **opções**. No painel esquerdo do **opções** caixa de diálogo, abra o **depuração** nó e escolha **símbolos**.) Adicione o caminho para os arquivos PDB mscoree. dll e o arquivo mscorwks.dll à lista de pesquisa. Esses PDBs são instalados em % VSINSTALLDIR%\SDK\v2.0\symbols. Escolha **OK**.

   Em segundo lugar, PDBs para mscoree. dll e o arquivo mscorwks.dll podem ser baixados do servidor de símbolo Microsoft. Para configurar o servidor de símbolos, abra a caixa de diálogo de opções de caminho de pesquisa de símbolo. (Da **ferramentas** menu, escolha **opções**. No painel esquerdo do **opções** caixa de diálogo, abra o **depuração** nó e escolha **símbolos**.) Adicione o seguinte caminho de pesquisa à lista de pesquisa: http://msdl.microsoft.com/download/symbols. Adicione um diretório de cache de símbolo de caixa de texto de cache do servidor de símbolo. Escolha **OK**.

1. Definir o modo de depurador para o modo somente nativo.

   Para fazer isso, abra o **propriedades** grade para o projeto de inicialização na solução. Selecione **propriedades de configuração** > **depuração**. Definir o **tipo de depurador** para **somente nativo**.

1. Inicie o depurador (F5).
  
1. Quando o **/clr** diagnóstico é gerado, escolha **novamente** e, em seguida, escolha **quebra**.
  
1. Abra a janela pilha de chamadas. (Na barra de menus, escolha **depurar** > **Windows** > **pilha de chamadas**.) Ofensivo `DllMain` ou inicializador estático é identificado com uma seta verde. Se a função ofensiva não for identificada, as etapas a seguir devem ser executadas para localizá-lo.

1. Abra o **imediato** janela (na barra de menus, escolha **depurar** > **Windows** > **imediato**.)

1. Digite .load SOS. dll para o **imediato** janela ao carregar o serviço de depuração SOS.
  
1. Tipo! dumpstack para o **imediato** janela para obter uma lista completa de interno **/clr** pilha.

1. Para a primeira instância (próxima à parte inferior da pilha) de qualquer cordllmain (se `DllMain` faz com que o problema) ou _VTableBootstrapThunkInitHelperStub ou GetTargetForVTableEntry (se um inicializador estático faz com que o problema). A entrada de pilha logo abaixo desta chamada é que a invocação do MSIL implementado função que tentou executar sob bloqueio do carregador.

1. Vá para o arquivo de origem e a linha número identificado na etapa anterior e corrigir o problema usando os cenários e as soluções descritas na seção de cenários.

## <a name="example"></a>Exemplo

### <a name="description"></a>Descrição

O exemplo a seguir mostra como evitar o bloqueio do carregador movendo o código de `DllMain` no construtor de um objeto global.

Neste exemplo, há um objeto gerenciado global cujo construtor contém o objeto gerenciado que foi originalmente em `DllMain`. A segunda parte deste exemplo referencia o assembly, criando uma instância do objeto gerenciado a chamar o construtor do módulo que faz a inicialização.

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

Este exemplo demonstra a problemas na inicialização de assemblies mistos:

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
