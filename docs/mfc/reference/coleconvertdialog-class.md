---
title: "Classe de COleConvertDialog | Microsoft Docs"
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
  - "COleConvertDialog"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de COleConvertDialog"
  - "Caixa de diálogo de converter"
  - "caixas de diálogo, O OLE"
  - "Caixa de diálogo OLE de converter"
  - "Caixas de diálogo VELHOS, Converter"
ms.assetid: a7c57714-31e8-4b78-834d-8ddd1b856a1c
caps.latest.revision: 22
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COleConvertDialog
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Para obter mais informações, consulte a estrutura de [OLEUICONVERT](http://msdn.microsoft.com/library/windows/desktop/ms686657) em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## Sintaxe  
  
```  
class COleConvertDialog : public COleDialog  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleConvertDialog::COleConvertDialog](../Topic/COleConvertDialog::COleConvertDialog.md)|Constrói um objeto de `COleConvertDialog` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleConvertDialog::DoConvert](../Topic/COleConvertDialog::DoConvert.md)|Executa a conversão especificada na caixa de diálogo.|  
|[COleConvertDialog::DoModal](../Topic/COleConvertDialog::DoModal.md)|Exibe a caixa de diálogo OLE de item de alteração.|  
|[COleConvertDialog::GetClassID](../Topic/COleConvertDialog::GetClassID.md)|Obtém **CLSID** associado com o item escolhido.|  
|[COleConvertDialog::GetDrawAspect](../Topic/COleConvertDialog::GetDrawAspect.md)|Especifica se o item como desenhar um ícone.|  
|[COleConvertDialog::GetIconicMetafile](../Topic/COleConvertDialog::GetIconicMetafile.md)|Obtém um manipulador para o metarquivo associado ao formulário icónico de este item.|  
|[COleConvertDialog::GetSelectionType](../Topic/COleConvertDialog::GetSelectionType.md)|Obtém o tipo de seleção escolhido.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleConvertDialog::m\_cv](../Topic/COleConvertDialog::m_cv.md)|Uma estrutura que controla o comportamento da caixa de diálogo.|  
  
## Comentários  
  
> [!NOTE]
>  O código gerado assistentes do recipiente de aplicativo usa essa classe.  
  
 Para obter mais informações sobre caixas de diálogo OLE\- específicas, consulte o artigo [Caixas de diálogo no OLE](../../mfc/dialog-boxes-in-ole.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CCommonDialog](../Topic/CCommonDialog%20Class.md)  
  
 [COleDialog](../../mfc/reference/coledialog-class.md)  
  
 `COleConvertDialog`  
  
## Requisitos  
 **Cabeçalho:** afxodlgs.h  
  
## Consulte também  
 [Classe de COleDialog](../../mfc/reference/coledialog-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de COleDialog](../../mfc/reference/coledialog-class.md)