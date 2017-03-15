---
title: "Classe basic_ios | Microsoft Docs"
ms.custom: ""
ms.date: "11/04/2016"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "std.basic_ios"
  - "ios/std::basic_ios"
  - "basic_ios"
  - "std::basic_ios"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "basic_ios class"
ms.assetid: 4fdcd8e1-62d2-4611-8a70-1e4f58434007
caps.latest.revision: 24
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
# <a name="basicios-class"></a>Classe basic_ios
A classe de modelo descreve as funções membro e de armazenamento comuns a ambos os fluxos de entrada (da classe de modelo [basic_istream](../standard-library/basic-istream-class.md)) e os fluxos de saída (da classe de modelo [basic_ostream](../standard-library/basic-ostream-class.md)) que dependem dos parâmetros do modelo. (A classe [ios_base](../standard-library/ios-base-class.md) descreve o que é comum e não depende dos parâmetros de modelo.) Um objeto da classe **basic_ios\<classe Elem, classe Traits>** ajuda a controlar um fluxo com elementos do tipo **Elem**, cujas características de caractere são determinadas pela classe **Traits**.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
 
template <class Elem, class Traits>  
class basic_ios : public ios_base  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Elem`  
 Um tipo.  
  
 `Traits`  
 Uma variável do tipo `char_traits`.  
  
## <a name="remarks"></a>Comentários  
 Um objeto da classe **basic_ios\<classe Elem, classe Traits>** armazena:  
  
-   Um ponteiro de ligação para um objeto do tipo [basic_istream](../standard-library/basic-istream-class.md)**\<Elem, Traits>**.  
  
-   Um ponteiro de buffer de fluxo para um objeto do tipo [basic_streambuf](../standard-library/basic-streambuf-class.md)**\<Elem, Traits >**.  
  
- [Informações de formatação](../standard-library/ios-base-class.md).  
  
- [Informações de estado de fluxo](../standard-library/ios-base-class.md) em um objeto base do tipo [ios_base](../standard-library/ios-base-class.md).  
  
-   Um caractere de preenchimento em um objeto do tipo `char_type`.  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[basic_ios](#basic_ios__basic_ios)|Constrói a classe `basic_ios`.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[char_type](#basic_ios__char_type)|Um sinônimo para o parâmetro de modelo `Elem`.|  
|[int_type](#basic_ios__int_type)|Um sinônimo de `Traits::int_type`.|  
|[off_type](#basic_ios__off_type)|Um sinônimo de `Traits::off_type`.|  
|[pos_type](#basic_ios__pos_type)|Um sinônimo de `Traits::pos_type`.|  
|[traits_type](#basic_ios__traits_type)|Um sinônimo para o parâmetro de modelo `Traits`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[bad](#basic_ios__bad)|Indica a perda de integridade do buffer de fluxo.|  
|[clear](#basic_ios__clear)|Limpa todos os sinalizadores de erro.|  
|[copyfmt](#basic_ios__copyfmt)|Copia sinalizadores de um fluxo para outro.|  
|[eof](#basic_ios__eof)|Indica se o final de um fluxo foi atingido.|  
|[exceptions](#basic_ios__exceptions)|Indica quais exceções serão lançadas pelo fluxo.|  
|[fail](#basic_ios__fail)|Indica falha ao extrair um campo válido de um fluxo.|  
|[fill](#basic_ios__fill)|Especifica ou retorna o caractere que será usado quando o texto não for tão grande quanto o fluxo.|  
|[good](#basic_ios__good)|Indica que o fluxo está em boas condições.|  
|[imbue](#basic_ios__imbue)|Altera a localidade.|  
|[init](#basic_ios__init)|Chamado por construtores `basic_ios`.|  
|[move](#basic_ios__move)|Move todos os valores, exceto o ponteiro para o buffer de fluxo, do parâmetro para o objeto atual.|  
|[narrow](#basic_ios__narrow)|Localiza o char equivalente para um determinado `char_type`.|  
|[rdbuf](#basic_ios__rdbuf)|Encaminha o fluxo para um buffer especificado.|  
|[rdstate](#basic_ios__rdstate)|Lê o estado dos bits para sinalizadores.|  
|[set_rdbuf](#basic_ios__set_rdbuf)|Atribui um buffer de fluxo para ser o buffer de leitura para esse objeto de fluxo.|  
|[setstate](#basic_ios__setstate)|Define sinalizadores adicionais.|  
|[swap](#basic_ios__swap)|Troca os valores nesse objeto `basic_ios` por aqueles de outro objeto `basic_ios`. Os ponteiros para buffers de fluxo não são trocados.|  
|[tie](#basic_ios__tie)|Garante que um fluxo seja processado antes de outro.|  
|[widen](#basic_ios__widen)|Localiza o `char_type` equivalente a um determinado char.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[explicit operator bool](#basic_ios__operator_bool)|Permite o uso de um objeto `basic_ios` como um `bool`. Conversão de tipo automática é desabilitada para evitar efeitos colaterais comuns não intencionais.|  
|[operator void *](#basic_ios__operator_void_star)|Indica se o fluxo ainda é válido.|  
|[operator!](#basic_ios__operator_not)|Indica se o fluxo não é inválido.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<ios>  
  
 **Namespace:** std  
  
##  <a name="a-namebasiciosbada--basiciosbad"></a><a name="basic_ios__bad"></a>  basic_ios::bad  
 Indica a perda de integridade do buffer de fluxo  
  
```  
bool bad() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se `rdstate & badbit` for diferente de zero; caso contrário `false`.  
  
 Para obter mais informações sobre `badbit`, consulte [ios_base::iostate](../standard-library/ios-base-class.md#ios_base__iostate).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_ios_bad.cpp  
// compile with: /EHsc  
#include <iostream>  
  
int main( void )  
{  
  using namespace std;  
  bool b = cout.bad( );  
  cout << boolalpha;  
  cout << b << endl;  
    
  b = cout.good( );  
  cout << b << endl;  
}  
  
```  
  
##  <a name="a-namebasiciosbasiciosa--basiciosbasicios"></a><a name="basic_ios__basic_ios"></a>  basic_ios::basic_ios  
 Constrói a classe basic_ios.  
  
```   
explicit basic_ios(basic_streambuf<Elem,  Traits>* sb);
basic_ios();
```  
  
### <a name="parameters"></a>Parâmetros  
 `sb`  
 Buffer padrão para armazenar elementos de entrada ou saída.  
  
### <a name="remarks"></a>Comentários  
 O primeiro construtor inicializa seus objetos de membro chamando [init](#basic_ios__init)(_ *Sb*). O segundo construtor (protegido) deixa seus objetos do membro não inicializados. Uma chamada posterior a **init** deve inicializar o objeto antes de ser destruída com segurança.  
  
##  <a name="a-namebasicioschartypea--basicioschartype"></a><a name="basic_ios__char_type"></a>  basic_ios::char_type  
 Um sinônimo para o parâmetro de modelo **Elem**.  
  
```   
typedef Elem char_type;  
```  
  
##  <a name="a-namebasicioscleara--basiciosclear"></a><a name="basic_ios__clear"></a>  basic_ios::clear  
 Limpa todos os sinalizadores de erro.  
  
```   
void clear(iostate state = goodbit, bool reraise = false); 
void clear(io_state state);
```  
  
### <a name="parameters"></a>Parâmetros  
 `state` (opcional)  
 Os sinalizadores a definir após limpeza de todos os sinalizadores. Assume o padrão de `goodbit`.  
  
 `reraise` (opcional)  
 Especifica se a exceção deve ser gerada novamente. Assume o padrão de `false` (não irá gerar novamente a exceção).  
  
### <a name="remarks"></a>Comentários  
 Os sinalizadores são **goodbit**, **failbit**, **eofbit** e **badbit**. Teste esses sinalizadores com [good](#basic_ios__good), [bad](#basic_ios__bad), [eof](#basic_ios__eof) e [fail](#basic_ios__fail)  
  
 A função de membro substitui as informações de estado de fluxo armazenadas com:  
  
 `state` &#124; `(`[rdbuf](#basic_ios__rdbuf) != 0 **goodbit** : **badbit**)  
  
 Se `state`**&**[exceptions](#basic_ios__exceptions) for diferente de zero, gera um objeto da classe [failure](../standard-library/ios-base-class.md#ios_base__failure).  
  
### <a name="example"></a>Exemplo  
  Consulte [rdstate](#basic_ios__rdstate) e [getline](../standard-library/string-functions.md#getline) para exemplos, usando **clear**.  
  
##  <a name="a-namebasicioscopyfmta--basicioscopyfmt"></a><a name="basic_ios__copyfmt"></a>  basic_ios::copyfmt  
 Copia sinalizadores de um fluxo para outro.  
  
```   
basic_ios<Elem, Traits>& copyfmt(
const basic_ios<Elem, Traits>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` right`  
 O fluxo cujos sinalizadores você deseja copiar.  
  
### <a name="return-value"></a>Valor de retorno  
 O objeto **this** para o fluxo para o qual você está copiando os sinalizadores.  
  
### <a name="remarks"></a>Comentários  
 A função membro relata o retorno de chamada eventÂ erase_event. Em seguida, copia do ` right` para **\*this** o caractere de preenchimento, o ponteiro de ligação e as informações de formatação. Antes de alterar a máscara de exceção, ele relata o evento de retorno de chamada copyfmt_event. Se, após a cópia estar concluída, **state &**[exceptions](#basic_ios__exceptions) for diferente de zero, a função chamará [clear](#basic_ios__clear) efetivamente com o argumento [rdstate](#basic_ios__rdstate). Retorna **\*this**.  
  
### <a name="example"></a>Exemplo  
  
```cpp    
// basic_ios_copyfmt.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <fstream>  
  
int main( )  
{  
  using namespace std;  
  ofstream x( "test.txt" );  
  int i = 10;  
    
  x << showpos;  
  cout << i << endl;  
  cout.copyfmt( x );  
  cout << i << endl;  
}  
  
```  
  
##  <a name="a-namebasicioseofa--basicioseof"></a><a name="basic_ios__eof"></a>  basic_ios::eof  
 Indica se o final de um fluxo foi atingido.  
  
```  
bool eof() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se o fim do fluxo tiver sido atingido, `false` caso contrário.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna `true` se [rdstate](#basic_ios__rdstate) `& eofbit` for diferente de zero. Para obter mais informações sobre `eofbit`, consulte [ios_base::iostate](../standard-library/ios-base-class.md#ios_base__iostate).  
  
### <a name="example"></a>Exemplo  
  
```cpp    
// basic_ios_eof.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <fstream>  
  
using namespace std;  
  
int main( int argc, char* argv[] )  
{  
  fstream   fs;  
  int n = 1;  
  fs.open( "basic_ios_eof.txt" );   // an empty file  
  cout << boolalpha  
  cout << fs.eof() << endl;  
  fs >> n;   // Read the char in the file  
  cout << fs.eof() << endl;  
}  
  
```  
  
##  <a name="a-namebasiciosexceptionsa--basiciosexceptions"></a><a name="basic_ios__exceptions"></a>  basic_ios::exceptions  
 Indica quais exceções serão lançadas pelo fluxo.  
  
```   
iostate exceptions() const; 
void exceptions(iostate Newexcept);
void exceptions(io_state Newexcept);
```  
  
### <a name="parameters"></a>Parâmetros  
 *Newexcept*  
 Os sinalizadores que você deseja que gerem uma exceção.  
  
### <a name="return-value"></a>Valor de retorno  
 Os sinalizadores atualmente especificados para gerar uma exceção para o fluxo.  
  
### <a name="remarks"></a>Comentários  
 A primeira função membro retorna a máscara de exceção armazenada. A segunda função membro armazena *_Except* na máscara de exceção e retorna seu valor armazenado anterior. Observe que armazenar uma nova máscara de exceção pode lançar uma exceção assim como a chamada [clear](#basic_ios__clear)( [rdstate](#basic_ios__rdstate) ).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_ios_exceptions.cpp  
// compile with: /EHsc /GR  
#include <iostream>  
  
int main( )  
{  
  using namespace std;  
    
  cout << cout.exceptions( ) << endl;  
  cout.exceptions( ios::eofbit );  
  cout << cout.exceptions( ) << endl;  
  try  
  {  
    cout.clear( ios::eofbit );   // Force eofbit on  
  }  
  catch ( exception &e )  
  {  
    cout.clear( );  
    cout << "Caught the exception." << endl;  
    cout << "Exception class: " << typeid(e).name()  << endl;  
    cout << "Exception description: " << e.what() << endl;  
  }  
}  
  
```  
  
```Output  
  
0  
1  
Caught the exception.  
Exception class: class std::ios_base::failure  
Exception description: ios_base::eofbit set   
```  
  
##  <a name="a-namebasiciosfaila--basiciosfail"></a><a name="basic_ios__fail"></a>  basic_ios::fail  
 Indica falha ao extrair um campo válido de um fluxo.  
  
```  
bool fail() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se [rdstate](#basic_ios__rdstate) `& (badbit|failbit)` for diferente de zero, caso contrário, `false`.  
  
 Para obter mais informações sobre `failbit`, consulte [ios_base::iostate](../standard-library/ios-base-class.md#ios_base__iostate).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_ios_fail.cpp  
// compile with: /EHsc  
#include <iostream>  
  
int main( void )  
{  
  using namespace std;  
  bool b = cout.fail( );  
  cout << boolalpha;  
  cout << b << endl;  
}  
  
```  
  
##  <a name="a-namebasiciosfilla--basiciosfill"></a><a name="basic_ios__fill"></a>  basic_ios::fill  
 Especifica ou retorna o caractere que será usado quando o texto não for tão grande quanto o fluxo.  
  
```   
char_type fill() const; 
char_type fill(char_type Char);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Char`  
 O caractere que você deseja usar como caractere de preenchimento.  
  
### <a name="return-value"></a>Valor de retorno  
 O caractere de preenchimento atual.  
  
### <a name="remarks"></a>Comentários  
 A primeira função membro retorna o caractere de preenchimento armazenado. A segunda função membro armazena `Char` no caractere de preenchimento e retorna seu valor armazenado anterior.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_ios_fill.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <iomanip>  
  
int main( )  
{  
  using namespace std;  
    
  cout << setw( 5 ) << 'a' << endl;     
  cout.fill( 'x' );  
  cout << setw( 5 ) << 'a' << endl;      
  cout << cout.fill( ) << endl;  
}  
  
```  
  
```Output  
  
a  
xxxxa  
x   
```  
  
##  <a name="a-namebasiciosgooda--basiciosgood"></a><a name="basic_ios__good"></a>  basic_ios::good  
 Indica que o fluxo está em boas condições.  
  
```  
bool good() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se [rdstate](#basic_ios__rdstate) `== goodbit` (nenhum sinalizador de estado está definido), caso contrário, `false`.  
  
 Para obter mais informações sobre `goodbit`, consulte [ios_base::iostate](../standard-library/ios-base-class.md#ios_base__iostate).  
  
### <a name="example"></a>Exemplo  
  Consulte [basic_ios::bad](#basic_ios__bad) para obter um exemplo de como usar `good`.  
  
##  <a name="a-namebasiciosimbuea--basiciosimbue"></a><a name="basic_ios__imbue"></a>  basic_ios::imbue  
 Altera a localidade.  
  
```   
locale imbue(const locale& Loc);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Loc`  
 Uma cadeia de caracteres de localidade.  
  
### <a name="return-value"></a>Valor de retorno  
 A localidade anterior.  
  
### <a name="remarks"></a>Comentários  
 Se [rdbuf](#basic_ios__rdbuf) não for um ponteiro nulo, a função membro chamará  
  
 `rdbuf`-> [pubimbue](../standard-library/basic-streambuf-class.md#basic_streambuf__pubimbue)(_ *Loc*)  
  
 Em qualquer caso, retorna [ios_base::imbue](../standard-library/ios-base-class.md#ios_base__imbue)(_ *Loc*).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_ios_imbue.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <locale>  
  
int main( )  
{  
  using namespace std;  
    
  cout.imbue( locale( "french_france" ) );  
  double x = 1234567.123456;  
  cout << x << endl;  
}  
  
```  
  
##  <a name="a-namebasiciosinita--basiciosinit"></a><a name="basic_ios__init"></a>  basic_ios::init  
 Chamado por construtores basic_ios.  
  
```  
 
void init(basic_streambuf<Elem,Traits>* _Sb, bool _Isstd = false);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Sb`  
 Buffer padrão para armazenar elementos de entrada ou saída.  
  
 `_Isstd`  
 Especifica se esse é um fluxo padrão.  
  
### <a name="remarks"></a>Comentários  
 A função membro armazena valores em todos os objetos membro, de modo que:  
  
- [rdbuf](#basic_ios__rdbuf) retorna *_Sb.*  
  
- [tie](#basic_ios__tie) retorna um ponteiro nulo.  
  
- [rdstate](#basic_ios__rdstate) retornará [goodbit](../standard-library/ios-base-class.md#ios_base__iostate) se `_Sb` for diferente de zero; caso contrário, retornará [badbit](../standard-library/ios-base-class.md#ios_base__iostate).  
  
- [exceptions](#basic_ios__exceptions) retorna **goodbit**.  
  
- [flags](../standard-library/ios-base-class.md#ios_base__flags) retorna [skipws](../standard-library/ios-base-class.md#ios_base__fmtflags) &#124; [dec](../standard-library/ios-base-class.md#ios_base__fmtflags).  
  
- [width](../standard-library/ios-base-class.md#ios_base__width) retorna 0.  
  
- [precision](../standard-library/ios-base-class.md#ios_base__precision) retorna 6.  
  
- [fill](#basic_ios__fill) retorna o caractere de espaço.  
  
- [getloc](../standard-library/ios-base-class.md#ios_base__getloc) retorna `locale::classic`.  
  
- [iword](../standard-library/ios-base-class.md#ios_base__iword) retorna zero e [pword](../standard-library/ios-base-class.md#ios_base__pword) retorna um ponteiro nulo para todos os valores de argumento.  
  
##  <a name="a-namebasiciosinttypea--basiciosinttype"></a><a name="basic_ios__int_type"></a>  basic_ios::int_type  
 Um sinônimo de **traits_type::int_type**.  
  
```  
typedef typename traits_type::int_type int_type;  
```  
  
##  <a name="a-namebasiciosmovea--basiciosmove"></a><a name="basic_ios__move"></a>  basic_ios::move  
 Move todos os valores, exceto o ponteiro para o buffer de fluxo, do parâmetro para o objeto atual.  
  
```   
void move(basic_ios&& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `right`  
 O objeto `ios_base` do qual mover valores.  
  
### <a name="remarks"></a>Comentários  
 A função membro protegida move todos os valores armazenados em ` right` para `*this`, exceto o `stream buffer pointer` armazenado, que permanece inalterado em ` right` e definido como um ponteiro nulo em `*this`. O `tie pointer` armazenado é definido como um ponteiro nulo em ` right`.  
  
##  <a name="a-namebasiciosnarrowa--basiciosnarrow"></a><a name="basic_ios__narrow"></a>  basic_ios::narrow  
 Localiza o char equivalente para um determinado `char_type`.  
  
```  
 
char narrow(char_type Char, char Default = '\0') const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `Char`  
 O `char` a ser convertido.  
  
 `Default`  
 O `char` que você deseja que seja retornado se nenhum equivalente for encontrado.  
  
### <a name="return-value"></a>Valor de retorno  
 O equivalente `char` para um determinado `char_type`.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna [use_facet](../standard-library/basic-filebuf-class.md#basic_filebuf__open)**<**Â **ctype**\< **E**> >( [getloc](../standard-library/ios-base-class.md#ios_base__getloc)( ) ). `narrow`( `Char`, `Default`).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_ios_narrow.cpp  
// compile with: /EHsc  
#include <ios>  
#include <iostream>  
#include <wchar.h>  
  
int main( )  
{  
  using namespace std;  
  wchar_t *x = L"test";  
  char y[10];  
  cout << x[0] << endl;  
  wcout << x << endl;  
  y[0] = wcout.narrow( x[0] );  
  cout << y[0] << endl;  
}  
  
```  
  
##  <a name="a-namebasiciosofftypea--basiciosofftype"></a><a name="basic_ios__off_type"></a>  basic_ios::off_type  
 Um sinônimo de **traits_type::off_type**.  
  
```  
typedef typename traits_type::off_type off_type;  
```  
  
##  <a name="a-namebasiciosoperatorvoidstara--basiciosoperator-void-"></a><a name="basic_ios__operator_void_star"></a>  basic_ios::operator void *  
 Indica se o fluxo ainda é válido.  
  
```  
 operator void *() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O operador retorna um ponteiro nulo apenas se [fail](#basic_ios__fail).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_ios_opgood.cpp  
// compile with: /EHsc  
#include <iostream>  
  
int main( )  
{  
  using namespace std;  
  cout << (bool)(&cout != 0) << endl;   // Stream is still good  
}  
  
```  
  
```Output  
1  
```  
  
##  <a name="a-namebasiciosoperatornota--basiciosoperator"></a><a name="basic_ios__operator_not"></a>  basic_ios::operator!  
 Indica se o fluxo não é inválido.  
  
```   
bool operator!() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna [fail](#basic_ios__fail).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_ios_opbad.cpp  
// compile with: /EHsc  
#include <iostream>  
  
int main( )  
{  
  using namespace std;  
  cout << !cout << endl;   // Stream is not bad  
}  
  
```  
  
```Output  
0  
```  
  
##  <a name="a-namebasiciosoperatorboola--basiciosoperator-bool"></a><a name="basic_ios__operator_bool"></a>  basic_ios::operator bool  
 Permite o uso de um objeto `basic_ios` como um `bool`. Conversão de tipo automática é desabilitada para evitar efeitos colaterais comuns não intencionais.  
  
```  
explicit operator bool() const;
```  
  
### <a name="remarks"></a>Comentários  
 O operador retornará um valor conversível em `false` somente se `fail``()`. O tipo de retorno é conversível apenas em `bool`, não em `void *` ou outro tipo escalar conhecido.  
  
##  <a name="a-namebasiciospostypea--basiciospostype"></a><a name="basic_ios__pos_type"></a>  basic_ios::pos_type  
 Um sinônimo de **traits_type::pos_type**.  
  
```  
typedef typename traits_type::pos_type pos_type;  
```  
  
##  <a name="a-namebasiciosrdbufa--basiciosrdbuf"></a><a name="basic_ios__rdbuf"></a>  basic_ios::rdbuf  
 Encaminha o fluxo para um buffer especificado.  
  
```   
basic_streambuf<Elem, Traits> *rdbuf() const; 
basic_streambuf<Elem, Traits> *rdbuf(
basic_streambuf<Elem, Traits>* _Sb);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Sb`  
 Um fluxo.  
  
### <a name="remarks"></a>Comentários  
 A primeira função membro retorna o ponteiro de buffer de fluxo armazenado.  
  
 A segunda função membro armazena `_Sb` no ponteiro de buffer de fluxo armazenadas e retorna o valor armazenado anteriormente.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_ios_rdbuf.cpp  
// compile with: /EHsc  
#include <ios>  
#include <iostream>  
#include <fstream>  
  
int main( )  
{  
  using namespace std;  
  ofstream file( "rdbuf.txt" );  
  streambuf *x = cout.rdbuf( file.rdbuf( ) );  
  cout << "test" << endl;   // Goes to file  
  cout.rdbuf(x);  
  cout << "test2" << endl;  
}  
  
```  
  
```Output  
test2  
```  
  
##  <a name="a-namebasiciosrdstatea--basiciosrdstate"></a><a name="basic_ios__rdstate"></a>  basic_ios::rdstate  
 Lê o estado dos bits para sinalizadores.  
  
```  
 
iostate rdstate() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 As informações de estado de fluxo armazenadas.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_ios_rdstate.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <fstream>  
using namespace std;  
  
void TestFlags( ios& x )  
{  
  cout << ( x.rdstate( ) & ios::badbit ) << endl;  
  cout << ( x.rdstate( ) & ios::failbit ) << endl;  
  cout << ( x.rdstate( ) & ios::eofbit ) << endl;  
  cout << endl;  
}  
  
int main( )  
{  
  fstream x( "c:\test.txt", ios::out );  
  x.clear( );  
  TestFlags( x );  
  x.clear( ios::badbit | ios::failbit | ios::eofbit );  
  TestFlags( x );  
}  
  
```  
  
```Output  
  
0  
0  
0  
  
4  
2  
1   
```  
  
##  <a name="a-namebasiciossetstatea--basiciossetstate"></a><a name="basic_ios__setstate"></a>  basic_ios::setstate  
 Define sinalizadores adicionais.  
  
```   
void setstate(iostate _State);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_State`  
 Sinalizadores adicionais a serem definidos.  
  
### <a name="remarks"></a>Comentários  
 A função membro efetivamente chama [clear](#basic_ios__clear)(_ *State* &#124; [rdstate](#basic_ios__rdstate)).  
  
### <a name="example"></a>Exemplo  
  
```cpp    
// basic_ios_setstate.cpp  
// compile with: /EHsc  
#include <ios>  
#include <iostream>  
using namespace std;  
  
int main( )  
{  
  bool b = cout.bad( );  
  cout << b << endl;   // Good  
  cout.clear( ios::badbit );  
  b = cout.bad( );  
  // cout.clear( );  
  cout << b << endl;   // Is bad, good  
  b = cout.fail( );  
  cout << b << endl;   // Not failed  
  cout.setstate( ios::failbit );  
  b = cout.fail( );  
  cout.clear( );  
  cout << b << endl;   // Is failed, good  
  return 0;  
}  
  
```  
  
```Output  
  
0  
1   
```  
  
##  <a name="a-namebasiciossetrdbufa--basiciossetrdbuf"></a><a name="basic_ios__set_rdbuf"></a>  basic_ios::set_rdbuf  
 Atribui um buffer de fluxo para ser o buffer de leitura para esse objeto de fluxo.  
  
```   
void set_rdbuf(
basic_streambuf<Elem, Tr>* strbuf)  
```  
  
### <a name="parameters"></a>Parâmetros  
 ` strbuf`  
 O buffer de fluxo para se tornar o buffer de leitura.  
  
### <a name="remarks"></a>Comentários  
 A função membro protegida armazenará ` strbuf` no `stream buffer pointer`. Não chama `clear`.  
  
##  <a name="a-namebasiciostiea--basiciostie"></a><a name="basic_ios__tie"></a>  basic_ios::tie  
 Garante que um fluxo seja processado antes de outro.  
  
```  
 
basic_ostream<Elem, Traits> *tie() const; 
basic_ostream<Elem, Traits> *tie(
basic_ostream<Elem, Traits>* str);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` str`  
 Um fluxo.  
  
### <a name="return-value"></a>Valor de retorno  
 A primeira função membro retorna o ponteiro de ligação armazenado. A segunda função membro armazena ` str` no ponteiro de ligação e retorna seu valor armazenado anterior.  
  
### <a name="remarks"></a>Comentários  
 `tie` faz dois fluxos serem sincronizados de modo que operações em um fluxo ocorram depois da conclusão das operações no outro fluxo.  
  
### <a name="example"></a>Exemplo  
  Neste exemplo, ao vincular cin a cout, garante-se que a cadeia de caracteres "Digite um número:" vá para o console antes de o número em si ser extraído do cin. Isso elimina a possibilidade de que a cadeia de caracteres "Digite um número:" ainda esteja no buffer quando o número for lido, para termos certeza de que o usuário de fato tem um prompt para responder. Por padrão, cin e cout estão vinculados.  
  
```  
  
#include <ios>  
#include <iostream>  
  
int main( )  
{  
  using namespace std;  
  int i;  
  cin.tie( &cout );  
  cout << "Enter a number:";  
  cin >> i;  
}  
  
```  
  
##  <a name="a-namebasiciostraitstypea--basiciostraitstype"></a><a name="basic_ios__traits_type"></a>  basic_ios::traits_type  
 Um sinônimo para o parâmetro de modelo **Traits**.  
  
```   
typedef Traits traits_type;  
```  
  
##  <a name="a-namebasicioswidena--basicioswiden"></a><a name="basic_ios__widen"></a>  basic_ios::widen  
 Localiza o `char_type` equivalente para um determinado `char`.  
  
```   
char_type widen(char Char) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `Char`  
 O caractere a ser convertido.  
  
### <a name="return-value"></a>Valor de retorno  
 Localiza o `char_type` equivalente para um determinado `char`.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna [use_facet](../standard-library/basic-filebuf-class.md#basic_filebuf__open)< **ctype**\< **E**> >( [getloc](../standard-library/ios-base-class.md#ios_base__getloc)). `widen`( `Char`).  
  
### <a name="example"></a>Exemplo  
  
```cpp    
// basic_ios_widen.cpp  
// compile with: /EHsc  
#include <ios>  
#include <iostream>  
#include <wchar.h>  
  
int main( )  
{  
  using namespace std;  
  char *z = "Hello";  
  wchar_t y[2] = {0,0};  
  cout << z[0] << endl;  
  y[0] = wcout.widen( z[0] );  
  wcout << &y[0] << endl;  
}  
  
```  
  
##  <a name="a-namebasiciosswapa--basiciosswap"></a><a name="basic_ios__swap"></a>  basic_ios::swap  
 Troca os valores nesse objeto `basic_ios` por aqueles de outro objeto `basic_ios`. Porém, os ponteiros para os buffers de fluxo não são trocados.  
  
```   
void swap(basic_ios&& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `right`  
 O objeto `basic_ios` usado para trocar valores.  
  
### <a name="remarks"></a>Comentários  
 A função membro protegida troca todos os valores armazenados em ` right` por `*this`, exceto o `stream buffer pointer` armazenado.  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação de iostream](../standard-library/iostream-programming.md)   
 [Convenções de iostreams](../standard-library/iostreams-conventions.md)

