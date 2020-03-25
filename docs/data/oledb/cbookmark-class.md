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
ms.openlocfilehash: e15be3342b32b432c438b65ec57765cb135f5316
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80212232"
---
# <a name="cbookmark-class"></a>Classe CBookmark

Mantém um valor de indicador em seu buffer.

## <a name="syntax"></a>Sintaxe

```cpp
template < DBLENGTH nSize = 0 >
class CBookmark : public CBookmarkBase

template <>
class CBookmark< 0 > : public CBookmarkBase
```

### <a name="parameters"></a>parâmetros

*nSize*<br/>
O tamanho do buffer do indicador em bytes. Quando *nSize* for zero, o buffer de indicador será criado dinamicamente em tempo de execução.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli. h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[CBookmark](#cbookmark)|O Construtor|
|[GetBuffer](#getbuffer)|Recupera o ponteiro para o buffer.|
|[GetSize](#getsize)|Recupera o tamanho do buffer em bytes.|
|[SetBookmark](#setbookmark)|Define o valor do indicador.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operador =](#operator)|Atribui uma classe de `CBookmark` para outra.|

## <a name="remarks"></a>Comentários

`CBookmark<0>` é uma especialização de modelo de `CBookmark`; seu buffer é criado dinamicamente em tempo de execução.

## <a name="cbookmarkcbookmark"></a><a name="cbookmark"></a>CBookmark::CBookmark

O construtor.

### <a name="syntax"></a>Sintaxe

```cpp
CBookmark();
CBookmark(DBLENGTH nSize);
```

#### <a name="parameters"></a>parâmetros

*nSize*<br/>
no Tamanho do buffer do indicador em bytes.

### <a name="remarks"></a>Comentários

A primeira função define o buffer como nulo e o tamanho do buffer como 0. A segunda função define o tamanho do buffer como *nSize*e o buffer para uma matriz de bytes de *nSize* bytes.

> [!NOTE]
>  Essa função só está disponível no `CBookmark<0>`.

## <a name="cbookmarkgetbuffer"></a><a name="getbuffer"></a>CBookmark::GetBuffer

Recupera o ponteiro para o buffer de indicadores.

### <a name="syntax"></a>Sintaxe

```cpp
virtual BYTE* GetBuffer() const throw();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o buffer de indicadores.

## <a name="cbookmarkgetsize"></a><a name="getsize"></a>CBookmark::GetSize

Recupera o tamanho do buffer do indicador.

### <a name="syntax"></a>Sintaxe

```cpp
virtual DBLENGTH GetSize() const throw();
```

### <a name="return-value"></a>Valor retornado

O tamanho do buffer em bytes.

## <a name="cbookmarksetbookmark"></a><a name="setbookmark"></a>CBookmark:: SetBookmark

Copia o valor de indicador referenciado por *pBuffer* para o buffer de `CBookmark` e define o tamanho do buffer como *nSize*.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT SetBookmark(DBLENGTH nSize, BYTE* pBuffer) throw();
```

#### <a name="parameters"></a>parâmetros

*nSize*<br/>
no O tamanho do buffer do indicador.

*pBuffer*<br/>
no Um ponteiro para a matriz de bytes que contém o valor do indicador.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Essa função só está disponível no `CBookmark<0>`.

## <a name="cbookmarkoperator-"></a><a name="operator"></a>CBookmark:: Operator =

Atribui um objeto de `CBookmark` para outro.

### <a name="syntax"></a>Sintaxe

```cpp
CBookmark& operator =(const CBookmark& bookmark) throw();
```

### <a name="remarks"></a>Comentários

Esse operador é necessário apenas em `CBookmark<0>`.

## <a name="see-also"></a>Confira também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)
