---
title: "Classe de CDocItem | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CDocItem"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CDocItem"
  - "itens de documento de cliente"
  - "itens de documento contêiner"
  - "itens de documento"
  - "itens, documento"
  - "Documentos VELHOS, itens"
  - "documentos de servidor"
  - "documentos de servidor, itens de documento"
ms.assetid: 84fb8610-a4c8-4211-adc0-e70e8d002c11
caps.latest.revision: 22
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDocItem
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe base para itens de documento, que são componentes de dados de um documento.  
  
## Sintaxe  
  
```  
class CDocItem : public CCmdTarget  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDocItem::GetDocument](../Topic/CDocItem::GetDocument.md)|Retorna o documento que contém o item.|  
|[CDocItem::IsBlank](../Topic/CDocItem::IsBlank.md)|Determina se o item contém as informações.|  
  
## Comentários  
 Os objetos de`CDocItem` são usados para representar itens VELHOS em documentos do cliente e servidor.  
  
 Para obter mais informações, consulte o artigo [Recipientes: implementando um contêiner](../../mfc/containers-implementing-a-container.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 `CDocItem`  
  
## Requisitos  
 **Cabeçalho:** afxole.h  
  
## Consulte também  
 [Classe de CCmdTarget](../Topic/CCmdTarget%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de COleDocument](../../mfc/reference/coledocument-class.md)   
 [Classe de COleServerItem](../../mfc/reference/coleserveritem-class.md)   
 [Classe de COleClientItem](../../mfc/reference/coleclientitem-class.md)