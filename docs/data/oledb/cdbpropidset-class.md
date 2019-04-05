---
title: Classe CDBPropIDSet
ms.date: 11/04/2016
f1_keywords:
- CDBPropIDSet
- ATL.CDBPropIDSet
- ATL::CDBPropIDSet
- CDBPropIDSet.AddPropertyID
- CDBPropIDSet::AddPropertyID
- AddPropertyID
- ATL.CDBPropIDSet.AddPropertyID
- ATL::CDBPropIDSet::AddPropertyID
- ATL::CDBPropIDSet::CDBPropIDSet
- CDBPropIDSet
- CDBPropIDSet.CDBPropIDSet
- CDBPropIDSet::CDBPropIDSet
- ATL.CDBPropIDSet.CDBPropIDSet
- CDBPropIDSet.operator=
- ATL.CDBPropIDSet.operator=
- ATL::CDBPropIDSet::operator=
- CDBPropIDSet::operator=
- CDBPropIDSet.SetGUID
- ATL::CDBPropIDSet::SetGUID
- SetGUID
- ATL.CDBPropIDSet.SetGUID
- CDBPropIDSet::SetGUID
helpviewer_keywords:
- CDBPropIDSet class
- AddPropertyID method
- CDBPropIDSet class, constructor
- operator =, property sets
- = operator, with OLE DB templates
- operator=, property sets
- SetGUID method
ms.assetid: 52bb806c-9581-494d-9af7-50d8a4834805
ms.openlocfilehash: 9e878af3acf4c4d3a6ca785454c4bb072f17cf09
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59022405"
---
# <a name="cdbpropidset-class"></a>Classe CDBPropIDSet

Herda de `DBPROPIDSET` estruturar e adiciona um construtor que inicializa os campos de chave, bem como a [AddPropertyID](../../data/oledb/cdbpropidset-addpropertyid.md) método de acesso.

## <a name="syntax"></a>Sintaxe

```cpp
class CDBPropIDSet : public tagDBPROPIDSET
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli.h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[AddPropertyID](#addpropertyid)|Adiciona uma propriedade para a propriedade ID definida.|
|[CDBPropIDSet](#cdbpropidset)|Construtor.|
|[SetGUID](#setguid)|Define o GUID da ID da propriedade do conjunto.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operador =](#op_equal)|Atribui o conteúdo da ID de uma propriedade de conjunto para outro.|

## <a name="remarks"></a>Comentários

OLE DB que os consumidores usam `DBPROPIDSET` estruturas para passar uma matriz de IDs de propriedade para a qual o consumidor deseja obter informações de propriedade. As propriedades identificadas em uma única [DBPROPIDSET](/previous-versions/windows/desktop/ms717981(v=vs.85)) estrutura pertencem ao conjunto de uma propriedade.

## <a name="addpropertyid"></a> CDBPropIDSet::AddPropertyID

Adiciona uma ID de propriedade para a propriedade ID definida.

### <a name="syntax"></a>Sintaxe

```cpp
bool AddPropertyID(DBPROPID propid) throw();
```

#### <a name="parameters"></a>Parâmetros

*PROPID*<br/>
[in] A ID de propriedade a ser adicionado à ID de propriedade definida.

## <a name="cdbpropidset"></a> Cdbpropidset:: Cdbpropidset

O construtor. Inicializa o `rgProperties`, `cProperties`e (opcionalmente) `guidPropertySet` campos dos [DBPROPIDSET](/previous-versions/windows/desktop/ms717981(v=vs.85)) estrutura.

### <a name="syntax"></a>Sintaxe

```cpp
CDBPropIDSet(const GUID& guid);

CDBPropIDSet(const CDBPropIDSet& propidset);

CDBPropIDSet();
```

#### <a name="parameters"></a>Parâmetros

*GUID*<br/>
[in] Um GUID usado para inicializar o `guidPropertySet` campo.

*propidset*<br/>
[in] Outro `CDBPropIDSet` objeto para a construção da cópia.

## <a name="setguid"></a> CDBPropIDSet::SetGUID

Define o campo GUID no `DBPROPIDSET` estrutura.

### <a name="syntax"></a>Sintaxe

```cpp
void SetGUID(const GUID& guid) throw();
```

#### <a name="parameters"></a>Parâmetros

*GUID*<br/>
[in] Um GUID usado para definir a `guidPropertySet` campo do [DBPROPIDSET](/previous-versions/windows/desktop/ms717981(v=vs.85)) estrutura.

### <a name="remarks"></a>Comentários

Este campo pode ser definido [construtor](../../data/oledb/cdbpropidset-cdbpropidset.md) também. Chame essa função se você usar o construtor padrão para essa classe.

## <a name="op_equal"></a> CDBPropIDSet::operator =

Atribui o conteúdo da ID de uma propriedade definida como outro conjunto de propriedade de ID.

### <a name="syntax"></a>Sintaxe

```cpp
CDBPropIDSet& operator =(CDBPropIDSet& propset) throw();
```

## <a name="see-also"></a>Consulte também

[Modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência dos modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-reference.md)