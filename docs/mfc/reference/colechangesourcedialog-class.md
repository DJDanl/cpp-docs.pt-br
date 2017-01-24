---
title: "Classe de COleChangeSourceDialog | Microsoft Docs"
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
  - "COleChangeSourceDialog"
  - "OLEUICHANGESOURCE"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de COleChangeSourceDialog"
  - "caixas de diálogo, O OLE"
  - "Caixa de diálogo OLE de alteração de origem"
  - "Caixas de diálogo VELHOS, Fonte de alteração"
  - "Estrutura de OleUIChangeSource"
ms.assetid: d0e08be7-21ef-45e1-97af-fe27d99e3bac
caps.latest.revision: 22
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COleChangeSourceDialog
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Usado para a caixa de diálogo OLE de origem de alteração.  
  
## Sintaxe  
  
```  
class COleChangeSourceDialog : public COleDialog  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleChangeSourceDialog::COleChangeSourceDialog](../Topic/COleChangeSourceDialog::COleChangeSourceDialog.md)|Constrói um objeto de `COleChangeSourceDialog` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleChangeSourceDialog::DoModal](../Topic/COleChangeSourceDialog::DoModal.md)|Exibe a caixa de diálogo OLE de origem de alteração.|  
|[COleChangeSourceDialog::GetDisplayName](../Topic/COleChangeSourceDialog::GetDisplayName.md)|Obtém o nome para exibição completo de origem.|  
|[COleChangeSourceDialog::GetFileName](../Topic/COleChangeSourceDialog::GetFileName.md)|Obtém o nome de arquivo do nome de origem.|  
|[COleChangeSourceDialog::GetFromPrefix](../Topic/COleChangeSourceDialog::GetFromPrefix.md)|Obtém o prefixo de origem anterior.|  
|[COleChangeSourceDialog::GetItemName](../Topic/COleChangeSourceDialog::GetItemName.md)|Obtém o nome do item de nome de origem.|  
|[COleChangeSourceDialog::GetToPrefix](../Topic/COleChangeSourceDialog::GetToPrefix.md)|Obtém o prefixo de origem|  
|[COleChangeSourceDialog::IsValidSource](../Topic/COleChangeSourceDialog::IsValidSource.md)|Indica se a fonte é válido.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleChangeSourceDialog::m\_cs](../Topic/COleChangeSourceDialog::m_cs.md)|Uma estrutura que controla o comportamento da caixa de diálogo.|  
  
## Comentários  
 Crie um objeto da classe `COleChangeSourceDialog` quando você deseja chamar essa caixa de diálogo.  Depois que um objeto de `COleChangeSourceDialog` foi construído, você pode usar a estrutura de [m\_cs](../Topic/COleChangeSourceDialog::m_cs.md) para inicializar valores ou estados de controles na caixa de diálogo.  A estrutura de `m_cs` é do tipo [OLEUICHANGESOURCE](http://msdn.microsoft.com/library/windows/desktop/ms682160).  Para obter mais informações sobre como usar esta classe da caixa de diálogo, consulte a função de membro de [DoModal](../Topic/COleChangeSourceDialog::DoModal.md) .  
  
 Para obter mais informações, consulte a estrutura de [OLEUICHANGESOURCE](http://msdn.microsoft.com/library/windows/desktop/ms682160) em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Para obter mais informações sobre caixas de diálogo OLE\- específicas, consulte o artigo [Caixas de diálogo no OLE](../../mfc/dialog-boxes-in-ole.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CCommonDialog](../Topic/CCommonDialog%20Class.md)  
  
 [COleDialog](../../mfc/reference/coledialog-class.md)  
  
 `COleChangeSourceDialog`  
  
## Requisitos  
 **Cabeçalho:** afxodlgs.h  
  
## Consulte também  
 [Classe de COleDialog](../../mfc/reference/coledialog-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de COleDialog](../../mfc/reference/coledialog-class.md)