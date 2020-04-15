---
title: Classe CD2DBrushProperties
ms.date: 11/04/2016
f1_keywords:
- CD2DBrushProperties
- AFXRENDERTARGET/CD2DBrushProperties
- AFXRENDERTARGET/CD2DBrushProperties::CD2DBrushProperties
- AFXRENDERTARGET/CD2DBrushProperties::CommonInit
helpviewer_keywords:
- CD2DBrushProperties [MFC], CD2DBrushProperties
- CD2DBrushProperties [MFC], CommonInit
ms.assetid: c77d717f-0a16-4d74-b2ce-0ae1766ed6f9
ms.openlocfilehash: bf6399d2a245addb7e2e65100d33643fcd54e893
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369283"
---
# <a name="cd2dbrushproperties-class"></a>Classe CD2DBrushProperties

Um invólucro para. `D2D1_BRUSH_PROPERTIES`

## <a name="syntax"></a>Sintaxe

```
class CD2DBrushProperties : public D2D1_BRUSH_PROPERTIES;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DBrushPropriedades:CD2DBrushPropriedades](#cd2dbrushproperties)|Sobrecarregado. Cria `CD2D_BRUSH_PROPERTIES` uma estrutura|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2DBrushPropriedades:CommonInit](#commoninit)|Inicializa o objeto|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`D2D1_BRUSH_PROPERTIES`

`CD2DBrushProperties`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

## <a name="cd2dbrushpropertiescd2dbrushproperties"></a><a name="cd2dbrushproperties"></a>CD2DBrushPropriedades:CD2DBrushPropriedades

Cria uma estrutura CD2D_BRUSH_PROPERTIES

```
CD2DBrushProperties();
CD2DBrushProperties(FLOAT _opacity);

CD2DBrushProperties(
    D2D1_MATRIX_3X2_F _transform,
    FLOAT _opacity = 1.);
```

### <a name="parameters"></a>Parâmetros

*_opacity*<br/>
A opacidade base do pincel. O valor padrão é 1.0.

*_transform*<br/>
A transformação para aplicar ao pincel

## <a name="cd2dbrushpropertiescommoninit"></a><a name="commoninit"></a>CD2DBrushPropriedades:CommonInit

Inicializa o objeto

```
void CommonInit();
```

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
