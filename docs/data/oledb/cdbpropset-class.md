---
title: Classe CDBPropSet
ms.date: 11/04/2016
f1_keywords:
- CDBPropSet
- ATL.CDBPropSet
- ATL::CDBPropSet
- CDBPropSet::AddProperty
- CDBPropSet.AddProperty
- AddProperty
- ATL::CDBPropSet::AddProperty
- ATL.CDBPropSet.AddProperty
- CDBPropSet.CDBPropSet
- CDBPropSet::CDBPropSet
- ATL::CDBPropSet::CDBPropSet
- ATL.CDBPropSet.CDBPropSet
- CDBPropSet.operator=
- ATL::CDBPropSet::operator=
- ATL.CDBPropSet.operator=
- CDBPropSet::operator=
- ATL.CDBPropSet.SetGUID
- CDBPropSet.SetGUID
- ATL::CDBPropSet::SetGUID
- CDBPropSet::SetGUID
helpviewer_keywords:
- CDBPropSet class
- AddProperty method
- CDBPropSet class, constructor
- operator =, property sets
- = operator, with OLE DB templates
- operator=, property sets
- SetGUID method
- AddProperty method
ms.assetid: 54190149-c277-4679-b81a-ef484d4d1c00
ms.openlocfilehash: e2bb01e6acb9298b08fddc3117ec93dd7c0c2417
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80211999"
---
# <a name="cdbpropset-class"></a>Classe CDBPropSet

Herda da estrutura de `DBPROPSET` e adiciona um construtor que inicializa os campos de chave, bem como o método de acesso de `AddProperty`.

## <a name="syntax"></a>Sintaxe

```cpp
class CDBPropSet : public tagDBPROPSET
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli. h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[AddProperty](#addproperty)|Adiciona uma propriedade ao conjunto de propriedades.|
|[CDBPropSet](#cdbpropset)|Construtor.|
|[SetGUID](#setguid)|Define o campo `guidPropertySet` da estrutura de `DBPROPSET`.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operador =](#op_equal)|Atribui o conteúdo de um conjunto de propriedades para outro.|

## <a name="remarks"></a>Comentários

Os provedores de OLE DB e os consumidores usam estruturas de `DBPROPSET` para passar matrizes de estruturas de `DBPROP`. Cada estrutura de `DBPROP` representa uma única propriedade que pode ser definida.

## <a name="cdbpropsetaddproperty"></a><a name="addproperty"></a>CDBPropSet:: AddProperty

Adiciona uma propriedade ao conjunto de propriedades.

### <a name="syntax"></a>Sintaxe

```cpp
bool AddProperty(DWORD dwPropertyID,
   constVARIANT& var,
   DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED) throw();bool AddProperty(DWORD dwPropertyID,
   LPCSTR szValue,  DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED) throw();bool AddProperty(DWORD dwPropertyID,
   LPCWSTR szValue,DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED) throw();bool AddProperty(DWORD dwPropertyID,
   bool bValue,  DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED) throw();bool AddProperty(DWORD dwPropertyID,
   BYTE bValue,  DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED);bool AddProperty(DWORD dwPropertyID,
   short nValue,  DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED);bool AddProperty(DWORD dwPropertyID,
   long nValue,  DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED);bool AddProperty(DWORD dwPropertyID,
   float fltValue,  DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED);bool AddProperty(DWORD dwPropertyID,
   double dblValue,  DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED) throw();bool AddProperty(DWORD dwPropertyID,
   CY cyValue,  DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED) throw();
```

#### <a name="parameters"></a>parâmetros

*dwPropertyID*<br/>
no A ID da propriedade a ser adicionada. Usado para inicializar a `dwPropertyID` da estrutura de `DBPROP` adicionada ao conjunto de propriedades.

*var*<br/>
no Uma variante usada para inicializar o valor da propriedade para a estrutura de `DBPROP` adicionada ao conjunto de propriedades.

*szValue*<br/>
no Uma cadeia de caracteres usada para inicializar o valor da propriedade para a estrutura de `DBPROP` adicionada ao conjunto de propriedades.

*bValue*<br/>
no Um valor `BYTE` ou booliano usado para inicializar o valor da propriedade para a estrutura de `DBPROP` adicionada ao conjunto de propriedades.

*nvalor*<br/>
no Um valor inteiro usado para inicializar o valor da propriedade para a estrutura de `DBPROP` adicionada ao conjunto de propriedades.

*fltValue*<br/>
no Um valor de ponto flutuante usado para inicializar o valor da propriedade para a estrutura de `DBPROP` adicionada ao conjunto de propriedades.

*dblValue*<br/>
no Um valor de ponto flutuante de precisão dupla usado para inicializar o valor da propriedade para a estrutura de `DBPROP` adicionada ao conjunto de propriedades.

*cyValue*<br/>
no Um valor de moeda CY usado para inicializar o valor da propriedade para a estrutura de `DBPROP` adicionada ao conjunto de propriedades.

### <a name="return-value"></a>Valor retornado

**true** se a propriedade tiver sido adicionada com êxito. Caso contrário, **false**.

## <a name="cdbpropsetcdbpropset"></a><a name="cdbpropset"></a>CDBPropSet::CDBPropSet

O construtor. Inicializa os campos `rgProperties`, `cProperties`e `guidPropertySet` da estrutura [DBPROPSET](/previous-versions/windows/desktop/ms714367(v=vs.85)) .

### <a name="syntax"></a>Sintaxe

```cpp
CDBPropSet(const GUID& guid);

CDBPropSet(const CDBPropSet& propset);

CDBPropSet();
```

#### <a name="parameters"></a>parâmetros

*guid*<br/>
no Um GUID usado para inicializar o campo de `guidPropertySet`.

*propset*<br/>
no Outro objeto `CDBPropSet` para a construção da cópia.

## <a name="cdbpropsetsetguid"></a><a name="setguid"></a>CDBPropSet:: SetGUID

Define o campo `guidPropertySet` na estrutura de `DBPROPSET`.

### <a name="syntax"></a>Sintaxe

```cpp
void SetGUID(const GUID& guid) throw();
```

#### <a name="parameters"></a>parâmetros

*guid*<br/>
no Um GUID usado para definir o campo de `guidPropertySet` da estrutura [DBPROPSET](/previous-versions/windows/desktop/ms714367(v=vs.85)) .

### <a name="remarks"></a>Comentários

Esse campo também pode ser definido pelo [Construtor](../../data/oledb/cdbpropset-cdbpropset.md) .

## <a name="cdbpropsetoperator-"></a><a name="op_equal"></a>CDBPropSet:: Operator =

Atribui o conteúdo de um conjunto de propriedades a outro conjunto de propriedades.

### <a name="syntax"></a>Sintaxe

```cpp
CDBPropSet& operator =(CDBPropSet& propset) throw();
```

## <a name="see-also"></a>Confira também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)<br/>
[Classe CDBPropIDSet](../../data/oledb/cdbpropidset-class.md)<br/>
Estrutura de [DBPROPSET](/previous-versions/windows/desktop/ms714367(v=vs.85))
estrutura [DBPROP](/previous-versions/windows/desktop/ms717970(v=vs.85))
