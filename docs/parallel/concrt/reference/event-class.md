---
title: Classe Event | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fb02865b20d1603be38192e770eb26627e6900e7
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="event-class"></a>Classe event
Um evento de redefinição manual que reconhece explicitamente o tempo de execução de simultaneidade.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class event;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[~ o evento destruidor](#dtor)|Destrói um evento.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[reset](#reset)|Redefine o evento para um estado não sinalizado.|  
|[set](#set)|Sinaliza o evento.|  
|[wait](#wait)|Aguarda o evento tornou-se sinalizado.|  
|[wait_for_multiple](#wait_for_multiple)|Espera por vários eventos ficar sinalizado.|  
  
### <a name="public-constants"></a>Constantes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[timeout_infinite](#timeout_infinite)|Valor que indica que uma espera nunca deve atingir o tempo limite.|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [estruturas de dados de sincronização](../../../parallel/concrt/synchronization-data-structures.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `event`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="ctor"></a> Evento 

 Constrói um novo evento.  
  
```
_CRTIMP event();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="dtor"></a> ~ eventos 

 Destrói um evento.  
  
```
~event();
```  
  
### <a name="remarks"></a>Comentários  
 Espera-se que não há nenhum thread aguardar o evento quando o destruidor é executado. Permitir que o evento destruct com threads ainda aguardando resulta em um comportamento indefinido.  
  
##  <a name="reset"></a> Redefinir 

 Redefine o evento para um estado não sinalizado.  
  
```
void reset();
```  
  
##  <a name="set"></a> Definir 

 Sinaliza o evento.  
  
```
void set();
```  
  
### <a name="remarks"></a>Comentários  
 Sinalizar o evento pode causar um número arbitrário de contextos de aguardar o evento seja executável.  
  
##  <a name="timeout_infinite"></a> timeout_infinite 

 Valor que indica que uma espera nunca deve atingir o tempo limite.  
  
```
static const unsigned int timeout_infinite = COOPERATIVE_TIMEOUT_INFINITE;
```  
  
##  <a name="wait"></a> Aguarde 

 Aguarda o evento tornou-se sinalizado.  
  
```
size_t wait(unsigned int _Timeout = COOPERATIVE_TIMEOUT_INFINITE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Timeout`  
 Indica o número de milissegundos antes de atingir o tempo limite de espera. O valor `COOPERATIVE_TIMEOUT_INFINITE` significa que não há nenhum tempo limite.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a espera foi atendida, o valor `0` retornado; caso contrário, o valor `COOPERATIVE_WAIT_TIMEOUT` para indicar que o limite de espera sem o evento se tornar sinalizado.  
  
> [!IMPORTANT]
>  Em um aplicativo do Windows UWP (plataforma Universal), não chame `wait` sobre o ASTA de thread porque essa chamada pode bloquear o thread atual e pode fazer com que o aplicativo pare de responder.  
  
##  <a name="wait_for_multiple"></a> wait_for_multiple 

 Espera por vários eventos ficar sinalizado.  
  
```
static size_t __cdecl wait_for_multiple(
    _In_reads_(count) event** _PPEvents,
    size_t count,
    bool _FWaitAll,
    unsigned int _Timeout = COOPERATIVE_TIMEOUT_INFINITE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PPEvents`  
 Uma matriz de eventos para aguardar. O número de eventos dentro da matriz é indicado pelo `count` parâmetro.  
  
 `count`  
 A contagem de eventos dentro da matriz fornecida no `_PPEvents` parâmetro.  
  
 `_FWaitAll`  
 Se definido como o valor `true`, o parâmetro especifica que todos os eventos dentro da matriz fornecida no `_PPEvents` parâmetro deve ser sinalizado para satisfazer a espera. Se definido como o valor `false`, especifica que qualquer evento dentro da matriz é fornecido no `_PPEvents` parâmetro fique sinalizado atenderá a espera.  
  
 `_Timeout`  
 Indica o número de milissegundos antes de atingir o tempo limite de espera. O valor `COOPERATIVE_TIMEOUT_INFINITE` significa que não há nenhum tempo limite.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a espera foi atendida, o índice na matriz fornecida no `_PPEvents` parâmetro que atendidas a condição de espera; caso contrário, o valor `COOPERATIVE_WAIT_TIMEOUT` para indicar que o limite de espera sem a condição seja atendida.  
  
### <a name="remarks"></a>Comentários  
 Se o parâmetro `_FWaitAll` é definido como o valor `true` para indicar que todos os eventos devem se tornar sinalizados para atender a espera, o índice retornado pela função não executa nenhum significado especial que não seja o fato de que não é o valor `COOPERATIVE_WAIT_TIMEOUT`.  
  
> [!IMPORTANT]
>  Em um aplicativo do Windows UWP (plataforma Universal), não chame `wait_for_multiple` sobre o ASTA de thread porque essa chamada pode bloquear o thread atual e pode fazer com que o aplicativo pare de responder.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)
