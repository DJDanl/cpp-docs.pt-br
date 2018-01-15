---
title: Struct char_traits&lt;wchar_t&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- char_traits<wchar_t>
- iosfwd/std::char_traits<wchar_t>
dev_langs: C++
helpviewer_keywords: char_traits<wchar_t> class
ms.assetid: 31f34072-04d6-4871-88fe-48e17d473484
caps.latest.revision: "21"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ea9e39defefae6133f73262c90f0da9db3ea2edf
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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



