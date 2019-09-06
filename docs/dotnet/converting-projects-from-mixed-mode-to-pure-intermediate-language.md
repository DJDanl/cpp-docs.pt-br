---
title: Convertendo projetos do modo misto em linguagem intermediária pura
ms.date: 08/19/2019
helpviewer_keywords:
- intermediate language, mixed-mode applications
- mixed-mode applications
- mixed-mode applications, intermediate language
- projects [C++], converting to intermediate language
ms.assetid: 855f9e3c-4f09-4bfe-8eab-a45f68292be9
ms.openlocfilehash: 05ece23e6d79fc399085099deebcde0aa4a92c64
ms.sourcegitcommit: 9d4ffb8e6e0d70520a1e1a77805785878d445b8a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/20/2019
ms.locfileid: "70311631"
---
# <a name="converting-projects-from-mixed-mode-to-pure-intermediate-language"></a>Convertendo projetos do modo misto em linguagem intermediária pura

Todos os C++ projetos do Visual CLR são vinculados às bibliotecas de tempo de execução do C por padrão. Consequentemente, esses projetos são classificados como aplicativos de modo misto, pois eles combinam código nativo com código direcionado ao Common Language Runtime (código gerenciado). Quando eles são compilados, eles são compilados na IL (linguagem intermediária), também conhecida como MSIL (Microsoft Intermediate Language).

> [!IMPORTANT]
> O Visual Studio 2015 foi preterido e o Visual Studio 2017 não dá mais suporte à criação de código **/CLR: Pure** ou **/CLR: safe** para aplicativos CLR. Se você precisar de assemblies puros ou seguros, é recomendável traduzir seu C#aplicativo para o.

Se você estiver usando uma versão anterior do conjunto de C++ ferramentas do compilador da Microsoft que dá suporte a **/CLR: Pure** ou **/CLR: safe**, você poderá usar este procedimento para converter seu código para MSIL puro:

### <a name="to-convert-your-mixed-mode-application-into-pure-intermediate-language"></a>Para converter seu aplicativo de modo misto em linguagem intermediária pura

1. Remover links para as [bibliotecas de tempo de execução do C](../c-runtime-library/crt-library-features.md) (CRT):

   1. No arquivo. cpp que define o ponto de entrada do seu aplicativo, altere o ponto de `Main()`entrada para. O `Main()` uso de indica que seu projeto não é vinculado ao CRT.

   2. Em Gerenciador de Soluções, clique com o botão direito do mouse no projeto e selecione **Propriedades** no menu de atalho para abrir as páginas de propriedades do seu aplicativo.

   3. Na página de propriedades **avançado** do projeto para o **vinculador**, selecione o **ponto de entrada** e, em seguida, insira **principal** nesse campo.

   4. Para aplicativos de console, na página de propriedades projeto do **sistema** para o **vinculador**, selecione o campo **subsistema** e altere-o para **console (/SUBSYSTEM: console)** .

      > [!NOTE]
      > Você não precisa definir essa propriedade para Windows Forms aplicativos porque o campo **subsistema** está definido como **Windows (/SUBSYSTEM: Windows)** por padrão.

   5. Em *stdafx. h*, comente todas as `#include` instruções. Por exemplo, em aplicativos de console:

      ```cpp
      // #include <iostream>
      // #include <tchar.h>
      ```

       - ou -

       Por exemplo, em aplicativos Windows Forms:

      ```cpp
      // #include <stdlib.h>
      // #include <malloc.h>
      // #include <memory.h>
      // #include <tchar.h>
      ```

   6. Para Windows Forms aplicativos, em Form1. cpp, comente a instrução `#include` que faz referência ao Windows. h. Por exemplo:

      ```cpp
      // #include <windows.h>
      ```

2. Adicione o seguinte código a *stdafx. h*:

   ```cpp
   #ifndef __FLTUSED__
   #define __FLTUSED__
      extern "C" __declspec(selectany) int _fltused=1;
   #endif
   ```

3. Remover todos os tipos não gerenciados:

   Sempre que apropriado, substitua os tipos não gerenciados por referências a estruturas do namespace [System](/dotnet/api/system) . Os tipos gerenciados comuns são listados na tabela a seguir:

   |Estrutura|Descrição|
   |---------------|-----------------|
   |[Booliano](/dotnet/api/system.boolean)|Representa um valor booliano.|
   |[Byte](/dotnet/api/system.byte)|Representa um inteiro sem sinal de 8 bits.|
   |[Char](/dotnet/api/system.char)|Representa um caractere Unicode.|
   |[DateTime](/dotnet/api/system.datetime)|Representa um momento no tempo, geralmente expresso como uma data e hora do dia.|
   |[Decimal](/dotnet/api/system.decimal)|Representa um número decimal.|
   |[Duplo](/dotnet/api/system.double)|Representa um número de ponto flutuante de precisão dupla.|
   |[Guid](/dotnet/api/system.guid)|Representa um identificador global exclusivo (GUID).|
   |[Int16](/dotnet/api/system.int16)|Representa um inteiro com sinal de 16 bits.|
   |[Int32](/dotnet/api/system.int32)|Representa um inteiro com sinal de 32 bits.|
   |[Int64](/dotnet/api/system.int64)|Representa um inteiro com sinal de 64 bits.|
   |[IntPtr](/dotnet/api/system.intptr)|Um tipo específico da plataforma que é usado para representar um ponteiro ou um identificador.|
   |[SByte](/dotnet/api/system.byte)|Representa um inteiro com sinal de 8 bits.|
   |[Simples](/dotnet/api/system.single)|Representa um número de ponto flutuante de precisão simples.|
   |[TimeSpan](/dotnet/api/system.timespan)|Representa um intervalo de tempo.|
   |[UInt16](/dotnet/api/system.uint16)|Representa um inteiro sem sinal de 16 bits.|
   |[UInt32](/dotnet/api/system.uint32)|Representa um inteiro sem sinal de 32 bits.|
   |[UInt64](/dotnet/api/system.uint64)|Representa um inteiro sem sinal de 64 bits.|
   |[UIntPtr](/dotnet/api/system.uintptr)|Um tipo específico da plataforma que é usado para representar um ponteiro ou um identificador.|
   |[Livre](/dotnet/api/system.void)|Indica um método que não retorna um valor; ou seja, o método tem o tipo de retorno void.|