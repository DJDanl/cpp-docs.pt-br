---
title: "Classe de COleInsertDialog | Microsoft Docs"
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
  - "COleInsertDialog"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de COleInsertDialog"
  - "caixas de diálogo, O OLE"
  - "Caixa de diálogo de objeto de inserção"
  - "Caixa de diálogo OLE do objeto de inserção"
ms.assetid: a9ec610b-abde-431e-bd01-c40159a66dbb
caps.latest.revision: 24
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COleInsertDialog
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Usado para a caixa de diálogo OLE do objeto de inserção.  
  
## Sintaxe  
  
```  
class COleInsertDialog : public COleDialog  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleInsertDialog::COleInsertDialog](../Topic/COleInsertDialog::COleInsertDialog.md)|Constrói um objeto de `COleInsertDialog` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleInsertDialog::CreateItem](../Topic/COleInsertDialog::CreateItem.md)|Cria o item selecionado na caixa de diálogo.|  
|[COleInsertDialog::DoModal](../Topic/COleInsertDialog::DoModal.md)|Exibe a caixa de diálogo OLE do objeto de inserção.|  
|[COleInsertDialog::GetClassID](../Topic/COleInsertDialog::GetClassID.md)|Obtém **CLSID** associado com o item escolhido.|  
|[COleInsertDialog::GetDrawAspect](../Topic/COleInsertDialog::GetDrawAspect.md)|Informa se o item como desenhar um ícone.|  
|[COleInsertDialog::GetIconicMetafile](../Topic/COleInsertDialog::GetIconicMetafile.md)|Obtém um manipulador para o metarquivo associado ao formulário icónico de este item.|  
|[COleInsertDialog::GetPathName](../Topic/COleInsertDialog::GetPathName.md)|Obtém o caminho completo do arquivo escolhido na caixa de diálogo.|  
|[COleInsertDialog::GetSelectionType](../Topic/COleInsertDialog::GetSelectionType.md)|Obtém o tipo de objeto selecionado.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleInsertDialog::m\_io](../Topic/COleInsertDialog::m_io.md)|Uma estrutura do tipo **OLEUIINSERTOBJECT** que controla o comportamento da caixa de diálogo.|  
  
## Comentários  
 Crie um objeto da classe `COleInsertDialog` quando você deseja chamar essa caixa de diálogo.  Depois que um objeto de `COleInsertDialog` foi construído, você pode usar a estrutura de [m\_io](../Topic/COleInsertDialog::m_io.md) para inicializar valores ou estados de controles na caixa de diálogo.  A estrutura de `m_io` é do tipo **OLEUIINSERTOBJECT**.  Para obter mais informações sobre como usar esta classe da caixa de diálogo, consulte a função de membro de [DoModal](../Topic/COleInsertDialog::DoModal.md) .  
  
> [!NOTE]
>  O código gerado assistentes do recipiente de aplicativo usa essa classe.  
  
 Para obter mais informações, consulte a estrutura de [OLEUIINSERTOBJECT](http://msdn.microsoft.com/library/windows/desktop/ms691316) em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Para obter mais informações sobre caixas de diálogo OLE\- específicas, consulte o artigo [Caixas de diálogo no OLE](../../mfc/dialog-boxes-in-ole.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CCommonDialog](../Topic/CCommonDialog%20Class.md)  
  
 [COleDialog](../../mfc/reference/coledialog-class.md)  
  
 `COleInsertDialog`  
  
## Requisitos  
 **Cabeçalho:** afxodlgs.h  
  
## Consulte também  
 [Exemplo OCLIENT MFC](../../top/visual-cpp-samples.md)   
 [Classe de COleDialog](../../mfc/reference/coledialog-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de COleDialog](../../mfc/reference/coledialog-class.md)