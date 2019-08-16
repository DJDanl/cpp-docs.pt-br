---
title: Opções, assistente de componente de página de Active Server ATL
ms.date: 11/04/2016
f1_keywords:
- vc.codewiz.class.atl.asp.options
helpviewer_keywords:
- ATL Active Server Page Component Wizard, options
ms.assetid: 54f34e26-53c7-4456-9675-cb86e356bde0
ms.openlocfilehash: c76ab7730256b007b66d54ca6753409926f7ae89
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69495309"
---
# <a name="options-atl-active-server-page-component-wizard"></a>Opções, assistente de componente de página de Active Server ATL

Use esta página do assistente de componente de página de Active Server do ATL para criar uma maior eficiência e suporte ao erro para o objeto.

Para saber mais sobre projetos da ATL e classes COM da ATL, confira [Componentes de Área de Trabalho COM da ATL](../../atl/atl-com-desktop-components.md).

- **Modelo de threading**

   Indica o método para gerenciar threads. Por padrão, o projeto usa Threading **Apartment** .

   Confira mais informações em [Como especificar o modelo de threading para um projeto](../../atl/specifying-the-threading-model-for-a-project-atl.md).

   |Opção|Descrição|
   |------------|-----------------|
   |**Simples**|Especifica que o objeto usa o modelo de Threading único. No modelo de Threading único, um objeto sempre é executado no thread COM primário. Consulte Apartments e [InprocServer32](/windows/win32/com/inprocserver32) de [thread único](/windows/win32/com/single-threaded-apartments) para obter mais informações.|
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

- **Suporte**

   Opções de suporte adicionais:

   |Opção|Descrição|
   |------------|-----------------|
   |**ISupportErrorInfo**|Cria suporte para a interface [ISupportErrorInfo](../../atl/reference/isupporterrorinfoimpl-class.md) para que o objeto possa retornar informações do erro para o cliente.|
   |**Pontos de conexão**|Habilita pontos de conexão para o objeto, fazendo com que a classe do objeto derive de [IConnectionPointContainerImpl](../../atl/reference/iconnectionpointcontainerimpl-class.md).|
   |**Marshaler com thread livre**|Cria um objeto de marshaler com thread livre para empacotar ponteiros de interface com eficiência entre threads no mesmo processo. Disponível para o objeto que especifica **tanto** o quanto o modelo de Threading.|

## <a name="see-also"></a>Consulte também

[Assistente do componente Active Server Page da ATL](../../atl/reference/atl-active-server-page-component-wizard.md)<br/>
[Componente Active Server Page da ATL](../../atl/reference/adding-an-atl-active-server-page-component.md)
