---
title: Estrutura ITopologyExecutionResource | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ITopologyExecutionResource
- CONCRTRM/concurrency::ITopologyExecutionResource
- CONCRTRM/concurrency::ITopologyExecutionResource::ITopologyExecutionResource::GetId
- CONCRTRM/concurrency::ITopologyExecutionResource::ITopologyExecutionResource::GetNext
dev_langs: C++
helpviewer_keywords: ITopologyExecutionResource structure
ms.assetid: e36756f7-4cd9-4fa6-ba60-23fea58ef2bf
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 9ffe0e2d8f4c26274a71082bec2cecaf19acb1af
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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
|[Itopologyexecutionresource](#getid)|Retorna os recursos do Gerenciador identificador exclusivo para este recurso de execução.|  
|[Itopologyexecutionresource](#getnext)|Retorna uma interface para o próximo recurso de execução na ordem de enumeração.|  
  
## <a name="remarks"></a>Comentários  
 Essa interface é normalmente usada para passar a topologia do sistema, como observado pelo Gerenciador de recursos.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `ITopologyExecutionResource`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrtrm.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="getid"></a>Método Itopologyexecutionresource:  
 Retorna os recursos do Gerenciador identificador exclusivo para este recurso de execução.  
  
```
virtual unsigned int GetId() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O Gerenciador de recursos do identificador exclusivo para este recurso de execução.  
  
##  <a name="getnext"></a>Método Itopologyexecutionresource:  
 Retorna uma interface para o próximo recurso de execução na ordem de enumeração.  
  
```
virtual ITopologyExecutionResource *GetNext() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma interface para o próximo recurso de execução na ordem de enumeração. Não se houver mais nenhum nó na ordem de enumeração do nó ao qual pertence este recurso de execução, esse método retornará o valor `NULL`.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)
