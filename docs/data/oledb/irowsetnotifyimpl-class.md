---
title: Classe IRowsetNotifyImpl
ms.date: 11/04/2016
f1_keywords:
- ATL.IRowsetNotifyImpl
- ATL::IRowsetNotifyImpl
- IRowsetNotifyImpl
- IRowsetNotifyImpl.OnFieldChange
- IRowsetNotifyImpl::OnFieldChange
- OnFieldChange
- IRowsetNotifyImpl::OnRowChange
- IRowsetNotifyImpl.OnRowChange
- OnRowChange
- OnRowsetChange
- IRowsetNotifyImpl::OnRowsetChange
- IRowsetNotifyImpl.OnRowsetChange
helpviewer_keywords:
- IRowsetNotifyImpl class
- OnFieldChange method
- OnRowChange method
- OnRowsetChange method
ms.assetid: fbfd0cb2-38ff-4b42-899a-8de902f834b8
ms.openlocfilehash: 4e6b4c3298c063038e7365496f26f50d3789be86
ms.sourcegitcommit: 0e3da5cea44437c132b5c2ea522bd229ea000a10
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/12/2019
ms.locfileid: "70311652"
---
# <a name="irowsetnotifyimpl-class"></a>Classe IRowsetNotifyImpl

Implementa e registra [IRowsetNotify](/previous-versions/windows/desktop/ms712959(v=vs.85)) no consumidor (também conhecido como "Sink") para que ele possa manipular notificações.

## <a name="syntax"></a>Sintaxe

```cpp
class ATL_NO_VTABLE IRowsetNotifyImpl : public IRowsetNotify
```

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** atldbcli. h

## <a name="members"></a>Membros

### <a name="methods"></a>{1&gt;Métodos&lt;1}

|||
|-|-|
|[OnFieldChange](#onfieldchange)|Notifica o consumidor sobre qualquer alteração no valor de uma coluna.|
|[OnRowChange](#onrowchange)|Notifica o consumidor sobre a primeira alteração em uma linha ou sobre qualquer alteração que afete toda a linha.|
|[OnRowsetChange](#onrowsetchange)|Notifica o consumidor sobre qualquer alteração que afete todo o conjunto de linhas.|

## <a name="remarks"></a>Comentários

Consulte [recebendo notificações](../../data/oledb/receiving-notifications.md) sobre a implementação da interface de ponto de conexão no consumidor.

`IRowsetNotifyImpl` fornece uma implementação fictícia para `IRowsetNotify`, com funções vazias para os métodos de `IRowsetNotify` [OnFieldChange](/previous-versions/windows/desktop/ms715961(v=vs.85)), [OnRowChange](/previous-versions/windows/desktop/ms722694(v=vs.85))e [OnRowsetChange](/previous-versions/windows/desktop/ms722669(v=vs.85)). Se você herdar dessa classe ao implementar uma interface `IRowsetNotify`, poderá implementar apenas os métodos necessários. Você também precisa fornecer implementações vazias para os outros métodos por conta própria.

## <a name="onfieldchange"></a>IRowsetNotifyImpl::OnFieldChange

Notifica o consumidor sobre qualquer alteração no valor de uma coluna.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(OnFieldChange)(
/* [in] */ IRowset* /* pRowset */,
/* [in] */ HROW /* hRow */,
/* [in] */ DBORDINAL /* cColumns */,
/* [size_is][in] */ DBORDINAL /* rgColumns */ [] ,
/* [in] */ DBREASON /* eReason */,
/* [in] */ DBEVENTPHASE /* ePhase */,
/* [in] */ BOOL /* fCantDeny */)
```

#### <a name="parameters"></a>Parâmetros

Consulte [IRowsetNotify:: OnFieldChange](/previous-versions/windows/desktop/ms715961(v=vs.85)) para obter descrições de parâmetros.

### <a name="return-value"></a>Valor retornado

Consulte [IRowsetNotify:: OnFieldChange](/previous-versions/windows/desktop/ms715961(v=vs.85)) para obter descrições de valor de retorno.

### <a name="remarks"></a>Comentários

Esse método encapsula o método [IRowsetNotify:: OnFieldChange](/previous-versions/windows/desktop/ms715961(v=vs.85)) . Consulte a descrição do método na referência do programador de OLE DB para obter detalhes.

## <a name="onrowchange"></a> IRowsetNotifyImpl::OnRowChange

Notifica o consumidor sobre a primeira alteração em uma linha ou sobre qualquer alteração que afete toda a linha.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(OnRowChange)(
/* [in] */ IRowset* /* pRowset */,
/* [in] */ DBCOUNTITEM /* cRows */,
/* [size_is][in] */ const HROW /* rghRows*/ [] ,
/* [in] */ DBREASON /* eReason */,
/* [in] */ DBEVENTPHASE /* ePhase */,
/* [in] */ BOOL /* fCantDeny */)
```

#### <a name="parameters"></a>Parâmetros

Consulte [IRowsetNotify:: OnRowChange](/previous-versions/windows/desktop/ms722694(v=vs.85)) para obter descrições de parâmetros.

### <a name="return-value"></a>Valor retornado

Consulte [IRowsetNotify:: OnRowChange](/previous-versions/windows/desktop/ms722694(v=vs.85)) para obter descrições de valor de retorno.

### <a name="remarks"></a>Comentários

Esse método encapsula o método [IRowsetNotify:: OnRowChange](/previous-versions/windows/desktop/ms722694(v=vs.85)) . Consulte a descrição do método na referência do programador de OLE DB para obter detalhes.

## <a name="onrowsetchange"></a> IRowsetNotifyImpl::OnRowsetChange

Notifica o consumidor sobre qualquer alteração que afete todo o conjunto de linhas.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(OnRowsetChange)(
/* [in] */ IRowset* /* pRowset */,
/* [in] */ DBREASON /* eReason */,
/* [in] */ DBEVENTPHASE /* ePhase */,
/* [in] */ BOOL /* fCantDeny */)
```

#### <a name="parameters"></a>Parâmetros

Consulte [IRowsetNotify:: OnRowsetChange](/previous-versions/windows/desktop/ms722669(v=vs.85)) para obter descrições de parâmetros.

### <a name="return-value"></a>Valor retornado

Consulte [IRowsetNotify:: OnRowsetChange](/previous-versions/windows/desktop/ms722669(v=vs.85)) para obter descrições de valor de retorno.

### <a name="remarks"></a>Comentários

Esse método encapsula o método [IRowsetNotify:: OnRowsetChange](/previous-versions/windows/desktop/ms722669(v=vs.85)) . Consulte a descrição do método na referência do programador de OLE DB para obter detalhes.

## <a name="see-also"></a>Consulte também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
Classe [IRowsetNotify](/previous-versions/windows/desktop/ms712959(v=vs.85))
[IRowsetNotifyCP](../../data/oledb/irowsetnotifycp-class.md)
