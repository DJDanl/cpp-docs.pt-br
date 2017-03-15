---
title: Classe ITarget | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- agents/concurrency::ITarget
dev_langs:
- C++
helpviewer_keywords:
- ITarget class
ms.assetid: 5678db25-112a-4f72-be13-42e16b67c48b
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
translationtype: Machine Translation
ms.sourcegitcommit: fc190feb08d9b221cd1cc21a9c91ad567c86c848
ms.openlocfilehash: aa9001de9ec35f20cd76f701d6b8acc5de7ffde0
ms.lasthandoff: 02/25/2017

---
# <a name="itarget-class"></a>Classe ITarget
O `ITarget` classe é a interface de todos os blocos de destino. Blocos de destino consumam mensagens oferecidas a eles por `ISource` blocos.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T>
class ITarget;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de dados de carga nas mensagens aceitas pelo bloco de destino.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`filter_method`|A assinatura de qualquer método usado pelo bloco que retorna um `bool` valor para determinar se uma mensagem oferecida deve ser aceitas.|  
|`type`|Um alias de tipo para `T`.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[~ Destruidor ITarget](#dtor)|Destrói o `ITarget` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método propagate](#propagate)|Quando substituído em uma classe derivada, assincronamente transmite uma mensagem de um bloco de código-fonte para este bloco de destino.|  
|[Método Send](#send)|Quando substituído em uma classe derivada, sincronicamente transmite uma mensagem para o bloco de destino.|  
|[Método supports_anonymous_source](#supports_anonymous_source)|Quando substituído em uma classe derivada, retorna true ou false dependendo se o bloco de mensagens aceita mensagens oferecidas por uma fonte que não está vinculada a ele. Se o método substituído retorna `true`, o destino não pode adiar uma mensagem oferecida, como a fonte a ser identificados no seu registro de link sourse exige que o consumo de uma mensagem adiada em um momento posterior.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método link_source](#link_source)|Quando substituído em uma classe derivada, vincula um bloco de origem especificado para esse `ITarget` bloco.|  
|[Método unlink_source](#unlink_source)|Quando substituído em uma classe derivada, desvincula um bloco de código-fonte especificado neste `ITarget` bloco.|  
|[Método unlink_sources](#unlink_sources)|Quando substituído em uma classe derivada, desvincula todos os blocos de código-fonte deste `ITarget` bloco.|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `ITarget`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-namedtora-itarget"></a><a name="dtor"></a>~ ITarget 

 Destrói o `ITarget` objeto.  
  
```
virtual ~ITarget();
```  
  
##  <a name="a-namelinksourcea-linksource"></a><a name="link_source"></a>link_source 

 Quando substituído em uma classe derivada, vincula um bloco de origem especificado para esse `ITarget` bloco.  
  
```
virtual void link_source(_Inout_ ISource<T>* _PSource) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PSource`  
 O `ISource` bloquear vinculado a este `ITarget` bloco.  
  
### <a name="remarks"></a>Comentários  
 Essa função não deve ser chamada diretamente em um `ITarget` bloco. Blocos devem ser conectados usando o `link_target` método `ISource` blocos, que irá chamar o `link_source` método de destino correspondente.  
  
##  <a name="a-namepropagatea-propagate"></a><a name="propagate"></a>Propagar 

 Quando substituído em uma classe derivada, assincronamente transmite uma mensagem de um bloco de código-fonte para este bloco de destino.  
  
```
virtual message_status propagate(
    _Inout_opt_ message<T>* _PMessage,
    _Inout_opt_ ISource<T>* _PSource) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PMessage`  
 Um ponteiro para o `message` objeto.  
  
 `_PSource`  
 Um ponteiro para o bloco de código-fonte oferecendo a mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 A [message_status](concurrency-namespace-enums.md) indicação de que o destino decidiu fazer com a mensagem.  
  
### <a name="remarks"></a>Comentários  
 O método lança um [invalid_argument](../../../standard-library/invalid-argument-class.md) exceção se o `_PMessage` ou `_PSource` parâmetro é `NULL`.  
  
##  <a name="a-namesenda-send"></a><a name="send"></a>Enviar 

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
 Um ponteiro para o bloco de código-fonte oferecendo a mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 A [message_status](concurrency-namespace-enums.md) indicação de que o destino decidiu fazer com a mensagem.  
  
### <a name="remarks"></a>Comentários  
 O método lança um [invalid_argument](../../../standard-library/invalid-argument-class.md) exceção se o `_PMessage` ou `_PSource` parâmetro é `NULL`.  
  
 Usando o `send` método fora do início da mensagem e propagar as mensagens em uma rede é perigoso e pode resultar em deadlock.  
  
 Quando `send` retorna, a mensagem seja já foi aceita e transferida para o bloco de destino, ou ele foi recusado pelo destino.  
  
##  <a name="a-namesupportsanonymoussourcea-supportsanonymoussource"></a><a name="supports_anonymous_source"></a>supports_anonymous_source 

 Quando substituído em uma classe derivada, retorna true ou false dependendo se o bloco de mensagens aceita mensagens oferecidas por uma fonte que não está vinculada a ele. Se o método substituído retorna `true`, o destino não pode adiar uma mensagem oferecida, como a fonte a ser identificados no seu registro de link sourse exige que o consumo de uma mensagem adiada em um momento posterior.  
  
```
virtual bool supports_anonymous_source();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o bloco pode aceitar mensagens de uma fonte que não está vinculada a ele `false` caso contrário.  
  
##  <a name="a-nameunlinksourcea-unlinksource"></a><a name="unlink_source"></a>unlink_source 

 Quando substituído em uma classe derivada, desvincula um bloco de código-fonte especificado neste `ITarget` bloco.  
  
```
virtual void unlink_source(_Inout_ ISource<T>* _PSource) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PSource`  
 O `ISource` bloquear sendo desvinculado neste `ITarget` bloco.  
  
### <a name="remarks"></a>Comentários  
 Essa função não deve ser chamada diretamente em um `ITarget` bloco. Blocos devem ser desconectados usando o `unlink_target` ou `unlink_targets` métodos em `ISource` blocos, que irá chamar o `unlink_source` método de destino correspondente.  
  
##  <a name="a-nameunlinksourcesa-unlinksources"></a><a name="unlink_sources"></a>unlink_sources 

 Quando substituído em uma classe derivada, desvincula todos os blocos de código-fonte deste `ITarget` bloco.  
  
```
virtual void unlink_sources() = 0;
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe ISource](isource-class.md)

