---
title: Classe ISource | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- ISource
- AGENTS/concurrency::ISource
- AGENTS/concurrency::ISource::accept
- AGENTS/concurrency::ISource::acquire_ref
- AGENTS/concurrency::ISource::consume
- AGENTS/concurrency::ISource::link_target
- AGENTS/concurrency::ISource::release
- AGENTS/concurrency::ISource::release_ref
- AGENTS/concurrency::ISource::reserve
- AGENTS/concurrency::ISource::unlink_target
- AGENTS/concurrency::ISource::unlink_targets
dev_langs:
- C++
helpviewer_keywords:
- ISource class
ms.assetid: c7b73463-42f6-4dcc-801a-81379b12d35a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 27b1aa57a8c90c2f996aab3b8ee47797f15edd5b
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33692565"
---
# <a name="isource-class"></a>Classe ISource
O `ISource` classe é a interface para todos os blocos de origem. Blocos de código-fonte propaguem as mensagens `ITarget` blocos.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T>
class ISource;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de dados da carga de mensagens gerado pelo bloco de origem.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`source_type`|Um alias de tipo para `T`.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[~ Destruidor ISource](#dtor)|Destrói a `ISource` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[accept](#accept)|Quando substituído em uma classe derivada, aceita uma mensagem que foi fornecida por esse `ISource` bloco, transferir a propriedade para o chamador.|  
|[acquire_ref](#acquire_ref)|Quando substituído em uma classe derivada, obtém uma contagem de referência neste `ISource` bloco, para impedir a exclusão.|  
|[consume](#consume)|Quando substituído em uma classe derivada, consome uma mensagem anteriormente oferecida por este `ISource` bloquear e reservada com êxito pelo destino, transferir a propriedade para o chamador.|  
|[link_target](#link_target)|Quando substituído em uma classe derivada, vincula um bloco de destino para este `ISource` bloco.|  
|[release](#release)|Quando substituído em uma classe derivada, libera uma reserva de mensagem bem-sucedida anterior.|  
|[release_ref](#release_ref)|Quando substituído em uma classe derivada, libera uma contagem de referência neste `ISource` bloco.|  
|[reserve](#reserve)|Quando substituído em uma classe derivada, reserva uma mensagem anteriormente oferecida por este `ISource` bloco.|  
|[unlink_target](#unlink_target)|Quando substituído em uma classe derivada, desvincula um bloco de destino deste `ISource` bloquear, se encontrado a ser vinculado anteriormente.|  
|[unlink_targets](#unlink_targets)|Quando substituído em uma classe derivada, desvincula todos os blocos de destino deste `ISource` bloco.|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `ISource`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="accept"></a> Aceitar 

 Quando substituído em uma classe derivada, aceita uma mensagem que foi fornecida por esse `ISource` bloco, transferir a propriedade para o chamador.  
  
```
virtual message<T>* accept(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<T>* _PTarget) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` do que o oferecido `message` objeto.  
  
 `_PTarget`  
 Um ponteiro para o bloco de destino que está chamando o `accept` método.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a mensagem de que o chamador agora tem a propriedade do.  
  
### <a name="remarks"></a>Comentários  
 O `accept` método é chamado por um destino, enquanto uma mensagem está sendo oferecida por este `ISource` bloco. O ponteiro de mensagem retornado pode ser diferente do passado para o `propagate` método o `ITarget` bloquear, se essa fonte decidir fazer uma cópia da mensagem.  
  
##  <a name="acquire_ref"></a> acquire_ref 

 Quando substituído em uma classe derivada, obtém uma contagem de referência neste `ISource` bloco, para impedir a exclusão.  
  
```
virtual void acquire_ref(_Inout_ ITarget<T>* _PTarget) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 Um ponteiro para o bloco de destino que é chamar esse método.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado um `ITarget` objeto que está sendo vinculado a esta fonte durante o `link_target` método.  
  
##  <a name="consume"></a> Consumir 

 Quando substituído em uma classe derivada, consome uma mensagem anteriormente oferecida por este `ISource` bloquear e reservada com êxito pelo destino, transferir a propriedade para o chamador.  
  
```
virtual message<T>* consume(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<T>* _PTarget) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` de reservado `message` objeto.  
  
 `_PTarget`  
 Um ponteiro para o bloco de destino que está chamando o `consume` método.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `message` que o chamador agora tem a propriedade do objeto.  
  
### <a name="remarks"></a>Comentários  
 O `consume` método é semelhante ao `accept`, mas sempre deve ser precedido por uma chamada para `reserve` que retornou `true`.  
  
##  <a name="dtor"></a> ~ ISource 

 Destrói a `ISource` objeto.  
  
```
virtual ~ISource();
```  
  
##  <a name="link_target"></a> link_target 

 Quando substituído em uma classe derivada, vincula um bloco de destino para este `ISource` bloco.  
  
```
virtual void link_target(_Inout_ ITarget<T>* _PTarget) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 Um ponteiro para o bloco de destino que está sendo vinculado a este `ISource` bloco.  
  
##  <a name="release"></a> versão 

 Quando substituído em uma classe derivada, libera uma reserva de mensagem bem-sucedida anterior.  
  
```
virtual void release(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<T>* _PTarget) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` de reservado `message` objeto.  
  
 `_PTarget`  
 Um ponteiro para o bloco de destino que está chamando o `release` método.  
  
##  <a name="release_ref"></a> release_ref 

 Quando substituído em uma classe derivada, libera uma contagem de referência neste `ISource` bloco.  
  
```
virtual void release_ref(_Inout_ ITarget<T>* _PTarget) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 Um ponteiro para o bloco de destino que é chamar esse método.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado um `ITarget` objeto que está sendo desvinculado dessa fonte. O bloco de código-fonte pode liberar quaisquer recursos reservados para o bloco de destino.  
  
##  <a name="reserve"></a> reserva 

 Quando substituído em uma classe derivada, reserva uma mensagem anteriormente oferecida por este `ISource` bloco.  
  
```
virtual bool reserve(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<T>* _PTarget) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` do que o oferecido `message` objeto.  
  
 `_PTarget`  
 Um ponteiro para o bloco de destino que está chamando o `reserve` método.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se a mensagem foi reservada com êxito, `false` caso contrário. Reservas podem falhar por vários motivos, incluindo: a mensagem já foi reservada ou aceito por outro destino, a fonte pode negar reservas e assim por diante.  
  
### <a name="remarks"></a>Comentários  
 Depois de chamar `reserve`, se tiver êxito, você deve chamar `consume` ou `release` para levar ou dar a posse da mensagem, respectivamente.  
  
##  <a name="unlink_target"></a> unlink_target 

 Quando substituído em uma classe derivada, desvincula um bloco de destino deste `ISource` bloquear, se encontrado a ser vinculado anteriormente.  
  
```
virtual void unlink_target(_Inout_ ITarget<T>* _PTarget) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 Um ponteiro para o bloco de destino que está sendo desvinculado neste `ISource` bloco.  
  
##  <a name="unlink_targets"></a> unlink_targets 

 Quando substituído em uma classe derivada, desvincula todos os blocos de destino deste `ISource` bloco.  
  
```
virtual void unlink_targets() = 0;
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe ITarget](itarget-class.md)
