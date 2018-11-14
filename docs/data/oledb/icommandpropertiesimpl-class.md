---
title: Classe ICommandPropertiesImpl
ms.date: 11/04/2016
f1_keywords:
- ICommandPropertiesImpl
- ATL.ICommandPropertiesImpl
- ATL::ICommandPropertiesImpl
- ICommandPropertiesImpl::GetProperties
- ICommandPropertiesImpl.GetProperties
- GetProperties
- ICommandPropertiesImpl.SetProperties
- ICommandPropertiesImpl::SetProperties
- SetProperties
helpviewer_keywords:
- ICommandPropertiesImpl class
- GetProperties method
- SetProperties method
ms.assetid: b3cf6aea-527e-4f0d-96e0-669178b021a2
ms.openlocfilehash: c6736eac040b2186ddb1b1dc1c5c3a5b6b957d20
ms.sourcegitcommit: c40469825b6101baac87d43e5f4aed6df6b078f5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2018
ms.locfileid: "51556147"
---
# <a name="icommandpropertiesimpl-class"></a>Classe ICommandPropertiesImpl

Fornece uma implementação de [ICommandProperties](https://docs.microsoft.com/previous-versions/windows/desktop/ms723044(v=vs.85)) interface.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T, class PropClass = T>
class ATL_NO_VTABLE ICommandPropertiesImpl
   : public ICommandProperties, public CUtlProps<PropClass>
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de

*PropClass*<br/>
Sua classe de propriedades.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldb.h

## <a name="members"></a>Membros

### <a name="interface-methods"></a>Métodos de interface

|||
|-|-|
|[GetProperties](#getproperties)|Retorna a lista de propriedades no grupo de propriedades do conjunto de linhas que atualmente são solicitadas para o conjunto de linhas.|
|[SetProperties](#setproperties)|Define propriedades no grupo de propriedades do conjunto de linhas.|

## <a name="remarks"></a>Comentários

Isso é obrigatório em comandos. A implementação é fornecida por uma função estática definida pela [BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md) macro.

## <a name="getproperties"></a> Icommandpropertiesimpl:: GetProperties

Retorna todos os conjuntos de propriedade solicitada usando o mapa de propriedade do comando.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(GetProperties)(const ULONG cPropertyIDSets,
   const DBPROPIDSET rgPropertyIDSets[],
   ULONG * pcPropertySets,
   DBPROPSET ** prgPropertySets);
```

#### <a name="parameters"></a>Parâmetros

Ver [icommandproperties:: GetProperties](https://docs.microsoft.com/previous-versions/windows/desktop/ms723119(v=vs.85)) na *referência do programador do OLE DB*.

### <a name="remarks"></a>Comentários

Ver [BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md).

## <a name="setproperties"></a> Icommandpropertiesimpl:: SetProperties

Define propriedades para o objeto de comando.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(SetProperties)(ULONG cPropertySets,
   DBPROPSET rgPropertySets[]);
```

#### <a name="parameters"></a>Parâmetros

Ver [icommandproperties:: SetProperties](https://docs.microsoft.com/previous-versions/windows/desktop/ms711497(v=vs.85)) na *referência do programador do OLE DB*.

## <a name="see-also"></a>Consulte também

[Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)