---
title: Opções, assistente de objeto simples do ATL
ms.date: 11/04/2016
f1_keywords:
- vc.codewiz.class.atl.simple.options
helpviewer_keywords:
- ATL Simple Object Wizard, options
ms.assetid: 125fe179-942d-4181-8b82-33e92e1fd779
ms.openlocfilehash: e92f4909907645fc317590fbcc3601887346c642
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69495167"
---
# <a name="options-atl-simple-object-wizard"></a>Opções, assistente de objeto simples do ATL

Use esta página do assistente de objeto simples do ATL para criar uma maior eficiência e suporte ao erro para o objeto.

Para saber mais sobre projetos da ATL e classes COM da ATL, confira [Componentes de Área de Trabalho COM da ATL](../../atl/atl-com-desktop-components.md).

- **Modelo de threading**

   Indica o método para gerenciar threads. Por padrão, o projeto usa Threading **Apartment** .

   Confira mais informações em [Como especificar o modelo de threading para um projeto](../../atl/specifying-the-threading-model-for-a-project-atl.md).

   |Opção|Descrição|
   |------------|-----------------|
   |**Simples**|Especifica que o objeto sempre é executado no thread COM primário. Consulte Apartments e [InprocServer32](/windows/win32/com/inprocserver32) de [thread único](/windows/win32/com/single-threaded-apartments) para obter mais informações.|
   |**Apartment**|Especifica que o objeto usa segmentação de apartamento. Equivalente a single thread apartment. Cada objeto de um componente Apartment-Threaded é atribuído a um apartamento para seu thread, durante a vida útil do objeto; no entanto, vários threads podem ser usados para vários objetos. Cada Apartment está vinculado a um thread específico e tem uma bomba de mensagem do Windows (padrão).<br /><br /> Consulte [Apartments de thread único](/windows/win32/com/single-threaded-apartments) para obter mais informações.|
   |**Mesmo**|Especifica que o objeto pode usar o Apartment ou o Threading livre, dependendo de qual tipo de um thread é criado.|
   |**Informações**|Especifica que o objeto usa Threading livre. O Threading gratuito é equivalente a um modelo de apartamento multithread. Consulte [Apartments multithread](/windows/win32/com/multithreaded-apartments) para obter mais informações.|
   |**Neutral**|Especifica que o objeto segue as diretrizes para Apartments de vários threads, mas pode ser executado em qualquer tipo de thread.|

- **Agregação**

   Indica se o objeto usa [agregação](/windows/win32/com/aggregation). O objeto Aggregate escolhe quais interfaces serão expostas aos clientes e as interfaces serão expostas como se o objeto agregado os implementasse. Os clientes do objeto de agregação se comunicam somente com o objeto de agregação.

   |Opção|Descrição|
   |------------|-----------------|
   |**Sim**|Especifica que o objeto pode ser agregado. O padrão.|
   |**No**|Especifica que o objeto não é agregado.|
   |**Apenas**|Especifica que o objeto deve ser agregado.|

- **Interface**

   Indica o tipo de interface com a qual o objeto é compatível. Por padrão, o objeto é compatível com uma interface dupla.

   |Opção|Descrição|
   |------------|-----------------|
   |**Dupla**|Especifica que o objeto dá suporte a uma interface dupla (sua vtable tem funções de interface personalizada e `IDispatch` métodos de ligação tardia). Permite que clientes COM e [controladores de automação](../../mfc/automation-clients.md) acessem o objeto. O padrão.|
   |**Personalizado**|Especifica que o objeto é compatível com uma interface personalizada (seu vtable tem funções de interface personalizada). Uma interface personalizada pode ser mais rápida do que uma interface dupla, principalmente entre limites de processo.<br /><br /> - **Compatível com automação** Permite que os controladores de automação acessem um objeto que tem o suporte à interface personalizada.|

- **Suporte**

   Indica suporte adicional para o objeto.

   |Opção|Descrição|
   |------------|-----------------|
   |**ISupportErrorInfo**|Cria suporte para a interface [ISupportErrorInfo](../../atl/reference/isupporterrorinfoimpl-class.md) para que o objeto possa retornar informações do erro para o cliente.|
   |**Pontos de conexão**|Habilita pontos de conexão para o objeto, fazendo com que a classe do objeto derive de [IConnectionPointContainerImpl](../../atl/reference/iconnectionpointcontainerimpl-class.md).|
   |**Marshaler com thread livre**|Cria um objeto de marshaler com thread livre para empacotar ponteiros de interface com eficiência entre threads no mesmo processo. Disponível para o objeto que especifica o modelo de Threading.|
   |**IObjectWithSite** (Suporte a objeto do IE)|Implementa o [IObjectWithSiteImpl](../../atl/reference/iobjectwithsiteimpl-class.md), que fornece uma maneira simples de dar suporte à comunicação entre um objeto e seu site em um contêiner.|

## <a name="see-also"></a>Consulte também

[Assistente de objeto simples da ATL](../../atl/reference/atl-simple-object-wizard.md)<br/>
[Objeto ATL Simples](../../atl/reference/adding-an-atl-simple-object.md)<br/>
[Problemas de Threading do servidor em processo](/windows/win32/com/in-process-server-threading-issues)
