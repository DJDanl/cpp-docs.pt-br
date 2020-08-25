---
title: Enumeração CMFCImagePaintArea::IMAGE_EDIT_MODE
ms.date: 11/04/2016
f1_keywords:
- IMAGE_EDIT_MODE Enumeration
helpviewer_keywords:
- IMAGE_EDIT_MODE Enumeration method [MFC]
ms.assetid: e51db66a-fa1c-4766-9dac-a25b595f871a
ms.openlocfilehash: 37c877cc8562a9479535d9c6132e49e7c9b7e82f
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88831132"
---
# <a name="cmfcimagepaintareaimage_edit_mode-enumeration"></a>Enumeração CMFCImagePaintArea::IMAGE_EDIT_MODE

Especifica um modo de desenho que você usa para modificar uma imagem em uma caixa de diálogo do editor de imagens.

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

|Nome|Descrição|
|-|-|
|IMAGE_EDIT_MODE_PEN|Usado para desenhar pixels individuais.|
|IMAGE_EDIT_MODE_FILL|Usado para preencher todas as áreas adjacentes que contêm a cor no local do cursor atual.|
|IMAGE_EDIT_MODE_LINE|Usado para desenhar uma linha.|
|IMAGE_EDIT_MODE_RECT|Usado para desenhar um retângulo.|
|IMAGE_EDIT_MODE_ELLIPSE|Usado para desenhar uma elipse.|
|IMAGE_EDIT_MODE_COLOR|Usado para definir a cor atual para a cor no local do cursor atual.|

### <a name="remarks"></a>Comentários

As `CMFCImagePaintArea` `CMFCImageEditorDialog` classes e usam essa enumeração para definir o modo de desenho atual. O modo de desenho e a cor atual são usados para modificar a área da imagem em uma caixa de diálogo do editor de imagens. Para obter mais informações sobre `CMFCImagePaintArea` e `CMFCImageEditorDialog` , consulte [classe CMFCImagePaintArea](../../mfc/reference/cmfcimagepaintarea-class.md) e [classe CMFCImageEditorDialog](../../mfc/reference/cmfcimageeditordialog-class.md).

Quando você seleciona uma cor de uma imagem usando o modo de desenho IMAGE_EDIT_MODE_COLOR, a estrutura define o modo de desenho atual como IMAGE_EDIT_MODE_PEN.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afximagepaintarea. h

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCImagePaintArea](../../mfc/reference/cmfcimagepaintarea-class.md)<br/>
[Classe CMFCImageEditorDialog](../../mfc/reference/cmfcimageeditordialog-class.md)
