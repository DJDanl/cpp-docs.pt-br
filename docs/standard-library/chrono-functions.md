---
title: "Funções &lt;chrono&gt; | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- chrono/std::duration_cast
- chrono/std::time_point_cast
ms.assetid: d6800e15-77a1-4df3-900e-d8b2fee190c7
caps.latest.revision: 10
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 65f4e356ad0d46333b0d443d0fd6ac0b9f2b6f58
ms.openlocfilehash: 2df866e0f6fec9833c67e4d4ea405a826996dedf
ms.contentlocale: pt-br
ms.lasthandoff: 10/03/2017

---
# <a name="ltchronogt-functions"></a>Funções &lt;chrono&gt;
||||  
|-|-|-|  
|[duration_cast](#duration_cast)|[time_point_cast](#time_point_cast)|  
  

##  <a name="duration_cast"></a>duration_cast
 Converte um objeto `duration` em um tipo especificado.  
  
```  
template <class To, class Rep, class Period>  
constexpr To duration_cast(const duration<Rep, Period>& Dur);
```  
  
### <a name="return-value"></a>Valor retornado  
 Um objeto `duration` do tipo `To` que representa o intervalo de tempo `Dur`, que será truncado se precisar caber no tipo de destino.  
  
### <a name="remarks"></a>Comentários  
 Se `To` for uma instanciação de `duration`, essa função não participará na resolução de sobrecarga.  
  
##  <a name="time_point_cast"></a>time_point_cast
 Converte um objeto [time_point](../standard-library/time-point-class.md) para um tipo especificado.  
  
```  
template <class To, class Clock, class Duration>  
time_point<Clock, To> time_point_cast(const time_point<Clock, Duration>& Tp);
```  
  
### <a name="return-value"></a>Valor retornado  
 Um objeto `time_point` que tem uma duração do tipo `To`.  
  
### <a name="remarks"></a>Comentários  
 A menos que `To` seja uma instanciação de [duração](../standard-library/duration-class.md), essa função não participará da resolução de sobrecarga.  
  
## <a name="see-also"></a>Consulte também  
 [\<chrono>](../standard-library/chrono.md)


