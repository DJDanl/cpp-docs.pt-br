---
title: Classe IRowsetNotifyCP | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- IRowsetNotifyCP
dev_langs:
- C++
helpviewer_keywords:
- IRowsetNotifyCP class
ms.assetid: ccef402b-94a0-4c2e-9a13-7e854ef82390
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 7d20a4eb011b67a743e91f1f8340c80ea146bb7c
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="irowsetnotifycp-class"></a>Classe IRowsetNotifyCP
Implementa o site do provedor para a interface de ponto de conexão [IRowsetNotify](https://msdn.microsoft.com/en-us/library/ms712959.aspx).  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Uma classe derivada de `IRowsetNotifyCP`.  
  
 `ReentrantEventSync`  
 Uma classe mutex que suporta reentrada (o padrão é **CComSharedMutex**). Um mutex é um objeto de sincronização que permite que um thread mutuamente acesse um recurso.  
  
 `piid`  
 Um ponteiro de ID de interface (**IID\***) para um **IRowsetNotify** interface de ponto de conexão. O valor padrão é **& __uuidof(IRowsetNotify)**.  
  
 `DynamicUnkArray`  
 Uma matriz do tipo [CComDynamicUnkArray](../../atl/reference/ccomdynamicunkarray-class.md), que é uma matriz alocada dinamicamente de **IUnknown** ponteiros para o cliente do coletor de interfaces.  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[Fire_OnFieldChange](../../data/oledb/irowsetnotifycp-fire-onfieldchange.md)|Notifica o consumidor de uma alteração no valor de uma coluna.|  
|[Fire_OnRowChange](../../data/oledb/irowsetnotifycp-fire-onrowchange.md)|Notifica o consumidor de uma alteração que afetam as linhas.|  
|[Fire_OnRowsetChange](../../data/oledb/irowsetnotifycp-fire-onrowsetchange.md)|Notifica o consumidor de uma alteração que afetam todo o conjunto de linhas.|  
  
## <a name="remarks"></a>Comentários  
 `IRowsetNotifyCP` implementa funções para informar ouvintes no ponto de conexão de difusão **IID_IRowsetNotify** de alterações no conteúdo do conjunto de linhas.  
  
 Observe que você também deve implementar e registrar `IRowsetNotify` do consumidor (também conhecido como o "sink") usando [IRowsetNotifyImpl](../../data/oledb/irowsetnotifyimpl-class.md) para que o consumidor pode lidar com as notificações. Consulte [recebendo notificações](../../data/oledb/receiving-notifications.md) sobre como implementar a interface de ponto de conexão do consumidor.  
  
 Para obter informações detalhadas sobre a implementação de notificações, consulte "Suporte a notificações" [criando um provedor atualizável](../../data/oledb/creating-an-updatable-provider.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura do modelo de provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)   
 [Notificações (COM)](http://msdn.microsoft.com/library/windows/desktop/ms678433)   
 [BEGIN_CONNECTION_POINT_MAP](../../atl/reference/connection-point-macros.md#begin_connection_point_map)   
 [END_CONNECTION_POINT_MAP](../../atl/reference/connection-point-macros.md#end_connection_point_map)   
 [CONNECTION_POINT_ENTRY](../../atl/reference/connection-point-macros.md#connection_point_entry)   
 [Criando um provedor atualizável](../../data/oledb/creating-an-updatable-provider.md)