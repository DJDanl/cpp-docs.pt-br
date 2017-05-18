---
title: Classe message_processor | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- message_processor
- AGENTS/concurrency::message_processor
- AGENTS/concurrency::message_processor::async_send
- AGENTS/concurrency::message_processor::sync_send
- AGENTS/concurrency::message_processor::wait
- AGENTS/concurrency::message_processor::process_incoming_message
dev_langs:
- C++
helpviewer_keywords:
- message_processor class
ms.assetid: 23afb052-daa7-44ed-bf24-d2513db748da
caps.latest.revision: 16
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
ms.openlocfilehash: dff934584179cc58d884be65fdb96cb6c646a4ac
ms.contentlocale: pt-br
ms.lasthandoff: 03/17/2017

---
# <a name="messageprocessor-class"></a>Classe message_processor
O `message_processor` classe é a classe base abstrata para processamento de `message` objetos. Não há nenhuma garantia sobre a ordem das mensagens.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T>
class message_processor;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de dados de carga nas mensagens tratadas por este `message_processor` objeto.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`type`|Um alias de tipo para `T`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[async_send](#async_send)|Quando substituído em uma classe derivada, armazena as mensagens no bloco de forma assíncrona.|  
|[sync_send](#sync_send)|Quando substituído em uma classe derivada, armazena as mensagens no bloco de forma síncrona.|  
|[Aguarde](#wait)|Quando substituído em uma classe derivada, espera por todas as operações assíncronas concluir.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[process_incoming_message](#process_incoming_message)|Quando substituído em uma classe derivada, executa o processamento de encaminhamento de mensagens em um bloco. Chamado uma vez sempre que uma nova mensagem é adicionada e a fila é encontrada estar vazio.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `message_processor`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="async_send"></a>async_send 

 Quando substituído em uma classe derivada, armazena as mensagens no bloco de forma assíncrona.  
  
```
virtual void async_send(_Inout_opt_ message<T>* _Msg) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Msg`  
 Um `message` objeto para enviar de forma assíncrona.  
  
### <a name="remarks"></a>Comentários  
 Implementações de processador devem substituir esse método.  
  
##  <a name="process_incoming_message"></a>process_incoming_message 

 Quando substituído em uma classe derivada, executa o processamento de encaminhamento de mensagens em um bloco. Chamado uma vez sempre que uma nova mensagem é adicionada e a fila é encontrada estar vazio.  
  
```
virtual void process_incoming_message() = 0;
```  
  
### <a name="remarks"></a>Comentários  
 Implementações de bloco de mensagens devem substituir esse método.  
  
##  <a name="sync_send"></a>sync_send 

 Quando substituído em uma classe derivada, armazena as mensagens no bloco de forma síncrona.  
  
```
virtual void sync_send(_Inout_opt_ message<T>* _Msg) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Msg`  
 Um `message` objeto a ser enviado de forma síncrona.  
  
### <a name="remarks"></a>Comentários  
 Implementações de processador devem substituir esse método.  
  
##  <a name="wait"></a>Aguarde 

 Quando substituído em uma classe derivada, espera por todas as operações assíncronas concluir.  
  
```
virtual void wait() = 0;
```  
  
### <a name="remarks"></a>Comentários  
 Implementações de processador devem substituir esse método.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe ordered_message_processor](ordered-message-processor-class.md)

