---
title: Classe CMFCDesktopAlertDialog
ms.date: 10/18/2018
f1_keywords:
- CMFCDesktopAlertDialog
- AFXDESKTOPALERTDIALOG/CMFCDesktopAlertDialog
- AFXDESKTOPALERTDIALOG/CMFCDesktopAlertDialog::CreateFromParams
- AFXDESKTOPALERTDIALOG/CMFCDesktopAlertDialog::GetDlgSize
- AFXDESKTOPALERTDIALOG/CMFCDesktopAlertDialog::HasFocus
- AFXDESKTOPALERTDIALOG/CMFCDesktopAlertDialog::PreTranslateMessage
helpviewer_keywords:
- CMFCDesktopAlertDialog [MFC], CreateFromParams
- CMFCDesktopAlertDialog [MFC], GetDlgSize
- CMFCDesktopAlertDialog [MFC], HasFocus
- CMFCDesktopAlertDialog [MFC], PreTranslateMessage
ms.assetid: a53c60aa-9607-485b-b826-ec64962075f6
ms.openlocfilehash: 02086e09ca3229fae28359b1ea81e4708c5d1865
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62403705"
---
# <a name="cmfcdesktopalertdialog-class"></a>Classe CMFCDesktopAlertDialog

O `CMFCDesktopAlertDialog` classe é usada junto com o [classe CMFCDesktopAlertWnd](../../mfc/reference/cmfcdesktopalertwnd-class.md) para exibir uma caixa de diálogo personalizada em uma janela pop-up.

Para obter mais detalhes, consulte o código-fonte localizado na **VC\\atlmfc\\src\\mfc** pasta de instalação do Visual Studio.

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

Execute as seguintes etapas para exibir uma caixa de diálogo personalizada em uma janela pop-up:

1. Derive uma classe de `CMFCDesktopAlertDialog`.

1. Crie um modelo de caixa de diálogo filho nos recursos do projeto.

1. Chame [CMFCDesktopAlertWnd::Create](../../mfc/reference/cmfcdesktopalertwnd-class.md#create) com a ID de recurso do modelo de caixa de diálogo e um ponteiro para as informações de classe de tempo de execução da classe derivada como parâmetros.

1. A caixa de diálogo personalizada para lidar com todas as notificações são provenientes dos controles hospedados de programa ou programar os controles hospedados para lidar com essas notificações diretamente.

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

[in] *params*<br/>

[in] *pParent*<br/>

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

[in] *pMsg*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCDesktopAlertWnd](../../mfc/reference/cmfcdesktopalertwnd-class.md)<br/>
[Classe CMFCDesktopAlertWndInfo](../../mfc/reference/cmfcdesktopalertwndinfo-class.md)<br/>
[Classe CDialogEx](../../mfc/reference/cdialogex-class.md)
