---
title: Classes base | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- inheritance, multiple
- base classes [C++], virtual
- derived classes [C++], multiple bases
- multiple inheritance, base classes
- virtual base classes [C++]
- base classes [C++]
ms.assetid: 6e6d54d0-6f21-4a16-9103-22935d98f596
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e0a83507d89c17aab363f986dab3ff4d84c4c916
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="base-classes"></a>Classes base
O processo de herança cria uma nova classe derivada que é composta dos membros da classe base (ou das classes base), mais os novos membros adicionados pela classe derivada. Em uma herança múltipla, é possível construir um gráfico de herança em que a mesma classe base faz parte de mais de uma das classes derivadas. A figura a seguir mostra um gráfico desse tipo.  
  
 ![Várias instâncias de uma classe base](../cpp/media/vc38xn1.gif "vc38XN1")  
Várias instâncias de uma mesma classe base  
  
 Na figura, são mostradas representações pictóricas dos componentes de `CollectibleString` e `CollectibleSortable`. No entanto, a classe base, `Collectible`, está em `CollectibleSortableString` pelo caminho de `CollectibleString` e pelo caminho de `CollectibleSortable`. Para eliminar essa redundância, essas classes podem ser declaradas como classes base virtuais quando são herdadas.  
  
