---
title: Opções, o Assistente de componente de página Active Server ATL | Microsoft Docs
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
ms.openlocfilehash: 31549c812b4f523cb8026a0d0b15ae60e31cd1f8
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32364533"
---
# <a name="options-atl-active-server-page-component-wizard"></a>Opções de Assistente de componente de página Active Server ATL
Use esta página do Assistente de componente do ATL Active Server página projetar para maior eficiência e suporte de erro para o objeto.  
  
 Para obter mais informações sobre projetos ATL e classes ATL COM, consulte [componentes de área de trabalho do ATL COM](../../atl/atl-com-desktop-components.md).  
  
 **Modelo de Threading**  
 Indica o método de gerenciamento de threads. Por padrão, o projeto usa **Apartment** threading.  
  
 Consulte [especificando o modelo de Threading do projeto](../../atl/specifying-the-threading-model-for-a-project-atl.md) para obter mais informações.  
  
|Opção|Descrição|  
|------------|-----------------|  
|`Single`|Especifica que o objeto usa o modelo de threading único. O modelo de threading único, um objeto sempre é executado no thread COM primário. Consulte [single-threaded Apartments](http://msdn.microsoft.com/library/windows/desktop/ms680112) e [InprocServer32](http://msdn.microsoft.com/library/windows/desktop/ms682390) para obter mais informações.|  
|**Apartment**|Especifica que o objeto usa apartment threading. Apartment do thread equivalente a uma única. Cada objeto de um componente de apartment-threaded é atribuído um compartimento para seu thread, durante a vida útil do objeto; No entanto, vários threads podem ser usados para vários objetos. Cada compartimento estiver associado a um segmento específico e tem um bombeamento de mensagens do Windows (padrão).<br /><br /> Consulte [single-threaded Apartments](http://msdn.microsoft.com/library/windows/desktop/ms680112) para obter mais informações.|  
|**Ambos**|Especifica que o objeto pode usar apartment ou thread livre, dependendo de qual tipo de um thread é criada.|  
|**Livre**|Especifica que o objeto usa thread livre. Thread livre equivale a um modelo de apartment com vários threads. Consulte [threaded Apartments](http://msdn.microsoft.com/library/windows/desktop/ms693421) para obter mais informações.|  
|**Neutral**|Especifica que o objeto segue as diretrizes para threads apartments, mas ela pode ser executada em qualquer tipo de segmento.|  
  
 **Agregação**  
 Indica se o objeto usa [agregação](http://msdn.microsoft.com/library/windows/desktop/ms686558). O objeto de agregação escolhe quais interfaces para expor para clientes e as interfaces são expostas como se o objeto de agregação implementado-los. Os clientes do objeto de agregação se comunicam somente com o objeto de agregação.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Sim**|Especifica se o objeto pode ser agregado. O padrão.|  
|**No**|Especifica que o objeto não é agregado.|  
|**Only**|Especifica que o objeto deve ser agregado.|  
  
 **Suporte**  
 (Descrição do elemento a ser adicionado)  
  
|Opção|Descrição|  
|------------|-----------------|  
|**ISupportErrorInfo**|Cria suporte para o [ISupportErrorInfo](../../atl/reference/isupporterrorinfoimpl-class.md) interface para o objeto possa retornar informações de erro para o cliente.|  
|**Pontos de Conexão**|Permite que os pontos de conexão para seu objeto fazendo a classe do objeto derivam [IConnectionPointContainerImpl](../../atl/reference/iconnectionpointcontainerimpl-class.md).|  
|**Empacotamento de segmentação livre**|Cria um objeto de empacotamento de segmentação livre para marshaling de ponteiros de interface com eficiência entre threads no mesmo processo. Disponível para o objeto especificando o **ambos** ou **livre** como o modelo de threading.|  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de componente de página Active Server ATL](../../atl/reference/atl-active-server-page-component-wizard.md)   
 [Componente de página de servidor ativo do ATL](../../atl/reference/adding-an-atl-active-server-page-component.md)

