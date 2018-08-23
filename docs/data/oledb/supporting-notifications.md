---
title: Dando suporte a notificações | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- notifications [C++], OLE DB consumers
- events [C++], notifications in OLE DB
- OLE DB consumers, notifications
- rowsets, event notifications
- OLE DB provider templates, notifications
- OLE DB providers, notifications
ms.assetid: 76e875fd-2bfd-4e4e-9f43-dbe5a3fa7382
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 39d310b882047955201f74695f68906cabcb9d7c
ms.sourcegitcommit: a41c4d096afca1e9b619bbbce045b77135d32ae2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/14/2018
ms.locfileid: "42572803"
---
# <a name="supporting-notifications"></a>Dando suporte a notificações

## <a name="implementing-connection-point-interfaces-on-the-provider-and-consumer"></a>Implementando Interfaces de ponto de Conexão no provedor e consumidor  
 Para implementar notificações, uma classe de provedor deve herdar de [IRowsetNotifyCP](../../data/oledb/irowsetnotifycp-class.md) e [IConnectionPointContainer](../../atl/reference/iconnectionpointcontainerimpl-class.md).  
  
 `IRowsetNotifyCP` implementa o site do provedor para a interface de ponto de conexão [IRowsetNotify](/previous-versions/windows/desktop/ms712959\(v=vs.85\)). `IRowsetNotifyCP` implementa funções para informar ouvintes no ponto de conexão de difusão `IID_IRowsetNotify` de alterações no conteúdo do conjunto de linhas.  
  
 Observe que você também deve implementar e registrar `IRowsetNotify` consumidor (também conhecido como o coletor) usando [IRowsetNotifyImpl](../../data/oledb/irowsetnotifyimpl-class.md) para que o consumidor pode lidar com notificações. Para obter informações sobre como implementar a interface de ponto de conexão no consumidor, consulte [recebendo notificações](../../data/oledb/receiving-notifications.md).  
  
 Além disso, a classe também deve conter um mapa que define a entrada de ponto de conexão, como este:  
  
```  
BEGIN_CONNECTION_POINT_MAP  
   CONNECTIONPOINT_ENTRY (IID_IRowsetNotify)  
END_CONNECTION_POINT_MAP  
```  
  
## <a name="adding-irowsetnotify"></a>Adicionando IRowsetNotify  
 Para adicionar `IRowsetNotify`, você precisará adicionar `IConnectionPointContainerImpl<rowset-name>` e `IRowsetNotifyCP<rowset-name>` para sua cadeia de herança.  
  
 Por exemplo, aqui está a cadeia de herança para `RUpdateRowset` na [UpdatePV](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB/Provider/UPDATEPV):  
  
> [!NOTE]
>  O código de exemplo pode ser diferente daquele que está listado aqui. Você deve considerar o código de exemplo como a versão mais recente.  
  
```cpp
///////////////////////////////////////////////////////////////////////////  
// class RUpdateRowset (in rowset.h)  
  
class RUpdateRowset :   
public CRowsetImpl< RUpdateRowset, CAgentMan, CUpdateCommand,   
         CAtlArray< CAgentMan, CAtlArray<CAgentMan>>, CSimpleRow,   
         IRowsetScrollImpl< RUpdateRowset, IRowsetScroll >>,  
      public IRowsetUpdateImpl< RUpdateRowset, CAgentMan >,  
      public IConnectionPointContainerImpl<RUpdateRowset>,  
      public IRowsetNotifyCP<RUpdateRowset>  
```  
  
### <a name="setting-com-map-entries"></a>Entradas de configuração de mapa COM  
 Você também precisará adicionar o seguinte para o mapa COM em seu conjunto de linhas:  
  
```  
COM_INTERFACE_ENTRY(IConnectionPointContainer)  
COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)  
```  
  
 Essas macros permitem que qualquer pessoa chame `QueryInterface` para seu contêiner de ponto de conexão (a base de `IRowsetNotify`) para localizar a interface solicitada no seu provedor. Para obter um exemplo de como usar pontos de conexão, consulte o exemplo de POLÍGONO de ATL e o tutorial.  
  
### <a name="setting-connection-point-map-entries"></a>Entradas de mapa de ponto de Conexão de configuração  
 Você também precisará adicionar um mapa de ponto de conexão. Ele deve ser semelhante:  
  
```  
BEGIN_CONNECTION_POINT_MAP(rowset-name)  
     CONNECTION_POINT_ENTRY(_uuidof(IRowsetNotify))  
END_CONNECTION_POINT_MAP()  
```  
  
 Este mapa de ponto de conexão permite que um componente procurando o `IRowsetNotify` interface para encontrá-lo no seu provedor.  
  
### <a name="setting-properties"></a>Propriedades de configuração  
 Você também precisa adicionar as propriedades a seguir ao seu provedor. Você só precisará adicionar propriedades de acordo com as interfaces que dão suporte a você.  
  
|Propriedade|Adicionar se você oferecer suporte|  
|--------------|------------------------|  
|`DBPROP_IConnectionPointContainer`|Sempre|  
|`DBPROP_NOTIFICATIONGRANULARITY`|Sempre|  
|`DBPROP_NOTIFICATIONPHASES`|Sempre|  
|`DBPROP_NOTIFYCOLUMNSET`|`IRowsetChange`|  
|`DBPROP_NOTIFYROWDELETE`|`IRowsetChange`|  
|`DBPROP_NOTIFYROWINSERT`|`IRowsetChange`|  
|`DBPROP_NOTIFYROWSETFETCHPOSITIONCHANGE`|Sempre|  
|`DBPROP_NOTIFYROWFIRSTCHANGE`|`IRowsetUpdate`|  
|`DBPROP_NOTIFYROWSETRELEASE`|Sempre|  
|`DBPROP_NOTIFYROWUNDOCHANGE`|`IRowsetUpdate`|  
|`DBPROP_NOTIFYROWUNDODELETE`|`IRowsetUpdate`|  
|`DBPROP_NOTIFYROWUNDOINSERT`|`IRowsetUpdate`|  
|`DBPROP_NOTIFYROWUPDATE`|`IRowsetUpdate`|  
  
 A maioria da implementação para as notificações já está incorporado os modelos do provedor de banco de dados OLE. Se você não adicionar `IRowsetNotifyCP` para sua cadeia de herança, o compilador removerá todo esse código de seu fluxo de compilação, tornando o tamanho do código menor.  
  
## <a name="see-also"></a>Consulte também  
 [Técnicas de provedor avançadas](../../data/oledb/advanced-provider-techniques.md)