---
title: '&lt;string&gt; typedefs | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: fdca01e9-f2f1-4b59-abda-0093d760b3cc
caps.latest.revision: 12
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: ba8cd6e49f490718beb8fdc216781d8950aedbfb
ms.lasthandoff: 02/25/2017

---
# <a name="ltstringgt-typedefs"></a>&lt;string&gt; typedefs
||||  
|-|-|-|  
|[string](#string)|[u16string](#u16string)|[u32string](#u32string)|  
|[wstring](#wstring)|  
  
##  <a name="a-namestringa--string"></a><a name="string"></a>  string  
 Um tipo que descreve uma especialização da classe de modelo [basic_string](../standard-library/basic-string-class.md) com elementos do tipo `char`.  
  
 Outros typedefs que especializam `basic_string` incluem [wstring](../standard-library/string-typedefs.md#wstring), [u16string](../standard-library/string-typedefs.md#u16string) e [u32string](../standard-library/string-typedefs.md#u32string).  
  
```cpp  
typedef basic_string<char, char_traits<char>, allocator<char>> string;
```  
  
### <a name="remarks"></a>Comentários  
 As declarações a seguir são equivalentes:  
  
```cpp  
string str("");

basic_string<char> str("");
```  
  
 Para obter uma lista de construtores de cadeia de caracteres, consulte [basic_string::basic_string](../standard-library/basic-string-class.md#basic_string__basic_string).  
  
##  <a name="a-nameu16stringa--u16string"></a><a name="u16string"></a>  u16string  
 Um tipo que descreve uma especialização da classe de modelo [basic_string](../standard-library/basic-string-class.md) com elementos do tipo `char16_t`.  
  
 Outros typedefs que especializam `basic_string` incluem [wstring](../standard-library/string-typedefs.md#wstring), [string](../standard-library/string-typedefs.md#string) e [u32string](../standard-library/string-typedefs.md#u32string).  
  
```cpp  
typedef basic_string<char16_t, char_traits<char16_t>, allocator<char16_t>> u16string;
```  
  
### <a name="remarks"></a>Comentários  
 Para obter uma lista de construtores de cadeia de caracteres, consulte [basic_string::basic_string](../standard-library/basic-string-class.md#basic_string__basic_string).  
  
##  <a name="a-nameu32stringa--u32string"></a><a name="u32string"></a>  u32string  
 Um tipo que descreve uma especialização da classe de modelo [basic_string](../standard-library/basic-string-class.md) com elementos do tipo `char32_t`.  
  
 Outros typedefs que especializam `basic_string` incluem [string](../standard-library/string-typedefs.md#string), [u16string](../standard-library/string-typedefs.md#u16string) e [wstring](../standard-library/string-typedefs.md#wstring).  
  
```cpp  
typedef basic_string<char32_t, char_traits<char32_t>, allocator<char32_t>> u32string;
```  
  
### <a name="remarks"></a>Comentários  
 Para obter uma lista de construtores de cadeia de caracteres, consulte [basic_string::basic_string](../standard-library/basic-string-class.md#basic_string__basic_string).  
  
##  <a name="a-namewstringa--wstring"></a><a name="wstring"></a>  wstring  
 Um tipo que descreve uma especialização da classe de modelo [basic_string](../standard-library/basic-string-class.md) com elementos do tipo `wchar_t`.  
  
 Outros typedefs que especializam `basic_string` incluem [string](../standard-library/string-typedefs.md#string), [u16string](../standard-library/string-typedefs.md#u16string) e [u32string](../standard-library/string-typedefs.md#u32string).  
  
```cpp  
typedef basic_string<wchar_t, char_traits<wchar_t>, allocator<wchar_t>> wstring;
```  
  
### <a name="remarks"></a>Comentários  
 As declarações a seguir são equivalentes:  
  
```cpp  
wstring wstr(L"");

basic_string<wchar_t> wstr(L"");
```  
  
 Para obter uma lista de construtores de cadeia de caracteres, consulte [basic_string::basic_string](../standard-library/basic-string-class.md#basic_string__basic_string).  
  
> [!NOTE]
>  O tamanho do `wchar_t` é definido pela implementação. Se seu código depender de `wchar_t` para ser de determinado tamanho, verifique a implementação da plataforma (por exemplo, com `sizeof(wchar_t)`). Se você precisar de um tipo de caractere de cadeia com uma largura que garantidamente continuará a mesma em todas as plataformas, use [string](../standard-library/string-typedefs.md#string), [u16string](../standard-library/string-typedefs.md#u16string) ou [u32string](../standard-library/string-typedefs.md#u32string).  
  
## <a name="see-also"></a>Consulte também  
 [\<string>](../standard-library/string.md)




