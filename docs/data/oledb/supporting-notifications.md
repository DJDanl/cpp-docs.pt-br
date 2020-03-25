---
title: Dando suporte a notificações
ms.date: 11/04/2016
helpviewer_keywords:
- notifications [C++], OLE DB consumers
- events [C++], notifications in OLE DB
- OLE DB consumers, notifications
- rowsets, event notifications
- OLE DB provider templates, notifications
- OLE DB providers, notifications
ms.assetid: 76e875fd-2bfd-4e4e-9f43-dbe5a3fa7382
ms.openlocfilehash: d29f84a0a5b33d55c0a04a4c758050cf9746f72a
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80209530"
---
# <a name="supporting-notifications"></a>Dando suporte a notificações

## <a name="implementing-connection-point-interfaces-on-the-provider-and-consumer"></a>Implementando interfaces de ponto de conexão no provedor e no consumidor

Para implementar notificações, uma classe de provedor deve herdar de [IRowsetNotifyCP](../../data/oledb/irowsetnotifycp-class.md) e [IConnectionPointContainer](../../atl/reference/iconnectionpointcontainerimpl-class.md).

`IRowsetNotifyCP` implementa o site do provedor para a interface de ponto de conexão [IRowsetNotify](/previous-versions/windows/desktop/ms712959(v=vs.85)). `IRowsetNotifyCP` implementa funções de difusão para avisar os ouvintes no ponto de conexão `IID_IRowsetNotify` de alterações ao conteúdo do conjunto de linhas.

Você também deve implementar e registrar `IRowsetNotify` no consumidor (também conhecido como coletor) usando o [IRowsetNotifyImpl](../../data/oledb/irowsetnotifyimpl-class.md) para que o consumidor possa lidar com notificações. Para obter informações sobre como implementar a interface de ponto de conexão no consumidor, consulte [recebendo notificações](../../data/oledb/receiving-notifications.md).

Além disso, a classe deve ter um mapa que defina a entrada do ponto de conexão, desta forma:

```cpp
BEGIN_CONNECTION_POINT_MAP
   CONNECTIONPOINT_ENTRY (IID_IRowsetNotify)
END_CONNECTION_POINT_MAP
```

## <a name="adding-irowsetnotify"></a>Adicionando IRowsetNotify

Para adicionar `IRowsetNotify`, você precisa adicionar `IConnectionPointContainerImpl<rowset-name>` e `IRowsetNotifyCP<rowset-name>` à sua cadeia de herança.

Por exemplo, aqui está a cadeia de herança para `RUpdateRowset` em [UpdatePV](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB/Provider/UPDATEPV):

> [!NOTE]
> O código de exemplo pode ser diferente do que está listado aqui. Você deve considerar o código de exemplo como a versão mais recente.

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

### <a name="setting-com-map-entries"></a>Configurando entradas de mapa COM

Você também precisa adicionar o seguinte ao mapa COM em seu conjunto de linhas:

```cpp
COM_INTERFACE_ENTRY(IConnectionPointContainer)
COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
```

Essas macros permitem que qualquer pessoa que chame `QueryInterface` para seu contêiner de ponto de conexão (a base de `IRowsetNotify`) Localize a interface solicitada em seu provedor. Para obter um exemplo de como usar pontos de conexão, consulte o exemplo de polígono do ATL e tutorial.

### <a name="setting-connection-point-map-entries"></a>Definindo entradas de mapa de ponto de conexão

Você também precisa adicionar um mapa de ponto de conexão. Ele deve ser semelhante a:

```cpp
BEGIN_CONNECTION_POINT_MAP(rowset-name)
     CONNECTION_POINT_ENTRY(_uuidof(IRowsetNotify))
END_CONNECTION_POINT_MAP()
```

Esse mapa de ponto de conexão permite que um componente procure a interface `IRowsetNotify` para encontrá-la em seu provedor.

### <a name="setting-properties"></a>Definindo propriedades

Você também precisa adicionar as propriedades a seguir ao seu provedor. Você só precisa adicionar propriedades com base nas interfaces às quais dá suporte.

|Propriedade|Adicionar se você oferecer suporte|
|--------------|------------------------|
|DBPROP_IConnectionPointContainer|Sempre|
|DBPROP_NOTIFICATIONGRANULARITY|Sempre|
|DBPROP_NOTIFICATIONPHASES|Sempre|
|DBPROP_NOTIFYCOLUMNSET|`IRowsetChange`|
|DBPROP_NOTIFYROWDELETE|`IRowsetChange`|
|DBPROP_NOTIFYROWINSERT|`IRowsetChange`|
|DBPROP_NOTIFYROWSETFETCHPOSITIONCHANGE|Sempre|
|DBPROP_NOTIFYROWFIRSTCHANGE|`IRowsetUpdate`|
|DBPROP_NOTIFYROWSETRELEASE|Sempre|
|DBPROP_NOTIFYROWUNDOCHANGE|`IRowsetUpdate`|
|DBPROP_NOTIFYROWUNDODELETE|`IRowsetUpdate`|
|DBPROP_NOTIFYROWUNDOINSERT|`IRowsetUpdate`|
|DBPROP_NOTIFYROWUPDATE|`IRowsetUpdate`|

A maior parte da implementação para as notificações já está inserida nos modelos de provedor de OLE DB. Se você não adicionar `IRowsetNotifyCP` à sua cadeia de herança, o compilador removerá todo o código do seu fluxo de compilação, tornando o tamanho do código menor.

## <a name="see-also"></a>Confira também

[Técnicas de provedor avançadas](../../data/oledb/advanced-provider-techniques.md)
