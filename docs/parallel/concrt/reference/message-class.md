---
title: Classe de mensagem | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- agents/concurrency::message
dev_langs:
- C++
helpviewer_keywords:
- message class
ms.assetid: 3e1f3505-6c0c-486c-8191-666d0880ec62
caps.latest.revision: 21
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
ms.openlocfilehash: 08d67f2899f27a92250d6fedbf755a5413e01ebd
ms.lasthandoff: 02/25/2017

---
# <a name="message-class"></a>Classe message
O envelope de mensagem básica que contém a carga de dados sendo passada entre blocos de mensagens.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T>
class message : public ::Concurrency::details::_Runtime_object;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de dados de carga dentro da mensagem.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`type`|Um alias de tipo para `T`.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[mensagem de construtor](#ctor)|Sobrecarregado. Constrói um objeto `message`.|  
|[~ Destruidor de mensagem](#dtor)|Destrói o `message` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método add_ref](#add_ref)|Adiciona a contagem de referência para o `message` objeto. Usado para blocos de mensagens que precisa determinar o tempo de vida da mensagem de contagem de referência.|  
|[Método msg_id](#msg_id)|Retorna a ID do `message` objeto.|  
|[Método remove_ref](#remove_ref)|Subtrai a contagem de referência para o `message` objeto. Usado para blocos de mensagens que precisa determinar o tempo de vida da mensagem de contagem de referência.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Membro de dados de carga](#payload)|A carga do `message` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `message`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-nameaddrefa-addref"></a><a name="add_ref"></a>add_ref 

 Adiciona a contagem de referência para o `message` objeto. Usado para blocos de mensagens que precisa determinar o tempo de vida da mensagem de contagem de referência.  
  
```
long add_ref();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O novo valor da contagem de referência.  
  
##  <a name="a-namectora-message"></a><a name="ctor"></a>Mensagem 

 Constrói um objeto `message`.  
  
```
message(
    T const& _P);

message(
    T const& _P,
    runtime_object_identity _Id);

message(
    message const& _Msg);

message(
    _In_ message const* _Msg);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_P`  
 A carga da mensagem.  
  
 `_Id`  
 A ID exclusiva da mensagem.  
  
 `_Msg`  
 Uma referência ou um ponteiro para um `message` objeto.  
  
### <a name="remarks"></a>Comentários  
 O construtor que usa um ponteiro para um `message` objeto como um argumento lança um [invalid_argument](../../../standard-library/invalid-argument-class.md) exceção se o parâmetro `_Msg` é `NULL`.  
  
##  <a name="a-namedtora-message"></a><a name="dtor"></a>~ mensagem 

 Destrói o `message` objeto.  
  
```
virtual ~message();
```  
  
##  <a name="a-namemsgida-msgid"></a><a name="msg_id"></a>msg_id 

 Retorna a ID do `message` objeto.  
  
```
runtime_object_identity msg_id() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O `runtime_object_identity` do `message` objeto.  
  
##  <a name="a-namepayloada-payload"></a><a name="payload"></a>carga 

 A carga do `message` objeto.  
  
```
T const payload;
```  
  
##  <a name="a-nameremoverefa-removeref"></a><a name="remove_ref"></a>remove_ref 

 Subtrai a contagem de referência para o `message` objeto. Usado para blocos de mensagens que precisa determinar o tempo de vida da mensagem de contagem de referência.  
  
```
long remove_ref();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O novo valor da contagem de referência.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)

