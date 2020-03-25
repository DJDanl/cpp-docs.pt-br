---
title: Pooling de recursos e serviços de banco de dados OLE
ms.date: 10/29/2018
helpviewer_keywords:
- resource pooling [OLE DB], provider requirements
- OLE DB, resource pooling
- service providers [OLE DB]
- OLE DB services [OLE DB], provider requirements
- OLE DB services [OLE DB]
- OLE DB providers, resource pooling
ms.assetid: 360c36e2-25ae-4caf-8ee7-d4a6b6898f68
ms.openlocfilehash: 67eeffff2bf165a5ccbdbaa546ad5b9ca9a57914
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80210022"
---
# <a name="ole-db-resource-pooling-and-services"></a>Pooling de recursos e serviços de banco de dados OLE

Para funcionar bem com o OLE DB pooling ou com qualquer serviço de OLE DB, seu provedor deve dar suporte à agregação de todos os objetos. Isso é um requisito de qualquer OLE DB 1,5 ou provedor posterior. É essencial para aproveitar os serviços. Provedores que não dão suporte à agregação não podem ser agrupados e nenhum serviço adicional é fornecido.

Para serem agrupados, os provedores devem dar suporte ao modelo de thread gratuito. O pool de recursos determina o modelo de thread do provedor de acordo com a propriedade DBPROP_THREADMODEL.

Se o provedor tiver um estado de conexão global que pode ser alterado enquanto a fonte de dados estiver em um estado inicializado, ele deverá dar suporte à nova propriedade DBPROP_RESETDATASOURCE. Essa propriedade é chamada antes de uma conexão ser reutilizada e dá ao provedor a oportunidade de limpar o estado antes do próximo uso. Se o provedor não puder limpar algum estado associado à conexão, ele poderá retornar DBPROPSTATUS_NOTSETTABLE para a propriedade e a conexão não será reutilizada.

Provedores que se conectam a um banco de dados remoto e podem detectar se a conexão pode ser perdida deve dar suporte à propriedade DBPROP_CONNECTIONSTATUS. Essa propriedade fornece aos serviços de OLE DB a capacidade de detectar conexões inativas e garantir que elas não sejam retornadas ao pool.

Por fim, a inscrição de transação automática geralmente não funciona, a menos que seja implementada no mesmo nível em que o pooling ocorre. Provedores que oferecem suporte à inscrição de transação automática devem dar suporte à desabilitação dessa inscrição expondo a propriedade DBPROP_INIT_OLEDBSERVICES e desabilitando a inscrição se a DBPROPVAL_OS_TXNENLISTMENT for desmarcada.

## <a name="see-also"></a>Confira também

[Técnicas de provedor avançadas](../../data/oledb/advanced-provider-techniques.md)
