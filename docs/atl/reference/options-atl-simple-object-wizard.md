---
title: Opções, o Assistente de objeto simples de ATL | Microsoft Docs
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
ms.openlocfilehash: ffc38f5359b68b90f91a2643e1fbaa743a94e559
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32364135"
---
# <a name="options-atl-simple-object-wizard"></a>Opções de Assistente de objeto simples de ATL
Use esta página do Assistente de objeto simples de ATL para maior eficiência e suporte de erro para o objeto de design.  
  
 Para obter mais informações sobre projetos ATL e classes ATL COM, consulte [componentes de área de trabalho do ATL COM](../../atl/atl-com-desktop-components.md).  
  
 **Modelo de Threading**  
 Indica o método de gerenciamento de threads. Por padrão, o projeto usa **Apartment** threading.  
  
 Consulte [especificando o modelo de Threading do projeto](../../atl/specifying-the-threading-model-for-a-project-atl.md) para obter mais informações.  
  
|Opção|Descrição|  
|------------|-----------------|  
|`Single`|Especifica que o objeto sempre é executado no thread COM primário. Consulte [single-threaded Apartments](http://msdn.microsoft.com/library/windows/desktop/ms680112) e [InprocServer32](http://msdn.microsoft.com/library/windows/desktop/ms682390) para obter mais informações.|  
|**Apartment**|Especifica que o objeto usa apartment threading. Apartment do thread equivalente a uma única. Cada objeto de um componente de apartment-threaded é atribuído um compartimento para seu thread, durante a vida útil do objeto; No entanto, vários threads podem ser usados para vários objetos. Cada compartimento estiver associado a um segmento específico e tem um bombeamento de mensagens do Windows (padrão).<br /><br /> Consulte [single-threaded Apartments](http://msdn.microsoft.com/library/windows/desktop/ms680112) para obter mais informações.|  
|**Ambos**|Especifica que o objeto pode usar apartment ou thread livre, dependendo de qual tipo de um thread é criada.|  
|**Livre**|Especifica que o objeto usa thread livre. Thread livre equivale a um modelo de apartment com vários threads. Consulte [threaded Apartments](http://msdn.microsoft.com/library/windows/desktop/ms693421) para obter mais informações.|  
|**Neutral**|Especifica que o objeto segue as diretrizes para threads apartments, mas ela pode ser executada em qualquer tipo de segmento.|  
  
 **Agregação**  
 Indica se o objeto usa [agregação](http://msdn.microsoft.com/library/windows/desktop/ms686558). O objeto de agregação escolhe quais interfaces para expor para clientes e as interfaces são expostas como se o objeto de agregação implementado-los. Os clientes do objeto de agregação se comunicam somente com o objeto de agregação.  
  
|Opção|Descrição|  
|------------|-----------------|  
|Sim|Especifica se o objeto pode ser agregado. O padrão.|  
|Não|Especifica que o objeto não é agregado.|  
|Somente|Especifica que o objeto deve ser agregado.|  
  
 **Interface**  
 Indica o tipo de interface para que o objeto oferece suporte. Por padrão, o objeto oferece suporte a uma interface dupla.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Duplo**|Especifica que o objeto oferece suporte a uma interface dupla (seu vtable tem associação tardia além de funções de interface personalizada `IDispatch` métodos). Permite que ambos os clientes COM e [controladores de automação](../../mfc/automation-clients.md) para acessar o objeto. O padrão.|  
|**Personalizado**|Especifica que o objeto oferece suporte a uma interface personalizada (seu vtable tem funções de interface personalizada). Uma interface personalizada pode ser mais rápida do que uma interface dupla, especialmente em limites de processo.<br /><br /> -   **Automação compatível** controladores de automação permite acessar um objeto que tem o suporte de interface personalizada.|  
  
 **Suporte**  
 Indica suporte adicional para o objeto.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**ISupportErrorInfo**|Cria suporte para o [ISupportErrorInfo](../../atl/reference/isupporterrorinfoimpl-class.md) interface para o objeto possa retornar informações de erro para o cliente.|  
|**Pontos de Conexão**|Permite que os pontos de conexão para seu objeto fazendo a classe do objeto derivam [IConnectionPointContainerImpl](../../atl/reference/iconnectionpointcontainerimpl-class.md).|  
|**Empacotamento de segmentação livre**|Cria um objeto de empacotamento de segmentação livre para marshaling de ponteiros de interface com eficiência entre threads no mesmo processo. Disponível para objetos especificando **ambos** como o modelo de threading.|  
|**IObjectWithSite (suporte de objeto do Internet Explorer)**|Implementa [IObjectWithSiteImpl](../../atl/reference/iobjectwithsiteimpl-class.md), que fornece uma maneira simples para permitir a comunicação entre um objeto e seu site em um contêiner.|  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de objeto simples de ATL](../../atl/reference/atl-simple-object-wizard.md)   
 [Objeto ATL simples](../../atl/reference/adding-an-atl-simple-object.md)   
 [Problemas de Threading do servidor em processo](http://msdn.microsoft.com/library/windows/desktop/ms687205)

