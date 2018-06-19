---
title: Criação de coleção e Interfaces de enumerador (ATL) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- enumerator interfaces
- collection interfaces
ms.assetid: ea19a39e-6333-41a1-be62-5435c236640e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 05649cce0e80af6f54327545cef7b663d69babf9
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32354913"
---
# <a name="design-principles-for-collection-and-enumerator-interfaces"></a>Noções básicas de criação de Interfaces de enumerador e coleção
Há diferentes princípios por trás de cada tipo de interface:  
  
-   Fornece uma interface de coleção *aleatório* acesso a um *único* item na coleção por meio de **Item** método, ele permite que os clientes descobrir quantos itens estão no conjunto de por meio de **contagem** propriedade, e geralmente permite que os clientes adicionar e remover itens.  
  
-   Fornece uma interface de enumerador *serial* acesso *vários* itens em uma coleção, ele não permite que o cliente descobrir quantos itens estão na coleção (até que o enumerador parar de retornar itens), e ele não fornece nenhuma forma de adicionar ou remover itens.  
  
 Cada tipo de interface desempenha um papel diferente no fornecimento de acesso para os elementos em uma coleção.  
  
## <a name="see-also"></a>Consulte também  
 [Coleções e enumeradores](../atl/atl-collections-and-enumerators.md)

