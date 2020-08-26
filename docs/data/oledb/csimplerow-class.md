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
ms.openlocfilehash: c332fc0c653bbde3a69421b8166d4d099eaeeaf4
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88841071"
---
# <a name="csimplerow-class"></a>Classe CSimpleRow

Fornece uma implementação padrão para o identificador de linha, que é usado na classe [IRowsetImpl](../../data/oledb/irowsetimpl-class.md) .

## <a name="syntax"></a>Sintaxe

```cpp
class CSimpleRow
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Atldb. h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

| Nome | Descrição |
|-|-|
|[AddRefRow](#addrefrow)|Adiciona uma contagem de referência em um identificador de linha existente.|
|[Comparar](#compare)|Compara duas linhas para ver se elas se referem à mesma instância de linha.|
|[CSimpleRow](#csimplerow)|O construtor.|
|[ReleaseRow](#releaserow)|Libera linhas.|

### <a name="data-members"></a>Membros de dados

| Nome | Descrição |
|-|-|
|[m_dwRef](#dwref)|Contagem de referência para um identificador de linha existente.|
|[m_iRowset](#irowset)|Um índice para o conjunto de linhas que representa o cursor.|

## <a name="remarks"></a>Comentários

Um identificador de linha é logicamente uma marca exclusiva para uma linha de resultado. `IRowsetImpl` Cria um novo `CSimpleRow` para cada linha solicitada em [IRowsetImpl:: GetNextRows](../../data/oledb/irowsetimpl-getnextrows.md). `CSimpleRow` também pode ser substituído por sua própria implementação do identificador de linha, pois é um argumento de modelo padrão para `IRowsetImpl` . O único requisito para substituir essa classe é fazer com que a classe de substituição forneça um construtor que aceite um único parâmetro do tipo **Long**.

## <a name="csimplerowaddrefrow"></a><a name="addrefrow"></a> CSimpleRow::AddRefRow

Adiciona uma contagem de referência a um identificador de linha existente de uma maneira thread-safe.

### <a name="syntax"></a>Sintaxe

```cpp
DWORD AddRefRow();
```

## <a name="csimplerowcompare"></a><a name="compare"></a> CSimpleRow:: Compare

Compara duas linhas para ver se elas se referem à mesma instância de linha.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT Compare(CSimpleRow* pRow);
```

#### <a name="parameters"></a>Parâmetros

*pRow*<br/>
Um ponteiro para um objeto `CSimpleRow`.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT, geralmente S_OK, indicando que as duas linhas são a mesma instância de linha ou S_FALSE, indicando que as duas linhas são diferentes. Consulte [IRowsetIdentity:: IsSameRow](/previous-versions/windows/desktop/ms719629(v=vs.85)) na *referência do programador de OLE DB* para outros valores de retorno possíveis.

## <a name="csimplerowcsimplerow"></a><a name="csimplerow"></a> CSimpleRow::CSimpleRow

O construtor.

### <a name="syntax"></a>Sintaxe

```cpp
CSimpleRow(DBCOUNTITEM iRowsetCur);
```

#### <a name="parameters"></a>Parâmetros

*iRowsetCur*<br/>
no Índice para o conjunto de linhas atual.

### <a name="remarks"></a>Comentários

Define [m_iRowset](../../data/oledb/csimplerow-m-irowset.md) como *iRowsetCur*.

## <a name="csimplerowreleaserow"></a><a name="releaserow"></a> CSimpleRow::ReleaseRow

Libera linhas de uma maneira thread-safe.

### <a name="syntax"></a>Sintaxe

```cpp
DWORD ReleaseRow();
```

## <a name="csimplerowm_dwref"></a><a name="dwref"></a> CSimpleRow:: m_dwRef

Contagem de referência para um identificador de linha existente.

### <a name="syntax"></a>Sintaxe

```cpp
DWORD m_dwRef;
```

## <a name="csimplerowm_irowset"></a><a name="irowset"></a> CSimpleRow:: m_iRowset

Índice para o conjunto de linhas que representa o cursor.

### <a name="syntax"></a>Sintaxe

```cpp
KeyType m_iRowset;
```

## <a name="see-also"></a>Confira também

[Modelos de Provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo de provedor de OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)<br/>
[Classe IRowsetImpl](../../data/oledb/irowsetimpl-class.md)
