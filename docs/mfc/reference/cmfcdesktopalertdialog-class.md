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
ms.openlocfilehash: 479959e9b021255e309caf6fee02588a8cd8f1d1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367648"
---
# <a name="cmfcdesktopalertdialog-class"></a>Classe CMFCDesktopAlertDialog

A `CMFCDesktopAlertDialog` classe é usada em conjunto com o [CMFCDesktopAlertWnd Class](../../mfc/reference/cmfcdesktopalertwnd-class.md) para exibir uma caixa de diálogo personalizada em uma janela pop-up.

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

## <a name="syntax"></a>Sintaxe

```
class CMFCDesktopAlertDialog : public CDialogEx
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCDesktopAlertDiálogo::CreateFromParams](#createfromparams)||
|[CMFCDesktopAlertDiálogo::getdlgsize](#getdlgsize)||
|[CMFCDesktopAlertDiálogo::HasFocus](#hasfocus)||
|[CMFCDesktopAlertDiálogo::PreTraduzirmensagem](#pretranslatemessage)|(Substitui `CDialogEx::PreTranslateMessage`.)|

### <a name="remarks"></a>Comentários

Execute as seguintes etapas para exibir uma caixa de diálogo personalizada em uma janela pop-up:

1. Derivar uma `CMFCDesktopAlertDialog`classe de .

1. Crie um modelo de diálogo filho nos recursos do projeto.

1. Chamada [CMFCDesktopAlertWnd::Crie](../../mfc/reference/cmfcdesktopalertwnd-class.md#create) com o ID de recurso do modelo de diálogo e um ponteiro para as informações da classe de tempo de execução da classe derivada como parâmetros.

1. Programe a caixa de diálogo personalizada para lidar com todas as notificações provenientes dos controles hospedados ou programe os controles hospedados para lidar diretamente com essas notificações.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cdialog](../../mfc/reference/cdialog-class.md)

[Cdialogex](../../mfc/reference/cdialogex-class.md)

[CMFCDesktopAlertDialog](../../mfc/reference/cmfcdesktopalertdialog-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxDesktopAlertDiálogo.h

## <a name="cmfcdesktopalertdialogcreatefromparams"></a><a name="createfromparams"></a>CMFCDesktopAlertDiálogo::CreateFromParams

```
BOOL CreateFromParams(
    CMFCDesktopAlertWndInfo& params,
    CMFCDesktopAlertWnd* pParent);
```

### <a name="parameters"></a>Parâmetros

[em] *params*<br/>

[em] *pParent*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcdesktopalertdialoggetdlgsize"></a><a name="getdlgsize"></a>CMFCDesktopAlertDiálogo::getdlgsize

```
CSize GetDlgSize();
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcdesktopalertdialoghasfocus"></a><a name="hasfocus"></a>CMFCDesktopAlertDiálogo::HasFocus

```
BOOL HasFocus() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcdesktopalertdialogpretranslatemessage"></a><a name="pretranslatemessage"></a>CMFCDesktopAlertDiálogo::PreTraduzirmensagem

```
virtual BOOL PreTranslateMessage(MSG* pMsg);
```

### <a name="parameters"></a>Parâmetros

[em] *pMsg*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCDesktopAlertWnd](../../mfc/reference/cmfcdesktopalertwnd-class.md)<br/>
[Classe CMFCDesktopAlertWndInfo](../../mfc/reference/cmfcdesktopalertwndinfo-class.md)<br/>
[Classe CDialogEx](../../mfc/reference/cdialogex-class.md)
