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
ms.openlocfilehash: b34c441ac63b023ae6272a1646151aad4be1bfbc
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375629"
---
# <a name="cdialogex-class"></a>Classe CDialogEx

A `CDialogEx` classe especifica a imagem de fundo e de fundo de uma caixa de diálogo.

## <a name="syntax"></a>Sintaxe

```
class CDialogEx : public CDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[cdialogex::Cdialogex](#cdialogex)|Constrói um objeto `CDialogEx`.|
|`CDialogEx::~CDialogEx`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[cdialogex::setbackgroundColor](#setbackgroundcolor)|Define a cor de fundo da caixa de diálogo.|
|[cdialogex::setbackgroundImage](#setbackgroundimage)|Define a imagem de fundo da caixa de diálogo.|

## <a name="remarks"></a>Comentários

Para usar `CDialogEx` a classe, obtenha sua `CDialogEx` classe de `CDialog` caixa de diálogo da classe em vez da classe.

As imagens da caixa de diálogo são armazenadas em um arquivo de recurso. A estrutura exclui automaticamente qualquer imagem que seja carregada do arquivo de recursos. Para excluir programáticamente a imagem de fundo atual, ligue para o `OnDestroy` método [CDialogEx::SetBackgroundImage](#setbackgroundimage) ou implemente um manipulador de eventos. Quando você chamar o método [CDialogEx::SetBackgroundImage,](#setbackgroundimage) passe em um `HBITMAP` parâmetro como o cabo da imagem. O `CDialogEx` objeto tomará posse da imagem e `m_bAutoDestroyBmp` a `TRUE`excluirá se a bandeira for .

Um `CDialogEx` objeto pode ser pai de um objeto [CMFCPopupMenu Class.](../../mfc/reference/cmfcpopupmenu-class.md) O objeto [CMFCPopupMenu](../../mfc/reference/cmfcpopupmenu-class.md) `CDialogEx::SetActiveMenu` Class chama o método quando o objeto [CMFCPopupMenu Class](../../mfc/reference/cmfcpopupmenu-class.md) é aberto. Depois, `CDialogEx` o objeto lida com qualquer evento de menu até que o objeto [CMFCPopupMenu Class](../../mfc/reference/cmfcpopupmenu-class.md) seja fechado.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cdialog](../../mfc/reference/cdialog-class.md)

[Cdialogex](../../mfc/reference/cdialogex-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdialogex.h

## <a name="cdialogexcdialogex"></a><a name="cdialogex"></a>cdialogex::Cdialogex

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

*Nidtemplate*<br/>
[em] O ID de recurso de um modelo de caixa de diálogo.

*lpszTemplateName*<br/>
[em] O nome do recurso de um modelo de caixa de diálogo.

*pParent*<br/>
[em] Um ponteiro para a janela dos pais. O valor padrão é NULL.

*Pparentwnd*<br/>
[em] Um ponteiro para a janela dos pais. O valor padrão é NULL.

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cdialogexsetbackgroundcolor"></a><a name="setbackgroundcolor"></a>cdialogex::setbackgroundColor

Define a cor de fundo da caixa de diálogo.

```
void SetBackgroundColor(
    COLORREF color,
    BOOL bRepaint=TRUE);
```

### <a name="parameters"></a>Parâmetros

*cor*<br/>
[em] Um valor de cor RGB.

*bRepaint*<br/>
[em] TRUE para atualizar imediatamente a tela; caso contrário, FALSE. O valor padrão é TRUE.

### <a name="remarks"></a>Comentários

## <a name="cdialogexsetbackgroundimage"></a><a name="setbackgroundimage"></a>cdialogex::setbackgroundImage

Define a imagem de fundo da caixa de diálogo.

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

*Hbitmap*<br/>
[em] Uma alça para a imagem de fundo.

*uiBmpResId*<br/>
[em] O ID de recurso da imagem de fundo.

*local*<br/>
[em] Um dos `CDialogEx::BackgroundLocation` valores que especificam a localização da imagem. Os valores válidos incluem BACKGR_TILE, BACKGR_TOPLEFT, BACKGR_TOPRIGHT, BACKGR_BOTTOMLEFT e BACKGR_BOTTOMRIGHT. O valor padrão é BACKGR_TILE.

*bAutoDestroy*<br/>
[em] TRUE para destruir automaticamente a imagem de fundo; caso contrário, FALSE.

*bRepaint*<br/>
[em] TRUE para redesenhar imediatamente a caixa de diálogo; caso contrário, FALSE.

### <a name="return-value"></a>Valor retornado

No segundo método, sintaxe de sobrecarga, TRUE se o método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

A imagem especificada não está esticada para se adequar à área cliente da caixa de diálogo.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCPopupMenu](../../mfc/reference/cmfcpopupmenu-class.md)<br/>
[Classe CContextMenuManager](../../mfc/reference/ccontextmenumanager-class.md)
