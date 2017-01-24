---
title: "Classes base | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classes base"
  - "classes base, virtual"
  - "classes derivadas, várias bases"
  - "herança, vários"
  - "várias heranças, classes base"
  - "classes de base virtuais"
ms.assetid: 6e6d54d0-6f21-4a16-9103-22935d98f596
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes base
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O processo de herança cria uma nova classe derivada que é composta dos membros da classe base \(ou das classes base\), mais os novos membros adicionados pela classe derivada.  Em uma herança múltipla, é possível construir um gráfico de herança em que a mesma classe base faz parte de mais de uma das classes derivadas.  A figura a seguir mostra um gráfico desse tipo.  
  
 ![Uma única classe Base várias instâncias](../cpp/media/vc38xn1.png "vc38XN1")  
Várias instâncias de uma mesma classe base  
  
 Na figura, são mostradas representações pictóricas dos componentes de `CollectibleString` e `CollectibleSortable`.  No entanto, a classe base, `Collectible`, está em `CollectibleSortableString` pelo caminho de `CollectibleString` e pelo caminho de `CollectibleSortable`.  Para eliminar essa redundância, essas classes podem ser declaradas como classes base virtuais quando são herdadas.  
  
 Para obter informações sobre como declarar classes base virtuais e como os objetos com classes base virtuais são compostos, consulte [Classes base virtuais](../Topic/Virtual%20Base%20Classes.md).  
  
## Consulte também  
 [Visão geral de classes derivadas](../misc/overview-of-derived-classes.md)