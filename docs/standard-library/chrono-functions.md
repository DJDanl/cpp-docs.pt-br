---
title: "Funções &lt;chrono&gt; | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: d6800e15-77a1-4df3-900e-d8b2fee190c7
caps.latest.revision: 10
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 9824bdc37d1ae2d1d3a8e42c727986fd2a194514
ms.lasthandoff: 02/25/2017

---
# <a name="ltchronogt-functions"></a>Funções &lt;chrono&gt;
||||  
|-|-|-|  
|[Função duration_cast](#duration_cast_function)|[Função time_point_cast](#time_point_cast_function)|  
  

##  <a name="a-namedurationcastfunctiona--durationcast-function"></a><a name="duration_cast_function"></a>  Função duration_cast  
 Converte um objeto `duration` em um tipo especificado.  
  
```  
template <class To, class Rep, class Period>  
constexpr To duration_cast(const duration<Rep, Period>& Dur);
```  
  
### <a name="return-value"></a>Valor retornado  
 Um objeto `duration` do tipo `To` que representa o intervalo de tempo `Dur`, que será truncado se precisar caber no tipo de destino.  
  
### <a name="remarks"></a>Comentários  
 Se `To` for uma instanciação de `duration`, essa função não participará na resolução de sobrecarga.  
  
##  <a name="a-nametimepointcastfunctiona--timepointcast-function"></a><a name="time_point_cast_function"></a>  Função time_point_cast  
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


