---
title: '&lt;sstream&gt; | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- std.<sstream>
- std::<sstream>
- <sstream>
dev_langs:
- C++
helpviewer_keywords:
- sstream header
ms.assetid: 56f55bc5-549d-4e7f-aaad-99e0ffa49c9e
caps.latest.revision: 20
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 736a3a9eed879f9ea77a4a4ae1a2c4d45457a1df
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="ltsstreamgt"></a>&lt;sstream&gt;
Define várias classes de modelo que dão suporte a operações de iostreams em sequências armazenadas em um objeto de matriz alocada. Essas sequências são facilmente convertidas para e de objetos da classe de modelo [basic_string](../standard-library/basic-string-class.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```
namespace std {
template <class CharType, class Traits = char_traits<CharType>, class Allocator = allocator<CharType>>
class basic_stringbuf;
typedef basic_stringbuf<char>  
stringbuf;
typedef basic_stringbuf<wchar_t> wstringbuf;

template <class CharType, class Traits = char_traits<CharType>, class Allocator = allocator<CharType>>
class basic_istringstream;
typedef basic_istringstream<char>  
istringstream;
typedef basic_istringstream<wchar_t> wistringstream;

template <class CharType, class Traits = char_traits<CharType>, class Allocator = allocator<CharType>>
class basic_ostringstream;
typedef basic_ostringstream<char>  
ostringstream;
typedef basic_ostringstream<wchar_t> wostringstream;

template <class CharType, class Traits = char_traits<CharType>, class Allocator = allocator<CharType>>
class basic_stringstream;
typedef basic_stringstream<char>  
stringstream;
typedef basic_stringstream<wchar_t> wstringstream;
// TEMPLATE FUNCTIONS
template <class CharType, class Traits, class Allocator>
void swap(
    basic_stringbuf<CharType, Traits, Allocator>& left,
    basic_stringbuf<CharType, Traits, Allocator>& right);

template <class CharType, class Traits, class Allocator>
void swap(
    basic_istringstream<CharType, Traits, Allocator>& left,
    basic_istringstream<CharType, Traits, Allocator>& right);

template <class CharType, class Traits, class Allocator>
void swap(
    basic_ostringstream<CharType, Traits, Allocator>& left,
    basic_ostringstream<CharType, Traits, Allocator>& right);

template <class CharType, class Traits, class Allocator>
void swap (
    basic_stringstream<CharType, Traits, Allocator>& left,
    basic_stringstream<CharType, Traits, Allocator>& right);

}  // namespace std
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`left`|Referência para um objeto `sstream`.|  
|`right`|Referência para um objeto `sstream`.|  
  
## <a name="remarks"></a>Comentários  
 Objetos do tipo `char *` podem usar a funcionalidade em [\<strstream>](../standard-library/strstream.md) para streaming. No entanto, `<strstream>` foi preterido e o uso de `<sstream>` é recomendado.  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[istringstream](../standard-library/sstream-typedefs.md#istringstream)|Cria um tipo `basic_istringstream` especializadas em um parâmetro do modelo `char`.|  
|[ostringstream](../standard-library/sstream-typedefs.md#ostringstream)|Cria um tipo `basic_ostringstream` especializadas em um parâmetro do modelo `char`.|  
|[stringbuf](../standard-library/sstream-typedefs.md#stringbuf)|Cria um tipo `basic_stringbuf` especializadas em um parâmetro do modelo `char`.|  
|[stringstream](../standard-library/sstream-typedefs.md#stringstream)|Cria um tipo `basic_stringstream` especializadas em um parâmetro do modelo `char`.|  
|[wistringstream](../standard-library/sstream-typedefs.md#wistringstream)|Cria um tipo `basic_istringstream` especializadas em um parâmetro do modelo `wchar_t`.|  
|[wostringstream](../standard-library/sstream-typedefs.md#wostringstream)|Cria um tipo `basic_ostringstream` especializadas em um parâmetro do modelo `wchar_t`.|  
|[wstringbuf](../standard-library/sstream-typedefs.md#wstringbuf)|Cria um tipo `basic_stringbuf` especializadas em um parâmetro do modelo `wchar_t`.|  
|[wstringstream](../standard-library/sstream-typedefs.md#wstringstream)|Cria um tipo `basic_stringstream` especializadas em um parâmetro do modelo `wchar_t`.|  
  
### <a name="manipulators"></a>Manipuladores  
  
|||  
|-|-|  
|[swap](../standard-library/sstream-functions.md#sstream_swap)|Troca os valores de dois objetos `sstream`.|  
  
### <a name="classes"></a>Classes  
  
|||  
|-|-|  
|[basic_stringbuf](../standard-library/basic-stringbuf-class.md)|Descreve um buffer de fluxo que controla a transmissão de elementos do tipo **Elem**, cujas características dos caracteres são determinadas pela classe **Tr**, para e de uma sequência de elementos armazenados em um objeto de matriz.|  
|[basic_istringstream](../standard-library/basic-istringstream-class.md)|Descreve um objeto que controla a extração de elementos e objetos codificados de um buffer de fluxo da classe [basic_stringbuf](../standard-library/basic-stringbuf-class.md)<**Elem**, **Tr**, `Alloc`>, com elementos do tipo **Elem**, cujas características de caractere são determinadas pela classe **Tr** e cujos elementos são alocados por um alocador de classe `Alloc`.|  
|[basic_ostringstream](../standard-library/basic-ostringstream-class.md)|Descreve um objeto que controla a inserção de elementos e objetos codificados em um buffer de fluxo da classe [basic_stringbuf](../standard-library/basic-stringbuf-class.md)<**Elem**, **Tr**, `Alloc`>, com elementos do tipo **Elem**, cujas características de caractere são determinadas pela classe **Tr** e cujos elementos são alocados por um alocador de classe `Alloc`.|  
|[basic_stringstream](../standard-library/basic-stringstream-class.md)|Descreve um objeto que controla a inserção e extração de elementos e objetos codificados em usando buffer de fluxo da classe [basic_stringbuf](../standard-library/basic-stringbuf-class.md)<**Elem**, **Tr**, `Alloc`>, com elementos do tipo **Elem**, cujas características de caractere são determinadas pela classe **Tr** e cujos elementos são alocados por um alocador de classe `Alloc`.|  
  
## <a name="requirements"></a>Requisitos  
  
- **Cabeçalho:** \<sstream>  
  
- **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação de iostream](../standard-library/iostream-programming.md)   
 [Convenções de iostreams](../standard-library/iostreams-conventions.md)




