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
ms.openlocfilehash: fa85bc7947b3b446ec7c6d3fdb0d7b62d308fb53
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80210321"
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

### <a name="parameters"></a>parâmetros

*T*<br/>
Uma classe derivada de `IRowsetNotifyCP`.

*ReentrantEventSync*<br/>
Uma classe mutex que dá suporte à reentrância (o padrão é `CComSharedMutex`). Um mutex é um objeto de sincronização que permite que um thread tenha acesso mutuamente exclusivo a um recurso.

*piid*<br/>
Um ponteiro de ID de interface (`IID*`) para uma interface de ponto de conexão `IRowsetNotify`. O valor padrão é `&__uuidof(IRowsetNotify)`.

*DynamicUnkArray*<br/>
Uma matriz do tipo [CComDynamicUnkArray](../../atl/reference/ccomdynamicunkarray-class.md), que é uma matriz alocada dinamicamente de ponteiros de `IUnknown` para as interfaces de coletor de cliente.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Atldb. h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[Fire_OnFieldChange](#onfieldchange)|Notifica o consumidor sobre uma alteração no valor de uma coluna.|
|[Fire_OnRowChange](#onrowchange)|Notifica o consumidor sobre uma alteração que afeta as linhas.|
|[Fire_OnRowsetChange](#onrowsetchange)|Notifica o consumidor sobre uma alteração que afeta todo o conjunto de linhas.|

## <a name="remarks"></a>Comentários

`IRowsetNotifyCP` implementa funções de difusão para avisar os ouvintes no ponto de conexão `IID_IRowsetNotify` de alterações ao conteúdo do conjunto de linhas.

Observe que você também deve implementar e registrar `IRowsetNotify` no consumidor (também conhecido como "coletor") usando [IRowsetNotifyImpl](../../data/oledb/irowsetnotifyimpl-class.md) para que o consumidor possa lidar com notificações. Consulte [recebendo notificações](../../data/oledb/receiving-notifications.md) sobre a implementação da interface de ponto de conexão no consumidor.

Para obter informações detalhadas sobre como implementar notificações, consulte "notificações de suporte" em [criando um provedor atualizável](../../data/oledb/creating-an-updatable-provider.md).

## <a name="irowsetnotifycpfire_onfieldchange"></a><a name="onfieldchange"></a>IRowsetNotifyCP:: Fire_OnFieldChange

Transmite um evento [OnFieldChange](/previous-versions/windows/desktop/ms715961(v=vs.85)) para notificar os consumidores sobre uma alteração no valor de uma coluna.

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

#### <a name="parameters"></a>parâmetros

Consulte [IRowsetNotify:: OnFieldChange](/previous-versions/windows/desktop/ms715961(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="irowsetnotifycpfire_onrowchange"></a><a name="onrowchange"></a>IRowsetNotifyCP:: Fire_OnRowChange

Transmite um evento [OnRowChange](/previous-versions/windows/desktop/ms722694(v=vs.85)) para todos os ouvintes no ponto de conexão `IID_IRowsetNotify` para notificar os consumidores de uma alteração que afete as linhas.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT Fire_OnRowChange(IRowset* pRowset,
   DBCOUNTITEM cRows,
   const HROW rghRows[],
   DBREASON eReason,
   DBEVENTPHASE ePhase,
   BOOL fCantDeny);
```

#### <a name="parameters"></a>parâmetros

Consulte [IRowsetNotify:: OnRowChange](/previous-versions/windows/desktop/ms722694(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="irowsetnotifycpfire_onrowsetchange"></a><a name="onrowsetchange"></a>IRowsetNotifyCP:: Fire_OnRowsetChange

Transmite um evento [OnRowsetChange](/previous-versions/windows/desktop/ms722669(v=vs.85)) para todos os ouvintes no ponto de conexão `IID_IRowsetNotify` para notificar os consumidores de uma alteração que afete todo o conjunto de linhas.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT Fire_OnRowsetChange(IRowset* pRowset,
   DBREASON eReason,
   DBEVENTPHASE ePhase,
   BOOL fCantDeny);
```

#### <a name="parameters"></a>parâmetros

Consulte [IRowsetNotify:: OnRowsetChange](/previous-versions/windows/desktop/ms722669(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="see-also"></a>Confira também

[Modelos de Provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)<br/>
[Notificações (COM)](/windows/win32/com/notifications)<br/>
[BEGIN_CONNECTION_POINT_MAP](../../atl/reference/connection-point-macros.md#begin_connection_point_map)<br/>
[END_CONNECTION_POINT_MAP](../../atl/reference/connection-point-macros.md#end_connection_point_map)<br/>
[CONNECTION_POINT_ENTRY](../../atl/reference/connection-point-macros.md#connection_point_entry)<br/>
[Criando um provedor atualizável](../../data/oledb/creating-an-updatable-provider.md)
