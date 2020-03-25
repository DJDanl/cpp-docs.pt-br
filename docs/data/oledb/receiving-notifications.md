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
ms.openlocfilehash: 4b630a9728770a5e35e6d6300cf465b90238350c
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80209753"
---
# <a name="receiving-notifications"></a>Recebendo notificações

OLE DB fornece interfaces para receber notificações quando ocorrem eventos. Elas são descritas em [OLE DB notificações de objeto](/previous-versions/windows/desktop/ms725406(v=vs.85)) na **referência do programador de OLE DB**. A configuração desses eventos usa o mecanismo de ponto de conexão COM padrão. Por exemplo, um objeto ATL que deseja recuperar eventos por meio de `IRowsetNotify` implementa a interface `IRowsetNotify` adicionando `IRowsetNotify` à lista derivada de classe e expondo-a por meio de uma macro COM_INTERFACE_ENTRY.

`IRowsetNotify` tem três métodos, que podem ser chamados em vários momentos. Se você quiser responder a apenas um desses métodos, poderá usar a classe [IRowsetNotifyImpl](../../data/oledb/irowsetnotifyimpl-class.md) , que retorna E_NOTIMPL para os métodos nos quais você não está interessado.

Ao criar o conjunto de linhas, você deve informar ao provedor que deseja que o objeto de conjunto de linhas retornado dê suporte a `IConnectionPointContainer`, o que é necessário para configurar a notificação.

O código a seguir mostra como abrir o conjunto de linhas de um objeto ATL e usar a função `AtlAdvise` para configurar o coletor de notificação. `AtlAdvise` retorna um cookie que é usado quando você chama `AtlUnadvise`.

```cpp
CDBPropSet propset(DBPROPSET_ROWSET);
propset.AddProperty(DBPROP_IConnectionPointContainer, true);
```

Em seguida, usado pelo seguinte código:

```cpp
product.Open(session, _T("Products"), &propset);

AtlAdvise(product.m_spRowset, GetUnknown(), IID_IRowsetNotify, &m_dwCookie);
```

## <a name="see-also"></a>Confira também

[Usando acessadores](../../data/oledb/using-accessors.md)
