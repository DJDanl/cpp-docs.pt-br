---
title: Referência de linguagem do C++/CX
ms.date: 09/15/2017
ms.assetid: 3f6abf92-4e5e-4ed8-8e11-f9252380d30a
ms.openlocfilehash: f28270ace3965a3cf89e250a873af14e48390708
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91507420"
---
# <a name="ccx-language-reference"></a>Referência de linguagem do C++/CX

O c++/CX é um conjunto de extensões para a linguagem C++ que permite a criação de aplicativos do Windows e Windows Runtime componentes em um idioma o mais próximo possível do C++ moderno. Use C++/CX para escrever aplicativos e componentes do Windows em código nativo que interaja facilmente com o Visual C#, Visual Basic e JavaScript e outras linguagens que dão suporte ao Windows Runtime. Nesses casos raros que exigem acesso direto às interfaces COM brutos ou ao código não-excepcional, você pode usar a [Windows Runtime WRL (biblioteca de modelos C++)](./wrl/windows-runtime-cpp-template-library-wrl.md).

> [!NOTE]
> **/WinRT é a alternativa recomendada para C++o/CX. [ C++](/windows/uwp/cpp-and-winrt-apis/index)** É uma nova projeção de linguagem C++ 17 padrão para APIs Windows Runtime, disponível no SDK do Windows 10 mais recente da versão 1803 em diante. O C++/WinRT é implementado inteiramente em arquivos de cabeçalho e projetado para fornecer a você acesso de primeira classe à API moderna do Windows.
>
> Com o C++/WinRT, você pode consumir e criar Windows Runtime APIs usando qualquer compilador C++ 17 compatível com padrões. O C++/WinRT normalmente apresenta melhor e produz binários menores do que qualquer outra opção de idioma para o Windows Runtime. Continuaremos a dar suporte a C++/CX e WRL, mas recomendamos que os novos aplicativos usem o C++/WinRT. Para obter mais informações, consulte [C++/WinRT](/windows/uwp/cpp-and-winrt-apis/index).

Usando C++/CX, você pode criar:

- Aplicativos de Plataforma Universal do Windows do C++ (UWP) que usam XAML para definir a interface do usuário e usar a pilha nativa. Para obter mais informações, consulte [criar um aplicativo "Olá mundo" em C++ (UWP)](/windows/uwp/get-started/create-a-basic-windows-10-app-in-cpp).

- C++ Windows Runtime componentes que podem ser consumidos por aplicativos Windows baseados em JavaScript. Para mais informações, consulte [Criando componentes do Windows Runtime em C++](/windows/uwp/winrt-components/creating-windows-runtime-components-in-cpp).

- Jogos do Windows DirectX e aplicativos intensivos de elementos gráficos. Para obter mais informações, consulte [criar um jogo UWP simples com o DirectX](/windows/uwp/gaming/tutorial--create-your-first-uwp-directx-game).

## <a name="related-articles"></a>Artigos relacionados

| Link | Descrição |
|--|--|
| [Referência rápida](../cppcx/quick-reference-c-cx.md) | Tabela de palavras-chave e operadores para C++/CX. |
| [Sistema de tipo](../cppcx/type-system-c-cx.md) | Descreve os tipos básicos de C++/CX e construções de programação e como utilizar C++/CX para consumir e criar Windows Runtime tipos. |
| [Como compilar aplicativos e bibliotecas](../cppcx/building-apps-and-libraries-c-cx.md) | Discute como usar o IDE para criar aplicativos e vincular a bibliotecas e DLLs estáticas. |
| [Interoperação com outras linguagens](../cppcx/interoperating-with-other-languages-c-cx.md) | Discute como os componentes que são escritos usando C++/CX podem ser usados com componentes que são escritos em JavaScript, qualquer linguagem gerenciada ou a Windows Runtime biblioteca de modelos do C++. |
| [Threading e marshaling](../cppcx/threading-and-marshaling-c-cx.md) | Discute como especificar comportamento de threading e marshaling dos componentes que você cria. |
| [Referência de namespaces](../cppcx/namespaces-reference-c-cx.md) | Consulte a documentação do namespace padrão, do namespace Platform, Platform::Collections e dos namespaces relacionados. |
| [Funções de CRT sem suporte em aplicativos da Plataforma Universal do Windows](../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md) | Relaciona as funções CRT não disponíveis para uso em aplicativos de Windows Runtime. |
| [Introdução aos aplicativos do Windows 10](/windows/uwp/get-started/) | Fornece instruções de alto nível sobre aplicativos do Windows 10 e links para mais informações. |
| [C++/CX, parte 0 de \[ n \] : uma introdução](https://devblogs.microsoft.com/cppblog/ccx-part-0-of-n-an-introduction/)<br /><br />[C++/CX, parte 1 de \[ n \] : uma classe simples](https://devblogs.microsoft.com/cppblog/ccx-part-1-of-n-a-simple-class/)<br /><br />[C++/CX parte 2 de \[ n \] : tipos que usam chapéus](https://devblogs.microsoft.com/cppblog/ccx-part-2-of-n-types-that-wear-hats/)<br /><br />[C++/CX, parte 3 de \[ n \] : em construção](https://devblogs.microsoft.com/cppblog/ccx-part-3-of-n-under-construction/)<br /><br />[C++/CX parte 4 de \[ n \] : funções membro estáticas](https://devblogs.microsoft.com/cppblog/ccx-part-4-of-n-static-member-functions/)| Uma série de Blogs introdutórios sobre C++/CX. |
