---
title: Classe CCommonDialog | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CCommonDialog
- AFXDLGS/CCommonDialog
- AFXDLGS/CCommonDialog::CCommonDialog
dev_langs:
- C++
helpviewer_keywords:
- CCommonDialog [MFC], CCommonDialog
ms.assetid: 1f68d65f-a0fd-4778-be22-ebbe51a95f95
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a42acf9c4655868bcc078b3e40d3966587aeaaad
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ccommondialog-class"></a>Classe CCommonDialog
A classe base para classes que encapsulam funcionalidades de caixas de diálogo comuns da Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CCommonDialog : public CDialog  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CCommonDialog::CCommonDialog](#ccommondialog)|Constrói um objeto `CCommonDialog`.|  
  
## <a name="remarks"></a>Comentários  
 As classes a seguir encapsulam a funcionalidade de caixas de diálogo comuns da Windows:  
  
- [CFileDialog](../../mfc/reference/cfiledialog-class.md)  
  
- [CFontDialog](../../mfc/reference/cfontdialog-class.md)  
  
- [CColorDialog](../../mfc/reference/ccolordialog-class.md)  
  
- [CPageSetupDialog](../../mfc/reference/cpagesetupdialog-class.md)  
  
- [CPrintDialog](../../mfc/reference/cprintdialog-class.md)  
  
- [CPrintDialogEx](../../mfc/reference/cprintdialogex-class.md)  
  
- [CFindReplaceDialog](../../mfc/reference/cfindreplacedialog-class.md)  
  
- [COleDialog](../../mfc/reference/coledialog-class.md)  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 `CCommonDialog`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdlgs.h  
  
##  <a name="ccommondialog"></a>CCommonDialog::CCommonDialog  
 Constrói um objeto `CCommonDialog`.  
  
```  
explicit CCommonDialog(CWnd* pParentWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pParentWnd`  
 Aponta para o objeto de janela pai ou o proprietário (do tipo [CWnd](../../mfc/reference/cwnd-class.md)) ao qual pertence o objeto de caixa de diálogo. Se for **nulo**, janela de pai do objeto de caixa de diálogo é definida como a janela principal do aplicativo.  
  
### <a name="remarks"></a>Comentários  
 Consulte [CDialog::CDialog](../../mfc/reference/cdialog-class.md#cdialog) para obter informações completas.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDialog](../../mfc/reference/cdialog-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CFileDialog](../../mfc/reference/cfiledialog-class.md)   
 [Classe CFontDialog](../../mfc/reference/cfontdialog-class.md)   
 [Classe CColorDialog](../../mfc/reference/ccolordialog-class.md)   
 [Classe CPageSetupDialog](../../mfc/reference/cpagesetupdialog-class.md)   
 [Classe CPrintDialog](../../mfc/reference/cprintdialog-class.md)   
 [Classe CFindReplaceDialog](../../mfc/reference/cfindreplacedialog-class.md)   
 [Classe COleDialog](../../mfc/reference/coledialog-class.md)
