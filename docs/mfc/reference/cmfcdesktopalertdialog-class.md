---
title: Classe CMFCDesktopAlertDialog | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCDesktopAlertDialog
- AFXDESKTOPALERTDIALOG/CMFCDesktopAlertDialog
- AFXDESKTOPALERTDIALOG/CMFCDesktopAlertDialog::CreateFromParams
- AFXDESKTOPALERTDIALOG/CMFCDesktopAlertDialog::GetDlgSize
- AFXDESKTOPALERTDIALOG/CMFCDesktopAlertDialog::HasFocus
- AFXDESKTOPALERTDIALOG/CMFCDesktopAlertDialog::PreTranslateMessage
dev_langs:
- C++
helpviewer_keywords:
- CMFCDesktopAlertDialog [MFC], CreateFromParams
- CMFCDesktopAlertDialog [MFC], GetDlgSize
- CMFCDesktopAlertDialog [MFC], HasFocus
- CMFCDesktopAlertDialog [MFC], PreTranslateMessage
ms.assetid: a53c60aa-9607-485b-b826-ec64962075f6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 815f9e8177cc908d7d76ca6d0f3130d1d50c93ad
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cmfcdesktopalertdialog-class"></a>Classe CMFCDesktopAlertDialog
O `CMFCDesktopAlertDialog` classe é usada junto com o [CMFCDesktopAlertWnd classe](../../mfc/reference/cmfcdesktopalertwnd-class.md) para exibir uma caixa de diálogo personalizada em uma janela pop-up.  

 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCDesktopAlertDialog : public CDialogEx  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCDesktopAlertDialog::CreateFromParams](#createfromparams)||  
|[CMFCDesktopAlertDialog::GetDlgSize](#getdlgsize)||  
|[CMFCDesktopAlertDialog::HasFocus](#hasfocus)||  
|[CMFCDesktopAlertDialog::PreTranslateMessage](#pretranslatemessage)|(Substitui `CDialogEx::PreTranslateMessage`.)|  
  
### <a name="remarks"></a>Comentários  
 Execute as etapas a seguir para exibir uma caixa de diálogo personalizada em uma janela pop-up:  
  
1.  Derive uma classe de `CMFCDesktopAlertDialog`.  
  
2.  Crie um modelo de caixa de diálogo de filho nos recursos do projeto.  
  
3.  Chamar [CMFCDesktopAlertWnd::Create](../../mfc/reference/cmfcdesktopalertwnd-class.md#create) com a ID de recurso do modelo de caixa de diálogo e um ponteiro para as informações de classe de tempo de execução da classe derivada como parâmetros.  
  
4.  A caixa de diálogo personalizada para lidar com todas as notificações são provenientes de controles hospedados de programas ou programar os controles hospedados para lidar com essas notificações diretamente.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CDialogEx](../../mfc/reference/cdialogex-class.md)  
  
 [CMFCDesktopAlertDialog](../../mfc/reference/cmfcdesktopalertdialog-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxDesktopAlertDialog.h  
  
##  <a name="createfromparams"></a>  CMFCDesktopAlertDialog::CreateFromParams  

  
```  
BOOL CreateFromParams(
    CMFCDesktopAlertWndInfo& params,  
    CMFCDesktopAlertWnd* pParent);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `params`  
 [in] `pParent`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getdlgsize"></a>  CMFCDesktopAlertDialog::GetDlgSize  

  
```  
CSize GetDlgSize();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="hasfocus"></a>  CMFCDesktopAlertDialog::HasFocus  

  
```  
BOOL HasFocus() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="pretranslatemessage"></a>  CMFCDesktopAlertDialog::PreTranslateMessage  

  
```  
virtual BOOL PreTranslateMessage(MSG* pMsg);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pMsg`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCDesktopAlertWnd](../../mfc/reference/cmfcdesktopalertwnd-class.md)   
 [Classe CMFCDesktopAlertWndInfo](../../mfc/reference/cmfcdesktopalertwndinfo-class.md)   
 [Classe CDialogEx](../../mfc/reference/cdialogex-class.md)
