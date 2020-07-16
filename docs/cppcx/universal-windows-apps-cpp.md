---
title: Aplicativos universais do Windows (C++)
ms.date: 03/30/2018
ms.assetid: 357121cc-d390-4bae-b34a-39614861a9f4
ms.topic: overview
ms.openlocfilehash: 25b89d2d9cb99e05145e60f9c9b1a6324fbbeb39
ms.sourcegitcommit: 6b3d793f0ef3bbb7eefaf9f372ba570fdfe61199
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/15/2020
ms.locfileid: "86404594"
---
# <a name="universal-windows-apps-c"></a>Aplicativos universais do Windows (C++)

O Plataforma Universal do Windows (UWP) é a interface de programação moderna para o Windows. Com o UWP, você escreve um aplicativo ou componente uma vez e o implanta em qualquer dispositivo Windows 10. Você pode escrever um componente em C++ e os aplicativos escritos em qualquer outra linguagem compatível com UWP podem usá-lo.

A maior parte da documentação do UWP está na árvore de conteúdo do Windows na [documentação plataforma universal do Windows](/windows/uwp/). Lá, você encontrará tutoriais de início, bem como documentação de referência.

Para novos aplicativos e componentes UWP, recomendamos que você use [C++/WinRT](/windows/uwp/cpp-and-winrt-apis/), uma nova projeção de linguagem c++ 17 padrão para APIs de Windows Runtime. O C++/WinRT está disponível no SDK do Windows 10 da versão 1803 em diante. O C++/WinRT é implementado inteiramente em arquivos de cabeçalho e foi projetado para fornecer a você acesso de primeira classe à API moderna do Windows. Diferentemente da implementação do C++/CX, o C++/WinRT não usa sintaxe não padrão nem extensões de linguagem da Microsoft, e aproveita totalmente o compilador C++ para criar uma saída altamente otimizada. Para obter mais informações, consulte [introdução ao C++/WinRT](/windows/uwp/cpp-and-winrt-apis/intro-to-using-cpp-with-winrt).

Você pode usar o conversor de aplicativo de ponte de área de trabalho para empacotar seu aplicativo de área de trabalho existente para implantação por meio do Microsoft Store. Para obter mais informações, consulte [Using Visual C++ Runtime in Centennial Project](https://devblogs.microsoft.com/cppblog/using-visual-c-runtime-in-centennial-project/) and [Desktop Bridge](/windows/uwp/porting/desktop-to-uwp-root).

## <a name="uwp-apps-that-use-ccx"></a>Aplicativos UWP que usam C++/CX

|||
|-|-|
|[Referência da linguagem C++/CX](visual-c-language-reference-c-cx.md)|Descreve o conjunto de extensões que simplificam o consumo de C++ de Windows Runtime de APIs e habilitam o tratamento de erros com base em exceções.|
|[Criando aplicativos e bibliotecas (C++/CX)](building-apps-and-libraries-c-cx.md)|Descreve como criar DLLs e bibliotecas estáticas que podem ser acessadas de um aplicativo ou componente C++/CX.|
|[Tutorial: criar um aplicativo "Olá, mundo" UWP em C++/CX](/windows/uwp/get-started/create-a-basic-windows-10-app-in-cpp)|Uma explicação que apresenta os conceitos básicos do desenvolvimento de aplicativos UWP em C++/CX. |
|[Criando componentes de Windows Runtime em C++/CX](/windows/uwp/winrt-components/creating-windows-runtime-components-in-cpp)|Descreve como criar DLLs que outros aplicativos e componentes UWP podem consumir.|
|[Programação de jogos UWP](/windows/uwp/gaming/)|Descreve como usar o DirectX e C++/CX para criar jogos.|

## <a name="uwp-apps-that-use-the-windows-runtime-c-template-library-wrl"></a>Aplicativos UWP que usam a Windows Runtime WRL (biblioteca de modelos C++)

A biblioteca de modelos do Windows Runtime C++ fornece as interfaces COM de baixo nível pelas quais o código ISO C++ pode acessar o Windows Runtime em um ambiente sem exceções. Na maioria dos casos, recomendamos que você use C++/WinRT ou C++/CX em vez da biblioteca de modelos do Windows Runtime C++ para desenvolvimento de aplicativos UWP. Para obter informações sobre a Windows Runtime biblioteca de modelos C++, consulte [Windows Runtime C++ Template Library (WRL)](wrl/windows-runtime-cpp-template-library-wrl.md).

## <a name="see-also"></a>Confira também

[C++ no Visual Studio](../overview/visual-cpp-in-visual-studio.md)<br/>
[Visão geral da programação do Windows em C++](../windows/overview-of-windows-programming-in-cpp.md)<br/>
