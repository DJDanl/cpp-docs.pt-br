---
title: ATL coleções e enumeradores | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- enumerator interfaces
- collections, ATL classes
- enumerators, ATL classes
- collection interfaces
ms.assetid: b2d37119-3ab2-4e0a-b65b-f377f07e4098
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4da59a76ccc4d51e82fd43805daa73d513fcde17
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46044269"
---
# <a name="atl-collections-and-enumerators"></a>Coleções e enumeradores ATL

Um `collection` é um objeto COM que fornece uma interface que permite o acesso a um grupo de itens de dados (dados brutos ou outros objetos). Uma interface que segue os padrões para fornecer acesso a um grupo de objetos é conhecido como um *interface de coleção*.

No mínimo, as interfaces de coleção devem fornecer um `Count` propriedade que retorna o número de itens na coleção, um `Item` propriedade que retorna um item da coleção com base em um índice, e um `_NewEnum` propriedade que retorna um enumerador para a coleção. Opcionalmente, as interfaces de coleção podem fornecer `Add` e `Remove` métodos para permitir que os itens a ser inserida ou excluída da coleção e um `Clear` método para remover todos os itens.

Um `enumerator` é um objeto COM que fornece uma interface para iterar pelos itens em uma coleção. Interfaces de enumerador fornecem acesso serial para os elementos de uma coleção por meio de quatro métodos necessários: `Next`, `Skip`, `Reset`, e `Clone`.

Você pode aprender mais sobre interfaces de enumerador, lendo o conteúdo de referência, como [IEnumString](/windows/desktop/api/objidl/nn-objidl-ienumstring) interface.

## <a name="in-this-section"></a>Nesta seção

[Classes de coleção e enumerador da ATL](../atl/atl-collection-and-enumerator-classes.md)<br/>
Descreve rapidamente e fornece links para as classes ATL que ajudarão você a implementam coleções e enumeradores.

[Princípios de design para interfaces de coleção e enumerador](../atl/design-principles-for-collection-and-enumerator-interfaces.md)<br/>
Discute os princípios de design diferentes por trás de cada tipo de interface.

[Implementando uma coleção baseada na biblioteca padrão C++](../atl/implementing-an-stl-based-collection.md)<br/>
Um exemplo estendido que orienta você durante a implementação de uma coleção baseada na biblioteca padrão C++.

## <a name="related-sections"></a>Seções relacionadas

[ATL](../atl/active-template-library-atl-concepts.md)<br/>
Fornece links para tópicos conceituais sobre como programar usando o Active Template Library.

[Exemplo de ATLCollections](../visual-cpp-samples.md)<br/>
Um exemplo que demonstra o uso de `ICollectionOnSTLImpl` e `CComEnumOnSTL`e a implementação das classes de política de cópia personalizada.

## <a name="see-also"></a>Consulte também

[Conceitos](../atl/active-template-library-atl-concepts.md)

