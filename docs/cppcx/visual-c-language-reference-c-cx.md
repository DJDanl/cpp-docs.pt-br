---
title: Referência da linguagem Visual C++ (C++/CX)
ms.date: 09/15/2017
ms.assetid: 3f6abf92-4e5e-4ed8-8e11-f9252380d30a
ms.openlocfilehash: 97d4f6391a02dd88e15c8fa4145539ab41a4dae3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50599999"
---
# <a name="visual-c-language-reference-ccx"></a>Referência da linguagem Visual C++ (C++/CX)

C + + c++ /CX é um conjunto de extensões para a linguagem C++ que permitem a criação de aplicativos do Windows e os componentes de tempo de execução do Windows em um idioma mais próximo possível modernas do C++. Usar C + + c++ /CX para escrever aplicativos do Windows e componentes em código nativo que interajam facilmente com Visual c#, Visual Basic e JavaScript e outras linguagens que dão suporte ao tempo de execução do Windows. Nos raros casos em que exigem acesso direto a interfaces COM brutas, ou um código não excepcional, você pode usar o [biblioteca de modelos em C++ Windows Runtime (WRL)](../windows/windows-runtime-cpp-template-library-wrl.md).

> [!NOTE]
> **[C + + c++ /CLI WinRT](https://docs.microsoft.com/windows/uwp/cpp-and-winrt-apis/index) é a alternativa recomendada para C + + c++ /CX**. É uma nova, o padrão C + + 17 projeção de linguagem para APIs do tempo de execução do Windows, disponível no Windows 10 SDK mais recente da versão 1803 em diante. C + + c++ /CLI WinRT é implementado inteiramente em arquivos de cabeçalho e projetado para fornecer acesso de primeira classe à moderna API do Windows.

> Com C + + c++ /CLI WinRT, você pode consumir e criar APIs do Windows Runtime usando qualquer compilador que 17 compatível com os padrões C + +. C + + c++ /CLI WinRT normalmente tem um desempenho melhor e produz binários menores do que qualquer outra opção de idioma para o tempo de execução do Windows. Continuaremos a dar suporte a C + + c++ /CLI CX e WRL, mas altamente recomendável que usem novos aplicativos C + + c++ /CLI WinRT. Para obter mais informações, consulte [C + + c++ /CLI WinRT](https://docs.microsoft.com/windows/uwp/cpp-and-winrt-apis/index).

Usando C + + c++ /CX, você pode criar:

- Aplicativos de C++ Universal Windows Platform (UWP) que usam XAML para definir o usuário de interface e usam a pilha nativa. Para obter mais informações, consulte [criar um aplicativo "hello world" em C++ (UWP)](/windows/uwp/get-started/create-a-basic-windows-10-app-in-cpp).

- Componentes de tempo de execução do C++ Windows que podem ser consumidos por aplicativos do Windows baseados em JavaScript. Para obter mais informações, consulte [Creating Windows Runtime Components in C++](/windows/uwp/winrt-components/creating-windows-runtime-components-in-cpp).

- Jogos do Windows DirectX e aplicativos intensivos de elementos gráficos. Para obter mais informações, consulte [criar um jogo UWP simples com o DirectX](/windows/uwp/gaming/tutorial--create-your-first-metro-style-directx-game).

## <a name="related-articles"></a>Artigos relacionados

|||
|-|-|
|[Referência rápida](../cppcx/quick-reference-c-cx.md)|Tabela de palavras-chave e operadores para C + + c++ /CLI CX.|
|[Sistema de tipos](../cppcx/type-system-c-cx.md)|Descreve básico c++ /CLI CX tipos e construções de programação e como utilizar C + + c++ /CLI CX consumir e criar tipos de tempo de execução do Windows.|
|[Compilando aplicativos e bibliotecas](../cppcx/building-apps-and-libraries-c-cx.md)|Discute como usar o IDE para criar aplicativos e associar a bibliotecas estáticas e DLLs.|
|[Interoperando com outras linguagens](../cppcx/interoperating-with-other-languages-c-cx.md)|Discute como componentes que são escritos usando C + + c++ /CLI CX pode ser usado com componentes escritos em JavaScript, qualquer gerenciado idioma ou a biblioteca de modelos C++ do Windows Runtime.|
|[Threading e Marshaling](../cppcx/threading-and-marshaling-c-cx.md)|Discute como especificar comportamento de threading e marshaling dos componentes que você cria.|
|[Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)|Consulte a documentação do namespace padrão, do namespace Platform, Platform::Collections e dos namespaces relacionados.|
|[As funções de CRT não têm suporte em aplicativos da Plataforma Universal do Windows](../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md)|Relaciona as funções CRT não disponíveis para uso em aplicativos de Tempo de Execução do Windows.|
|[Manuais de instruções dos aplicativos do Windows 10](https://msdn.microsoft.com/library/windows/apps/xaml/mt244352.aspx)|Fornece instruções de alto nível sobre aplicativos do Windows 10 e links para mais informações.|
|[C + + c++ /CX parte 0 de \[n\]: uma introdução](https://blogs.msdn.microsoft.com/vcblog/2012/08/29/ccx-part-0-of-n-an-introduction/)<br /><br />[C + + c++ /CX parte 1 de \[n\]: uma classe simples](https://blogs.msdn.microsoft.com/vcblog/2012/09/05/ccx-part-1-of-n-a-simple-class/)<br /><br />[C + + c++ /CX parte 2 de \[n\]: tipos que desempenham funções diferentes](https://blogs.msdn.microsoft.com/vcblog/2012/09/17/ccx-part-2-of-n-types-that-wear-hats/)<br /><br />[C + + c++ /CX parte 3 de \[n\]: em construção](https://blogs.msdn.microsoft.com/vcblog/2012/10/05/ccx-part-3-of-n-under-construction/)<br /><br />[C + + c++ /CX parte 4 de \[n\]: funções membro Static](https://blogs.msdn.microsoft.com/vcblog/2012/10/19/ccx-part-4-of-n-static-member-functions/)|Uma série de blog introdutória do Visual C++ no C + + c++ /CLI CX.|
