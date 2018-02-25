---
title: "Funções de &lt;thread&gt; | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- thread/std::get_id
- thread/std::sleep_for
- thread/std::sleep_until
- thread/std::swap
- thread/std::yield
ms.assetid: bb1aa1ef-fe3f-4e2c-8b6e-e22dbf2f5a19
caps.latest.revision: 
manager: ghogen
helpviewer_keywords:
- std::get_id [C++]
- std::sleep_for [C++]
- std::sleep_until [C++]
- std::swap [C++]
- std::yield [C++]
ms.openlocfilehash: 54e4c09c7db5fb29cdfb067b47d8584451277d4a
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="ltthreadgt-functions"></a>Funções &lt;thread&gt;
||||  
|-|-|-|  
|[get_id](#get_id)|[sleep_for](#sleep_for)|[sleep_until](#sleep_until)|  
|[swap](#swap)|[yield](#yield)|  
  
##  <a name="get_id"></a>  get_id  
 Identifica exclusivamente o thread atual de execução.  
  
```  
thread::id this_thread::get_id() noexcept;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um objeto do tipo [thread::id](../standard-library/thread-class.md) que identifica exclusivamente o thread de execução atual.  
  
##  <a name="sleep_for"></a>  sleep_for  
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
  
##  <a name="sleep_until"></a>  sleep_until  
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
  
##  <a name="swap"></a>  swap  
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
  
##  <a name="yield"></a>  yield  
 Sinaliza ao sistema operacional para executar outros threads, mesmo se o thread atual continuar normalmente em execução.  
  
```  
inline void yield() noexcept;  
```  
  
## <a name="see-also"></a>Consulte também  
 [\<thread>](../standard-library/thread.md)

