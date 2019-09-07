---
title: Aplicativos universais do Windows (C++)
ms.date: 03/30/2018
ms.assetid: 357121cc-d390-4bae-b34a-39614861a9f4
ms.topic: landing-page
ms.openlocfilehash: 68952e93e4f91ac3653a9991802ad42854d9d25a
ms.sourcegitcommit: 180f63704f6ddd07a4172a93b179cf0733fd952d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/06/2019
ms.locfileid: "70741025"
---
# <a name="universal-windows-apps-c"></a>Aplicativos universais do Windows (C++)

O Plataforma Universal do Windows (UWP) é a interface de programação moderna para o Windows. Com o UWP, você escreve um aplicativo ou componente uma vez e o implanta em qualquer dispositivo Windows 10. Você pode escrever um componente no C++ e os aplicativos escritos em qualquer outra linguagem compatível com UWP podem usá-lo.

A maior parte da documentação do UWP está na árvore de conteúdo do Windows na [documentação plataforma universal do Windows](/windows/uwp/). Lá, você encontrará tutoriais de início, bem como documentação de referência. 

Para novos aplicativos e componentes UWP, recomendamos que você use [ C++o/WinRT](/windows/uwp/cpp-and-winrt-apis/), uma nova projeção de linguagem c++ 17 padrão para APIs de Windows Runtime. C++O/WinRT está disponível no SDK do Windows 10 da versão 1803 em diante. C++O/WinRT é implementado inteiramente em arquivos de cabeçalho e foi projetado para fornecer a você acesso de primeira classe à API moderna do Windows. Ao contrário C++da implementação de/CX. C++O/WinRT não usa sintaxe não padrão nem extensões de linguagem da Microsoft, e aproveita totalmente o compilador C++ para criar uma saída altamente otimizada. Para obter mais informações, consulte [Introduction C++to/WinRT](/windows/uwp/cpp-and-winrt-apis/intro-to-using-cpp-with-winrt).

Você pode usar o conversor de aplicativo de ponte de área de trabalho para empacotar seu aplicativo de área de trabalho existente para implantação por meio do Microsoft Store. Para obter mais informações, consulte [using C++ Visual Runtime in Centennial Project](https://blogs.msdn.microsoft.com/vcblog/2016/07/07/using-visual-c-runtime-in-centennial-project) and [Desktop Bridge](/windows/uwp/porting/desktop-to-uwp-root).

## <a name="uwp-apps-that-use-ccx"></a>Aplicativos UWP que usam C++o/CX

|||
|-|-|
|[C++Referência de linguagem/CX](visual-c-language-reference-c-cx.md)|Descreve o conjunto de extensões que simplificam C++ o consumo de Windows Runtime APIs e habilitam o tratamento de erros com base em exceções.|
|[Compilando aplicativos e bibliotecas (C++/CX)](building-apps-and-libraries-c-cx.md)|Descreve como criar DLLs e bibliotecas estáticas que podem ser acessadas C++de um aplicativo ou componente do/CX.|
|[Tutorial: Criar um aplicativo UWP "Olá, mundo" em C++/CX](/windows/uwp/get-started/create-a-basic-windows-10-app-in-cpp)|Uma explicação que apresenta os conceitos básicos do desenvolvimento de aplicativos UWP C++no/CX. |
|[Criando Windows Runtime componentes em C++/CX](/windows/uwp/winrt-components/creating-windows-runtime-components-in-cpp)|Descreve como criar DLLs que outros aplicativos e componentes UWP podem consumir.|
|[Programação de jogos UWP](/windows/uwp/gaming/)|Descreve como usar o DirectX e C++o/CX para criar jogos.|

## <a name="uwp-apps-that-use-the-windows-runtime-c-template-library-wrl"></a>Aplicativos UWP que usam a WRL C++ (biblioteca de modelos de Windows Runtime)

A biblioteca C++ de modelos de Windows Runtime fornece as interfaces com de baixo nível pelas C++ quais o código ISO pode acessar o Windows Runtime em um ambiente sem exceção. Na maioria dos casos, recomendamos que você C++use/WinRT C++ou/CX em vez da C++ biblioteca de modelos Windows Runtime para o desenvolvimento de aplicativos UWP. Para obter informações sobre a C++ Windows Runtime biblioteca de modelos, consulte [Windows Runtime C++ Template Library (WRL)](wrl/windows-runtime-cpp-template-library-wrl.md).

## <a name="see-also"></a>Consulte também

[C++ no Visual Studio](../overview/visual-cpp-in-visual-studio.md)<br/>
[Visão geral da programação do Windows no C++](../windows/overview-of-windows-programming-in-cpp.md)<br/>