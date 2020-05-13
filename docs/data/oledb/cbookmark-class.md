---
title: Classe CBookmark
ms.date: 11/04/2016
f1_keywords:
- ATL.CBookmark
- ATL::CBookmark<nSize>
- CBookmark
- ATL.CBookmark<nSize>
- ATL::CBookmark
- CBookmark<0>.CBookmark<0>
- CBookmark::CBookmark
- ATL.CBookmark.CBookmark
- CBookmark.CBookmark
- ATL::CBookmark<0>::CBookmark<0>
- ATL.CBookmark<0>.CBookmark<0>
- CBookmark<0>::CBookmark<0>
- ATL::CBookmark::CBookmark
- ATL.CBookmark<0>.GetBuffer
- ATL.CBookmark.GetBuffer
- ATL::CBookmark<0>::GetBuffer
- ATL::CBookmark::GetBuffer
- CBookmark.GetBuffer
- ATL::CBookmark<nSize>::GetBuffer
- ATL.CBookmark<nSize>.GetBuffer
- CBookmark<0>.GetBuffer
- CBookmark<nSize>::GetBuffer
- CBookmark<0>::GetBuffer
- CBookmark<nSize>.GetBuffer
- CBookmark::GetBuffer
- CBookmark::GetSize
- ATL.CBookmark<nSize>.GetSize
- CBookmark<nSize>.GetSize
- CBookmark.GetSize
- ATL::CBookmark::GetSize
- CBookmark<0>::GetSize
- ATL::CBookmark<nSize>::GetSize
- ATL.CBookmark<0>.GetSize
- ATL::CBookmark<0>::GetSize
- ATL.CBookmark.GetSize
- CBookmark<0>.GetSize
- CBookmark<nSize>::GetSize
- CBookmark<0>::SetBookmark
- ATL.CBookmark<0>.SetBookmark
- CBookmark<0>.SetBookmark
- SetBookmark
- ATL::CBookmark::SetBookmark
- ATL::CBookmark<0>::SetBookmark
- CBookmark.SetBookmark
- ATL.CBookmark.SetBookmark
- CBookmark::SetBookmark
- CBookmark<0>::operator=
- CBookmark<0>.operator=
- ATL.CBookmark.operator=
- CBookmark::operator=
- ATL.CBookmark<0>.operator=
- ATL::CBookmark<0>::operator=
- CBookmark.operator=
- ATL::CBookmark::operator=
helpviewer_keywords:
- CBookmark class
- CBookmark class, constructor
- GetBuffer method
- GetSize method
- SetBookmark method
- = operator, with OLE DB templates
- operator =, bookmarks
- operator=, bookmarks
ms.assetid: bc942f95-6f93-41d9-bb6e-bcdae4ae0b7a
ms.openlocfilehash: d3d82ea09b7ed2c1cbaf325906b4f9b480e1eb4e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81359331"
---
# <a name="cbookmark-class"></a>Classe CBookmark

Possui um valor de marcador em seu buffer.

## <a name="syntax"></a>Sintaxe

```cpp
template < DBLENGTH nSize = 0 >
class CBookmark : public CBookmarkBase

template <>
class CBookmark< 0 > : public CBookmarkBase
```

### <a name="parameters"></a>Parâmetros

*Nsize*<br/>
O tamanho do buffer de marca ção em bytes. Quando *nSize* é zero, o buffer de marcadores será criado dinamicamente no tempo de execução.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli.h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[Cbookmark](#cbookmark)|O construtor|
|[GetBuffer](#getbuffer)|Recupera o ponteiro para o buffer.|
|[GetSize](#getsize)|Recupera o tamanho do buffer em bytes.|
|[Setbookmark](#setbookmark)|Define o valor do marcador.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operador =](#operator)|Atribui uma `CBookmark` classe a outra.|

## <a name="remarks"></a>Comentários

`CBookmark<0>`é uma especialização `CBookmark`de modelo de; seu buffer é criado dinamicamente em tempo de execução.

## <a name="cbookmarkcbookmark"></a><a name="cbookmark"></a>CBookmark::CBookmark

O construtor.

### <a name="syntax"></a>Sintaxe

```cpp
CBookmark();
CBookmark(DBLENGTH nSize);
```

#### <a name="parameters"></a>Parâmetros

*Nsize*<br/>
[em] Tamanho do buffer do marcador em bytes.

### <a name="remarks"></a>Comentários

A primeira função define o buffer como NULL e o tamanho do buffer para 0. A segunda função define o tamanho do buffer para *nSize*e o buffer para uma matriz de bytes *nSize.*

> [!NOTE]
> Esta função só `CBookmark<0>`está disponível em .

## <a name="cbookmarkgetbuffer"></a><a name="getbuffer"></a>CBookmark::GetBuffer

Recupera o ponteiro para o buffer do marcador.

### <a name="syntax"></a>Sintaxe

```cpp
virtual BYTE* GetBuffer() const throw();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o buffer do marcador.

## <a name="cbookmarkgetsize"></a><a name="getsize"></a>Marca cbookmark::GetSize

Recupera o tamanho do buffer de marcador.

### <a name="syntax"></a>Sintaxe

```cpp
virtual DBLENGTH GetSize() const throw();
```

### <a name="return-value"></a>Valor retornado

O tamanho do buffer em bytes.

## <a name="cbookmarksetbookmark"></a><a name="setbookmark"></a>Marca de cmarcação::SetBookmark

Copia o valor do marcador referenciado `CBookmark` por *pBuffer* para o buffer e define o tamanho do buffer como *nSize*.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT SetBookmark(DBLENGTH nSize, BYTE* pBuffer) throw();
```

#### <a name="parameters"></a>Parâmetros

*Nsize*<br/>
[em] O tamanho do buffer do marcador.

*pBuffer*<br/>
[em] Um ponteiro para a matriz de bytes contendo o valor do marcador.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Esta função só `CBookmark<0>`está disponível em .

## <a name="cbookmarkoperator-"></a><a name="operator"></a>CBookmark::operador =

Atribui um `CBookmark` objeto a outro.

### <a name="syntax"></a>Sintaxe

```cpp
CBookmark& operator =(const CBookmark& bookmark) throw();
```

### <a name="remarks"></a>Comentários

Este operador é `CBookmark<0>`necessário apenas em .

## <a name="see-also"></a>Confira também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumo OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)
