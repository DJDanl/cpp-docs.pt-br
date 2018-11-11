---
title: Pooling de recursos no aplicativo de banco de dados OLE
ms.date: 10/29/2018
helpviewer_keywords:
- OLE DB services [OLE DB], resource pooling
- resource pooling [OLE DB], services
- OLE DB, resource pooling
- OLE DB providers, resource pooling
ms.assetid: 2ead1bcf-bbd4-43ea-a307-bb694b992fc1
ms.openlocfilehash: 2dc5fbe760b2e62eec8b974bb496e52d1de25f50
ms.sourcegitcommit: 943c792fdabf01c98c31465f23949a829eab9aad
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/07/2018
ms.locfileid: "51264952"
---
# <a name="resource-pooling-in-your-ole-db-application"></a>Pooling de recursos no aplicativo de banco de dados OLE

Para aproveitar o pool em seu aplicativo, certifique-se de serviços do OLE DB são invocados obtendo sua fonte de dados por meio `IDataInitialize` ou `IDBPromptInitialize`. Se você usar diretamente `CoCreateInstance` para invocar o provedor com base no CLSID do provedor, sem serviços do OLE DB são invocados.

Os serviços de OLE DB mantêm pools de fontes de dados conectadas, desde que uma referência a `IDataInitialize` ou `IDBPromptInitialize` é retido ou, desde que haja uma conexão em uso. Pools também são mantidos automaticamente dentro de um ambiente de serviços do COM+ 1.0 ou o Internet Information Services (IIS). Se seu aplicativo se beneficia de pooling externa em um ambiente de serviços do COM+ 1.0 ou o IIS, você deve manter uma referência ao `IDataInitialize` ou `IDBPromptInitialize` ou mantenha pelo menos uma conexão. Para certificar-se de que o pool não obter destruído quando a última conexão é liberado pelo aplicativo, manter a referência ou manter a conexão para o tempo de vida do seu aplicativo.

Serviços do OLE DB identificam o pool do qual a conexão é desenhado no momento em que `Initialize` é chamado. Depois que a conexão é desenhada de um pool, ele não pode ser movido para um pool diferente. Portanto, evite fazer as coisas em seu aplicativo que alterar as informações de inicialização, por exemplo, chamar `UnInitialize` ou chamar `QueryInterface` para uma interface específica do provedor antes de chamar `Initialize`. Além disso, as conexões estabelecidas com um valor prompt diferente DBPROMPT_NOPROMPT não são agrupadas. No entanto, a cadeia de caracteres de inicialização recuperada de uma conexão estabelecida por meio de solicitando que pode ser usada para estabelecer conexões em pool adicionais à mesma fonte de dados.

Alguns provedores devem fazer uma conexão separada para cada sessão. Essas conexões adicionais devem ser inscrito separadamente na transação distribuída, se houver. Os caches de serviços de OLE DB e reutiliza uma única sessão por fonte de dados, mas se o aplicativo solicitar mais de uma sessão em vez de uma única fonte de dados, o provedor pode acabar fazendo conexões adicionais e fazer inscrições em transações adicionais que não são agrupadas. Ele é mais eficiente para criar uma fonte de dados separado para cada sessão em um ambiente em pool que criar várias sessões de uma única fonte de dados.

Por fim, porque ADO automaticamente faz uso de OLE DB services, você pode usar o ADO para estabelecer conexões e o pool e a inscrição ocorrem automaticamente.

## <a name="see-also"></a>Consulte também

[Pooling de recursos e serviços do OLE DB](../../data/oledb/ole-db-resource-pooling-and-services.md)