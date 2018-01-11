---
title: Classe discard_block_engine | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: random/std::discard_block_engine
dev_langs: C++
helpviewer_keywords: discard_block_engine class
ms.assetid: aa84808e-38fe-4fa0-9f73-d5b9a653345b
caps.latest.revision: "18"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ca21ef820c4dfe713a5a9b0c969ac0b14e3efe01
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="discardblockengine-class"></a>Classe discard_block_engine
Gera uma sequência aleatória descartando valores retornados pelo mecanismo de base.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Engine, size_t P, size_t R>  
class discard_block_engine;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Engine`  
 O tipo de mecanismo de base.  
  
 `P`  
 **Tamanho do bloco**. O número de valores em cada bloco.  
  
 `R`  
 **Bloco usado**. O número de valores em cada bloco usado. O restante é descartado (`P` - `R`). **Pré-condição**: `0 < R ≤ P`  
  
## <a name="members"></a>Membros  
  
||||  
|-|-|-|  
|`discard_block_engine::discard_block_engine`|`discard_block_engine::base`|`discard_block_engine::discard`|  
|`discard_block_engine::operator()`|`discard_block_engine::base_type`|`discard_block_engine::seed`|  
  
 Para obter mais informações sobre membros do mecanismo, consulte [\<random>](../standard-library/random.md).  
  
## <a name="remarks"></a>Comentários  
 Essa classe de modelo descreve um adaptador de mecanismo que produz valores descartando alguns dos valores retornados pelo mecanismo de base.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<random>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [\<random>](../standard-library/random.md)

