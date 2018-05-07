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
ms.openlocfilehash: d9e1dee5c63281c729cdb798a190938c6433aac0
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="receiving-notifications"></a>Recebendo notificações
OLE DB fornece interfaces para receber notificações quando os eventos ocorrem. Elas são descritas nas [OLE DB objeto notificações](https://msdn.microsoft.com/en-us/library/ms725406.aspx) no *referência do programador de DB OLE*. A instalação desses eventos usa o mecanismo padrão de ponto de conexão de COM. Por exemplo, um objeto ATL que deseja recuperar eventos por meio de `IRowsetNotify` implementa o `IRowsetNotify` interface adicionando `IRowsetNotify` à lista de classe derivada e expô-lo por meio de um **COM_INTERFACE_ENTRY** macro.  
  
 `IRowsetNotify` tem três métodos, que podem ser chamados várias vezes. Se você deseja responder a apenas um desses métodos, você pode usar o [IRowsetNotifyImpl](../../data/oledb/irowsetnotifyimpl-class.md) classe, que retorna **E_NOTIMPL** para os métodos que você não está interessado.  
  
 Quando você cria o conjunto de linhas, você deve instruir o provedor que você deseja que o objeto de conjunto de linhas retornado para oferecer suporte a **IConnectionPointContainer**, que é necessário para configurar a notificação.  
  
 O código a seguir mostra como abrir o conjunto de linhas de um objeto ATL e usar o `AtlAdvise` função para configurar o coletor de notificação. `AtlAdvise` Retorna um cookie que é usado quando você chamar `AtlUnadvise`.  
  
```  
CDBPropSet propset(DBPROPSET_ROWSET);  

propset.AddProperty(DBPROP_IConnectionPointContainer, true);  
  

product.Open(session, _T("Products"), &propset);  
  

AtlAdvise(product.m_spRowset, GetUnknown(), IID_IRowsetNotify, &m_dwCookie);  
```  
  
## <a name="see-also"></a>Consulte também  
 [Usando acessadores](../../data/oledb/using-accessors.md)