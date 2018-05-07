---
title: Classe CDialogEx | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CDialogEx
- AFXDIALOGEX/CDialogEx
- AFXDIALOGEX/CDialogEx::CDialogEx
- AFXDIALOGEX/CDialogEx::SetBackgroundColor
- AFXDIALOGEX/CDialogEx::SetBackgroundImage
dev_langs:
- C++
helpviewer_keywords:
- CDialogEx [MFC], CDialogEx
- CDialogEx [MFC], SetBackgroundColor
- CDialogEx [MFC], SetBackgroundImage
ms.assetid: a6ed3b1f-aef8-4b66-ac78-2160faf63c13
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 42da6afd054f05bb37ac0b4ea8bf497a31e433b8
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cdialogex-class"></a>Classe CDialogEx
O `CDialogEx` classe especifica a cor do plano de fundo e a imagem de plano de fundo de uma caixa de diálogo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CDialogEx : public CDialog  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDialogEx::CDialogEx](#cdialogex)|Constrói um objeto `CDialogEx`.|  
|`CDialogEx::~CDialogEx`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDialogEx::SetBackgroundColor](#setbackgroundcolor)|Define a cor de plano de fundo da caixa de diálogo.|  
|[CDialogEx::SetBackgroundImage](#setbackgroundimage)|Define a imagem de plano de fundo da caixa de diálogo.|  
  
## <a name="remarks"></a>Comentários  
 Para usar o `CDialogEx` classe, derive sua classe de caixa de diálogo do `CDialogEx` classe o `CDialog` classe.  
  
 Imagens da caixa de diálogo são armazenadas em um arquivo de recurso. A estrutura automaticamente exclui qualquer imagem que é carregada do arquivo de recurso. Para excluir a imagem de plano de fundo atual de programaticamente, chame o [CDialogEx::SetBackgroundImage](#setbackgroundimage) método ou implemente um `OnDestroy` manipulador de eventos. Quando você chama o [CDialogEx::SetBackgroundImage](#setbackgroundimage) método, passe um `HBITMAP` parâmetro como o identificador da imagem. O `CDialogEx` objeto será apropriar-se da imagem e excluí-lo se o `m_bAutoDestroyBmp` sinalizador é `TRUE`.  
  
 Um `CDialogEx` objeto pode ser um pai de um [CMFCPopupMenu classe](../../mfc/reference/cmfcpopupmenu-class.md) objeto. O [CMFCPopupMenu classe](../../mfc/reference/cmfcpopupmenu-class.md) objeto chamadas a `CDialogEx::SetActiveMenu` método quando o [CMFCPopupMenu classe](../../mfc/reference/cmfcpopupmenu-class.md) objeto é aberta. Depois disso, o `CDialogEx` objeto trata qualquer evento de menu até que o [CMFCPopupMenu classe](../../mfc/reference/cmfcpopupmenu-class.md) objeto está fechado.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CDialogEx](../../mfc/reference/cdialogex-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdialogex.h  
  
##  <a name="cdialogex"></a>  CDialogEx::CDialogEx  
 Constrói um objeto `CDialogEx`.  
  
```  
CDialogEx(
    UINT nIDTemplate,  
    CWnd* pParent=NULL);

 
CDialogEx(
    LPCTSTR lpszTemplateName,  
    CWnd* pParentWnd=NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIDTemplate`  
 A ID de recurso de um modelo de caixa de diálogo.  
  
 [in] `lpszTemplateName`  
 O nome do recurso de um modelo de caixa de diálogo.  
  
 [in] `pParent`  
 Um ponteiro para a janela pai. O valor padrão é `NULL`.  
  
 [in] `pParentWnd`  
 Um ponteiro para a janela pai. O valor padrão é `NULL`.  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setbackgroundcolor"></a>  CDialogEx::SetBackgroundColor  
 Define a cor de plano de fundo da caixa de diálogo.  
  
```  
void SetBackgroundColor(
    COLORREF color,  
    BOOL bRepaint=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `color`  
 Um valor de cor RGB.  
  
 [in] `bRepaint`  
 `TRUE` Para atualizar imediatamente a tela. Caso contrário, `FALSE`. O valor padrão é `TRUE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setbackgroundimage"></a>  CDialogEx::SetBackgroundImage  
 Define a imagem de plano de fundo da caixa de diálogo.  
  
```  
void SetBackgroundImage(
    HBITMAP hBitmap,  
    BackgroundLocation location=BACKGR_TILE,  
    BOOL bAutoDestroy=TRUE,  
    BOOL bRepaint=TRUE);

 
BOOL SetBackgroundImage(
    UINT uiBmpResId,  
    BackgroundLocation location=BACKGR_TILE,  
    BOOL bRepaint=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `hBitmap`  
 Um identificador para a imagem de plano de fundo.  
  
 [in] `uiBmpResId`  
 A ID de recurso da imagem de plano de fundo.  
  
 [in] `location`  
 Uma da `CDialogEx::BackgroundLocation` valores que especificam o local da imagem. Os valores válidos incluem BACKGR_TILE, BACKGR_TOPLEFT, BACKGR_TOPRIGHT, BACKGR_BOTTOMLEFT e BACKGR_BOTTOMRIGHT. O valor padrão é BACKGR_TILE.  
  
 [in] `bAutoDestroy`  
 `TRUE` para destruir automaticamente a imagem de plano de fundo; Caso contrário, `FALSE`.  
  
 [in] `bRepaint`  
 `TRUE` redesenhar imediatamente a caixa de diálogo; Caso contrário, `FALSE`.  
  
### <a name="return-value"></a>Valor de retorno  
 No segundo método de sobrecarga sintaxe, `TRUE` se o método for bem-sucedida; caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 A imagem que você especifica não é estendida para caber na área de cliente de caixa de diálogo.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCPopupMenu](../../mfc/reference/cmfcpopupmenu-class.md)   
 [Classe CContextMenuManager](../../mfc/reference/ccontextmenumanager-class.md)
