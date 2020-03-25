---
title: Habilitando e desabilitando serviços de banco de dados OLE
ms.date: 10/29/2018
helpviewer_keywords:
- OLE DB services [OLE DB], enabling and disabling
- service providers [OLE DB]
ms.assetid: 445f97eb-32a8-41c2-ad26-1169f78a074f
ms.openlocfilehash: 3016126d09b39ec74f4acb758a2176be05052648
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80210958"
---
# <a name="enabling-and-disabling-ole-db-services"></a>Habilitando e desabilitando serviços de banco de dados OLE

O Gerenciador de componentes de serviço OLE DB compara as propriedades especificadas pelo consumidor com as propriedades com suporte do provedor para determinar se os componentes de serviço individuais podem ser usados para satisfazer a funcionalidade estendida solicitada pelo consumidor. Por exemplo, se um aplicativo solicita um cursor rolável e o provedor só dá suporte a um cursor de somente avanço, o Gerenciador de componentes de serviço usa o componente de serviço do mecanismo de cursor do cliente para fornecer a funcionalidade rolável. Se o aplicativo depender da funcionalidade estendida com suporte por padrão no conjunto de linhas do provedor e o aplicativo não definir explicitamente as propriedades para solicitar essa funcionalidade, a funcionalidade poderá não aparecer no conjunto de linhas retornado pelo cliente Mecanismo de cursor. Para ser interoperável, os aplicativos sempre devem definir propriedades para solicitar explicitamente a funcionalidade estendida quando necessário.

Em alguns casos, pode ser necessário desabilitar serviços de OLE DB individuais para funcionar bem com aplicativos existentes que fazem suposições sobre as características de um provedor. Os serviços de OLE DB fornecem a capacidade de desabilitar serviços individuais ou todos os serviços, seja em uma base de conexão por conexão ou para todos os aplicativos que usam um único provedor.

## <a name="see-also"></a>Confira também

[Pooling de recursos e serviços do OLE DB](../../data/oledb/ole-db-resource-pooling-and-services.md)
