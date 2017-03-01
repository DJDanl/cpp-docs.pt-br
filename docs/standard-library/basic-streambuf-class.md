---
title: Classe basic_streambuf | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- basic_streambuf
- streambuf/std::basic_streambuf
- std.basic_streambuf
- std::basic_streambuf
dev_langs:
- C++
helpviewer_keywords:
- basic_streambuf class
ms.assetid: 136af6c3-13bf-4501-9288-b93da26efac7
caps.latest.revision: 27
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
ms.openlocfilehash: c79716aefc6abbff8030694f21447960087eae79
ms.lasthandoff: 02/25/2017

---
# <a name="basicstreambuf-class"></a>Classe basic_streambuf
Descreve uma classe base abstrata para derivar um buffer de fluxo, que controla a transmissão de elementos de e para uma representação específica de um fluxo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Elem, class Tr = char_traits<Elem>>  
class basic_streambuf;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Elem`  
 Um [char_type](#basic_streambuf__char_type).  
  
 `Tr`  
 O caractere [traits_type](#basic_streambuf__traits_type).  
  
## <a name="remarks"></a>Comentários  
 A classe de modelo descreve uma classe base abstrata para derivar um buffer de fluxo, que controla a transmissão de elementos de e para uma representação específica de um fluxo. Um objeto da classe `basic_streambuf` ajuda a controlar um fluxo com elementos do tipo `Tr`, também conhecido como [char_type](#basic_streambuf__char_type), cujas características de caractere são determinadas pela classe [char_traits](../standard-library/char-traits-struct.md), também conhecida como [traits_type](#basic_streambuf__traits_type).  
  
 Todo buffer de fluxo controla conceitualmente dois fluxos independentes: um para extrações (entrada) e outro para inserções (saída). Uma representação específica pode, no entanto, tornar um ou ambos esses fluxos inacessíveis. Normalmente, mantém alguma relação entre os dois fluxos. O que você insere no fluxo de saída de um objeto [basic_stringbuf](../standard-library/basic-stringbuf-class.md)< `Elem`, `Tr`>, por exemplo, é o que você mais tarde extrai do fluxo de entrada. Ao posicionar um fluxo de um objeto [basic_filebuf](../standard-library/basic-filebuf-class.md)< `Elem`, `Tr`>, você posiciona o outro fluxo em tandem.  
  
 A interface pública para a classe de modelo `basic_streambuf` fornece as operações que são comuns a todos os buffers de fluxo, por mais especializados que sejam. A interface protegida fornece as operações necessárias para uma representação específica de um fluxo para fazer seu trabalho. As funções membro virtuais protegidas permitem personalizar o comportamento de um buffer de fluxo derivado para uma representação específica de um fluxo. Cada buffer de fluxo derivado nesta biblioteca descreve como especializa o comportamento de suas funções membro virtual protegidas. O comportamento padrão para a classe base, que costuma não fazer nada, é descrito neste tópico.  
  
 As funções membro protegidas restantes controla a cópia para e de qualquer armazenamento fornecido para transmissões de buffer para e de fluxos. Um buffer de entrada, por exemplo, é caracterizado por:  
  
- [eback](#basic_streambuf__eback), um ponteiro para o início do buffer.  
  
- [gptr](#basic_streambuf__gptr), um ponteiro para o próximo elemento a ler.  
  
- [egptr](#basic_streambuf__egptr), um ponteiro logo após o fim do buffer.  
  
 Da mesma forma, um buffer de saída é caracterizado por:  
  
- [pbase](#basic_streambuf__pbase), um ponteiro para o início do buffer.  
  
- [pptr](#basic_streambuf__pptr), um ponteiro para o próximo elemento a gravar.  
  
- [epptr](#basic_streambuf__epptr), um ponteiro logo após o fim do buffer.  
  
 Para qualquer buffer, o seguinte protocolo é usado:  
  
-   Se o próximo ponteiro for nulo, nenhum buffer existirá. Caso contrário, todos os três ponteiros apontam para a mesma sequência. Eles podem ser comparados com segurança para ordem.  
  
-   Para um buffer de saída, se o ponteiro seguinte comparar menos que o ponteiro final, você poderá armazenar um elemento na posição de gravação designada pelo ponteiro seguinte.  
  
-   Para um buffer de entrada, se o ponteiro seguinte comparar menos que o ponteiro final, você poderá ler um elemento na posição de leitura designada pelo ponteiro seguinte.  
  
-   Para um buffer de entrada, se o ponteiro inicial comparar menos que o ponteiro seguinte, você pode colocar um elemento de volta na posição putback designada pelo próximo ponteiro decrementado.  
  
 Quaisquer funções membro virtuais protegidas que você grave para uma classe derivada de `basic_streambuf`< `Elem`, `Tr`> deve cooperar para manter esse protocolo.  
  
 Um objeto da classe `basic_streambuf`< `Elem`, `Tr`> armazena os seis ponteiros descritos anteriormente. Ele também armazena um objeto de localidade em um objeto do tipo [localidade](../standard-library/locale-class.md) para uso potencial por um buffer de fluxo derivado.  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[basic_streambuf](#basic_streambuf__basic_streambuf)|Constrói um objeto do tipo `basic_streambuf`.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[char_type](#basic_streambuf__char_type)|Associa um nome de tipo ao parâmetro de modelo `Elem`.|  
|[int_type](#basic_streambuf__int_type)|Associa um nome de tipo dentro do escopo de `basic_streambuf` ao parâmetro do modelo `Elem`.|  
|[off_type](#basic_streambuf__off_type)|Associa um nome de tipo dentro do escopo de `basic_streambuf` ao parâmetro do modelo `Elem`.|  
|[pos_type](#basic_streambuf__pos_type)|Associa um nome de tipo dentro do escopo de `basic_streambuf` ao parâmetro do modelo `Elem`.|  
|[traits_type](#basic_streambuf__traits_type)|Associa um nome de tipo ao parâmetro de modelo `Tr`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[eback](#basic_streambuf__eback)|Uma função protegida que retorna um ponteiro para o início do buffer de entrada.|  
|[egptr](#basic_streambuf__egptr)|Uma função protegida que retorna um ponteiro logo após o final do buffer de entrada.|  
|[epptr](#basic_streambuf__epptr)|Uma função protegida que retorna um ponteiro logo após o final do buffer de saída.|  
|[gbump](#basic_streambuf__gbump)|Uma função protegida que adiciona ` count` ao próximo ponteiro para o buffer de entrada.|  
|[getloc](#basic_streambuf__getloc)|Obtém a localidade do objeto `basic_streambuf`.|  
|[gptr](#basic_streambuf__gptr)|Uma função protegida que retorna um ponteiro para o próximo elemento do buffer de entrada.|  
|[imbue](#basic_streambuf__imbue)|Uma função virtual protegida chamada por [pubimbue](#basic_streambuf__pubimbue).|  
|[in_avail](#basic_streambuf__in_avail)|Retorna o número de elementos que estão prontos para serem lidos do buffer.|  
|[overflow](#basic_streambuf__overflow)|Uma função virtual protegida que pode ser chamada quando um novo caractere é inserido em um buffer cheio.|  
|[pbackfail](#basic_streambuf__pbackfail)|Uma função membro virtual protegida que tenta colocar um elemento de volta no fluxo de entrada, então torná-lo elemento atual (apontando para o ponteiro seguinte).|  
|[pbase](#basic_streambuf__pbase)|Uma função protegida que retorna um ponteiro para o início do buffer de saída.|  
|[pbump](#basic_streambuf__pbump)|Uma função protegida que adiciona `count` ao próximo ponteiro para o buffer de saída.|  
|[pptr](#basic_streambuf__pptr)|Uma função protegida que retorna um ponteiro para o próximo elemento do buffer de saída.|  
|[pubimbue](#basic_streambuf__pubimbue)|Define a localidade do objeto `basic_streambuf`.|  
|[pubseekoff](#basic_streambuf__pubseekoff)|Chama [seekoff](#basic_streambuf__seekoff), uma função virtual protegida que é substituída em uma classe derivada.|  
|[pubseekpos](#basic_streambuf__pubseekpos)|Chama [seekpos](#basic_streambuf__seekpos), uma função virtual protegida que é substituída em uma classe derivada e redefine a posição atual do ponteiro.|  
|[pubsetbuf](#basic_streambuf__pubsetbuf)|Chama [setbuf](#basic_streambuf__setbuf), uma função virtual protegida que é substituída em uma classe derivada.|  
|[pubsync](#basic_streambuf__pubsync)|Chama [sync](#basic_streambuf__sync), uma função virtual protegida que é substituída em uma classe derivada e atualiza o fluxo externo associado a esse buffer.|  
|[sbumpc](#basic_streambuf__sbumpc)|Lê e retorna o elemento atual, movendo o ponteiro de fluxo.|  
|[seekoff](#basic_streambuf__seekoff)|A função membro virtual protegida tenta alterar as posições atuais para os fluxos controlados.|  
|[seekpos](#basic_streambuf__seekpos)|A função membro virtual protegida tenta alterar as posições atuais para os fluxos controlados.|  
|[setbuf](#basic_streambuf__setbuf)|A função membro virtual protegida executa uma operação que específica para cada buffer de fluxo derivado.|  
|[setg](#basic_streambuf__setg)|Uma função protegida que armazena `_Gbeg` no ponteiro de início, `_Gnext` no próximo ponteiro e `_Gend` no ponteiro final para o buffer de entrada.|  
|[setp](#basic_streambuf__setp)|Uma função protegida que armazena `_Pbeg` no ponteiro inicial e `_Pend` no ponteiro final para o buffer de saída.|  
|[sgetc](#basic_streambuf__sgetc)|Retorna o elemento atual sem alterar a posição no fluxo.|  
|[sgetn](#basic_streambuf__sgetn)|Retorna o número de elementos lidos.|  
|[showmanyc](#basic_streambuf__showmanyc)|Função membro virtual protegida que retorna uma contagem do número de caracteres que pode ser extraído do fluxo de entrada e garante que o programa não esteja sujeito a uma espera indefinida.|  
|[snextc](#basic_streambuf__snextc)|Lê o elemento atual e retorna o elemento seguinte.|  
|[sputbackc](#basic_streambuf__sputbackc)|Coloca um `char_type` no fluxo.|  
|[sputc](#basic_streambuf__sputc)|Coloca um caractere no fluxo.|  
|[sputn](#basic_streambuf__sputn)|Coloca uma cadeia de caracteres no fluxo.|  
|[stossc](#basic_streambuf__stossc)|Move-se além do elemento atual no fluxo.|  
|[sungetc](#basic_streambuf__sungetc)|Obtém um caractere do fluxo.|  
|[swap](#basic_streambuf__swap)|Troca os valores nesse objeto pelos valores do parâmetro do objeto `basic_streambuf` fornecido.|  
|[sync](#basic_streambuf__sync)|Uma função virtual protegida que tenta sincronizar os fluxos controlados com quaisquer fluxos externos associados.|  
|[uflow](#basic_streambuf__uflow)|Função virtual protegida que extrai o elemento atual do fluxo de entrada.|  
|[underflow](#basic_streambuf__underflow)|Função virtual protegida que extrai o elemento atual do fluxo de entrada.|  
|[xsgetn](#basic_streambuf__xsgetn)|Uma função virtual protegida que extrai elementos de fluxo de entrada.|  
|[xsputn](#basic_streambuf__xsputn)|Uma função virtual protegida que insere elementos no fluxo de saída.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operator=](#basic_streambuf__operator_eq)|Atribui os valores deste objeto de outro objeto `basic_streambuf`.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<streambuf >  
  
 **Namespace:** std  
  
##  <a name="a-namebasicstreambufbasicstreambufa--basicstreambufbasicstreambuf"></a><a name="basic_streambuf__basic_streambuf"></a>  basic_streambuf::basic_streambuf  
 Constrói um objeto do tipo `basic_streambuf`.  
  
```  
basic_streambuf();

basic_streambuf(const basic_streambuf& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` right`  
 Uma referência lvalue para o objeto `basic_streambuf` usada para definir os valores a esse objeto `basic_streambuf`.  
  
### <a name="remarks"></a>Comentários  
 O primeiro construtor protegido armazena um ponteiro nulo em todos os ponteiros controlando o buffer de entrada e o buffer de saída. Ele também armazena `locale::classic` no objeto de localidade. Para obter mais informações, consulte [Locale::classic](../standard-library/locale-class.md#locale__classic).  
  
 O segundo construtor protegido copia os ponteiros e a localidade de ` right`.  
  
##  <a name="a-namebasicstreambufchartypea--basicstreambufchartype"></a><a name="basic_streambuf__char_type"></a>  basic_streambuf::char_type  
 Associa um nome de tipo ao parâmetro do modelo **Elem**.  
  
```  
typedef Elem char_type;  
```  
  
##  <a name="a-namebasicstreambufebacka--basicstreambufeback"></a><a name="basic_streambuf__eback"></a>  basic_streambuf::eback  
 Uma função protegida que retorna um ponteiro para o início do buffer de entrada.  
  
```  
char_type *eback() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o início do buffer de entrada.  
  
##  <a name="a-namebasicstreambufegptra--basicstreambufegptr"></a><a name="basic_streambuf__egptr"></a>  basic_streambuf::egptr  
 Uma função protegida que retorna um ponteiro logo após o final do buffer de entrada.  
  
```  
char_type *egptr() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro logo após o final do buffer de entrada.  
  
##  <a name="a-namebasicstreambufepptra--basicstreambufepptr"></a><a name="basic_streambuf__epptr"></a>  basic_streambuf::epptr  
 Uma função protegida que retorna um ponteiro logo após o final do buffer de saída.  
  
```  
char_type *epptr() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro logo após o final do buffer de saída.  
  
##  <a name="a-namebasicstreambufgbumpa--basicstreambufgbump"></a><a name="basic_streambuf__gbump"></a>  basic_streambuf::gbump  
 Uma função protegida que adiciona ` count` ao próximo ponteiro para o buffer de entrada.  
  
```  
void gbump(int count);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` count`  
 O valor pelo qual avançar o ponteiro.  
  
##  <a name="a-namebasicstreambufgetloca--basicstreambufgetloc"></a><a name="basic_streambuf__getloc"></a>  basic_streambuf::getloc  
 Obtém a localidade do objeto basic_streambuf.  
  
```  
locale getloc() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O objeto de localidade armazenado.  
  
### <a name="remarks"></a>Comentários  
 Para obter informações relacionadas, consulte [ios_base::getloc](../standard-library/ios-base-class.md#ios_base__getloc).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_streambuf_getloc.cpp  
// compile with: /EHsc  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   cout << cout.rdbuf( )->getloc( ).name( ).c_str( ) << endl;  
}  
```  
  
```Output  
C  
```  
  
##  <a name="a-namebasicstreambufgptra--basicstreambufgptr"></a><a name="basic_streambuf__gptr"></a>  basic_streambuf::gptr  
 Uma função protegida que retorna um ponteiro para o próximo elemento do buffer de entrada.  
  
```  
char_type *gptr() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o próximo elemento do buffer de entrada.  
  
##  <a name="a-namebasicstreambufimbuea--basicstreambufimbue"></a><a name="basic_streambuf__imbue"></a>  basic_streambuf::imbue  
 Uma função virtual protegida chamada por [pubimbue](#basic_streambuf__pubimbue).  
  
```  
virtual void imbue(const locale& _Loc);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Loc`  
 Uma referência a uma localidade.  
  
### <a name="remarks"></a>Comentários  
 O comportamento padrão é não fazer nada.  
  
##  <a name="a-namebasicstreambufinavaila--basicstreambufinavail"></a><a name="basic_streambuf__in_avail"></a>  basic_streambuf::in_avail  
 Retorna o número de elementos que estão prontos para serem lidos do buffer.  
  
```  
streamsize in_avail();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de elementos que estão prontos para serem lidos do buffer.  
  
### <a name="remarks"></a>Comentários  
 Se uma [posição de leitura](../standard-library/basic-streambuf-class.md) estiver disponível, a função membro retornará [egptr](#basic_streambuf__egptr) – [gptr](#basic_streambuf__gptr). Caso contrário, retorna [showmanyc](#basic_streambuf__showmanyc).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_streambuf_in_avail.cpp  
// compile with: /EHsc  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   char c;  
   // cin's buffer is empty, in_avail will return 0  
   cout << cin.rdbuf( )->in_avail( ) << endl;  
   cin >> c;  
   cout << cin.rdbuf( )->in_avail( ) << endl;  
}  
```  
  
##  <a name="a-namebasicstreambufinttypea--basicstreambufinttype"></a><a name="basic_streambuf__int_type"></a>  basic_streambuf::int_type  
 Associa um nome de tipo dentro do escopo de basic_streambuf a um dos tipos em um parâmetro de modelo.  
  
```  
typedef typename traits_type::int_type int_type;  
```  
  
##  <a name="a-namebasicstreambufofftypea--basicstreambufofftype"></a><a name="basic_streambuf__off_type"></a>  basic_streambuf::off_type  
 Associa um nome de tipo dentro do escopo de basic_streambuf a um dos tipos em um parâmetro de modelo.  
  
```  
typedef typename traits_type::off_type off_type;  
```  
  
##  <a name="a-namebasicstreambufoperatoreqa--basicstreambufoperator"></a><a name="basic_streambuf__operator_eq"></a>  basic_streambuf::operator=  
 Atribui os valores deste objeto de outro objeto `basic_streambuf`.  
  
```  
basic_streambuf& operator=(const basic_streambuf& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` right`  
 Uma referência lvalue para o objeto `basic_streambuf` usada para atribuir valores a esse objeto.  
  
### <a name="remarks"></a>Comentários  
 O operador membro protegido copia de ` right` os ponteiros que controlam o buffer de entrada e o buffer de saída. Também armazena ` right``.`[getloc()](#basic_streambuf__getloc) no `locale object`. Ele retorna `*this`.  
  
##  <a name="a-namebasicstreambufoverflowa--basicstreambufoverflow"></a><a name="basic_streambuf__overflow"></a>  basic_streambuf::overflow  
 Uma função virtual protegida que pode ser chamada quando um novo caractere é inserido em um buffer cheio.  
  
```  
virtual int_type overflow(int_type _Meta = traits_type::eof());
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Meta`  
 O caractere a ser inserido no buffer, ou **traits_type::**[eof](../standard-library/char-traits-struct.md#char_traits__eof).  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função não conseguir obter sucesso, ela retornará **traits_type::eof** ou gerará uma exceção. Caso contrário, retornará **traits_type::**[not_eof](../standard-library/char-traits-struct.md#char_traits__not_eof)(_ *Meta*). O comportamento padrão é retornar **traits_type::eof**.  
  
### <a name="remarks"></a>Comentários  
 Se _ *Meta* não for equivalente a **traits_type::eof**, a função membro virtual protegida buscará inserir o elemento **traits_type::**[to_char_type](../standard-library/char-traits-struct.md#char_traits__to_char_type)(\_ *Meta*) no fluxo de saída. Isso pode ser feito de várias maneiras:  
  
-   Se `write position` estiver disponível, ela poderá armazenar o elemento na posição de gravação e incrementar o próximo ponteiro para o buffer de saída.  
  
-   Ele pode disponibilizar uma posição de gravação alocando armazenamento novo ou adicional ao buffer de saída.  
  
-   Ele pode disponibilizar uma posição de gravação gravando, em algum destino externo, alguns ou todos os elementos entre os ponteiros inicial e seguinte para o buffer de saída.  
  
 A função de estouro virtual, junto com as funções [sync](#basic_streambuf__sync) e [underflow](#basic_streambuf__underflow), definem as características da classe derivada streambuf. Cada classe derivada pode implementar o estouro de forma diferente, mas a interface com a classe de fluxo de chamada é a mesma.  
  
 A função `overflow` frequentemente é chamada por funções `streambuf` públicas como `sputc` e `sputn` quando a área put está cheia, mas outras classes, incluindo as classes de fluxo, podem chamar `overflow` a qualquer momento.  
  
 A função consome os caracteres na área de put entre os ponteiros `pbase` e `pptr` e, em seguida, reinicializa a área put. A função `overflow` também deve consumir `nCh` (se `nCh` não for `EOF`) ou pode optar por colocar o caractere na nova área de put para que ele seja consumido na próxima chamada.  
  
 A definição de consumir varia entre as classes derivadas. Por exemplo, a classe `filebuf` grava seus caracteres em um arquivo, enquanto a classe `strstreambuf` os mantém em seu buffer e, se o buffer for designado como dinâmico, expande o buffer em resposta a uma chamada para estouro. Essa expansão é obtida liberando o buffer antigo e substituindo-o por um novo maior. Os ponteiros são ajustados conforme necessário.  
  
##  <a name="a-namebasicstreambufpbackfaila--basicstreambufpbackfail"></a><a name="basic_streambuf__pbackfail"></a>  basic_streambuf::pbackfail  
 Uma função membro virtual protegida que tenta colocar um elemento de volta no fluxo de entrada, então torná-lo elemento atual (apontando para o ponteiro seguinte).  
  
```  
virtual int_type pbackfail(int_type _Meta = traits_type::eof());
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Meta`  
 O caractere a ser inserido no buffer, ou **traits_type::**[eof](../standard-library/char-traits-struct.md#char_traits__eof).  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função não conseguir obter sucesso, ela retornará **traits_type::eof** ou gerará uma exceção. Caso contrário, retorna algum outro valor. O comportamento padrão é retornar **traits_type::eof**.  
  
### <a name="remarks"></a>Comentários  
 Se _ *Meta* for comparável a **traits_type::eof**, o elemento a ser recuado será efetivamente aquele que já estava no fluxo antes do elemento atual. Caso contrário, esse elemento é substituído por **traits_type::**[to_char_type](../standard-library/char-traits-struct.md#char_traits__to_char_type)(\_ *Meta*). A função pode colocar um elemento de volta de várias maneiras:  
  
-   Se uma posição putback estiver disponível, ela poderá armazenar o elemento na posição putback e diminuir o ponteiro seguinte para o buffer de entrada.  
  
-   Pode disponibilizar uma posição de putback alocando armazenamento novo ou adicional para o buffer de entrada.  
  
-   Para um buffer de fluxo com fluxos de entrada e saída comuns, ele pode disponibilizar uma posição de putback gravando, em algum destino externo, alguns ou todos os elementos entre os ponteiros inicial e seguintes para o buffer de saída.  
  
##  <a name="a-namebasicstreambufpbasea--basicstreambufpbase"></a><a name="basic_streambuf__pbase"></a>  basic_streambuf::pbase  
 Uma função protegida que retorna um ponteiro para o início do buffer de saída.  
  
```  
char_type *pbase() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o início do buffer de saída.  
  
##  <a name="a-namebasicstreambufpbumpa--basicstreambufpbump"></a><a name="basic_streambuf__pbump"></a>  basic_streambuf::pbump  
 Uma função protegida que adiciona ` count` ao próximo ponteiro para o buffer de saída.  
  
```  
void pbump(int count);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` count`  
 O número de caracteres pelo qual mover a posição de gravação para frente.  
  
##  <a name="a-namebasicstreambufpostypea--basicstreambufpostype"></a><a name="basic_streambuf__pos_type"></a>  basic_streambuf::pos_type  
 Associa um nome de tipo dentro do escopo de basic_streambuf a um dos tipos em um parâmetro de modelo.  
  
```  
typedef typename traits_type::pos_type pos_type;  
```  
  
##  <a name="a-namebasicstreambufpptra--basicstreambufpptr"></a><a name="basic_streambuf__pptr"></a>  basic_streambuf::pptr  
 Uma função protegida que retorna um ponteiro para o próximo elemento do buffer de saída.  
  
```  
char_type *pptr() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o próximo elemento do buffer de saída.  
  
##  <a name="a-namebasicstreambufpubimbuea--basicstreambufpubimbue"></a><a name="basic_streambuf__pubimbue"></a>  basic_streambuf::pubimbue  
 Define a localidade do objeto basic_streambuf.  
  
```  
locale pubimbue(const locale& _Loc);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Loc`  
 Uma referência a uma localidade.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor anterior armazenado no objeto de localidade.  
  
### <a name="remarks"></a>Comentários  
 A função membro armazena _ *Loc* no objeto de localidade e chama [imbue](#basic_streambuf__imbue).  
  
### <a name="example"></a>Exemplo  
  Consulte [basic_ios::imbue](../standard-library/basic-ios-class.md#basic_ios__imbue) para obter um exemplo que usa `pubimbue`.  
  
##  <a name="a-namebasicstreambufpubseekoffa--basicstreambufpubseekoff"></a><a name="basic_streambuf__pubseekoff"></a>  basic_streambuf::pubseekoff  
 Chama [seekoff](#basic_streambuf__seekoff), uma função virtual protegida que é substituída em uma classe derivada.  
  
```  
pos_type pubseekoff(off_type _Off,
    ios_base::seekdir _Way,
    ios_base::openmode _Which = ios_base::in | ios_base::out);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Off`  
 A posição pela qual buscar com relação a `_Way`.  
  
 `_Way`  
 O ponto de partida para operações de deslocamento. Consulte [seekdir](../standard-library/ios-base-class.md#ios_base__seekdir) para valores possíveis.  
  
 `_Which`  
 Especifica o modo para a posição do ponteiro. O padrão é permitir que você modifique as posições de leitura e gravação.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a nova posição ou uma posição de fluxo inválida ( [seekoff](#basic_streambuf__seekoff)(_ *Off*, `_Way`, `_Which`) ).  
  
### <a name="remarks"></a>Comentários  
 Move o ponteiro com relação a `_Way`.  
  
##  <a name="a-namebasicstreambufpubseekposa--basicstreambufpubseekpos"></a><a name="basic_streambuf__pubseekpos"></a>  basic_streambuf::pubseekpos  
 Chama [seekpos](#basic_streambuf__seekpos), uma função virtual protegida que é substituída em uma classe derivada e redefine a posição atual do ponteiro.  
  
```  
pos_type pubseekpos(pos_type _Sp, ios_base::openmode _Which = ios_base::in | ios_base::out);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Sp`  
 A posição pela qual buscar.  
  
 `_Which`  
 Especifica o modo para a posição do ponteiro. O padrão é permitir que você modifique as posições de leitura e gravação.  
  
### <a name="return-value"></a>Valor de retorno  
 A nova posição ou uma posição de fluxo inválida. Para determinar se a posição de fluxo é inválida, compare o valor retornado com `pos_type(off_type(-1))`.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna [seekpos](#basic_streambuf__seekpos)(_ *Sp*, `_Which`).  
  
##  <a name="a-namebasicstreambufpubsetbufa--basicstreambufpubsetbuf"></a><a name="basic_streambuf__pubsetbuf"></a>  basic_streambuf::pubsetbuf  
 Chama [setbuf](#basic_streambuf__setbuf), uma função virtual protegida que é substituída em uma classe derivada.  
  
```  
basic_streambuf<Elem, Tr> *pubsetbuf(
    char_type* _Buffer,  
    streamsize count);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Buffer`  
 Um ponteiro para `char_type` para essa instanciação.  
  
 ` count`  
 O tamanho do buffer.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna [setbuf](#basic_streambuf__setbuf)( `_Buffer`, ` count`).  
  
##  <a name="a-namebasicstreambufpubsynca--basicstreambufpubsync"></a><a name="basic_streambuf__pubsync"></a>  basic_streambuf::pubsync  
 Chama [sync](#basic_streambuf__sync), uma função virtual protegida que é substituída em uma classe derivada e atualiza o fluxo externo associado a esse buffer.  
  
```  
int pubsync();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna [sync](#basic_streambuf__sync) ou -1 se houver falha.  
  
##  <a name="a-namebasicstreambufsbumpca--basicstreambufsbumpc"></a><a name="basic_streambuf__sbumpc"></a>  basic_streambuf::sbumpc  
 Lê e retorna o elemento atual, movendo o ponteiro de fluxo.  
  
```  
int_type sbumpc();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O elemento atual.  
  
### <a name="remarks"></a>Comentários  
 Se uma posição de leitura estiver disponível, a função membro retornará **traits_type::**[to_int_type](../standard-library/char-traits-struct.md#char_traits__to_int_type)( ** \* ** [gptr](#basic_streambuf__gptr)) e incrementará o ponteiro seguinte para o buffer de entrada. Caso contrário, retorna [uflow](#basic_streambuf__uflow).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_streambuf_sbumpc.cpp  
// compile with: /EHsc  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   int i = 0;  
   i = cin.rdbuf( )->sbumpc( );  
   cout << i << endl;  
}  
```  
  
```Output  
  
3  
  
```  
  
```Output  
  
      33  
51  
```  
  
##  <a name="a-namebasicstreambufseekoffa--basicstreambufseekoff"></a><a name="basic_streambuf__seekoff"></a>  basic_streambuf::seekoff  
 Uma função de membro virtual protegida que tenta alterar as posições atuais para os fluxos controlados.  
  
```  
virtual pos_type seekoff(
    off_type _Off,  
    ios_base::seekdir _Way,  
    ios_base::openmode _Which = ios_base::in | ios_base::out);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Off`  
 A posição pela qual buscar com relação a `_Way`.  
  
 `_Way`  
 O ponto de partida para operações de deslocamento. Consulte [seekdir](../standard-library/ios-base-class.md#ios_base__seekdir) para valores possíveis.  
  
 `_Which`  
 Especifica o modo para a posição do ponteiro. O padrão é permitir que você modifique as posições de leitura e gravação.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a nova posição ou uma posição de fluxo inválida ( `seekoff` (_ *Off*, `_Way`, `_Which`) ).  
  
### <a name="remarks"></a>Comentários  
 A nova posição é determinada da seguinte forma:  
  
-   Se `_Way`  ==  `ios_base::beg`, a nova posição é o início do fluxo mais _ *Off*.  
  
-   Se `_Way`  ==  `ios_base::cur`, a nova posição é a posição atual do fluxo mais _ *Off*.  
  
-   Se `_Way`  ==  `ios_base::end`, a nova posição é o final do fluxo mais _ *Off*.  
  
 Normalmente, se **which & ios_base::in** for diferente de zero, o fluxo de entrada será afetado; se **which & ios_base::out** for diferente de zero, o fluxo de saída será afetado. No entanto, o uso real desse parâmetro varia entre os buffers de fluxo derivados.  
  
 Se a função tiver êxito em alterar a posição ou as posições do fluxo, ela retornará a posição do fluxo resultante ou uma das posições do fluxo resultantes. Caso contrário, retorna uma posição de fluxo inválida. O comportamento padrão é retornar uma posição de fluxo inválida.  
  
##  <a name="a-namebasicstreambufseekposa--basicstreambufseekpos"></a><a name="basic_streambuf__seekpos"></a>  basic_streambuf::seekpos  
 Uma função de membro virtual protegida que tenta alterar as posições atuais para os fluxos controlados.  
  
```  
virtual pos_type seekpos(pos_type _Sp, ios_base::openmode _Which = ios_base::in | ios_base::out);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Sp`  
 A posição pela qual buscar.  
  
 `_Which`  
 Especifica o modo para a posição do ponteiro. O padrão é permitir que você modifique as posições de leitura e gravação.  
  
### <a name="return-value"></a>Valor de retorno  
 A nova posição ou uma posição de fluxo inválida. Para determinar se a posição de fluxo é inválida, compare o valor retornado com `pos_type(off_type(-1))`.  
  
### <a name="remarks"></a>Comentários  
 A nova posição é _ *Sp*.  
  
 Normalmente, se **which & ios_base::in** for diferente de zero, o fluxo de entrada será afetado; se **which & ios_base::out** for diferente de zero, o fluxo de saída será afetado. No entanto, o uso real desse parâmetro varia entre os buffers de fluxo derivados.  
  
 Se a função tiver êxito em alterar a posição ou as posições do fluxo, ela retornará a posição do fluxo resultante ou uma das posições do fluxo resultantes. Caso contrário, retorna uma posição de fluxo inválida (-1). O comportamento padrão é retornar uma posição de fluxo inválida.  
  
##  <a name="a-namebasicstreambufsetbufa--basicstreambufsetbuf"></a><a name="basic_streambuf__setbuf"></a>  basic_streambuf::setbuf  
 A função membro virtual protegida que executa uma operação específica para cada buffer de fluxo derivado.  
  
```  
virtual basic_streambuf<Elem, Tr> *setbuf(
    char_type* _Buffer,  
    streamsize count);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Buffer`  
 Ponteiro para um buffer.  
  
 ` count`  
 O tamanho do buffer.  
  
### <a name="return-value"></a>Valor de retorno  
 O comportamento padrão é retornar **this**.  
  
### <a name="remarks"></a>Comentários  
 Consulte [basic_filebuf](../standard-library/basic-filebuf-class.md). `setbuf` fornece uma área de memória para o objeto `streambuf` usar. Como o buffer é usado é definido nas classes derivadas.  
  
##  <a name="a-namebasicstreambufsetga--basicstreambufsetg"></a><a name="basic_streambuf__setg"></a>  basic_streambuf::setg  
 Uma função protegida que armazena _ *Gbeg* no ponteiro de início, `_Gnext` no próximo ponteiro e `_Gend` no ponteiro final para o buffer de entrada.  
  
```  
void setg(char_type* _Gbeg,
    char_type* _Gnext,
    char_type* _Gend);
```  
  
### <a name="parameters"></a>Parâmetros  
 *_Gbeg*  
 Um ponteiro para o início do buffer.  
  
 `_Gnext`  
 Um ponteiro para algum lugar no meio do buffer.  
  
 `_Gend`  
 Um ponteiro para o fim do buffer.  
  
##  <a name="a-namebasicstreambufsetpa--basicstreambufsetp"></a><a name="basic_streambuf__setp"></a>  basic_streambuf::setp  
 Uma função protegida que armazena `_Pbeg` no ponteiro inicial e `_Pend` no ponteiro final para o buffer de saída.  
  
```  
void setp(char_type* _Pbeg, char_type* _Pend);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Pbeg`  
 Um ponteiro para o início do buffer.  
  
 `_Pend`  
 Um ponteiro para o fim do buffer.  
  
##  <a name="a-namebasicstreambufsgetca--basicstreambufsgetc"></a><a name="basic_streambuf__sgetc"></a>  basic_streambuf::sgetc  
 Retorna o elemento atual sem alterar a posição no fluxo.  
  
```  
int_type sgetc();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O elemento atual.  
  
### <a name="remarks"></a>Comentários  
 Se uma posição de leitura estiver disponível, a função membro retornará **traits_type::**[to_int_type](../standard-library/char-traits-struct.md#char_traits__to_int_type)( `*` [gptr](#basic_streambuf__gptr)). Caso contrário, retorna [underflow](#basic_streambuf__underflow).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_streambuf_sgetc.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <fstream>  
  
int main( )   
{  
   using namespace std;  
   ifstream myfile( "basic_streambuf_sgetc.txt", ios::in );  
  
   char i = myfile.rdbuf( )->sgetc( );  
   cout << i << endl;  
   i = myfile.rdbuf( )->sgetc( );  
   cout << i << endl;  
}  
```  
  
##  <a name="a-namebasicstreambufsgetna--basicstreambufsgetn"></a><a name="basic_streambuf__sgetn"></a>  basic_streambuf::sgetn  
 Extrai até ` count` caracteres do buffer de entrada e armazena-os no buffer ` ptr` fornecido.  
  
 Esse método pode não ser seguro, pois depende do chamador para verificar se os valores passados estão corretos.  
  
```  
streamsize sgetn(
    char_type* ptr,  
    streamsize count);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` ptr`  
 O buffer que deve conter os caracteres extraídos.  
  
 ` count`  
 O número de elementos a serem lidos.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de elementos lidos. Consulte [streamsize](../standard-library/ios-typedefs.md#streamsize) para obter mais informações.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna [xsgetn](#basic_streambuf__xsgetn)( ` ptr`, ` count`).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_streambuf_sgetn.cpp  
// compile with: /EHsc /W3  
#include <iostream>  
#include <fstream>  
  
int main()  
{  
    using namespace std;  
  
    ifstream myfile("basic_streambuf_sgetn.txt", ios::in);  
    char a[10];  
  
    // Extract 3 characters from myfile and store them in a.  
    streamsize i = myfile.rdbuf()->sgetn(&a[0], 3);  // C4996  
    a[i] = myfile.widen('\0');  
  
    // Display the size and contents of the buffer passed to sgetn.  
    cout << i << " " << a << endl;  
  
    // Display the contents of the original input buffer.  
    cout << myfile.rdbuf() << endl;  
}  
```  
  
##  <a name="a-namebasicstreambufshowmanyca--basicstreambufshowmanyc"></a><a name="basic_streambuf__showmanyc"></a>  basic_streambuf::showmanyc  
 Uma função membro virtual protegida que retorna uma contagem do número de caracteres que pode ser extraído do fluxo de entrada e garante que o programa não esteja sujeito a uma espera indefinida.  
  
```  
virtual streamsize showmanyc();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O comportamento padrão é retornar zero.  
  
##  <a name="a-namebasicstreambufsnextca--basicstreambufsnextc"></a><a name="basic_streambuf__snextc"></a>  basic_streambuf::snextc  
 Lê o elemento atual e retorna o elemento seguinte.  
  
```  
int_type snextc();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O próximo elemento no fluxo.  
  
### <a name="remarks"></a>Comentários  
 A função membro chama [sbumpc](#basic_streambuf__sbumpc) e, se essa função retornar **traits_type::**[eof](../standard-library/char-traits-struct.md#char_traits__eof), retornará **traits_type::eof**. Caso contrário, retorna [sgetc](#basic_streambuf__sgetc).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_streambuf_snextc.cpp  
// compile with: /EHsc  
#include <iostream>  
int main( )   
{  
   using namespace std;  
   int i = 0;  
   i = cin.rdbuf( )->snextc( );  
   // cout << ( int )char_traits<char>::eof << endl;  
   cout << i << endl;  
}  
```  
  
```Output  
  
aa  
  
```  
  
```Output  
  
aa97  
```  
  
##  <a name="a-namebasicstreambufsputbackca--basicstreambufsputbackc"></a><a name="basic_streambuf__sputbackc"></a>  basic_streambuf::sputbackc  
 Coloca um char_type no fluxo.  
  
```  
int_type sputbackc(char_type _Ch);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Ch`  
 O caractere.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o caractere ou a falha.  
  
### <a name="remarks"></a>Comentários  
 Se houver uma posição putback estiver disponível e `_Ch` for comparável ao caractere armazenado nessa posição, a função membro diminuirá o ponteiro seguinte para o buffer de entrada e retornará **traits_type::**[to_int_type](../standard-library/char-traits-struct.md#char_traits__to_int_type)( `_Ch`). Caso contrário, retorna [pbackfail](#basic_streambuf__pbackfail)( `_Ch`).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_streambuf_sputbackc.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <fstream>  
  
int main( )  
{  
    using namespace std;  
  
    ifstream myfile("basic_streambuf_sputbackc.txt",  
        ios::in);  
  
    int i = myfile.rdbuf()->sbumpc();  
    cout << (char)i << endl;  
    int j = myfile.rdbuf()->sputbackc('z');  
    if (j == 'z')  
    {  
        cout << "it worked" << endl;  
    }  
    i = myfile.rdbuf()->sgetc();  
    cout << (char)i << endl;  
}  
```  
  
##  <a name="a-namebasicstreambufsputca--basicstreambufsputc"></a><a name="basic_streambuf__sputc"></a>  basic_streambuf::sputc  
 Coloca um caractere no fluxo.  
  
```  
int_type sputc(char_type _Ch);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Ch`  
 O caractere.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o caractere, se for bem-sucedido.  
  
### <a name="remarks"></a>Comentários  
 Se um `write position` estiver disponível, a função membro armazenará `_Ch` na posição de gravação, incrementará o ponteiro seguinte para o buffer de saída e retornará **traits_type::**[to_int_type](../standard-library/char-traits-struct.md#char_traits__to_int_type)( `_Ch`). Caso contrário, retorna [overflow](#basic_streambuf__overflow)( `_Ch`).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_streambuf_sputc.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <fstream>  
  
int main( )   
{  
   using namespace std;  
  
   int i = cout.rdbuf( )->sputc( 'a' );  
   cout << endl << ( char )i << endl;  
}  
```  
  
```Output  
a  
a  
```  
  
##  <a name="a-namebasicstreambufsputna--basicstreambufsputn"></a><a name="basic_streambuf__sputn"></a>  basic_streambuf::sputn  
 Coloca uma cadeia de caracteres no fluxo.  
  
```  
streamsize sputn(const char_type* ptr, streamsize count);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` ptr`  
 A cadeia de caracteres.  
  
 ` count`  
 A contagem de caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de caracteres de fato inseridos no fluxo.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna [xsputn](#basic_streambuf__xsputn)( ` ptr`, ` count`). Consulte a seção Comentários desse membro para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_streambuf_sputn.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <fstream>  
  
int main()  
{  
    using namespace std;  
  
    streamsize i = cout.rdbuf()->sputn("test", 4);  
    cout << endl << i << endl;  
}  
```  
  
```Output  
test  
4  
```  
  
##  <a name="a-namebasicstreambufstossca--basicstreambufstossc"></a><a name="basic_streambuf__stossc"></a>  basic_streambuf::stossc  
 Move-se além do elemento atual no fluxo.  
  
```  
void stossc();
```  
  
### <a name="remarks"></a>Comentários  
 A função membro chama [sbumpc](#basic_streambuf__sbumpc). Observe que uma implementação não é necessária para fornecer essa função membro.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_streambuf_stossc.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <fstream>  
  
int main( )   
{  
   using namespace std;  
   ifstream myfile( "basic_streambuf_stossc.txt", ios::in );  
  
   myfile.rdbuf( )->stossc( );  
   char i = myfile.rdbuf( )->sgetc( );  
   cout << i << endl;  
}  
```  
  
##  <a name="a-namebasicstreambufsungetca--basicstreambufsungetc"></a><a name="basic_streambuf__sungetc"></a>  basic_streambuf::sungetc  
 Obtém um caractere do fluxo.  
  
```  
int_type sungetc();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o caractere ou a falha.  
  
### <a name="remarks"></a>Comentários  
 Se uma posição de putback estiver disponível, a função membro diminuirá o ponteiro seguinte para o buffer de entrada e retornará `traits_type::` [to_int_type](../standard-library/char-traits-struct.md#char_traits__to_int_type)( `*` [gptr](#basic_streambuf__gptr)). No entanto, nem sempre é possível determinar o último caractere lido para que ele pode ser capturado no estado do buffer atual. Se isso for true, a função retornará [pbackfail](#basic_streambuf__pbackfail). Para evitar essa situação, acompanhe o caractere a colocado de volta e chame `sputbackc(ch)`, que não falhará, desde que você não o chame no início do fluxo e não tente colocar mais de um caractere de volta.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_streambuf_sungetc.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <fstream>  
  
int main( )   
{  
   using namespace std;  
  
   ifstream myfile( "basic_streambuf_sungetc.txt", ios::in );  
  
   // Read and increment  
   int i = myfile.rdbuf( )->sbumpc( );  
   cout << ( char )i << endl;  
  
   // Read and increment  
   i = myfile.rdbuf( )->sbumpc( );  
   cout << ( char )i << endl;  
  
   // Decrement, read, and do not increment  
   i = myfile.rdbuf( )->sungetc( );  
   cout << ( char )i << endl;  
  
   i = myfile.rdbuf( )->sungetc( );   
   cout << ( char )i << endl;  
  
   i = myfile.rdbuf( )->sbumpc( );  
   cout << ( char )i << endl;  
}  
```  
  
##  <a name="a-namebasicstreambufswapa--basicstreambufswap"></a><a name="basic_streambuf__swap"></a>  basic_streambuf::swap  
 Troca os valores nesse objeto pelos valores do objeto `basic_streambuf` fornecido.  
  
```  
void swap(basic_streambuf& right);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|` right`|Uma referência lvalue para o objeto `basic_streambuf` usada para trocar valores.|  
  
### <a name="remarks"></a>Comentários  
 A função membro protegida troca com ` right` todos os ponteiros controlando o `input buffer` e o `output buffer`. Também troca ` right``.`[getloc()](#basic_streambuf__getloc) com o objeto `locale`.  
  
##  <a name="a-namebasicstreambufsynca--basicstreambufsync"></a><a name="basic_streambuf__sync"></a>  basic_streambuf::sync  
 Uma função virtual protegida que tenta sincronizar os fluxos controlados com quaisquer fluxos externos associados.  
  
```  
virtual int sync();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função não conseguir obter êxito, ela retornará -1. O comportamento padrão é retornar zero.  
  
### <a name="remarks"></a>Comentários  
 `sync` envolve gravar quaisquer elementos entre os ponteiros inicial e seguinte para o buffer de saída. Não envolve colocar de volta nenhum elemento entre os ponteiros seguinte e final para o buffer de entrada.  
  
##  <a name="a-namebasicstreambuftraitstypea--basicstreambuftraitstype"></a><a name="basic_streambuf__traits_type"></a>  basic_streambuf::traits_type  
 Associa um nome de tipo ao parâmetro de modelo **Tr**.  
  
```  
typedef Tr traits_type;  
```  
  
##  <a name="a-namebasicstreambufuflowa--basicstreambufuflow"></a><a name="basic_streambuf__uflow"></a>  basic_streambuf::uflow  
 Função virtual protegida que extrai o elemento atual do fluxo de entrada.  
  
```  
virtual int_type uflow();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O elemento atual.  
  
### <a name="remarks"></a>Comentários  
 A função membro virtual protegida tenta extrair o elemento atual **ch** do fluxo de entrada, então avança a posição atual do fluxo e retorna o elemento como **traits_type::**[to_int_type](../standard-library/char-traits-struct.md#char_traits__to_int_type)( **ch**). Isso pode ser feito de várias maneiras:  
  
-   Se houver uma posição de leitura estiver disponível, ela pegará **ch** como o elemento armazenado na posição leitura e avançará o próximo ponteiro para o buffer de entrada.  
  
-   Ele pode ler um elemento diretamente, de alguma fonte externa e entregá-lo como o valor **ch**.  
  
-   Para um buffer de fluxo com fluxos de entrada e saída comuns, ele pode disponibilizar uma posição de leitura gravando, em algum destino externo, alguns ou todos os elementos entre os ponteiros inicial e seguintes para o buffer de saída. Ou pode alocar armazenamento novo ou adicional para o buffer de entrada. A função então lê, de alguma fonte externa, um ou mais elementos.  
  
 Se a função não conseguir obter sucesso, ela retornará **traits_type::**[eof](../standard-library/char-traits-struct.md#char_traits__eof) ou gerará uma exceção. Caso contrário, retornará o elemento `ch` atual no fluxo de entrada, convertido conforme descrito acima e avançará o ponteiro seguinte para o buffer de entrada. O comportamento padrão é chamar [underflow](#basic_streambuf__underflow) e, se essa função retornar **traits_type::eof**, retornar **traits_type::eof**. Caso contrário, a função retorna o elemento atual **ch** no fluxo de entrada, convertido conforme descrito anteriormente e avança o ponteiro seguinte para o buffer de entrada.  
  
##  <a name="a-namebasicstreambufunderflowa--basicstreambufunderflow"></a><a name="basic_streambuf__underflow"></a>  basic_streambuf::underflow  
 Função virtual protegida para extrair o elemento atual do fluxo de entrada.  
  
```  
virtual int_type underflow();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O elemento atual.  
  
### <a name="remarks"></a>Comentários  
 A função membro virtual protegida busca extrair o elemento atual **ch** do fluxo de entrada, sem avançar a posição de fluxo atual e retorná-la como `traits_type::`[to_int_type](../standard-library/char-traits-struct.md#char_traits__to_int_type)( **ch**). Isso pode ser feito de várias maneiras:  
  
-   Se uma posição de leitura estiver disponível, **ch** será o elemento armazenado na posição de leitura. Para obter mais informações sobre isso, consulte a seção Comentários da [Classe basic_streambuf](../standard-library/basic-streambuf-class.md).  
  
-   Pode disponibilizar uma posição de leitura alocando armazenamento novo ou adicional para o buffer de entrada, então lendo, de alguma fonte externa, um ou mais elementos. Para obter mais informações sobre isso, consulte a seção Comentários da [Classe basic_streambuf](../standard-library/basic-streambuf-class.md).  
  
 Se a função não conseguir obter sucesso, ela retornará `traits_type::`[eof](../standard-library/char-traits-struct.md#char_traits__eof)`()` ou gerará uma exceção. Caso contrário, retornará o elemento atual no fluxo de entrada, convertido conforme descrito anteriormente. O comportamento padrão é retornar `traits_type::eof()`.  
  
 A função `underflow` virtual, com as funções [sync](#basic_streambuf__sync) e [overflow](#basic_streambuf__overflow), define as características da classe derivada de `streambuf`. Cada classe derivada pode implementar `underflow` de forma diferente, mas a interface com a classe de fluxo de chamada é a mesma.  
  
 A função `underflow` frequentemente é chamada por funções `streambuf` públicas como [sgetc](#basic_streambuf__sgetc) e [sgetn](#basic_streambuf__sgetn) quando a área get está vazia, mas outras classes, incluindo as classes de fluxo, podem chamar `underflow` a qualquer momento.  
  
 A função `underflow` fornece a área de get caracteres da fonte de entrada. Se a área get contiver caracteres, `underflow` retornará o primeiro caractere. Se a área get estiver vazia, ela preencherá a área get e retornará o caractere seguinte (que deixa na área get). Não se houver mais nenhum caractere disponível, `underflow` retornará `EOF` e deixará a área get vazia.  
  
 Na classe `strstreambuf`, `underflow` ajusta o ponteiro [egptr](#basic_streambuf__egptr) para acessar o armazenamento alocado dinamicamente por uma chamada para `overflow`.  
  
##  <a name="a-namebasicstreambufxsgetna--basicstreambufxsgetn"></a><a name="basic_streambuf__xsgetn"></a>  basic_streambuf::xsgetn  
 Função virtual protegida para extrair elementos do fluxo de entrada.  
  
 Esse método pode não ser seguro, pois depende do chamador para verificar se os valores passados estão corretos.  
  
```  
virtual streamsize xsgetn(
    char_type* ptr,  
    streamsize count);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` ptr`  
 O buffer que deve conter os caracteres extraídos.  
  
 ` count`  
 O número de elementos a extrair.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de elementos extraídos.  
  
### <a name="remarks"></a>Comentários  
 A função de membro virtual protegida extrai até ` count` elementos do fluxo de entrada, como por chamadas repetidas a [sbumpc](#basic_streambuf__sbumpc) e armazena-os na matriz que começa em ` ptr`. Retorna o número de elementos realmente extraídos.  
  
##  <a name="a-namebasicstreambufxsputna--basicstreambufxsputn"></a><a name="basic_streambuf__xsputn"></a>  basic_streambuf::xsputn  
 Função virtual protegida para inserir elementos no fluxo de saída.  
  
```  
virtual streamsize xsputn(const char_type* ptr, streamsize count);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` ptr`  
 Ponteiro para elementos a inserir.  
  
 ` count`  
 Número de elementos a inserir.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de elementos realmente inseridos no fluxo.  
  
### <a name="remarks"></a>Comentários  
 A função de membro virtual protegida insere até ` count` elementos no fluxo de saída, como se por chamadas repetidas a [sputc](#basic_streambuf__sputc), da matriz que começa em ` ptr`. A inserção de caracteres no fluxo de saída para quando todos os caracteres ` count` tiverem sido gravados ou se chamar `sputc( count)` retornaria `traits::eof()`. Retorna o número de elementos realmente inseridos.  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação de iostream](../standard-library/iostream-programming.md)   
 [Convenções de iostreams](../standard-library/iostreams-conventions.md)


