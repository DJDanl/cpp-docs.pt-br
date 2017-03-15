---
title: "Classe strstream | Microsoft Docs"
ms.custom: ""
ms.date: "11/04/2016"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "std::strstream"
  - "strstream"
  - "std.strstream"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "strstream class"
ms.assetid: 63f3be31-9e36-42b1-9715-a474a5997e2a
caps.latest.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
translation.priority.ht: 
  - "cs-cz"
  - "de-de"
  - "es-es"
  - "fr-fr"
  - "it-it"
  - "ja-jp"
  - "ko-kr"
  - "pl-pl"
  - "pt-br"
  - "ru-ru"
  - "tr-tr"
  - "zh-cn"
  - "zh-tw"
---
# <a name="strstream-class"></a>Classe strstream
Descreve um objeto que controla a inserção e extração de elementos e objetos codificados usando um buffer de fluxo da classe [strstreambuf](../standard-library/strstreambuf-class.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```
class strstream : public iostream
```  
  
## <a name="remarks"></a>Comentários  
 O objeto armazena um objeto da classe `strstreambuf`.  
  
> [!NOTE]
>  Essa classe foi preterida. Considere usar [ostringstream](../standard-library/sstream-typedefs.md#stringstream) ou [wstringstream](../standard-library/sstream-typedefs.md#wstringstream) em vez disso.  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[strstream](#strstream__strstream)|Constrói um objeto do tipo `strstream`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[freeze](#strstream__freeze)|Faz com que um buffer de fluxo esteja indisponível por meio de operações de buffer de fluxo.|  
|[pcount](#strstream__pcount)|Retorna uma contagem do número de elementos gravados na sequência controlada.|  
|[rdbuf](#strstream__rdbuf)|Retorna um ponteiro para o objeto `strstreambuf` associado do fluxo.|  
|[str](#strstream__str)|Chama [freeze](../standard-library/strstreambuf-class.md#strstreambuf__freeze) e retorna um ponteiro para o início da sequência controlada.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<strstream>  
  
 **Namespace:** std  
  
##  <a name="a-namestrstreamfreezea--strstreamfreeze"></a><a name="strstream__freeze"></a>  strstream::freeze  
 Faz com que um buffer de fluxo esteja indisponível por meio de operações de buffer de fluxo.  
  
```
void freeze(bool _Freezeit = true);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Freezeit`  
 Um `bool` que indica se você deseja que o fluxo seja congelado.  
  
### <a name="remarks"></a>Comentários  
 A função membro chama [rdbuf](#strstream__rdbuf) -> [freeze](../standard-library/strstreambuf-class.md#strstreambuf__freeze)(_ *Freezeit*).  
  
### <a name="example"></a>Exemplo  
  Consulte [strstreambuf::freeze](../standard-library/strstreambuf-class.md#strstreambuf__freeze) para ver um exemplo que usa **freeze**.  
  
##  <a name="a-namestrstreampcounta--strstreampcount"></a><a name="strstream__pcount"></a>  strstream::pcount  
 Retorna uma contagem do número de elementos gravados na sequência controlada.  
  
```
streamsize pcount() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de elementos gravados na sequência controlada.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna [rdbuf](#strstream__rdbuf) -> [pcount](../standard-library/strstreambuf-class.md#strstreambuf__pcount).  
  
### <a name="example"></a>Exemplo  
  Consulte [strstreambuf::pcount](../standard-library/strstreambuf-class.md#strstreambuf__pcount) para ver uma amostra que usa pcount.  
  
##  <a name="a-namestrstreamrdbufa--strstreamrdbuf"></a><a name="strstream__rdbuf"></a>  strstream::rdbuf  
 Retorna um ponteiro para o objeto strstreambuf associado ao fluxo.  
  
```
strstreambuf *rdbuf() const
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o objeto strstreambuf associado ao fluxo.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna o endereço do buffer de fluxo armazenado do tipo **pointer** para [strstreambuf](../standard-library/strstreambuf-class.md).  
  
### <a name="example"></a>Exemplo  
  Consulte [strstreambuf::pcount](../standard-library/strstreambuf-class.md#strstreambuf__pcount) para ver uma amostra que usa `rdbuf`.  
  
##  <a name="a-namestrstreamstra--strstreamstr"></a><a name="strstream__str"></a>  strstream::str  
 Chama [freeze](../standard-library/strstreambuf-class.md#strstreambuf__freeze) e retorna um ponteiro para o início da sequência controlada.  
  
```
char *str();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o início da sequência controlada.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna [rdbuf](#strstream__rdbuf) -> [str](../standard-library/strstreambuf-class.md#strstreambuf__str).  
  
### <a name="example"></a>Exemplo  
  Consulte [strstreambuf::str](../standard-library/strstreambuf-class.md#strstreambuf__str) para ver uma amostra que usa **str**.  
  
##  <a name="a-namestrstreamstrstreama--strstreamstrstream"></a><a name="strstream__strstream"></a>  strstream::strstream  
 Constrói um objeto do tipo `strstream`.  
  
```
strstream();

strstream(char* ptr,
    streamsize count,
    ios_base::openmode _Mode = ios_base::in | ios_base::out);
```  
  
### <a name="parameters"></a>Parâmetros  
 `count`  
 O tamanho do buffer.  
  
 `_Mode`  
 O modo de entrada e saída do buffer. Consulte [ios_base::openmode](../standard-library/ios-base-class.md#ios_base__openmode) para obter mais informações.  
  
 `ptr`  
 O buffer.  
  
### <a name="remarks"></a>Comentários  
 Ambos os construtores inicializam a classe base chamando [streambuf](../standard-library/streambuf-typedefs.md#streambuf)( **sb**), em que **sb** é o objeto armazenado de classe [strstreambuf](../standard-library/strstreambuf-class.md). O primeiro construtor também inicializa **sb** chamando [strstreambuf](../standard-library/strstreambuf-class.md#strstreambuf__strstreambuf). O segundo construtor inicializa a classe base com uma de duas maneiras:  
  
-   Se `_Mode` & **ios_base::app**== 0, então `ptr` deve designar o primeiro elemento de uma matriz de elementos `count` e o construtor chamará `strstreambuf`( `ptr`, `count`, `ptr`).  
  
-   Caso contrário, `ptr` deve designar o primeiro elemento de uma matriz de elementos de contagem que contém uma cadeia de caracteres C cujo primeiro elemento é designado por `ptr` e o construtor chama `strstreambuf`( `ptr`, `count`, `ptr` + `strlen`( `ptr`) ).  
  
## <a name="see-also"></a>Consulte também  
 [iostream](../standard-library/istream-typedefs.md#iostream)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação de iostream](../standard-library/iostream-programming.md)   
 [Convenções de iostreams](../standard-library/iostreams-conventions.md)



