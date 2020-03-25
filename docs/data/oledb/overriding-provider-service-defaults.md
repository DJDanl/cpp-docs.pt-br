---
title: Substituindo padrões de serviço do fornecedor
ms.date: 10/29/2018
helpviewer_keywords:
- service providers [OLE DB]
- OLE DB services [OLE DB], overriding defaults
ms.assetid: 08e366c0-74d8-463b-93a6-d58a8dc195f8
ms.openlocfilehash: 4cf3ad1064627f64315822a5045642aa50330d10
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80209762"
---
# <a name="overriding-provider-service-defaults"></a>Substituindo padrões de serviço do fornecedor

O valor do registro do provedor para OLEDB_SERVICES é retornado como o valor padrão para a propriedade de inicialização [DBPROP_INIT_OLEDBSERVICES](/previous-versions/windows/desktop/ms716898(v=vs.85)) no objeto de fonte de dados.

Contanto que a entrada do registro exista, os objetos do provedor serão agregados. O usuário pode substituir a configuração padrão do provedor por serviços habilitados definindo a propriedade DBPROP_INIT_OLEDBSERVICES antes da inicialização. Para habilitar ou desabilitar um serviço específico, o usuário Obtém o valor atual da propriedade DBPROP_INIT_OLEDBSERVICES, define ou limpa o bit para que a propriedade específica seja habilitada ou desabilitada e redefine a propriedade. DBPROP_INIT_OLEDBSERVICES pode ser definido diretamente no OLE DB ou na cadeia de conexão passada para ADO ou `IDataInitialize::GetDatasource`. Os valores correspondentes para habilitar/desabilitar serviços individuais são listados na tabela a seguir.

|Serviços padrão habilitados|DBPROP_INIT_OLEDBSERVICES valor da propriedade|Valor na cadeia de conexão|
|------------------------------|------------------------------------------------|--------------------------------|
|Todos os serviços (padrão)|DBPROPVAL_OS_ENABLEALL|"Serviços OLE DBs =-1;"|
|Todos, exceto pooling e autoinscrição|`DBPROPVAL_OS_ENABLEALL &`<br /><br /> `~DBPROPVAL_OS_RESOURCEPOOLING &`<br /><br /> `~DBPROPVAL_OS_TXNENLISTMENT`|"Serviços OLE DBs =-4;"|
|Todos, exceto o cursor do cliente|`DBPROPVAL_OS_ENABLEALL &`<br /><br /> `~DBPROPVAL_OS_CLIENTCURSOR`|"Serviços OLE DBs =-5;"|
|Todos, exceto pooling, inscrição e cursor do cliente|`DBPROPVAL_OS_ENABLEALL &`<br /><br /> `~DBPROPVAL_OS_TXNENLISTMENT &`<br /><br /> `~DBPROPVAL_OS_CLIENTCURSOR`|"Serviços OLE DBs =-7;"|
|Nenhum serviço|`~DBPROPVAL_OS_ENABLEALL`|"Serviços OLE DBs = 0;"|

Se a entrada do registro não existir para o provedor, os gerenciadores de componentes não coletarão os objetos do provedor. Nenhum serviço será ativado, mesmo que solicitado explicitamente pelo usuário.

## <a name="see-also"></a>Confira também

[Pool de recursos](/previous-versions/windows/desktop/ms713655(v=vs.85))<br/>
[Como os consumidores usam o pool de recursos](/previous-versions/windows/desktop/ms715907(v=vs.85))<br/>
[Como os provedores funcionam com eficiência com o pool de recursos](/previous-versions/windows/desktop/ms714906(v=vs.85))<br/>
[Habilitando e desabilitando serviços do OLE DB](../../data/oledb/enabling-and-disabling-ole-db-services.md)<br/>
