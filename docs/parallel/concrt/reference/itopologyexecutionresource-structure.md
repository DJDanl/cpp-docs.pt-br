---
title: Estrutura ITopologyExecutionResource | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- concrtrm/concurrency::ITopologyExecutionResource
dev_langs:
- C++
helpviewer_keywords:
- ITopologyExecutionResource structure
ms.assetid: e36756f7-4cd9-4fa6-ba60-23fea58ef2bf
caps.latest.revision: 10
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
ms.openlocfilehash: cc54beb4790c9d2ea5bfcb2c8ffd4bca7dca399e
ms.lasthandoff: 02/25/2017

---
# <a name="itopologyexecutionresource-structure"></a>Estrutura ITopologyExecutionResource
Uma interface para um recurso de execução, conforme definido pelo Gerenciador de recursos.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct ITopologyExecutionResource;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método Itopologyexecutionresource::](#getid)|Retorna os recursos do Gerenciador identificador exclusivo para este recurso de execução.|  
|[Método Itopologyexecutionresource::](#getnext)|Retorna uma interface para o próximo recurso de execução na ordem de enumeração.|  
  
## <a name="remarks"></a>Comentários  
 Essa interface é normalmente usada para percorrer a topologia do sistema observado pelo Gerenciador de recursos.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `ITopologyExecutionResource`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrtrm. h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-namegetida--itopologyexecutionresourcegetid-method"></a><a name="getid"></a>Método Itopologyexecutionresource::  
 Retorna os recursos do Gerenciador identificador exclusivo para este recurso de execução.  
  
```
virtual unsigned int GetId() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O Gerenciador de recursos do identificador exclusivo para este recurso de execução.  
  
##  <a name="a-namegetnexta--itopologyexecutionresourcegetnext-method"></a><a name="getnext"></a>Método Itopologyexecutionresource::  
 Retorna uma interface para o próximo recurso de execução na ordem de enumeração.  
  
```
virtual ITopologyExecutionResource *GetNext() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma interface para o próximo recurso de execução na ordem de enumeração. Não se houver mais nenhum nó na ordem de enumeração do nó ao qual pertence este recurso de execução, esse método retornará o valor `NULL`.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)

