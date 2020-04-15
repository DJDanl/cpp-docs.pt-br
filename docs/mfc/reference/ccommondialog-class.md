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
ms.openlocfilehash: 853a4756df3b70f4f33deb7159b4d1aee610092c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369439"
---
# <a name="ccommondialog-class"></a>Classe CCommonDialog

A classe base para classes que encapsulam a funcionalidade dos diálogos comuns do Windows.

## <a name="syntax"></a>Sintaxe

```
class CCommonDialog : public CDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[ccommondialog::CCommonDialog](#ccommondialog)|Constrói um objeto `CCommonDialog`.|

## <a name="remarks"></a>Comentários

As classes a seguir encapsulam a funcionalidade dos diálogos comuns do Windows:

- [Cfiledialog](../../mfc/reference/cfiledialog-class.md)

- [Cfontdialog](../../mfc/reference/cfontdialog-class.md)

- [Ccolordialog](../../mfc/reference/ccolordialog-class.md)

- [Cpagesetupdialog](../../mfc/reference/cpagesetupdialog-class.md)

- [Cprintdialog](../../mfc/reference/cprintdialog-class.md)

- [Cprintdialogex](../../mfc/reference/cprintdialogex-class.md)

- [Cfindreplacedialog](../../mfc/reference/cfindreplacedialog-class.md)

- [Coledialog](../../mfc/reference/coledialog-class.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cdialog](../../mfc/reference/cdialog-class.md)

`CCommonDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdlgs.h

## <a name="ccommondialogccommondialog"></a><a name="ccommondialog"></a>ccommondialog::CCommonDialog

Constrói um objeto `CCommonDialog`.

```
explicit CCommonDialog(CWnd* pParentWnd);
```

### <a name="parameters"></a>Parâmetros

*Pparentwnd*<br/>
Aponta para o objeto da janela pai ou proprietário (do tipo [CWnd)](../../mfc/reference/cwnd-class.md)ao qual o objeto de diálogo pertence. Se for NULL, a janela pai do objeto de diálogo será definida na janela principal do aplicativo.

### <a name="remarks"></a>Comentários

Consulte [CDialog::CDialog](../../mfc/reference/cdialog-class.md#cdialog) para obter informações completas.

## <a name="see-also"></a>Confira também

[Classe CDialog](../../mfc/reference/cdialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CFileDialog](../../mfc/reference/cfiledialog-class.md)<br/>
[Classe CFontDialog](../../mfc/reference/cfontdialog-class.md)<br/>
[Classe CColorDialog](../../mfc/reference/ccolordialog-class.md)<br/>
[Classe CPageSetupDialog](../../mfc/reference/cpagesetupdialog-class.md)<br/>
[Classe CprintDialog](../../mfc/reference/cprintdialog-class.md)<br/>
[Classe CFindReplaceDialog](../../mfc/reference/cfindreplacedialog-class.md)<br/>
[Classe COleDialog](../../mfc/reference/coledialog-class.md)
