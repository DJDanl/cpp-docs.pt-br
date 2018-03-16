---
title: scheduler_ptr estrutura | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- scheduler_ptr
- PPLINTERFACE/concurrency::scheduler_ptr
- PPLINTERFACE/concurrency::scheduler_ptr::scheduler_ptr::scheduler_ptr
- PPLINTERFACE/concurrency::scheduler_ptr::scheduler_ptr::get
- PPLINTERFACE/concurrency::scheduler_ptr::scheduler_ptr::operator bool
dev_langs:
- C++
ms.assetid: e88c84af-c306-476d-aef1-f42a0fa0a80f
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 257dcae6df4deb0a52f7dee4db98adba2b2b4f29
ms.sourcegitcommit: 9239c52c05e5cd19b6a72005372179587a47a8e4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2018
---
# <a name="schedulerptr-structure"></a>scheduler_ptr estrutura
Representa um ponteiro para um agendador. Esta classe existe para permitir a especificação de um tempo de vida compartilhada usando shared_ptr ou apenas uma referência simples ponteiro bruto.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct scheduler_ptr;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[scheduler_ptr::scheduler_ptr](#ctor)|Sobrecarregado. Cria um ponteiro de Agendador do shared_ptr para Agendador|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[scheduler_ptr::get](#get)|Retorna o ponteiro bruto para o Agendador|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[scheduler_ptr:: Operator bool](#operator_bool)|Testar se o ponteiro do Agendador é não nulo|  
|[scheduler_ptr::operator-&gt;](#operator_ptr)|Se comportam como um ponteiro|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `scheduler_ptr`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** pplinterface.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="get"></a>  scheduler_ptr:: método Get  
 Retorna o ponteiro bruto para o Agendador  
  
```
scheduler_interface* get() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
  
##  <a name="operator_bool"></a>  scheduler_ptr:: Operator bool   
 Testar se o ponteiro do Agendador é não nulo  
  
' ' operador bool() const;
```  
  
##  <a name="operator_ptr"></a>  scheduler_ptr::operator-&gt;   
 Behave like a pointer  
  
```
scheduler_interface * operador -> () const;
```  
  
### Return Value  
  
##  <a name="ctor"></a>  scheduler_ptr::scheduler_ptr Constructor  
 Creates a scheduler pointer from shared_ptr to scheduler  
  
```
scheduler_ptr explícita (Agendador std:: shared_ptr < scheduler_interface >);

scheduler_ptr explícita (_In_opt_ scheduler_interface * pScheduler);
```  
  
### Parameters  
 `scheduler`  
 `pScheduler`  
  
## See Also  
 [concurrency Namespace](concurrency-namespace.md)
