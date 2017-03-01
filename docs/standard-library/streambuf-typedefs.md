---
title: Typedefs &lt;streambuf&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 2678e18f-f0f0-4995-bc53-f1bc7dfc4ec6
caps.latest.revision: 11
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 8a11f21fc55babc7c71bb312bc582719f532347a
ms.lasthandoff: 02/25/2017

---
# <a name="ltstreambufgt-typedefs"></a>Typedefs &lt;streambuf&gt;
|||  
|-|-|  
|[streambuf](#streambuf)|[wstreambuf](#wstreambuf)|  
  
##  <a name="a-namestreambufa--streambuf"></a><a name="streambuf"></a>  streambuf  
 Uma especialização de `basic_streambuf` que usa `char` como os parâmetros do modelo.  
  
```
typedef basic_streambuf<char, char_traits<char>> streambuf;
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo da classe de modelo [basic_streambuf](../standard-library/basic-streambuf-class.md), especializado para elementos do tipo `char` com características de caractere padrão.  
  
##  <a name="a-namewstreambufa--wstreambuf"></a><a name="wstreambuf"></a>  wstreambuf  
 Uma especialização de `basic_streambuf` que usa `wchar_t` como os parâmetros do modelo.  
  
```
typedef basic_streambuf<wchar_t, char_traits<wchar_t>> wstreambuf;
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo da classe de modelo [basic_streambuf](../standard-library/basic-streambuf-class.md), especializado para elementos do tipo `wchar_t` com características de caractere padrão.  
  
## <a name="see-also"></a>Consulte também  
 [\<streambuf>](../standard-library/streambuf.md)




