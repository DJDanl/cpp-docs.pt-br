---
title: "Pooling de recursos no aplicativo de banco de dados OLE | Microsoft Docs"
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
  - "Provedores OLE DB, sondagem de recursos"
  - "Serviços OLE DB [OLE DB], sondagem de recursos"
  - "OLE DB, sondagem de recursos"
  - "sondagem de recursos [OLE DB], serviços"
ms.assetid: 2ead1bcf-bbd4-43ea-a307-bb694b992fc1
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Pooling de recursos no aplicativo de banco de dados OLE
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Para utilizar agrupar em seu aplicativo, você deve ter certeza de que os serviços de OLE DB é invocado obtendo a fonte de dados com **IDataInitialize** ou **IDBPromptInitialize**.  Se você usar diretamente `CoCreateInstance` para invocar o provedor baseado em CLSID do provedor, nenhum serviço do OLE DB é invocado.  
  
 Os serviços de OLE DB mantêm pools de fontes de dados conectadas como uma referência a **IDataInitialize** ou a **IDBPromptInitialize** é mantido ou enquanto houver uma conexão em uso.  Os pools são mantidos também automaticamente no ambiente do ou do Internet information services \(IIS\) de um COM\+ 1,0.  Se seu aplicativo se beneficia de cluster a parte externa de serviços de um COM\+ 1,0 ou do IIS, deverá manter uma referência a **IDataInitialize** ou a **IDBPromptInitialize** ou sustentá\-la pelo menos uma conexão.  Para garantir que o pool não será destruído quando a última conexão é liberada pelo aplicativo, mantém a referência ou aferra\-se à conexão para o tempo de vida de seu aplicativo.  
  
 Os serviços de OLE DB identificam o pool de que a conexão é desenhada no momento em que `Initialize` é chamado.  Depois que a conexão é desenhada de um pool, não pode ser movida para um pool diferente.  Consequentemente, evite fazer as ações em seu aplicativo que modificam as informações de inicialização, como chamar `UnInitialize` ou chame `QueryInterface` para uma interface específica do provedor antes de chamar `Initialize`.  Além disso, as conexões estabelecidas com um valor diferente de alerta **DBPROMPT\_NOPROMPT** não são agrupadas.  No entanto, a cadeia de caracteres de inicialização recuperados de uma conexão estabelecida com o alerta pode ser usada para estabelecer conexões agrupadas adicionais para a mesma fonte de dados.  
  
 Alguns provedores devem fazer uma conexão separada para cada sessão.  Essas conexões adicionais devem ser digitadas separada na transação distribuída, se houver.  OLE DB serve a cache e reutilizar uma única sessão pela fonte de dados, mas se o aplicativo solicita mais de uma sessão de cada vez de uma única fonte de dados, o provedor pode acabar a fatura de conexões adicionais e fazer as assinaturas de transação adicionais que não são agrupadas.  É realmente mais eficiente criar uma fonte de dados separada para cada sessão em um ambiente clusterizado do que para criar várias sessões de uma única fonte de dados.  
  
 Finalmente, porque utiliza ADO automaticamente serviços do OLE DB, você pode usar o ADO para estabelecer conexões e clustering e a assinatura ocorre automaticamente.  
  
## Consulte também  
 [Pooling de recursos e serviços de banco de dados OLE](../../data/oledb/ole-db-resource-pooling-and-services.md)