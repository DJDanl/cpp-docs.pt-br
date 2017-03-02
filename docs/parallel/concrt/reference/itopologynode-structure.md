---
title: Estrutura ITopologyNode | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- concrtrm/concurrency::ITopologyNode
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
translationtype: Machine Translation
ms.sourcegitcommit: fa774c7f025b581d65c28d65d83e22ff2d798230
ms.openlocfilehash: 8274da148f9f74cad73d63363bbbaff307943539
ms.lasthandoff: 02/25/2017

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
|[Método Getexecutionresourcecount](#getexecutionresourcecount)|Retorna o número de recursos de execução agrupados sob este nó.|  
|[Método Getfirstexecutionresource](#getfirstexecutionresource)|Retorna o primeiro recurso de execução agrupado sob esse nó na ordem de enumeração.|  
|[Método Itopologynode::](#getid)|Retorna o identificador exclusivo do Gerenciador de recursos desse nó.|  
|[Método Itopologynode::](#getnext)|Retorna uma interface para o próximo nó de topologia na ordem de enumeração.|  
|[Método Getnumanode](#getnumanode)|Retorna o Windows atribuído ao qual pertence este nó Maanger do recurso de número de nó NUMA.|  
  
## <a name="remarks"></a>Comentários  
 Essa interface é normalmente usada para percorrer a topologia do sistema observado pelo Gerenciador de recursos.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `ITopologyNode`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrtrm. h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-namegetexecutionresourcecounta--itopologynodegetexecutionresourcecount-method"></a><a name="getexecutionresourcecount"></a>Método Getexecutionresourcecount  
 Retorna o número de recursos de execução agrupados sob este nó.  
  
```
virtual unsigned int GetExecutionResourceCount() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de recursos de execução agrupados sob este nó.  
  
##  <a name="a-namegetfirstexecutionresourcea--itopologynodegetfirstexecutionresource-method"></a><a name="getfirstexecutionresource"></a>Método Getfirstexecutionresource  
 Retorna o primeiro recurso de execução agrupado sob esse nó na ordem de enumeração.  
  
```
virtual ITopologyExecutionResource *GetFirstExecutionResource() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O primeiro recurso de execução agrupados sob esse nó na ordem de enumeração.  
  
##  <a name="a-namegetida--itopologynodegetid-method"></a><a name="getid"></a>Método Itopologynode::  
 Retorna o identificador exclusivo do Gerenciador de recursos desse nó.  
  
```
virtual unsigned int GetId() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O Gerenciador de recursos do identificador exclusivo para este nó.  
  
### <a name="remarks"></a>Comentários  
 O tempo de execução de simultaneidade representa segmentos de hardware do sistema em grupos de nós de processador. Nós geralmente são derivados da topologia do hardware do sistema. Por exemplo, todos os processadores em um soquete específico ou um nó NUMA específico podem pertencer ao mesmo nó do processador. O Gerenciador de recursos atribui identificadores exclusivos para esses nós começando com `0` até e incluindo `nodeCount - 1`, onde `nodeCount` representa o número total de nós de processador no sistema.  
  
 A contagem de nós pode ser obtida da função [GetProcessorNodeCount](concurrency-namespace-functions.md).  
  
##  <a name="a-namegetnexta--itopologynodegetnext-method"></a><a name="getnext"></a>Método Itopologynode::  
 Retorna uma interface para o próximo nó de topologia na ordem de enumeração.  
  
```
virtual ITopologyNode *GetNext() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma interface para o próximo nó na ordem de enumeração. Não se houver mais nenhum nó na ordem de enumeração da topologia do sistema, este método retornará o valor `NULL`.  
  
##  <a name="a-namegetnumanodea--itopologynodegetnumanode-method"></a><a name="getnumanode"></a>Método Getnumanode  
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

