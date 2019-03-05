---
title: Enumeração CMFCImagePaintArea::IMAGE_EDIT_MODE
ms.date: 11/04/2016
f1_keywords:
- IMAGE_EDIT_MODE Enumeration
helpviewer_keywords:
- IMAGE_EDIT_MODE Enumeration method [MFC]
ms.assetid: e51db66a-fa1c-4766-9dac-a25b595f871a
ms.openlocfilehash: 372a1df6500f4d7219c89d8f82425246c2236514
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57272133"
---
# <a name="cmfcimagepaintareaimageeditmode-enumeration"></a>Enumeração CMFCImagePaintArea::IMAGE_EDIT_MODE

Especifica um modo de desenho que você pode usar para modificar uma imagem em uma caixa de diálogo do editor de imagem.

## <a name="syntax"></a>Sintaxe

```
enum IMAGE_EDIT_MODE
{
    IMAGE_EDIT_MODE_PEN = 0,
    IMAGE_EDIT_MODE_FILL,
    IMAGE_EDIT_MODE_LINE,
    IMAGE_EDIT_MODE_RECT,
    IMAGE_EDIT_MODE_ELLIPSE,
    IMAGE_EDIT_MODE_COLOR
};
```

## <a name="members"></a>Membros

|||
|-|-|
|Nome|Descrição|
|IMAGE_EDIT_MODE_PEN|Usado para desenhar os pixels individuais.|
|IMAGE_EDIT_MODE_FILL|Usado para preencher todas as áreas adjacentes que contêm a cor do local atual do cursor.|
|IMAGE_EDIT_MODE_LINE|Usado para desenhar uma linha.|
|IMAGE_EDIT_MODE_RECT|Usado para desenhar um retângulo.|
|IMAGE_EDIT_MODE_ELLIPSE|Usado para desenhar uma elipse.|
|IMAGE_EDIT_MODE_COLOR|Usado para definir a cor atual para a cor no local atual do cursor.|

### <a name="remarks"></a>Comentários

O `CMFCImagePaintArea` e `CMFCImageEditorDialog` classes usam essa enumeração para definir o modo de desenho atual. O modo de desenho e a cor atual são usadas para modificar a área de imagem em uma caixa de diálogo do editor de imagem. Para obter mais informações sobre `CMFCImagePaintArea` e `CMFCImageEditorDialog`, consulte [classe CMFCImagePaintArea](../../mfc/reference/cmfcimagepaintarea-class.md) e [classe CMFCImageEditorDialog](../../mfc/reference/cmfcimageeditordialog-class.md).

Quando você seleciona uma cor de uma imagem usando o modo de desenho IMAGE_EDIT_MODE_COLOR, a estrutura define o modo de desenho atual para IMAGE_EDIT_MODE_PEN.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afximagepaintarea.h

## <a name="see-also"></a>Consulte também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCImagePaintArea](../../mfc/reference/cmfcimagepaintarea-class.md)<br/>
[Classe CMFCImageEditorDialog](../../mfc/reference/cmfcimageeditordialog-class.md)
