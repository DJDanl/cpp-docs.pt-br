---
title: Struct char_traits&lt;char16_t&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- char_traits<char16_t>
- iosfwd/std::char_traits<char16_t>
dev_langs: C++
helpviewer_keywords: char_traits<char16_t> class
ms.assetid: 5daf3b62-dd6e-451f-b189-0350a04ff966
caps.latest.revision: "15"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 245ce0febf1a19e0bbb93c5d72584b26e23f6dfc
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="chartraitsltchar16tgt-struct"></a>Struct char_traits&lt;char16_t&gt;
Uma struct é uma especialização da struct de modelo **char_traits\<CharType>** para um elemento do tipo `char16_t`.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <>  
struct char_traits<char16_t>;
```  
  
## <a name="remarks"></a>Comentários  
 A especialização permite que a struct aproveite funções de biblioteca que manipulam objetos do tipo `char16_t`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<string>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [\<string>](../standard-library/string.md)   
 [Struct char_traits](../standard-library/char-traits-struct.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)



