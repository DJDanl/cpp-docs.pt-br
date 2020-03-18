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
ms.openlocfilehash: 50052e13371482fa0a8b6d66ef666b9801837501
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79444031"
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
Sua classe, derivada de `ISessionPropertiesImpl`.

*PropClass*<br/>
Uma classe de propriedade definida pelo usuário que assume como padrão *T*.

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** Atldb. h

## <a name="members"></a>Membros

### <a name="interface-methods"></a>Métodos de interface

|||
|-|-|
|[GetProperties](#getproperties)|Retorna a lista de propriedades no grupo de propriedades de sessão que está atualmente definido na sessão.|
|[SetProperties](#setproperties)|Define propriedades no grupo de propriedades de sessão.|

## <a name="remarks"></a>Comentários

Uma interface obrigatória em sessões. Essa classe implementa as propriedades da sessão chamando uma função estática definida pelo [mapa do conjunto de propriedades](../../data/oledb/begin-propset-map.md). O mapa do conjunto de propriedades deve ser especificado na sua classe de sessão.

## <a name="getproperties"></a>ISessionPropertiesImpl:: GetProperties

Retorna a lista de propriedades no grupo de propriedades `DBPROPSET_SESSION` que estão atualmente definidas na sessão.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(GetProperties)(ULONG cPropertyIDSets,
   const DBPROPIDSET rgPropertyIDSets[],
   ULONG * pcPropertySets,
   DBPROPSET ** prgPropertySets);
```

#### <a name="parameters"></a>Parâmetros

Consulte [ISessionProperties:: GetProperties](/previous-versions/windows/desktop/ms723643(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="setproperties"></a>ISessionPropertiesImpl:: SetProperties

Define as propriedades no grupo de propriedades `DBPROPSET_SESSION`.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(SetProperties)(ULONG cPropertySets,
   DBPROPSET rgPropertySets[]);
```

#### <a name="parameters"></a>Parâmetros

Consulte [ISessionProperties:: SetProperties](/previous-versions/windows/desktop/ms714405(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="see-also"></a>Consulte também

[Modelos de Provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)