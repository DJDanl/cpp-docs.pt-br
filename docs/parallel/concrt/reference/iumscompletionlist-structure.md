---
title: Estrutura IUMSCompletionList | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- concrtrm/concurrency::IUMSCompletionList
dev_langs:
- C++
helpviewer_keywords:
- IUMSCompletionList structure
ms.assetid: 81b5250e-3065-492c-b20d-2cdabf12271a
caps.latest.revision: 19
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
ms.sourcegitcommit: fa774c7f025b581d65c28d65d83e22ff2d798230
ms.openlocfilehash: 25023c27244669092e0f57fe59bdb190fd2f2afb
ms.lasthandoff: 02/25/2017

---
# <a name="iumscompletionlist-structure"></a>Estrutura IUMSCompletionList
Representa uma lista de conclusão UMS. Quando bloqueia um thread UMS, o Agendador designado de agendamento de contexto é despachado para tomar uma decisão do que agendar na raiz do processador virtual subjacente enquanto o thread original está bloqueado. Quando o thread original desbloqueia, o sistema operacional enfileira à lista de conclusão que pode ser acessada por meio dessa interface. O Agendador pode consultar a lista de conclusão no contexto de programação designado ou qualquer outro lugar, que ele procura por trabalho.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct IUMSCompletionList;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método Getunblocknotifications](#getunblocknotifications)|Recupera uma cadeia de `IUMSUnblockNotification` interfaces que representa os contextos de execução cujo thread associado proxies tiveram desbloqueado desde a última vez que esse método foi chamado.|  
  
## <a name="remarks"></a>Comentários  
 Um programador deve ser extremamente cuidadoso com os quais ações são executadas depois de utilizar essa interface para remover itens da lista de conclusão. Os itens devem ser colocados na lista do Agendador de contextos de execução e ser acessível geralmente assim que possível. É inteiramente possível que um dos itens da fila tem a propriedade de um bloqueio arbitrário. O Agendador não pode fazer nenhuma chamadas de função arbitrário que podem bloquear entre a chamada para remoção da fila de itens e o posicionamento desses itens em uma lista que podem ser acessados em geral de dentro do Agendador.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IUMSCompletionList`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrtrm. h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-namegetunblocknotificationsa--iumscompletionlistgetunblocknotifications-method"></a><a name="getunblocknotifications"></a>Método Getunblocknotifications  
 Recupera uma cadeia de `IUMSUnblockNotification` interfaces que representa os contextos de execução cujo thread associado proxies tiveram desbloqueado desde a última vez que esse método foi chamado.  
  
```
virtual IUMSUnblockNotification *GetUnblockNotifications() = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cadeia de `IUMSUnblockNotification` interfaces.  
  
### <a name="remarks"></a>Comentários  
 As notificações retornadas são inválidas depois que os contextos de execução são reagendados.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Estrutura IUMSScheduler](iumsscheduler-structure.md)   
 [Estrutura IUMSUnblockNotification](iumsunblocknotification-structure.md)

