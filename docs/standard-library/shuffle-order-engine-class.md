---
title: Classe shuffle_order_engines | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- shuffle_order_engine
- random/std::shuffle_order_engine
- random/std::shuffle_order_engine::base
- random/std::shuffle_order_engine::discard
- random/std::shuffle_order_engine::operator()
- random/std::shuffle_order_engine::base_type
- random/std::shuffle_order_engine::seed
dev_langs:
- C++
helpviewer_keywords:
- shuffle_order_engine class
ms.assetid: 0bcd1fb0-44d7-4e59-bb1b-4a9b673a960d
caps.latest.revision: 17
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
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
ms.sourcegitcommit: 41b445ceeeb1f37ee9873cb55f62d30d480d8718
ms.openlocfilehash: c4cb4367968c89c42df8580efef06db052c49396
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="shuffleorderengine-class"></a>Classe shuffle_order_engine
Gera uma sequência aleatória reordenando os valores retornados pelo mecanismo de base.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Engine, size_t K>  
class shuffle_order_engine;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Engine`  
 O tipo de mecanismo de base.  
  
 `K`  
 **Tamanho da tabela**. Número de elementos no buffer (tabela). **Pré-condição**: `0 < K`  
  
## <a name="members"></a>Membros  
  
||||  
|-|-|-|  
|`shuffle_order_engine::shuffle_order_engine`|`shuffle_order_engine::base`|`shuffle_order_engine::discard`|  
|`shuffle_order_engine::operator()`|`shuffle_order_engine::base_type`|`shuffle_order_engine::seed`|  
  
 Para obter mais informações sobre membros do mecanismo, consulte [\<random>](../standard-library/random.md).  
  
## <a name="remarks"></a>Comentários  
 Essa classe de modelo descreve um *adaptador de mecanismo* que produz valores ao reorganizar os valores retornados por seu mecanismo básico. Cada construtor preenche a tabela interna com os valores `K` retornados pelo mecanismo básico. Além disso, um elemento aleatório é selecionado na tabela quando um valor é solicitado.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<random>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [\<random>](../standard-library/random.md)


