---
title: Classe basic_fstream | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- std::basic_fstream
- basic_fstream
- fstream/std::basic_fstream
- std.basic_fstream
dev_langs:
- C++
helpviewer_keywords:
- basic_fstream class
ms.assetid: 8473817e-42a4-430b-82b8-b476c86bcf8a
caps.latest.revision: 24
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 43723f5e423cd864b228f9a3c5bf05ee71b2b8c3
ms.lasthandoff: 02/25/2017

---
# <a name="basicfstream-class"></a>Classe basic_fstream
Descreve um objeto que controla a inserção e a extração de elementos e objetos codificados usando um buffer de fluxo da classe [basic_filebuf](../standard-library/basic-filebuf-class.md)< `Elem`, `Tr`>, com elementos do tipo `Elem` cujas características dos caracteres são determinadas pela classe `Tr`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Elem, class Tr = char_traits<Elem>>  
class basic_fstream : public basic_iostream<Elem, Tr>  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Elem`  
 O elemento básico no buffer de arquivo.  
  
 `Tr`  
 As características do elemento básico no buffer de arquivo (geralmente `char_traits` <  `Elem`>).  
  
## <a name="remarks"></a>Comentários  
 O objeto armazena um objeto da classe `basic_filebuf` <  `Elem`, `Tr`>.  
  
> [!NOTE]
>  O ponteiro get e o ponteiro put de um objeto fstream **NÃO** são independentes um do outro. Se o ponteiro se mover, o mesmo ocorrerá com o ponteiro put.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como criar um objeto `basic_fstream` que pode ser lido e gravado.  
  
```  
// basic_fstream_class.cpp  
// compile with: /EHsc  
  
#include <fstream>  
#include <iostream>  
  
using namespace std;  
  
int main(int argc, char **argv)  
{  
    fstream fs("fstream.txt", ios::in | ios::out | ios::trunc);  
    if (!fs.bad())  
    {  
        // Write to the file.  
        fs << "Writing to a basic_fstream object..." << endl;  
        fs.close();  
  
        // Dump the contents of the file to cout.  
        fs.open("fstream.txt", ios::in);  
        cout << fs.rdbuf();  
        fs.close();  
    }  
}  
```  
  
```Output  
Writing to a basic_fstream object...  
```  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[basic_fstream](#basic_fstream__basic_fstream)|Constrói um objeto do tipo `basic_fstream`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[close](#basic_fstream__close)|Fecha um arquivo.|  
|[is_open](#basic_fstream__is_open)|Determina se um arquivo está aberto.|  
|[open](#basic_fstream__open)|Abre um arquivo.|  
|[rdbuf](#basic_fstream__rdbuf)|Retorna o endereço do buffer de fluxo armazenado do tipo ponteiro para [basic_filebuf](../standard-library/basic-filebuf-class.md)< `Elem`, `Tr`>.|  
|[swap](#basic_fstream__swap)|Troca o conteúdo desse objeto pelo conteúdo de outro objeto `basic_fstream`.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<fstream>  
  
 **Namespace:** std  
  
##  <a name="a-namebasicfstreambasicfstreama--basicfstreambasicfstream"></a><a name="basic_fstream__basic_fstream"></a>  basic_fstream::basic_fstream  
 Constrói um objeto do tipo `basic_fstream`.  
  
```  
basic_fstream();

explicit basic_fstream(
    const char* _Filename,  
    ios_base::openmode _Mode = ios_base::in | ios_base::out,  
    int _Prot = (int)ios_base::_Openprot);

explicit basic_fstream(
    const wchar_t* _Filename,  
    ios_base::openmode _Mode = ios_base::in | ios_base::out,  
    int _Prot = (int)ios_base::_Openprot);

basic_fstream(basic_fstream&& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Filename`  
 O nome do arquivo a ser aberto.  
  
 `_Mode`  
 Uma das enumerações em [ios_base::openmode](../standard-library/ios-base-class.md#ios_base__openmode).  
  
 `_Prot`  
 A proteção de abertura de arquivo padrão, equivalente ao parâmetro `shflag` em [_fsopen, _wfsopen](../c-runtime-library/reference/fsopen-wfsopen.md).  
  
### <a name="remarks"></a>Comentários  
 O primeiro construtor inicializa a classe base chamando [basic_iostream](../standard-library/basic-iostream-class.md)( **sb**), em que **sb** é o objeto armazenado da classe [basic_filebuf](../standard-library/basic-filebuf-class.md)\< **Elem**, **Tr**>. Também inicializa **sb** chamando `basic_filebuf`\< **Elem**, **Tr**>.  
  
 O segundo e o terceiro construtores inicializam a classe base chamando `basic_iostream`( **sb**). Também inicializa **sb** chamando `basic_filebuf`\< **Elem**, **Tr**> e então **sb.**[open](../standard-library/basic-filebuf-class.md#basic_filebuf__open)(_ *Filename*, `_Mode`). Se a última função retornar um ponteiro nulo, o construtor chamará [setstate](../standard-library/basic-ios-class.md#basic_ios__setstate)( **failbit**).  
  
 O quarto construtor inicializa o objeto com o conteúdo de `right`, tratados como uma referência rvalue.  
  
### <a name="example"></a>Exemplo  
  Consulte [streampos](../standard-library/ios-typedefs.md#streampos) para obter um exemplo que usa `basic_fstream`.  
  
##  <a name="a-namebasicfstreamclosea--basicfstreamclose"></a><a name="basic_fstream__close"></a>  basic_fstream::close  
 Fecha um arquivo.  
  
```  
void close();
```  
  
### <a name="remarks"></a>Comentários  
 A função membro chama [rdbuf](#basic_fstream__rdbuf)**->** [close](../standard-library/basic-filebuf-class.md#basic_filebuf__close).  
  
### <a name="example"></a>Exemplo  
  Consulte [basic_filebuf::close](../standard-library/basic-filebuf-class.md#basic_filebuf__close) para obter um exemplo de como usar **close**.  
  
##  <a name="a-namebasicfstreamisopena--basicfstreamisopen"></a><a name="basic_fstream__is_open"></a>  basic_fstream::is_open  
 Determina se um arquivo está aberto.  
  
```  
bool is_open() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se o arquivo estiver aberto; **false** caso contrário.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna [rdbuf](#basic_fstream__rdbuf)**->**[is_open](../standard-library/basic-filebuf-class.md#basic_filebuf__is_open).  
  
### <a name="example"></a>Exemplo  
  Consulte [basic_filebuf::is_open](../standard-library/basic-filebuf-class.md#basic_filebuf__is_open) para obter um exemplo de como usar `is_open`.  
  
##  <a name="a-namebasicfstreamopena--basicfstreamopen"></a><a name="basic_fstream__open"></a>  basic_fstream::open  
 Abre um arquivo.  
  
```  
void open(
    const char* _Filename,  
    ios_base::openmode _Mode = ios_base::in | ios_base::out,  
    int _Prot = (int)ios_base::_Openprot);

void open(
    const char* _Filename,  
    ios_base::openmode _Mode);

void open(
    const wchar_t* _Filename,  
    ios_base::openmode _Mode = ios_base::in | ios_base::out,  
    int _Prot = (int)ios_base::_Openprot);

void open(
    const wchar_t* _Filename,  
    ios_base::openmode _Mode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Filename`  
 O nome do arquivo a ser aberto.  
  
 `_Mode`  
 Uma das enumerações em [ios_base::openmode](../standard-library/ios-base-class.md#ios_base__openmode).  
  
 `_Prot`  
 A proteção de abertura de arquivo padrão, equivalente ao parâmetro `shflag` em [_fsopen, _wfsopen](../c-runtime-library/reference/fsopen-wfsopen.md).  
  
### <a name="remarks"></a>Comentários  
 A função membro chama [rdbuf](#basic_fstream__rdbuf) **->** [open](../standard-library/basic-filebuf-class.md#basic_filebuf__open)(_ *Filename*, `_Mode`). Se essa função retorna um ponteiro nulo, a função chamará [setstate](../standard-library/basic-ios-class.md#basic_ios__setstate)( **failbit**).  
  
### <a name="example"></a>Exemplo  
  Consulte [basic_filebuf::is_open](../standard-library/basic-filebuf-class.md#basic_filebuf__open) para obter um exemplo de como usar **open**.  
  
##  <a name="a-namebasicfstreamoperatoreqa--basicfstreamoperator"></a><a name="basic_fstream__operator_eq"></a>  basic_fstream::operator=  
 Atribui a esse objeto o conteúdo de um objeto de fluxo especificado. Essa é uma atribuição de movimentação que envolve um rvalue que não deixa uma cópia.  
  
```  
basic_fstream& operator=(basic_fstream&& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` right`  
 Uma referência lvalue a um objeto `basic_fstream`.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `*this`.  
  
### <a name="remarks"></a>Comentários  
 O operador membro substitui o conteúdo do objeto usando o conteúdo de ` right`, tratado como uma referência rvalue.  
  
##  <a name="a-namebasicfstreamrdbufa--basicfstreamrdbuf"></a><a name="basic_fstream__rdbuf"></a>  basic_fstream::rdbuf  
 Retorna o endereço do buffer de fluxo armazenado do tipo ponteiro para [basic_filebuf](../standard-library/basic-filebuf-class.md)\< **Elem**, **Tr**>.  
  
```  
basic_filebuf<Elem, Tr> *rdbuf() const 
```  
  
### <a name="return-value"></a>Valor de retorno  
 O endereço do buffer de fluxo armazenado.  
  
### <a name="example"></a>Exemplo  
  Consulte [basic_filebuf::close](../standard-library/basic-filebuf-class.md#basic_filebuf__close) para obter um exemplo de como usar `rdbuf`.  
  
##  <a name="a-namebasicfstreamswapa--basicfstreamswap"></a><a name="basic_fstream__swap"></a>  basic_fstream::swap  
 Troca o conteúdo de dois `basic_fstream` objetos.  
  
```  
void swap(basic_fstream& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` right`  
 Uma referência `lvalue` a um objeto `basic_fstream`.  
  
### <a name="remarks"></a>Comentários  
 A função membro troca o conteúdo desse objeto e o conteúdo de ` right`.  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação de iostream](../standard-library/iostream-programming.md)   
 [Convenções de iostreams](../standard-library/iostreams-conventions.md)


