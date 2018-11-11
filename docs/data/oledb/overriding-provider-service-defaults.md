---
title: Substituindo padrões de serviço do fornecedor
ms.date: 10/29/2018
helpviewer_keywords:
- service providers [OLE DB]
- OLE DB services [OLE DB], overriding defaults
ms.assetid: 08e366c0-74d8-463b-93a6-d58a8dc195f8
ms.openlocfilehash: a9f8eb1c96c40336f39f14fe1a0ee29d60efd003
ms.sourcegitcommit: 943c792fdabf01c98c31465f23949a829eab9aad
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/07/2018
ms.locfileid: "51265211"
---
# <a name="overriding-provider-service-defaults"></a>Substituindo padrões de serviço do fornecedor

Valor do registro do provedor para OLEDB_SERVICES é retornado como o valor padrão para o [DBPROP_INIT_OLEDBSERVICES](/previous-versions/windows/desktop/ms716898) propriedade de inicialização no objeto de fonte de dados.

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

[Pool de recursos](/previous-versions/windows/desktop/ms713655)<br/>
[Como os consumidores usam o pool de recursos](/previous-versions/windows/desktop/ms715907)<br/>
[Como os provedores funcionam com eficiência com o pool de recursos](/previous-versions/windows/desktop/ms714906)<br/>
[Habilitando e desabilitando serviços do OLE DB](../../data/oledb/enabling-and-disabling-ole-db-services.md)<br/>