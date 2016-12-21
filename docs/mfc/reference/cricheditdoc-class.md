---
title: "Classe de CRichEditDoc | Microsoft Docs"
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
  - "CRichEditDoc"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CRichEditDoc"
  - "arquitetura do documento/exibição, controles de edição ricos"
  - "documentos, edição rico"
  - "Contêiner VELHOS, edição rico"
  - "controles de edição ricos, Contêiner OLE"
ms.assetid: c936ec18-d516-49d4-b7fb-c9aa0229eddc
caps.latest.revision: 24
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CRichEditDoc
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Com [CRichEditView](../../mfc/reference/cricheditview-class.md) e [CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md), fornece a funcionalidade do controle de edição rico dentro do contexto da arquitetura de exibição de documento MFC.  
  
## Sintaxe  
  
```  
  
class CRichEditDoc : public COleServerDoc  
  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CRichEditDoc::CreateClientItem](../Topic/CRichEditDoc::CreateClientItem.md)|Chamado para executar limpeza do documento.|  
|[CRichEditDoc::GetStreamFormat](../Topic/CRichEditDoc::GetStreamFormat.md)|Indica se a entrada e saída de fluxo devem incluir informações de formatação.|  
|[CRichEditDoc::GetView](../Topic/CRichEditDoc::GetView.md)|Retorna o objeto asssociated de [CRichEditView](../../mfc/reference/cricheditview-class.md) .|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CRichEditDoc::m\_bRTF](../Topic/CRichEditDoc::m_bRTF.md)|Indica se o fluxo E\/S deve incluir formatação.|  
  
## Comentários  
 “Um controle de edição rico” é uma janela com que o usuário pode inserir e editar texto.  Texto pode ser atribuído a formatação de caracteres e de parágrafo, e pode incluir VELHOS objetos inseridos.  Controles de edição ricos fornecem uma interface de programação para formatar o texto.  Em o entanto, um aplicativo deve implementar todos os componentes necessários da interface do usuário efetuar operações de formatação disponíveis para o usuário.  
  
 `CRichEditView` mantém a característica de texto e de formatação de texto.  `CRichEditDoc` mantém a lista de itens de cliente que estão no modo.  `CRichEditCntrItem` fornece acesso aos itens de contêiner\- lado VELHOS de cliente.  
  
 Este controle comum do windows \(e portanto [CRichEditCtrl](../Topic/CRichEditCtrl%20Class.md) e classes relacionadas\) estão disponíveis somente para programas que executam sob as versões 3,51 \/98 Windows 95 e Windows NT e posterior.  
  
 Para um exemplo de como usar um documento rico em um aplicativo MFC, consulte o aplicativo de exemplo [WORDPAD](../../top/visual-cpp-samples.md) .  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CDocument](../Topic/CDocument%20Class.md)  
  
 [COleDocument](../../mfc/reference/coledocument-class.md)  
  
 [COleLinkingDoc](../../mfc/reference/colelinkingdoc-class.md)  
  
 [COleServerDoc](../Topic/COleServerDoc%20Class.md)  
  
 `CRichEditDoc`  
  
## Requisitos  
 **Cabeçalho:** afxrich.h  
  
## Consulte também  
 [Exemplo WORDPAD MFC](../../top/visual-cpp-samples.md)   
 [Classe de COleServerDoc](../Topic/COleServerDoc%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CRichEditView](../../mfc/reference/cricheditview-class.md)   
 [Classe de CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md)   
 [Classe de COleDocument](../../mfc/reference/coledocument-class.md)   
 [Classe de CRichEditCtrl](../Topic/CRichEditCtrl%20Class.md)