---
title: "Classe de COleDialog | Microsoft Docs"
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
  - "COleDialog"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de COleDialog"
  - "caixas de diálogo, O OLE"
  - "Caixas de diálogo VELHOS, classe base"
ms.assetid: b1ed0aca-3914-4b00-af34-4a4fb491aec7
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COleDialog
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece a funcionalidade comum das caixas de diálogo para OLE.  
  
## Sintaxe  
  
```  
class COleDialog : public CCommonDialog  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleDialog::GetLastError](../Topic/COleDialog::GetLastError.md)|Obtém o código de erro retornado pela caixa de diálogo.|  
  
## Comentários  
 A biblioteca de classe de base do Microsoft fornece várias classes derivadas de `COleDialog`:  
  
-   [COleInsertDialog](../../mfc/reference/coleinsertdialog-class.md)  
  
-   [COleConvertDialog](../../mfc/reference/coleconvertdialog-class.md)  
  
-   [COleChangeIconDialog](../../mfc/reference/colechangeicondialog-class.md)  
  
-   [COleLinksDialog](../../mfc/reference/colelinksdialog-class.md)  
  
-   [COleBusyDialog](../../mfc/reference/colebusydialog-class.md)  
  
-   [COleUpdateDialog](../Topic/COleUpdateDialog%20Class.md)  
  
-   [COlePasteSpecialDialog](../../mfc/reference/colepastespecialdialog-class.md)  
  
-   [COlePropertiesDialog](../Topic/COlePropertiesDialog%20Class.md)  
  
-   [COleChangeSourceDialog](../../mfc/reference/colechangesourcedialog-class.md)  
  
 Para obter mais informações sobre caixas de diálogo OLE\- específicas, consulte o artigo [Caixas de diálogo no OLE](../../mfc/dialog-boxes-in-ole.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CCommonDialog](../Topic/CCommonDialog%20Class.md)  
  
 `COleDialog`  
  
## Requisitos  
 **Cabeçalho:** afxodlgs.h  
  
## Consulte também  
 [Classe de CCommonDialog](../Topic/CCommonDialog%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)