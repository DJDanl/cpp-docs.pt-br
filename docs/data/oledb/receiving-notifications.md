---
title: "Recebendo notifica&#231;&#245;es | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "eventos [C++], notificações no OLE DB"
  - "notificações [C++], eventos"
  - "notificações [C++], Consumidores OLE DB"
  - "Consumidores OLE DB, notificações"
  - "Provedores OLE DB, notificações"
  - "recebendo notificações no OLE DB"
  - "conjuntos de linhas, notificações de evento"
ms.assetid: 305a1103-0c87-40c8-94bc-7fbbdd52ae32
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Recebendo notifica&#231;&#245;es
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O OLE DB fornece interfaces para receber notificações quando os eventos ocorrem.  Esses são descritos em [Notificações do objeto OLE DB](https://msdn.microsoft.com/en-us/library/ms725406.aspx)*na referência do programador de OLE DB*.  A configuração desses eventos usa o mecanismo padrão do ponto da.  Por exemplo, um objeto de ATL que deseja recuperar eventos com `IRowsetNotify` implementa a interface de `IRowsetNotify` adicionando `IRowsetNotify` classe à lista derivado e expõe o com uma macro de **COM\_INTERFACE\_ENTRY** .  
  
 `IRowsetNotify` tem três métodos, que podem ser chamados diversas vezes.  Se você quiser responder a somente um desses métodos, você pode usar a classe de [IRowsetNotifyImpl](../Topic/IRowsetNotifyImpl%20Class.md) , que retorna **E\_NOTIMPL** para os métodos que não está interessado.  
  
 Quando você cria o conjunto de linhas, você deve informar ao provedor que você deseja que o objeto retornado do conjunto de linhas para dar suporte a **IConnectionPointContainer**, que é necessário para configurar a notificação.  
  
 O código a seguir mostra como abrir o conjunto de linhas de um objeto de ATL e usar a função de `AtlAdvise` para configurar o coletor de notificação.  `AtlAdvise` retorna um cookie usada quando você chama `AtlUnadvise`.  
  
```  
CDBPropSet propset(DBPROPSET_ROWSET);  
propset.AddProperty(DBPROP_IConnectionPointContainer, true);  
  
product.Open(session, _T("Products"), &propset);  
  
AtlAdvise(product.m_spRowset, GetUnknown(), IID_IRowsetNotify, &m_dwCookie);  
```  
  
## Consulte também  
 [Usando acessadores](../../data/oledb/using-accessors.md)