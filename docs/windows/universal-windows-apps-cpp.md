---
title: Aplicativos universais do Windows (C++)
ms.date: 03/30/2018
ms.assetid: 357121cc-d390-4bae-b34a-39614861a9f4
ms.openlocfilehash: 3ffcc38dfd849c9cd5eaf9e6466d53731becdd9a
ms.sourcegitcommit: b032daf81cb5fdb1f5a988277ee30201441c4945
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/15/2018
ms.locfileid: "51693081"
---
# <a name="universal-windows-apps-c"></a>Aplicativos universais do Windows (C++)

Aplicativos universais do Windows Platform (UWP) incorporam um conjunto de princípios de design que enfatizam a interfaces do usuário simples que são centralizadas em torno do conteúdo que ajusta automaticamente para diferentes tamanhos de tela em dispositivos diferentes. Você pode criar a interface do usuário na marcação XAML e o code-behind em C++ nativo. Você também pode criar componentes (DLLs) que podem ser consumidos por aplicativos UWP que são escritos em outras linguagens. A superfície de API para aplicativos UWP é o tempo de execução do Windows, que é uma biblioteca bem fatorada que fornece uma ampla variedade de serviços do sistema operacional.

> [!TIP]
> Para Windows 10, você pode usar o conversor de aplicativo de ponte de Desktop para empacotar o aplicativo de área de trabalho existente para implantação por meio do Microsoft Store. Para obter mais informações, consulte [usando o Visual C++ Runtime em projeto Centennial](https://blogs.msdn.microsoft.com/vcblog/2016/07/07/using-visual-c-runtime-in-centennial-project) e [ponte de Desktop](/windows/uwp/porting/desktop-to-uwp-root).

## <a name="uwp-apps-that-use-cwinrt"></a>Aplicativos UWP que usam C + + c++ /CLI WinRT

C + + c++ /CLI WinRT é uma nova e somente cabeçalho baseada na biblioteca C++ projeção de linguagem para o tempo de execução do Windows que usa C++ completamente padrão, ao contrário do C + + / implementação do CX. C + + c++ /CLI WinRT não usa a sintaxe não padrão ou extensões de linguagem da Microsoft e tira total proveito do compilador do C++ para criar uma saída altamente otimizada. Para obter mais informações, consulte [C + + c++ /CLI WinRT](/windows/uwp/cpp-and-winrt-apis). Para obter uma introdução ao C + + / WinRT e um início rápido de código, consulte [Introdução ao C + + c++ /CLI WinRT](/windows/uwp/cpp-and-winrt-apis/intro-to-using-cpp-with-winrt).

## <a name="uwp-apps-that-use-ccx"></a>Aplicativos UWP que usam C + + c++ /CX

|||
|-|-|
|[Referência de linguagem do Visual C++ (C++ c++ /CX)](../cppcx/visual-c-language-reference-c-cx.md)|Descreve o conjunto de extensões que simplificam o consumo de C++ de APIs do Windows Runtime e permitem a manipulação de erros que se baseia em exceções.|
|[Compilando aplicativos e bibliotecas (C++/CX)](../cppcx/building-apps-and-libraries-c-cx.md)|Descreve como criar DLLs e bibliotecas estáticas que podem ser acessadas a partir de um c++ /CX aplicativo ou componente.|
|[Tutorial: Criar uma UWP aplicativo "Olá, mundo" no C + + c++ /CX](/windows/uwp/get-started/create-a-basic-windows-10-app-in-cpp)|Um passo a passo que apresenta os conceitos básicos do desenvolvimento de aplicativos UWP no C + + c++ /CLI CX. |
|[Criando componentes de tempo de execução do Windows em C + + c++ /CX](/windows/uwp/winrt-components/creating-windows-runtime-components-in-cpp)|Descreve como criar DLLs que outros aplicativos da UWP e componentes podem consumir.|
|[Programação de jogos de UWP](/windows/uwp/gaming/)|Descreve como usar DirectX e C++ c++ /CX para criar jogos.|

## <a name="uwp-apps-that-use-the-windows-runtime-c-template-library-wrl"></a>Aplicativos UWP que usam a biblioteca de modelos C++ do Windows Runtime (WRL)

A biblioteca de modelos de C++ de tempo de execução do Windows fornece as interfaces COM baixo nível pelo qual o código ISO C++ pode acessar o tempo de execução do Windows em um ambiente sem exceções. Na maioria dos casos, é recomendável que você use C + + c++ /CLI WinRT ou C + + c++ /CX em vez da biblioteca de modelos do Windows em tempo de execução C++ para desenvolvimento de aplicativos UWP. Para obter informações sobre a biblioteca de modelos C++ do Windows Runtime, consulte [biblioteca de modelos em C++ Windows Runtime (WRL)](windows-runtime-cpp-template-library-wrl.md).

## <a name="see-also"></a>Consulte também

[Visual C++](../visual-cpp-in-visual-studio.md)<br/>
[Visão geral da programação do Windows no C++](overview-of-windows-programming-in-cpp.md)<br/>