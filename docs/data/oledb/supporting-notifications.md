---
title: "Dando suporte a notifica&#231;&#245;es | Microsoft Docs"
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
  - "notificações [C++], Consumidores OLE DB"
  - "Consumidores OLE DB, notificações"
  - "modelos de provedor do OLE DB, notificações"
  - "Provedores OLE DB, notificações"
  - "conjuntos de linhas, notificações de evento"
ms.assetid: 76e875fd-2bfd-4e4e-9f43-dbe5a3fa7382
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Dando suporte a notifica&#231;&#245;es
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

## Implementando o ponto de conexão faz interface no provedor e o consumidor  
 Para implementar notificações, uma classe do provedor deve herdar de [IRowsetNotifyCP](../../data/oledb/irowsetnotifycp-class.md) e de [IConnectionPointContainer](../Topic/IConnectionPointContainerImpl%20Class.md).  
  
 `IRowsetNotifyCP` implementa ao site do provedor para a interface [IRowsetNotify](https://msdn.microsoft.com/en-us/library/ms712959.aspx)do ponto de conexão.  `IRowsetNotifyCP` implementa funções difundidas para recomendar ouvintes no ponto de conexão **IID\_IRowsetNotify** as alterações para o conteúdo do conjunto de linhas.  
  
 Observe que você também deve implementar e registrar `IRowsetNotify` no consumidor \(também conhecido como o coletor\) que usa [IRowsetNotifyImpl](../Topic/IRowsetNotifyImpl%20Class.md) de modo que ele possa controlar notificações.  Para obter informações sobre como implementar a interface do ponto de conexão no consumidor, consulte [Recebendo notificações](../../data/oledb/receiving-notifications.md).  
  
 Além disso, a classe também deve conter um mapa que define a entrada do ponto de conexão, desta forma:  
  
```  
BEGIN_CONNECTION_POINT_MAP  
   CONNECTIONPOINT_ENTRY (IID_IRowsetNotify)  
END_CONNECTION_POINT_MAP  
```  
  
## Adicionando IRowsetNotify  
 Para adicionar `IRowsetNotify`, você precisa adicionar `IConnectionPointContainerImpl<rowset-name>` e `IRowsetNotifyCP<rowset-name>` a sua cadeia de herança.  
  
 Por exemplo, aqui está a cadeia de herança para `RUpdateRowset` em [UpdatePV](http://msdn.microsoft.com/pt-br/c8bed873-223c-4a7d-af55-f90138c6f38f):  
  
> [!NOTE]
>  O código de exemplo pode ser diferente do que é listado aqui; você deve considerar o código de exemplo como a versão mais atualizada.  
  
```  
///////////////////////////////////////////////////////////////////////////  
// class RUpdateRowset (in rowset.h)  
  
class RUpdateRowset :   
public CRowsetImpl< RUpdateRowset, CAgentMan, CUpdateCommand,   
         CAtlArray< CAgentMan, CAtlArray<CAgentMan> >, CSimpleRow,   
         IRowsetScrollImpl< RUpdateRowset, IRowsetScroll > >,  
      public IRowsetUpdateImpl< RUpdateRowset, CAgentMan >,  
      public IConnectionPointContainerImpl<RUpdateRowset>,  
      public IRowsetNotifyCP<RUpdateRowset>  
```  
  
### Entradas do mapa do COM configuração  
 Você também precisa unir o seguinte ao mapa COM no conjunto de linhas:  
  
```  
COM_INTERFACE_ENTRY(IConnectionPointContainer)  
COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)  
```  
  
 Esses macros permitem qualquer um que chama `QueryInterface` do respectivo contêiner do ponto de conexão \(a base de `IRowsetNotify`\) para localizar a interface solicitada do provedor.  Para obter um exemplo de como usar pontos de conexão, consulte o exemplo e o tutorial de POLYGON de ATL.  
  
### Entradas do mapa do ponto de conexão de configuração  
 Você também precisa adicionar um mapa de ponto de conexão.  Deve ser algo como:  
  
```  
BEGIN_CONNECTION_POINT_MAP(rowset-name)  
     CONNECTION_POINT_ENTRY(_uuidof(IRowsetNotify))  
END_CONNECTION_POINT_MAP()  
```  
  
 Esse mapa do ponto de conexão permite um componente que procura a interface de `IRowsetNotify` para localizá\-la do provedor.  
  
### Definindo propriedades  
 Você também precisa unir as seguintes propriedades ao provedor.  Você só precisará adicionar propriedades com base nas interfaces que você tem suporte.  
  
|Propriedade|Se você adicionar suporte|  
|-----------------|-------------------------------|  
|**DBPROP\_IConnectionPointContainer**|Sempre|  
|**DBPROP\_NOTIFICATIONGRANULARITY**|Sempre|  
|**DBPROP\_NOTIFICATIONPHASES**|Sempre|  
|**DBPROP\_NOTIFYCOLUMNSET**|`IRowsetChange`|  
|**DBPROP\_NOTIFYROWDELETE**|`IRowsetChange`|  
|**DBPROP\_NOTIFYROWINSERT**|`IRowsetChange`|  
|**DBPROP\_NOTIFYROWSETFETCHPOSITIONCHANGE**|Sempre|  
|**DBPROP\_NOTIFYROWFIRSTCHANGE**|`IRowsetUpdate`|  
|**DBPROP\_NOTIFYROWSETRELEASE**|Sempre|  
|**DBPROP\_NOTIFYROWUNDOCHANGE**|`IRowsetUpdate`|  
|**DBPROP\_NOTIFYROWUNDODELETE**|`IRowsetUpdate`|  
|**DBPROP\_NOTIFYROWUNDOINSERT**|`IRowsetUpdate`|  
|**DBPROP\_NOTIFYROWUPDATE**|`IRowsetUpdate`|  
  
 A maioria de implementação para notificações já é inserida em modelos do provedor OLE DB.  Devido a um recurso do compilador do Visual C\+\+ .NET, se você não adicionar `IRowsetNotifyCP` a sua cadeia de herança, o compilador remove todo o código de seu fluxo de compilação, tornando seu tamanho menor de código.  
  
## Consulte também  
 [Técnicas de provedor avançadas](../Topic/Advanced%20Provider%20Techniques.md)