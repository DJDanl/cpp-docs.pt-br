---
title: Recebendo notificações | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- notifications [C++], OLE DB consumers
- receiving notifications in OLE DB
- events [C++], notifications in OLE DB
- notifications [C++], events
- OLE DB consumers, notifications
- rowsets, event notifications
- OLE DB providers, notifications
ms.assetid: 305a1103-0c87-40c8-94bc-7fbbdd52ae32
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 554090aadd9090e813a17d6b967ad6acbf92d924
ms.sourcegitcommit: 3a141cf07b5411d5f1fdf6cf67c4ce928cf389c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/11/2018
ms.locfileid: "49083574"
---
# <a name="receiving-notifications"></a>Recebendo notificações

OLE DB fornece interfaces para receber notificações quando ocorrem eventos. Elas são descritas em [OLE DB objeto notificações](/previous-versions/windows/desktop/ms725406) na *referência do programador DB OLE*. A instalação desses eventos usa o mecanismo de ponto de conexão de COM padrão. Por exemplo, um objeto ATL que deseja recuperar os eventos por meio `IRowsetNotify` implementa o `IRowsetNotify` interface adicionando `IRowsetNotify` para a lista de classe derivada e expô-lo por meio de uma macro COM_INTERFACE_ENTRY.  
  
`IRowsetNotify` tem três métodos que podem ser chamados em vários momentos. Se você quiser responder a apenas um desses métodos, você pode usar o [IRowsetNotifyImpl](../../data/oledb/irowsetnotifyimpl-class.md) classe, que retornará E_NOTIMPL para os métodos que você não está interessado.  
  
Quando você cria o conjunto de linhas, você deve instruir o provedor que você deseja que o objeto de conjunto de linhas retornado para dar suporte a `IConnectionPointContainer`, que é necessário para configurar a notificação.  
  
O código a seguir mostra como abrir o conjunto de linhas de um objeto ATL e usar o `AtlAdvise` função para configurar o coletor de notificação. `AtlAdvise` Retorna um cookie que é usado quando você chama `AtlUnadvise`.  
  
```cpp  
CDBPropSet propset(DBPROPSET_ROWSET);  

propset.AddProperty(DBPROP_IConnectionPointContainer, true);  
  
product.Open(session, _T("Products"), &propset);  
  
AtlAdvise(product.m_spRowset, GetUnknown(), IID_IRowsetNotify, &m_dwCookie);  
```  
  
## <a name="see-also"></a>Consulte também  

[Usando acessadores](../../data/oledb/using-accessors.md)