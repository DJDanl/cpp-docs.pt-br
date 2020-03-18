---
title: Classe ICommandPropertiesImpl
ms.date: 11/04/2016
f1_keywords:
- ICommandPropertiesImpl
- ATL.ICommandPropertiesImpl
- ATL::ICommandPropertiesImpl
- ICommandPropertiesImpl::GetProperties
- ICommandPropertiesImpl.GetProperties
- ICommandPropertiesImpl.SetProperties
- ICommandPropertiesImpl::SetProperties
helpviewer_keywords:
- ICommandPropertiesImpl class
- GetProperties method
- SetProperties method
ms.assetid: b3cf6aea-527e-4f0d-96e0-669178b021a2
ms.openlocfilehash: 165f7124657cbaf0c0f94171eaf9394011796aea
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79447050"
---
# <a name="icommandpropertiesimpl-class"></a>Classe ICommandPropertiesImpl

Fornece uma implementação da interface [ICommandProperties](/previous-versions/windows/desktop/ms723044(v=vs.85)) .

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
Sua classe Properties.

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** Atldb. h

## <a name="members"></a>Membros

### <a name="interface-methods"></a>Métodos de interface

|||
|-|-|
|[GetProperties](#getproperties)|Retorna a lista de propriedades no grupo de propriedades de conjunto de linhas que são solicitadas no momento para o conjunto de linhas.|
|[SetProperties](#setproperties)|Define propriedades no grupo de propriedades Rowset.|

## <a name="remarks"></a>Comentários

Isso é obrigatório em comandos. A implementação é fornecida por uma função estática definida pela macro [BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md) .

## <a name="getproperties"></a>ICommandPropertiesImpl:: GetProperties

Retorna todos os conjuntos de propriedades solicitados usando o mapa de propriedades do comando.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(GetProperties)(const ULONG cPropertyIDSets,
   const DBPROPIDSET rgPropertyIDSets[],
   ULONG * pcPropertySets,
   DBPROPSET ** prgPropertySets);
```

#### <a name="parameters"></a>Parâmetros

Consulte [ICommandProperties:: GetProperties](/previous-versions/windows/desktop/ms723119(v=vs.85)) na *referência do programador de OLE DB*.

### <a name="remarks"></a>Comentários

Consulte [BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md).

## <a name="setproperties"></a>ICommandPropertiesImpl:: SetProperties

Define propriedades para o objeto de comando.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(SetProperties)(ULONG cPropertySets,
   DBPROPSET rgPropertySets[]);
```

#### <a name="parameters"></a>Parâmetros

Consulte [ICommandProperties:: SetProperties](/previous-versions/windows/desktop/ms711497(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="see-also"></a>Consulte também

[Modelos de Provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)