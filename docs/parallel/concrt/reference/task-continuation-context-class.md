---
title: Classe task_continuation_context | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- task_continuation_context
- PPLTASKS/concurrency::task_continuation_context
- PPLTASKS/concurrency::task_continuation_context::get_current_winrt_context
- PPLTASKS/concurrency::task_continuation_context::use_arbitrary
- PPLTASKS/concurrency::task_continuation_context::use_current
- PPLTASKS/concurrency::task_continuation_context::use_default
- PPLTASKS/concurrency::task_continuation_context::use_synchronous_execution
dev_langs:
- C++
helpviewer_keywords:
- task_continuation_context class
ms.assetid: 1fb5a76a-3682-45c2-a615-8b6b527741f0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 37b218a6db251123513ca155fd491fee7ebabd13
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="taskcontinuationcontext-class"></a>Classe task_continuation_context
A classe `task_continuation_context` permite que você especifique onde gostaria que uma continuação fosse executada. Isso é útil somente usar essa classe de um aplicativo de tempo de execução do Windows. Para aplicativos não - Windows Runtime, o contexto de execução de continuação de tarefas é determinado pelo tempo de execução e não é configurável.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class task_continuation_context : public details::_ContextCallback;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[get_current_winrt_context](#get_current_winrt_context)|Retorna um objeto de contexto de continuação de tarefa que representa o contexto de thread atual do winrt.|  
|[use_arbitrary](#use_arbitrary)|Cria um contexto de continuação da tarefa que permite que o Tempo de execução escolha o contexto de execução para uma continuação.|  
|[use_current](#use_current)|Retorna um objeto de contexto de continuação da tarefa que representa o contexto de execução atual.|  
|[use_default](#use_default)|Cria o contexto de continuação da tarefa padrão.|  
|[use_synchronous_execution](#use_synchronous_execution)|Retorna um objeto de contexto de continuação de tarefa que representa o contexto de execução síncrona.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `_ContextCallback`  
  
 `task_continuation_context`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** ppltasks  
  
 **Namespace:** simultaneidade  

## <a name="get_current_winrt_context"></a> get_current_winrt_context
 Retorna um objeto de contexto de continuação de tarefa que representa o contexto de thread atual do WinRT.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
static task_continuation_context get_current_winrt_context();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 O contexto do thread atual em tempo de execução do Windows. Retorna um task_continuation_context vazio se chamado em um contexto de não - Windows Runtime.  
  
## <a name="remarks"></a>Comentários  
 O `get_current_winrt_context` método captura o contexto do thread de tempo de execução do Windows do chamador. Ele retorna um contexto vazio para chamadores não - Windows Runtime.  
  
 O valor retornado por `get_current_winrt_context` pode ser usado para indicar o tempo de execução que a continuação deve ser executado no modelo de apartment de contexto capturado STA vs (MTA), independentemente da tarefa antecedente está ciente de apartment. Um compartimento com reconhecimento de tarefa é uma tarefa que é desencapsulado um tempo de execução do Windows `IAsyncInfo` interface ou uma tarefa que é descendente de uma tarefa.  
  
 Esse método é semelhante de `use_current` método, mas ele também está disponível para o código C++ nativo sem C + + suporte de extensão CX. Ele é destinado para uso por usuários avançados gravação C + + código da biblioteca não reconhece CX para nativo e chamadores de tempo de execução do Windows. A menos que você precisa dessa funcionalidade, recomendamos o `use_current` método, que só está disponível para o C + + clientes CX.  
  
  
##  <a name="use_arbitrary"></a> use_arbitrary 

 Cria um contexto de continuação da tarefa que permite que o Tempo de execução escolha o contexto de execução para uma continuação.  
  
```
static task_continuation_context use_arbitrary();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um contexto de continuação de tarefa que representa um local arbitrário.  
  
### <a name="remarks"></a>Comentários  
 Quando é usado neste contexto de continuação a continuação serão executadas em um contexto que de tempo de execução escolhe mesmo se a tarefa antecedente com reconhecimento de compartimento.  
  
 `use_arbitrary` pode ser usado para desativar o comportamento padrão para uma continuação em uma tarefa com reconhecimento de compartimento criada em um STA.  
  
 Esse método só está disponível para aplicativos de tempo de execução do Windows.  
  
##  <a name="use_current"></a> use_current 

 Retorna um objeto de contexto de continuação da tarefa que representa o contexto de execução atual.  
  
```
static task_continuation_context use_current();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O contexto de execução atual.  
  
### <a name="remarks"></a>Comentários  
 Esse método captura o contexto do chamador em tempo de execução do Windows para que as continuações podem ser executadas no direito de compartimento.  
  
 O valor retornado por `use_current` pode ser usado para indicar o tempo de execução que a continuação deve executadas no contexto capturado (STA vs MTA), independentemente ou não a tarefa antecedente com reconhecimento de compartimento. Um compartimento com reconhecimento de tarefa é uma tarefa que é desencapsulado um tempo de execução do Windows `IAsyncInfo` interface ou uma tarefa que é descendente de uma tarefa.  
  
 Esse método só está disponível para aplicativos de tempo de execução do Windows.  
  
##  <a name="use_default"></a> use_default 

 Cria o contexto de continuação da tarefa padrão.  
  
```
static task_continuation_context use_default();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O contexto de continuação do padrão.  
  
### <a name="remarks"></a>Comentários  
 O contexto padrão será usado se você não especificar um contexto de continuação quando você chamar o `then` método. Aplicativos do Windows para Windows 7 e abaixo, bem como aplicativos de desktop no Windows 8 e superior, o tempo de execução determina onde continuações tarefa serão executada. No entanto, em um aplicativo de tempo de execução do Windows, o contexto de continuação padrão para uma continuação em uma tarefa com reconhecimento de compartimento é o compartimento em que `then` é invocado.  
  
 Um compartimento com reconhecimento de tarefa é uma tarefa que é desencapsulado um tempo de execução do Windows `IAsyncInfo` interface ou uma tarefa que é descendente de uma tarefa. Portanto, se você agendar uma continuação em uma tarefa com reconhecimento de compartimento em um STA de tempo de execução do Windows, a continuação serão executadas no que STA.  
  
 Uma continuação em uma tarefa com reconhecimento de compartimento não será executado em um contexto que de tempo de execução escolhe.  

## <a name="use_synchronous_execution"></a> task_continuation_context::use_synchronous_execution  
Retorna um objeto de contexto de continuação de tarefa que representa o contexto de execução síncrona.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
static task_continuation_context use_synchronous_execution();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 O contexto de execução síncrona.  
  
## <a name="remarks"></a>Comentários  
 O `use_synchronous_execution` método força a tarefa de continuação para execução síncrona no contexto, fazendo com que a conclusão da tarefa seu antecedente.  
  
 Se a tarefa antecedente já foi concluída quando a continuação é anexada, a continuação é executada síncrona no contexto que conecta a continuação.  
  
 
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)
