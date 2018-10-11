---
title: Converter projetos do modo em linguagem intermediária pura misto | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- intermediate language, mixed-mode applications
- mixed-mode applications
- mixed-mode applications, intermediate language
- projects [C++], converting to intermediate language
ms.assetid: 855f9e3c-4f09-4bfe-8eab-a45f68292be9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 7f9cbfce7e04040f0e1618148a3c258f21bb84b8
ms.sourcegitcommit: 3a141cf07b5411d5f1fdf6cf67c4ce928cf389c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/11/2018
ms.locfileid: "49083457"
---
# <a name="converting-projects-from-mixed-mode-to-pure-intermediate-language"></a>Convertendo projetos do modo misto em linguagem intermediária pura

Vincular todos os projetos de CLR do Visual C++ para as bibliotecas de tempo de execução C por padrão. Consequentemente, esses projetos são classificados como aplicativos de modo misto, porque eles combinam código nativo com código que tem como alvo o common language runtime (código gerenciado). Quando eles são compilados, são compilados em IL (linguagem intermediária), também conhecido como Microsoft intermediate language (MSIL).

> [!IMPORTANT]
> Preterido do Visual Studio 2015 e Visual Studio 2017 não suporta a criação de **/clr: pure** ou **/CLR: safe** código para aplicativos do CLR. Se você precisar de assemblies puros ou seguros, é recomendável que converter o seu aplicativo c#.

Se você estiver usando uma versão anterior do conjunto de ferramentas de compilador do Visual C++ que dá suporte a **/clr: pure** ou **/CLR: safe**, você pode usar este procedimento para converter seu código em MSIL puro:

### <a name="to-convert-your-mixed-mode-application-into-pure-intermediate-language"></a>Para converter seu aplicativo de modo misto em linguagem intermediária pura

1. Remover links para o [bibliotecas de tempo de execução C](../c-runtime-library/crt-library-features.md) (CRT):

   1. No arquivo. cpp, definindo o ponto de entrada do seu aplicativo, altere o ponto de entrada para `Main()`. Usando `Main()` indica que o seu projeto não vincular ao CRT.

   2. No Gerenciador de soluções, clique em seu projeto e selecione **propriedades** no menu de atalho para abrir as páginas de propriedade para o seu aplicativo.

   3. No **avançado** página de propriedades do projeto para o **vinculador**, selecione o **ponto de entrada** e, em seguida, digite **principal** neste campo.

   4. Para aplicativos de console, no **System** página de propriedades do projeto para o **vinculador**, selecione o **subsistema** do campo e altere-a para **Console (/ Subsystem:console)**.

      > [!NOTE]
      > Você não precisa definir essa propriedade para aplicativos de formulários do Windows porque o **subsistema** campo é definido como **Windows (/ subsistema: WINDOWS)** por padrão.

   5. Em Stdafx. h, comente todas as `#include` instruções. Por exemplo, em aplicativos de console:

      ```cpp
      // #include <iostream>
      // #include <tchar.h>
      ```

       -ou-

       Por exemplo, em aplicativos do Windows Forms:

      ```cpp
      // #include <stdlib.h>
      // #include <malloc.h>
      // #include <memory.h>
      // #include <tchar.h>
      ```

   6. Para aplicativos de formulários do Windows, no Form1, comente o `#include` instrução que referencia o Windows. h. Por exemplo:

      ```cpp
      // #include <windows.h>
      ```

2. Adicione o seguinte código para Stdafx. h:

   ```cpp
   #ifndef __FLTUSED__
   #define __FLTUSED__
      extern "C" __declspec(selectany) int _fltused=1;
   #endif
   ```

3. Remova todos os tipos não gerenciados:

   Onde for apropriado, substitua os tipos não gerenciados por referências às estruturas do [sistema](/dotnet/api/system) namespace. Tipos gerenciados comuns são listados na tabela a seguir:

   |Estrutura|Descrição|
   |---------------|-----------------|
   |[Booliano](/dotnet/api/system.boolean)|Representa um valor booliano.|
   |[Byte](/dotnet/api/system.byte)|Representa um inteiro sem sinal de 8 bits.|
   |[Char](/dotnet/api/system.char)|Representa um caractere Unicode.|
   |[DateTime](/dotnet/api/system.datetime.datetime.aspx)|Representa um momento no tempo, geralmente expresso como uma data e hora do dia.|
   |[Decimal](/dotnet/api/system.decimal)|Representa um número decimal.|
   |[Duplo](/dotnet/api/system.double)|Representa um número de ponto flutuante de precisão dupla.|
   |[Guid](/dotnet/api/system.guid)|Representa um identificador global exclusivo (GUID).|
   |[Int16](/dotnet/api/system.int16)|Representa um inteiro com sinal de 16 bits.|
   |[Int32](/dotnet/api/system.int32)|Representa um inteiro com sinal de 32 bits.|
   |[Int64](/dotnet/api/system.int64)|Representa um inteiro com sinal de 64 bits.|
   |[IntPtr](/dotnet/api/system.intptr)|Um tipo específico da plataforma que é usado para representar um ponteiro ou um identificador.|
   |[SByte](/dotnet/api/system.byte.aspx)|Representa um inteiro com sinal de 8 bits.|
   |[Simples](/dotnet/api/system.single.aspx)|Representa um número de ponto flutuante de precisão simples.|
   |[TimeSpan](/dotnet/api/system.timespan)|Representa um intervalo de tempo.|
   |[UInt16](/dotnet/api/system.uint16)|Representa um inteiro sem sinal de 16 bits.|
   |[UInt32](/dotnet/api/system.uint32)|Representa um inteiro sem sinal de 32 bits.|
   |[UInt64](/dotnet/api/system.uint64)|Representa um inteiro sem sinal de 64 bits.|
   |[UIntPtr](/dotnet/api/system.uintptr)|Um tipo específico da plataforma que é usado para representar um ponteiro ou um identificador.|
   |[void](/dotnet/api/system.void)|Indica um método que não retorna um valor; ou seja, o método tem o tipo de retorno void.|