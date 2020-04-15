---
title: Classe CMFCImagePaintArea
ms.date: 11/04/2016
f1_keywords:
- CMFCImagePaintArea
- AFXIMAGEPAINTAREA/CMFCImagePaintArea
- AFXIMAGEPAINTAREA/CMFCImagePaintArea::CMFCImagePaintArea
- AFXIMAGEPAINTAREA/CMFCImagePaintArea::GetMode
- AFXIMAGEPAINTAREA/CMFCImagePaintArea::SetBitmap
- AFXIMAGEPAINTAREA/CMFCImagePaintArea::SetColor
- AFXIMAGEPAINTAREA/CMFCImagePaintArea::SetMode
helpviewer_keywords:
- CMFCImagePaintArea [MFC], CMFCImagePaintArea
- CMFCImagePaintArea [MFC], GetMode
- CMFCImagePaintArea [MFC], SetBitmap
- CMFCImagePaintArea [MFC], SetColor
- CMFCImagePaintArea [MFC], SetMode
ms.assetid: c59eec22-f15a-4e58-8c4d-4a18a41f4452
ms.openlocfilehash: 4e73bd7bc1a28317dbfc452df1f45541dfcbfd21
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374441"
---
# <a name="cmfcimagepaintarea-class"></a>Classe CMFCImagePaintArea

Fornece a área de imagem que você usa para modificar uma imagem em uma caixa de diálogo do editor de imagens.

## <a name="syntax"></a>Sintaxe

```
class CMFCImagePaintArea : public CButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|||
|-|-|
|Nome|Descrição|
|[CMFCImagePaintArea::CMFCImagePaintArea](#cmfcimagepaintarea)|Constrói um objeto `CMFCImagePaintArea`.|
|`CMFCImagePaintArea::~CMFCImagePaintArea`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|||
|-|-|
|Nome|Descrição|
|[CMFCImagePaintarea::GetMode](#getmode)|Recupera o modo de desenho atual.|
|[CMFCImagePaintArea::SetBitmap](#setbitmap)|Define a imagem bitmap para a área de imagem.|
|[CMFCImagePaintarea::SetColor](#setcolor)|Define a cor do desenho atual.|
|[CMFCImagePaintarea::SetMode](#setmode)|Define o modo de desenho atual.|

### <a name="remarks"></a>Comentários

Essa classe não se destina a ser usada diretamente do seu código.

A estrutura usa essa classe para exibir a área de imagem em uma caixa de diálogo do editor de imagens. Para obter mais informações sobre a caixa de diálogo do editor de imagens, consulte [CMFCImageEditorSala de diálogo](../../mfc/reference/cmfcimageeditordialog-class.md).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCImagePaintArea` construir um objeto da classe, definir a cor do desenho atual, definir o modo de desenho atual e definir a imagem bitmap para a área de imagem.

[!code-cpp[NVC_MFC_RibbonApp#37](../../mfc/reference/codesnippet/cpp/cmfcimagepaintarea-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CButton](../../mfc/reference/cbutton-class.md)

[Cmfcimagepaintarea](../../mfc/reference/cmfcimagepaintarea-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afximagepaintarea.h

## <a name="cmfcimagepaintareacmfcimagepaintarea"></a><a name="cmfcimagepaintarea"></a>CMFCImagePaintArea::CMFCImagePaintArea

Constrói um objeto `CMFCImagePaintArea`.

```
CMFCImagePaintArea(CMFCImageEditorDialog* pParentDlg);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*pParentDlg*|[em] Um ponteiro para a caixa de diálogo que é o pai do editor de imagens.|

## <a name="cmfcimagepaintareagetmode"></a><a name="getmode"></a>CMFCImagePaintarea::GetMode

Recupera o modo de desenho atual.

```
IMAGE_EDIT_MODE GetMode() const;
```

### <a name="return-value"></a>Valor retornado

Um [valor IMAGE_EDIT_MODE](cmfcimagepaintarea-image-edit-mode-enumeration.md) que especifica o modo de desenho atual.

## <a name="cmfcimagepaintareasetbitmap"></a><a name="setbitmap"></a>CMFCImagePaintArea::SetBitmap

Define a imagem bitmap para a área de imagem.

```
void SetBitmap(CBitmap* pBitmap);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*Pbitmap*|[em] A nova imagem bitmap a ser exibida.|

### <a name="remarks"></a>Comentários

Se *o pBitmap* for NULL, este método definirá o tamanho da área de pintura modificável para zero. Caso contrário, ele define o tamanho da área de pintura modificável para o tamanho da imagem bitmap fornecida.

## <a name="cmfcimagepaintareasetcolor"></a><a name="setcolor"></a>CMFCImagePaintarea::SetColor

Define a cor do desenho atual.

```
void SetColor(COLORREF color);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*cor*|[em] A nova cor do desenho.|

### <a name="remarks"></a>Comentários

Quando você seleciona uma cor da barra de paleta do editor de imagens ou do seletor de cores, a estrutura chama esse método para atualizar a cor de desenho atual. A cor do desenho inicial é preta (um valor COLORREF de 0).

A cor do desenho é usada pela caixa de diálogo do editor de imagens para todos os modos de desenho, exceto IMAGE_EDIT_MODE_COLOR. Para obter mais informações sobre os modos de desenho, consulte [CMFCImagePaintArea::IMAGE_EDIT_MODE Enumeração](cmfcimagepaintarea-image-edit-mode-enumeration.md).

## <a name="cmfcimagepaintareasetmode"></a><a name="setmode"></a>CMFCImagePaintarea::SetMode

Define o modo de desenho atual.

```
void SetMode(IMAGE_EDIT_MODE mode);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*Modo*|[em] Um [valor IMAGE_EDIT_MODE](cmfcimagepaintarea-image-edit-mode-enumeration.md) que especifica o modo de desenho atual.|

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCImageEditorDialog](../../mfc/reference/cmfcimageeditordialog-class.md)
