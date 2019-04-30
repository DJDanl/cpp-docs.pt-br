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
ms.openlocfilehash: ed8b7a271bc6ac234fc9276d6c88d26848da24f8
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62390679"
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