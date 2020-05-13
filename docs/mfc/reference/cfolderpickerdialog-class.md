---
title: Classe CFolderPickerDialog
ms.date: 03/27/2019
f1_keywords:
- CFolderPickerDialog
- AFXDLGS/CFolderPickerDialog
- AFXDLGS/CFolderPickerDialog::CFolderPickerDialog
helpviewer_keywords:
- CFolderPickerDialog [MFC], CFolderPickerDialog
ms.assetid: 8db01684-dd1d-4e9c-989e-07a2318a8156
ms.openlocfilehash: ed3dc151060519bce216cf4a2f3d6559d6b8937e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373860"
---
# <a name="cfolderpickerdialog-class"></a>Classe CFolderPickerDialog

A classe CFolderPickerDialog implementa CFileDialog no modo de seleção de pastas.

## <a name="syntax"></a>Sintaxe

```
class CFolderPickerDialog : public CFileDialog;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CPastPickerDiálogo::~CPastaPickerDiálogo](#_dtorcfolderpickerdialog)|Destruidor.|
|[CPastPickerDiálogo::CPastaPickerDiálogo](#cfolderpickerdialog)|Construtor.|

## <a name="remarks"></a>Comentários

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cdialog](../../mfc/reference/cdialog-class.md)

[Ccommondialog](../../mfc/reference/ccommondialog-class.md)

[Cfiledialog](../../mfc/reference/cfiledialog-class.md)

`CFolderPickerDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdlgs.h

## <a name="cfolderpickerdialogcfolderpickerdialog"></a><a name="cfolderpickerdialog"></a>CPastPickerDiálogo::CPastaPickerDiálogo

Construtor.

```
explicit CFolderPickerDialog(
    LPCTSTR lpszFolder = NULL,
    DWORD dwFlags = 0,
    CWnd* pParentWnd = NULL,
    DWORD dwSize = 0);
```

### <a name="parameters"></a>Parâmetros

*lpszFolder*<br/>
Pasta inicial.

*dwFlags*<br/>
Uma combinação de uma ou mais bandeiras que permitem personalizar a caixa de diálogo.

*Pparentwnd*<br/>
Um ponteiro para a janela pai ou proprietário do objeto da caixa de diálogo.

*Dwsize*<br/>
O tamanho da estrutura OPENFILENAME.

### <a name="remarks"></a>Comentários

## <a name="cfolderpickerdialogcfolderpickerdialog"></a><a name="_dtorcfolderpickerdialog"></a>CPastPickerDiálogo::~CPastaPickerDiálogo

Destruidor.

```
virtual ~CFolderPickerDialog();
```

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
