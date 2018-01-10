---
title: Estrutura ITopologyNode | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ITopologyNode
- CONCRTRM/concurrency::ITopologyNode
- CONCRTRM/concurrency::ITopologyNode::ITopologyNode::GetExecutionResourceCount
- CONCRTRM/concurrency::ITopologyNode::ITopologyNode::GetFirstExecutionResource
- CONCRTRM/concurrency::ITopologyNode::ITopologyNode::GetId
- CONCRTRM/concurrency::ITopologyNode::ITopologyNode::GetNext
- CONCRTRM/concurrency::ITopologyNode::ITopologyNode::GetNumaNode
dev_langs: C++
helpviewer_keywords: ITopologyNode structure
ms.assetid: 92e7e032-04f6-4c7c-be36-8f9a35fc4734
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9c2e989dca783e90d975bd46a6f5f44cdfa469ef
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="itopologynode-structure"></a>Estrutura ITopologyNode
Uma interface para um nó de topologia, conforme definido pelo Gerenciador de recursos. Um nó contém um ou mais recursos de execução.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct ITopologyNode;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[: Getexecutionresourcecount](#getexecutionresourcecount)|Retorna o número de recursos de execução agrupadas sob este nó.|  
|[: Getfirstexecutionresource](#getfirstexecutionresource)|Retorna o primeiro recurso execução agrupado sob este nó na ordem de enumeração.|  
|[Itopologynode](#getid)|Retorna os recursos do Gerenciador identificador exclusivo para este nó.|  
|[Itopologynode](#getnext)|Retorna uma interface para o próximo nó da topologia na ordem de enumeração.|  
|[: Getnumanode](#getnumanode)|Retorna o Windows atribuído ao qual pertence este nó Maanger do recurso de número de nó NUMA.|  
  
## <a name="remarks"></a>Comentários  
 Essa interface é normalmente usada para passar a topologia do sistema, como observado pelo Gerenciador de recursos.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `ITopologyNode`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrtrm.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="getexecutionresourcecount"></a>Método: Getexecutionresourcecount  
 Retorna o número de recursos de execução agrupadas sob este nó.  
  
```
virtual unsigned int GetExecutionResourceCount() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de recursos de execução agrupadas sob este nó.  
  
##  <a name="getfirstexecutionresource"></a>Método: Getfirstexecutionresource  
 Retorna o primeiro recurso execução agrupado sob este nó na ordem de enumeração.  
  
```
virtual ITopologyExecutionResource *GetFirstExecutionResource() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O primeiro recurso execução agrupadas sob este nó na ordem de enumeração.  
  
##  <a name="getid"></a>Método Itopologynode:  
 Retorna os recursos do Gerenciador identificador exclusivo para este nó.  
  
```
virtual unsigned int GetId() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O Gerenciador de recursos do identificador exclusivo para este nó.  
  
### <a name="remarks"></a>Comentários  
 O tempo de execução de simultaneidade representa threads de hardware do sistema em grupos de nós de processador. Nós geralmente são derivados da topologia do hardware do sistema. Por exemplo, todos os processadores em um soquete específico ou um nó NUMA específico podem pertencer ao mesmo nó de processador. O Gerenciador de recursos atribui identificadores exclusivos para esses nós começando com `0` até e inclusive `nodeCount - 1`, onde `nodeCount` representa o número total de nós de processador no sistema.  
  
 A contagem de nós pode ser obtida da função [GetProcessorNodeCount](concurrency-namespace-functions.md).  
  
##  <a name="getnext"></a>Método Itopologynode:  
 Retorna uma interface para o próximo nó da topologia na ordem de enumeração.  
  
```
virtual ITopologyNode *GetNext() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma interface para o próximo nó na ordem de enumeração. Não se houver mais nenhum nó na ordem de enumeração da topologia do sistema, esse método retornará o valor `NULL`.  
  
##  <a name="getnumanode"></a>Método: Getnumanode  
 Retorna o Windows atribuído ao qual pertence este nó Maanger do recurso de número de nó NUMA.  
  
```
virtual unsigned long GetNumaNode() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O Windows atribuído ao qual pertence este nó do Gerenciador de recursos de número de nó NUMA.  
  
### <a name="remarks"></a>Comentários  
 Um proxy de thread em execução em uma raiz de processador virtual que pertencem a esse nó terá afinidade com pelo menos o nível de nó para o nó NUMA retornada por este método.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)
