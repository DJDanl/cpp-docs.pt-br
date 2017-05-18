---
title: Classe de evento | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- event
- CONCRT/concurrency::event
- CONCRT/concurrency::event::reset
- CONCRT/concurrency::event::set
- CONCRT/concurrency::event::wait
- CONCRT/concurrency::event::wait_for_multiple
- CONCRT/concurrency::event::timeout_infinite
dev_langs:
- C++
helpviewer_keywords:
- event class
ms.assetid: fba35a53-6568-4bfa-9aaf-07c0928cf73d
caps.latest.revision: 22
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
ms.openlocfilehash: f858bfad08ca8d62c42556c54b505908b7122569
ms.contentlocale: pt-br
ms.lasthandoff: 03/17/2017

---
# <a name="event-class"></a>Classe event
Um evento de redefinição manual que reconhece explicitamente o tempo de execução de simultaneidade.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class event;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[~ evento destruidor](#dtor)|Destrói um evento.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[reset](#reset)|Redefine o evento para um estado não-sinalizado.|  
|[set](#set)|Sinaliza o evento.|  
|[Aguarde](#wait)|Aguarda o evento ficar sinalizado.|  
|[wait_for_multiple](#wait_for_multiple)|Aguarda vários eventos ficar sinalizado.|  
  
### <a name="public-constants"></a>Constantes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[timeout_infinite](#timeout_infinite)|Valor que indica que uma espera nunca deve atingir o tempo limite.|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [estruturas de dados](../../../parallel/concrt/synchronization-data-structures.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `event`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="ctor"></a>evento 

 Constrói um novo evento.  
  
```
_CRTIMP event();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="dtor"></a>~ eventos 

 Destrói um evento.  
  
```
~event();
```  
  
### <a name="remarks"></a>Comentários  
 Espera-se que não há nenhum thread aguardar o evento quando o destruidor é executado. Permitir que o evento destruct com threads ainda aguardando resulta em um comportamento indefinido.  
  
##  <a name="reset"></a>Redefinir 

 Redefine o evento para um estado não-sinalizado.  
  
```
void reset();
```  
  
##  <a name="set"></a>definir 

 Sinaliza o evento.  
  
```
void set();
```  
  
### <a name="remarks"></a>Comentários  
 Sinalização do evento pode causar um número arbitrário de contextos de aguardar o evento se torne executável.  
  
##  <a name="timeout_infinite"></a>timeout_infinite 

 Valor que indica que uma espera nunca deve atingir o tempo limite.  
  
```
static const unsigned int timeout_infinite = COOPERATIVE_TIMEOUT_INFINITE;
```  
  
##  <a name="wait"></a>Aguarde 

 Aguarda o evento ficar sinalizado.  
  
```
size_t wait(unsigned int _Timeout = COOPERATIVE_TIMEOUT_INFINITE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Timeout`  
 Indica o número de milissegundos antes que a espera expire. O valor `COOPERATIVE_TIMEOUT_INFINITE` significa que não há nenhum tempo limite.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a espera foi atendida, o valor `0` retornado; caso contrário, o valor `COOPERATIVE_WAIT_TIMEOUT` para indicar que o tempo de espera esgotado sem o evento tornar-se sinalizado.  
  
> [!IMPORTANT]
>  Em um [!INCLUDE[win8_appname_long](../../../build/includes/win8_appname_long_md.md)] aplicativo, não chame `wait` sobre o ASTA de thread porque essa chamada pode bloquear o thread atual e pode fazer com que o aplicativo pare de responder.  
  
##  <a name="wait_for_multiple"></a>wait_for_multiple 

 Aguarda vários eventos ficar sinalizado.  
  
```
static size_t __cdecl wait_for_multiple(
    _In_reads_(count) event** _PPEvents,
    size_t count,
    bool _FWaitAll,
    unsigned int _Timeout = COOPERATIVE_TIMEOUT_INFINITE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PPEvents`  
 Uma matriz de eventos de aguardar. O número de eventos dentro da matriz é indicado pela `count` parâmetro.  
  
 `count`  
 A contagem de eventos dentro da matriz fornecida no `_PPEvents` parâmetro.  
  
 `_FWaitAll`  
 Se definido como o valor `true`, o parâmetro especifica que todos os eventos dentro da matriz fornecido no `_PPEvents` parâmetro deve ficar sinalizado para satisfazer a aguardar. Se definido como o valor `false`, especifica que qualquer evento dentro da matriz fornecido no `_PPEvents` parâmetro tornando-se sinalizado atenderá a espera.  
  
 `_Timeout`  
 Indica o número de milissegundos antes que a espera expire. O valor `COOPERATIVE_TIMEOUT_INFINITE` significa que não há nenhum tempo limite.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a espera foi atendida, o índice dentro da matriz fornecida no `_PPEvents` parâmetro que satisfeito a condição de espera; caso contrário, o valor `COOPERATIVE_WAIT_TIMEOUT` para indicar que o tempo de espera esgotado sem condição ser atendida.  
  
### <a name="remarks"></a>Comentários  
 Se o parâmetro `_FWaitAll` é definido como o valor `true` para indicar que todos os eventos devem tornou-se sinalizado para satisfazer a espera, o índice retornado pela função não executa nenhum significado especial além do fato de que não é o valor `COOPERATIVE_WAIT_TIMEOUT`.  
  
> [!IMPORTANT]
>  Em um [!INCLUDE[win8_appname_long](../../../build/includes/win8_appname_long_md.md)] aplicativo, não chame `wait_for_multiple` sobre o ASTA de thread porque essa chamada pode bloquear o thread atual e pode fazer com que o aplicativo pare de responder.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)

