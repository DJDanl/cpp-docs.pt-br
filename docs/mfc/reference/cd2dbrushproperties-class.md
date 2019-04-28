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
ms.openlocfilehash: 5ca791af658ee719b2e6d6ea78f82e23a66edc98
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62253708"
---
# <a name="cd2dbrushproperties-class"></a>Classe CD2DBrushProperties

Um wrapper para `D2D1_BRUSH_PROPERTIES`.

## <a name="syntax"></a>Sintaxe

```
class CD2DBrushProperties : public D2D1_BRUSH_PROPERTIES;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

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
