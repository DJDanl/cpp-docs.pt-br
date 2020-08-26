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
- CDBPropIDSet.CDBPropIDSet
- CDBPropIDSet::CDBPropIDSet
- ATL.CDBPropIDSet.CDBPropIDSet
- CDBPropIDSet.operator=
- ATL.CDBPropIDSet.operator=
- ATL::CDBPropIDSet::operator=
- CDBPropIDSet::operator=
- CDBPropIDSet.SetGUID
- ATL::CDBPropIDSet::SetGUID
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
ms.openlocfilehash: 24cc621e522ed1939fe3127d97e8d54b75fa1618
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88838289"
---
# <a name="cdbpropidset-class"></a>Classe CDBPropIDSet

Herda da `DBPROPIDSET` estrutura e adiciona um construtor que inicializa campos de chave, bem como o método de acesso [AddPropertyID](../../data/oledb/cdbpropidset-addpropertyid.md) .

## <a name="syntax"></a>Sintaxe

```cpp
class CDBPropIDSet : public tagDBPROPIDSET
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli. h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

| Nome | Descrição |
|-|-|
|[AddPropertyID](#addpropertyid)|Adiciona uma propriedade ao conjunto de IDs de propriedade.|
|[CDBPropIDSet](#cdbpropidset)|Construtor.|
|[SetGUID](#setguid)|Define o GUID do conjunto de IDs de propriedade.|

### <a name="operators"></a>Operadores

| Nome | Descrição |
|-|-|
|[operador =](#op_equal)|Atribui o conteúdo de uma ID de propriedade definida para outra.|

## <a name="remarks"></a>Comentários

OLE DB consumidores usam `DBPROPIDSET` estruturas para passar uma matriz de IDs de propriedade para as quais o consumidor deseja obter informações de propriedade. As propriedades identificadas em uma única estrutura [DBPROPIDSET](/previous-versions/windows/desktop/ms717981(v=vs.85)) pertencem a um conjunto de propriedades.

## <a name="cdbpropidsetaddpropertyid"></a><a name="addpropertyid"></a> CDBPropIDSet:: AddPropertyID

Adiciona uma ID de propriedade ao conjunto de IDs de propriedade.

### <a name="syntax"></a>Sintaxe

```cpp
bool AddPropertyID(DBPROPID propid) throw();
```

#### <a name="parameters"></a>parâmetros

*propid*<br/>
no A ID da propriedade a ser adicionada ao conjunto de IDs de propriedade.

## <a name="cdbpropidsetcdbpropidset"></a><a name="cdbpropidset"></a> CDBPropIDSet::CDBPropIDSet

O construtor. Inicializa os `rgProperties` `cProperties` campos, e (opcionalmente) `guidPropertySet` da estrutura [DBPROPIDSET](/previous-versions/windows/desktop/ms717981(v=vs.85)) .

### <a name="syntax"></a>Sintaxe

```cpp
CDBPropIDSet(const GUID& guid);

CDBPropIDSet(const CDBPropIDSet& propidset);

CDBPropIDSet();
```

#### <a name="parameters"></a>parâmetros

*guid*<br/>
no Um GUID usado para inicializar o `guidPropertySet` campo.

*propidset*<br/>
no Outro `CDBPropIDSet` objeto para a construção da cópia.

## <a name="cdbpropidsetsetguid"></a><a name="setguid"></a> CDBPropIDSet:: SetGUID

Define o campo GUID na `DBPROPIDSET` estrutura.

### <a name="syntax"></a>Sintaxe

```cpp
void SetGUID(const GUID& guid) throw();
```

#### <a name="parameters"></a>parâmetros

*guid*<br/>
no Um GUID usado para definir o `guidPropertySet` campo da estrutura [DBPROPIDSET](/previous-versions/windows/desktop/ms717981(v=vs.85)) .

### <a name="remarks"></a>Comentários

Esse campo também pode ser definido pelo [Construtor](../../data/oledb/cdbpropidset-cdbpropidset.md) . Chame essa função se você usar o construtor padrão para essa classe.

## <a name="cdbpropidsetoperator-"></a><a name="op_equal"></a> CDBPropIDSet:: Operator =

Atribui o conteúdo de uma ID de propriedade definida para outro conjunto de propriedades de ID.

### <a name="syntax"></a>Sintaxe

```cpp
CDBPropIDSet& operator =(CDBPropIDSet& propset) throw();
```

## <a name="see-also"></a>Confira também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)
