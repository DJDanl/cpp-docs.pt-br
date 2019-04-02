---
title: Aplicativos universais do Windows (C++)
ms.date: 03/30/2018
ms.assetid: 357121cc-d390-4bae-b34a-39614861a9f4
ms.openlocfilehash: fbd5366ee52dfe32baef9458a82c16914666699e
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58783739"
---
# <a name="universal-windows-apps-c"></a>Aplicativos universais do Windows (C++)

A Universal Windows Platform (UWP) é a interface de programação modernos para Windows. Com UWP, você escreve um aplicativo ou componente once e implantá-lo em qualquer dispositivo Windows 10. Você pode escrever um componente em C++ e os aplicativos escritos em qualquer outra linguagem compatível com a UWP podem usá-lo.

A maioria da documentação do UWP está na árvore de conteúdo do Windows no [documentação da plataforma Universal do Windows](/windows/uwp/). Lá você encontrará tutoriais de início, bem como documentação de referência. 

Para novos aplicativos UWP e componentes, é recomendável que você use [C + + c++ /CLI WinRT](/windows/uwp/cpp-and-winrt-apis/), uma novo padrão C + + 17 projeção de linguagem para APIs do Windows Runtime. C + + c++ /CLI WinRT está disponível no SDK do Windows 10, versão 1803 em diante. C + + c++ /CLI WinRT é implementado inteiramente em arquivos de cabeçalho e foi projetado para fornecer acesso de primeira classe à moderna API do Windows. Ao contrário do C + + / implementação do CX. C + + c++ /CLI WinRT não usa a sintaxe não padrão ou extensões de linguagem da Microsoft e tira total proveito do compilador do C++ para criar uma saída altamente otimizada. Para obter mais informações, consulte [Introdução ao C + + c++ /CLI WinRT](/windows/uwp/cpp-and-winrt-apis/intro-to-using-cpp-with-winrt).

Você pode usar o conversor de aplicativo de ponte de Desktop para empacotar o aplicativo de área de trabalho existente para implantação por meio do Microsoft Store. Para obter mais informações, consulte [usando o Visual C++ Runtime em projeto Centennial](https://blogs.msdn.microsoft.com/vcblog/2016/07/07/using-visual-c-runtime-in-centennial-project) e [ponte de Desktop](/windows/uwp/porting/desktop-to-uwp-root).

## <a name="uwp-apps-that-use-ccx"></a>Aplicativos UWP que usam C + + c++ /CX

|||
|-|-|
|[Referência de linguagem do Visual C++ (C++ c++ /CX)](visual-c-language-reference-c-cx.md)|Descreve o conjunto de extensões que simplificam o consumo de C++ de APIs do Windows Runtime e permitem a manipulação de erros que se baseia em exceções.|
|[Compilando aplicativos e bibliotecas (C++/CX)](building-apps-and-libraries-c-cx.md)|Descreve como criar DLLs e bibliotecas estáticas que podem ser acessadas a partir de um c++ /CX aplicativo ou componente.|
|[Tutorial: Criar uma UWP aplicativo "Olá, mundo" no C + + c++ /CX](/windows/uwp/get-started/create-a-basic-windows-10-app-in-cpp)|Um passo a passo que apresenta os conceitos básicos do desenvolvimento de aplicativos UWP no C + + c++ /CLI CX. |
|[Criando componentes de tempo de execução do Windows em C + + c++ /CX](/windows/uwp/winrt-components/creating-windows-runtime-components-in-cpp)|Descreve como criar DLLs que outros aplicativos da UWP e componentes podem consumir.|
|[Programação de jogos de UWP](/windows/uwp/gaming/)|Descreve como usar DirectX e C++ c++ /CX para criar jogos.|

## <a name="uwp-apps-that-use-the-windows-runtime-c-template-library-wrl"></a>Aplicativos UWP que usam a biblioteca de modelos C++ do Windows Runtime (WRL)

A biblioteca de modelos de C++ de tempo de execução do Windows fornece as interfaces COM baixo nível pelo qual o código ISO C++ pode acessar o tempo de execução do Windows em um ambiente sem exceções. Na maioria dos casos, é recomendável que você use C + + c++ /CLI WinRT ou C + + c++ /CX em vez da biblioteca de modelos do Windows em tempo de execução C++ para desenvolvimento de aplicativos UWP. Para obter informações sobre a biblioteca de modelos C++ do Windows Runtime, consulte [biblioteca de modelos em C++ Windows Runtime (WRL)](wrl/windows-runtime-cpp-template-library-wrl.md).

## <a name="see-also"></a>Consulte também

[C++ no Visual Studio](../overview/visual-cpp-in-visual-studio.md)<br/>
[Visão geral da programação do Windows no C++](../windows/overview-of-windows-programming-in-cpp.md)<br/>