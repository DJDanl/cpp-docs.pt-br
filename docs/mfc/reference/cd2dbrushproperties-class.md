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
ms.openlocfilehash: 8fa93a6dda6b15b972ea399fc6522a8dec7c8de5
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50539016"
---
# <a name="cd2dbrushproperties-class"></a>Classe CD2DBrushProperties

Um wrapper para `D2D1_BRUSH_PROPERTIES`.

## <a name="syntax"></a>Sintaxe

```
class CD2DBrushProperties : public D2D1_BRUSH_PROPERTIES;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DBrushProperties::CD2DBrushProperties](#cd2dbrushproperties)|Sobrecarregado. Cria um `CD2D_BRUSH_PROPERTIES` estrutura|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2DBrushProperties::CommonInit](#commoninit)|Inicializa o objeto|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`D2D1_BRUSH_PROPERTIES`

`CD2DBrushProperties`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

##  <a name="cd2dbrushproperties"></a>  CD2DBrushProperties::CD2DBrushProperties

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
A opacidade de base do pincel. O valor padrão é 1.0.

*_transform*<br/>
A transformação a ser aplicada ao Pincel

##  <a name="commoninit"></a>  CD2DBrushProperties::CommonInit

Inicializa o objeto

```
void CommonInit();
```

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
