---
title: Classe basic_ostream | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- std::basic_ostream
- std.basic_ostream
- ostream/std::basic_ostream
- basic_ostream
dev_langs:
- C++
helpviewer_keywords:
- basic_ostream class
ms.assetid: 5baadc65-b662-4fab-8c9f-94457c58cda1
caps.latest.revision: 24
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
ms.openlocfilehash: 73cde54e382bb04b82739239bd0f07142c5b3321
ms.lasthandoff: 02/25/2017

---
# <a name="basicostream-class"></a>Classe basic_ostream
Essa classe de modelo descreve um objeto que controla a inserção de elementos e objetos codificados em um buffer de fluxo com elementos do tipo **Elem**, também conhecido como [char_type](../standard-library/basic-ios-class.md#basic_ios__char_type), cujas características de caractere são determinadas pela classe **Tr**, também conhecida como [traits_type](../standard-library/basic-ios-class.md#basic_ios__traits_type).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Elem, class Tr = char_traits<Elem>>  
class basic_ostream : virtual public basic_ios<Elem, Tr>  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Elem`  
 Um `char_type`.  
  
 `Tr`  
 O caractere `traits_type`.  
  
## <a name="remarks"></a>Comentários  
 A maioria das funções membro que sobrecarrega o [operator<<](#basic_ostream__operator_lt__lt_) é composta por funções de entrada formatadas. Elas seguem o padrão:  
  
```  
iostate state = goodbit;  
const sentry ok(*this);

if (ok)  
 {try  
 {<convert and insert elements  
    accumulate flags in state> }  
    catch (...)  
 {try  
 {setstate(badbit);

}  
    catch (...)  
 {}  
    if ((exceptions()& badbit) != 0)  
    throw; }}  
width(0);
// Except for operator<<(Elem)  
setstate(state);

return (*this);
```  
  
 Duas outras funções membro são funções de saída sem formatação. Elas seguem o padrão:  
  
```  
iostate state = goodbit;  
const sentry ok(*this);

if (!ok)  
    state |= badbit;  
else  
 {try  
 {<obtain and insert elements  
    accumulate flags in state> }  
    catch (...)  
 {try  
 {setstate(badbit);

}  
    catch (...)  
 {}  
    if ((exceptions()& badbit) != 0)  
    throw; }}  
setstate(state);

return (*this);
```  
  
 Ambos os grupos de funções chama [setstate](../standard-library/basic-ios-class.md#basic_ios__setstate)**(badbit)** se encontram uma falha durante a inserção de elementos.  
  
 Um objeto da classe basic_istream\< **Elem**, **Tr**> armazena somente um objeto base virtual público da classe [basic_ios](../standard-library/basic-ios-class.md)**\<Elem**, **Tr >**.  
  
## <a name="example"></a>Exemplo  
 Consulte o exemplo de [Classe basic_ifstream](../standard-library/basic-ofstream-class.md) para saber mais sobre fluxos de saída.  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[basic_ostream](#basic_ostream__basic_ostream)|Constrói um objeto `basic_ostream`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[flush](#basic_ostream__flush)|Libera o buffer.|  
|[put](#basic_ostream__put)|Coloca um caractere em um fluxo.|  
|[seekp](#basic_ostream__seekp)|Redefine a posição no fluxo de saída.|  
|[sentry](#basic_ostream__sentry)|A classe aninhada descreve um objeto cuja declaração estrutura as funções de saída formatadas e as funções de saída não formatadas.|  
|[swap](#basic_ostream__operator_eq)|Troca os valores desse objeto `basic_ostream` por aqueles do objeto `basic_ostream` fornecido.|  
|[tellp](#basic_ostream__tellp)|Relata a posição no fluxo de saída.|  
|[write](#basic_ostream__write)|Coloca caracteres em um fluxo.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operator=](#basic_ostream_operator_eq)|Atribui o valor do objeto parâmetro `basic_ostream` fornecido para esse objeto.|  
|[operator<<](#basic_ostream_operator_lt_lt_)|Grava no fluxo.|  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<ostream >  
  
 **Namespace:** std  
  
##  <a name="a-namebasicostreambasicostreama--basicostreambasicostream"></a><a name="basic_ostream__basic_ostream"></a>  basic_ostream::basic_ostream  
 Constrói um objeto `basic_ostream`.  
  
```  
explicit basic_ostream(
    basic_streambuf<Elem, Tr>* strbuf,  
    bool _Isstd = false);

basic_ostream(basic_ostream&& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` strbuf`  
 Um objeto do tipo [basic_streambuf](../standard-library/basic-streambuf-class.md).  
  
 `_Isstd`  
 `true` se esse for um fluxo padrão; caso contrário, `false`.  
  
 ` right`  
 Uma referência rvalue a um objeto do tipo `basic_ostream`.  
  
### <a name="remarks"></a>Comentários  
 O primeiro construtor inicializa a classe base chamando [init](../standard-library/basic-ios-class.md#basic_ios__init)(` strbuf`). O segundo construtor inicializa a classe base chamando [basic_ios::move](../standard-library/basic-ios-class.md#basic_ios__move)`(`` right``)`.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo de [basic_ofstream::basic_ofstream](../standard-library/basic-ofstream-class.md#basic_ofstream__basic_ofstream) para saber mais sobre fluxos de saída.  
  
##  <a name="a-namebasicostreamflusha--basicostreamflush"></a><a name="basic_ostream__flush"></a>  basic_ostream::flush  
 Libera o buffer.  
  
```  
basic_ostream<Elem, Tr>& flush();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto basic_ostream.  
  
### <a name="remarks"></a>Comentários  
 Se [rdbuf](../standard-library/basic-ios-class.md#basic_ios__rdbuf) não for um ponteiro nulo, a função chamará **rdbuf->**[pubsync](../standard-library/basic-streambuf-class.md#basic_streambuf__pubsync). Se isso retornar -1, a função chamará [setstate](../standard-library/basic-ios-class.md#basic_ios__setstate)( **badbit**). Retorna **\*this**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_ostream_flush.cpp  
// compile with: /EHsc  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   cout << "test";  
   cout.flush();  
}  
```  
  
```Output  
test  
```  
  
##  <a name="a-namebasicostreamoperatorltlta--basicostreamoperatorltlt"></a><a name="basic_ostream_operator_lt_lt_"></a>  basic_ostream::operator&lt;&lt;  
 Grava no fluxo.  
  
```  
basic_ostream<Elem, Tr>& operator<<(
    basic_ostream<Elem, Tr>& (* Pfn)(basic_ostream<Elem, Tr>&));

basic_ostream<Elem, Tr>& operator<<(
    ios_base& (* Pfn)(ios_base&));

basic_ostream<Elem, Tr>& operator<<(
    basic_ios<Elem, Tr>& (* Pfn)(basic_ios<Elem, Tr>&));

basic_ostream<Elem, Tr>& operator<<(basic_streambuf<Elem, Tr>* strbuf);
basic_ostream<Elem, Tr>& operator<<(bool val);
basic_ostream<Elem, Tr>& operator<<(short val);
basic_ostream<Elem, Tr>& operator<<(unsigned short val);
basic_ostream<Elem, Tr>& operator<<(int __w64  val);
basic_ostream<Elem, Tr>& operator<<(unsigned int __w64  val);
basic_ostream<Elem, Tr>& operator<<(long val);
basic_ostream<Elem, Tr>& operator<<(unsigned long __w64  val);
basic_ostream<Elem, Tr>& operator<<(long long val);
basic_ostream<Elem, Tr>& operator<<(unsigned long long val);
basic_ostream<Elem, Tr>& operator<<(float val);
basic_ostream<Elem, Tr>& operator<<(double val);
basic_ostream<Elem, Tr>& operator<<(long double val);
basic_ostream<Elem, Tr>& operator<<(const void* val);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Pfn`  
 Um ponteiro de função.  
  
 ` strbuf`  
 Um ponteiro para um objeto **stream_buf**.  
  
 ` val`  
 Um elemento para gravar no fluxo.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto basic_ostream.  
  
### <a name="remarks"></a>Comentários  
 O cabeçalho `<ostream>` também define vários operadores de inserção global. Para obter mais informações, consulte [operator<< (\<ostream>)](../standard-library/ostream-operators.md#operator_lt__lt_).  
  
 A primeira função de membro garante que uma expressão do formulário **ostr << endl** chame [endl](../standard-library/ostream-functions.md#endl)**(ostr)** e, em seguida, retorne **\*this**. A segunda e a terceira funções garantem que outros manipuladores, como [hexa](../standard-library/ios-functions.md#hex), comportem-se de modo semelhante. As funções restantes são todas as funções de saída formatadas.  
  
 A função  
  
```  
basic_ostream<Elem, Tr>& operator<<(basic_streambuf<Elem, Tr>* strbuf);
```  
  
 extrai elementos de ` strbuf`, se ` strbuf` não for um ponteiro nulo e insere-os. A extração para no fim do arquivo ou se uma extração gerar uma exceção (que é gerada novamente). Ela também parará, sem extrair o elemento em questão, se uma inserção falhar. Se a função não inserir nenhum elemento ou se uma extração gerar uma exceção, a função chamará [setstate](../standard-library/basic-ios-class.md#basic_ios__setstate)(**failbit**). Em qualquer caso, a função retorna **\*this**.  
  
 A função  
  
```  
basic_ostream<Elem, Tr>& operator<<(bool val);
```  
  
 Converte _`Val` para um campo Booliano e insere-o chamando [use_facet](../standard-library/basic-filebuf-class.md#basic_filebuf__open)**<num_put\<Elem, OutIt>**`(`[getloc](../standard-library/ios-base-class.md#ios_base__getloc)). [put](#basic_ostream__put)(**OutIt**([rdbuf](../standard-library/basic-ios-class.md#basic_ios__rdbuf)), **\*this**, `getloc`, **val**). Aqui, **OutIt** é definido como [ostreambuf_iterator](../standard-library/ostreambuf-iterator-class.md)**\<Elem, Tr>**. A função retorna **\*this**.  
  
 As funções  
  
```  
basic_ostream<Elem, Tr>& operator<<(short val);
basic_ostream<Elem, Tr>& operator<<(unsigned short val);
basic_ostream<Elem, Tr>& operator<<(int val);
basic_ostream<Elem, Tr>& operator<<(unsigned int __w64  val);
basic_ostream<Elem, Tr>& operator<<(long val);
basic_ostream<Elem, Tr>& operator<<(unsigned long val);
basic_ostream<Elem, Tr>& operator<<(long long val);
basic_ostream<Elem, Tr>& operator<<(unsigned long long val);
basic_ostream<Elem, Tr>& operator<<(const void* val);
```  
  
 cada um converte ` val` para um campo numérico e insere-o chamando **use_facet<num_put\<Elem, OutIt>**(`getloc`). **put**(**OutIt**(`rdbuf`), **\*this**, `getloc`, **val**). Aqui, **OutIt** é definido como **ostreambuf_iterator\<Elem, Tr>**. A função retorna **\*this**.  
  
 As funções  
  
```  
basic_ostream<Elem, Tr>& operator<<(float val);
basic_ostream<Elem, Tr>& operator<<(double val);
basic_ostream<Elem, Tr>& operator<<(long double val);
```  
  
 cada um converte `val` para um campo numérico e insere-o chamando **use_facet<num_put\<Elem, OutIt>**(`getloc`)**. put**(**OutIt**(`rdbuf`), **\*this**, `getloc`, **val**). Aqui, **OutIt** é definido como **ostreambuf_iterator\<Elem, Tr>**. A função retorna **\*this**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_ostream_op_write.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <string.h>  
  
using namespace std;  
  
ios_base& hex2( ios_base& ib )  
{  
   ib.unsetf( ios_base::dec );  
   ib.setf( ios_base::hex );  
   return ib;  
}  
  
basic_ostream<char, char_traits<char> >& somefunc(basic_ostream<char, char_traits<char> > &i)
{
    if (i == cout)
    {
        i << "i is cout" << endl;
    }
    return i;
}

class CTxtStreambuf : public basic_streambuf< char, char_traits< char > >
{
public:
    CTxtStreambuf(char *_pszText)
    {
        pszText = _pszText;
        setg(pszText, pszText, pszText + strlen(pszText));
    };
    char *pszText;
};

int main()
{
    cout << somefunc;
    cout << 21 << endl;

    hex2(cout);
    cout << 21 << endl;

    CTxtStreambuf f("text in streambuf");
    cout << &f << endl;
}
```  
  
##  <a name="a-namebasicostreamoperatoreqa--basicostreamoperator"></a><a name="basic_ostream__operator_eq"></a>  basic_ostream::operator=  
 Atribui valores para o parâmetro de objeto `basic_ostream` fornecido para esse objeto.  
  
```  
basic_ostream& operator=(basic_ostream&& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` right`  
 Uma referência `rvalue` a um objeto `basic_ostream`.  
  
### <a name="remarks"></a>Comentários  
 O operador do membro chama `(`` right``)` de troca.  
  
##  <a name="a-namebasicostreamputa--basicostreamput"></a><a name="basic_ostream__put"></a>  basic_ostream::put  
 Coloca um caractere em um fluxo.  
  
```  
basic_ostream<Elem, Tr>& put(char_type _Ch);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Ch`  
 Um caractere.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto basic_ostream.  
  
### <a name="remarks"></a>Comentários  
 A função de saída não formatada insere o elemento `_Ch`. Retorna **\*this**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_ostream_put.cpp  
// compile with: /EHsc  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   cout.put( 'v' );  
   cout << endl;  
   wcout.put( L'l' );  
}  
```  
  
```Output  
v  
l  
```  
  
##  <a name="a-namebasicostreamseekpa--basicostreamseekp"></a><a name="basic_ostream__seekp"></a>  basic_ostream::seekp  
 Redefine a posição no fluxo de saída.  
  
```  
basic_ostream<Elem, Tr>& seekp(pos_type _Pos);

basic_ostream<Elem, Tr>& seekp(off_type _Off, ios_base::seekdir _Way);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Pos`  
 A posição no fluxo.  
  
 `_Off`  
 O deslocamento em relação a `_Way`.  
  
 `_Way`  
 Uma das enumerações de [ios_base::seekdir](../standard-library/ios-base-class.md#ios_base__seekdir).  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto basic_ostream.  
  
### <a name="remarks"></a>Comentários  
 Se [fail](../standard-library/basic-ios-class.md#basic_ios__fail) for **false**, a primeira função membro chamará **newpos =** [rdbuf](../standard-library/basic-ios-class.md#basic_ios__rdbuf)**->** [pubseekpos](../standard-library/basic-streambuf-class.md#basic_streambuf__pubseekpos)(_*Pos*), para algum objeto temporário `pos_type` **newpos**. Se **fail** for false, a segunda função chamará **newpos = rdbuf->** [pubseekoff](../standard-library/basic-streambuf-class.md#basic_streambuf__pubseekoff)(*_Off, _Way*). Em ambos os casos, se (`off_type`)**newpos ==** (`off_type`)(-1) (a operação de posicionamento falhar), a função chamará **istr.**[setstate](../standard-library/basic-ios-class.md#basic_ios__setstate)(**failbit**). Ambas as funções retornam **\*this**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_ostream_seekp.cpp  
// compile with: /EHsc  
#include <fstream>  
#include <iostream>  
  
int main()  
{  
    using namespace std;  
    ofstream x("basic_ostream_seekp.txt");  
    streamoff i = x.tellp();  
    cout << i << endl;  
    x << "testing";  
    i = x.tellp();  
    cout << i << endl;  
    x.seekp(2);   // Put char in third char position in file  
    x << " ";  
  
    x.seekp(2, ios::end);   // Put char two after end of file  
    x << "z";  
}  
```  
  
```Output  
0  
7  
```  
  
##  <a name="a-namebasicostreamsentrya--basicostreamsentry"></a><a name="basic_ostream__sentry"></a>  basic_ostream::sentry  
 A classe aninhada descreve um objeto cuja declaração estrutura as funções de saída formatadas e as funções de saída não formatadas.  
  
class sentry {  
   public:  
   explicit sentry(basic_ostream\<Elem, Tr>& _Ostr); operator bool() const; ~sentry(); };  
  
### <a name="remarks"></a>Comentários  
 A classe aninhada descreve um objeto cuja declaração estrutura as funções de saída formatadas e as funções de saída não formatadas. Se **ostr.**[good](../standard-library/basic-ios-class.md#basic_ios__good) for **true** e **ostr.**[tie](../standard-library/basic-ios-class.md#basic_ios__tie) não for um ponteiro nulo, o construtor chamará **ostr.tie->**[flush](#basic_ostream__flush). O construtor então armazena o valor retornado por **ostr.good** no **status**. Uma chamada posterior a **operador bool** entrega esse valor armazenado.  
  
 Se `uncaught_exception` retornar **false** e [flags](../standard-library/ios-base-class.md#ios_base__flags) **&** [unitbuf](../standard-library/ios-functions.md#unitbuf) for diferente de zero, o destruidor chamará [flush](#basic_ostream__flush).  
  
##  <a name="a-namebasicostreamswapa--basicostreamswap"></a><a name="basic_ostream__swap"></a>  basic_ostream::swap  
 Troca os valores desse `basic_ostream` objeto pelo valores do `basic_ostream` fornecido.  
  
```  
void swap(basic_ostream& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` right`  
 Uma referência a um objeto `basic_ostream`.  
  
### <a name="remarks"></a>Comentários  
 As função membro chama [basic_ios::swap](../standard-library/basic-ios-class.md#basic_ios__swap)`(`` right``)` para trocar o conteúdo desse objeto pelo conteúdo de ` right`.  
  
##  <a name="a-namebasicostreamtellpa--basicostreamtellp"></a><a name="basic_ostream__tellp"></a>  basic_ostream::tellp  
 Relata a posição no fluxo de saída.  
  
```  
pos_type tellp();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Posição no fluxo de saída.  
  
### <a name="remarks"></a>Comentários  
 Se [fail](../standard-library/basic-ios-class.md#basic_ios__fail) for **false**, a função membro retornará [rdbuf](../standard-library/basic-ios-class.md#basic_ios__rdbuf)**->** [pubseekoff](../standard-library/basic-streambuf-class.md#basic_streambuf__pubseekoff)(0, `cur`, **in**). Caso contrário, retornará `pos_type`(-1).  
  
### <a name="example"></a>Exemplo  
  Consulte [seekp](#basic_ostream__seekp) para obter um exemplo usando `tellp`.  
  
##  <a name="a-namebasicostreamwritea--basicostreamwrite"></a><a name="basic_ostream__write"></a>  basic_ostream::write  
 Coloque caracteres em um fluxo.  
  
```  
basic_ostream<Elem, Tr>& write(const char_type* str, streamsize count);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` count`  
 Contagem de caracteres a colocar no fluxo.  
  
 ` str`  
 Caracteres a colocar no fluxo.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto basic_ostream.  
  
### <a name="remarks"></a>Comentários  
 A [função de saída não formatado](../standard-library/basic-ostream-class.md) insere a sequência de elementos ` count` começando em ` str`.  
  
### <a name="example"></a>Exemplo  
  Consulte [streamsize](../standard-library/ios-typedefs.md#streamsize) para obter um exemplo usando `write`.  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação de iostream](../standard-library/iostream-programming.md)   
 [Convenções de iostreams](../standard-library/iostreams-conventions.md)


