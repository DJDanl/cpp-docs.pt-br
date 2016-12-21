---
title: "Classe de COleChangeIconDialog | Microsoft Docs"
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
  - "COleChangeIconDialog"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Caixa de diálogo de ícone de alteração"
  - "Classe de COleChangeIconDialog"
  - "caixas de diálogo, O OLE"
  - "Caixa de diálogo OLE de ícone de alteração"
  - "Caixas de diálogo VELHOS, Ícone de alteração"
ms.assetid: 8d6e131b-ddbb-4dff-a432-f239efda8e3d
caps.latest.revision: 22
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COleChangeIconDialog
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Usado para a caixa de diálogo OLE de ícone de alteração.  
  
## Sintaxe  
  
```  
class COleChangeIconDialog : public COleDialog  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleChangeIconDialog::COleChangeIconDialog](../Topic/COleChangeIconDialog::COleChangeIconDialog.md)|Constrói um objeto de `COleChangeIconDialog` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleChangeIconDialog::DoChangeIcon](../Topic/COleChangeIconDialog::DoChangeIcon.md)|Executa a alteração especificada na caixa de diálogo.|  
|[COleChangeIconDialog::DoModal](../Topic/COleChangeIconDialog::DoModal.md)|Exibe a caixa de diálogo de ícone de alteração do OLE 2.|  
|[COleChangeIconDialog::GetIconicMetafile](../Topic/COleChangeIconDialog::GetIconicMetafile.md)|Obtém um manipulador para o metarquivo associado ao formulário icónico de este item.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleChangeIconDialog::m\_ci](../Topic/COleChangeIconDialog::m_ci.md)|Uma estrutura que controla o comportamento da caixa de diálogo.|  
  
## Comentários  
 Crie um objeto da classe `COleChangeIconDialog` quando você deseja chamar essa caixa de diálogo.  Depois que um objeto de `COleChangeIconDialog` foi construído, você pode usar a estrutura de [m\_ci](../Topic/COleChangeIconDialog::m_ci.md) para inicializar valores ou estados de controles na caixa de diálogo.  A estrutura de `m_ci` é do tipo **OLEUICHANGEICON**.  Para obter mais informações sobre como usar esta classe da caixa de diálogo, consulte a função de membro de [DoModal](../Topic/COleChangeIconDialog::DoModal.md) .  
  
 Para obter mais informações, consulte a estrutura de [OLEUICHANGEICON](http://msdn.microsoft.com/library/windows/desktop/ms680098) em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Para obter mais informações sobre caixas de diálogo OLE\- específicas, consulte o artigo [Caixas de diálogo no OLE](../../mfc/dialog-boxes-in-ole.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CCommonDialog](../Topic/CCommonDialog%20Class.md)  
  
 [COleDialog](../../mfc/reference/coledialog-class.md)  
  
 `COleChangeIconDialog`  
  
## Requisitos  
 **Cabeçalho:** afxodlgs.h  
  
## Consulte também  
 [Classe de COleDialog](../../mfc/reference/coledialog-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de COleDialog](../../mfc/reference/coledialog-class.md)