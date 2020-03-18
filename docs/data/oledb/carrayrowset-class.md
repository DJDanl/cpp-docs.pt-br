---
title: Classe CArrayRowset
ms.date: 11/04/2016
f1_keywords:
- ATL.CArrayRowset<TAccessor>
- ATL.CArrayRowset
- CArrayRowset
- ATL::CArrayRowset
- ATL::CArrayRowset<TAccessor>
- ATL::CArrayRowset::CArrayRowset
- CArrayRowset.CArrayRowset
- ATL.CArrayRowset.CArrayRowset
- ATL.CArrayRowset<TAccessor>.CArrayRowset
- CArrayRowset::CArrayRowset
- CArrayRowset<TAccessor>::CArrayRowset
- ATL::CArrayRowset<TAccessor>::CArrayRowset
- CArrayRowset<TAccessor>.Snapshot
- ATL::CArrayRowset::Snapshot
- Snapshot
- CArrayRowset<TAccessor>::Snapshot
- ATL.CArrayRowset.Snapshot
- ATL.CArrayRowset<TAccessor>.Snapshot
- ATL::CArrayRowset<TAccessor>::Snapshot
- CArrayRowset::Snapshot
- CArrayRowset.Snapshot
- CArrayRowset::operator[]
- CArrayRowset.operator[]
- ATL::CArrayRowset::m_nRowsRead
- ATL::CArrayRowset<TAccessor>::m_nRowsRead
- CArrayRowset<TAccessor>::m_nRowsRead
- ATL.CArrayRowset<TAccessor>.m_nRowsRead
- CArrayRowset.m_nRowsRead
- m_nRowsRead
- ATL.CArrayRowset.m_nRowsRead
- CArrayRowset::m_nRowsRead
helpviewer_keywords:
- CArrayRowset class
- CArrayRowset class, constructor
- Snapshot method
- operator [], arrays
- '[] operator'
- operator[], arrays
- m_nRowsRead
ms.assetid: 511427e1-73ca-4fd8-9ba1-ae9463557cb6
ms.openlocfilehash: 66b7607eb28392196f6b7d3790aee976a861f2b6
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79441717"
---
# <a name="carrayrowset-class"></a>Classe CArrayRowset

Acessa os elementos de um conjunto de linhas usando a sintaxe de matriz.

## <a name="syntax"></a>Sintaxe

```cpp
template < class TAccessor >
class CArrayRowset :
   public CVirtualBuffer <TAccessor>,
   protected CBulkRowset <TAccessor>
```

### <a name="parameters"></a>Parâmetros

*TAccessor*<br/>
O tipo de classe de acessador que você deseja que o conjunto de linhas use.

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** atldbcli. h

## <a name="members"></a>Membros

### <a name="methods"></a>{1&gt;Métodos&lt;1}

|||
|-|-|
|[CArrayRowset](#carrayrowset)|Construtor.|
|[Instantâneo](#snapshot)|Lê todo o conjunto de linhas na memória.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[Operador&#91;&#93;](#operator)|Acessa um elemento do conjunto de linhas.|

### <a name="data-members"></a>Membros de Dados

|||
|-|-|
|[CArrayRowset::m_nRowsRead](#nrowsread)|O número de linhas já lidas.|

## <a name="carrayrowset"></a>CArrayRowset::CArrayRowset

Cria um novo objeto de `CArrayRowset`.

### <a name="syntax"></a>Sintaxe

```cpp
CArrayRowset(int nMax = 100000);
```

#### <a name="parameters"></a>Parâmetros

*Nmáx*<br/>
no Número máximo de linhas no conjunto de linhas.

## <a name="snapshot"></a>CArrayRowset:: instantâneo

Lê todo o conjunto de linhas na memória, criando uma imagem ou um instantâneo dele.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT Snapshot() throw();
```

## <a name="operator"></a>Operador CArrayRowset::

Fornece sintaxe semelhante à matriz para acessar uma linha no conjunto de linhas.

### <a name="syntax"></a>Sintaxe

```cpp
TAccessor & operator[](int nrow);
```

#### <a name="parameters"></a>Parâmetros

*TAccessor*<br/>
Um parâmetro de modelo que especifica o tipo de acessador armazenado no conjunto de linhas.

*nRow*<br/>
no Número da linha (elemento de matriz) que você deseja acessar.

### <a name="return-value"></a>Valor retornado

O conteúdo da linha solicitada.

### <a name="remarks"></a>Comentários

Se *nrow* exceder o número de linhas no conjunto de linhas, uma exceção será lançada.

## <a name="nrowsread"></a>CArrayRowset:: m_nRowsRead

Contém o número de linhas no conjunto de linhas que já foram lidas.

### <a name="syntax"></a>Sintaxe

```cpp
ULONG m_nRowsRead;
```

## <a name="see-also"></a>Consulte também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)<br/>
[Classe CRowset](../../data/oledb/crowset-class.md)