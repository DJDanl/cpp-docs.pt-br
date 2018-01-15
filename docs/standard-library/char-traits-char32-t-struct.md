---
title: Struct char_traits&lt;char32_t&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- iosfwd/std::char_traits<char_32t>
- char_traits<char32_t>
dev_langs: C++
helpviewer_keywords: char_traits<char32_t> class
ms.assetid: c0315466-45d0-4a99-b83e-3b1dbfbfbbc3
caps.latest.revision: "14"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 8a6b315da89f94da232f5d0ed44a9e3351f41824
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="chartraitsltchar32tgt-struct"></a>Struct char_traits&lt;char32_t&gt;
Uma struct é uma especialização da struct de modelo **char_traits\<CharType>** para um elemento do tipo `char32_t`.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <>  
struct char_traits<char32_t>;
```  
  
## <a name="remarks"></a>Comentários  
 A especialização permite que a struct aproveite funções de biblioteca que manipulam objetos desse tipo `char32_t`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<string>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [\<string>](../standard-library/string.md)   
 [Struct char_traits](../standard-library/char-traits-struct.md)
