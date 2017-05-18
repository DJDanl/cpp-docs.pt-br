---
title: scheduler_ptr estrutura | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- scheduler_ptr
- PPLINTERFACE/concurrency::scheduler_ptr
- PPLINTERFACE/concurrency::scheduler_ptr::scheduler_ptr::scheduler_ptr
- PPLINTERFACE/concurrency::scheduler_ptr::scheduler_ptr::get
- PPLINTERFACE/concurrency::scheduler_ptr::scheduler_ptr::operator bool
dev_langs:
- C++
ms.assetid: e88c84af-c306-476d-aef1-f42a0fa0a80f
caps.latest.revision: 8
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
ms.openlocfilehash: 4bef1995724d078c9702669806ff61d5563ac465
ms.contentlocale: pt-br
ms.lasthandoff: 03/17/2017

---
# <a name="schedulerptr-structure"></a>scheduler_ptr estrutura
Representa um ponteiro para um agendador. Esta classe existe para permitir a especificação de um tempo de vida compartilhada usando shared_ptr ou apenas uma referência simples usando o ponteiro bruto.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct scheduler_ptr;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[scheduler_ptr:: scheduler_ptr](#ctor)|Sobrecarregado. Cria um ponteiro de Agendador de shared_ptr para Agendador|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[scheduler_ptr:: Get](#get)|Retorna o ponteiro bruto ao Agendador|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[scheduler_ptr:: Operator bool](#operator_bool)|Testar se o ponteiro do Agendador é não-nulo|  
|[scheduler_ptr:: Operator-&gt;](#operator_ptr)|Se comportam como um ponteiro|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `scheduler_ptr`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** pplinterface.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="get"></a>scheduler_ptr:: método Get  
 Retorna o ponteiro bruto ao Agendador  
  
```
scheduler_interface* get() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
  
##  <a name="operator_bool"></a>scheduler_ptr:: Operator bool   
 Testar se o ponteiro do Agendador é não-nulo  
  
' ' operador bool() const;
```  
  
##  <a name="operator_ptr"></a>  scheduler_ptr::operator-&gt;   
 Behave like a pointer  
  
```
scheduler_interface * operator->() const;
```  
  
### Return Value  
  
##  <a name="ctor"></a>  scheduler_ptr::scheduler_ptr Constructor  
 Creates a scheduler pointer from shared_ptr to scheduler  
  
```
explícita scheduler_ptr(std::shared_ptr<scheduler_interface> scheduler);</scheduler_interface>

scheduler_ptr explícita (_In_opt_ scheduler_interface * pScheduler);
```  
  
### Parameters  
 `scheduler`  
 `pScheduler`  
  
## See Also  
 [concurrency Namespace](concurrency-namespace.md)

