---
title: Typedefs &lt;istream&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- istream/std::iostream
- istream/std::istream
- istream/std::wiostream
- istream/std::wistream
ms.assetid: 55bc1f84-53a7-46ca-a36f-ac6ef75d0374
caps.latest.revision: 10
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 65f4e356ad0d46333b0d443d0fd6ac0b9f2b6f58
ms.openlocfilehash: cc53eb1fed0dfc562ddb59ad239d716dd6057ebd
ms.contentlocale: pt-br
ms.lasthandoff: 10/03/2017

---
# <a name="ltistreamgt-typedefs"></a>Typedefs &lt;istream&gt;
||||  
|-|-|-|  
|[iostream](#iostream)|[istream](#istream)|[wiostream](#wiostream)|  
|[wistream](#wistream)|  
  
##  <a name="iostream"></a>  iostream  
 Um tipo `basic_iostream` especializado em `char`.  
  
```  
typedef basic_iostream<char, char_traits<char>> iostream;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo da classe de modelo [basic_iostream](../standard-library/basic-iostream-class.md), especializado para elementos do tipo `char` com características de caractere padrão.  
  
##  <a name="istream"></a>  istream  
 Um tipo `basic_istream` especializado em `char`.  
  
```  
typedef basic_istream<char, char_traits<char>> istream;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo da classe de modelo [basic_istream](../standard-library/basic-istream-class.md), especializado para elementos do tipo `char` com características de caractere padrão.  
  
##  <a name="wiostream"></a>  wiostream  
 Um tipo `basic_iostream` especializado em `wchar_t`.  
  
```  
typedef basic_iostream<wchar_t, char_traits<wchar_t>> wiostream;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo da classe de modelo [basic_iostream](../standard-library/basic-iostream-class.md), especializado para elementos do tipo `wchar_t` com características de caractere padrão.  
  
##  <a name="wistream"></a>  wistream  
 Um tipo `basic_istream` especializado em `wchar_t`.  
  
```  
typedef basic_istream<wchar_t, char_traits<wchar_t>> wistream;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo da classe de modelo [basic_istream](../standard-library/basic-istream-class.md), especializado para elementos do tipo `wchar_t` com características de caractere padrão.  
  
## <a name="see-also"></a>Consulte também  
 [\<istream>](../standard-library/istream.md)


