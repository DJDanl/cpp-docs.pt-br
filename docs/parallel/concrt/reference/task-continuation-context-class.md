---
title: Classe task_continuation_context | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ppltasks/concurrency::task_continuation_context
dev_langs:
- C++
helpviewer_keywords:
- task_continuation_context class
ms.assetid: 1fb5a76a-3682-45c2-a615-8b6b527741f0
caps.latest.revision: 15
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: fc190feb08d9b221cd1cc21a9c91ad567c86c848
ms.openlocfilehash: 627c2adc60c143ef7cd9be62f71a4365eed5aed5
ms.lasthandoff: 02/25/2017

---
# <a name="taskcontinuationcontext-class"></a>Classe task_continuation_context
A classe `task_continuation_context` permite que você especifique onde gostaria que uma continuação fosse executada. Isso é útil somente para o uso dessa classe por meio de um aplicativo da Windows Store. Para aplicativos que não são da Windows Store, o contexto de execução da continuação da tarefa é determinado pelo tempo de execução e não é configurável.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class task_continuation_context : public details::_ContextCallback;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método get_current_winrt_context](#get_current_winrt_context)|Retorna um objeto de contexto de continuação da tarefa que representa o contexto de thread atual do winrt.|  
|[Método use_arbitrary](#use_arbitrary)|Cria um contexto de continuação da tarefa que permite que o Tempo de execução escolha o contexto de execução para uma continuação.|  
|[Método use_current](#use_current)|Retorna um objeto de contexto de continuação da tarefa que representa o contexto de execução atual.|  
|[Método use_default](#use_default)|Cria o contexto de continuação da tarefa padrão.|  
|[Método use_synchronous_execution](#use_synchronous_execution)|Retorna um objeto de contexto de continuação da tarefa que representa o contexto de execução síncrona.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `_ContextCallback`  
  
 `task_continuation_context`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** ppltasks.h  
  
 **Namespace:** simultaneidade  

## <a name="a-namegetcurrentwinrtcontexta-getcurrentwinrtcontext"></a><a name="get_current_winrt_context"></a>get_current_winrt_context
 Retorna um objeto de contexto de continuação da tarefa que representa o contexto de thread atual do WinRT.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
static task_continuation_context get_current_winrt_context();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 O contexto de thread atual do tempo de execução do Windows. Retorna um task_continuation_context vazio se for chamado de um contexto de execução não - Windows.  
  
## <a name="remarks"></a>Comentários  
 O `get_current_winrt_context` método captura o contexto de thread de tempo de execução do Windows do chamador. Ele retorna um contexto vazio para chamadores não - Windows Runtime.  
  
 O valor retornado por `get_current_winrt_context` pode ser usado para indicar o tempo de execução que a continuação deve ser executado no modelo de apartment do contexto capturado STA vs (MTA), independentemente da tarefa antecedente está ciente apartment. Um compartimento com reconhecimento de tarefa é uma tarefa que decodifica um tempo de execução do Windows `IAsyncInfo` interface ou uma tarefa que é descendente de tal tarefa.  
  
 Esse método é semelhante de `use_current` método, mas ele também está disponível para código C++ nativo sem C + + / suporte à extensão do CX. Ele é destinado para uso por usuários avançados de escrita C + + código de biblioteca CX independente para nativo e chamadores de tempo de execução do Windows. A menos que você precisa dessa funcionalidade, recomendamos o `use_current` método, que só está disponível para o C + + / clientes CX.  
  
  
##  <a name="a-nameusearbitrarya-usearbitrary"></a><a name="use_arbitrary"></a>use_arbitrary 

 Cria um contexto de continuação da tarefa que permite que o Tempo de execução escolha o contexto de execução para uma continuação.  
  
```
static task_continuation_context use_arbitrary();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um contexto de continuação da tarefa que representa um local arbitrário.  
  
### <a name="remarks"></a>Comentários  
 Quando é usado neste contexto de continuação a continuação será executado em um contexto que o runtime decide mesmo se a tarefa antecedente é com reconhecimento de compartimento.  
  
 `use_arbitrary`pode ser usado para desativar o comportamento padrão para uma continuação em uma tarefa com reconhecimento de compartimento criada em um STA.  
  
 Este método só está disponível para aplicativos da Windows Store.  
  
##  <a name="a-nameusecurrenta-usecurrent"></a><a name="use_current"></a>use_current 

 Retorna um objeto de contexto de continuação da tarefa que representa o contexto de execução atual.  
  
```
static task_continuation_context use_current();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O contexto de execução atual.  
  
### <a name="remarks"></a>Comentários  
 Esse método captura o contexto do chamador em tempo de execução do Windows para que as continuações podem ser executadas no apartment à direita.  
  
 O valor retornado por `use_current` pode ser usado para indicar o tempo de execução que a continuação deve ser executado no contexto capturado (STA vs MTA), independentemente se é ou não a tarefa antecedente com reconhecimento de compartimento. Um compartimento com reconhecimento de tarefa é uma tarefa que decodifica um tempo de execução do Windows `IAsyncInfo` interface ou uma tarefa que é descendente de tal tarefa.  
  
 Este método só está disponível para aplicativos da Windows Store.  
  
##  <a name="a-nameusedefaulta-usedefault"></a><a name="use_default"></a>use_default 

 Cria o contexto de continuação da tarefa padrão.  
  
```
static task_continuation_context use_default();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O contexto de continuação do padrão.  
  
### <a name="remarks"></a>Comentários  
 O contexto padrão será usado se você não especificar um contexto de continuação ao chamar o `then` método. Em aplicativos do Windows para Windows 7 e abaixo, bem como aplicativos de área de trabalho no Windows 8 e superior, o tempo de execução determina qual continuações de tarefa serão executado. No entanto, em um aplicativo da Windows Store, o contexto de continuação para uma continuação em uma tarefa com reconhecimento de compartimento padrão é o compartimento onde `then` é invocado.  
  
 Um compartimento com reconhecimento de tarefa é uma tarefa que decodifica um tempo de execução do Windows `IAsyncInfo` interface ou uma tarefa que é descendente de tal tarefa. Portanto, se você agendar uma continuação em uma tarefa com reconhecimento de compartimento em um STA de tempo de execução do Windows, a continuação executará em que STA.  
  
 Uma continuação em uma tarefa com reconhecimento de compartimento não será executado em um contexto que escolhe o tempo de execução.  

## <a name="a-nameusesynchronousexecutiona-taskcontinuationcontextusesynchronousexecution"></a><a name="use_synchronous_execution"></a>task_continuation_context::use_synchronous_execution  
Retorna um objeto de contexto de continuação da tarefa que representa o contexto de execução síncrona.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
static task_continuation_context use_synchronous_execution();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 O contexto de execução síncrona.  
  
## <a name="remarks"></a>Comentários  
 O `use_synchronous_execution` método forçará a tarefa de continuação para execução síncrona no contexto de, causando a conclusão da sua tarefa antecedente.  
  
 Se a tarefa antecedente já foi concluída quando a continuação é anexada, a continuação síncrona executa no contexto que conecta a continuação.  
  
 
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)

