---
title: Coleções e enumeradores ATL
ms.date: 11/04/2016
helpviewer_keywords:
- enumerator interfaces
- collections, ATL classes
- enumerators, ATL classes
- collection interfaces
ms.assetid: b2d37119-3ab2-4e0a-b65b-f377f07e4098
ms.openlocfilehash: 502bedb1773dc2a6edbd6679d50e9c5946228283
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69491898"
---
# <a name="atl-collections-and-enumerators"></a>Coleções e enumeradores ATL

Um `collection` é um objeto com que fornece uma interface que permite o acesso a um grupo de itens de dados (dados brutos ou outros objetos). Uma interface que segue os padrões para fornecer acesso a um grupo de objetos é conhecida como uma *interface de coleção*.

No mínimo, as interfaces de coleção devem fornecer `Count` uma propriedade que retorna o número de itens na coleção, uma `Item` propriedade que retorna um item da coleção com base em um índice e uma `_NewEnum` propriedade que retorna um enumerador para a coleção. Opcionalmente, as interfaces de coleção `Add` podem `Remove` fornecer métodos e para permitir que os itens sejam inseridos ou excluídos da coleção, `Clear` e um método para remover todos os itens.

Um `enumerator` é um objeto com que fornece uma interface para iteração por meio de itens em uma coleção. As interfaces do enumerador fornecem acesso serial aos elementos de uma coleção por meio de `Next`quatro `Skip`métodos `Reset`necessários: `Clone`,, e.

Você pode aprender mais sobre as interfaces do enumerador lendo o conteúdo de referência, como a interface [IEnumString](/windows/win32/api/objidl/nn-objidl-ienumstring) .

## <a name="in-this-section"></a>Nesta seção

[Classes de coleção e enumerador da ATL](../atl/atl-collection-and-enumerator-classes.md)<br/>
Descreve brevemente e fornece links para as classes ATL que ajudarão você a implementar coleções e enumeradores.

[Princípios de design para interfaces de coleção e enumerador](../atl/design-principles-for-collection-and-enumerator-interfaces.md)<br/>
Discute os diferentes princípios de design por trás de cada tipo de interface.

[Implementando uma coleção baseada na biblioteca padrão C++](../atl/implementing-an-stl-based-collection.md)<br/>
Um exemplo estendido que orienta você pela implementação de uma C++ coleção baseada em biblioteca padrão.

## <a name="related-sections"></a>Seções relacionadas

[ATL](../atl/active-template-library-atl-concepts.md)<br/>
Fornece links para tópicos conceituais sobre como programar usando o Active Template Library.

[Exemplo de ATLCollections](../overview/visual-cpp-samples.md)<br/>
Um exemplo que demonstra o uso de `ICollectionOnSTLImpl` e `CComEnumOnSTL`e a implementação de classes de política de cópia personalizada.

## <a name="see-also"></a>Consulte também

[Conceitos](../atl/active-template-library-atl-concepts.md)
