---
title: Classe de mensagem | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b0828d1d8698cb696b257e6730e4aea3961dd159
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46042202"
---
# <a name="message-class"></a>Classe message
O envelope de mensagem básica que contém o conteúdo dos dados que está sendo transmitido entre blocos de mensagens.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T>
class message : public ::Concurrency::details::_Runtime_object;
```  
  
#### <a name="parameters"></a>Parâmetros  
*T*<br/>
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
|[~ Destruidor da mensagem](#dtor)|Destrói o `message` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[add_ref](#add_ref)|Adiciona a contagem de referência para o `message` objeto. Usado para blocos de mensagem que precisa determinar os tempos de vida da mensagem de contagem de referência.|  
|[msg_id](#msg_id)|Retorna a ID do `message` objeto.|  
|[remove_ref](#remove_ref)|Subtrai da contagem de referência para o `message` objeto. Usado para blocos de mensagem que precisa determinar os tempos de vida da mensagem de contagem de referência.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[payload](#payload)|A carga do `message` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `message`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Agents. h  
  
 **Namespace:** simultaneidade  
  
##  <a name="add_ref"></a> add_ref 

 Adiciona a contagem de referência para o `message` objeto. Usado para blocos de mensagem que precisa determinar os tempos de vida da mensagem de contagem de referência.  
  
```
long add_ref();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O novo valor da contagem de referência.  
  
##  <a name="ctor"></a> Mensagem 

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
*P*<br/>
A carga da mensagem.  
  
*ID*<br/>
A ID exclusiva dessa mensagem.  
  
*_Msg*<br/>
Uma referência ou ponteiro para um `message` objeto.  
  
### <a name="remarks"></a>Comentários  
 O construtor que usa um ponteiro para um `message` objeto como um argumento lança uma [invalid_argument](../../../standard-library/invalid-argument-class.md) exceção se o parâmetro `_Msg` é `NULL`.  
  
##  <a name="dtor"></a> ~ mensagem 

 Destrói o `message` objeto.  
  
```
virtual ~message();
```  
  
##  <a name="msg_id"></a> msg_id 

 Retorna a ID do `message` objeto.  
  
```
runtime_object_identity msg_id() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O `runtime_object_identity` do `message` objeto.  
  
##  <a name="payload"></a> carga 

 A carga do `message` objeto.  
  
```
T const payload;
```  
  
##  <a name="remove_ref"></a> remove_ref 

 Subtrai da contagem de referência para o `message` objeto. Usado para blocos de mensagem que precisa determinar os tempos de vida da mensagem de contagem de referência.  
  
```
long remove_ref();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O novo valor da contagem de referência.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)
