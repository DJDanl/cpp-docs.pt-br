---
title: Criação de coleção e enumerador Interfaces (ATL)
ms.date: 11/04/2016
helpviewer_keywords:
- enumerator interfaces
- collection interfaces
ms.assetid: ea19a39e-6333-41a1-be62-5435c236640e
ms.openlocfilehash: f40c86d3bc8d9b4e4c752fe6657f6a5a14f19e0c
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57269923"
---
# <a name="design-principles-for-collection-and-enumerator-interfaces"></a>Princípios de design para Interfaces de enumerador e coleção

Há princípios de design diferentes por trás de cada tipo de interface:

- Fornece uma interface de coleção *aleatório* acesso a um *único* item na coleção por meio do `Item` método, ele permite que os clientes descobrir quantos itens estão na coleção por meio do `Count` propriedade, e geralmente permite que os clientes adicionar e remover itens.

- Fornece uma interface de enumerador *serial* acesso ao *vários* itens em uma coleção, ele não permite que o cliente a descobrir quantos itens estão na coleção (até que o enumerador interrompe retornando itens), e ele não fornece nenhuma forma de adicionar ou remover itens.

Cada tipo de interface desempenha uma função diferente no fornecimento de acesso aos elementos em uma coleção.

## <a name="see-also"></a>Consulte também

[Coleções e enumeradores](../atl/atl-collections-and-enumerators.md)
