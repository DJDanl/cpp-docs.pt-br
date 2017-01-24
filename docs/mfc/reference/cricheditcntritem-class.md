---
title: "Classe de CRichEditCntrItem | Microsoft Docs"
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
  - "CRichEditCntrItem"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CRichEditCntrItem"
  - "Itens VELHOS, em modos de edição rico"
  - "controles de edição ricos, Itens VELHOS"
  - "controles de edição ricos, Usando"
ms.assetid: 6c0b4efe-0fb8-4621-b5e1-fdcb8ec48c3b
caps.latest.revision: 24
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CRichEditCntrItem
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Com [CRichEditView](../../mfc/reference/cricheditview-class.md) e [CRichEditDoc](../../mfc/reference/cricheditdoc-class.md), fornece a funcionalidade do controle de edição rico dentro do contexto da arquitetura de exibição de documento MFC.  
  
## Sintaxe  
  
```  
class CRichEditCntrItem : public COleClientItem  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CRichEditCntrItem::CRichEditCntrItem](../Topic/CRichEditCntrItem::CRichEditCntrItem.md)|Constrói um objeto de `CRichEditCntrItem` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CRichEditCntrItem::SyncToRichEditObject](../Topic/CRichEditCntrItem::SyncToRichEditObject.md)|Alterna o item como outro tipo.|  
  
## Comentários  
 “Um controle de edição rico” é uma janela com que o usuário pode inserir e editar texto.  Texto pode ser atribuído a formatação de caracteres e de parágrafo, e pode incluir VELHOS objetos inseridos.  Controles de edição ricos fornecem uma interface de programação para formatar o texto.  Em o entanto, um aplicativo deve implementar todos os componentes necessários da interface do usuário efetuar operações de formatação disponíveis para o usuário.  
  
 `CRichEditView` mantém a característica de texto e de formatação de texto.  `CRichEditDoc` mantém a lista de itens VELHOS de cliente que estão no modo.  `CRichEditCntrItem` fornece acesso de contêiner\- OLE item ao lado do cliente.  
  
 Este controle comum do windows \(e portanto [CRichEditCtrl](../Topic/CRichEditCtrl%20Class.md) e classes relacionadas\) estão disponíveis somente para programas que executam sob as versões 3,51 \/98 Windows 95 e Windows NT e posterior.  
  
 Para um exemplo de como usar ricos editar itens no recipiente um aplicativo MFC, consulte o aplicativo de exemplo [WORDPAD](../../top/visual-cpp-samples.md) .  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CDocItem](../../mfc/reference/cdocitem-class.md)  
  
 [COleClientItem](../../mfc/reference/coleclientitem-class.md)  
  
 `CRichEditCntrItem`  
  
## Requisitos  
 **Cabeçalho:** afxrich.h  
  
## Consulte também  
 [Exemplo WORDPAD MFC](../../top/visual-cpp-samples.md)   
 [Classe de COleClientItem](../../mfc/reference/coleclientitem-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CRichEditDoc](../../mfc/reference/cricheditdoc-class.md)   
 [Classe de CRichEditView](../../mfc/reference/cricheditview-class.md)