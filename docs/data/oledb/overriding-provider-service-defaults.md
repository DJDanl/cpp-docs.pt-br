---
title: "Substituindo padrões de serviço do provedor | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- service providers [OLE DB]
- OLE DB services [OLE DB], overriding defaults
ms.assetid: 08e366c0-74d8-463b-93a6-d58a8dc195f8
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 9185f1eb3640a4baeb8f7cc1d7b20169c980a8e1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="overriding-provider-service-defaults"></a>Substituindo padrões de serviço do fornecedor
O valor do provedor do registro para **OLEDB_SERVICES** é retornado como o valor padrão para o [DBPROP_INIT_OLEDBSERVICES](https://msdn.microsoft.com/en-us/library/ms716898.aspx) propriedade de inicialização no objeto de fonte de dados.  
  
 Como a entrada do registro existe, os objetos do provedor são agregados e o usuário pode substituir configuração padrão do provedor para serviços habilitados, definindo o **DBPROP_INIT_OLEDBSERVICES** propriedade antes da inicialização. Para habilitar ou desabilitar um serviço específico, o usuário geralmente obtém o valor atual de **DBPROP_INIT_OLEDBSERVICES** propriedade define ou limpa o bit de uma propriedade específica ser habilitado ou desabilitado e redefine a propriedade. **DBPROP_INIT_OLEDBSERVICES** pode ser definido diretamente no banco de dados OLE ou na cadeia de conexão passada para o ADO ou **IDataInitialize:: Getdatasource**. Os valores correspondentes para habilitar/desabilitar serviços individuais são listados na tabela a seguir.  
  
|Serviços padrão habilitados|Valor da propriedade DBPROP_INIT_OLEDBSERVICES|Valor de cadeia de caracteres de conexão|  
|------------------------------|------------------------------------------------|--------------------------------|  
|Todos os serviços (padrão)|**DBPROPVAL_OS_ENABLEALL**|"Serviços do OLE DB = -1;"|  
|Tudo, exceto o pool e AutoEnlistment|**DBPROPVAL_OS_ENABLEALL &**<br /><br /> **~ DBPROPVAL_OS_RESOURCEPOOLING &**<br /><br /> **~ DBPROPVAL_OS_TXNENLISTMENT**|"Serviços do OLE DB = -4;"|  
|Tudo, exceto Cursor do cliente|**DBPROPVAL_OS_ENABLEALL** &<br /><br /> ~**DBPROPVAL_OS_CLIENTCURSOR**|"Serviços do OLE DB = -5;"|  
|Todos exceto pool, AutoEnlistment e o Cursor do cliente|**DBPROPVAL_OS_ENABLEALL &**<br /><br /> **~ DBPROPVAL_OS_TXNENLISTMENT &**<br /><br /> **~ DBPROPVAL_OS_CLIENTCURSOR**|"Serviços do OLE DB = -7;"|  
|Nenhum serviço|~**DBPROPVAL_OS_ENABLEALL**|"Serviços do OLE DB = 0;"|  
  
 Se a entrada do registro não existe para o provedor, os gerenciadores de componente não agregará os objetos do provedor, e nenhum serviço será invocado, mesmo se solicitado explicitamente pelo usuário.  
  
## <a name="see-also"></a>Consulte também  
 [Pool de recursos](https://msdn.microsoft.com/en-us/library/ms713655.aspx)   
 [Como os consumidores usam o pool de recursos](https://msdn.microsoft.com/en-us/library/ms715907.aspx)   
 [Como os provedores de trabalhar efetivamente com o pool de recursos](https://msdn.microsoft.com/en-us/library/ms714906.aspx)   
 [Habilitando e desabilitando serviços do OLE DB](../../data/oledb/enabling-and-disabling-ole-db-services.md)