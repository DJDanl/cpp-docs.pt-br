---
title: Opções, ATL Simple Object Wizard | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- vc.codewiz.class.atl.simple.options
dev_langs:
- C++
helpviewer_keywords:
- ATL Simple Object Wizard, options
ms.assetid: 125fe179-942d-4181-8b82-33e92e1fd779
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 548b75a3cee974538450534e25a091c56ae35014
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45707415"
---
# <a name="options-atl-simple-object-wizard"></a>Opções, ATL Simple Object Wizard

Use esta página do ATL Simple Object Wizard para projetar para maior eficiência e o suporte para o objeto de erro.

Para obter mais informações sobre projetos ATL e classes COM da ATL, consulte [componentes de área de trabalho COM ATL](../../atl/atl-com-desktop-components.md).

- **Modelo de Threading**

   Indica o método para o gerenciamento de threads. Por padrão, o projeto utiliza **Apartment** threading.

   Ver [especificando o modelo de Threading do projeto](../../atl/specifying-the-threading-model-for-a-project-atl.md) para obter mais informações.

   |Opção|Descrição|
   |------------|-----------------|
   |**Simples**|Especifica que o objeto sempre é executado no thread COM primário. Ver [single-threaded Apartments](/windows/desktop/com/single-threaded-apartments) e [InprocServer32](/windows/desktop/com/inprocserver32) para obter mais informações.|
   |**Apartment**|Especifica que o objeto usa apartamento de threading. Apartment equivalente a único thread. Cada objeto de um componente do apartment-threaded é atribuído um apartamento de thread, durante a vida útil do objeto; No entanto, vários threads podem ser usados para vários objetos. Cada compartimento estiver associado a um thread específico e tem uma bomba de mensagem do Windows (padrão).<br /><br /> Ver [single-threaded Apartments](/windows/desktop/com/single-threaded-apartments) para obter mais informações.|
   |**Ambos**|Especifica que o objeto pode usar apartment ou threading livre, dependendo de qual tipo de um thread é criada.|
   |**livre**|Especifica que o objeto usa threading livre. Threading livre é equivalente a um modelo de apartment com vários threads. Ver [multi-threaded Apartments](/windows/desktop/com/multithreaded-apartments) para obter mais informações.|
   |**Neutral**|Especifica que o objeto segue as diretrizes para apartments de vários threads, mas ela pode ser executada em qualquer tipo de thread.|

- **Agregação**

   Indica se o objeto usa [agregação](/windows/desktop/com/aggregation). O objeto agregado escolhe quais interfaces para expor para clientes e as interfaces são expostas como se o objeto agregado implementada-los. Os clientes do objeto agregado se comunicam somente com o objeto agregado.

   |Opção|Descrição|
   |------------|-----------------|
   |**Sim**|Especifica se o objeto pode ser agregado. O padrão.|
   |**No**|Especifica que o objeto não é agregado.|
   |**Only**|Especifica que o objeto deve ser agregado.|

- **Interface**

   Indica o tipo de interface que o objeto dá suporte. Por padrão, o objeto dá suporte a uma interface dupla.

   |Opção|Descrição|
   |------------|-----------------|
   |**Duplo**|Especifica que o objeto dá suporte a uma interface dupla (seu vtable tem funções de interface personalizados além de associação tardia `IDispatch` métodos). Permite que ambos os clientes COM e [controladores de automação](../../mfc/automation-clients.md) para acessar o objeto. O padrão.|
   |**Personalizado**|Especifica que o objeto dá suporte a uma interface personalizada (seu vtable tem funções de interface personalizada). Uma interface personalizada pode ser mais rápida do que uma interface dupla, especialmente entre os limites do processo.<br /><br /> -   **Automação compatível** controladores de automação permite acessar um objeto que tem o suporte de interface personalizada.|

- **Suporte**

   Indica suporte adicional para o objeto.

   |Opção|Descrição|
   |------------|-----------------|
   |**ISupportErrorInfo**|Cria o suporte para o [ISupportErrorInfo](../../atl/reference/isupporterrorinfoimpl-class.md) de interface para que o objeto pode retornar informações de erro para o cliente.|
   |**Pontos de Conexão**|Permite que os pontos de conexão para seu objeto, fazendo a classe do seu objeto derivam [IConnectionPointContainerImpl](../../atl/reference/iconnectionpointcontainerimpl-class.md).|
   |**Marshaler de thread livre**|Cria um objeto livre de marshaler para marshaling de ponteiros de interface com eficiência entre os threads no mesmo processo. Disponível para o objeto especificando **ambos** como o modelo de threading.|
   |**IObjectWithSite** (suporte de objeto do IE)|Implementa [IObjectWithSiteImpl](../../atl/reference/iobjectwithsiteimpl-class.md), que fornece uma maneira simple para permitir a comunicação entre um objeto e seu site em um contêiner.|

## <a name="see-also"></a>Consulte também

[ATL Simple Object Wizard](../../atl/reference/atl-simple-object-wizard.md)   
[Objeto simples da ATL](../../atl/reference/adding-an-atl-simple-object.md)   
[Problemas de Threading do servidor em processo](/windows/desktop/com/in-process-server-threading-issues)

