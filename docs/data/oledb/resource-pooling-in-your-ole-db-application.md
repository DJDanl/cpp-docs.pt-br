---
title: Pool de recursos no aplicativo OLE DB | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- OLE DB services [OLE DB], resource pooling
- resource pooling [OLE DB], services
- OLE DB, resource pooling
- OLE DB providers, resource pooling
ms.assetid: 2ead1bcf-bbd4-43ea-a307-bb694b992fc1
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 84b8814974850238ccf0be7411821d6e2cce8880
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="resource-pooling-in-your-ole-db-application"></a>Pooling de recursos no aplicativo de banco de dados OLE
Para aproveitar o pool em seu aplicativo, você deve verificar se os serviços de OLE DB são chamados obtendo sua fonte de dados por meio de **IDataInitialize** ou **IDBPromptInitialize**. Se você usar diretamente `CoCreateInstance` para chamar o provedor com base no CLSID do provedor, não há serviços de OLE DB são invocados.  
  
 Os serviços de OLE DB mantêm grupos de fontes de dados conectadas, contanto que uma referência a **IDataInitialize** ou **IDBPromptInitialize** é mantido ou desde que haja uma conexão em uso. Pools também são mantidos automaticamente em um ambiente de COM+ 1.0 serviços ou serviços de informações da Internet (IIS). Se seu aplicativo se beneficia de pooling fora de um ambiente de COM+ 1.0 serviços ou IIS, você deve manter uma referência a **IDataInitialize** ou **IDBPromptInitialize** ou mantenha pelo menos um conexão. Para certificar-se de que o pool não obter destruído quando a última conexão é liberada pelo aplicativo, manter a referência ou manter a conexão para o tempo de vida do aplicativo.  
  
 Serviços OLE DB identificam o grupo do qual a conexão é desenhado no momento em que `Initialize` é chamado. Depois que a conexão é desenhada de um pool, ele não pode ser movido para um pool diferente. Portanto, evite fazer as coisas em seu aplicativo que alterar as informações de inicialização, como chamar `UnInitialize` ou chamar `QueryInterface` para uma interface específica do provedor antes de chamar `Initialize`. Além disso, as conexões estabelecidas com um valor da solicitação que **DBPROMPT_NOPROMPT** não são agrupados. No entanto, a cadeia de caracteres de inicialização recuperada de uma conexão estabelecida por meio de solicitação pode ser usada para estabelecer conexões adicionais do pool com a mesma fonte de dados.  
  
 Alguns provedores devem fazer uma conexão separada para cada sessão. Essas conexões adicionais devem ser inscrita separadamente na transação distribuída, se houver. Serviços OLE DB armazena em cache e reutiliza uma única sessão por fonte de dados, mas se o aplicativo solicitar mais de uma sessão em vez de uma única fonte de dados, o provedor pode acabar fazer conexões adicionais e fazer inscrições de transações adicionais que são não agrupado. Ela é realmente mais eficiente para criar uma fonte de dados separada para cada sessão em um ambiente em pool que criar várias sessões de uma fonte de dados.  
  
 Por fim, como ADO automaticamente faz uso do OLE DB services, você pode usar o ADO para estabelecer conexões e o pool e a inscrição acontecem automaticamente.  
  
## <a name="see-also"></a>Consulte também  
 [Pooling de recursos e serviços do OLE DB](../../data/oledb/ole-db-resource-pooling-and-services.md)