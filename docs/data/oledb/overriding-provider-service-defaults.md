---
title: "Substituindo padr&#245;es de servi&#231;o do fornecedor | Microsoft Docs"
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
  - "provedores de serviço [OLE DB]"
  - "Serviços de OLE DB [OLE DB], substituindo padrões"
ms.assetid: 08e366c0-74d8-463b-93a6-d58a8dc195f8
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Substituindo padr&#245;es de servi&#231;o do fornecedor
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Valor do registro do provedor **OLEDB\_SERVICES** é retornado como o valor padrão para o [DBPROP\_INIT\_OLEDBSERVICES](https://msdn.microsoft.com/en-us/library/ms716898.aspx) propriedade de inicialização no objeto de fonte de dados.  
  
 Desde que exista a entrada do registro, objetos do provedor são agregados e o usuário pode substituir configuração padrão do provedor para serviços habilitados, definindo o **DBPROP\_INIT\_OLEDBSERVICES** propriedade antes da inicialização. Para habilitar ou desabilitar um serviço específico, o usuário geralmente obtém o valor atual do **DBPROP\_INIT\_OLEDBSERVICES** propriedade define ou limpa o bit de propriedade específica a ser habilitado ou desabilitado e redefine a propriedade.**DBPROP\_INIT\_OLEDBSERVICES** pode ser definido diretamente no banco de dados OLE ou na cadeia de conexão passada para o ADO ou **IDataInitialize:: Getdatasource**. Os valores correspondentes para habilitar\/desabilitar serviços individuais são listados na tabela a seguir.  
  
|Serviços padrão habilitados|Valor da propriedade DBPROP\_INIT\_OLEDBSERVICES|Valor de cadeia de conexão|  
|---------------------------------|------------------------------------------------------|--------------------------------|  
|Todos os serviços \(padrão\)|**DBPROPVAL\_OS\_ENABLEALL**|"Serviços do OLE DB \= \-1;"|  
|Tudo, exceto Pooling e AutoEnlistment|**DBPROPVAL\_OS\_ENABLEALL &**<br /><br /> **~ DBPROPVAL\_OS\_RESOURCEPOOLING &**<br /><br /> **~ DBPROPVAL\_OS\_TXNENLISTMENT**|"Serviços do OLE DB \= \-4;"|  
|Todos exceto o Cursor do cliente|**DBPROPVAL\_OS\_ENABLEALL** &<br /><br /> ~**DBPROPVAL\_OS\_CLIENTCURSOR**|"Serviços do OLE DB \= \-5;"|  
|Todos exceto Pooling, AutoEnlistment e Cursor do cliente|**DBPROPVAL\_OS\_ENABLEALL &**<br /><br /> **~ DBPROPVAL\_OS\_TXNENLISTMENT &**<br /><br /> **~ DBPROPVAL\_OS\_CLIENTCURSOR**|"Serviços do OLE DB \= \-7;"|  
|Nenhum serviço|~**DBPROPVAL\_OS\_ENABLEALL**|"Serviços do OLE DB \= 0;"|  
  
 Se a entrada do registro não existe para o provedor, os gerenciadores de componente não agregará objetos do provedor e nenhum serviço será invocado, mesmo se explicitamente solicitada pelo usuário.  
  
## Consulte também  
 [Pool de recursos](https://msdn.microsoft.com/en-us/library/ms713655.aspx)   
 [Como os consumidores usam o pool de recursos](https://msdn.microsoft.com/en-us/library/ms715907.aspx)   
 [Como provedores de trabalham efetivamente com o pool de recursos](https://msdn.microsoft.com/en-us/library/ms714906.aspx)   
 [Habilitando e desabilitando serviços de banco de dados OLE](../../data/oledb/enabling-and-disabling-ole-db-services.md)