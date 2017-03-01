---
title: Estrutura system_clock | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- chrono/std::chrono::system_clock
dev_langs:
- C++
ms.assetid: a97bd46e-267a-4836-9f7d-af1f664e99ae
caps.latest.revision: 14
author: corob-msft
ms.author: corob
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
ms.openlocfilehash: 883a683e456b00b4a2a80004cb8bb5d72f03a91a
ms.lasthandoff: 02/25/2017

---
# <a name="systemclock-structure"></a>Estrutura system_clock
Representa um *tipo de relógio* baseado no relógio em tempo real do sistema.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
struct system_clock;  
```  
  
## <a name="remarks"></a>Comentários  
 Um *tipo de relógio* é usado para obter a hora atual como UTC. O tipo incorpora uma instanciação de [duration](../standard-library/duration-class.md) e o modelo de classe [time_point](../standard-library/time-point-class.md) e define uma função membro estática `now()` que retorna a hora.  
  
 Um relógio será *monotônico* se o valor retornado por uma primeira chamada a `now()` for sempre menor ou igual ao valor retornado por uma chamada posterior a `now()`.  
  
 Um relógio será *estável* se ele for *monotônico* e se o tempo entre os tiques do relógio for constante.  
  
 Nessa implementação, um `system_clock` é sinônimo de um `high_resolution_clock`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`system_clock::duration`|Um sinônimo de `duration<rep, period>`.|  
|`system_clock::period`|Um sinônimo do tipo que é usado para representar o período de tiques na instanciação independente de `duration`.|  
|`system_clock::rep`|Um sinônimo do tipo que é usado para representar o número de tiques do relógio na instanciação independente de `duration`.|  
|`system_clock::time_point`|Um sinônimo de `time_point<Clock, duration>`, em que `Clock` é um sinônimo do próprio tipo de relógio ou de outro tipo de relógio que se baseia na mesma época e que tem o mesmo tipo `duration` aninhado.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método system_clock::from_time_t](#system_clock__from_time_t_method)|Estático. Retorna um `time_point` que mais se aproxima de um tempo especificado.|  
|[Método system_clock::now](#system_clock__now_method)|Estático. Retorna a data atual.|  
|[Método system_clock::to_time_t](#system_clock__to_time_t_method)|Estático. Retorna um objeto `time_t` que mais se aproxima de um `time_point` especificado.|  
  
### <a name="public-constants"></a>Constantes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Constante system_clock::is_monotonic](#system_clock__is_monotonic_constant)|Especifica se o tipo de relógio é monotônico.|  
|[Constante system_clock::is_steady](#system_clock__is_steady_constant)|Especifica se o tipo de relógio é estável.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** chrono  
  
 **Namespace:** std::chrono  
  
##  <a name="a-namesystemclockfromtimetmethoda--systemclockfromtimet-method"></a><a name="system_clock__from_time_t_method"></a>  Método system_clock::from_time_t  
 Método estático que retorna um [time_point](../standard-library/time-point-class.md) que mais se aproxima do tempo representado por `Tm`.  
  
```  
static time_point from_time_t(time_t Tm) noexcept;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `Tm`  
 Um objeto [time_t](../c-runtime-library/standard-types.md).  
  
##  <a name="a-namesystemclockismonotonicconstanta--systemclockismonotonic-constant"></a><a name="system_clock__is_monotonic_constant"></a>  Constante system_clock::is_monotonic  
 Valor estático que especifica se o tipo de relógio é monotônico.  
  
```  
static const bool is_monotonic = false;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Nessa implementação, `system_clock::is_monotonic` sempre retorna `false`.  
  
### <a name="remarks"></a>Comentários  
 Um relógio será *monotônico* se o valor retornado por uma primeira chamada a `now()` for sempre menor ou igual ao valor retornado por uma chamada posterior a `now()`.  
  
##  <a name="a-namesystemclockissteadyconstanta--systemclockissteady-constant"></a><a name="system_clock__is_steady_constant"></a>  Constante system_clock::is_steady  
 Valor estático que especifica se o tipo de relógio é *estável*.  
  
```  
static const bool is_steady = false;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Nessa implementação, `system_clock::is_steady` sempre retorna `false`.  
  
### <a name="remarks"></a>Comentários  
 Um relógio será *estável* se ele for [monotônico](#system_clock__is_monotonic_constant) e se o tempo entre os tiques do relógio for constante.  
  
##  <a name="a-namesystemclocknowmethoda--systemclocknow-method"></a><a name="system_clock__now_method"></a>  Método system_clock::now  
 Método estático que retorna a hora atual.  
  
```  
static time_point now() noexcept;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um objeto [time_point](../standard-library/time-point-class.md) que representa a hora atual.  
  
##  <a name="a-namesystemclocktotimetmethoda--systemclocktotimet-method"></a><a name="system_clock__to_time_t_method"></a>  Método system_clock::to_time_t  
 Método estático que retorna um [time_t](../c-runtime-library/standard-types.md) que mais se aproxima do tempo representado por `Time`.  
  
```  
static time_t to_time_t(const time_point& Time) noexcept;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `Time`  
 Um objeto [time_point](../standard-library/time-point-class.md).  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\<chrono>](../standard-library/chrono.md)   
 [Struct steady_clock](../standard-library/steady-clock-struct.md)

