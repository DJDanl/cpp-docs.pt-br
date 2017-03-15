---
title: Estrutura hash | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- typeindex/std::hash
dev_langs:
- C++
ms.assetid: e5a41202-ef3b-45d0-b3a7-4c2dbdc0487a
caps.latest.revision: 13
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 2b2f4ebb7a96f9e9a79f1bce2ab1fb80ad94c911
ms.lasthandoff: 02/25/2017

---
# <a name="hash-structure"></a>Estrutura hash
A classe de modelo define seu método como um `val.hash_code()` de retorno. O método define uma função de hash que é usada para mapear valores do tipo [type_index](../standard-library/type-index-class.md) para uma distribuição de valores de índice.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <>
struct hash<type_index>  
: public unary_function<type_index, size_t>
 { // hashes a typeinfo object
    size_t operator()(type_index val) const;

 };
```  
  
## <a name="see-also"></a>Consulte também  
 [\<typeindex>](../standard-library/typeindex.md)




