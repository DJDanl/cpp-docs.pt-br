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
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 6b08321ffb027901683a4f85960579625ce98cc2
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="base-classes"></a>Classes base
O processo de herança cria uma nova classe derivada que é composta dos membros da classe base (ou das classes base), mais os novos membros adicionados pela classe derivada. Em uma herança múltipla, é possível construir um gráfico de herança em que a mesma classe base faz parte de mais de uma das classes derivadas. A figura a seguir mostra um gráfico desse tipo.  
  
 ![Várias instâncias de uma classe base](../cpp/media/vc38xn1.gif "vc38XN1")  
Várias instâncias de uma mesma classe base  
  
 Na figura, são mostradas representações pictóricas dos componentes de `CollectibleString` e `CollectibleSortable`. No entanto, a classe base, `Collectible`, está em `CollectibleSortableString` pelo caminho de `CollectibleString` e pelo caminho de `CollectibleSortable`. Para eliminar essa redundância, essas classes podem ser declaradas como classes base virtuais quando são herdadas.  
  

