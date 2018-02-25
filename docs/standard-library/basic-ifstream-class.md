---
title: Classe basic_ifstream | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- fstream/std::basic_ifstream
- fstream/std::basic_ifstream::close
- fstream/std::basic_ifstream::is_open
- fstream/std::basic_ifstream::open
- fstream/std::basic_ifstream::rdbuf
- fstream/std::basic_ifstream::swap
dev_langs:
- C++
helpviewer_keywords:
- std::basic_ifstream [C++]
- std::basic_ifstream [C++], close
- std::basic_ifstream [C++], is_open
- std::basic_ifstream [C++], open
- std::basic_ifstream [C++], rdbuf
- std::basic_ifstream [C++], swap
ms.assetid: 366cd9a7-efc4-4b7f-ba10-c8271e47ffcf
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a9c923d4c3de5410ac65f9706d875300b0d07cbb
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="basicifstream-class"></a>Classe basic_ifstream
Descreve um objeto que controla a extração de elementos e objetos codificados de um buffer de fluxo da classe [basic_filebuf](../standard-library/basic-filebuf-class.md)< `Elem`, `Tr`>, com elementos do tipo `Elem` cujas características dos caracteres são determinadas pela classe `Tr`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Elem, class Tr = char_traits<Elem>>  
class basic_ifstream : public basic_istream<Elem, Tr>  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Elem`  
 O elemento básico no buffer de arquivo.  
  
 `Tr`  
 As características do elemento básico no buffer de arquivo (geralmente `char_traits` <  `Elem`>).  
  
## <a name="remarks"></a>Comentários  
 O objeto armazena um objeto da classe `basic_filebuf` <  `Elem`, `Tr`>.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra como ler texto de um arquivo.  
  
```  
// basic_ifstream_class.cpp  
// compile with: /EHsc  
  
#include <fstream>  
#include <iostream>  
  
using namespace std;  
  
int main(int argc, char **argv)  
{  
    ifstream ifs("basic_ifstream_class.txt");  
    if (!ifs.bad())  
    {  
        // Dump the contents of the file to cout.  
        cout << ifs.rdbuf();  
        ifs.close();  
    }  
}  
```  
  
## <a name="input-basicifstreamclasstxt"></a>Entrada: basic_ifstream_class.txt  
  
```  
This is the contents of basic_ifstream_class.txt.  
```  
  
## <a name="output"></a>Saída  
  
```  
This is the contents of basic_ifstream_class.txt.  
```  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[basic_ifstream](#basic_ifstream)|Inicializa uma nova instância de um objeto `basic_ifstream`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[close](#close)|Fecha um arquivo.|  
|[is_open](#is_open)|Determina se um arquivo está aberto.|  
|[open](#open)|Abre um arquivo.|  
|[rdbuf](#rdbuf)|Retorna o endereço do buffer de fluxo armazenado.|  
|[swap](#swap)|Troca o conteúdo desse `basic_ifstream` pelo conteúdo do `basic_ifstream` fornecido.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operator=](#op_eq)|Atribui o conteúdo desse objeto de fluxo. Essa é uma atribuição de movimentação que envolve um `rvalue` que não deixa uma cópia.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<fstream>  
  
 **Namespace:** std  
  
##  <a name="basic_ifstream"></a>  basic_ifstream::basic_ifstream  
 Constrói um objeto do tipo `basic_ifstream`.  
  
```  
basic_ifstream();

explicit basic_ifstream(
    const char* _Filename,  
    ios_base::openmode _Mode = ios_base::in,  
    int _Prot = (int)ios_base::_Openprot);

explicit basic_ifstream(
    const wchar_t* _Filename,  
    ios_base::openmode _Mode = ios_base::in,  
    int _Prot = (int)ios_base::_Openprot);

basic_ifstream(basic_ifstream&& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Filename`  
 O nome do arquivo a ser aberto.  
  
 `_Mode`  
 Uma das enumerações em [ios_base::openmode](../standard-library/ios-base-class.md#openmode).  
  
 `_Prot`  
 A proteção de abertura de arquivo padrão, equivalente ao parâmetro `shflag` em [_fsopen, _wfsopen](../c-runtime-library/reference/fsopen-wfsopen.md).  
  
### <a name="remarks"></a>Comentários  
 O primeiro construtor inicializa a classe base chamando [basic_istream](../standard-library/basic-istream-class.md)( `sb`), em que `sb` é o objeto armazenado da classe [basic_filebuf](../standard-library/basic-filebuf-class.md)< `Elem`, `Tr`>. Também inicializa `sb` chamando `basic_filebuf`< `Elem`, `Tr`>.  
  
 O segundo e o terceiro construtores inicializam a classe base chamando `basic_istream`( `sb`). Também inicializa `sb` chamando [basic_filebuf](../standard-library/basic-filebuf-class.md#basic_filebuf)< `Elem`, `Tr`> e, em seguida, `sb`. [open](../standard-library/basic-filebuf-class.md#open)( `_Filename`, `_Mode` &#124; `ios_base::in`). Se a última função retornar um ponteiro nulo, o construtor chamará **setstate**( `failbit`).  
  
 O quarto construtor inicializa o objeto com o conteúdo de `right`, tratados como uma referência rvalue.  
  
### <a name="example"></a>Exemplo  
  O exemplo a seguir mostra como ler texto de um arquivo. Para criar o arquivo, consulte o exemplo para [basic_ofstream::basic_ofstream](../standard-library/basic-ofstream-class.md#basic_ofstream).  
  
```  
// basic_ifstream_ctor.cpp  
// compile with: /EHsc  
  
#include <fstream>  
#include <iostream>  
  
using namespace std;  
  
int main(int argc, char **argv)  
{  
    ifstream ifs("basic_ifstream_ctor.txt");  
    if (!ifs.bad())  
    {  
        // Dump the contents of the file to cout.  
        cout << ifs.rdbuf();  
        ifs.close();  
    }  
}  
```  
  
##  <a name="close"></a>  basic_ifstream::close  
 Fecha um arquivo.  
  
```  
void close();
```  
  
### <a name="remarks"></a>Comentários  
 As chamadas de função de membro [rdbuf](#rdbuf)  **->**  [fechar](../standard-library/basic-filebuf-class.md#close).  
  
### <a name="example"></a>Exemplo  
  Consulte [basic_filebuf::close](../standard-library/basic-filebuf-class.md#close) para ver um exemplo que usa **fechar**.  
  
##  <a name="is_open"></a>  basic_ifstream::is_open  
 Determina se um arquivo está aberto.  
  
```  
bool is_open() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se o arquivo estiver aberto; **false** caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Retorna a função de membro [rdbuf](#rdbuf)  **->**  [is_open](../standard-library/basic-filebuf-class.md#is_open).  
  
### <a name="example"></a>Exemplo  
  Consulte [basic_filebuf::is_open](../standard-library/basic-filebuf-class.md#is_open) para ver um exemplo que usa `is_open`.  
  
##  <a name="open"></a>  basic_ifstream::open  
 Abre um arquivo.  
  
```  
void open(
    const char* _Filename,  
    ios_base::openmode _Mode = ios_base::in,  
    int _Prot = (int)ios_base::_Openprot);

void open(
    const char* _Filename,  
    ios_base::openmode _Mode);

void open(
    const wchar_t* _Filename,  
    ios_base::openmode _Mode = ios_base::in,  
    int _Prot = (int)ios_base::_Openprot);

void open(
    const wchar_t* _Filename,  
    ios_base::openmode _Mode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Filename`  
 O nome do arquivo a ser aberto.  
  
 `_Mode`  
 Uma das enumerações em [ios_base::openmode](../standard-library/ios-base-class.md#openmode).  
  
 `_Prot`  
 A proteção de abertura de arquivo padrão, equivalente ao parâmetro `shflag` em [_fsopen, _wfsopen](../c-runtime-library/reference/fsopen-wfsopen.md).  
  
### <a name="remarks"></a>Comentários  
 A função membro chama [rdbuf](#rdbuf) **->** [open](../standard-library/basic-filebuf-class.md#open)(_ *Filename*, `_Mode` &#124; **ios_base::in**). Se abrir falhar, a função chamará [setstate](../standard-library/basic-ios-class.md#setstate)( **failbit**), que pode gerar uma exceção ios_base::failure.  
  
### <a name="example"></a>Exemplo  
  Consulte [basic_filebuf::open](../standard-library/basic-filebuf-class.md#open) para ver um exemplo que usa **abrir**.  
  
##  <a name="op_eq"></a>  basic_ifstream::operator=  
 Atribui o conteúdo desse objeto de fluxo. Essa é uma atribuição de movimentação que envolve um rvalue que não deixa uma cópia.  
  
```  
basic_ifstream& operator=(basic_ifstream&& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `right`  
 Uma referência rvalue a um objeto `basic_ifstream`.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `*this`.  
  
### <a name="remarks"></a>Comentários  
 O operador membro substitui o conteúdo do objeto usando o conteúdo de `right`, tratado como uma referência rvalue. Para obter mais informações, consulte [Lvalues e Rvalues](../cpp/lvalues-and-rvalues-visual-cpp.md).  
  
##  <a name="rdbuf"></a>  basic_ifstream::rdbuf  
 Retorna o endereço do buffer de fluxo armazenado.  
  
```  
basic_filebuf<Elem, Tr> *rdbuf() const 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um objeto [basic_filebuf](../standard-library/basic-filebuf-class.md) que representa o buffer de fluxo armazenado.  
  
### <a name="example"></a>Exemplo  
  Consulte [basic_filebuf::close](../standard-library/basic-filebuf-class.md#close) para ver um exemplo que usa `rdbuf`.  
  
##  <a name="swap"></a>  basic_ifstream::swap  
 Troca o conteúdo de dois `basic_ifstream` objetos.  
  
```  
void swap(basic_ifstream& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `right`  
 Uma referência a outro buffer de fluxo.  
  
### <a name="remarks"></a>Comentários  
 A função membro troca o conteúdo desse objeto pelo conteúdo de `right`.  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação de iostream](../standard-library/iostream-programming.md)   
 [Convenções de iostreams](../standard-library/iostreams-conventions.md)


