---
title: "Classe locale | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "xlocale/std::locale"
  - "std::locale"
  - "std.locale"
  - "locale"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe locale"
ms.assetid: 7dd6d271-472d-4750-8fb5-ea8f55fbef62
caps.latest.revision: 28
caps.handback.revision: 28
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe locale
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe que descreve um objeto de localidade que encapsula informações específicas à cultura como um conjunto de facetas que definem coletivamente um ambiente localizado específico.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class locale;  
```  
  
## <a name="remarks"></a>Comentários  
 Uma faceta é um ponteiro para um objeto de uma classe derivada da classe [faceta](#facet_class) que tem um objeto público do formulário:  
  
```  
static locale::id id;  
```  
  
 Você pode definir um conjunto de final aberto dessas facetas. Também é possível construir um objeto de localidade que designa um número arbitrário de facetas.  
  
 Os grupos predefinidos dessas facetas representam o [categorias de localidade](#locale__category) normalmente gerenciadas na biblioteca C padrão pela função `setlocale`.  
  
 A categoria collate (LC_COLLATE) inclui as facetas:  
  
```  
collate<char>  
collate<wchar_t>  
```  
  
 A categoria ctype (LC_CTYPE) inclui as facetas:  
  
```  
ctype<char>  
ctype<wchar_t>  
codecvt<char, char, mbstate_t>  
codecvt<wchar_t, char, mbstate_t>  
codecvt<char16_t, char, mbstate_t>  
codecvt<char32_t, char, mbstate_t>  
```  
  
 A categoria monetary (LC_MONETARY) inclui as facetas:  
  
```  
moneypunct<char, false>  
moneypunct<wchar_t, false>  
moneypunct<char, true>  
moneypunct<wchar_t, true>  
money_get<char, istreambuf_iterator<char>>  
money_get<wchar_t, istreambuf_iterator<wchar_t>>  
money_put<char, ostreambuf_iterator<char>>  
money_put<wchar_t, ostreambuf_iterator<wchar_t>>  
```  
  
 A categoria numeric (LC_NUMERIC) inclui as facetas:  
  
```  
num_get<char, istreambuf_iterator<char>>  
num_get<wchar_t, istreambuf_iterator<wchar_t>>  
num_put<char, ostreambuf_iterator<char>>  
num_put<wchar_t, ostreambuf_iterator<wchar_t>>  
numpunct<char>  
numpunct<wchar_t>  
```  
  
 A categoria time (LC_TIME) inclui as facetas:  
  
```  
time_get<char, istreambuf_iterator<char>>  
time_get<wchar_t, istreambuf_iterator<wchar_t>>  
time_put<char, ostreambuf_iterator<char>>  
time_put<wchar_t, ostreambuf_iterator<wchar_t>>  
```  
  
 A categoria messages (LC_MESSAGES) inclui as facetas:  
  
```  
messages<char>  
messages<wchar_t>  
```  
  
 (A última categoria é exigida pela Posix, mas não pelo C Standard.)  
  
 Algumas dessas facetas predefinidas são usadas por classes iostreams para controlar a conversão bidirecional de valores numéricos das sequências de texto.  
  
 Um objeto de localidade de classe também armazena um nome de localidade como um objeto da classe [cadeia de caracteres](../Topic/%3Cstring%3E%20typedefs.md#string). Usar um nome inválido de localidade para construir uma faceta de localidade ou um objeto de localidade lançará um objeto da classe [runtime_error](../Topic/runtime_error%20Class.md). O nome da localidade armazenado será `"*"` se o objeto de localidade não puder ter certeza de que uma localidade de estilo C corresponde exatamente àquela representada pelo objeto. Caso contrário, você pode estabelecer uma localidade correspondente na biblioteca C padrão, para o objeto de localidade `_Loc`, chamando `setlocale`(LC_ALL `,` `_Loc`. [nome](#locale__name)`().c_str()`).  
  
 Nessa implementação, também é possível chamar a função membro estática:  
  
```  
static locale empty();
```  
  
 para construir um objeto de localidade que não tenha nenhuma faceta. Também é uma localidade transparente; Se as funções de modelo [has_facet](../Topic/%3Clocale%3E%20functions.md#has_facet) e [use_facet](../Topic/%3Clocale%3E%20functions.md#use_facet) não é possível encontrar a faceta solicitada em uma localidade transparente, elas consultarão primeiro a localidade global e, em seguida, se for transparente, a localidade clássica. Desse modo, você pode escrever:  
  
```  
cout.imbue(locale::empty());
```  
  
 Inserções subsequentes em [cout](../Topic/%3Ciostream%3E%20functions.md#cout) mediadas pelo estado atual da localidade global. Você ainda pode escrever:  
  
```  
locale loc(locale::empty(),
    locale::classic(),  
    locale::numeric);

cout.imbue(loc);
```   
  
 As regras de formatação numérica para inserções subsequentes em `cout` permanecem iguais as da localidade C, mesmo que a localidade global forneça regras que se modificam para inserção de valores monetários e de data.  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[localidade](#locale__locale)|Cria uma localidade, ou uma cópia de uma localidade, ou uma cópia da localidade em que uma faceta ou uma categoria foi substituída por uma faceta ou categoria de outra localidade.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[categoria](#locale__category)|Um tipo de inteiro que fornece valores de bitmask para denotar famílias padrão de facetas.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[combinar](#locale__combine)|Insere uma faceta de uma localidade especificada em uma localidade de destino.|  
|[nome](#locale__name)|Retorna o nome da localidade armazenado.|  
  
### <a name="static-functions"></a>Funções estáticas  
  
|||  
|-|-|  
|[clássico](#locale__classic)|A função membro estática retorna um objeto de localidade que representa a localidade C clássica.|  
|[global](#locale__global)|Redefine o local padrão do programa.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operador! =](#locale__operator_neq)|Testa a desigualdade de duas localidades.|  
|[operador)](#locale__operator__)|Compara dois objetos `basic_string`.|  
|[operador = =](#locale__operator_eq_eq)|Testa a igualdade de duas localidades.|  
  
### <a name="classes"></a>Classes  
  
|||  
|-|-|  
|[faceta](#facet_class)|Uma classe que serve como a classe base para todas as facetas de localidade.|  
|[ID](#id_class)|A classe do membro fornece uma identificação exclusiva da faceta usada como um índice para procurar facetas em uma localidade.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \< localidade>  
  
 **Namespace:** std  
  
##  <a name="a-namelocalecategorya-localecategory"></a><a name="locale__category"></a>  Locale:: category  
 Um tipo de inteiro que fornece valores de bitmask para denotar famílias padrão de facetas.  
  
```  
typedef int category;  
static const int collate = LC_COLLATE;  
static const int ctype = LC_CTYPE;  
static const int monetary = LC_MONETARY;  
static const int numeric = LC_NUMERIC;  
static const int time = LC_TIME;  
static const int messages = LC_MESSAGES;  
static const int all = LC_ALL;  
static const int none = 0;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo para uma `int` tipo que pode representar um grupo de elementos distintos de bitmask digite local à localidade de classe ou pode ser usado para representar qualquer uma das categorias de localidade C correspondentes. Os elementos são:  
  
- **COLLATE**, correspondente à categoria C LC_COLLATE  
  
- **CType**, correspondente à categoria C LC_CTYPE  
  
- **monetário**, correspondente à categoria C LC_MONETARY  
  
- **numérico**, correspondente à categoria C LC_NUMERIC  
  
- **tempo**, correspondente à categoria C LC_TIME  
  
- **mensagens**, correspondente à categoria Posix LC_MESSAGES  
  
 Além disso, dois valores úteis são:  
  
- **nenhum**, correspondendo ao nenhuma das categorias de C  
  
- **todos os**, correspondente à união de todas as categorias LC_ALL C  
  
 Você pode representar um grupo de categorias de arbitrário usando `OR` com essas constantes, como em **monetário** &#124; **tempo**.  
  
##  <a name="a-namelocaleclassica-localeclassic"></a><a name="locale__classic"></a>  Locale:: Classic  
 A função membro estática retorna um objeto de localidade que representa a localidade C clássica.  
  
```  
static const locale& classic();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência para a localidade C.  
  
### <a name="remarks"></a>Comentários  
 A localidade C clássica está nos EUA Localidade inglês ASCII dentro da biblioteca C padrão usada implicitamente em programas que não são internacionalizados.  
  
### <a name="example"></a>Exemplo  
  
```  
// locale_classic.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <string>  
#include <locale>  
  
using namespace std;  
  
int main( )   
{  
   locale loc1( "german" );  
   locale loc2 = locale::global( loc1 );  
   cout << "The name of the previous locale is: " << loc2.name( )  
        << "." << endl;  
   cout << "The name of the current locale is: " << loc1.name( )   
        << "." << endl;  
  
   if (loc2 == locale::classic( ) )  
      cout << "The previous locale was classic." << endl;  
   else  
      cout << "The previous locale was not classic." << endl;  
  
   if (loc1 == locale::classic( ) )  
      cout << "The current locale is classic." << endl;  
   else  
      cout << "The current locale is not classic." << endl;  
}  
```  
  
```Output  
The name of the previous locale is: C.  
The name of the current locale is: German_Germany.1252.  
The previous locale was classic.  
The current locale is not classic.  
```  
  
##  <a name="a-namelocalecombinea-localecombine"></a><a name="locale__combine"></a>  Locale:: Combine  
 Insere uma faceta de uma localidade especificada em uma localidade de destino.  
  
```  
template <class Facet>  
locale combine(const locale& _Loc) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Loc`  
 A localidade que contém o aspecto a ser inserido na localidade de destino.  
  
### <a name="return-value"></a>Valor de retorno  
 A função de membro retorna um objeto de localidade que substitui ou adiciona ao **\*isso** a faceta `Facet` listados em `_Loc`.  
  
### <a name="example"></a>Exemplo  
  
```  
// locale_combine.cpp  
// compile with: /EHsc  
#include <locale>  
#include <iostream>  
#include <tchar.h>  
using namespace std;  
  
int main() {  
   locale loc ( "German_germany" );  
   _TCHAR * s1 = _T("Das ist wei\x00dfzz."); // \x00df is the German sharp-s; it comes before z in the German alphabet  
   _TCHAR * s2 = _T("Das ist weizzz.");  
   int result1 = use_facet<collate<_TCHAR> > ( loc ).  
      compare (s1, &s1[_tcslen( s1 )-1 ],  s2, &s2[_tcslen( s2 )-1 ] );  
   cout << isalpha (_T ( '\x00df' ), loc ) << result1 << endl;  
  
   locale loc2 ( "C" );  
   int result2 = use_facet<collate<_TCHAR> > ( loc2 ).  
      compare (s1, &s1[_tcslen( s1 )-1 ],  s2, &s2[_tcslen( s2 )-1 ] );  
   cout << isalpha (_T ( '\x00df' ), loc2 )  << result2 << endl;  
  
   locale loc3 = loc2.combine<collate<_TCHAR> > (loc);  
   int result3 = use_facet<collate<_TCHAR> > ( loc3 ).  
      compare (s1, &s1[_tcslen( s1 )-1 ],  s2, &s2[_tcslen( s2 )-1 ] );  
   cout << isalpha (_T ( '\x00df' ), loc3 ) << result3 << endl;  
}  
```  
  
##  <a name="a-namefacetclassa-facet-class"></a><a name="facet_class"></a>  Classe facet  
 Uma classe que serve como a classe base para todas as facetas de localidade.  
  
Faceta de classe {protegidos: faceta explícita (size_t _Refs = 0); virtual ~ facet(); private: facet(const facet&) / / não definido pelo operador void =(const facet&) / / não definido};  
  
### <a name="remarks"></a>Comentários  
 Observe que você não pode copiar ou atribuir um objeto de faceta de classe. Você pode criar e destruir objetos derivados da classe `locale::facet` mas não os objetos da classe base correta. Normalmente, você pode construir um objeto `_Myfac` derivado de faceta ao construir uma localidade, como em **localeloc**( `locale::classic`(), **novo**`_Myfac`);  
  
 Nesses casos, o construtor para a faceta de classe base deve ter um zero `_Refs` argumento. Quando o objeto não é necessário, ele será excluído. Assim, fornecer uma diferente de zero _ *Refs* argumento somente em casos raros em que você assumir a responsabilidade pelo tempo de vida do objeto.  
  
##  <a name="a-namelocaleglobala-localeglobal"></a><a name="locale__global"></a>  Locale:: global  
 Redefine a localidade padrão para o programa. Isso afeta a localidade global para C e C++.  
  
```  
static locale global(const locale& _Loc);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Loc`  
 A localidade a ser usada como a localidade padrão pelo programa.  
  
### <a name="return-value"></a>Valor de retorno  
 A localidade anterior antes que a localidade padrão foi redefinida.  
  
### <a name="remarks"></a>Comentários  
 Na inicialização do programa, a localidade global é o mesmo que a localidade clássica. O `global()` chamadas de função `setlocale( LC_ALL, loc.name. c_str())` para estabelecer uma localidade correspondente na biblioteca C padrão.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// locale_global.cpp  
// compile by using: /EHsc  
#include <locale>  
#include <iostream>  
#include <tchar.h>  
using namespace std;  
  
int main( )  
{  
   locale loc ( "German_germany" );  
   locale loc1;  
   cout << "The initial locale is: " << loc1.name( ) << endl;  
   locale loc2 = locale::global ( loc );  
   locale loc3;  
   cout << "The current locale is: " << loc3.name( ) << endl;  
   cout << "The previous locale was: " << loc2.name( ) << endl;  
}  
```  
  
```Output  
The initial locale is: C  
The current locale is: German_Germany.1252  
The previous locale was: C  
```  
  
##  <a name="a-nameidclassa-id-class"></a><a name="id_class"></a>  ID de classe  
 A classe do membro fornece uma identificação exclusiva da faceta usada como um índice para procurar facetas em uma localidade.  
  
id da classe {protegidos: ID (); private: id(const id&) / / não definido pelo operador void =(const id&) / / não definido};  
  
### <a name="remarks"></a>Comentários  
 A classe de membro descreve o objeto de membro estático exigido por cada faceta de localidade exclusivo. Observe que você não pode copiar ou atribuir um objeto da classe **id**.  
  
##  <a name="a-namelocalelocalea-localelocale"></a><a name="locale__locale"></a>  Locale:: Locale  
 Cria uma localidade, ou uma cópia de uma localidade, ou uma cópia da localidade em que uma faceta ou uma categoria foi substituída por uma faceta ou categoria de outra localidade.  
  
```  
locale();

explicit locale(
    const char* _Locname,  
    category _Cat = all);

explicit locale(
    const string& _Locname);

locale(
    const locale& _Loc);

locale(
    const locale& _Loc,   
    const locale& _Other,  
    category _Cat);

locale(
    const locale& _Loc,   
    const char* _Locname,  
    category _Cat);

template <class Facet>  
locale(
 const locale& _Loc,   
    const Facet* _Fac);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Locname`  
 Nome de uma localidade.  
  
 `_Loc`  
 Uma localidade que deve ser copiado na construção nova localidade.  
  
 `_Other`  
 Uma localidade da qual selecionar uma categoria.  
  
 `_Cat`  
 A categoria a ser substituído na localidade construída.  
  
 `_Fac`  
 A faceta para ser substituído na localidade construída.  
  
### <a name="remarks"></a>Comentários  
 O primeiro construtor inicializa o objeto de acordo com a localidade global. Os construtores de segundo e terceiro inicializam todas as categorias de localidade para ter um comportamento consistente com o nome da localidade `_Locname`. Copiam os construtores restantes `_Loc`, com as exceções indicadas:  
  
 `locale(const locale& _Loc, const locale& _Other, category _Cat);`  
  
 substitui de `_Other` essas facetas correspondente a uma categoria C para qual C & `_Cat` é diferente de zero.  
  
 `locale(const locale& _Loc, const char* _Locname, category _Cat);`  
  
 `locale(const locale& _Loc, const string& _Locname, category _Cat);`  
  
 substitui de `locale(_Locname, _All)` essas facetas correspondente a uma categoria C para qual C & `_Cat`é diferente de zero.  
  
 `template<class Facet> locale(const locale& _Loc, Facet* _Fac);`  
  
 substitui (ou adiciona) `_Loc` a faceta `_Fac`, se `_Fac` não for um ponteiro nulo.  
  
 Se um nome de localidade `_Locname` é um ponteiro nulo ou inválido caso contrário, a função gera [runtime_error](../Topic/runtime_error%20Class.md).  
  
### <a name="example"></a>Exemplo  
  
```  
// locale_locale.cpp  
// compile with: /EHsc  
#include <locale>  
#include <iostream>  
#include <tchar.h>  
using namespace std;  
  
int main( ) {  
  
   // Second constructor  
   locale loc ( "German_germany" );  
   _TCHAR * s1 = _T("Das ist wei\x00dfzz."); // \x00df is the German sharp-s, it comes before z in the German alphabet  
   _TCHAR * s2 = _T("Das ist weizzz.");  
   int result1 = use_facet<collate<_TCHAR> > ( loc ).  
      compare (s1, &s1[_tcslen( s1 )-1 ],  s2, &s2[_tcslen( s2 )-1 ] );  
   cout << isalpha (_T ( '\x00df' ), loc ) << result1 << endl;  
  
   // The first (default) constructor  
   locale loc2;  
   int result2 = use_facet<collate<_TCHAR> > ( loc2 ).  
      compare (s1, &s1[_tcslen( s1 )-1 ],  s2, &s2[_tcslen( s2 )-1 ] );  
   cout << isalpha (_T ( '\x00df' ), loc2 )  << result2 << endl;  
  
   // Third constructor  
   locale loc3 (loc2,loc, _M_COLLATE );  
   int result3 = use_facet<collate<_TCHAR> > ( loc3 ).  
      compare (s1, &s1[_tcslen( s1 )-1 ],  s2, &s2[_tcslen( s2 )-1 ] );  
   cout << isalpha (_T ( '\x00df' ), loc3 ) << result3 << endl;  
  
   // Fourth constructor  
   locale loc4 (loc2, "German_Germany", _M_COLLATE );  
   int result4 = use_facet<collate<_TCHAR> > ( loc4 ).  
      compare (s1, &s1[_tcslen( s1 )-1 ],  s2, &s2[_tcslen( s2 )-1 ] );  
   cout << isalpha (_T ( '\x00df' ), loc4 ) << result4 << endl;  
}  
```  
  
##  <a name="a-namelocalenamea-localename"></a><a name="locale__name"></a>  Locale:: Name  
 Retorna o nome da localidade armazenado.  
  
```  
string name() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cadeia de caracteres fornecendo o nome da localidade.  
  
### <a name="example"></a>Exemplo  
  
```  
// locale_name.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <string>  
#include <locale>  
  
using namespace std;  
  
int main( )   
{  
   locale loc1( "german" );  
   locale loc2 = locale::global( loc1 );  
   cout << "The name of the previous locale is: "   
        << loc2.name( ) << "." << endl;  
   cout << "The name of the current locale is: "   
        << loc1.name( ) << "." << endl;  
}  
```  
  
```Output  
The name of the previous locale is: C.  
The name of the current locale is: German_Germany.1252.  
```  
  
##  <a name="a-namelocaleoperatorneqa-localeoperator"></a><a name="locale__operator_neq"></a>  Locale:: Operator! =  
 Testa a desigualdade de duas localidades.  
  
```  
bool operator!=(const locale& right) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 ` right`  
 Uma das localidades a ser testado para desigualdade.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor booleano que é **true** se as localidades não são cópias da mesma localidade; **False** se as localidades são cópias da mesma localidade.  
  
### <a name="remarks"></a>Comentários  
 Duas localidades são iguais se eles forem a mesma localidade, caso haja uma cópia do outro, ou se eles tenham nomes idênticos.  
  
### <a name="example"></a>Exemplo  
  
```  
// locale_op_ne.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <string>  
#include <locale>  
  
using namespace std;  
  
int main( )   
{  
   locale loc1( "German_Germany" );  
   locale loc2( "German_Germany" );  
   locale loc3( "English" );  
  
   if ( loc1 != loc2 )  
      cout << "locales loc1 (" << loc1.name( )  
      << ") and\n loc2 (" << loc2.name( ) << ") are not equal." << endl;  
   else  
      cout << "locales loc1 (" << loc1.name( )  
      << ") and\n loc2 (" << loc2.name( ) << ") are equal." << endl;  
  
   if ( loc1 != loc3 )  
      cout << "locales loc1 (" << loc1.name( )  
      << ") and\n loc3 (" << loc3.name( ) << ") are not equal." << endl;  
   else  
      cout << "locales loc1 (" << loc1.name( )  
      << ") and\n loc3 (" << loc3.name( ) << ") are equal." << endl;  
}  
```  
  
```Output  
locales loc1 (German_Germany.1252) and  
 loc2 (German_Germany.1252) are equal.  
locales loc1 (German_Germany.1252) and  
 loc3 (English_United States.1252) are not equal.  
```  
  
##  <a name="a-namelocaleoperatora-localeoperator"></a><a name="locale__operator__"></a>  localidade:: Operator)  
 Compara dois objetos `basic_string`.  
  
```  
template <class CharType, class Traits, class Allocator>  
bool operator()(
    const basic_string<CharType, Traits, Allocator>& left,  
    const basic_string<CharType, Traits, Allocator>& right) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 ` left`  
 A cadeia de caracteres à esquerda.  
  
 ` right`  
 A cadeia de caracteres à direita.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a função de membro:  
  
-   -1 se a primeira sequência compara menor que a segunda sequência.  
  
-   + 1 se a segunda sequência compara menor que a primeira sequência.  
  
-   0 se as sequências são equivalentes.  
  
### <a name="remarks"></a>Comentários  
 Efetivamente executa a função de membro:  
  
```  
const collate<CharType>& fac = use_fac<collate<CharType>>(*this);

return (fac.compare(left.begin(), left.end(), right.begin(), right.end()) <0);
```  
  
 Portanto, você pode usar um objeto de localidade como um objeto de função.  
  
### <a name="example"></a>Exemplo  
  
```  
// locale_op_compare.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <string>  
#include <locale>  
  
int main( )   
{  
   using namespace std;  
   wchar_t *sa = L"ztesting";  
   wchar_t *sb = L"\0x00DFtesting";  
   basic_string<wchar_t> a( sa );  
   basic_string<wchar_t> b( sb );  
  
   locale loc( "German_Germany" );  
   cout << loc( a,b ) << endl;  
  
   const collate<wchar_t>& fac = use_facet<collate<wchar_t> >( loc );  
   cout << ( fac.compare( sa, sa + a.length( ),  
       sb, sb + b.length( ) ) < 0) << endl;  
}  
```  
  
```Output  
0  
0  
```  
  
##  <a name="a-namelocaleoperatoreqeqa-localeoperator"></a><a name="locale__operator_eq_eq"></a>  Locale:: Operator = =  
 Testa a igualdade de duas localidades.  
  
```  
bool operator==(const locale& right) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 ` right`  
 Uma das localidades a ser testado para igualdade.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor booleano que é **true** se as localidades são cópias da mesma localidade; **False** se as localidades não são cópias da mesma localidade.  
  
### <a name="remarks"></a>Comentários  
 Duas localidades são iguais se eles forem a mesma localidade, caso haja uma cópia do outro, ou se eles tenham nomes idênticos.  
  
### <a name="example"></a>Exemplo  
  
```  
// locale_op_eq.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <string>  
#include <locale>  
  
using namespace std;  
  
int main( )   
{  
   locale loc1( "German_Germany" );  
   locale loc2( "German_Germany" );  
   locale loc3( "English" );  
  
   if ( loc1 == loc2 )  
      cout << "locales loc1 (" << loc1.name( )  
      << ")\n and loc2 (" << loc2.name( ) << ") are equal."   
      << endl;  
   else  
      cout << "locales loc1 (" << loc1.name( )  
      << ")\n and loc2 (" << loc2.name( ) << ") are not equal."   
      << endl;  
  
   if ( loc1 == loc3 )  
      cout << "locales loc1 (" << loc1.name( )  
      << ")\n and loc3 (" << loc3.name( ) << ") are equal."   
      << endl;  
   else  
      cout << "locales loc1 (" << loc1.name( )  
      << ")\n and loc3 (" << loc3.name( ) << ") are not equal."   
      << endl;  
}  
```  
  
```Output  
locales loc1 (German_Germany.1252)  
 and loc2 (German_Germany.1252) are equal.  
locales loc1 (German_Germany.1252)  
 and loc3 (English_United States.1252) are not equal.  
```  
  
## <a name="see-also"></a>Consulte também  
 [\< localidade>](../standard-library/locale.md)   
 [Páginas de código](../c-runtime-library/code-pages.md)   
 [Nomes de localidades, idiomas e cadeias de caracteres de país/região](../c-runtime-library/locale-names-languages-and-country-region-strings.md)   
 [Segurança de threads na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)

