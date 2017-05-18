---
title: Classe completion_future | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- completion_future
- AMPRT/completion_future
- AMPRT/Concurrency::completion_future::completion_future
- AMPRT/Concurrency::completion_future::get
- AMPRT/Concurrency::completion_future::then
- AMPRT/Concurrency::completion_future::to_task
- AMPRT/Concurrency::completion_future::valid
- AMPRT/Concurrency::completion_future::wait
- AMPRT/Concurrency::completion_future::wait_for
- AMPRT/Concurrency::completion_future::wait_until
dev_langs:
- C++
ms.assetid: 1303c62e-546d-4b02-a578-251ed3fc0b6b
caps.latest.revision: 8
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 5faef5bd1be6cc02d6614a6f6193c74167a8ff23
ms.openlocfilehash: 1c6d8e880fbdb784b22b1e9c879473efa7bc9802
ms.contentlocale: pt-br
ms.lasthandoff: 03/17/2017

---
# <a name="completionfuture-class"></a>Classe completion_future
Representa um futuro correspondente a uma operação assíncrona de C++ AMP.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
class completion_future;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor completion_future](#ctor)|Inicializa uma nova instância da classe `completion_future`.|  
|[~ completion_future destruidor](#dtor)|Destrói o `completion_future` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[get](#get)|Aguarda até que a operação assíncrona associada seja concluída.|  
|[em seguida](#then)|Cadeias de um objeto de função de retorno de chamada para o `completion_future` objeto a ser executado quando a operação assíncrona associada finaliza a execução.|  
|[to_task](#to_task)|Retorna um `task` objeto correspondente para a operação assíncrona associada.|  
|[válido](#valid)|Obtém um valor booliano que indica se o objeto está associado uma operação assíncrona.|  
|[Aguarde](#wait)|Bloqueia até que a operação assíncrona associada é concluída.|  
|[wait_for](#wait_for)|Bloqueia até que a operação assíncrona associada seja concluída ou o tempo especificado por `_Rel_time` tiver decorrido.|  
|[wait_until](#wait_until)|Bloqueia até que a operação assíncrona associada seja concluída ou até que a hora atual excede o valor especificado pelo `_Abs_time`.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operador std::shared_future\<void >](#operator_shared_future)|Converte implicitamente o `completion_future` o objeto para um `std::shared_future` objeto.|  
|[operator=](#operator_eq)|Copia o conteúdo especificado `completion_future` deste objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `completion_future`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amprt.h  
  
 **Namespace:** simultaneidade  


## <a name="ctor"></a>completion_future 

Inicializa uma nova instância da classe `completion_future`.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
completion_future();  
  
completion_future(  
    const completion_future& _Other );  
  
completion_future(  
    completion_future&& _Other );  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `completion_future` objeto para copiar ou mover.  
  
### <a name="overloads-list"></a>Lista de sobrecargas  
  
|Nome|Descrição|  
|----------|-----------------|  
|`completion_future();`|Inicializa uma nova instância de `completion_future` classe|  
|`completion_future(const completion_future& _Other);`|Inicializa uma nova instância de `completion_future` classe copiando um construtor.|  
|`completion_future(completion_future&& _Other);`|Inicializa uma nova instância de `completion_future` classe movendo um construtor.|  
  
## <a name="get"></a>Obter 

Aguarda até que a operação assíncrona associada seja concluída. Lança a exceção armazenada se um foi encontrado durante a operação assíncrona.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
void get() const;  
```  
  
## <a name="operator_shared_future"></a>operador std::shared_future<void> 

Converte implicitamente o `completion_future` o objeto para um `std::shared_future` objeto.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
operator std::shared_future<void>() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um objeto `std::shared_future`.  
  
## <a name="operator_eq"></a>operador = 

Copia o conteúdo especificado `completion_future` deste objeto.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
completion_future&  operator= (const completion_future& _Other );    
completion_future&  operator= (completion_future&& _Other );  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O objeto copiar de.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a esta `completion_future` objeto.  
  
## <a name="overloads-list"></a>Lista de sobrecargas  
  
|Nome|Descrição|  
|----------|-----------------|  
|`completion_future& operator=(const completion_future& _Other);`|Copia o conteúdo especificado `completion_future` objeto a este, usando uma cópia em profundidade.|  
|`completion_future& operator=(completion_future&& _Other);`|Copia o conteúdo especificado `completion_future` objeto a este, usando uma atribuição de movimentação.|  
  
## <a name="then"></a>em seguida 

Cadeias de um objeto de função de retorno de chamada para o `completion_future` objeto a ser executado quando a operação assíncrona associada finaliza a execução.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
template <typename _Functor>  
void then(const _Functor & _Func ) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Functor`  
 Functor o retorno de chamada.  
  
 `_Func`  
 O objeto de função de retorno de chamada.  
  
## <a name="to_task"></a>to_task 

Retorna um `task` objeto correspondente para a operação assíncrona associada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
concurrency::task<void> to_task() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `task` objeto correspondente para a operação assíncrona associada.  
  
## <a name="valid"></a>válido 

Obtém um valor booliano que indica se o objeto está associado uma operação assíncrona.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
bool valid() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o objeto está associado uma operação assíncrona; Caso contrário, `false`.  
  
## <a name="wait"></a>Aguarde 

Bloqueia até que a operação assíncrona associada é concluída.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
void wait() const;  
```  
  
## <a name="wait_for"></a>wait_for 

Bloqueia até que a operação assíncrona associada seja concluída ou o tempo especificado pelo `_Rel_time` tiver decorrido.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
template <  
    class _Rep,  
    class _Period  
>  
std::future_status::future_status wait_for(  
    const std::chrono::duration< _Rep, _Period>& _Rel_time ) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Rep`  
 Um tipo aritmético que representa o número de tiques.  
  
 `_Period`  
 Um std::ratio que representa o número de segundos decorridos por tique.  
  
 `_Rel_time`  
 O tempo máximo de espera para a operação ser concluída.  
  
### <a name="return-value"></a>Valor de retorno  
 Devoluções:  
  
-   `std::future_status::deferred`Se a operação assíncrona associada não está em execução.  
  
-   `std::future_status::ready`Se a operação assíncrona associada é concluída.  
  
-   `std::future_status::timeout`Se o período de tempo tiver decorrido.  
  
## <a name="wait_until"></a>wait_until 

Bloqueia até que a operação assíncrona associada seja concluída ou até que a hora atual excede o valor especificado pelo `_Abs_time`.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
template <  
    class _Clock,  
    class _Duration  
>  
std::future_status::future_status wait_until(  
    const std::chrono::time_point< _Clock, _Duration>& _Abs_time ) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Clock`  
 O relógio no qual este ponto de tempo é medido.  
  
 `_Duration`  
 O intervalo de tempo desde o início do `_Clock`da época, após o qual a função atingirá o tempo limite.  
  
 `_Abs_time`  
 O ponto no tempo após o qual a função será o tempo limite.  
  
### <a name="return-value"></a>Valor de retorno  
 Devoluções:  
  
1.  `std::future_status::deferred`Se a operação assíncrona associada não está em execução.  
  
2.  `std::future_status::ready`Se a operação assíncrona associada é concluída.  
  
3.  `std::future_status::timeout`Se o período de tempo especificado tiver decorrido.  
  
## <a name="dtor"></a>~ completion_future 

Destrói o `completion_future` objeto.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
~completion_future();  
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)

