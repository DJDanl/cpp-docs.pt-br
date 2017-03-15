---
title: Classe auto_partitioner | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ppl/concurrency::auto_partitioner
dev_langs:
- C++
helpviewer_keywords:
- auto_partitioner class
ms.assetid: 7cc08e5d-20b4-47a4-b4b5-c214a78f5a9e
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
translationtype: Machine Translation
ms.sourcegitcommit: fc190feb08d9b221cd1cc21a9c91ad567c86c848
ms.openlocfilehash: 8092a0d6c4fe6053a3bb7e80e659ab6a7628664a
ms.lasthandoff: 02/25/2017

---
# <a name="autopartitioner-class"></a>Classe auto_partitioner
O `auto_partitioner` classe representa o método padrão `parallel_for`, `parallel_for_each` e `parallel_transform` usar para o intervalo que itera através de partição. Esse método de particionamento employes roubo de balanceamento de carga de intervalo, bem como por-iterar cancelamento.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class auto_partitioner;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor auto_partitioner](#ctor)|Constrói um objeto `auto_partitioner`.|  
|[~ auto_partitioner destruidor](#dtor)|Destrói um objeto `auto_partitioner`.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `auto_partitioner`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** ppl.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-namedtora-autopartitioner"></a><a name="dtor"></a>~ auto_partitioner 

 Destrói um objeto `auto_partitioner`.  
  
```
~auto_partitioner();
```  
  
##  <a name="a-namectora-autopartitioner"></a><a name="ctor"></a>auto_partitioner 

 Constrói um objeto `auto_partitioner`.  
  
```
auto_partitioner();
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)

