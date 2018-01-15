---
title: Classe basic_stringstream | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- sstream/std::basic_stringstream
- sstream/std::basic_stringstream::allocator_type
- sstream/std::basic_stringstream::rdbuf
- sstream/std::basic_stringstream::str
dev_langs: C++
helpviewer_keywords:
- std::basic_stringstream [C++]
- std::basic_stringstream [C++], allocator_type
- std::basic_stringstream [C++], rdbuf
- std::basic_stringstream [C++], str
ms.assetid: 49629814-ca37-45c5-931b-4ff894e6ebd2
caps.latest.revision: "19"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: eabc994dc5792a5fa896a1d87f09c0ad511d91f6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="basicstringstream-class"></a>Classe basic_stringstream
Descreve um objeto que controla a inserção e a extração de elementos e objetos codificados usando um buffer de fluxo da classe [basic_stringbuf](../standard-library/basic-stringbuf-class.md)< **Elem**, **Tr**, `Alloc`>.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Elem, class Tr = char_traits<Elem>, class Alloc = allocator<Elem>>  
class basic_stringstream : public basic_iostream<Elem, Tr>  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Alloc`  
 A classe do alocador.  
  
 `Elem`  
 O tipo do elemento básico da cadeia de caracteres.  
  
 *Tr*  
 As características de caractere especializadas no elemento básico da cadeia de caracteres.  
  
## <a name="remarks"></a>Comentários  
 A classe de modelo descreve um objeto que controla a inserção e extração de elementos e objetos codificados usando um buffer de fluxo da classe [basic_stringbuf](../standard-library/basic-stringbuf-class.md)< **Elem**, **Tr**, `Alloc`>, com elementos do tipo **Elem**, cujas características de caractere são determinadas pela classe **Tr** e cujos elementos são alocados por um alocador da classe `Alloc`. O objeto armazena um objeto da classe basic_stringbuf< **Elem**, **Tr**, `Alloc`>.  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[basic_stringstream](#basic_stringstream)|Constrói um objeto do tipo `basic_stringstream`.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[allocator_type](#allocator_type)|O tipo é um sinônimo do parâmetro de modelo `Alloc`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[rdbuf](#rdbuf)|Retorna o endereço do buffer de fluxo armazenado do tipo `pointer` para [basic_stringbuf](../standard-library/basic-stringbuf-class.md)< `Elem`, `Tr`, `Alloc`>.|  
|[str](#str)|Define ou obtém o texto em um buffer de cadeia de caracteres sem alterar a posição de gravação.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<sstream>  
  
 **Namespace:** std  
  
##  <a name="allocator_type"></a>  basic_stringstream::allocator_type  
 O tipo é um sinônimo do parâmetro de modelo `Alloc`.  
  
```  
typedef Alloc allocator_type;  
```  
  
##  <a name="basic_stringstream"></a>  basic_stringstream::basic_stringstream  
 Constrói um objeto do tipo `basic_stringstream`.  
  
```  
explicit basic_stringstream(ios_base::openmode _Mode = ios_base::in | ios_base::out);

explicit basic_stringstream(const basic_string<Elem, Tr, Alloc>& str, ios_base::openmode _Mode = ios_base::in | ios_base::out);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Mode`  
 Uma das enumerações em [ios_base::openmode](../standard-library/ios-base-class.md#openmode).  
  
 `str`  
 Um objeto do tipo `basic_string`.  
  
### <a name="remarks"></a>Comentários  
 O primeiro construtor inicializa a classe base chamando [basic_iostream](../standard-library/basic-iostream-class.md)( **sb**), em que **sb** é o objeto armazenado da classe [basic_stringbuf](../standard-library/basic-stringbuf-class.md)< **Elem**, **Tr**, `Alloc`>. Ele também inicializa **sb** chamando basic_stringbuf< **Elem**, **Tr**, `Alloc`>(`_Mode`).  
  
 O segundo construtor inicializa a classe base chamando basic_iostream(**sb**). Ele também inicializa **sb** chamando basic_stringbuf< **Elem**, **Tr**, `Alloc`>(_ *Str*, `_Mode`).  
  
##  <a name="rdbuf"></a>  basic_stringstream::rdbuf  
 Retorna o endereço do buffer de fluxo armazenado do tipo **pointer** para [basic_stringbuf](../standard-library/basic-stringbuf-class.md)< **Elem**, **Tr**, `Alloc`>.  
  
```  
basic_stringbuf<Elem, Tr, Alloc> *rdbuf() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O endereço do buffer de fluxo armazenado do tipo **pointer** para basic_stringbuf< **Elem**, **Tr**, `Alloc`>.  
  
### <a name="example"></a>Exemplo  
  Consulte [basic_filebuf::close](../standard-library/basic-filebuf-class.md#close) para ver um exemplo que usa `rdbuf`.  
  
##  <a name="str"></a>  basic_stringstream::str  
 Define ou obtém o texto em um buffer de cadeia de caracteres sem alterar a posição de gravação.  
  
```  
basic_string<Elem, Tr, Alloc> str() const;

 
void str(
    const basic_string<Elem, Tr, Alloc>& _Newstr);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Newstr`  
 A nova cadeia de caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um objeto da classe [basic_string](../standard-library/basic-string-class.md)< **Elem**, **Tr**, `Alloc`>, cuja sequência controlada é uma cópia da sequência controlada por **\*this**.  
  
### <a name="remarks"></a>Comentários  
 A primeira função membro retorna [rdbuf](#rdbuf) -> [str](../standard-library/basic-stringbuf-class.md#str). As segunda função membro chama `rdbuf` -> **str**( `_Newstr`).  
  
### <a name="example"></a>Exemplo  
  Consulte [basic_stringbuf::str](../standard-library/basic-stringbuf-class.md#str) para obter um exemplo que usa **str**.  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação de iostream](../standard-library/iostream-programming.md)   
 [Convenções de iostreams](../standard-library/iostreams-conventions.md)

