---
title: Classe IRowsetNotifyCP
ms.date: 11/04/2016
f1_keywords:
- IRowsetNotifyCP
- Fire_OnFieldChange
- ATL::IRowsetNotifyCP::Fire_OnFieldChange
- ATL.IRowsetNotifyCP.Fire_OnFieldChange
- IRowsetNotifyCP.Fire_OnFieldChange
- IRowsetNotifyCP::Fire_OnFieldChange
- IRowsetNotifyCP.Fire_OnRowChange
- ATL.IRowsetNotifyCP.Fire_OnRowChange
- Fire_OnRowChange
- ATL::IRowsetNotifyCP::Fire_OnRowChange
- IRowsetNotifyCP::Fire_OnRowChange
- Fire_OnRowsetChange
- IRowsetNotifyCP::Fire_OnRowsetChange
- IRowsetNotifyCP.Fire_OnRowsetChange
- ATL::IRowsetNotifyCP::Fire_OnRowsetChange
- ATL.IRowsetNotifyCP.Fire_OnRowsetChange
helpviewer_keywords:
- IRowsetNotifyCP class
- Fire_OnFieldChange method
- Fire_OnRowChange method
- Fire_OnRowsetChange method
ms.assetid: ccef402b-94a0-4c2e-9a13-7e854ef82390
ms.openlocfilehash: a3ab63206ce7ac53ff996ecf1bb64bdaa0b79fcb
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59031680"
---
# <a name="irowsetnotifycp-class"></a>Classe IRowsetNotifyCP

Implementa o site do provedor para a interface de ponto de conexão [IRowsetNotify](/previous-versions/windows/desktop/ms712959(v=vs.85)).

## <a name="syntax"></a>Sintaxe

```cpp
template <class T, class ReentrantEventSync = CComSharedMutex>
class IRowsetNotifyCP :
   public IConnectionPointImpl<
      T,
      piid = &__uuidof(IRowsetNotify),
      CComDynamicUnkArray DynamicUnkArray>,
   public ReentrantEventSync
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Uma classe derivada de `IRowsetNotifyCP`.

*ReentrantEventSync*<br/>
Uma classe mutex que dá suporte a reentrância (o padrão é `CComSharedMutex`). Um mutex é um objeto de sincronização que permite um acesso mutuamente exclusivo de thread a um recurso.

*piid*<br/>
Um ponteiro de ID de interface (`IID*`) para um `IRowsetNotify` interface de ponto de conexão. O valor padrão é `&__uuidof(IRowsetNotify)`.

*DynamicUnkArray*<br/>
Uma matriz do tipo [CComDynamicUnkArray](../../atl/reference/ccomdynamicunkarray-class.md), que é uma matriz alocada dinamicamente do `IUnknown` interfaces de coletor de ponteiros para o cliente.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldb.h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[Fire_OnFieldChange](#onfieldchange)|Notifica o consumidor de uma alteração no valor de uma coluna.|
|[Fire_OnRowChange](#onrowchange)|Notifica o consumidor de uma alteração que afete as linhas.|
|[Fire_OnRowsetChange](#onrowsetchange)|Notifica o consumidor de uma alteração que afete todo o conjunto de linhas.|

## <a name="remarks"></a>Comentários

`IRowsetNotifyCP` implementa funções para informar ouvintes no ponto de conexão de difusão `IID_IRowsetNotify` de alterações no conteúdo do conjunto de linhas.

Observe que você também deve implementar e registrar `IRowsetNotify` consumidor (também conhecido como o "coletor") usando [IRowsetNotifyImpl](../../data/oledb/irowsetnotifyimpl-class.md) para que o consumidor pode lidar com notificações. Ver [recebendo notificações](../../data/oledb/receiving-notifications.md) sobre como implementar a interface de ponto de conexão no consumidor.

Para obter informações detalhadas sobre como implementar notificações, consulte "Suporte a notificações" no [criando um provedor atualizável](../../data/oledb/creating-an-updatable-provider.md).

## <a name="onfieldchange"></a> IRowsetNotifyCP::Fire_OnFieldChange

Transmite uma [OnFieldChange](/previous-versions/windows/desktop/ms715961(v=vs.85)) eventos para notificar os consumidores de uma alteração no valor de uma coluna.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT Fire_OnFieldChange(IRowset* pRowset,
   HROW hRow,
   DBORDINAL cColumns,
   DBORDINAL* rgColumns,
   DBREASON eReason,
   DBEVENTPHASE ePhase,
   BOOL fCantDeny);
```

#### <a name="parameters"></a>Parâmetros

Ver [IRowsetNotify::OnFieldChange](/previous-versions/windows/desktop/ms715961(v=vs.85)) na *referência do programador do OLE DB*.

## <a name="onrowchange"></a> IRowsetNotifyCP::Fire_OnRowChange

Transmite uma [OnRowChange](/previous-versions/windows/desktop/ms722694(v=vs.85)) evento para todos os ouvintes no ponto de conexão `IID_IRowsetNotify` para notificar os consumidores de uma alteração que afete as linhas.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT Fire_OnRowChange(IRowset* pRowset,
   DBCOUNTITEM cRows,
   const HROW rghRows[],
   DBREASON eReason,
   DBEVENTPHASE ePhase,
   BOOL fCantDeny);
```

#### <a name="parameters"></a>Parâmetros

Ver [IRowsetNotify::OnRowChange](/previous-versions/windows/desktop/ms722694(v=vs.85)) na *referência do programador do OLE DB*.

## <a name="onrowsetchange"></a> IRowsetNotifyCP::Fire_OnRowsetChange

Transmite uma [OnRowsetChange](/previous-versions/windows/desktop/ms722669(v=vs.85)) evento para todos os ouvintes no ponto de conexão `IID_IRowsetNotify` para notificar os consumidores de uma alteração que afete todo o conjunto de linhas.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT Fire_OnRowsetChange(IRowset* pRowset,
   DBREASON eReason,
   DBEVENTPHASE ePhase,
   BOOL fCantDeny);
```

#### <a name="parameters"></a>Parâmetros

Ver [IRowsetNotify::OnRowsetChange](/previous-versions/windows/desktop/ms722669(v=vs.85)) na *referência do programador do OLE DB*.

## <a name="see-also"></a>Consulte também

[Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)<br/>
[Notificações (COM)](/windows/desktop/com/notifications)<br/>
[BEGIN_CONNECTION_POINT_MAP](../../atl/reference/connection-point-macros.md#begin_connection_point_map)<br/>
[END_CONNECTION_POINT_MAP](../../atl/reference/connection-point-macros.md#end_connection_point_map)<br/>
[CONNECTION_POINT_ENTRY](../../atl/reference/connection-point-macros.md#connection_point_entry)<br/>
[Criando um provedor atualizável](../../data/oledb/creating-an-updatable-provider.md)