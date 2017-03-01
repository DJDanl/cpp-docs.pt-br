---
title: "Funções de &lt;thread&gt; | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: bb1aa1ef-fe3f-4e2c-8b6e-e22dbf2f5a19
caps.latest.revision: 12
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: de302b9a2d971b2a39d4ce775799f27dd7244a5c
ms.lasthandoff: 02/25/2017

---
# <a name="ltthreadgt-functions"></a>Funções &lt;thread&gt;
||||  
|-|-|-|  
|[get_id](#get_id_function)|[sleep_for](#sleep_for_function)|[sleep_until](#sleep_until_function)|  
|[swap](#swap_function)|[yield](#yield_function)|  
  
##  <a name="a-namegetidfunctiona--getid"></a><a name="get_id_function"></a>  get_id  
 Identifica exclusivamente o thread atual de execução.  
  
```  
thread::id this_thread::get_id() noexcept;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um objeto do tipo [thread::id](../standard-library/thread-class.md) que identifica exclusivamente o thread de execução atual.  
  
##  <a name="a-namesleepforfunctiona--sleepfor"></a><a name="sleep_for_function"></a>  sleep_for  
 Bloqueia o thread de chamada.  
  
```  
template <class Rep,  
class Period>  
inline void sleep_for(const chrono::duration<Rep, Period>& Rel_time);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Rel_time`  
 O objeto [duration](../standard-library/duration-class.md) que especifica um intervalo de tempo.  
  
### <a name="remarks"></a>Comentários  
 A função bloqueia o thread de chamada durante, pelo menos, o tempo especificado por `Rel_time`. Essa função não gera exceções.  
  
##  <a name="a-namesleepuntilfunctiona--sleepuntil"></a><a name="sleep_until_function"></a>  sleep_until  
 Bloqueia o thread de chamada, pelo menos, até o tempo especificado.  
  
```  
template <class Clock, class Duration>  
void sleep_until(const chrono::time_point<Clock, Duration>& Abs_time);

void sleep_until(const xtime *Abs_time);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Abs_time`  
 Representa um ponto no tempo.  
  
### <a name="remarks"></a>Comentários  
 Essa função não gera exceções.  
  
##  <a name="a-nameswapfunctiona--swap"></a><a name="swap_function"></a>  swap  
 Troca os estados de dois objetos `thread`.  
  
```  
void swap(thread& Left, thread& Right) noexcept;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `Left`  
 O objeto `thread` à esquerda.  
  
 `Right`  
 O objeto `thread` à direita.  
  
### <a name="remarks"></a>Comentários  
 A função chama `Left.swap(Right)`.  
  
##  <a name="a-nameyieldfunctiona--yield"></a><a name="yield_function"></a>  yield  
 Sinaliza ao sistema operacional para executar outros threads, mesmo se o thread atual continuar normalmente em execução.  
  
```  
inline void yield() noexcept;  
```  
  
## <a name="see-also"></a>Consulte também  
 [\<thread>](../standard-library/thread.md)


