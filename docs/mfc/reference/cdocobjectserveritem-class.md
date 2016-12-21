---
title: "Classe de CDocObjectServerItem | Microsoft Docs"
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
  - "CDocObjectServerItem"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Documentos ActiveX [C++], o servidor de documento"
  - "Classe de CDocObjectServerItem"
  - "o servidor de docobject"
  - "servidor de objeto de documento"
  - "servidores [C++], Documentos ActiveX"
  - "servidores [C++], objetos de doc"
ms.assetid: 530f7156-50c8-4806-9328-602c9133f622
caps.latest.revision: 22
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDocObjectServerItem
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Verbos VELHOS de servidor implementa especificamente para servidores de DocObject.  
  
## Sintaxe  
  
```  
class CDocObjectServerItem : public COleServerItem  
```  
  
## Membros  
  
### Construtores protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDocObjectServerItem::CDocObjectServerItem](../Topic/CDocObjectServerItem::CDocObjectServerItem.md)|Constrói um objeto de `CDocObjectServerItem` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDocObjectServerItem::GetDocument](../Topic/CDocObjectServerItem::GetDocument.md)|Recupera um ponteiro para o documento que contém o item.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDocObjectServerItem::OnHide](../Topic/CDocObjectServerItem::OnHide.md)|Gera uma exceção se a estrutura tenta ocultar um item de DocObject.|  
|[CDocObjectServerItem::OnShow](../Topic/CDocObjectServerItem::OnShow.md)|Chamado pela estrutura para fazer ao item de DocObject ativo no lugar.  Se o item não for um DocObject, chama [COleServerItem::OnShow](../Topic/COleServerItem::OnShow.md).|  
  
## Comentários  
 `CDocObjectServerItem` define funções de membro substituível: [OnHide](../Topic/CDocObjectServerItem::OnHide.md), [OnOpen](http://msdn.microsoft.com/pt-br/7a9b1363-6ad8-4732-9959-4e35c07644fd), e [OnShow](../Topic/CDocObjectServerItem::OnShow.md).  
  
 Para usar `CDocObjectServerItem`, certifique\-se que a substituição de [OnGetEmbeddedItem](../Topic/COleServerDoc::OnGetEmbeddedItem.md) em seu `COleServerDoc`\- a classe derivada retorna um novo objeto de `CDocObjectServerItem` .  Se você precisar alterar algumas funcionalidades no item, você pode criar uma nova instância do seu próprio `CDocObjectServerItem`\- classe derivada.  
  
 Para obter mais informações sobre DocObjects, consulte [CDocObjectServer](../../mfc/reference/cdocobjectserver-class.md) e [COleCmdUI](../../mfc/reference/colecmdui-class.md)*na referência MFC*.  Consulte também [Primeiras etapas da Internet: documentos ativos](../Topic/Active%20Documents%20on%20the%20Internet.md) e [documentos ativos](../Topic/Active%20Documents%20on%20the%20Internet.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CDocItem](../../mfc/reference/cdocitem-class.md)  
  
 [COleServerItem](../../mfc/reference/coleserveritem-class.md)  
  
 `CDocObjectServerItem`  
  
## Requisitos  
 **Cabeçalho:** afxdocob.h  
  
## Consulte também  
 [Classe de COleServerItem](../../mfc/reference/coleserveritem-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CDocObjectServer](../../mfc/reference/cdocobjectserver-class.md)   
 [Classe de COleDocObjectItem](../Topic/COleDocObjectItem%20Class.md)