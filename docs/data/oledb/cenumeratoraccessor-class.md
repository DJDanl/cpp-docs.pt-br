---
title: Classe CEnumeratorAccessor
ms.date: 11/04/2016
f1_keywords:
- ATL::CEnumeratorAccessor
- CEnumeratorAccessor
- ATL.CEnumeratorAccessor
- CEnumeratorAccessor.m_bIsParent
- ATL::CEnumeratorAccessor::m_bIsParent
- m_bIsParent
- ATL.CEnumeratorAccessor.m_bIsParent
- CEnumeratorAccessor::m_bIsParent
- ATL::CEnumeratorAccessor::m_nType
- CEnumeratorAccessor.m_nType
- CEnumeratorAccessor::m_nType
- ATL.CEnumeratorAccessor.m_nType
- m_nType
- ATL::CEnumeratorAccessor::m_szDescription
- CEnumeratorAccessor.m_szDescription
- CEnumeratorAccessor::m_szDescription
- ATL.CEnumeratorAccessor.m_szDescription
- CEnumeratorAccessor::m_szName
- ATL.CEnumeratorAccessor.m_szName
- m_szName
- ATL::CEnumeratorAccessor::m_szName
- CEnumeratorAccessor.m_szName
- CEnumeratorAccessor::m_szParseName
- ATL::CEnumeratorAccessor::m_szParseName
- m_szParseName
- CEnumeratorAccessor.m_szParseName
- ATL.CEnumeratorAccessor.m_szParseName
helpviewer_keywords:
- CEnumeratorAccessor class
- m_bIsParent
- m_nType
- m_szDescription
- m_szName
- m_szParseName
ms.assetid: 21e8e7ea-3511-4afe-b33f-d520f4ff82bb
ms.openlocfilehash: e609b346bb4a0c2469c24e20540c646fa869ae26
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59025157"
---
# <a name="cenumeratoraccessor-class"></a>Classe CEnumeratorAccessor

Usado pelo [CEnumerator](../../data/oledb/cenumerator-class.md) para acessar os dados do conjunto de linhas do enumerador.

## <a name="syntax"></a>Sintaxe

```cpp
class CEnumeratorAccessor
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli.h

## <a name="members"></a>Membros

### <a name="data-members"></a>Membros de Dados

|||
|-|-|
|[m_bIsParent](#bisparent)|Uma variável que indica se o enumerador é um enumerador pai, se a linha é um enumerador.|
|[m_nType](#ntype)|Uma variável que indica se a linha descreve uma fonte de dados ou um enumerador.|
|[m_szDescription](#szdescription)|A descrição da fonte de dados ou enumerador.|
|[m_szName](#szname)|O nome da fonte de dados ou enumerador.|
|[m_szParseName](#szparsename)|Cadeia de caracteres para passar para [IParseDisplayName](/windows/desktop/api/oleidl/nn-oleidl-iparsedisplayname) para obter um identificador de origem para a fonte de dados ou enumerador.|

## <a name="remarks"></a>Comentários

Esse conjunto de linhas consiste nas fontes de dados e enumeradores visíveis do enumerador atual.

## <a name="bisparent"></a> CEnumeratorAccessor::m_bIsParent

Uma variável que indica se o enumerador é um enumerador pai, se a linha é um enumerador.

### <a name="syntax"></a>Sintaxe

```cpp
VARIANT_BOOL m_bIsParent;
```

### <a name="remarks"></a>Comentários

Ver [ISourcesRowset:: Getsourcesrowset](/previous-versions/windows/desktop/ms711200(v=vs.85)) na *referência do programador DB OLE* para obter mais informações.

## <a name="ntype"></a> Cenumeratoraccessor:: M_ntype

Uma variável que indica se a linha descreve uma fonte de dados ou um enumerador.

### <a name="syntax"></a>Sintaxe

```cpp
USHORT m_nType;
```

### <a name="remarks"></a>Comentários

Ver [ISourcesRowset:: Getsourcesrowset](/previous-versions/windows/desktop/ms711200(v=vs.85)) na *referência do programador DB OLE* para obter mais informações.

## <a name="szdescription"></a> CEnumeratorAccessor::m_szDescription

A descrição da fonte de dados ou enumerador.

### <a name="syntax"></a>Sintaxe

```cpp
WCHAR m_szDescription[129];
```

### <a name="remarks"></a>Comentários

Ver [ISourcesRowset:: Getsourcesrowset](/previous-versions/windows/desktop/ms711200(v=vs.85)) na *referência do programador DB OLE* para obter mais informações.

## <a name="szname"></a> CEnumeratorAccessor::m_szName

O nome da fonte de dados ou enumerador.

### <a name="syntax"></a>Sintaxe

```cpp
WCHAR m_szName[129];
```

### <a name="remarks"></a>Comentários

Ver [ISourcesRowset:: Getsourcesrowset](/previous-versions/windows/desktop/ms711200(v=vs.85)) na *referência do programador DB OLE* para obter mais informações.

## <a name="szparsename"></a> CEnumeratorAccessor::m_szParseName

Cadeia de caracteres para passar para [IParseDisplayName](/windows/desktop/api/oleidl/nn-oleidl-iparsedisplayname) para obter um identificador de origem para a fonte de dados ou enumerador.

### <a name="syntax"></a>Sintaxe

```cpp
WCHAR m_szParseName[129];
```

### <a name="remarks"></a>Comentários

Ver [ISourcesRowset:: Getsourcesrowset](/previous-versions/windows/desktop/ms711200(v=vs.85)) na *referência do programador DB OLE* para obter mais informações.

## <a name="see-also"></a>Consulte também

[Modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência dos modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-reference.md)