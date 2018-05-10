---
title: Classe ITarget | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- ITarget
- AGENTS/concurrency::ITarget
- AGENTS/concurrency::ITarget::propagate
- AGENTS/concurrency::ITarget::send
- AGENTS/concurrency::ITarget::supports_anonymous_source
- AGENTS/concurrency::ITarget::link_source
- AGENTS/concurrency::ITarget::unlink_source
- AGENTS/concurrency::ITarget::unlink_sources
dev_langs:
- C++
helpviewer_keywords:
- ITarget class
ms.assetid: 5678db25-112a-4f72-be13-42e16b67c48b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9780e4b9ff8950511601b03e8423764c3def77a1
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="itarget-class"></a>Classe ITarget
O `ITarget` classe é a interface para todos os blocos de destino. Blocos de destino consumam mensagens oferecidas a eles por `ISource` blocos.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T>
class ITarget;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de dados da carga de mensagens aceito pelo bloco de destino.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`filter_method`|A assinatura de qualquer método usado pelo bloco que retorna um `bool` valor para determinar se uma mensagem oferecida deve ser aceita.|  
|`type`|Um alias de tipo para `T`.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[~ Destruidor ITarget](#dtor)|Destrói a `ITarget` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[propagate](#propagate)|Quando substituído em uma classe derivada, assincronamente transmite uma mensagem de um bloco de origem para este bloco de destino.|  
|[send](#send)|Quando substituído em uma classe derivada, sincronicamente transmite uma mensagem para o bloco de destino.|  
|[supports_anonymous_source](#supports_anonymous_source)|Quando substituído em uma classe derivada, retorna true ou false dependendo se o bloco de mensagens aceita mensagens oferecidas por uma fonte que não está vinculada a ele. Se o método substituído retorna `true`, o destino não é possível adiar uma mensagem oferecida, como a fonte a ser identificados no seu registro de link sourse requer o consumo de uma mensagem adiada em um momento posterior.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[link_source](#link_source)|Quando substituído em uma classe derivada, vincula um bloco de origem especificado para este `ITarget` bloco.|  
|[unlink_source](#unlink_source)|Quando substituído em uma classe derivada, desvincula um bloco de código-fonte especificado neste `ITarget` bloco.|  
|[unlink_sources](#unlink_sources)|Quando substituído em uma classe derivada, desvincula todos os blocos de código-fonte deste `ITarget` bloco.|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `ITarget`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="dtor"></a> ~ ITarget 

 Destrói a `ITarget` objeto.  
  
```
virtual ~ITarget();
```  
  
##  <a name="link_source"></a> link_source 

 Quando substituído em uma classe derivada, vincula um bloco de origem especificado para este `ITarget` bloco.  
  
```
virtual void link_source(_Inout_ ISource<T>* _PSource) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PSource`  
 O `ISource` bloquear sendo vinculada a este `ITarget` bloco.  
  
### <a name="remarks"></a>Comentários  
 Essa função não deve ser chamada diretamente em um `ITarget` bloco. Blocos devem ser conectados usando o `link_target` método `ISource` blocos, que invocarão o `link_source` método de destino correspondente.  
  
##  <a name="propagate"></a> Propagar 

 Quando substituído em uma classe derivada, assincronamente transmite uma mensagem de um bloco de origem para este bloco de destino.  
  
```
virtual message_status propagate(
    _Inout_opt_ message<T>* _PMessage,
    _Inout_opt_ ISource<T>* _PSource) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PMessage`  
 Um ponteiro para o `message` objeto.  
  
 `_PSource`  
 Um ponteiro para o bloco de código-fonte oferta a mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Um [message_status](concurrency-namespace-enums.md) indicação de que o destino decidiu fazer com a mensagem.  
  
### <a name="remarks"></a>Comentários  
 O método gera uma [invalid_argument](../../../standard-library/invalid-argument-class.md) exceção se o `_PMessage` ou `_PSource` parâmetro é `NULL`.  
  
##  <a name="send"></a> Enviar 

 Quando substituído em uma classe derivada, sincronicamente transmite uma mensagem para o bloco de destino.  
  
```
virtual message_status send(
    _Inout_ message<T>* _PMessage,
    _Inout_ ISource<T>* _PSource) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PMessage`  
 Um ponteiro para o `message` objeto.  
  
 `_PSource`  
 Um ponteiro para o bloco de código-fonte oferta a mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Um [message_status](concurrency-namespace-enums.md) indicação de que o destino decidiu fazer com a mensagem.  
  
### <a name="remarks"></a>Comentários  
 O método gera uma [invalid_argument](../../../standard-library/invalid-argument-class.md) exceção se o `_PMessage` ou `_PSource` parâmetro é `NULL`.  
  
 Usando o `send` método fora de iniciação de mensagem e propagar as mensagens em uma rede é perigoso e pode resultar em um deadlock.  
  
 Quando `send` retorna, a mensagem seja já foi aceitada e transferida para o bloco de destino, ou ele foi recusado pelo destino.  
  
##  <a name="supports_anonymous_source"></a> supports_anonymous_source 

 Quando substituído em uma classe derivada, retorna true ou false dependendo se o bloco de mensagens aceita mensagens oferecidas por uma fonte que não está vinculada a ele. Se o método substituído retorna `true`, o destino não é possível adiar uma mensagem oferecida, como a fonte a ser identificados no seu registro de link sourse requer o consumo de uma mensagem adiada em um momento posterior.  
  
```
virtual bool supports_anonymous_source();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se o bloco pode aceitar a mensagem de uma fonte que não está vinculada a ele `false` caso contrário.  
  
##  <a name="unlink_source"></a> unlink_source 

 Quando substituído em uma classe derivada, desvincula um bloco de código-fonte especificado neste `ITarget` bloco.  
  
```
virtual void unlink_source(_Inout_ ISource<T>* _PSource) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PSource`  
 O `ISource` bloquear sendo desvinculado neste `ITarget` bloco.  
  
### <a name="remarks"></a>Comentários  
 Essa função não deve ser chamada diretamente em um `ITarget` bloco. Blocos devem ser desconectados usando o `unlink_target` ou `unlink_targets` métodos em `ISource` blocos, que invocarão o `unlink_source` método de destino correspondente.  
  
##  <a name="unlink_sources"></a> unlink_sources 

 Quando substituído em uma classe derivada, desvincula todos os blocos de código-fonte deste `ITarget` bloco.  
  
```
virtual void unlink_sources() = 0;
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe ISource](isource-class.md)
