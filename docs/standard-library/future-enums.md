---
title: "Enumerações &lt;future&gt; | Microsoft Docs"
ms.custom: ""
ms.date: "11/04/2016"
ms.reviewer: ""
ms.suite: ""
ms.tgt_pltfrm: ""
ms.topic: "article"
ms.assetid: 8c675645-db47-4cab-bc0e-7b87f8a302df
caps.latest.revision: 11
manager: "ghogen"
---
# <a name="ltfuturegt-enums"></a>Enumerações &lt;future&gt;
||||  
|-|-|-|  
|[Enumeração future_errc](#future_errc_enumeration)|[Enumeração future_status](#future_status_enumeration)|[Enumeração launch](#launch_enumeration)|  
  
##  <a name="a-namefutureerrcenumerationa--futureerrc-enumeration"></a><a name="future_errc_enumeration"></a>  Enumeração future_errc  
 Fornece nomes simbólicos para todos os erros relatados pela classe [future_error](../standard-library/future-error-class.md).  
  
class future_errc { broken_promise, future_already_retrieved, promise_already_satisfied, no_state };  
  
##  <a name="a-namefuturestatusenumerationa--futurestatus-enumeration"></a><a name="future_status_enumeration"></a> Enumeração future_status  
 Fornece nomes simbólicos para os motivos que uma função de espera temporizada pode retornar.  
  
```
enum future_status{    ready,
    timeout,
 deferred};
```  
  
##  <a name="a-namelaunchenumerationa--launch-enumeration"></a><a name="launch_enumeration"></a>  Enumeração launch  
 Representa um tipo de bitmask que descreve os modos possíveis para a função de modelo [async](../standard-library/future-functions.md#async_function).  
  
class launch{ async, deferred };  
  
## <a name="see-also"></a>Consulte também  
 [\<future>](../standard-library/future.md)



