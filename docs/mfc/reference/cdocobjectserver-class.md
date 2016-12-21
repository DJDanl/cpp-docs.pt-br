---
title: "Classe de CDocObjectServer | Microsoft Docs"
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
  - "CDocObjectServer"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Documentos ActiveX [C++], o servidor de documento"
  - "Classe de CDocObjectServer"
  - "o servidor de docobject"
  - "servidor de objeto de documento"
  - "servidores [C++], Documentos ActiveX"
  - "servidores [C++], objetos de doc"
ms.assetid: 18cd0dff-0616-4472-b8d9-66c081bc383a
caps.latest.revision: 23
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDocObjectServer
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa as interfaces VELHOS adicionais necessárias para fazer um servidor normal de `COleDocument` em um servidor completo de DocObject: `IOleDocument`, `IOleDocumentView`, `IOleCommandTarget`, e `IPrint`.  
  
## Sintaxe  
  
```  
class CDocObjectServer : public CCmdTarget  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDocObjectServer::CDocObjectServer](../Topic/CDocObjectServer::CDocObjectServer.md)|Constrói um objeto de `CDocObjectServer` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDocObjectServer::ActivateDocObject](../Topic/CDocObjectServer::ActivateDocObject.md)|Alterna o servidor de objeto de documento, mas não mostra o.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDocObjectServer::OnActivateView](../Topic/CDocObjectServer::OnActivateView.md)|Exibe o modo de DocObject.|  
|[CDocObjectServer::OnApplyViewState](../Topic/CDocObjectServer::OnApplyViewState.md)|Restaura o estado de exibição de DocObject.|  
|[CDocObjectServer::OnSaveViewState](../Topic/CDocObjectServer::OnSaveViewState.md)|Salvar o estado de exibição de DocObject.|  
  
## Comentários  
 `CDocObjectServer` é derivado de e `CCmdTarget` de trabalho próxima a `COleServerDoc` para expor as interfaces.  
  
 Um documento de servidor de DocObject pode conter objetos de [CDocObjectServerItem](../../mfc/reference/cdocobjectserveritem-class.md) , que representa a interface do servidor para itens de DocObject.  
  
 Para personalizar seu servidor de DocObject, para derivar sua própria classe de `CDocObjectServer` e para substituir a configuração de exibição funciona, [OnActivateView](../Topic/CDocObjectServer::OnActivateView.md), [OnApplyViewState](../Topic/CDocObjectServer::OnApplyViewState.md), e [OnSaveViewState](../Topic/CDocObjectServer::OnSaveViewState.md).  Você precisará fornecer uma nova instância da classe em resposta a chamadas de estrutura.  
  
 Para obter mais informações sobre DocObjects, consulte [CDocObjectServerItem](../../mfc/reference/cdocobjectserveritem-class.md) e [COleCmdUI](../../mfc/reference/colecmdui-class.md)*na referência MFC*.  Consulte também [Primeiras etapas da Internet: documentos ativos](../Topic/Active%20Documents%20on%20the%20Internet.md) e [documentos ativos](../Topic/Active%20Documents%20on%20the%20Internet.md).  
  
 Consulte também o seguinte artigo de Base de Dados de Conhecimento:  
  
-   Q247382: PRB: Dicas para controles no servidor de documento ActiveX está oculto pelo recipiente de documento ActiveX  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 `CDocObjectServer`  
  
## Requisitos  
 **Cabeçalho:** afxdocob.h  
  
## Consulte também  
 [Classe de CCmdTarget](../Topic/CCmdTarget%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CDocObjectServerItem](../../mfc/reference/cdocobjectserveritem-class.md)