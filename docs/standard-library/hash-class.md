---
title: Classe hash | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- hash
- std::hash
- functional/std::hash
- bitset/std::hash
- memory/std::hash
- string/std::hash
- system_error/std::hash
- thread/std::hash
- typeindex/std::hash
- vector/std::hash
- XSTDDEF/std::hash
- xstring/std::hash
dev_langs:
- C++
helpviewer_keywords:
- hash class
ms.assetid: e1b500c6-a5c8-4f6f-ad33-7ec52eb8e2e4
caps.latest.revision: 21
author: corob-msft
ms.author: corob
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
ms.sourcegitcommit: 28baed4badda4f2c1d7e5b20235fe8d40c2a7195
ms.openlocfilehash: d549fb7aeed268327122532e6c4390ac931740e7
ms.lasthandoff: 02/25/2017

---
# <a name="hash-class"></a>Classe hash
Calcula o código hash de um valor.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Ty>  
struct hash {  
    size_t operator()(Ty val) const; 
};  
```  
  
## <a name="remarks"></a>Comentários  
O objeto de função define uma função de hash adequada para mapear valores do tipo *Ty* para uma distribuição de valores de índice. O membro `operator()` retorna um código hash para *val*, adequado para uso com as classes de modelo `unordered_map`, `unordered_multimap`, `unordered_set` e `unordered_multiset`. A biblioteca padrão oferece especializações para tipos básicos: *Ty* pode ser qualquer tipo escalar, incluindo tipos de ponteiro e tipos de enumeração. Além disso, há especializações para os tipos de biblioteca `string`, `wstring`, `u16string`, `u32string`, `string_view`, `wstring_view`, `u16string_view`, `u32string_view`, `bitset`, `error_code`, `error_condition`, `optional`, `shared_ptr`, `thread`, `type_index`, `unique_ptr`, `variant` e `vector<bool>`.  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// std__functional__hash.cpp   
// compile with: /EHsc   
#include <functional>   
#include <iostream>   
#include <unordered_set>   
  
int main()   
    {   
    std::unordered_set<int, std::hash<int> > c0;   
    c0.insert(3);   
    std::cout << *c0.find(3) << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
3  
```  
  
## <a name="requirements"></a>Requisitos  
**Cabeçalho:** \<functional>  
  
**Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [<unordered_map>](../standard-library/unordered-map.md)   
 [Classe unordered_multimap](../standard-library/unordered-multimap-class.md)   
 [Classe unordered_multiset](../standard-library/unordered-multiset-class.md)   
 [<unordered_set>](../standard-library/unordered-set.md)


