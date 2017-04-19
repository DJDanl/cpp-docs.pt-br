---
title: Typedefs &lt;ostream&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ostream/std::ostream
- ostream/std::wostream
ms.assetid: 2ec4dc52-a01f-4654-bd65-dd5288777c48
caps.latest.revision: 11
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 310954b0965be071c288f09de058e3cebe3ce27d
ms.lasthandoff: 02/25/2017

---
# <a name="ltostreamgt-typedefs"></a>Typedefs &lt;ostream&gt;
|||  
|-|-|  
|[ostream](#ostream)|[wostream](#wostream)|  
  
##  <a name="ostream"></a>  ostream  
 Cria um tipo de basic_ostream que é especializado em `char` e `char_traits` é especializado em `char`.  
  
```
typedef basic_ostream<char, char_traits<char>> ostream;
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo da classe de modelo [basic_ostream](../standard-library/basic-ostream-class.md), especializado para elementos do tipo `char` com características de caractere padrão.  
  
##  <a name="wostream"></a>  wostream  
 Cria um tipo de basic_ostream que é especializado em `wchar_t` e `char_traits` é especializado em `wchar_t`.  
  
```
typedef basic_ostream<wchar_t, char_traits<wchar_t>> wostream;
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo da classe de modelo [basic_ostream](../standard-library/basic-ostream-class.md), especializado para elementos do tipo `wchar_t` com características de caractere padrão.  
  
## <a name="see-also"></a>Consulte também  
 [\<ostream>](../standard-library/ostream.md)




