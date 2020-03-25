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
ms.openlocfilehash: a52d7443ab335e8546a4bcce03cf68c3b1d60e3d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80212000"
---
# <a name="cdbpropidset-class"></a>Classe CDBPropIDSet

Herda da estrutura de `DBPROPIDSET` e adiciona um construtor que inicializa os campos de chave, bem como o método de acesso [AddPropertyID](../../data/oledb/cdbpropidset-addpropertyid.md) .

## <a name="syntax"></a>Sintaxe

```cpp
class CDBPropIDSet : public tagDBPROPIDSET
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli. h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[AddPropertyID](#addpropertyid)|Adiciona uma propriedade ao conjunto de IDs de propriedade.|
|[CDBPropIDSet](#cdbpropidset)|Construtor.|
|[SetGUID](#setguid)|Define o GUID do conjunto de IDs de propriedade.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operador =](#op_equal)|Atribui o conteúdo de uma ID de propriedade definida para outra.|

## <a name="remarks"></a>Comentários

OLE DB consumidores usam estruturas `DBPROPIDSET` para passar uma matriz de IDs de propriedade para as quais o consumidor deseja obter informações de propriedade. As propriedades identificadas em uma única estrutura [DBPROPIDSET](/previous-versions/windows/desktop/ms717981(v=vs.85)) pertencem a um conjunto de propriedades.

## <a name="cdbpropidsetaddpropertyid"></a><a name="addpropertyid"></a>CDBPropIDSet:: AddPropertyID

Adiciona uma ID de propriedade ao conjunto de IDs de propriedade.

### <a name="syntax"></a>Sintaxe

```cpp
bool AddPropertyID(DBPROPID propid) throw();
```

#### <a name="parameters"></a>parâmetros

*propid*<br/>
no A ID da propriedade a ser adicionada ao conjunto de IDs de propriedade.

## <a name="cdbpropidsetcdbpropidset"></a><a name="cdbpropidset"></a>CDBPropIDSet::CDBPropIDSet

O construtor. Inicializa os `rgProperties`, `cProperties`e (opcionalmente) `guidPropertySet` campos da estrutura [DBPROPIDSET](/previous-versions/windows/desktop/ms717981(v=vs.85)) .

### <a name="syntax"></a>Sintaxe

```cpp
CDBPropIDSet(const GUID& guid);

CDBPropIDSet(const CDBPropIDSet& propidset);

CDBPropIDSet();
```

#### <a name="parameters"></a>parâmetros

*guid*<br/>
no Um GUID usado para inicializar o campo de `guidPropertySet`.

*propidset*<br/>
no Outro objeto `CDBPropIDSet` para a construção da cópia.

## <a name="cdbpropidsetsetguid"></a><a name="setguid"></a>CDBPropIDSet:: SetGUID

Define o campo GUID na estrutura de `DBPROPIDSET`.

### <a name="syntax"></a>Sintaxe

```cpp
void SetGUID(const GUID& guid) throw();
```

#### <a name="parameters"></a>parâmetros

*guid*<br/>
no Um GUID usado para definir o campo de `guidPropertySet` da estrutura [DBPROPIDSET](/previous-versions/windows/desktop/ms717981(v=vs.85)) .

### <a name="remarks"></a>Comentários

Esse campo também pode ser definido pelo [Construtor](../../data/oledb/cdbpropidset-cdbpropidset.md) . Chame essa função se você usar o construtor padrão para essa classe.

## <a name="cdbpropidsetoperator-"></a><a name="op_equal"></a>CDBPropIDSet:: Operator =

Atribui o conteúdo de uma ID de propriedade definida para outro conjunto de propriedades de ID.

### <a name="syntax"></a>Sintaxe

```cpp
CDBPropIDSet& operator =(CDBPropIDSet& propset) throw();
```

## <a name="see-also"></a>Confira também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)
