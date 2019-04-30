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
- GetProperties
- IDBPropertiesImpl::GetPropertyInfo
- IDBPropertiesImpl.GetPropertyInfo
- GetPropertyInfo
- IDBPropertiesImpl.SetProperties
- SetProperties
- IDBPropertiesImpl::SetProperties
helpviewer_keywords:
- IDBPropertiesImpl class
- GetProperties method
- GetPropertyInfo method
- SetProperties method
ms.assetid: a7f15a8b-95b2-4316-b944-d5d03f8d74ab
ms.openlocfilehash: 807cdf55a5a2fa6e0cc063c22b1685d8156c41a5
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62408921"
---
# <a name="idbpropertiesimpl-class"></a>Classe IDBPropertiesImpl

Fornece uma implementação para o `IDBProperties` interface.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
class ATL_NO_VTABLE IDBPropertiesImpl
   : public IDBProperties, public CUtlProps<T>
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IDBPropertiesImpl`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldb.h

## <a name="members"></a>Membros

### <a name="interface-methods"></a>Métodos de interface

|||
|-|-|
|[GetProperties](#getproperties)|Retorna os valores das propriedades dos grupos de propriedade de inicialização, informações de fonte de dados e fonte de dados que estão atualmente definidas no objeto de fonte de dados ou os valores das propriedades no grupo de propriedades de inicialização são definidas no momento no enumerador.|
|[GetPropertyInfo](#getpropertyinfo)|Retorna informações sobre todas as propriedades com suporte pelo provedor.|
|[SetProperties](#setproperties)|Define propriedades em grupos de propriedades fonte de dados e de inicialização, para objetos de fonte de dados, ou o grupo de propriedades de inicialização para enumeradores.|

## <a name="remarks"></a>Comentários

[IDBProperties](/previous-versions/windows/desktop/ms719607(v=vs.85)) é uma interface obrigatória para objetos de fonte de dados e uma interface opcional para enumeradores. No entanto, se expõe um enumerador [IDBInitialize](/previous-versions/windows/desktop/ms713706(v=vs.85)), ele deve expor `IDBProperties`. `IDBPropertiesImpl` implementa `IDBProperties` usando uma função estática definida por [BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md).

## <a name="getproperties"></a> IDBPropertiesImpl::GetProperties

Retorna os valores das propriedades dos grupos de propriedade de inicialização, informações de fonte de dados e fonte de dados que estão atualmente definidas no objeto de fonte de dados ou os valores das propriedades no grupo de propriedades de inicialização são definidas no momento no enumerador.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(GetProperties)(ULONG cPropertySets,
   const DBPROPIDSET rgPropertySets[],
   ULONG * pcProperties,
   DBPROPSET ** prgProperties);
```

#### <a name="parameters"></a>Parâmetros

Ver [idbproperties:: GetProperties](/previous-versions/windows/desktop/ms714344(v=vs.85)) na *referência do programador do OLE DB*.

Alguns parâmetros correspondem aos *referência do programador DB OLE* parâmetros de nomes diferentes, que são descritos em `IDBProperties::GetProperties`:

|Parâmetros de modelo de banco de dados OLE|*Referência do OLE DB Programmer* parâmetros|
|--------------------------------|------------------------------------------------|
|*cPropertySets*|*cPropertyIDSets*|
|*rgPropertySets*|*rgPropertyIDSets*|
|*pcProperties*|*pcPropertySets*|
|*prgProperties*|*prgPropertySets*|

### <a name="remarks"></a>Comentários

Se o provedor é inicializado, esse método retorna os valores das propriedades em DBPROPSET_DATASOURCE, DBPROPSET_DATASOURCEINFO, grupos de propriedades DBPROPSET_DBINIT definidas atualmente no objeto de fonte de dados. Se o provedor não é inicializado, ele retorna somente propriedades de grupo DBPROPSET_DBINIT.

## <a name="getpropertyinfo"></a> IDBPropertiesImpl::GetPropertyInfo

Retorna informações de propriedade com suporte pela fonte de dados.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(GetPropertyInfo)(ULONG cPropertySets,
   const DBPROPIDSET rgPropertySets[],
   ULONG * pcPropertyInfoSets,
   DBPROPINFOSET ** prgPropertyInfoSets,
   OLECHAR ** ppDescBuffer);
```

#### <a name="parameters"></a>Parâmetros

Ver [idbproperties:: Getpropertyinfo](/previous-versions/windows/desktop/ms718175(v=vs.85)) na *referência do programador do OLE DB*.

Alguns parâmetros correspondem aos *referência do programador DB OLE* parâmetros de nomes diferentes, que são descritos em `IDBProperties::GetPropertyInfo`:

|Parâmetros de modelo de banco de dados OLE|*Referência do OLE DB Programmer* parâmetros|
|--------------------------------|------------------------------------------------|
|*cPropertySets*|*cPropertyIDSets*|
|*rgPropertySets*|*rgPropertyIDSets*|

### <a name="remarks"></a>Comentários

Usa [idbinitializeimpl:: M_pcutlpropinfo](../../data/oledb/idbinitializeimpl-m-pcutlpropinfo.md) para implementar essa funcionalidade.

## <a name="setproperties"></a> IDBPropertiesImpl::SetProperties

Define propriedades em grupos de propriedades fonte de dados e de inicialização, para objetos de fonte de dados, ou o grupo de propriedades de inicialização para enumeradores.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(SetProperties)(ULONG cPropertySets,
   DBPROPSET rgPropertySets[]);
```

#### <a name="parameters"></a>Parâmetros

Ver [idbproperties:: SetProperties](/previous-versions/windows/desktop/ms723049(v=vs.85)) na *referência do programador do OLE DB*.

### <a name="remarks"></a>Comentários

Se o provedor é inicializado, esse método define os valores das propriedades de DBPROPSET_DATASOURCE, DBPROPSET_DATASOURCEINFO, grupos de propriedades DBPROPSET_DBINIT para o objeto de fonte de dados. Se o provedor não é inicializado, ele define somente propriedades de grupo DBPROPSET_DBINIT.

## <a name="see-also"></a>Consulte também

[Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)