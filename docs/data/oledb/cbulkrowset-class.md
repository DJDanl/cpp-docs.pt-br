---
title: Classe CBulkRowset
ms.date: 11/04/2016
f1_keywords:
- ATL::CBulkRowset
- ATL.CBulkRowset
- ATL::CBulkRowset<TAccessor>
- CBulkRowset
- ATL.CBulkRowset<TAccessor>
- CBulkRowset::AddRefRows
- CBulkRowset.AddRefRows
- ATL.CBulkRowset<TAccessor>.AddRefRows
- ATL::CBulkRowset::AddRefRows
- CBulkRowset<TAccessor>::AddRefRows
- ATL.CBulkRowset.AddRefRows
- ATL::CBulkRowset<TAccessor>::AddRefRows
- ATL.CBulkRowset<TAccessor>.CBulkRowset
- ATL::CBulkRowset::CBulkRowset
- CBulkRowset.CBulkRowset
- CBulkRowset::CBulkRowset
- ATL.CBulkRowset.CBulkRowset
- ATL::CBulkRowset<TAccessor>::CBulkRowset
- CBulkRowset<TAccessor>::CBulkRowset
- ATL.CBulkRowset.MoveFirst
- CBulkRowset<TAccessor>.MoveFirst
- ATL.CBulkRowset<TAccessor>.MoveFirst
- ATL::CBulkRowset::MoveFirst
- ATL::CBulkRowset<TAccessor>::MoveFirst
- CBulkRowset::MoveFirst
- CBulkRowset<TAccessor>::MoveFirst
- CBulkRowset.MoveFirst
- CBulkRowset.MoveLast
- ATL.CBulkRowset.MoveLast
- ATL::CBulkRowset<TAccessor>::MoveLast
- CBulkRowset::MoveLast
- CBulkRowset<TAccessor>.MoveLast
- ATL::CBulkRowset::MoveLast
- ATL.CBulkRowset<TAccessor>.MoveLast
- CBulkRowset<TAccessor>::MoveLast
- ATL.CBulkRowset<TAccessor>.MoveNext
- ATL::CBulkRowset::MoveNext
- CBulkRowset::MoveNext
- ATL.CBulkRowset.MoveNext
- CBulkRowset.MoveNext
- ATL::CBulkRowset<TAccessor>::MoveNext
- CBulkRowset<TAccessor>.MoveNext
- CBulkRowset<TAccessor>::MoveNext
- CBulkRowset::MovePrev
- CBulkRowset<TAccessor>::MovePrev
- ATL::CBulkRowset<TAccessor>::MovePrev
- CBulkRowset<TAccessor>.MovePrev
- ATL::CBulkRowset::MovePrev
- CBulkRowset.MovePrev
- ATL.CBulkRowset.MovePrev
- ATL.CBulkRowset<TAccessor>.MovePrev
- CBulkRowset<TAccessor>::MoveToBookmark
- CBulkRowset.MoveToBookmark
- ATL.CBulkRowset.MoveToBookmark
- CBulkRowset::MoveToBookmark
- ATL::CBulkRowset<TAccessor>::MoveToBookmark
- ATL::CBulkRowset::MoveToBookmark
- CBulkRowset.MoveToRatio
- ATL::CBulkRowset::MoveToRatio
- CBulkRowset::MoveToRatio
- ATL.CBulkRowset<TAccessor>.MoveToRatio
- ATL::CBulkRowset<TAccessor>::MoveToRatio
- ATL.CBulkRowset.MoveToRatio
- CBulkRowset<TAccessor>::MoveToRatio
- ATL.CBulkRowset<TAccessor>.ReleaseRows
- ATL::CBulkRowset<TAccessor>::ReleaseRows
- ATL.CBulkRowset.ReleaseRows
- CBulkRowset<TAccessor>::ReleaseRows
- ATL::CBulkRowset::ReleaseRows
- CBulkRowset::ReleaseRows
- CBulkRowset.ReleaseRows
- ATL.CBulkRowset.SetRows
- CBulkRowset::SetRows
- CBulkRowset<TAccessor>.SetRows
- ATL.CBulkRowset<TAccessor>.SetRows
- CBulkRowset<TAccessor>::SetRows
- ATL::CBulkRowset<TAccessor>::SetRows
- ATL::CBulkRowset::SetRows
- CBulkRowset.SetRows
- SetRows
helpviewer_keywords:
- CBulkRowset class
- AddRefRows method
- CBulkRowset class, constructor
- MoveFirst method
- MoveLast method
- MoveNext method
- MovePrev method
- MoveToBookmark method
- MoveToRatio method
- ReleaseRows method
- SetRows method
ms.assetid: c6bde426-c543-4022-a98a-9519d9e2ae59
ms.openlocfilehash: a235a38531141f306b33093ac2546ae232830f0e
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79446057"
---
# <a name="cbulkrowset-class"></a>Classe CBulkRowset

Busca e manipula linhas para trabalhar em massa de dados recuperando vários identificadores de linha com uma única chamada.

## <a name="syntax"></a>Sintaxe

```cpp
template <class TAccessor>
class CBulkRowset : public CRowset<TAccessor>
```

### <a name="parameters"></a>Parâmetros

*TAccessor*<br/>
Uma classe de acessador.

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** atldbcli. h

## <a name="members"></a>Membros

### <a name="methods"></a>{1&gt;Métodos&lt;1}

|||
|-|-|
|[AddRefRows](#addrefrows)|Incrementa a contagem de referência.|
|[CBulkRowset](#cbulkrowset)|Construtor.|
|[MoveFirst](#movefirst)|Recupera a primeira linha de dados, executando uma nova busca em massa, se necessário.|
|[Velas](#movelast)|Move para a última linha.|
|[MoveNext](#movenext)|Recupera a próxima linha de dados.|
|[MovePrev](#moveprev)|Move para a linha anterior.|
|[MoveToBookmark](#movetobookmark)|Busca a linha marcada por um indicador ou a linha em um deslocamento especificado a partir desse indicador.|
|[MoveToRatio](#movetoratio)|Busca linhas começando com base em uma posição fracionária no conjunto de linhas.|
|[ReleaseRows](#releaserows)|Define a linha atual (`m_nCurrentRow`) como zero e libera Todas as linhas.|
|[SetRows](#setrows)|Define o número de identificadores de linha a serem recuperados por uma chamada.|

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir demonstra o uso da classe `CBulkRowset`.

[!code-cpp[NVC_OLEDB_Consumer#1](../../data/oledb/codesnippet/cpp/cbulkrowset-class_1.cpp)]

## <a name="addrefrows"></a>CBulkRowset::AddRefRows

Chama [IRowset:: AddRefRows](/previous-versions/windows/desktop/ms719619(v=vs.85)) para incrementar a contagem de referência para todas as linhas recuperadas atualmente do conjunto de linhas em massa.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT AddRefRows() throw();
```

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

## <a name="cbulkrowset"></a>CBulkRowset::CBulkRowset

Cria um novo objeto `CBulkRowset` e define a contagem de linhas padrão como 10.

### <a name="syntax"></a>Sintaxe

```cpp
CBulkRowset();
```

## <a name="movefirst"></a>CBulkRowset:: MoveFirst

Recupera a primeira linha de dados.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT MoveFirst() throw();
```

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

## <a name="movelast"></a>CBulkRowset:: MoveLast

Move para a última linha.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT MoveLast() throw();
```

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

## <a name="movenext"></a>CBulkRowset:: MoveNext

Recupera a próxima linha de dados.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT MoveNext() throw();
```

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão. Quando o final do conjunto de linhas for atingido, retornará DB_S_ENDOFROWSET.

## <a name="moveprev"></a>CBulkRowset::MovePrev

Move para a linha anterior.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT MovePrev() throw();
```

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

## <a name="movetobookmark"></a>CBulkRowset::MoveToBookmark

Busca a linha marcada por um indicador ou a linha em um deslocamento especificado (*lSkip*) desse indicador.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT MoveToBookmark(const CBookmarkBase& bookmark,
   DBCOUNTITEM lSkip = 0) throw();
```

#### <a name="parameters"></a>Parâmetros

*Indicador*<br/>
no Um indicador que marca o local do qual você deseja buscar dados.

*lSkip*<br/>
no A contagem de números de linhas do indicador até a linha de destino. Se *lSkip* for zero, a primeira linha buscada será a linha marcada. Se *lSkip* for 1, a primeira linha buscada será a linha após a linha marcada. Se *lSkip* for-1, a primeira linha buscada será a linha antes da linha marcada.

### <a name="return-value"></a>Valor retornado

Consulte [IRowset:: GetData](/previous-versions/windows/desktop/ms716988(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="movetoratio"></a>CBulkRowset::MoveToRatio

Busca linhas começando com base em uma posição fracionária no conjunto de linhas.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT MoveToRatio(DBCOUNTITEM nNumerator,
   DBCOUNTITEM nDenominator)throw();
```

#### <a name="parameters"></a>Parâmetros

*nNumerator*<br/>
no O numerador usado para determinar a posição fracionária da qual buscar dados.

*nDenominator*<br/>
no O denominador usado para determinar a posição fracionária da qual buscar dados.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

`MoveToRatio` busca as linhas aproximadamente de acordo com a fórmula a seguir:

`(nNumerator *  RowsetSize ) / nDenominator`

Em que `RowsetSize` é o tamanho do conjunto de linhas, medido em linhas. A precisão dessa fórmula depende do provedor específico. Para obter detalhes, consulte [IRowsetScroll:: GetRowsAtRatio](/previous-versions/windows/desktop/ms709602(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="releaserows"></a>CBulkRowset:: ReleaseRows

Chama [IRowset:: ReleaseRows](/previous-versions/windows/desktop/ms719771(v=vs.85)) para decrementar a contagem de referência para todas as linhas recuperadas atualmente do conjunto de linhas em massa.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT ReleaseRows() throw();
```

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

## <a name="setrows"></a>CBulkRowset:: SetRows

Define o número de identificadores de linha recuperados por cada chamada.

### <a name="syntax"></a>Sintaxe

```cpp
void SetRows(DBROWCOUNT nRows) throw();
```

#### <a name="parameters"></a>Parâmetros

*nRows*<br/>
no O novo tamanho do conjunto de linhas (número de linhas).

### <a name="remarks"></a>Comentários

Se você chamar essa função, ela deverá ser anterior à abertura do conjunto de linhas.

## <a name="see-also"></a>Consulte também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)