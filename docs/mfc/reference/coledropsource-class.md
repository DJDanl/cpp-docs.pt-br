---
title: "Classe de COleDropSource | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "COleDropSource"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de COleDropSource"
  - "arrastar e soltar, fonte subjacente"
  - "operações de arrastar"
  - "o destino alvo, arrastando a dados"
ms.assetid: d3eecc5f-a70b-4a01-b705-7d2c098ebe17
caps.latest.revision: 24
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COleDropSource
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Permite que os dados a serem arrastados para um alvo da operação.  
  
## Sintaxe  
  
```  
class COleDropSource : public CCmdTarget  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleDropSource::COleDropSource](../Topic/COleDropSource::COleDropSource.md)|Constrói um objeto de `COleDropSource` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleDropSource::GiveFeedback](../Topic/COleDropSource::GiveFeedback.md)|Altera o cursor durante uma operação de arrastar e soltar.|  
|[COleDropSource::OnBeginDrag](../Topic/COleDropSource::OnBeginDrag.md)|Captura do mouse handles durante uma operação de arrastar e soltar.|  
|[COleDropSource::QueryContinueDrag](../Topic/COleDropSource::QueryContinueDrag.md)|Verifica se arraste deve continuar.|  
  
## Comentários  
 A classe de [COleDropTarget](../Topic/COleDropTarget%20Class.md) trata a parte de recebimento da operação de arrastar e soltar.  O objeto de `COleDropSource` é responsável para determinar quando uma operação de arrastar começa, fornecer comentários durante a operação de arrastar, e determiná\-los quando a operação de arrasto termina.  
  
 Para usar um objeto de `COleDropSource` , chamar apenas o construtor.  Isso simplifica o processo de determinar quais eventos, como um clique do mouse, começando uma operação de arrastar usando a função de [COleDataSource::DoDragDrop](../Topic/COleDataSource::DoDragDrop.md), de [COleClientItem::DoDragDrop](../Topic/COleClientItem::DoDragDrop.md), ou de [COleServerItem::DoDragDrop](../Topic/COleServerItem::DoDragDrop.md) .  Essas funções criarão um objeto de `COleDropSource` para você.  Convém alterar o comportamento padrão das funções substituível de `COleDropSource` .  Essas funções de membro serão chamados no momento apropriado estrutura.  
  
 Para obter mais informações sobre as operações de arrastar\-e\-soltar usando OLE, consulte o artigo [Arrastar e soltar \(OLE\)](../../mfc/drag-and-drop-ole.md).  
  
 Para obter mais informações, consulte [IDropSource](http://msdn.microsoft.com/library/windows/desktop/ms690071) em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 `COleDropSource`  
  
## Requisitos  
 **Cabeçalho:** afxole.h  
  
## Consulte também  
 [O MFC exemplos HIERSVR](../../top/visual-cpp-samples.md)   
 [Exemplo OCLIENT MFC](../../top/visual-cpp-samples.md)   
 [Classe de CCmdTarget](../Topic/CCmdTarget%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)