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
ms.openlocfilehash: dd698499607a5c4f04ccd01207d78fef9328c079
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "70311853"
---
# <a name="cenumeratoraccessor-class"></a>Classe CEnumeratorAccessor

Usado pelo [CEnumerator](../../data/oledb/cenumerator-class.md) para acessar os dados do conjunto de linhas do enumerador.

## <a name="syntax"></a>Sintaxe

```cpp
class CEnumeratorAccessor
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli. h

## <a name="members"></a>Membros

### <a name="data-members"></a>Membros de Dados

|||
|-|-|
|[m_bIsParent](#bisparent)|Uma variável que indica se o enumerador é um enumerador pai, se a linha for um enumerador.|
|[m_nType](#ntype)|Uma variável que indica se a linha descreve uma fonte de dados ou um enumerador.|
|[m_szDescription](#szdescription)|A descrição da fonte de dados ou do enumerador.|
|[m_szName](#szname)|O nome da fonte de dados ou do enumerador.|
|[m_szParseName](#szparsename)|Cadeia de caracteres a ser passada para [IParseDisplayName](/windows/win32/api/oleidl/nn-oleidl-iparsedisplayname) para obter um moniker para a fonte de dados ou o enumerador.|

## <a name="remarks"></a>Comentários

Esse conjunto de linhas consiste nas fontes de dados e enumeradores visíveis do enumerador atual.

## <a name="bisparent"></a> CEnumeratorAccessor::m_bIsParent

Uma variável que indica se o enumerador é um enumerador pai, se a linha for um enumerador.

### <a name="syntax"></a>Sintaxe

```cpp
VARIANT_BOOL m_bIsParent;
```

### <a name="remarks"></a>Comentários

Consulte [ISourcesRowset:: GetSourcesRowset](/previous-versions/windows/desktop/ms711200(v=vs.85)) na *referência do programador de OLE DB* para obter mais informações.

## <a name="ntype"></a>CEnumeratorAccessor::m_nType

Uma variável que indica se a linha descreve uma fonte de dados ou um enumerador.

### <a name="syntax"></a>Sintaxe

```cpp
USHORT m_nType;
```

### <a name="remarks"></a>Comentários

Consulte [ISourcesRowset:: GetSourcesRowset](/previous-versions/windows/desktop/ms711200(v=vs.85)) na *referência do programador de OLE DB* para obter mais informações.

## <a name="szdescription"></a>CEnumeratorAccessor::m_szDescription

A descrição da fonte de dados ou do enumerador.

### <a name="syntax"></a>Sintaxe

```cpp
WCHAR m_szDescription[129];
```

### <a name="remarks"></a>Comentários

Consulte [ISourcesRowset:: GetSourcesRowset](/previous-versions/windows/desktop/ms711200(v=vs.85)) na *referência do programador de OLE DB* para obter mais informações.

## <a name="szname"></a> CEnumeratorAccessor::m_szName

O nome da fonte de dados ou do enumerador.

### <a name="syntax"></a>Sintaxe

```cpp
WCHAR m_szName[129];
```

### <a name="remarks"></a>Comentários

Consulte [ISourcesRowset:: GetSourcesRowset](/previous-versions/windows/desktop/ms711200(v=vs.85)) na *referência do programador de OLE DB* para obter mais informações.

## <a name="szparsename"></a> CEnumeratorAccessor::m_szParseName

Cadeia de caracteres a ser passada para [IParseDisplayName](/windows/win32/api/oleidl/nn-oleidl-iparsedisplayname) para obter um moniker para a fonte de dados ou o enumerador.

### <a name="syntax"></a>Sintaxe

```cpp
WCHAR m_szParseName[129];
```

### <a name="remarks"></a>Comentários

Consulte [ISourcesRowset:: GetSourcesRowset](/previous-versions/windows/desktop/ms711200(v=vs.85)) na *referência do programador de OLE DB* para obter mais informações.

## <a name="see-also"></a>Consulte também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)