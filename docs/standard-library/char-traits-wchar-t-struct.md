---
title: Struct char_traits&lt;wchar_t&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- std.char_traits<wchar_t>
- char_traits<wchar_t>
- string/std::char_traits<wchar_t>
- std::char_traits<wchar_t>
dev_langs:
- C++
helpviewer_keywords:
- char_traits<wchar_t> class
ms.assetid: 31f34072-04d6-4871-88fe-48e17d473484
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
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 14d43585a5a18305a73f7edc995d9ae17106ef39
ms.lasthandoff: 02/25/2017

---
# <a name="chartraitsltwchartgt-struct"></a>Struct char_traits&lt;wchar_t&gt;
Uma classe que é uma especialização da struct de modelo **char_traits\<CharType>** para um elemento do tipo `wchar_t`.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <>  
struct char_traits<wchar_t>;
```  
  
## <a name="remarks"></a>Comentários  
 A especialização permite que a struct aproveite funções de biblioteca que manipulam objetos desse tipo `wchar_t`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<string>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Struct char_traits](../standard-library/char-traits-struct.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)




