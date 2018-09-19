---
title: Habilitando e desabilitando serviços do OLE DB | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- OLE DB services [OLE DB], enabling and disabling
- service providers [OLE DB]
ms.assetid: 445f97eb-32a8-41c2-ad26-1169f78a074f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 6edd507edc21d58d17435b1d31d918a965db624a
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46100728"
---
# <a name="enabling-and-disabling-ole-db-services"></a>Habilitando e desabilitando serviços de banco de dados OLE

O Gerenciador de componentes de serviço do OLE DB compara as propriedades especificadas pelo consumidor com suporte pelo provedor para determinar se os componentes de serviço individuais podem ser invocados para atender a funcionalidade estendida solicitada pelo consumidor. Por exemplo, se um aplicativo solicita um cursor rolável e o provedor dá suporte apenas a um cursor de somente avanço, o Gerenciador de componentes de serviço chama o componente de serviço do mecanismo de Cursor do cliente para fornecer a funcionalidade rolável. Se o aplicativo é contar com funcionalidade estendida tem suportada por padrão no conjunto de linhas do provedor e o aplicativo não definir explicitamente as propriedades para solicitar que a funcionalidade, a funcionalidade pode não aparecer no conjunto de linhas retornado pelo cliente Mecanismo de cursor. Para ser interoperável, aplicativos sempre devem definir propriedades para solicitar explicitamente a funcionalidade estendida onde for necessário.  
  
Em alguns casos, pode ser necessário desabilitar serviços individuais do OLE DB para funcionar bem com aplicativos existentes que fazem suposições sobre as características de um provedor. Serviços do OLE DB fornecem a capacidade de desabilitar os serviços individuais ou todos os serviços, em uma base de conexão por conexão ou para todos os aplicativos que usam um único provedor.  
  
## <a name="see-also"></a>Consulte também  

[Pooling de recursos e serviços do OLE DB](../../data/oledb/ole-db-resource-pooling-and-services.md)