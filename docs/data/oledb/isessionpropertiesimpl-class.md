---
title: Classe ISessionPropertiesImpl
ms.date: 11/04/2016
f1_keywords:
- ISessionPropertiesImpl
- ISessionPropertiesImpl::GetProperties
- ISessionPropertiesImpl.GetProperties
- GetProperties
- ISessionPropertiesImpl.SetProperties
- SetProperties
- ISessionPropertiesImpl::SetProperties
helpviewer_keywords:
- ISessionPropertiesImpl class
- GetProperties method
- SetProperties method
ms.assetid: ca0ba254-c7dc-4c52-abec-cf895a0c6a63
ms.openlocfilehash: 7b9f402d9b1c45c2fa10c1128afd271229036f88
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57420772"
---
# <a name="isessionpropertiesimpl-class"></a>Classe ISessionPropertiesImpl

Fornece uma implementação de [ISessionProperties](/previous-versions/windows/desktop/ms713721(v=vs.85)) interface.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T, class PropClass = T>
class ATL_NO_VTABLE ISessionPropertiesImpl :
   public ISessionProperties, 
   public CUtlProps<PropClass>
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `ISessionPropertiesImpl`.

*PropClass*<br/>
Uma classe de propriedade definidos pelo usuário que assume como padrão *T*.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldb.h

## <a name="members"></a>Membros

### <a name="interface-methods"></a>Métodos de interface

|||
|-|-|
|[GetProperties](#getproperties)|Retorna a lista de propriedades no grupo de propriedades de sessão são definidas no momento na sessão.|
|[SetProperties](#setproperties)|Define propriedades no grupo de propriedades de sessão.|

## <a name="remarks"></a>Comentários

Uma interface obrigatória em sessões. Essa classe implementa propriedades da sessão, chamando uma função estática definida pelos [mapa de conjunto de propriedade](../../data/oledb/begin-propset-map.md). O mapa do conjunto de propriedade deve ser especificado em sua classe de sessão.

## <a name="getproperties"></a> ISessionPropertiesImpl::GetProperties

Retorna a lista de propriedades no `DBPROPSET_SESSION` grupo de propriedades que são definidas no momento na sessão.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(GetProperties)(ULONG cPropertyIDSets,
   const DBPROPIDSET rgPropertyIDSets[],
   ULONG * pcPropertySets,
   DBPROPSET ** prgPropertySets);
```

#### <a name="parameters"></a>Parâmetros

Ver [ISessionProperties::GetProperties](/previous-versions/windows/desktop/ms723643(v=vs.85)) na *referência do programador do OLE DB*.

## <a name="setproperties"></a> ISessionPropertiesImpl::SetProperties

Define as propriedades no `DBPROPSET_SESSION` grupo de propriedades.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(SetProperties)(ULONG cPropertySets,
   DBPROPSET rgPropertySets[]);
```

#### <a name="parameters"></a>Parâmetros

Ver [ISessionProperties::SetProperties](/previous-versions/windows/desktop/ms714405(v=vs.85)) na *referência do programador do OLE DB*.

## <a name="see-also"></a>Consulte também

[Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)