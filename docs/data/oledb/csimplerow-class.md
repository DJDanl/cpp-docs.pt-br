---
title: Classe CSimpleRow | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- CSimpleRow class
- AddRefRow method
- Compare method
- CSimpleRow class, constructor
- ReleaseRow method
- m_dwRef
- m_iRowset
ms.assetid: 06d9621d-60cc-4508-8b0c-528d1b1a809b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: d5ceb07577386f4b3fc9389cf9103fba4036b591
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50076784"
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

## <a name="addrefrow"></a> Csimplerow:: Addrefrow

Adiciona uma contagem de referência para um identificador de linha existente em uma forma thread-safe.

### <a name="syntax"></a>Sintaxe

```cpp
DWORD AddRefRow();
```

## <a name="compare"></a> Csimplerow:: Compare

Compara duas linhas para ver se eles se referem à mesma instância de linha.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT Compare(CSimpleRow* pRow);
```

#### <a name="parameters"></a>Parâmetros

*pRow*<br/>
Um ponteiro para um `CSimpleRow` objeto.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT, geralmente S_OK, indicando que as duas linhas são a mesma instância de linha ou S_FALSE, indicando as duas linhas são diferentes. Ver [IRowsetIdentity::IsSameRow](/previous-versions/windows/desktop/ms719629) na *referência do programador DB OLE* para outro possíveis valores de retorno.

## <a name="csimplerow"></a> Csimplerow:: Csimplerow

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

## <a name="releaserow"></a> Csimplerow:: Releaserow

Libera linhas em uma forma thread-safe.

### <a name="syntax"></a>Sintaxe

```cpp
DWORD ReleaseRow();
```

## <a name="dwref"></a> Csimplerow:: M_dwref

Contagem de referência deve ser um identificador de linha existente.

### <a name="syntax"></a>Sintaxe

```cpp
DWORD m_dwRef;
```

## <a name="irowset"></a> Csimplerow:: M_irowset

Índice para o conjunto de linhas que representa o cursor.

### <a name="syntax"></a>Sintaxe

```cpp
KeyType m_iRowset;
```

## <a name="see-also"></a>Consulte também

[Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)<br/>
[Classe IRowsetImpl](../../data/oledb/irowsetimpl-class.md)