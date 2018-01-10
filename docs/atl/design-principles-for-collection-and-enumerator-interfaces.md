---
title: "Criação de coleção e Interfaces de enumerador (ATL) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- enumerator interfaces
- collection interfaces
ms.assetid: ea19a39e-6333-41a1-be62-5435c236640e
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 8709274e1b95816dee01b4457993521dde5d5213
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="design-principles-for-collection-and-enumerator-interfaces"></a>Noções básicas de criação de Interfaces de enumerador e coleção
Há diferentes princípios por trás de cada tipo de interface:  
  
-   Fornece uma interface de coleção *aleatório* acesso a um *único* item na coleção por meio de **Item** método, ele permite que os clientes descobrir quantos itens estão no conjunto de por meio de **contagem** propriedade, e geralmente permite que os clientes adicionar e remover itens.  
  
-   Fornece uma interface de enumerador *serial* acesso *vários* itens em uma coleção, ele não permite que o cliente descobrir quantos itens estão na coleção (até que o enumerador parar de retornar itens), e ele não fornece nenhuma forma de adicionar ou remover itens.  
  
 Cada tipo de interface desempenha um papel diferente no fornecimento de acesso para os elementos em uma coleção.  
  
## <a name="see-also"></a>Consulte também  
 [Coleções e enumeradores](../atl/atl-collections-and-enumerators.md)

