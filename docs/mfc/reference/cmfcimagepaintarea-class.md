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
ms.openlocfilehash: af1d485d6d6281e909e33176ee1ae2b736c76600
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50641383"
---
# <a name="cmfcimagepaintarea-class"></a>Classe CMFCImagePaintArea

Fornece a área de imagem que você pode usar para modificar uma imagem em uma caixa de diálogo do editor de imagem.

## <a name="syntax"></a>Sintaxe

```
class CMFCImagePaintArea : public CButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|||
|-|-|
|Nome|Descrição|
|[CMFCImagePaintArea::CMFCImagePaintArea](#cmfcimagepaintarea)|Constrói um objeto `CMFCImagePaintArea`.|
|`CMFCImagePaintArea::~CMFCImagePaintArea`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|||
|-|-|
|Nome|Descrição|
|[CMFCImagePaintArea::GetMode](#getmode)|Recupera o modo de desenho atual.|
|[CMFCImagePaintArea::SetBitmap](#setbitmap)|Define a imagem de bitmap para a área de imagem.|
|[CMFCImagePaintArea::SetColor](#setcolor)|Define a cor atual do desenho.|
|[CMFCImagePaintArea::SetMode](#setmode)|Define o modo de desenho atual.|

### <a name="remarks"></a>Comentários

Essa classe não se destina a ser usada diretamente do seu código.

A estrutura usa essa classe para exibir a área de imagem em uma caixa de diálogo do editor de imagem. Para obter mais informações sobre a caixa de diálogo do editor de imagem, consulte [classe CMFCImageEditorDialog](../../mfc/reference/cmfcimageeditordialog-class.md).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como construir um objeto do `CMFCImagePaintArea` classe, defina a cor de desenho, defina o modo de desenho atual e definir a imagem de bitmap para a área de imagem atual.

[!code-cpp[NVC_MFC_RibbonApp#37](../../mfc/reference/codesnippet/cpp/cmfcimagepaintarea-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CButton](../../mfc/reference/cbutton-class.md)

[CMFCImagePaintArea](../../mfc/reference/cmfcimagepaintarea-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afximagepaintarea.h

##  <a name="cmfcimagepaintarea"></a>  CMFCImagePaintArea::CMFCImagePaintArea

Constrói um objeto `CMFCImagePaintArea`.

```
CMFCImagePaintArea(CMFCImageEditorDialog* pParentDlg);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*pParentDlg*|[in] Um ponteiro para a caixa de diálogo que é o pai do editor de imagem.|

##  <a name="getmode"></a>  CMFCImagePaintArea::GetMode

Recupera o modo de desenho atual.

```
IMAGE_EDIT_MODE GetMode() const;
```

### <a name="return-value"></a>Valor de retorno

Uma [IMAGE_EDIT_MODE](cmfcimagepaintarea-image-edit-mode-enumeration.md) valor que especifica o modo de desenho atual.

##  <a name="setbitmap"></a>  CMFCImagePaintArea::SetBitmap

Define a imagem de bitmap para a área de imagem.

```
void SetBitmap(CBitmap* pBitmap);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*pBitmap*|[in] A nova imagem de bitmap para exibir.|

### <a name="remarks"></a>Comentários

Se *pBitmap* for NULL, esse método define o tamanho da área de pintura modificável como zero. Caso contrário, ele define o tamanho da área de pintura modificável como o tamanho da imagem bitmap fornecido.

##  <a name="setcolor"></a>  CMFCImagePaintArea::SetColor

Define a cor atual do desenho.

```
void SetColor(COLORREF color);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*Cor*|[in] A nova cor de desenho.|

### <a name="remarks"></a>Comentários

Quando você seleciona uma cor da barra de paleta do editor de imagem ou seletor de cores, o framework chama esse método para atualizar a cor atual do desenho. A cor inicial do desenho é preta (um valor COLORREF 0).

A cor de desenho é usada pela caixa de diálogo do editor de imagem para todos os modos de desenho, exceto para IMAGE_EDIT_MODE_COLOR. Para obter mais informações sobre modos de desenho, consulte [cmfcimagepaintarea:: Image_edit_mode enumeração](cmfcimagepaintarea-image-edit-mode-enumeration.md).

##  <a name="setmode"></a>  CMFCImagePaintArea::SetMode

Define o modo de desenho atual.

```
void SetMode(IMAGE_EDIT_MODE mode);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*modo*|[in] Uma [IMAGE_EDIT_MODE](cmfcimagepaintarea-image-edit-mode-enumeration.md) valor que especifica o modo de desenho atual.|

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCImageEditorDialog](../../mfc/reference/cmfcimageeditordialog-class.md)
