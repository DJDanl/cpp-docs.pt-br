---
title: Classe ISessionPropertiesImpl
ms.date: 11/04/2016
f1_keywords:
- ISessionPropertiesImpl
- ISessionPropertiesImpl::GetProperties
- ISessionPropertiesImpl.GetProperties
- ISessionPropertiesImpl.SetProperties
- ISessionPropertiesImpl::SetProperties
helpviewer_keywords:
- ISessionPropertiesImpl class
- GetProperties method
- SetProperties method
ms.assetid: ca0ba254-c7dc-4c52-abec-cf895a0c6a63
ms.openlocfilehash: d664f32226498326ffb092f1d3248fbdbf614d50
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91509766"
---
# <a name="isessionpropertiesimpl-class"></a>Classe ISessionPropertiesImpl

Fornece uma implementação da interface [ISessionProperties](/previous-versions/windows/desktop/ms713721(v=vs.85)) .

## <a name="syntax"></a>Sintaxe

```cpp
template <class T, class PropClass = T>
class ATL_NO_VTABLE ISessionPropertiesImpl :
   public ISessionProperties,
   public CUtlProps<PropClass>
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `ISessionPropertiesImpl` .

*PropClass*<br/>
Uma classe de propriedade definida pelo usuário que assume como padrão *T*.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Atldb. h

## <a name="members"></a>Membros

### <a name="interface-methods"></a>Métodos de interface

| Nome | Descrição |
|-|-|
|[GetProperties](#getproperties)|Retorna a lista de propriedades no grupo de propriedades de sessão que está atualmente definido na sessão.|
|[SetProperties](#setproperties)|Define propriedades no grupo de propriedades de sessão.|

## <a name="remarks"></a>Comentários

Uma interface obrigatória em sessões. Essa classe implementa as propriedades da sessão chamando uma função estática definida pelo [mapa do conjunto de propriedades](./macros-for-ole-db-provider-templates.md#begin_propset_map). O mapa do conjunto de propriedades deve ser especificado na sua classe de sessão.

## <a name="isessionpropertiesimplgetproperties"></a><a name="getproperties"></a> ISessionPropertiesImpl:: GetProperties

Retorna a lista de propriedades no `DBPROPSET_SESSION` grupo de propriedades que estão atualmente definidas na sessão.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(GetProperties)(ULONG cPropertyIDSets,
   const DBPROPIDSET rgPropertyIDSets[],
   ULONG * pcPropertySets,
   DBPROPSET ** prgPropertySets);
```

#### <a name="parameters"></a>Parâmetros

Consulte [ISessionProperties:: GetProperties](/previous-versions/windows/desktop/ms723643(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="isessionpropertiesimplsetproperties"></a><a name="setproperties"></a> ISessionPropertiesImpl:: SetProperties

Define propriedades no `DBPROPSET_SESSION` grupo de propriedades.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(SetProperties)(ULONG cPropertySets,
   DBPROPSET rgPropertySets[]);
```

#### <a name="parameters"></a>Parâmetros

Consulte [ISessionProperties:: SetProperties](/previous-versions/windows/desktop/ms714405(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="see-also"></a>Consulte também

[Modelos de Provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo de provedor de OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)
