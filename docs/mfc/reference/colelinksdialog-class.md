---
title: "Classe de COleLinksDialog | Microsoft Docs"
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
  - "COleLinksDialog"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de COleLinksDialog"
  - "caixas de diálogo, O OLE"
  - "a edição vincula a caixa de diálogo"
  - "A edição OLE vincula a caixa de diálogo"
ms.assetid: fb2eb638-2809-46db-ac74-392a732affc7
caps.latest.revision: 22
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COleLinksDialog
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Usado para edição OLE vincula a caixa de diálogo.  
  
## Sintaxe  
  
```  
class COleLinksDialog : public COleDialog  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleLinksDialog::COleLinksDialog](../Topic/COleLinksDialog::COleLinksDialog.md)|Constrói um objeto de `COleLinksDialog` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleLinksDialog::DoModal](../Topic/COleLinksDialog::DoModal.md)|Exibe a caixa de diálogo OLE de links de edição.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleLinksDialog::m\_el](../Topic/COleLinksDialog::m_el.md)|Uma estrutura do tipo **OLEUIEDITLINKS** que controla o comportamento da caixa de diálogo.|  
  
## Comentários  
 Crie um objeto da classe `COleLinksDialog` quando você deseja chamar essa caixa de diálogo.  Depois que um objeto de `COleLinksDialog` foi construído, você pode usar a estrutura de [m\_el](../Topic/COleLinksDialog::m_el.md) para inicializar valores ou estados de controles na caixa de diálogo.  A estrutura de `m_el` é do tipo **OLEUIEDITLINKS**.  Para obter mais informações sobre como usar esta classe da caixa de diálogo, consulte a função de membro de [DoModal](../Topic/COleLinksDialog::DoModal.md) .  
  
> [!NOTE]
>  O código gerado assistentes do recipiente de aplicativo usa essa classe.  
  
 Para obter mais informações, consulte a estrutura de [OLEUIEDITLINKS](http://msdn.microsoft.com/library/windows/desktop/ms678492) em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Para obter mais informações sobre caixas de diálogo OLE\- específicas, consulte o artigo [Caixas de diálogo no OLE](../../mfc/dialog-boxes-in-ole.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CCommonDialog](../Topic/CCommonDialog%20Class.md)  
  
 [COleDialog](../../mfc/reference/coledialog-class.md)  
  
 `COleLinksDialog`  
  
## Requisitos  
 **Cabeçalho:** afxodlgs.h  
  
## Consulte também  
 [Classe de COleDialog](../../mfc/reference/coledialog-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de COleDialog](../../mfc/reference/coledialog-class.md)