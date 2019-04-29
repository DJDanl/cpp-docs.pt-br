---
title: Recebendo notificações
ms.date: 10/24/2018
helpviewer_keywords:
- notifications [C++], OLE DB consumers
- receiving notifications in OLE DB
- events [C++], notifications in OLE DB
- notifications [C++], events
- OLE DB consumers, notifications
- rowsets, event notifications
- OLE DB providers, notifications
ms.assetid: 305a1103-0c87-40c8-94bc-7fbbdd52ae32
ms.openlocfilehash: b35c1d3d6ff7d5d74493e843575f7448c4df8d8f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62283760"
---
# <a name="receiving-notifications"></a>Recebendo notificações

OLE DB fornece interfaces para receber notificações quando ocorrem eventos. Elas são descritas em [OLE DB objeto notificações](/previous-versions/windows/desktop/ms725406(v=vs.85)) na **referência do programador DB OLE**. A instalação desses eventos usa o mecanismo de ponto de conexão de COM padrão. Por exemplo, um objeto ATL que deseja recuperar os eventos por meio `IRowsetNotify` implementa o `IRowsetNotify` interface adicionando `IRowsetNotify` para a lista de classe derivada e expô-lo por meio de uma macro COM_INTERFACE_ENTRY.

`IRowsetNotify` tem três métodos que podem ser chamados em vários momentos. Se você quiser responder a apenas um desses métodos, você pode usar o [IRowsetNotifyImpl](../../data/oledb/irowsetnotifyimpl-class.md) classe, que retornará E_NOTIMPL para os métodos que você não esteja interessado em.

Quando você cria o conjunto de linhas, você deve instruir o provedor que você deseja que o objeto de conjunto de linhas retornado para dar suporte a `IConnectionPointContainer`, que é necessário para configurar a notificação.

O código a seguir mostra como abrir o conjunto de linhas de um objeto ATL e usar o `AtlAdvise` função para configurar o coletor de notificação. `AtlAdvise` Retorna um cookie que é usado quando você chama `AtlUnadvise`.

```cpp
CDBPropSet propset(DBPROPSET_ROWSET);
propset.AddProperty(DBPROP_IConnectionPointContainer, true);
```

Em seguida, usado pelo código a seguir:

```cpp
product.Open(session, _T("Products"), &propset);

AtlAdvise(product.m_spRowset, GetUnknown(), IID_IRowsetNotify, &m_dwCookie);
```

## <a name="see-also"></a>Consulte também

[Usando acessadores](../../data/oledb/using-accessors.md)