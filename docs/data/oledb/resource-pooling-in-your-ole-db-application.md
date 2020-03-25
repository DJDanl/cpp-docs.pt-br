---
title: Pooling de recursos no aplicativo de banco de dados OLE
ms.date: 10/29/2018
helpviewer_keywords:
- OLE DB services [OLE DB], resource pooling
- resource pooling [OLE DB], services
- OLE DB, resource pooling
- OLE DB providers, resource pooling
ms.assetid: 2ead1bcf-bbd4-43ea-a307-bb694b992fc1
ms.openlocfilehash: 3604f6eaaf0f34a0ff7e54826923c2aa92eef4a2
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80209750"
---
# <a name="resource-pooling-in-your-ole-db-application"></a>Pooling de recursos no aplicativo de banco de dados OLE

Para aproveitar o pooling em seu aplicativo, você deve verificar se OLE DB serviços são invocados obtendo sua fonte de dados por meio de `IDataInitialize` ou `IDBPromptInitialize`. Se você usar diretamente `CoCreateInstance` para invocar o provedor com base no CLSID do provedor, nenhum serviço OLE DB será invocado.

Os serviços de OLE DB mantêm pools de fontes de dados conectadas, desde que uma referência a `IDataInitialize` ou `IDBPromptInitialize` seja mantida ou contanto que haja uma conexão em uso. Os pools também são mantidos automaticamente em um ambiente de serviços COM+ 1,0 ou Serviços de Informações da Internet (IIS). Se seu aplicativo se beneficiar de pools externos a um ambiente do IIS ou serviços COM+ 1,0, você deverá manter uma referência a `IDataInitialize` ou `IDBPromptInitialize` ou manter pelo menos uma conexão. Para certificar-se de que o pool não seja destruído quando a última conexão for liberada pelo aplicativo, mantenha a referência ou aguarde a conexão para o tempo de vida do seu aplicativo.

Os serviços de OLE DB identificam o pool do qual a conexão é desenhada no momento em que `Initialize` é chamado. Depois que a conexão é desenhada de um pool, ela não pode ser movida para um pool diferente. Portanto, evite fazer coisas em seu aplicativo que alterem informações de inicialização, como chamar `UnInitialize` ou chamar `QueryInterface` para uma interface específica do provedor antes de chamar `Initialize`. Além disso, as conexões estabelecidas com um valor de prompt diferente de DBPROMPT_NOPROMPT não são agrupadas. No entanto, a cadeia de inicialização recuperada de uma conexão estabelecida por meio de prompt pode ser usada para estabelecer conexões adicionais em pool com a mesma fonte de dados.

Alguns provedores devem fazer uma conexão separada para cada sessão. Essas conexões adicionais devem ser inscritos separadamente na transação distribuída, se houver uma. O OLE DB Services armazena em cache e reutiliza uma única sessão por fonte de dados, mas se o aplicativo solicitar mais de uma sessão por vez de uma única fonte de dados, o provedor poderá acabar fazendo conexões adicionais e fazendo informações de transações adicionais que Não está em pool. É mais eficiente criar uma fonte de dados separada para cada sessão em um ambiente em pool do que criar várias sessões de uma única fonte de dados.

Por fim, como o ADO usa automaticamente os serviços de OLE DB, você pode usar o ADO para estabelecer conexões e o pooling e a inscrição ocorrem automaticamente.

## <a name="see-also"></a>Confira também

[Pooling de recursos e serviços do OLE DB](../../data/oledb/ole-db-resource-pooling-and-services.md)
