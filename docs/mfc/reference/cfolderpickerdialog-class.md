---
title: Classe CFolderPickerDialog
ms.date: 11/04/2016
f1_keywords:
- CFolderPickerDialog
- AFXDLGS/CFolderPickerDialog
- AFXDLGS/CFolderPickerDialog::CFolderPickerDialog
helpviewer_keywords:
- CFolderPickerDialog [MFC], CFolderPickerDialog
ms.assetid: 8db01684-dd1d-4e9c-989e-07a2318a8156
ms.openlocfilehash: f1718919a4fe9019ef591d83473c118eba966900
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57276176"
---
# <a name="cfolderpickerdialog-class"></a>Classe CFolderPickerDialog

Classe CFolderPickerDialog implementa CFileDialog no modo de selecionador de pasta.

## <a name="syntax"></a>Sintaxe

```
class CFolderPickerDialog : public CFileDialog;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CFolderPickerDialog::~CFolderPickerDialog](#cfolderpickerdialog__~cfolderpickerdialog)|Destruidor.|
|[CFolderPickerDialog::CFolderPickerDialog](#cfolderpickerdialog)|Construtor.|

## <a name="remarks"></a>Comentários

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CDialog](../../mfc/reference/cdialog-class.md)

[CCommonDialog](../../mfc/reference/ccommondialog-class.md)

[CFileDialog](../../mfc/reference/cfiledialog-class.md)

`CFolderPickerDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdlgs. h

##  <a name="cfolderpickerdialog"></a>  CFolderPickerDialog::CFolderPickerDialog

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
Uma combinação de um ou mais sinalizadores que permitem que você personalize a caixa de diálogo.

*pParentWnd*<br/>
Um ponteiro para a janela do pai ou o proprietário do objeto de caixa de diálogo.

*dwSize*<br/>
O tamanho da estrutura OPENFILENAME.

### <a name="remarks"></a>Comentários

##  <a name="_dtorcfolderpickerdialog"></a>  CFolderPickerDialog::~CFolderPickerDialog

Destruidor.

```
virtual ~CFolderPickerDialog();
```

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
