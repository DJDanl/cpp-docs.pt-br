---
title: Classe CSimpleRow
ms.date: 11/04/2016
f1_keywords:
- CSimpleRow
- ATL::CSimpleRow
- ATL.CSimpleRow
- CSimpleRow::AddRefRow
- AddRefRow
- ATL.CSimpleRow.AddRefRow
- ATL::CSimpleRow::AddRefRow
- CSimpleRow.AddRefRow
- CSimpleRow.Compare
- CSimpleRow::Compare
- CSimpleRow
- ATL::CSimpleRow::CSimpleRow
- CSimpleRow.CSimpleRow
- ATL.CSimpleRow.CSimpleRow
- CSimpleRow::CSimpleRow
- ATL::CSimpleRow::ReleaseRow
- CSimpleRow::ReleaseRow
- ReleaseRow
- CSimpleRow.ReleaseRow
- ATL.CSimpleRow.ReleaseRow
- CSimpleRow.m_dwRef
- CSimpleRow::m_dwRef
- CSimpleRow::m_iRowset
- CSimpleRow.m_iRowset
helpviewer_keywords:
- CSimpleRow class
- AddRefRow method
- Compare method
- CSimpleRow class, constructor
- ReleaseRow method
- m_dwRef
- m_iRowset
ms.assetid: 06d9621d-60cc-4508-8b0c-528d1b1a809b
ms.openlocfilehash: b7284ace73d80eff6337e1d71cafef26094455f0
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57414012"
---
# <a name="csimplerow-class"></a>Classe CSimpleRow

Fornece uma implementação padrão para o identificador de linha, que é usado na [IRowsetImpl](../../data/oledb/irowsetimpl-class.md) classe.

## <a name="syntax"></a>Sintaxe

```cpp
class CSimpleRow
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldb.h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[AddRefRow](#addrefrow)|Adiciona uma contagem de referência em um identificador de linha existente.|
|[Compare](#compare)|Compara duas linhas para ver se eles se referem à mesma instância de linha.|
|[CSimpleRow](#csimplerow)|O construtor.|
|[ReleaseRow](#releaserow)|Libera linhas.|

### <a name="data-members"></a>Membros de Dados

|||
|-|-|
|[m_dwRef](#dwref)|Contagem de referência deve ser um identificador de linha existente.|
|[m_iRowset](#irowset)|Um índice ao conjunto de linhas que representa o cursor.|

## <a name="remarks"></a>Comentários

Um identificador de linha é logicamente uma marca exclusiva para uma linha de resultado. `IRowsetImpl` cria um novo `CSimpleRow` para todas as linhas solicitadas no [irowsetimpl:: GetNextRows](../../data/oledb/irowsetimpl-getnextrows.md). `CSimpleRow` também pode ser substituído por sua própria implementação da alça da linha, pois é um argumento de modelo padrão para `IRowsetImpl`. O único requisito para substituir essa classe é ter a classe de substituição a fornecer um construtor que aceita um único parâmetro do tipo **longo**.

## <a name="addrefrow"></a> CSimpleRow::AddRefRow

Adiciona uma contagem de referência para um identificador de linha existente em uma forma thread-safe.

### <a name="syntax"></a>Sintaxe

```cpp
DWORD AddRefRow();
```

## <a name="compare"></a> CSimpleRow::Compare

Compara duas linhas para ver se eles se referem à mesma instância de linha.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT Compare(CSimpleRow* pRow);
```

#### <a name="parameters"></a>Parâmetros

*pRow*<br/>
Um ponteiro para um `CSimpleRow` objeto.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT, geralmente S_OK, indicando que as duas linhas são a mesma instância de linha ou S_FALSE, indicando as duas linhas são diferentes. Ver [IRowsetIdentity::IsSameRow](/previous-versions/windows/desktop/ms719629(v=vs.85)) na *referência do programador DB OLE* para outro possíveis valores de retorno.

## <a name="csimplerow"></a> CSimpleRow::CSimpleRow

O construtor.

### <a name="syntax"></a>Sintaxe

```cpp
CSimpleRow(DBCOUNTITEM iRowsetCur);
```

#### <a name="parameters"></a>Parâmetros

*iRowsetCur*<br/>
[in] Índice ao conjunto de linhas atual.

### <a name="remarks"></a>Comentários

Conjuntos [m_iRowset](../../data/oledb/csimplerow-m-irowset.md) à *iRowsetCur*.

## <a name="releaserow"></a> CSimpleRow::ReleaseRow

Libera linhas em uma forma thread-safe.

### <a name="syntax"></a>Sintaxe

```cpp
DWORD ReleaseRow();
```

## <a name="dwref"></a> CSimpleRow::m_dwRef

Contagem de referência deve ser um identificador de linha existente.

### <a name="syntax"></a>Sintaxe

```cpp
DWORD m_dwRef;
```

## <a name="irowset"></a> CSimpleRow::m_iRowset

Índice para o conjunto de linhas que representa o cursor.

### <a name="syntax"></a>Sintaxe

```cpp
KeyType m_iRowset;
```

## <a name="see-also"></a>Consulte também

[Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)<br/>
[Classe IRowsetImpl](../../data/oledb/irowsetimpl-class.md)