---
title: "Classe IRowsetNotifyCP | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "IRowsetNotifyCP"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe IRowsetNotifyCP"
ms.assetid: ccef402b-94a0-4c2e-9a13-7e854ef82390
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe IRowsetNotifyCP
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa ao site do provedor para a interface [IRowsetNotify](https://msdn.microsoft.com/en-us/library/ms712959.aspx)do ponto de conexão.  
  
## Sintaxe  
  
```  
template <  
   class T,   
   class ReentrantEventSync = CComSharedMutex   
>  
class IRowsetNotifyCP :   
   public IConnectionPointImpl<  
      T,   
      piid = &__uuidof(IRowsetNotify),   
      CComDynamicUnkArray DynamicUnkArray  
   >,  
   public ReentrantEventSync  
```  
  
#### Parâmetros  
 `T`  
 Uma classe derivada de `IRowsetNotifyCP`.  
  
 `ReentrantEventSync`  
 Uma classe do mutex que da suporte ao reentrancy \(o padrão é **CComSharedMutex**\).  Um mutex é um objeto de sincronização que permite a um thread o acesso a um recurso mutuamente exclusivos.  
  
 `piid`  
 Um ponteiro de ID da interface**IID\***\(\) para uma interface do ponto de conexão de **IRowsetNotify** .  O valor padrão é **&\_\_uuidof\(IRowsetNotify\)**.  
  
 `DynamicUnkArray`  
 Uma matriz do tipo [CComDynamicUnkArray](../Topic/CComDynamicUnkArray%20Class.md), que é atribuída dinamicamente uma matriz de ponteiros de **IUnknown** as interfaces de coletor do cliente.  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[Fire\_OnFieldChange](../../data/oledb/irowsetnotifycp-fire-onfieldchange.md)|Notifica o consumidor de uma alteração no valor de uma coluna.|  
|[Fire\_OnRowChange](../../data/oledb/irowsetnotifycp-fire-onrowchange.md)|Notifica o consumidor de uma alteração que afeta as linhas.|  
|[Fire\_OnRowsetChange](../../data/oledb/irowsetnotifycp-fire-onrowsetchange.md)|Notifica o consumidor de uma alteração que afeta todo o conjunto de linhas.|  
  
## Comentários  
 `IRowsetNotifyCP` implementa funções difundidas para recomendar ouvintes no ponto de conexão **IID\_IRowsetNotify** as alterações para o conteúdo do conjunto de linhas.  
  
 Observe que você também deve implementar e registrar `IRowsetNotify` no consumidor \(também conhecido como “coletor”\) que usa [IRowsetNotifyImpl](../Topic/IRowsetNotifyImpl%20Class.md) de modo que ele possa controlar notificações.  Consulte [Recebendo notificações](../../data/oledb/receiving-notifications.md) sobre como implementar o ponto de conexão para fazer interface no consumidor.  
  
 Para obter informações detalhadas sobre como implementar notificações, consulte “notificações de suporte” em [Criando um provedor atualizável](../../data/oledb/creating-an-updatable-provider.md).  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Modelos de provedor de banco de dados OLE](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor de banco de dados OLE](../../data/oledb/ole-db-provider-template-architecture.md)   
 [Notifications \(COM\)](http://msdn.microsoft.com/library/windows/desktop/ms678433)   
 [Overview of Notifications \(OLE DB\)](https://msdn.microsoft.com/en-us/library/ms725406.aspx)   
 [BEGIN\_CONNECTION\_POINT\_MAP](../Topic/BEGIN_CONNECTION_POINT_MAP.md)   
 [END\_CONNECTION\_POINT\_MAP](../Topic/END_CONNECTION_POINT_MAP.md)   
 [CONNECTION\_POINT\_ENTRY](../Topic/CONNECTION_POINT_ENTRY.md)   
 [Criando um provedor atualizável](../../data/oledb/creating-an-updatable-provider.md)