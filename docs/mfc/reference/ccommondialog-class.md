---
title: Classe CCommonDialog
ms.date: 11/04/2016
f1_keywords:
- CCommonDialog
- AFXDLGS/CCommonDialog
- AFXDLGS/CCommonDialog::CCommonDialog
helpviewer_keywords:
- CCommonDialog [MFC], CCommonDialog
ms.assetid: 1f68d65f-a0fd-4778-be22-ebbe51a95f95
ms.openlocfilehash: 4fa7aa51d1ce482e00f68365045cd35c3fb7939b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62182261"
---
# <a name="ccommondialog-class"></a>Classe CCommonDialog

A classe base para classes que encapsulam funcionalidade das caixas de diálogo comuns da Windows.

## <a name="syntax"></a>Sintaxe

```
class CCommonDialog : public CDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CCommonDialog::CCommonDialog](#ccommondialog)|Constrói um objeto `CCommonDialog`.|

## <a name="remarks"></a>Comentários

As seguintes classes de encapsulam a funcionalidade das caixas de diálogo comuns do Windows:

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

**Cabeçalho:** afxdlgs. h

##  <a name="ccommondialog"></a>  CCommonDialog::CCommonDialog

Constrói um objeto `CCommonDialog`.

```
explicit CCommonDialog(CWnd* pParentWnd);
```

### <a name="parameters"></a>Parâmetros

*pParentWnd*<br/>
Aponta para o objeto de janela pai ou proprietária (do tipo [CWnd](../../mfc/reference/cwnd-class.md)) ao qual pertence o objeto de caixa de diálogo. Se for NULL, a janela do pai do objeto de caixa de diálogo é definida como a janela principal do aplicativo.

### <a name="remarks"></a>Comentários

Ver [CDialog::CDialog](../../mfc/reference/cdialog-class.md#cdialog) para obter informações completas.

## <a name="see-also"></a>Consulte também

[Classe CDialog](../../mfc/reference/cdialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CFileDialog](../../mfc/reference/cfiledialog-class.md)<br/>
[Classe CFontDialog](../../mfc/reference/cfontdialog-class.md)<br/>
[Classe CColorDialog](../../mfc/reference/ccolordialog-class.md)<br/>
[Classe CPageSetupDialog](../../mfc/reference/cpagesetupdialog-class.md)<br/>
[Classe CPrintDialog](../../mfc/reference/cprintdialog-class.md)<br/>
[Classe CFindReplaceDialog](../../mfc/reference/cfindreplacedialog-class.md)<br/>
[Classe COleDialog](../../mfc/reference/coledialog-class.md)
