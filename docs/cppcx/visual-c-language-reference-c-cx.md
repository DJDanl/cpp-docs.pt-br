---
title: Referência de linguagem do Visual C++ (C + + CX) | Microsoft Docs
ms.custom: ''
ms.date: 09/15/2017
ms.technology: cpp-windows
ms.topic: language-reference
ms.assetid: 3f6abf92-4e5e-4ed8-8e11-f9252380d30a
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2b251a89eee456905fae1e2096a74362fc6c44ae
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33090151"
---
# <a name="visual-c-language-reference-ccx"></a>Referência da linguagem Visual C++ (C++/CX)

C + + CX é um conjunto de extensões para a linguagem C++ que permite a criação de aplicativos do Windows e os componentes de tempo de execução do Windows em um idioma mais próximo possível moderno do C++. Usar C + + CX escrever componentes e aplicativos do Windows em código nativo que interajam facilmente com Visual c#, Visual Basic e JavaScript e outras linguagens com suporte para o tempo de execução do Windows. Nos raros casos em que requerem acesso direto a interfaces COM brutas, ou um código não excepcional, você pode usar o [biblioteca de modelo em C++ Windows Runtime (WRL)](../windows/windows-runtime-cpp-template-library-wrl.md).

> [!NOTE]
> C + + WinRT é uma novo, standard C++ 17 idiomas projeção para APIs do Windows Runtime. Ele está disponível do Windows 10 SDK mais recente da versão 1803 em diante. C + + WinRT é implementada inteiramente em arquivos de cabeçalho e projetado para fornecer acesso de primeira classe para a API do Windows modernos.

> Com C + + WinRT, você pode consumir e criar APIs de tempo de execução do Windows usando qualquer compilador de 17 compatível com os padrões C + +. C + + WinRT geralmente é melhor e produz binários menores do que qualquer outra opção de idioma para o tempo de execução do Windows. Continuaremos a dar suporte a C + + CX e WRL, mas altamente recomendável que os novos aplicativos usar C + + WinRT. Para obter mais informações, consulte [C + + WinRT](https://docs.microsoft.com/windows/uwp/cpp-and-winrt-apis/index).


Usando C + + CX, você pode criar:

- Aplicativos C++ Windows UWP (plataforma Universal) que usam XAML para definir o usuário de interface e usam a pilha nativa. Para obter mais informações, consulte [criar um aplicativo "hello world" em C++ (UWP)](/windows/uwp/get-started/create-a-basic-windows-10-app-in-cpp).

- Componentes de tempo de execução C++ Windows que podem ser consumidos por aplicativos do Windows baseados em JavaScript. Para obter mais informações, consulte [Criando componentes do tempo de execução do Windows em C++](/windows/uwp/winrt-components/creating-windows-runtime-components-in-cpp).

- Jogos do Windows DirectX e aplicativos intensivos de elementos gráficos. Para obter mais informações, consulte [criar um jogo de UWP simples com DirectX](/windows/uwp/gaming/tutorial--create-your-first-metro-style-directx-game).

## <a name="related-articles"></a>Artigos relacionados

|||
|-|-|
|[Referência rápida](../cppcx/quick-reference-c-cx.md)|Tabela das palavras-chave e operadores para C + + CX.|
|[Sistema de tipos](../cppcx/type-system-c-cx.md)|Descreve básica C + + CX tipos e construções de programação e como utilizar C + + CX consumir e criar tipos de tempo de execução do Windows.|
|[Compilando aplicativos e bibliotecas](../cppcx/building-apps-and-libraries-c-cx.md)|Discute como usar o IDE para criar aplicativos e associar a bibliotecas estáticas e DLLs.|
|[Interoperando com outras linguagens](../cppcx/interoperating-with-other-languages-c-cx.md)|Discute como componentes que são escritos usando C + + CX pode ser usado com componentes escritos no JavaScript, qualquer linguagem gerenciada ou [!INCLUDE[cppwrl](../cppcx/includes/cppwrl-md.md)].|
|[Threading e Marshaling](../cppcx/threading-and-marshaling-c-cx.md)|Discute como especificar comportamento de threading e marshaling dos componentes que você cria.|
|[Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)|Consulte a documentação do namespace padrão, do namespace Platform, Platform::Collections e dos namespaces relacionados.|
|[As funções de CRT não têm suporte em aplicativos da Plataforma Universal do Windows](../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md)|Relaciona as funções CRT não disponíveis para uso em aplicativos de Tempo de Execução do Windows.|
|[Manuais de instruções dos aplicativos do Windows 10](http://msdn.microsoft.com/library/windows/apps/xaml/mt244352.aspx)|Fornece instruções de alto nível sobre aplicativos do Windows 10 e links para mais informações.|
|[C + c++ /CX parte 0 de \[n\]: uma introdução](https://blogs.msdn.microsoft.com/vcblog/2012/08/29/ccx-part-0-of-n-an-introduction/)<br /><br />[C + + CX parte 1 de \[n\]: uma classe simples](https://blogs.msdn.microsoft.com/vcblog/2012/09/05/ccx-part-1-of-n-a-simple-class/)<br /><br />[C + c++ /CX parte 2 de \[n\]: tipos que desempenham funções diferentes](https://blogs.msdn.microsoft.com/vcblog/2012/09/17/ccx-part-2-of-n-types-that-wear-hats/)<br /><br />[C + c++ /CX parte 3 de \[n\]: em construção](https://blogs.msdn.microsoft.com/vcblog/2012/10/05/ccx-part-3-of-n-under-construction/)<br /><br />[C + c++ /CX parte 4 de \[n\]: funções membro Static](https://blogs.msdn.microsoft.com/vcblog/2012/10/19/ccx-part-4-of-n-static-member-functions/)|Uma série de blog do Visual C++ introdutória no C + + CX.|
