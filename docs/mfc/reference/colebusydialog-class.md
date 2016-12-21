---
title: "Classe de COleBusyDialog | Microsoft Docs"
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
  - "COleBusyDialog"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de COleBusyDialog"
  - "Caixa de diálogo ocupado de servidor"
  - "Caixa de diálogo de resposta do servidor"
ms.assetid: c881a532-9672-4c41-b51b-5ce4a7246a6b
caps.latest.revision: 22
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COleBusyDialog
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Usado para o servidor OLE caixas de diálogo ocupados de resposta ou do servidor.  
  
## Sintaxe  
  
```  
class COleBusyDialog : public COleDialog  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleBusyDialog::COleBusyDialog](../Topic/COleBusyDialog::COleBusyDialog.md)|Constrói um objeto de `COleBusyDialog` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleBusyDialog::DoModal](../Topic/COleBusyDialog::DoModal.md)|Exibe a caixa de diálogo ocupado do OLE.|  
|[COleBusyDialog::GetSelectionType](../Topic/COleBusyDialog::GetSelectionType.md)|Determina a escolha feita na caixa de diálogo.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleBusyDialog::m\_bz](../Topic/COleBusyDialog::m_bz.md)|Estrutura do tipo **OLEUIBUSY** que controla o comportamento da caixa de diálogo.|  
  
## Comentários  
 Crie um objeto da classe `COleBusyDialog` quando você deseja chamar essas caixas de diálogo.  Depois que um objeto de `COleBusyDialog` foi construído, você pode usar a estrutura de [m\_bz](../Topic/COleBusyDialog::m_bz.md) para inicializar valores ou estados de controles na caixa de diálogo.  A estrutura de `m_bz` é do tipo **OLEUIBUSY**.  Para obter mais informações sobre como usar esta classe da caixa de diálogo, consulte a função de membro de [DoModal](../Topic/COleBusyDialog::DoModal.md) .  
  
> [!NOTE]
>  O código gerado assistentes do recipiente de aplicativo usa essa classe.  
  
 Para obter mais informações, consulte a estrutura de [OLEUIBUSY](http://msdn.microsoft.com/library/windows/desktop/ms682493) em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Para obter mais informações sobre caixas de diálogo OLE\- específicas, consulte o artigo [Caixas de diálogo no OLE](../../mfc/dialog-boxes-in-ole.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CCommonDialog](../Topic/CCommonDialog%20Class.md)  
  
 [COleDialog](../../mfc/reference/coledialog-class.md)  
  
 `COleBusyDialog`  
  
## Requisitos  
 **Cabeçalho:** afxodlgs.h  
  
## Consulte também  
 [Classe de COleDialog](../../mfc/reference/coledialog-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de COleDialog](../../mfc/reference/coledialog-class.md)