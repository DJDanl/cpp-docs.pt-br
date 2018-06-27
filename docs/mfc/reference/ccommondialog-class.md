---
title: Classe CCommonDialog | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 53f53bdb19c6f40d73179b600051ecfaf6b69c94
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36950629"
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
  
##  <a name="ccommondialog"></a>  CCommonDialog::CCommonDialog  
 Constrói um objeto `CCommonDialog`.  
  
```  
explicit CCommonDialog(CWnd* pParentWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pParentWnd*  
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
