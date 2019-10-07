---
title: C++Referência de linguagem/CX
ms.date: 09/15/2017
ms.assetid: 3f6abf92-4e5e-4ed8-8e11-f9252380d30a
ms.openlocfilehash: ed8e2374daf862e99517fb113e869504b7c7aabc
ms.sourcegitcommit: 180f63704f6ddd07a4172a93b179cf0733fd952d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/06/2019
ms.locfileid: "70740863"
---
# <a name="ccx-language-reference"></a>C++Referência de linguagem/CX

C++O/CX é um conjunto de extensões para C++ a linguagem que permite a criação de aplicativos do Windows e Windows Runtime componentes em um idioma que seja o mais próximo possível C++do moderno. Use C++o/CX para escrever aplicativos e componentes do Windows no código nativo que interagem C#facilmente com o Visual, Visual Basic e JavaScript, além de outras linguagens que dão suporte ao Windows Runtime. Nesses casos raros que exigem acesso direto às interfaces COM brutos ou ao código não-excepcional, você pode usar a [WRL ( C++ biblioteca de modelos de Windows Runtime)](../windows/windows-runtime-cpp-template-library-wrl.md).

> [!NOTE]
> **/WinRT é a alternativa recomendada para C++o/CX. [ C++](/windows/uwp/cpp-and-winrt-apis/index)** É uma nova projeção de linguagem C++ 17 padrão para APIs Windows Runtime, disponível no SDK do Windows 10 mais recente da versão 1803 em diante. C++O/WinRT é implementado inteiramente em arquivos de cabeçalho e projetado para fornecer a você acesso de primeira classe à API moderna do Windows.
>
> Com C++o/WinRT, você pode consumir e criar Windows Runtime APIs usando qualquer compilador c++ 17 compatível com padrões. C++O/WinRT normalmente tem um desempenho melhor e produz binários menores do que qualquer outra opção de idioma para o Windows Runtime. Continuaremos a dar suporte a C++/CX e WRL, mas recomendamos que os novos aplicativos usem o C++/WinRT. Saiba mais em [C++/WinRT](/windows/uwp/cpp-and-winrt-apis/index).

Usando C++o/CX, você pode criar:

- C++Os aplicativos Plataforma Universal do Windows (UWP) que usam o XAML para definir a interface do usuário e usar a pilha nativa. Para obter mais informações, consulte [criar um aplicativo "Olá mundo" C++ no (UWP)](/windows/uwp/get-started/create-a-basic-windows-10-app-in-cpp).

- C++Windows Runtime componentes que podem ser consumidos por aplicativos do Windows baseados em JavaScript. Para obter mais informações, consulte [Creating Windows Runtime Components in C++](/windows/uwp/winrt-components/creating-windows-runtime-components-in-cpp).

- Jogos do Windows DirectX e aplicativos intensivos de elementos gráficos. Para obter mais informações, consulte [criar um jogo UWP simples com o DirectX](/windows/uwp/gaming/tutorial--create-your-first-uwp-directx-game).

## <a name="related-articles"></a>Artigos relacionados

|||
|-|-|
|[Referência rápida](../cppcx/quick-reference-c-cx.md)|Tabela de palavras-chave e operadores para C++/CX.|
|[Sistema de tipos](../cppcx/type-system-c-cx.md)|Descreve os C++tipos básicos/CX e construções de programação e como utilizar C++o/CX para consumir e criar Windows Runtime tipos.|
|[Como compilar aplicativos e bibliotecas](../cppcx/building-apps-and-libraries-c-cx.md)|Discute como usar o IDE para criar aplicativos e vincular a bibliotecas e DLLs estáticas.|
|[Como interoperar com outras linguagens](../cppcx/interoperating-with-other-languages-c-cx.md)|Discute como os componentes escritos usando C++o/CX podem ser usados com componentes que são escritos em JavaScript, qualquer linguagem gerenciada ou a Windows Runtime C++ biblioteca de modelos.|
|[Threading e Marshaling](../cppcx/threading-and-marshaling-c-cx.md)|Discute como especificar comportamento de threading e marshaling dos componentes que você cria.|
|[Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)|Consulte a documentação do namespace padrão, do namespace Platform, Platform::Collections e dos namespaces relacionados.|
|[As funções de CRT não têm suporte em aplicativos da Plataforma Universal do Windows](../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md)|Relaciona as funções CRT não disponíveis para uso em aplicativos de Tempo de Execução do Windows.|
|[Introdução aos aplicativos do Windows 10](/windows/uwp/get-started/)|Fornece instruções de alto nível sobre aplicativos do Windows 10 e links para mais informações.|
|[C++/CX, parte 0 \[de\]n: Uma introdução](https://blogs.msdn.microsoft.com/vcblog/2012/08/29/ccx-part-0-of-n-an-introduction/)<br /><br />[C++/CX parte 1 de \[n\]: Uma classe simples](https://blogs.msdn.microsoft.com/vcblog/2012/09/05/ccx-part-1-of-n-a-simple-class/)<br /><br />[C++/CX parte 2 de \[n\]: Tipos que usam chapéus](https://blogs.msdn.microsoft.com/vcblog/2012/09/17/ccx-part-2-of-n-types-that-wear-hats/)<br /><br />[C++/CX parte 3 de \[n\]: Em construção](https://blogs.msdn.microsoft.com/vcblog/2012/10/05/ccx-part-3-of-n-under-construction/)<br /><br />[C++/CX parte 4 de \[n\]: Funções de membro estático](https://blogs.msdn.microsoft.com/vcblog/2012/10/19/ccx-part-4-of-n-static-member-functions/)|Uma série de Blogs introdutórios sobre C++o/CX.|
