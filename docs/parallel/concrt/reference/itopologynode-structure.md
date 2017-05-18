---
title: Estrutura ITopologyNode | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
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
dev_langs:
- C++
helpviewer_keywords:
- ITopologyNode structure
ms.assetid: 92e7e032-04f6-4c7c-be36-8f9a35fc4734
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 5faef5bd1be6cc02d6614a6f6193c74167a8ff23
ms.openlocfilehash: c0a4e8365d7d0ef9912bb84e4a2a4cfe7e9ef0f1
ms.contentlocale: pt-br
ms.lasthandoff: 03/17/2017

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
|[Getexecutionresourcecount](#getexecutionresourcecount)|Retorna o número de recursos de execução agrupados sob este nó.|  
|[Getfirstexecutionresource](#getfirstexecutionresource)|Retorna o primeiro recurso de execução agrupado sob esse nó na ordem de enumeração.|  
|[Itopologynode](#getid)|Retorna o identificador exclusivo do Gerenciador de recursos desse nó.|  
|[Itopologynode](#getnext)|Retorna uma interface para o próximo nó de topologia na ordem de enumeração.|  
|[Getnumanode](#getnumanode)|Retorna o Windows atribuído ao qual pertence este nó Maanger do recurso de número de nó NUMA.|  
  
## <a name="remarks"></a>Comentários  
 Essa interface é normalmente usada para percorrer a topologia do sistema observado pelo Gerenciador de recursos.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `ITopologyNode`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrtrm. h  
  
 **Namespace:** simultaneidade  
  
##  <a name="getexecutionresourcecount"></a>Método Getexecutionresourcecount  
 Retorna o número de recursos de execução agrupados sob este nó.  
  
```
virtual unsigned int GetExecutionResourceCount() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de recursos de execução agrupados sob este nó.  
  
##  <a name="getfirstexecutionresource"></a>Método Getfirstexecutionresource  
 Retorna o primeiro recurso de execução agrupado sob esse nó na ordem de enumeração.  
  
```
virtual ITopologyExecutionResource *GetFirstExecutionResource() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O primeiro recurso de execução agrupados sob esse nó na ordem de enumeração.  
  
##  <a name="getid"></a>Método Itopologynode::  
 Retorna o identificador exclusivo do Gerenciador de recursos desse nó.  
  
```
virtual unsigned int GetId() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O Gerenciador de recursos do identificador exclusivo para este nó.  
  
### <a name="remarks"></a>Comentários  
 O tempo de execução de simultaneidade representa segmentos de hardware do sistema em grupos de nós de processador. Nós geralmente são derivados da topologia do hardware do sistema. Por exemplo, todos os processadores em um soquete específico ou um nó NUMA específico podem pertencer ao mesmo nó do processador. O Gerenciador de recursos atribui identificadores exclusivos para esses nós começando com `0` até e incluindo `nodeCount - 1`, onde `nodeCount` representa o número total de nós de processador no sistema.  
  
 A contagem de nós pode ser obtida da função [GetProcessorNodeCount](concurrency-namespace-functions.md).  
  
##  <a name="getnext"></a>Método Itopologynode::  
 Retorna uma interface para o próximo nó de topologia na ordem de enumeração.  
  
```
virtual ITopologyNode *GetNext() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma interface para o próximo nó na ordem de enumeração. Não se houver mais nenhum nó na ordem de enumeração da topologia do sistema, este método retornará o valor `NULL`.  
  
##  <a name="getnumanode"></a>Método Getnumanode  
 Retorna o Windows atribuído ao qual pertence este nó Maanger do recurso de número de nó NUMA.  
  
```
virtual unsigned long GetNumaNode() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O Windows atribuído ao qual pertence este nó do Gerenciador de recursos de número de nó NUMA.  
  
### <a name="remarks"></a>Comentários  
 Um proxy de thread em execução em uma raiz de processador virtual pertencentes a esse nó terá afinidade com pelo menos o nível de nó do nó NUMA retornado por esse método.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)

