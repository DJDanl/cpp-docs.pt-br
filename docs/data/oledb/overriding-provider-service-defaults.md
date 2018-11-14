---
title: Substituindo padrões de serviço do fornecedor
ms.date: 10/29/2018
helpviewer_keywords:
- service providers [OLE DB]
- OLE DB services [OLE DB], overriding defaults
ms.assetid: 08e366c0-74d8-463b-93a6-d58a8dc195f8
ms.openlocfilehash: 9f845834b844c16bf2820a295768696e8f6a6526
ms.sourcegitcommit: c40469825b6101baac87d43e5f4aed6df6b078f5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2018
ms.locfileid: "51556290"
---
# <a name="overriding-provider-service-defaults"></a>Substituindo padrões de serviço do fornecedor

Valor do registro do provedor para OLEDB_SERVICES é retornado como o valor padrão para o [DBPROP_INIT_OLEDBSERVICES](https://docs.microsoft.com/previous-versions/windows/desktop/ms716898(v=vs.85)) propriedade de inicialização no objeto de fonte de dados.

Desde que exista a entrada do registro, objetos do provedor é agregado. O usuário pode substituir configuração padrão do provedor para serviços habilitados, definindo a propriedade DBPROP_INIT_OLEDBSERVICES antes da inicialização. Para habilitar ou desabilitar um serviço específico, o usuário obtém o valor atual da propriedade DBPROP_INIT_OLEDBSERVICES, define ou limpa o bit para a propriedade específica a ser ativado ou desativado e redefine a propriedade. DBPROP_INIT_OLEDBSERVICES pode ser definido diretamente no OLE DB ou na cadeia de conexão passada para o ADO ou `IDataInitialize::GetDatasource`. Os valores correspondentes para habilitar/desabilitar serviços individuais são listados na tabela a seguir.

|Serviços padrão habilitados|Valor da propriedade DBPROP_INIT_OLEDBSERVICES|Valor na cadeia de caracteres de conexão|
|------------------------------|------------------------------------------------|--------------------------------|
|Todos os serviços (padrão)|DBPROPVAL_OS_ENABLEALL|"Serviços do OLE DB = -1;"|
|Todos, exceto de Pooling e AutoEnlistment|`DBPROPVAL_OS_ENABLEALL &`<br /><br /> `~DBPROPVAL_OS_RESOURCEPOOLING &`<br /><br /> `~DBPROPVAL_OS_TXNENLISTMENT`|"Serviços do OLE DB = -4;"|
|Todos, exceto o Cursor do cliente|`DBPROPVAL_OS_ENABLEALL &`<br /><br /> `~DBPROPVAL_OS_CLIENTCURSOR`|"Serviços do OLE DB = -5;"|
|Todos exceto Pooling, AutoEnlistment e Cursor do cliente|`DBPROPVAL_OS_ENABLEALL &`<br /><br /> `~DBPROPVAL_OS_TXNENLISTMENT &`<br /><br /> `~DBPROPVAL_OS_CLIENTCURSOR`|"Serviços do OLE DB = -7;"|
|Não há serviços|`~DBPROPVAL_OS_ENABLEALL`|"Serviços do OLE DB = 0;"|

Se a entrada do registro não existir para o provedor, os gerentes de componente não coletar objetos do provedor. Nenhum serviço será ativado, mesmo que explicitamente solicitado pelo usuário.

## <a name="see-also"></a>Consulte também

[Pool de recursos](https://docs.microsoft.com/previous-versions/windows/desktop/ms713655(v=vs.85))<br/>
[Como os consumidores usam o pool de recursos](https://docs.microsoft.com/previous-versions/windows/desktop/ms715907(v=vs.85))<br/>
[Como os provedores funcionam com eficiência com o pool de recursos](https://docs.microsoft.com/previous-versions/windows/desktop/ms714906(v=vs.85))<br/>
[Habilitando e desabilitando serviços do OLE DB](../../data/oledb/enabling-and-disabling-ole-db-services.md)<br/>