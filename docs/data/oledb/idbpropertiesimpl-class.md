---
title: Classe IDBPropertiesImpl
ms.date: 11/04/2016
f1_keywords:
- IDBPropertiesImpl
- ATL.IDBPropertiesImpl
- ATL.IDBPropertiesImpl<T>
- ATL::IDBPropertiesImpl<T>
- ATL::IDBPropertiesImpl
- IDBPropertiesImpl::GetProperties
- IDBPropertiesImpl.GetProperties
- IDBPropertiesImpl::GetPropertyInfo
- IDBPropertiesImpl.GetPropertyInfo
- GetPropertyInfo
- IDBPropertiesImpl.SetProperties
- IDBPropertiesImpl::SetProperties
helpviewer_keywords:
- IDBPropertiesImpl class
- GetProperties method
- GetPropertyInfo method
- SetProperties method
ms.assetid: a7f15a8b-95b2-4316-b944-d5d03f8d74ab
ms.openlocfilehash: 77f70c8b0bc602da6840bec38565c4441644c6d0
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79443714"
---
# <a name="idbpropertiesimpl-class"></a>Classe IDBPropertiesImpl

Fornece uma implementação para a interface `IDBProperties`.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
class ATL_NO_VTABLE IDBPropertiesImpl
   : public IDBProperties, public CUtlProps<T>
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IDBPropertiesImpl`.

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** Atldb. h

## <a name="members"></a>Membros

### <a name="interface-methods"></a>Métodos de interface

|||
|-|-|
|[GetProperties](#getproperties)|Retorna os valores das propriedades na fonte de dados, informações da fonte de dados e grupos de propriedades de inicialização que estão atualmente definidos no objeto de fonte de dados ou os valores das propriedades no grupo de propriedades de inicialização que estão atualmente definidas no enumera.|
|[GetPropertyInfo](#getpropertyinfo)|Retorna informações sobre todas as propriedades com suporte no provedor.|
|[SetProperties](#setproperties)|Define propriedades nos grupos de propriedades de fonte de dados e de inicialização, para objetos de fonte de dados ou para o grupo de propriedades de inicialização, para enumeradores.|

## <a name="remarks"></a>Comentários

[IDBProperties](/previous-versions/windows/desktop/ms719607(v=vs.85)) é uma interface obrigatória para objetos de fonte de dados e uma interface opcional para enumeradores. No entanto, se um enumerador expõe [IDBInitialize](/previous-versions/windows/desktop/ms713706(v=vs.85)), ele deve expor `IDBProperties`. `IDBPropertiesImpl` implementa `IDBProperties` usando uma função estática definida por [BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md).

## <a name="getproperties"></a>IDBPropertiesImpl:: GetProperties

Retorna os valores das propriedades na fonte de dados, informações da fonte de dados e grupos de propriedades de inicialização que estão atualmente definidos no objeto de fonte de dados ou os valores das propriedades no grupo de propriedades de inicialização que estão atualmente definidas no enumera.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(GetProperties)(ULONG cPropertySets,
   const DBPROPIDSET rgPropertySets[],
   ULONG * pcProperties,
   DBPROPSET ** prgProperties);
```

#### <a name="parameters"></a>Parâmetros

Consulte [IDBProperties:: GetProperties](/previous-versions/windows/desktop/ms714344(v=vs.85)) na *referência do programador de OLE DB*.

Alguns parâmetros correspondem a parâmetros de *referência do programador OLE DB* de nomes diferentes, que são descritos em `IDBProperties::GetProperties`:

|OLE DB parâmetros de modelo|Parâmetros *de referência do programador de OLE DB*|
|--------------------------------|------------------------------------------------|
|*cPropertySets*|*cPropertyIDSets*|
|*rgPropertySets*|*rgPropertyIDSets*|
|*pcProperties*|*pcPropertySets*|
|*prgProperties*|*prgPropertySets*|

### <a name="remarks"></a>Comentários

Se o provedor for inicializado, esse método retornará os valores das propriedades no DBPROPSET_DATASOURCE, DBPROPSET_DATASOURCEINFO DBPROPSET_DBINIT grupos de propriedades que estão atualmente definidos no objeto de fonte de dados. Se o provedor não for inicializado, ele retornará apenas DBPROPSET_DBINIT Propriedades do grupo.

## <a name="getpropertyinfo"></a>IDBPropertiesImpl:: GetPropertyInfo

Retorna informações de propriedade com suporte da fonte de dados.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(GetPropertyInfo)(ULONG cPropertySets,
   const DBPROPIDSET rgPropertySets[],
   ULONG * pcPropertyInfoSets,
   DBPROPINFOSET ** prgPropertyInfoSets,
   OLECHAR ** ppDescBuffer);
```

#### <a name="parameters"></a>Parâmetros

Consulte [IDBProperties:: GetPropertyInfo](/previous-versions/windows/desktop/ms718175(v=vs.85)) na *referência do programador de OLE DB*.

Alguns parâmetros correspondem a parâmetros de *referência do programador OLE DB* de nomes diferentes, que são descritos em `IDBProperties::GetPropertyInfo`:

|OLE DB parâmetros de modelo|Parâmetros *de referência do programador de OLE DB*|
|--------------------------------|------------------------------------------------|
|*cPropertySets*|*cPropertyIDSets*|
|*rgPropertySets*|*rgPropertyIDSets*|

### <a name="remarks"></a>Comentários

Usa [IDBInitializeImpl:: m_pCUtlPropInfo](../../data/oledb/idbinitializeimpl-m-pcutlpropinfo.md) para implementar essa funcionalidade.

## <a name="setproperties"></a>IDBPropertiesImpl:: SetProperties

Define propriedades nos grupos de propriedades de fonte de dados e de inicialização, para objetos de fonte de dados ou para o grupo de propriedades de inicialização, para enumeradores.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(SetProperties)(ULONG cPropertySets,
   DBPROPSET rgPropertySets[]);
```

#### <a name="parameters"></a>Parâmetros

Consulte [IDBProperties:: SetProperties](/previous-versions/windows/desktop/ms723049(v=vs.85)) na *referência do programador de OLE DB*.

### <a name="remarks"></a>Comentários

Se o provedor for inicializado, esse método definirá os valores das propriedades nos grupos de propriedades DBPROPSET_DATASOURCE, DBPROPSET_DATASOURCEINFO DBPROPSET_DBINIT para o objeto de fonte de dados. Se o provedor não for inicializado, ele só definirá DBPROPSET_DBINIT Propriedades do grupo.

## <a name="see-also"></a>Consulte também

[Modelos de Provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)