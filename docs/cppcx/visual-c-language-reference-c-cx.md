---
title: Referência de linguagem Visual C++ (C++/CX)
ms.date: 09/15/2017
ms.assetid: 3f6abf92-4e5e-4ed8-8e11-f9252380d30a
ms.openlocfilehash: ce0272499b653b9077a891e39e9b29797e7e051d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62384940"
---
# <a name="visual-c-language-reference-ccx"></a>Referência de linguagem Visual C++ (C++/CX)

C++/CX é um conjunto de extensões para o C++ linguagem que permitem a criação de aplicativos do Windows e os componentes de tempo de execução do Windows em um idioma que é o mais próximo possível moderno C++. Use C++/CX para escrever aplicativos do Windows e componentes no formato nativo de código que facilmente interagir com o Visual C#, Visual Basic e JavaScript e outras linguagens que dão suporte ao tempo de execução do Windows. Nos raros casos em que exigem acesso direto a interfaces COM brutas, ou um código não excepcional, você pode usar o [biblioteca de modelos em C++ Windows Runtime (WRL)](../windows/windows-runtime-cpp-template-library-wrl.md).

> [!NOTE]
> **[C++/ WinRT](/windows/uwp/cpp-and-winrt-apis/index) é a alternativa recomendada para C++/CX**. É uma nova, o padrão C + + 17 projeção de linguagem para APIs do tempo de execução do Windows, disponível no Windows 10 SDK mais recente da versão 1803 em diante. C++/ WinRT é implementado inteiramente em arquivos de cabeçalho e projetado para fornecer acesso de primeira classe à moderna API do Windows.
>
> Com o C++/WinRT, você pode consumir e criar APIs do Windows Runtime usando qualquer compilador que 17 compatível com os padrões C + +. C++/ WinRT normalmente tem um desempenho melhor e produz binários menores do que qualquer outra opção de idioma para o tempo de execução do Windows. Continuaremos a dar suporte a C++/CX e WRL, mas altamente recomendável que novos aplicativos usem C++/WinRT. Para obter mais informações, consulte [ C++/WinRT](/windows/uwp/cpp-and-winrt-apis/index).

Usando C++/CX, você pode criar:

- Aplicativos de C++ Universal Windows Platform (UWP) que usam XAML para definir o usuário de interface e usam a pilha nativa. Para obter mais informações, consulte [criar um aplicativo "hello world" em C++ (UWP)](/windows/uwp/get-started/create-a-basic-windows-10-app-in-cpp).

- Componentes de tempo de execução do C++ Windows que podem ser consumidos por aplicativos do Windows baseados em JavaScript. Para obter mais informações, consulte [Creating Windows Runtime Components in C++](/windows/uwp/winrt-components/creating-windows-runtime-components-in-cpp).

- Jogos do Windows DirectX e aplicativos intensivos de elementos gráficos. Para obter mais informações, consulte [criar um jogo UWP simples com o DirectX](/windows/uwp/gaming/tutorial--create-your-first-uwp-directx-game).

## <a name="related-articles"></a>Artigos relacionados

|||
|-|-|
|[Referência rápida](../cppcx/quick-reference-c-cx.md)|Tabela de palavras-chave e operadores para C++/CX.|
|[Sistema de tipos](../cppcx/type-system-c-cx.md)|Descreve o básico C++tipos /CX e construções de programação e como utilizar C++/CX consumir e criar tipos de tempo de execução do Windows.|
|[Como compilar aplicativos e bibliotecas](../cppcx/building-apps-and-libraries-c-cx.md)|Discute como usar o IDE para criar aplicativos e vincular a bibliotecas estáticas e DLLs.|
|[Como interoperar com outras linguagens](../cppcx/interoperating-with-other-languages-c-cx.md)|Discute como componentes que são escritos usando C++/CX pode ser usado com componentes escritos em JavaScript, qualquer gerenciado idioma ou o tempo de execução do Windows C++ biblioteca de modelos.|
|[Threading e Marshaling](../cppcx/threading-and-marshaling-c-cx.md)|Discute como especificar comportamento de threading e marshaling dos componentes que você cria.|
|[Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)|Consulte a documentação do namespace padrão, do namespace Platform, Platform::Collections e dos namespaces relacionados.|
|[As funções de CRT não têm suporte em aplicativos da Plataforma Universal do Windows](../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md)|Relaciona as funções CRT não disponíveis para uso em aplicativos de Tempo de Execução do Windows.|
|[Manuais de instruções dos aplicativos do Windows 10](https://msdn.microsoft.com/library/windows/apps/xaml/mt244352.aspx)|Fornece instruções de alto nível sobre aplicativos do Windows 10 e links para mais informações.|
|[C++/CX parte 0 de \[n\]: Uma introdução](https://blogs.msdn.microsoft.com/vcblog/2012/08/29/ccx-part-0-of-n-an-introduction/)<br /><br />[C++/CX parte 1 de \[n\]: Uma classe simples](https://blogs.msdn.microsoft.com/vcblog/2012/09/05/ccx-part-1-of-n-a-simple-class/)<br /><br />[C++/CX parte 2 de \[n\]: Tipos que desempenham funções diferentes](https://blogs.msdn.microsoft.com/vcblog/2012/09/17/ccx-part-2-of-n-types-that-wear-hats/)<br /><br />[C++/CX parte 3 de \[n\]: Em construção](https://blogs.msdn.microsoft.com/vcblog/2012/10/05/ccx-part-3-of-n-under-construction/)<br /><br />[C++/CX parte 4 de \[n\]: Funções de membro estático](https://blogs.msdn.microsoft.com/vcblog/2012/10/19/ccx-part-4-of-n-static-member-functions/)|Um elemento Visual introdutório C++ série de blog sobre C++/CX.|
