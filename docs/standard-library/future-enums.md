---
title: "Enumerações &lt;future&gt; | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- future/std::future_errc
- future/std::future_status
- future/std::launch
ms.assetid: 8c675645-db47-4cab-bc0e-7b87f8a302df
caps.latest.revision: "11"
manager: ghogen
ms.openlocfilehash: 835abafde46858bd108dfa648a246345bd254eaf
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="ltfuturegt-enums"></a>Enumerações &lt;future&gt;
||||  
|-|-|-|  
|[future_errc](#future_errc)|[future_status](#future_status)|[Iniciar](#launch)|  
  
##  <a name="future_errc"></a>  Enumeração future_errc  
 Fornece nomes simbólicos para todos os erros relatados pela classe [future_error](../standard-library/future-error-class.md).  
  
class future_errc { broken_promise, future_already_retrieved, promise_already_satisfied, no_state };  
  
##  <a name="future_status"></a> Enumeração future_status  
 Fornece nomes simbólicos para os motivos que uma função de espera temporizada pode retornar.  
  
```
enum future_status{    ready,
    timeout,
 deferred};
```  
  
##  <a name="launch"></a>  Enumeração launch  
 Representa um tipo de bitmask que descreve os modos possíveis para a função de modelo [async](../standard-library/future-functions.md#async).  
  
class launch{ async, deferred };  
  
## <a name="see-also"></a>Consulte também  
 [\<future>](../standard-library/future.md)



