---
title: Operadores &lt;filesystem&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- FILESYSTEM/std::experimental::filesystem::operator==
- FILESYSTEM/std::experimental::filesystem::operator!=
- FILESYSTEM/std::experimental::filesystem::operator<
- FILESYSTEM/std::experimental::filesystem::operator<=
- FILESYSTEM/std::experimental::filesystem::operator>
- FILESYSTEM/std::experimental::filesystem::operator>=
- FILESYSTEM/std::experimental::filesystem::operator/
- FILESYSTEM/std::experimental::filesystem::operator<<
- FILESYSTEM/std::experimental::filesystem::operator>>
dev_langs: C++
ms.assetid: 102c4833-aa3b-41a8-8998-f5003c546bfd
caps.latest.revision: "12"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 815ff0025372e8b085f7c6f6ea38299bb15c8305
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ltfilesystemgt-operators"></a>Operadores &lt;filesystem&gt;
Os operadores executam uma comparação léxica de dois caminhos como cadeias de caracteres. Use a função **equivalent** para determinar se dois caminhos (por exemplo, um caminho relativo e um caminho absoluto) fazem referência ao mesmo arquivo ou diretório no disco.  
  
```  
C:\root> D:\root: false  
C:\root> C:\root\sub: false  
C:\root> C:\roo: true  
```  
  
 Para obter mais informações, consulte [Navegação no sistema de arquivos (C++)](../standard-library/file-system-navigation.md).  
  
## <a name="operator"></a>operator==  
  
```  
bool operator==(const path& left, const path& right) noexcept;  
```  
  
 A função retorna left.native() == right.native().  
  
## <a name="operator"></a>operator!=  
  
```  
bool operator!=(const path& left, const path& right) noexcept;  
```  
  
 A função retorna !(left == right).  
  
## <a name="operator"></a>operador <  
  
```  
bool operator<(const path& left, const path& right) noexcept;  
```  
  
 A função retorna left.native() < right.native().  
  
## <a name="operator"></a>Operador <=  
  
```  
bool operator<=(const path& left, const path& right) noexcept;  
```  
  
 A função retorna !(right \< left).  
  
## <a name="operator"></a>Operador >  
  
```  
bool operator>(const path& left, const path& right) noexcept;  
```  
  
 A função retorna direita \< esquerda.  
  
## <a name="operator"></a>Operador >=  
  
```  
bool operator>=(const path& left, const path& right) noexcept;  
```  
  
 A função retorna !(left < right).  
  
## <a name="operator"></a>operator/  
  
```  
path operator/(const path& left, const path& right);
```  
  
 A função executa:  
  
```  
basic_string<Elem, Traits> str;  
path ans = left;  
return (ans /= right);
```  
  
## <a name="operator"></a>Operador <<  
  
```  
template <class Elem, class Traits>  
basic_ostream<Elem, Traits>& operator<<(basic_ostream<Elem, Traits>& os, const path& pval);
```  
  
 A função retorna os << pval.string\<Elem, Traits>().  
  
## <a name="operator"></a>Operador >>  
  
```  
template <class Elem, class Traits>  
basic_istream<Elem, Traits>& operator<<(basic_istream<Elem, Traits>& is, const path& pval);
```  
  
 A função executa:  
  
```  
basic_string<Elem, Traits> str;  
is>> str;  
pval = str;  
return (is);
```  
  
## <a name="see-also"></a>Consulte também  
 [Classe path (Biblioteca padrão C++ )](../standard-library/path-class.md)   
 [Navegação no sistema de arquivos (C++)](../standard-library/file-system-navigation.md)   
 [\<filesystem>](../standard-library/filesystem.md)

