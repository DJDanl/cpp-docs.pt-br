---
title: Classe istrstream | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- istrstream
- strstream/std::istrstream::rdbuf
- strstream/std::istrstream::str
dev_langs:
- C++
helpviewer_keywords:
- istrstream class
ms.assetid: c2d41c75-bd2c-4437-bd77-5939ce1b97af
caps.latest.revision: 20
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: a156bcbefa4d3636a2a4b1978378a815a8d0fed9
ms.lasthandoff: 02/25/2017

---
# <a name="istrstream-class"></a>Classe istrstream
Descreve um objeto que controla a extração de elementos e objetos codificados de um buffer de fluxo da classe [strstreambuf](../standard-library/strstreambuf-class.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```
class istrstream : public istream
```  
  
## <a name="remarks"></a>Comentários  
 O objeto armazena um objeto da classe `strstreambuf`.  
  
> [!NOTE]
>  Essa classe foi preterida. Considere usar [istringstream](../standard-library/sstream-typedefs.md#istringstream) ou [wistringstream](../standard-library/sstream-typedefs.md#wistringstream) em vez disso.  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[istrstream](#istrstream__istrstream)|Constrói um objeto do tipo `istrstream`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[rdbuf](#istrstream__rdbuf)|Retorna um ponteiro para o objeto `strstreambuf` associado do fluxo.|  
|[str](#istrstream__str)|Chama [freeze](../standard-library/strstreambuf-class.md#strstreambuf__freeze) e retorna um ponteiro para o início da sequência controlada.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<strstream>  
  
 **Namespace:** std  
  
##  <a name="istrstream__istrstream"></a>  istrstream::istrstream  
 Constrói um objeto do tipo `istrstream`.  
  
```
explicit istrstream(
    const char* ptr);

explicit istrstream(
    char* ptr);

istrstream(
    const char* ptr,
    streamsize count);

istrstream(
    char* ptr,
    int count);
```  
  
### <a name="parameters"></a>Parâmetros  
 `count`  
 O tamanho do buffer (`ptr`).  
  
 `ptr`  
 O conteúdo com que o buffer é inicializado.  
  
### <a name="remarks"></a>Comentários  
 Todos os construtores inicializam a classe base chamando [istream](../standard-library/istream-typedefs.md#istream)( **sb**), em que **sb** é o objeto armazenado da classe [strstreambuf](../standard-library/strstreambuf-class.md). Os primeiros dois construtores também inicializam **sb** chamando `strstreambuf`( ( **const**`char` \*) `ptr`, 0 ). Os dois construtores restantes chamam `strstreambuf`( ( **const**`char` *) `ptr`, `count` ).  
  
##  <a name="istrstream__rdbuf"></a>  istrstream::rdbuf  
 Retorna um ponteiro para o objeto strstreambuf associado ao fluxo.  
  
```
strstreambuf *rdbuf() const
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o objeto strstreambuf associado ao fluxo.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna o endereço do buffer de fluxo armazenado do tipo pointer para [strstreambuf](../standard-library/strstreambuf-class.md).  
  
### <a name="example"></a>Exemplo  
  Consulte [strstreambuf::pcount](../standard-library/strstreambuf-class.md#strstreambuf__pcount) para ver uma amostra que usa `rdbuf`.  
  
##  <a name="istrstream__str"></a>  istrstream::str  
 Chama [freeze](../standard-library/strstreambuf-class.md#strstreambuf__freeze) e retorna um ponteiro para o início da sequência controlada.  
  
```
char *str();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o início da sequência controlada.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna [rdbuf](#istrstream__rdbuf) -> [str](../standard-library/strstreambuf-class.md#strstreambuf__str).  
  
### <a name="example"></a>Exemplo  
  Consulte [strstream::str](../standard-library/strstreambuf-class.md#strstreambuf__str) para ver uma amostra que usa **str**.  
  
## <a name="see-also"></a>Consulte também  
 [istream](../standard-library/istream-typedefs.md#istream)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação de iostream](../standard-library/iostream-programming.md)   
 [Convenções de iostreams](../standard-library/iostreams-conventions.md)




