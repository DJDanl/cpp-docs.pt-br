---
title: Classe istrstream | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- strstream/std::istrstream::rdbuf
- strstream/std::istrstream::str
dev_langs:
- C++
helpviewer_keywords:
- istrstream class
ms.assetid: c2d41c75-bd2c-4437-bd77-5939ce1b97af
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: aec0c2bbac29da5406002aefbd6a6adcac926a33
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
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
|[istrstream](#istrstream)|Constrói um objeto do tipo `istrstream`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[rdbuf](#rdbuf)|Retorna um ponteiro para o objeto `strstreambuf` associado do fluxo.|  
|[str](#str)|Chama [freeze](../standard-library/strstreambuf-class.md#freeze) e retorna um ponteiro para o início da sequência controlada.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<strstream>  
  
 **Namespace:** std  
  
##  <a name="istrstream"></a>  istrstream::istrstream  
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
  
##  <a name="rdbuf"></a>  istrstream::rdbuf  
 Retorna um ponteiro para o objeto strstreambuf associado ao fluxo.  
  
```
strstreambuf *rdbuf() const
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o objeto strstreambuf associado ao fluxo.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna o endereço do buffer de fluxo armazenado do tipo pointer para [strstreambuf](../standard-library/strstreambuf-class.md).  
  
### <a name="example"></a>Exemplo  
  Consulte [strstreambuf::pcount](../standard-library/strstreambuf-class.md#pcount) para ver uma amostra que usa `rdbuf`.  
  
##  <a name="str"></a>  istrstream::str  
 Chama [freeze](../standard-library/strstreambuf-class.md#freeze) e retorna um ponteiro para o início da sequência controlada.  
  
```
char *str();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o início da sequência controlada.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna [rdbuf](#rdbuf) -> [str](../standard-library/strstreambuf-class.md#str).  
  
### <a name="example"></a>Exemplo  
  Consulte [strstream::str](../standard-library/strstreambuf-class.md#str) para ver uma amostra que usa **str**.  
  
## <a name="see-also"></a>Consulte também  
 [istream](../standard-library/istream-typedefs.md#istream)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação de iostream](../standard-library/iostream-programming.md)   
 [Convenções de iostreams](../standard-library/iostreams-conventions.md)



