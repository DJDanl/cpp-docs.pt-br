---
title: Características da janela da ATL
ms.date: 11/04/2016
helpviewer_keywords:
- window traits
ms.assetid: c90cf850-9e91-49da-9cf3-ad4efb30347d
ms.openlocfilehash: 0ab1a3c8f20a8e81304cdae68731bc70fbfc05c7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50647038"
---
# <a name="understanding-window-traits"></a>Noções básicas sobre características da janela

Classes de características da janela fornecem um método simples para padronizar os estilos usados para a criação de um objeto de janela ATL. Características da janela são aceitos como parâmetros de modelo pelo [CWindowImpl](../atl/reference/cwindowimpl-class.md) e outras classes de janela ATL como uma maneira de fornecer padrão estilos de janela no nível de classe.

Se o criador de uma instância de janela não fornecer estilos explicitamente na chamada para [criar](../atl/reference/cwindowimpl-class.md#create), você pode usar uma classe de características para garantir que a janela ainda é criada com os estilos corretos. Você pode garantir que determinados estilos são definidos para todas as instâncias dessa classe de janela ao permitir que outros estilos a ser definido em uma base por instância.

## <a name="atl-window-traits-templates"></a>Modelos de características de janela da ATL

ATL fornece dois modelos de características de janela que permitem que você definir estilos padrão em tempo de compilação usando seus parâmetros de modelo.

|Classe|Descrição|
|-----------|-----------------|
|[CWinTraits](../atl/reference/cwintraits-class.md)|Use este modelo quando desejar fornecer padrão estilos de janela que serão usados somente quando não há outros estilos são especificados na chamada para `Create`. Os estilos fornecidos no têm precedência de tempo de execução sobre os estilos definidos no tempo de compilação.|
|[CWinTraitsOR](../atl/reference/cwintraitsor-class.md)|Use essa classe quando você deseja especificar os estilos que sempre devem ser definidos para a classe de janela. Os estilos de fornecidos em tempo de execução são combinados com os estilos definidos em tempo de compilação usando o operador OR bit a bit.|

Além desses modelos, a ATL fornece uma série de especializações predefinidas a `CWinTraits` modelo para comumente usadas combinações de estilos de janela. Consulte a [CWinTraits](../atl/reference/cwintraits-class.md) consultar a documentação para obter detalhes completos.

## <a name="custom-window-traits"></a>Características da janela personalizado

A situação improvável que uma especialização dos modelos fornecidos pelo ATL não é suficiente e você precisa criar sua própria classe de características, basta criar uma classe que implementa duas funções estáticas: `GetWndStyle` e `GetWndStyleEx`:

[!code-cpp[NVC_ATL_Windowing#68](../atl/codesnippet/cpp/understanding-window-traits_1.h)]

Cada uma dessas funções será passada algum valor de estilo em tempo de execução que ele pode usar para gerar um novo valor de estilo. Se sua classe de características da janela está sendo usado como o argumento de modelo para uma classe de janela da ATL, os valores de estilo passados para essas funções estáticas será tudo o que foi passado como os argumentos de estilo para [criar](../atl/reference/cwindowimpl-class.md#create).

## <a name="see-also"></a>Consulte também

[Classes de janela](../atl/atl-window-classes.md)

