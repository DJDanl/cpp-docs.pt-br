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
ms.openlocfilehash: 3d8bfc40c3c9e937ad5acd7228e49877af65204a
ms.sourcegitcommit: 1839405b97036891b6e4d37c99def044d6f37eff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/18/2020
ms.locfileid: "88562149"
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
|[CMFCImagePaintArea:: GetMode](#getmode)|Recupera o modo de desenho atual.|
|[CMFCImagePaintArea:: SetBitmap](#setbitmap)|Define a imagem de bitmap para a área da imagem.|
|[CMFCImagePaintArea:: setColor](#setcolor)|Define a cor do desenho atual.|
|[CMFCImagePaintArea:: setmode](#setmode)|Define o modo de desenho atual.|

### <a name="remarks"></a>Comentários

Essa classe não se destina a ser usada diretamente do seu código.

A estrutura usa essa classe para exibir a área da imagem em uma caixa de diálogo do editor de imagens. Para obter mais informações sobre a caixa de diálogo Editor de imagens, consulte [classe CMFCImageEditorDialog](../../mfc/reference/cmfcimageeditordialog-class.md).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como construir um objeto da `CMFCImagePaintArea` classe, definir a cor atual do desenho, definir o modo de desenho atual e definir a imagem de bitmap para a área da imagem.

[!code-cpp[NVC_MFC_RibbonApp#37](../../mfc/reference/codesnippet/cpp/cmfcimagepaintarea-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CButton](../../mfc/reference/cbutton-class.md)

[CMFCImagePaintArea](../../mfc/reference/cmfcimagepaintarea-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afximagepaintarea. h

## <a name="cmfcimagepaintareacmfcimagepaintarea"></a><a name="cmfcimagepaintarea"></a> CMFCImagePaintArea::CMFCImagePaintArea

Constrói um objeto `CMFCImagePaintArea`.

```
CMFCImagePaintArea(CMFCImageEditorDialog* pParentDlg);
```

### <a name="parameters"></a>parâmetros

*pParentDlg*\
no Um ponteiro para a caixa de diálogo que é o pai do editor de imagem.

## <a name="cmfcimagepaintareagetmode"></a><a name="getmode"></a> CMFCImagePaintArea:: GetMode

Recupera o modo de desenho atual.

```
IMAGE_EDIT_MODE GetMode() const;
```

### <a name="return-value"></a>Valor retornado

Um valor [IMAGE_EDIT_MODE](cmfcimagepaintarea-image-edit-mode-enumeration.md) que especifica o modo de desenho atual.

## <a name="cmfcimagepaintareasetbitmap"></a><a name="setbitmap"></a> CMFCImagePaintArea:: SetBitmap

Define a imagem de bitmap para a área da imagem.

```cpp
void SetBitmap(CBitmap* pBitmap);
```

### <a name="parameters"></a>parâmetros

*pBitmap*\
no A nova imagem de bitmap a ser exibida.

### <a name="remarks"></a>Comentários

Se *pBitmap* for NULL, esse método definirá o tamanho da área de pintura modificável como zero. Caso contrário, ele define o tamanho da área de pintura modificável com o tamanho da imagem de bitmap fornecida.

## <a name="cmfcimagepaintareasetcolor"></a><a name="setcolor"></a> CMFCImagePaintArea:: setColor

Define a cor do desenho atual.

```cpp
void SetColor(COLORREF color);
```

### <a name="parameters"></a>parâmetros

*Cor*\
no A nova cor do desenho.

### <a name="remarks"></a>Comentários

Quando você seleciona uma cor na barra de paleta ou no seletor de cores do editor de imagens, a estrutura chama esse método para atualizar a cor atual do desenho. A cor inicial do desenho é preta (um valor COLORREF de 0).

A cor do desenho é usada pela caixa de diálogo Editor de imagem para todos os modos de desenho, exceto para IMAGE_EDIT_MODE_COLOR. Para obter mais informações sobre modos de desenho, consulte [Enumeração CMFCImagePaintArea:: IMAGE_EDIT_MODE](cmfcimagepaintarea-image-edit-mode-enumeration.md).

## <a name="cmfcimagepaintareasetmode"></a><a name="setmode"></a> CMFCImagePaintArea:: setmode

Define o modo de desenho atual.

```cpp
void SetMode(IMAGE_EDIT_MODE mode);
```

### <a name="parameters"></a>parâmetros

*moda*\
no Um valor [IMAGE_EDIT_MODE](cmfcimagepaintarea-image-edit-mode-enumeration.md) que especifica o modo de desenho atual.

## <a name="see-also"></a>Confira também

[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCImageEditorDialog](../../mfc/reference/cmfcimageeditordialog-class.md)
