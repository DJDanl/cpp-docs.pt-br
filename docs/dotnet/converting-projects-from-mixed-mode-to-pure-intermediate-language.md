---
title: Convertendo projetos do modo misto em linguagem intermediária pura
ms.date: 08/19/2019
helpviewer_keywords:
- intermediate language, mixed-mode applications
- mixed-mode applications
- mixed-mode applications, intermediate language
- projects [C++], converting to intermediate language
ms.assetid: 855f9e3c-4f09-4bfe-8eab-a45f68292be9
ms.openlocfilehash: 8b22f3aaf706fa096f6c25ab8e9fdab6dc512cd8
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80208792"
---
# <a name="converting-projects-from-mixed-mode-to-pure-intermediate-language"></a>Convertendo projetos do modo misto em linguagem intermediária pura

Todos os C++ projetos do Visual CLR são vinculados às bibliotecas de tempo de execução do C por padrão. Consequentemente, esses projetos são classificados como aplicativos de modo misto, pois eles combinam código nativo com código direcionado ao Common Language Runtime (código gerenciado). Quando eles são compilados, eles são compilados na IL (linguagem intermediária), também conhecida como MSIL (Microsoft Intermediate Language).

> [!IMPORTANT]
> O Visual Studio 2015 foi preterido e o Visual Studio 2017 não dá mais suporte à criação de código **/CLR: Pure** ou **/CLR: safe** para aplicativos CLR. Se você precisar de assemblies puros ou seguros, é recomendável traduzir seu C#aplicativo para o.

Se você estiver usando uma versão anterior do conjunto de C++ ferramentas do compilador da Microsoft que dá suporte a **/CLR: Pure** ou **/CLR: safe**, você poderá usar este procedimento para converter seu código para MSIL puro:

### <a name="to-convert-your-mixed-mode-application-into-pure-intermediate-language"></a>Para converter seu aplicativo de modo misto em linguagem intermediária pura

1. Remover links para as [bibliotecas de tempo de execução do C](../c-runtime-library/crt-library-features.md) (CRT):

   1. No arquivo. cpp que define o ponto de entrada do seu aplicativo, altere o ponto de entrada para `Main()`. O uso de `Main()` indica que o projeto não é vinculado ao CRT.

   2. Em Gerenciador de Soluções, clique com o botão direito do mouse no projeto e selecione **Propriedades** no menu de atalho para abrir as páginas de propriedades do seu aplicativo.

   3. Na página de propriedades **avançado** do projeto para o **vinculador**, selecione o **ponto de entrada** e, em seguida, insira **principal** nesse campo.

   4. Para aplicativos de console, na página de propriedades projeto do **sistema** para o **vinculador**, selecione o campo **subsistema** e altere-o para **console (/SUBSYSTEM: console)** .

      > [!NOTE]
      > Você não precisa definir essa propriedade para Windows Forms aplicativos porque o campo **subsistema** está definido como **Windows (/SUBSYSTEM: Windows)** por padrão.

   5. Em *stdafx. h*, comente todas as instruções de `#include`. Por exemplo, em aplicativos de console:

      ```cpp
      // #include <iostream>
      // #include <tchar.h>
      ```

       -ou-

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

   |Estrutura|DESCRIÇÃO|
   |---------------|-----------------|
   |[Booliano](/dotnet/api/system.boolean)|{1&gt;Representa um valor booliano.&lt;1}|
   |[Byte](/dotnet/api/system.byte)|{1&gt;Representa um inteiro sem sinal de 8 bits.&lt;1}|
   |[Char](/dotnet/api/system.char)|{1&gt;Representa um caractere Unicode.&lt;1}|
   |[DateTime](/dotnet/api/system.datetime)|Representa um momento no tempo, geralmente expresso como uma data e hora do dia.|
   |[Decimal](/dotnet/api/system.decimal)|{1&gt;Representa um número decimal.&lt;1}|
   |[Double](/dotnet/api/system.double)|{1&gt;Representa um número de ponto flutuante de precisão dupla.&lt;1}|
   |[Guid](/dotnet/api/system.guid)|{1&gt;Representa um identificador global exclusivo (GUID).&lt;1}|
   |[Int16](/dotnet/api/system.int16)|{1&gt;Representa um inteiro com sinal de 16 bits.&lt;1}|
   |[Int32](/dotnet/api/system.int32)|{1&gt;Representa um inteiro com sinal de 32 bits.&lt;1}|
   |[Int64](/dotnet/api/system.int64)|{1&gt;Representa um inteiro com sinal de 64 bits.&lt;1}|
   |[IntPtr](/dotnet/api/system.intptr)|{1&gt;Um tipo específico da plataforma que é usado para representar um ponteiro ou um identificador.&lt;1}|
   |[SByte](/dotnet/api/system.byte)|{1&gt;Representa um inteiro com sinal de 8 bits.&lt;1}|
   |[Single](/dotnet/api/system.single)|{1&gt;Representa um número de ponto flutuante de precisão simples.&lt;1}|
   |[TimeSpan](/dotnet/api/system.timespan)|{1&gt;Representa um intervalo de tempo.&lt;1}|
   |[UInt16](/dotnet/api/system.uint16)|{1&gt;Representa um inteiro sem sinal de 16 bits.&lt;1}|
   |[UInt32](/dotnet/api/system.uint32)|{1&gt;Representa um inteiro sem sinal de 32 bits.&lt;1}|
   |[UInt64](/dotnet/api/system.uint64)|{1&gt;Representa um inteiro sem sinal de 64 bits.&lt;1}|
   |[UIntPtr](/dotnet/api/system.uintptr)|{1&gt;Um tipo específico da plataforma que é usado para representar um ponteiro ou um identificador.&lt;1}|
   |[Livre](/dotnet/api/system.void)|Indica um método que não retorna um valor; ou seja, o método tem o tipo de retorno void.|
