---
title: "Auxiliares da classe de cole&#231;&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.mfc.macros.classes"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classes de coleção, funções auxiliares"
  - "Função ConstructElements"
  - "Função DestructElements"
  - "classe de coleção de funções auxiliares"
  - "Função SerializeElements"
ms.assetid: bc3a2368-9edd-4748-9e6a-13cba79517ca
caps.latest.revision: 14
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Auxiliares da classe de cole&#231;&#227;o
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Classifica a coleção `CMap`, `CList`, funções e globais templated uso de auxiliar de `CArray` para fins como comparando, copiando, e serializando elementos.  Como parte de sua implementação das classes baseadas em `CMap`, `CList`, e `CArray`, você deve substituir essas funções como necessário com as versões personalizadas para o tipo de dados armazenados na lista, o mapa, ou matriz.  Para obter informações sobre como anular funções auxiliares como `SerializeElements`, consulte o artigo [Coleções: Como fazer uma coleção fortemente tipado](../../mfc/how-to-make-a-type-safe-collection.md).  Observe que **ConstructElements** e **DestructElements** foram preteridos.  
  
 A biblioteca de classes do Microsoft fornece as seguintes funções globais para ajudar a personalizar suas classes de coleção:  
  
### Auxiliares da classe de coleção  
  
|||  
|-|-|  
|[CompareElements](../Topic/CompareElements.md)|Indica se os elementos são os mesmos.|  
|[CopyElements](../Topic/CopyElements.md)|Elementos de cópias de uma matriz para outra.|  
|[DumpElements](../Topic/DumpElements.md)|\- Fornece orientou saída de diagnóstico.|  
|[HashKey](../Topic/HashKey.md)|Calcula uma chave hash.|  
|[SerializeElements](../Topic/SerializeElements.md)|As lojas ou recuperam os elementos para ou de um arquivo morto.|  
  
## Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)   
 [Classe de CMap](../../mfc/reference/cmap-class.md)   
 [Classe de CList](../../mfc/reference/clist-class.md)   
 [Classe de CArray](../../mfc/reference/carray-class.md)