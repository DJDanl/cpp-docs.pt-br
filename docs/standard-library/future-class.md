---
title: Classe future | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- future/std::future
- future/std::future::future
- future/std::future::get
- future/std::future::share
- future/std::future::valid
- future/std::future::wait
- future/std::future::wait_for
- future/std::future::wait_until
dev_langs:
- C++
ms.assetid: 495e82c3-5341-4e37-87dd-b40107fbdfb6
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
helpviewer_keywords:
- std::future [C++]
- std::future [C++], future
- std::future [C++], get
- std::future [C++], share
- std::future [C++], valid
- std::future [C++], wait
- std::future [C++], wait_for
- std::future [C++], wait_until
ms.workload:
- cplusplus
ms.openlocfilehash: f54b265e98d8375b20ca5b7cf484290083d1d59c
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="future-class"></a>Classe future
Descreve um *objeto de retorno assíncrono*.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class Ty>
class future;
```  
  
## <a name="remarks"></a>Comentários  
 Cada *provedor assíncrono* padrão retorna um objeto cujo tipo é uma instanciação desse modelo. Um objeto `future` fornece apenas o acesso ao provedor assíncrono ao qual está associado. Se precisar de vários objetos de retorno assíncronos associados ao mesmo provedor assíncrono, copie o objeto `future` para um objeto [shared_future](../standard-library/shared-future-class.md).  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[future](#future)|Constrói um objeto `future`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[get](#get)|Recupera o resultado armazenado no estado assíncrono associado.|  
|[share](#share)|Converte o objeto em um `shared_future`.|  
|[valid](#valid)|Especifica se o objeto não está vazio.|  
|[wait](#wait)|Bloqueia o thread atual até que o estado assíncrono associado esteja pronto.|  
|[wait_for](#wait_for)|Bloqueia até que o estado assíncrono associado esteja pronto ou até que o tempo especificado tenha decorrido.|  
|[wait_until](#wait_until)|Bloqueia até que o estado assíncrono associado esteja pronto ou até um ponto no tempo especificado.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[future::operator=](#op_eq)|Transfere o estado assíncrono associado de um objeto especificado.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<futuro >  
  
 **Namespace:** std  
  
##  <a name="future"></a>Construtor future::future  
 Constrói um objeto `future`.  
  
```
future() noexcept;
future(future&& Other) noexcept;
```  
  
### <a name="parameters"></a>Parâmetros  
 `Other`  
 Um objeto `future`.  
  
### <a name="remarks"></a>Comentários  
 O primeiro construtor cria um objeto `future` que não tem nenhum estado assíncrono associado.  
  
 O segundo construtor cria um objeto `future` e transfere o estado assíncrono associado de `Other`. `Other` não tem mais um estado assíncrono associado.  
  
##  <a name="get"></a>  future::get  
 Recupera o resultado armazenado no estado assíncrono associado.  
  
```
Ty get();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se o resultado for uma exceção, o método a gerará novamente. Caso contrário, o resultado será retornado.  
  
### <a name="remarks"></a>Comentários  
 Antes de recuperar o resultado, este método bloqueia o thread atual até que o estado assíncrono associado esteja pronto.  
  
 Para a especialização parcial `future<Ty&>`, o valor armazenado será efetivamente uma referência ao objeto que foi passado para o provedor assíncrono como o valor retornado.  
  
 Como não existe nenhum valor armazenado para a especialização `future<void>`, o método retorna `void`.  
  
 Em outras especializações, o método move seu valor retornado do valor armazenado. Portanto, chame este método apenas uma vez.  
  
##  <a name="op_eq"></a>  future::operator=  
 Transfere o estado assíncrono associado de um objeto especificado.  
  
```
future& operator=(future&& Right) noexcept;
```  
  
### <a name="parameters"></a>Parâmetros  
 `Right`  
 Um objeto `future`.  
  
### <a name="return-value"></a>Valor de retorno  
 `*this`  
  
### <a name="remarks"></a>Comentários  
 Após a transferência, `Right` não tem mais um estado assíncrono associado.  
  
##  <a name="share"></a>  future::share  
 Converte o objeto em um objeto [shared_future](../standard-library/shared-future-class.md).  
  
```
shared_future<Ty> share();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `shared_future(move(*this))`  
  
##  <a name="valid"></a>  future::valid  
 Especifica se o objeto tem um estado assíncrono associado.  
  
```
bool valid() noexcept;
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se o objeto tiver um estado assíncrono associado; caso contrário, `false`.  
  
##  <a name="wait"></a>  future::wait  
 Bloqueia o thread atual até que o estado assíncrono associado esteja *pronto*.  
  
```cpp  
void wait() const;
```  
  
### <a name="remarks"></a>Comentários  
 Um estado assíncrono associado ficará *pronto* somente se seu provedor assíncrono tiver armazenado um valor retornado ou armazenado uma exceção.  
  
##  <a name="wait_for"></a>  future::wait_for  
 Bloqueia o thread atual até que o estado assíncrono associado esteja *pronto* ou até que o intervalo de tempo especificado tenha decorrido.  
  
```
template <class Rep, class Period>
future_status wait_for(const chrono::duration<Rep, Period>& Rel_time) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `Rel_time`  
 Um objeto [chrono::duration](../standard-library/duration-class.md) que especifica um intervalo de tempo máximo durante o qual o thread fica bloqueado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um [future_status](../standard-library/future-enums.md#future_status) que indica o motivo do retorno.  
  
### <a name="remarks"></a>Comentários  
 Um estado assíncrono associado ficará pronto somente se seu provedor assíncrono tiver armazenado um valor retornado ou armazenado uma exceção.  
  
##  <a name="wait_until"></a>  future::wait_until  
 Bloqueia o thread atual até que o estado assíncrono associado esteja *pronto* ou após um determinado ponto no tempo.  
  
```cpp  
template <class Clock, class Duration>
future_status wait_until(const chrono::time_point<Clock, Duration>& Abs_time) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `Abs_time`  
 Um objeto [chrono::time_point](../standard-library/time-point-class.md) que especifica um tempo após o qual o thread pode ser desbloqueado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um [future_status](../standard-library/future-enums.md#future_status) que indica o motivo do retorno.  
  
### <a name="remarks"></a>Comentários  
 Um estado assíncrono associado ficará *pronto* somente se seu provedor assíncrono tiver armazenado um valor retornado ou armazenado uma exceção.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\<future>](../standard-library/future.md)



