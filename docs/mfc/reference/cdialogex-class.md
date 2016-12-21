---
title: "Classe de CDialogEx | Microsoft Docs"
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
  - "CDialogEx"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CDialogEx"
  - "Método de CDialogEx::PreTranslateMessage"
ms.assetid: a6ed3b1f-aef8-4b66-ac78-2160faf63c13
caps.latest.revision: 27
caps.handback.revision: 16
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDialogEx
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O `CDialogEx` classe especifica a cor do plano de fundo e a imagem de plano de fundo da caixa de diálogo.  
  
## Sintaxe  
  
```  
class CDialogEx : public CDialog  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDialogEx::CDialogEx](../Topic/CDialogEx::CDialogEx.md)|Constrói um objeto `CDialogEx`.|  
|`CDialogEx::~CDialogEx`|Destruidor.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDialogEx::SetBackgroundColor](../Topic/CDialogEx::SetBackgroundColor.md)|Define a cor de plano de fundo da caixa de diálogo.|  
|[CDialogEx::SetBackgroundImage](../Topic/CDialogEx::SetBackgroundImage.md)|Define a imagem de plano de fundo da caixa de diálogo.|  
  
## Comentários  
 Para usar o `CDialogEx` da classe, derivar a classe de caixa de diálogo da `CDialogEx` classe em vez da `CDialog` classe.  
  
 Imagens da caixa de diálogo são armazenadas em um arquivo de recurso.  O framework automaticamente exclui qualquer imagem que é carregada do arquivo de recurso.  Para excluir a imagem de plano de fundo atual programaticamente, chame o [CDialogEx::SetBackgroundImage](../Topic/CDialogEx::SetBackgroundImage.md) método ou implementar uma `OnDestroy` manipulador de eventos.  Quando você chama o [CDialogEx::SetBackgroundImage](../Topic/CDialogEx::SetBackgroundImage.md) método, passe um `HBITMAP` parâmetro como a alça da imagem.  O `CDialogEx` objeto apropriar\-se da imagem e o exclua se o `m_bAutoDestroyBmp` sinalizador é `TRUE`.  
  
 Um `CDialogEx` objeto pode ser um pai de um [Classe de CMFCPopupMenu](../Topic/CMFCPopupMenu%20Class.md) objeto.  O [Classe de CMFCPopupMenu](../Topic/CMFCPopupMenu%20Class.md) chamadas do objeto de `CDialogEx::SetActiveMenu` método quando o [Classe de CMFCPopupMenu](../Topic/CMFCPopupMenu%20Class.md) objeto é aberta.  Depois disso, o `CDialogEx` objeto manipula qualquer evento de menu até o [Classe de CMFCPopupMenu](../Topic/CMFCPopupMenu%20Class.md) objeto está fechado.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CDialogEx](../../mfc/reference/cdialogex-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxdialogex.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCPopupMenu](../Topic/CMFCPopupMenu%20Class.md)   
 [Classe de CContextMenuManager](../../mfc/reference/ccontextmenumanager-class.md)