---
title: "Opções, o Assistente de componente de página do Active Server ATL | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- vc.codewiz.class.atl.asp.options
dev_langs:
- C++
helpviewer_keywords:
- ATL Active Server Page Component Wizard, options
ms.assetid: 54f34e26-53c7-4456-9675-cb86e356bde0
caps.latest.revision: 12
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 608b7747c70286ed3bf9598036ac672881730815
ms.lasthandoff: 02/25/2017

---
# <a name="options-atl-active-server-page-component-wizard"></a>Opções, Assistente de componente de página de servidor ativo ATL
Use esta página do Assistente de componentes do ATL Active Server página criar para maior eficiência e suporte de erro para o objeto.  
  
 Para obter mais informações sobre projetos ATL e classes ATL COM, consulte [componentes de área de trabalho do ATL COM](../../atl/atl-com-desktop-components.md).  
  
 **Modelo de Threading**  
 Indica o método de gerenciamento de threads. Por padrão, o projeto usa **Apartment** threading.  
  
 Consulte [especificando o modelo de Threading do projeto](../../atl/specifying-the-threading-model-for-a-project-atl.md) para obter mais informações.  
  
|Opção|Descrição|  
|------------|-----------------|  
|`Single`|Especifica que o objeto usa o modelo de threading único. O modelo de threading único, um objeto sempre é executado no thread primário COM. Consulte [single-threaded Apartments](http://msdn.microsoft.com/library/windows/desktop/ms680112) e [InprocServer32](http://msdn.microsoft.com/library/windows/desktop/ms682390) para obter mais informações.|  
|**Apartment**|Especifica que o objeto usa apartment threading. Apartment equivalente a único thread. Cada objeto de um componente apartamento é atribuído um apartamento de seu segmento, durante a vida útil do objeto; No entanto, vários threads podem ser usados para vários objetos. Cada compartimento estiver associado a um thread específico e tem uma bomba de mensagem do Windows (padrão).<br /><br /> Consulte [single-threaded Apartments](http://msdn.microsoft.com/library/windows/desktop/ms680112) para obter mais informações.|  
|**Ambos**|Especifica que o objeto pode usar apartment ou thread livre, dependendo de qual tipo de um thread é criada.|  
|**Livre**|Especifica que o objeto usa thread livre. Thread livre equivale a um modelo de apartment com vários threads. Consulte [multi-threaded Apartments](http://msdn.microsoft.com/library/windows/desktop/ms693421) para obter mais informações.|  
|**Neutro** (apenas Windows 2000)|Especifica que o objeto segue as diretrizes para multi-threaded apartments, mas ela pode ser executada em qualquer tipo de thread.|  
  
 **Agregação**  
 Indica se o objeto usa [agregação](http://msdn.microsoft.com/library/windows/desktop/ms686558). O objeto de agregação escolhe quais interfaces para expor aos clientes e as interfaces são expostas como se o objeto de agregação implementadas. Clientes do objeto agregação se comunicar somente com o objeto de agregação.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Sim**|Especifica se o objeto pode ser agregado. O padrão.|  
|**No**|Especifica que o objeto não é agregado.|  
|**Somente**|Especifica que o objeto deve ser agregado.|  
  
 **Suporte**  
 (Descrição do elemento a ser adicionado)  
  
|Opção|Descrição|  
|------------|-----------------|  
|**ISupportErrorInfo**|Cria o suporte para o [ISupportErrorInfo](../../atl/reference/isupporterrorinfoimpl-class.md) de interface para o objeto possa retornar informações de erro para o cliente.|  
|**Pontos de Conexão**|Permite que os pontos de conexão para o objeto fazendo a classe do objeto derivam [IConnectionPointContainerImpl](../../atl/reference/iconnectionpointcontainerimpl-class.md).|  
|**Empacotamento de segmentação livre**|Cria um objeto de empacotamento de segmentação livre para marshaling de ponteiros de interface com eficiência entre threads no mesmo processo. Disponível para o objeto especificando o **ambos** ou **livre** como o modelo de threading.|  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de componente de página do Active Server ATL](../../atl/reference/atl-active-server-page-component-wizard.md)   
 [Componente de página de servidor ativo do ATL](../../atl/reference/adding-an-atl-active-server-page-component.md)


