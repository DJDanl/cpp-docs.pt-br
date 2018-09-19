---
title: Opções, o Assistente de página componente Active Server ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- vc.codewiz.class.atl.asp.options
dev_langs:
- C++
helpviewer_keywords:
- ATL Active Server Page Component Wizard, options
ms.assetid: 54f34e26-53c7-4456-9675-cb86e356bde0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fda466ad45b5b91f02920d68eef8eab071010830
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46020128"
---
# <a name="options-atl-active-server-page-component-wizard"></a>Opções, Assistente de página componente Active Server ATL

Use esta página do Assistente de componentes do ATL Active Server página projetar para maior eficiência e suporte de erro para o objeto.

Para obter mais informações sobre projetos ATL e classes COM da ATL, consulte [componentes de área de trabalho COM ATL](../../atl/atl-com-desktop-components.md).

- **Modelo de Threading**

   Indica o método para o gerenciamento de threads. Por padrão, o projeto utiliza **Apartment** threading.

   Ver [especificando o modelo de Threading do projeto](../../atl/specifying-the-threading-model-for-a-project-atl.md) para obter mais informações.

   |Opção|Descrição|
   |------------|-----------------|
   |**Simples**|Especifica que o objeto usa o modelo de threading único. O modelo de threading único, um objeto sempre é executado no thread COM primário. Ver [single-threaded Apartments](/windows/desktop/com/single-threaded-apartments) e [InprocServer32](/windows/desktop/com/inprocserver32) para obter mais informações.|
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

- **Suporte**

   Opções adicionais de suporte:

   |Opção|Descrição|
   |------------|-----------------|
   |**ISupportErrorInfo**|Cria o suporte para o [ISupportErrorInfo](../../atl/reference/isupporterrorinfoimpl-class.md) de interface para que o objeto pode retornar informações de erro para o cliente.|
   |**Pontos de Conexão**|Permite que os pontos de conexão para seu objeto, fazendo a classe do seu objeto derivam [IConnectionPointContainerImpl](../../atl/reference/iconnectionpointcontainerimpl-class.md).|
   |**Marshaler de thread livre**|Cria um objeto livre de marshaler para marshaling de ponteiros de interface com eficiência entre os threads no mesmo processo. Disponível para o objeto que especifica um **ambos** ou **gratuito** como o modelo de threading.|

## <a name="see-also"></a>Consulte também

[Assistente do componente Active Server Page da ATL](../../atl/reference/atl-active-server-page-component-wizard.md)<br/>
[Componente de página de servidor ativo do ATL](../../atl/reference/adding-an-atl-active-server-page-component.md)

