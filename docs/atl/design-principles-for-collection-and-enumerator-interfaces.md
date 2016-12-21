---
title: "No&#231;&#245;es b&#225;sicas de cria&#231;&#227;o de interfaces de cole&#231;&#227;o e enumerator | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "interfaces de coleção"
  - "interfaces enumerator"
ms.assetid: ea19a39e-6333-41a1-be62-5435c236640e
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# No&#231;&#245;es b&#225;sicas de cria&#231;&#227;o de interfaces de cole&#231;&#227;o e enumerator
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Há noções básicas de design diferentes de apoio cada tipo de interface:  
  
-   Fornece uma interface de coleção *de acesso aleatório* *a um único* item na coleção via o método de **Item** , permite que os clientes descobrir quantos itens estão na coleção através da propriedade de **Contagem** , e permite que os clientes geralmente adicionar e remover itens.  
  
-   Uma interface de enumerador fornece *acesso serial* *para vários* itens em uma coleção, não permite que o cliente descobrir quantos itens estão na coleção \(até que o enumerador parar de retornar itens\), e não fornece nenhuma maneira para adicionar ou remover itens.  
  
 Cada tipo de interface executa uma função diferente em fornecer acesso aos elementos em uma coleção.  
  
## Consulte também  
 [Coleções e enumeradores](../atl/atl-collections-and-enumerators.md)