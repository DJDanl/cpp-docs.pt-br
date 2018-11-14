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
ms.openlocfilehash: 01bcc60b0c88a3953d5e75b53ac58877f7eb15df
ms.sourcegitcommit: c40469825b6101baac87d43e5f4aed6df6b078f5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2018
ms.locfileid: "51556381"
---
# <a name="irowsetnotifyimpl-class"></a>Classe IRowsetNotifyImpl

Implementa e registra [IRowsetNotify](https://docs.microsoft.com/previous-versions/windows/desktop/ms712959(v=vs.85)) no consumidor (também conhecido como o "coletor") para que ele pode manipular notificações.

## <a name="syntax"></a>Sintaxe

```cpp
class ATL_NO_VTABLE IRowsetNotifyImpl : public IRowsetNotify
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli.h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[OnFieldChange](#onfieldchange)|Notifica o consumidor sobre qualquer alteração no valor de uma coluna.|
|[OnRowChange](#onrowchange)|Notifica o consumidor sobre a primeira alteração em uma linha ou sobre qualquer alteração que afete toda a linha.|
|[OnRowsetChange](#onrowsetchange)|Notifica o consumidor sobre qualquer alteração que afete todo o conjunto de linhas.|

## <a name="remarks"></a>Comentários

Ver [recebendo notificações](../../data/oledb/receiving-notifications.md) sobre como implementar a interface de ponto de conexão no consumidor.

`IRowsetNotifyImpl` Fornece uma implementação fictícia para `IRowsetNotify`, com funções vazias para o `IRowsetNotify` métodos [OnFieldChange](https://docs.microsoft.com/previous-versions/windows/desktop/ms715961(v=vs.85)), [OnRowChange](https://docs.microsoft.com/previous-versions/windows/desktop/ms722694(v=vs.85)), e [OnRowsetChange](https://docs.microsoft.com/previous-versions/windows/desktop/ms722669(v=vs.85)). Se você herdar desta classe quando você implementa um `IRowsetNotify` interface, você pode implementar métodos necessários. Você também precisará fornecer implementações vazias para os outros métodos por conta própria.

## <a name="onfieldchange"></a> Irowsetnotifyimpl:: Onfieldchange

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

Ver [IRowsetNotify::OnFieldChange](https://docs.microsoft.com/previous-versions/windows/desktop/ms715961(v=vs.85)) para descrições de parâmetro.

### <a name="return-value"></a>Valor de retorno

Ver [IRowsetNotify::OnFieldChange](https://docs.microsoft.com/previous-versions/windows/desktop/ms715961(v=vs.85)) para descrições de valor de retorno.

### <a name="remarks"></a>Comentários

Este método encapsula o [IRowsetNotify::OnFieldChange](https://docs.microsoft.com/previous-versions/windows/desktop/ms715961(v=vs.85)) método. Consulte a descrição desse método na referência do OLE DB do programador para obter detalhes.

## <a name="onrowchange"></a> Irowsetnotifyimpl:: Onrowchange

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

Ver [IRowsetNotify::OnRowChange](https://docs.microsoft.com/previous-versions/windows/desktop/ms722694(v=vs.85)) para descrições de parâmetro.

### <a name="return-value"></a>Valor de retorno

Ver [IRowsetNotify::OnRowChange](https://docs.microsoft.com/previous-versions/windows/desktop/ms722694(v=vs.85)) para descrições de valor de retorno.

### <a name="remarks"></a>Comentários

Este método encapsula o [IRowsetNotify::OnRowChange](https://docs.microsoft.com/previous-versions/windows/desktop/ms722694(v=vs.85)) método. Consulte a descrição desse método na referência do OLE DB do programador para obter detalhes.

## <a name="onrowsetchange"></a> Irowsetnotifyimpl:: Onrowsetchange

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

Ver [IRowsetNotify::OnRowsetChange](https://docs.microsoft.com/previous-versions/windows/desktop/ms722669(v=vs.85)) para descrições de parâmetro.

### <a name="return-value"></a>Valor de retorno

Ver [IRowsetNotify::OnRowsetChange](https://docs.microsoft.com/previous-versions/windows/desktop/ms722669(v=vs.85)) para descrições de valor de retorno.

### <a name="remarks"></a>Comentários

Este método encapsula o [IRowsetNotify::OnRowsetChange](https://docs.microsoft.com/previous-versions/windows/desktop/ms722669(v=vs.85)) método. Consulte a descrição desse método na referência do OLE DB do programador para obter detalhes.

## <a name="see-also"></a>Consulte também

[Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[IRowsetNotify](https://docs.microsoft.com/previous-versions/windows/desktop/ms712959(v=vs.85))
[classe IRowsetNotifyCP](../../data/oledb/irowsetnotifycp-class.md)