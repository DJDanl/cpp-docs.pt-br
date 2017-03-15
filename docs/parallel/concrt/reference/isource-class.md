---
title: Classe ISource | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- agents/concurrency::ISource
dev_langs:
- C++
helpviewer_keywords:
- ISource class
ms.assetid: c7b73463-42f6-4dcc-801a-81379b12d35a
caps.latest.revision: 20
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
ms.openlocfilehash: db3ba296a96b2e77c0ae7d9be3d0a499fe2e7f76
ms.lasthandoff: 02/25/2017

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
 O tipo de dados de carga nas mensagens produzido pelo bloco de origem.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`source_type`|Um alias de tipo para `T`.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[~ Destruidor ISource](#dtor)|Destrói o `ISource` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método Accept](#accept)|Quando substituído em uma classe derivada, aceita uma mensagem que foi oferecida por esse `ISource` bloco, transferir a propriedade para o chamador.|  
|[Método acquire_ref](#acquire_ref)|Quando substituído em uma classe derivada, obtém uma contagem de referência sobre isso `ISource` bloco, para impedir a exclusão.|  
|[Método Consume](#consume)|Quando substituído em uma classe derivada, consome uma mensagem anteriormente oferecida por esse `ISource` bloquear e reservada com êxito pelo destino, transferindo a propriedade para o chamador.|  
|[Método link_target](#link_target)|Quando substituído em uma classe derivada, um bloco de destino está vinculada a esta `ISource` bloco.|  
|[Método de liberação](#release)|Quando substituído em uma classe derivada, libera uma reserva de mensagem bem-sucedida anterior.|  
|[Método release_ref](#release_ref)|Quando substituído em uma classe derivada, libera uma contagem de referência sobre isso `ISource` bloco.|  
|[Método Reserve](#reserve)|Quando substituído em uma classe derivada, reserva uma mensagem anteriormente oferecida por esse `ISource` bloco.|  
|[Método unlink_target](#unlink_target)|Quando substituído em uma classe derivada, desvincula um bloco de destino deste `ISource` bloquear, se encontrado a ser vinculado anteriormente.|  
|[Método unlink_targets](#unlink_targets)|Quando substituído em uma classe derivada, desvincula todos os blocos de destino deste `ISource` bloco.|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `ISource`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-nameaccepta-accept"></a><a name="accept"></a>aceitar 

 Quando substituído em uma classe derivada, aceita uma mensagem que foi oferecida por esse `ISource` bloco, transferir a propriedade para o chamador.  
  
```
virtual message<T>* accept(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<T>* _PTarget) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` da oferecida `message` objeto.  
  
 `_PTarget`  
 Um ponteiro para o bloco de destino que está chamando o `accept` método.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a mensagem que o chamador agora é o proprietário.  
  
### <a name="remarks"></a>Comentários  
 O `accept` método é chamado por um destino, enquanto uma mensagem está sendo oferecida por esse `ISource` bloco. O ponteiro de mensagem retornado pode ser diferente do passado para o `propagate` método o `ITarget` bloquear, se essa fonte decide fazer uma cópia da mensagem.  
  
##  <a name="a-nameacquirerefa-acquireref"></a><a name="acquire_ref"></a>acquire_ref 

 Quando substituído em uma classe derivada, obtém uma contagem de referência sobre isso `ISource` bloco, para impedir a exclusão.  
  
```
virtual void acquire_ref(_Inout_ ITarget<T>* _PTarget) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 Um ponteiro para o bloco de destino que está chamando este método.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado um `ITarget` objeto que está sendo vinculado a esta fonte durante o `link_target` método.  
  
##  <a name="a-nameconsumea-consume"></a><a name="consume"></a>consumir 

 Quando substituído em uma classe derivada, consome uma mensagem anteriormente oferecida por esse `ISource` bloquear e reservada com êxito pelo destino, transferindo a propriedade para o chamador.  
  
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
  
##  <a name="a-namedtora-isource"></a><a name="dtor"></a>~ ISource 

 Destrói o `ISource` objeto.  
  
```
virtual ~ISource();
```  
  
##  <a name="a-namelinktargeta-linktarget"></a><a name="link_target"></a>link_target 

 Quando substituído em uma classe derivada, um bloco de destino está vinculada a esta `ISource` bloco.  
  
```
virtual void link_target(_Inout_ ITarget<T>* _PTarget) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 Um ponteiro para o bloco de destino que está sendo vinculado a este `ISource` bloco.  
  
##  <a name="a-namereleasea-release"></a><a name="release"></a>versão 

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
  
##  <a name="a-namereleaserefa-releaseref"></a><a name="release_ref"></a>release_ref 

 Quando substituído em uma classe derivada, libera uma contagem de referência sobre isso `ISource` bloco.  
  
```
virtual void release_ref(_Inout_ ITarget<T>* _PTarget) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 Um ponteiro para o bloco de destino que está chamando este método.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado um `ITarget` objeto que está sendo desvinculado dessa fonte. O bloco de código-fonte pode liberar quaisquer recursos reservados para o bloco de destino.  
  
##  <a name="a-namereservea-reserve"></a><a name="reserve"></a>reservar 

 Quando substituído em uma classe derivada, reserva uma mensagem anteriormente oferecida por esse `ISource` bloco.  
  
```
virtual bool reserve(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<T>* _PTarget) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` da oferecida `message` objeto.  
  
 `_PTarget`  
 Um ponteiro para o bloco de destino que está chamando o `reserve` método.  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se a mensagem foi reservada com êxito, `false` caso contrário. Reservas podem falhar por vários motivos, incluindo: a mensagem já foi reservada ou aceito por outro destino, a origem pode negar reservas e assim por diante.  
  
### <a name="remarks"></a>Comentários  
 Depois de você chamar `reserve`, se for bem-sucedida, você deve chamar `consume` ou `release` para levar ou desistir de posse da mensagem, respectivamente.  
  
##  <a name="a-nameunlinktargeta-unlinktarget"></a><a name="unlink_target"></a>unlink_target 

 Quando substituído em uma classe derivada, desvincula um bloco de destino deste `ISource` bloquear, se encontrado a ser vinculado anteriormente.  
  
```
virtual void unlink_target(_Inout_ ITarget<T>* _PTarget) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 Um ponteiro para o bloco de destino que está sendo desvinculado neste `ISource` bloco.  
  
##  <a name="a-nameunlinktargetsa-unlinktargets"></a><a name="unlink_targets"></a>unlink_targets 

 Quando substituído em uma classe derivada, desvincula todos os blocos de destino deste `ISource` bloco.  
  
```
virtual void unlink_targets() = 0;
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe ITarget](itarget-class.md)

