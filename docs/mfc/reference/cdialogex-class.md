---
title: Classe CDialogEx
ms.date: 11/04/2016
f1_keywords:
- CDialogEx
- AFXDIALOGEX/CDialogEx
- AFXDIALOGEX/CDialogEx::CDialogEx
- AFXDIALOGEX/CDialogEx::SetBackgroundColor
- AFXDIALOGEX/CDialogEx::SetBackgroundImage
helpviewer_keywords:
- CDialogEx [MFC], CDialogEx
- CDialogEx [MFC], SetBackgroundColor
- CDialogEx [MFC], SetBackgroundImage
ms.assetid: a6ed3b1f-aef8-4b66-ac78-2160faf63c13
ms.openlocfilehash: f92058d1aa0dabccf6623d20a248fed8eb99ab26
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62168044"
---
# <a name="cdialogex-class"></a>Classe CDialogEx

O `CDialogEx` classe especifica a cor de plano de fundo e a imagem de plano de fundo de uma caixa de diálogo.

## <a name="syntax"></a>Sintaxe

```
class CDialogEx : public CDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDialogEx::CDialogEx](#cdialogex)|Constrói um objeto `CDialogEx`.|
|`CDialogEx::~CDialogEx`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDialogEx::SetBackgroundColor](#setbackgroundcolor)|Define a cor do plano de fundo da caixa de diálogo.|
|[CDialogEx::SetBackgroundImage](#setbackgroundimage)|Define a imagem de plano de fundo da caixa de diálogo.|

## <a name="remarks"></a>Comentários

Para usar o `CDialogEx` classe, derive sua classe de caixa de diálogo do `CDialogEx` classe, em vez do `CDialog` classe.

Imagens de caixa de diálogo são armazenadas em um arquivo de recurso. O framework exclui automaticamente qualquer imagem que é carregada do arquivo de recurso. Para excluir programaticamente a imagem de plano de fundo atual, chame o [CDialogEx::SetBackgroundImage](#setbackgroundimage) método ou implementar um `OnDestroy` manipulador de eventos. Quando você chama o [CDialogEx::SetBackgroundImage](#setbackgroundimage) método, passe um `HBITMAP` parâmetro como a alça da imagem. O `CDialogEx` objeto será apropriar-se de que a imagem e excluí-lo se o `m_bAutoDestroyBmp` sinalizador é `TRUE`.

Um `CDialogEx` objeto pode ser um pai de um [classe CMFCPopupMenu](../../mfc/reference/cmfcpopupmenu-class.md) objeto. O [classe CMFCPopupMenu](../../mfc/reference/cmfcpopupmenu-class.md) chamadas do objeto de `CDialogEx::SetActiveMenu` método quando o [classe CMFCPopupMenu](../../mfc/reference/cmfcpopupmenu-class.md) objeto é aberta. Depois disso, o `CDialogEx` objeto manipula qualquer evento de menu até que o [classe CMFCPopupMenu](../../mfc/reference/cmfcpopupmenu-class.md) objeto está fechado.

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

*nIDTemplate*<br/>
[in] A ID de recurso de um modelo de caixa de diálogo.

*lpszTemplateName*<br/>
[in] O nome do recurso de um modelo de caixa de diálogo.

*pParent*<br/>
[in] Um ponteiro para a janela pai. O valor padrão é NULL.

*pParentWnd*<br/>
[in] Um ponteiro para a janela pai. O valor padrão é NULL.

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="setbackgroundcolor"></a>  CDialogEx::SetBackgroundColor

Define a cor do plano de fundo da caixa de diálogo.

```
void SetBackgroundColor(
    COLORREF color,
    BOOL bRepaint=TRUE);
```

### <a name="parameters"></a>Parâmetros

*color*<br/>
[in] Um valor de cor RGB.

*bRepaint*<br/>
[in] TRUE para atualizar imediatamente a tela; Caso contrário, FALSE. O valor padrão é TRUE.

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

*hBitmap*<br/>
[in] Um identificador para a imagem de plano de fundo.

*uiBmpResId*<br/>
[in] A ID de recurso da imagem de plano de fundo.

*location*<br/>
[in] Um do `CDialogEx::BackgroundLocation` valores que especificam o local da imagem. Os valores válidos incluem BACKGR_TILE, BACKGR_TOPLEFT, BACKGR_TOPRIGHT, BACKGR_BOTTOMLEFT e BACKGR_BOTTOMRIGHT. O valor padrão é BACKGR_TILE.

*bAutoDestroy*<br/>
[in] TRUE para destruir automaticamente a imagem de plano de fundo; Caso contrário, FALSE.

*bRepaint*<br/>
[in] TRUE para redesenhar imediatamente a caixa de diálogo; Caso contrário, FALSE.

### <a name="return-value"></a>Valor de retorno

No segundo método de sobrecarga sintaxe, TRUE se o método for bem-sucedida; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

A imagem que você especificar não é alongada para caber na área de cliente de caixa de diálogo.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCPopupMenu](../../mfc/reference/cmfcpopupmenu-class.md)<br/>
[Classe CContextMenuManager](../../mfc/reference/ccontextmenumanager-class.md)
