---
title: Classe de mensagem | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- message
- AGENTS/concurrency::message
- AGENTS/concurrency::message::message
- AGENTS/concurrency::message::add_ref
- AGENTS/concurrency::message::msg_id
- AGENTS/concurrency::message::remove_ref
- AGENTS/concurrency::message::payload
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 5faef5bd1be6cc02d6614a6f6193c74167a8ff23
ms.openlocfilehash: c6cc72c1fe9385eabe86194031913b7363d602ff
ms.contentlocale: pt-br
ms.lasthandoff: 03/17/2017

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
|[message](#ctor)|Sobrecarregado. Constrói um objeto `message`.|  
|[~ Destruidor de mensagem](#dtor)|Destrói o `message` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[add_ref](#add_ref)|Adiciona a contagem de referência para o `message` objeto. Usado para blocos de mensagens que precisa determinar o tempo de vida da mensagem de contagem de referência.|  
|[msg_id](#msg_id)|Retorna a ID do `message` objeto.|  
|[remove_ref](#remove_ref)|Subtrai a contagem de referência para o `message` objeto. Usado para blocos de mensagens que precisa determinar o tempo de vida da mensagem de contagem de referência.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[carga](#payload)|A carga do `message` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `message`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="add_ref"></a>add_ref 

 Adiciona a contagem de referência para o `message` objeto. Usado para blocos de mensagens que precisa determinar o tempo de vida da mensagem de contagem de referência.  
  
```
long add_ref();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O novo valor da contagem de referência.  
  
##  <a name="ctor"></a>Mensagem 

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
  
##  <a name="dtor"></a>~ mensagem 

 Destrói o `message` objeto.  
  
```
virtual ~message();
```  
  
##  <a name="msg_id"></a>msg_id 

 Retorna a ID do `message` objeto.  
  
```
runtime_object_identity msg_id() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O `runtime_object_identity` do `message` objeto.  
  
##  <a name="payload"></a>carga 

 A carga do `message` objeto.  
  
```
T const payload;
```  
  
##  <a name="remove_ref"></a>remove_ref 

 Subtrai a contagem de referência para o `message` objeto. Usado para blocos de mensagens que precisa determinar o tempo de vida da mensagem de contagem de referência.  
  
```
long remove_ref();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O novo valor da contagem de referência.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)

