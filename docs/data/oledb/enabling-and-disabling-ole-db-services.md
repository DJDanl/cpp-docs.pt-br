---
title: Habilitando e desabilitando serviços de banco de dados OLE
ms.date: 10/29/2018
helpviewer_keywords:
- OLE DB services [OLE DB], enabling and disabling
- service providers [OLE DB]
ms.assetid: 445f97eb-32a8-41c2-ad26-1169f78a074f
ms.openlocfilehash: df17a55950b03d4d63dea2199e3bc19bedb8a7e3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62175336"
---
# <a name="enabling-and-disabling-ole-db-services"></a>Habilitando e desabilitando serviços de banco de dados OLE

O Gerenciador de componentes de serviço do OLE DB compara as propriedades especificadas pelo consumidor para as propriedades com suporte pelo provedor para determinar se os componentes de serviço individual pode ser usados para satisfazer a funcionalidade estendida solicitada pelo consumidor. Por exemplo, se um aplicativo solicita um cursor rolável e o provedor dá suporte apenas a um cursor de somente avanço, o Gerenciador de componentes de serviço usa o componente de serviço do mecanismo de Cursor do cliente para fornecer funcionalidade rolável. Se o aplicativo é contar com funcionalidade estendida tem suportada por padrão no conjunto de linhas do provedor e o aplicativo não define explicitamente as propriedades para solicitar que a funcionalidade, a funcionalidade pode não aparecer no conjunto de linhas retornado pelo cliente Mecanismo de cursor. Para ser interoperável, aplicativos sempre devem definir propriedades para solicitar explicitamente a funcionalidade estendida onde for necessário.

Em alguns casos, pode ser necessário desabilitar serviços individuais do OLE DB para funcionar bem com aplicativos existentes que fazem suposições sobre as características de um provedor. Serviços do OLE DB fornecem a capacidade de desabilitar os serviços individuais ou todos os serviços, em uma base de conexão por conexão ou para todos os aplicativos que usam um único provedor.

## <a name="see-also"></a>Consulte também

[Pooling de recursos e serviços do OLE DB](../../data/oledb/ole-db-resource-pooling-and-services.md)