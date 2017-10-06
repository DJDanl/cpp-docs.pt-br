---
title: "Sobrecarga de função | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- function overloading [C++], about function overloading
- function overloading
- declaring functions [C++], overloading
ms.assetid: 3c9884cb-1d5e-42e8-9a49-6f46141f929e
caps.latest.revision: 10
author: mikeblome
ms.author: mblome
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
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 9076fdd48e466d68d5dcecec2c339a98f39a8bb1
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="function-overloading"></a>Sobrecarga de função
O C++ permite a especificação de mais de uma função do mesmo nome no mesmo escopo. Elas são chamadas de funções sobrecarregadas e são descritas em detalhes em Sobrecarga. As funções sobrecarregadas permitem que os programadores forneçam semânticas diferentes para uma função, dependendo dos tipos e do número de argumentos.  
  
 Por exemplo, um **imprimir** função que usa uma cadeia de caracteres (ou **char \* **) argumento executa tarefas muito diferentes daquele que usa um argumento de tipo **duplo** . A sobrecarga permite a nomeação uniforme e impede que os programadores tenham de inventar nomes como `print_sz` ou `print_d`. A tabela a seguir mostra quais partes de uma declaração de função C++ usa para diferenciar entre grupos de funções com o mesmo nome no mesmo escopo.  
  
### <a name="overloading-considerations"></a>Considerações de sobrecarga  
  
|Elemento de declaração de função|Usado para sobrecarga?|  
|----------------------------------|---------------------------|  
|Tipo de retorno de função|Não|  
|Número de argumentos|Sim|  
|Tipo de argumentos|Sim|  
|Presença ou ausência de reticências|Sim|  
|Uso de nomes `typedef`|Não|  
|Limites de matriz não especificados|Não|  
|**Const** ou `volatile` (veja abaixo)|Sim|  
  
 Embora as funções podem ser distinguidas com base em tipo de retorno, eles não podem ser sobrecarregados dessa forma.  `Const`ou `volatile` só são usadas como base para sobrecarga se eles forem usados em uma classe para aplicar ao **isso** ponteiro para a classe, não tipo de retorno da função.  Em outras palavras, sobrecarga se aplica somente se o **const** ou `volatile` palavra-chave segue a lista de argumentos da função na declaração.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir ilustra como a sobrecarga pode ser usada.  
  
```  
// function_overloading.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <math.h>  
  
// Prototype three print functions.  
int print( char *s );                  // Print a string.  
int print( double dvalue );            // Print a double.  
int print( double dvalue, int prec );  // Print a double with a  
//  given precision.  
using namespace std;  
int main( int argc, char *argv[] )  
{  
const double d = 893094.2987;  
if( argc < 2 )  
    {  
// These calls to print invoke print( char *s ).  
print( "This program requires one argument." );  
print( "The argument specifies the number of" );  
print( "digits precision for the second number" );  
print( "printed." );  
exit(0);  
    }  
  
// Invoke print( double dvalue ).  
print( d );  
  
// Invoke print( double dvalue, int prec ).  
print( d, atoi( argv[1] ) );  
}  
  
// Print a string.  
int print( char *s )  
{  
cout << s << endl;  
return cout.good();  
}  
  
// Print a double in default precision.  
int print( double dvalue )  
{  
cout << dvalue << endl;  
return cout.good();  
}  
  
// Print a double in specified precision.  
//  Positive numbers for precision indicate how many digits  
//  precision after the decimal point to show. Negative  
//  numbers for precision indicate where to round the number  
//  to the left of the decimal point.  
int print( double dvalue, int prec )  
{  
// Use table-lookup for rounding/truncation.  
static const double rgPow10[] = {   
10E-7, 10E-6, 10E-5, 10E-4, 10E-3, 10E-2, 10E-1, 10E0,  
10E1,  10E2,  10E3,  10E4, 10E5,  10E6  
    };  
const int iPowZero = 6;  
// If precision out of range, just print the number.  
if( prec < -6 || prec > 7 )  
return print( dvalue );  
// Scale, truncate, then rescale.  
dvalue = floor( dvalue / rgPow10[iPowZero - prec] ) *  
rgPow10[iPowZero - prec];  
cout << dvalue << endl;  
return cout.good();  
}  
```  
  
 O código anterior mostra a sobrecarga da função `print` no escopo do arquivo.  
  
 O argumento padrão não é considerado parte do tipo de função. Consequentemente, não é usado na seleção de funções sobrecarregadas. Duas funções que diferem apenas nos argumentos padrão são consideradas várias definições em vez de funções sobrecarregadas.  
  
 Não é possível fornecer argumentos padrão para operadores sobrecarregados.  
  
  
## <a name="argument-matching"></a>Correspondência de argumento  
 As funções sobrecarregadas são selecionadas para corresponder melhor declarações de função no escopo atual aos argumentos fornecidos na chamada de função. Se uma função apropriada for localizada, essa função é chamada. “Apropriada” neste contexto significa uma das seguintes opções:  
  
-   Uma correspondência exata foi encontrada.  
  
-   Uma conversão trivial foi executada.  
  
-   Uma promoção integral foi executada.  
  
-   Uma conversão padrão para o tipo de argumento desejado existe.  
  
-   Uma conversão definida pelo usuário (operador ou construtor de conversão) para o tipo de argumento desejado existe.  
  
-   Argumentos representados por reticências foram encontrados.  
  
 O compilador cria um conjunto de funções candidatas para cada argumento. As funções candidatas são funções em que o argumento real nessa posição pode ser convertido no tipo do argumento formal.  
  
 Um conjunto de “melhores funções correspondentes” é criado para cada argumento, e a função selecionada é a interseção de todos os conjuntos. Se a interseção contiver mais de uma função, a sobrecarga é ambígua e gera um erro. A função que é selecionada sempre é uma correspondência melhor de que todas as outras funções no grupo para no mínimo um argumento. Se isso não acontecer (se não houver nenhum vencedor claro), a chamada de função gera um erro.  
  
 Observe as seguintes declarações (as funções são marcadas `Variant 1`, `Variant 2` e `Variant 3`, para identificação na discussão a seguir):  
  
```  
Fraction &Add( Fraction &f, long l );       // Variant 1  
Fraction &Add( long l, Fraction &f );       // Variant 2  
Fraction &Add( Fraction &f, Fraction &f );  // Variant 3  
  
Fraction F1, F2;  
```  
  
 Considere o seguinte instrução:  
  
```  
F1 = Add( F2, 23 );  
```  
  
 A instrução anterior compila dois conjuntos:  
  
|Conjunto 1: Funções candidatas que têm o primeiro argumento do tipo fração|Conjunto 2: Funções candidatas cujo segundo argumento pode ser convertido no tipo int|  
|--------------------------------------------------------------------------|-----------------------------------------------------------------------------------|  
|Variant 1|Variant 1 (`int` pode ser convertida em `long` usando uma conversão padrão)|  
|3 Variant||  
  
 As funções no Conjunto 2 são funções para as quais há conversões implícitas a partir do tipo de parâmetro real para o tipo de parâmetro formal, e dentre as quais exista uma função para qual o "custo" de conversão do tipo de parâmetro real para seu tipo de parâmetro formal seja o menor.  
  
 A interseção desses dois conjuntos é a Variant 1. Um exemplo de uma chamada de função ambígua é:  
  
```  
F1 = Add( 3, 6 );  
```  
  
 A chamada de função anterior compila os seguintes conjuntos:  
  
|Conjunto 1: Funções candidatas que têm o primeiro argumento do tipo int|Conjunto 2: Funções candidatas que têm o segundo argumento do tipo int|  
|---------------------------------------------------------------------|----------------------------------------------------------------------|  
|Variant 2 (`int` pode ser convertido em `long` usando uma conversão padrão)|Variant 1 (`int` pode ser convertida em `long` usando uma conversão padrão)|  
  
 Observe que a interseção entre esses dois conjuntos está vazia. Em virtude disso, o compilador gera uma mensagem de erro.  
  
 Para o argumento correspondente a uma função com * n * argumentos padrão é tratado como * n *funções separadas + 1, cada um com um número diferente de argumentos.  
  
 As reticências (...) atuam como um curinga; elas correspondem a qualquer argumento real. Isso pode resultar em muitos conjuntos ambíguos, se você não criar seus conjuntos de função sobrecarregada com extremo cuidado.  
  
> [!NOTE]
>  A ambiguidade das funções sobrecarregadas não pode ser determinada até que uma chamada de função seja encontrada. Nesse ponto, os conjuntos são compilados para cada argumento na chamada de função, e você pode determinar se há uma sobrecarga inequívoca. Isso significa que as ambiguidades podem permanecer em seu código até que sejam evocadas por uma chamada de função específica.  
  
## <a name="argument-type-differences"></a>Diferenças de tipo de argumento  
 As funções sobrecarregadas diferenciam-se entre os tipos de argumento que têm inicializadores diferentes. Portanto, um argumento de um determinado tipo e uma referência a esse tipo são considerados iguais para fins de sobrecarga. Eles são considerados iguais porque têm os mesmos inicializadores. Por exemplo, `max( double, double )` é considerado o mesmo que `max( double &, double & )`. Declarar essas duas funções causa um erro.  
  
 Pela mesma razão, função argumentos de tipo modificado por **const** ou `volatile` não são tratados Diferentemente de tipo base para fins de sobrecarga.  
  
 No entanto, a função de sobrecarga mecanismo pode distinguir entre as referências que são qualificadas por **const** e `volatile` e referências para o tipo base. Isso torna o código como o seguinte possível:  
  
```  
// argument_type_differences.cpp  
// compile with: /EHsc /W3  
// C4521 expected  
#include <iostream>  
  
using namespace std;  
class Over {  
public:  
   Over() { cout << "Over default constructor\n"; }  
   Over( Over &o ) { cout << "Over&\n"; }  
   Over( const Over &co ) { cout << "const Over&\n"; }  
   Over( volatile Over &vo ) { cout << "volatile Over&\n"; }  
};  
  
int main() {  
   Over o1;            // Calls default constructor.  
   Over o2( o1 );      // Calls Over( Over& ).  
   const Over o3;      // Calls default constructor.  
   Over o4( o3 );      // Calls Over( const Over& ).  
   volatile Over o5;   // Calls default constructor.  
   Over o6( o5 );      // Calls Over( volatile Over& ).  
}  
```  
  
### <a name="output"></a>Saída  
  
```  
Over default constructor  
Over&  
Over default constructor  
const Over&  
Over default constructor  
volatile Over&  
```  
  
 Ponteiros para **const** e `volatile` objetos também são considerados diferentes de ponteiros para o tipo base para fins de sobrecarga.  
  
## <a name="argument-matching-and-conversions"></a>Correspondência de argumento e conversões  
 Quando o compilador tenta corresponder argumentos reais com os argumentos em declarações de função, ele pode fornecer conversões padrão ou definidas pelo usuário para obter o tipo correto se nenhuma correspondência exata for encontrada. A aplicação de conversões está sujeita a estas regras:  
  
-   As sequências de conversões que contêm mais de uma conversão definida pelo usuário não são consideradas.  
  
-   As sequências de conversões que podem ser encurtadas removendo as conversões intermediárias não são consideradas.  
  
 A sequência de conversões resultante, se houver, será considerada a melhor sequência de correspondência. Há várias maneiras para converter um objeto do tipo `int` digitar `unsigned long` usando conversões padrão (descrito na [conversões padrão](../cpp/standard-conversions.md)):  
  
-   Converter `int` em `long` e depois `long` em `unsigned long`.  
  
-   Converter `int` em `unsigned long`.  
  
 A primeira sequência, embora atinja a meta desejada, não é a melhor sequência de correspondência — há uma sequência mais curta.  
  
 A tabela a seguir mostra um grupo de conversões, as conversões triviais chamadas, que têm um efeito limitado na determinação de qual sequência é a melhor correspondência. As instâncias em que as conversões triviais afetam a escolha de sequência são abordadas na lista após a tabela.  
  
### <a name="trivial-conversions"></a>Conversões triviais  
  
|Converter do tipo|Converter no tipo|  
|-----------------------|---------------------|  
|*nome do tipo*|*nome do tipo***&**|  
|*nome do tipo***&**|*nome do tipo*|  
|*nome do tipo* **]**|*nome do tipo\**|  
|*nome do tipo* **(** *lista de argumentos* **)**|**(** * \*nome do tipo* **) (** *lista de argumentos* **)**|  
|*nome do tipo*|**Const** *nome de tipo*|  
|*nome do tipo*|`volatile`*nome de tipo*|  
|*nome do tipo\**|**Const** *nome de tipo\**|  
|*nome do tipo\**|`volatile`*nome de tipo\**|  
  
 A sequência em que as conversões são executadas é a seguinte:  
  
1.  Correspondência exata. Uma correspondência exata entre os tipos com que a função é chamada e os tipos declarados no protótipo da função sempre é a melhor correspondência. As sequências de conversões triviais são classificadas como correspondências exatas. No entanto, as sequências que não fazem qualquer uma dessas conversões são consideradas melhor do que as sequências que convertem:  
  
    -   De ponteiro para ponteiro para **const** (`type` ** \* ** para **const** `type` ** \* ** ).  
  
    -   De ponteiro para ponteiro para `volatile` (`type` ** \* ** para `volatile` `type` ** \* **).  
  
    -   De referência, a referência a **const** (`type` ** & ** para **const** `type` ** & **).  
  
    -   De referência, a referência a `volatile` (`type` ** & ** para `volatile` `type` ** & **).  
  
2.  Correspondência usando promoções. Qualquer sequência não classificada como uma correspondência exata que contém somente promoções integrais, conversões de **float** para **duplo**, e conversões triviais é classificado como uma correspondência usando promoções. Embora não seja tão boa quanto a correspondência exata, a correspondência usando promoções é melhor do que a correspondência usando conversões padrão.  
  
3.  Correspondência usando conversões padrão. Qualquer sequência não classificada como correspondência exata ou correspondência usando promoções que contém somente conversões padrão e conversões triviais é classificada como correspondência usando conversões padrão. Nessa categoria, as seguintes regras são aplicadas:  
  
    -   Conversão de um ponteiro para uma classe derivada, para um ponteiro para uma classe base direta ou indireta é preferível à conversão para **void \* ** ou **void const \* **.  
  
    -   A conversão de um ponteiro em uma classe derivada, em um ponteiro em uma classe base gera uma correspondência melhor quanto mais próxima a classe base estiver de uma classe base direta. Suponhamos que a hierarquia de classes seja a ilustrada na figura a seguir.  
  
 ![Preferencial conversões](../cpp/media/vc391t1.gif "vc391T1")  
Gráfico ilustrando as conversões preferidas  
  
 A conversão do tipo `D*` no tipo `C*` é preferível à conversão do tipo `D*` no tipo `B*`. Da mesma forma, a conversão do tipo `D*` no tipo `B*` é preferível à conversão do tipo `D*` no tipo `A*`.  
  
 Essa mesma regra se aplica para referenciar conversões. A conversão do tipo `D&` no tipo `C&` é preferível à conversão do tipo `D&` no tipo `B&`.  
  
 Essa mesma regra se aplica às conversões de ponteiro em membro. A conversão do tipo `T D::*` no tipo `T C::*` é preferível à conversão do tipo `T D::*` no tipo `T B::*`, e assim por diante (onde `T` é o tipo do membro).  
  
 A regra anterior só se aplica ao longo de um caminho específico de derivação. Considere o gráfico mostrado na figura a seguir.  
  
 ![Vários &#45; herança que mostra as conversões preferenciais](../cpp/media/vc391t2.gif "vc391T2")  
Gráfico de herança múltipla que ilustra as conversões preferidas  
  
 A conversão do tipo `C*` no tipo `B*` é preferível à conversão do tipo `C*` no tipo `A*`. A razão é que eles estão no mesmo caminho, e `B*` é mais próximo. No entanto, a conversão do tipo `C*` no tipo `D*` não é preferível à conversão no tipo `A*`; não há preferência porque as conversões seguem caminhos diferentes.  
  
1.  Correspondência com conversões definidas pelo usuário. Essa sequência não pode ser classificada como correspondência exata, correspondência usando promoções ou correspondência usando conversões padrão. A sequência deve conter apenas conversões definidas pelo usuário, conversões padrão ou conversões triviais para ser classificada como correspondência com conversões definidas pelo usuário. Uma correspondência com conversões definidas pelo usuário é considerada uma correspondência melhor do que uma correspondência com um sinal de reticências, mas tão boa quanto uma correspondência com conversões padrão.  
  
2.  Correspondência com um sinal de reticências. Qualquer sequência que corresponda a reticências na declaração é classificada como correspondência com um sinal de reticências. Essa é considerada a correspondência mais fraca.  
  
 As conversões definidas pelo usuário são aplicadas quando não há promoção ou conversão. Essas conversões são selecionadas com base no tipo do argumento que está sendo correspondido. Considere o código a seguir:  
  
```  
// argument_matching1.cpp  
class UDC  
{  
public:  
   operator int()  
   {  
      return 0;  
   }  
   operator long();  
};  
  
void Print( int i )  
{  
};  
  
UDC udc;  
  
int main()  
{  
   Print( udc );  
}  
```  
  
 As conversões definidas pelo usuário disponíveis para a classe `UDC` são do tipo `int` e tipo **longo**. Portanto, o compilador considera conversões para o tipo do objeto que está sendo correspondido: `UDC`. Uma conversão em `int` existe e é selecionada.  
  
 Durante o processo de correspondência de argumentos, as conversões padrão podem ser aplicadas ao argumento e ao resultado de uma conversão definida pelo usuário. Portanto, o código a seguir funciona:  
  
```  
void LogToFile( long l );  
...  
UDC udc;  
LogToFile( udc );  
```  
  
 No exemplo anterior, a conversão definida pelo usuário, **operador long**, é chamado para converter `udc` digitar **longo**. Se nenhuma conversão definida pelo usuário para o tipo **longo** tivesse sido definido, a conversão será Avançar da seguinte maneira: tipo `UDC` seria convertido para o tipo `int` usando a conversão definida pelo usuário. Em seguida, o conversão padrão de tipo `int` digitar **longo** teria sido aplicada para coincidir com o argumento na declaração.  
  
 Se uma conversão definida pelo usuário for necessária para corresponder a um argumento, as conversões padrão não serão usadas na avaliação da melhor correspondência. Isso é válido mesmo quando mais de uma função candidata exija uma conversão definida pelo usuário; nesse caso, as funções são consideradas iguais. Por exemplo:  
  
```  
// argument_matching2.cpp  
// C2668 expected  
class UDC1  
{  
public:  
   UDC1( int );  // User-defined conversion from int.  
};  
  
class UDC2  
{  
public:  
   UDC2( long ); // User-defined conversion from long.  
};  
  
void Func( UDC1 );  
void Func( UDC2 );  
  
int main()  
{  
   Func( 1 );  
}  
```  
  
 Ambas as versões de `Func` exigem uma conversão definida pelo usuário para converter o tipo `int` no argumento do tipo de classe. As conversões possíveis são:  
  
-   Converter do tipo `int` no tipo `UDC1` (uma conversão definida pelo usuário).  
  
-   Conversão de tipo de `int` digitar **longo**; em seguida, converter em tipo `UDC2` (uma conversão em duas etapas).  
  
 Mesmo que a segunda exija uma conversão padrão, bem como a conversão definida pelo usuário, as duas conversões ainda são consideradas iguais.  
  
> [!NOTE]
>  As conversões definidas pelo usuário são consideradas conversão por construção ou conversão por inicialização (função de conversão). Ambos os métodos são considerados iguais ao considerar a melhor correspondência.  
  
## <a name="argument-matching-and-the-this-pointer"></a>Correspondência de argumento e este ponteiro  
 As funções de membro de classe são tratadas de modo diferente, dependendo se são declaradas como `static`. Como as funções não estáticas têm um argumento implícito que fornece o ponteiro `this`, as funções não estáticas são consideradas como tendo mais um argumento que as funções estáticas; caso contrário, são declaradas como idênticas.  
  
 Essas funções de membro não estáticas exigem que o ponteiro `this` implícito corresponda ao tipo de objeto por meio do qual a função está sendo chamada, ou, para operadores sobrecarregados, requerem que o primeiro argumento corresponda ao objeto no qual o operador está sendo aplicado. (Para obter mais informações sobre operadores sobrecarregados, consulte [operadores sobrecarregados](../cpp/operator-overloading.md).)  
  
 Ao contrário de outros argumentos em funções sobrecarregadas, nenhum objeto temporário é introduzido e nenhuma conversão é tentada ao tentar corresponder ao argumento do ponteiro `this`.  
  
 Quando o `->` operador de seleção de membro é usado para acessar uma função de membro de classe `class_name`, o `this` tem o tipo de argumento de ponteiro `class_name * const`. Se os membros são declarados como `const` ou `volatile`, os tipos são `const class_name * const` e `volatile class_name * const`, respectivamente.  
  
 O operador de seleção de membro `.` funciona exatamente da mesma maneira, exceto que um operador `&` (address-of) implícito tem um prefixo no nome do objeto. O exemplo a seguir mostra como isso funciona:  
  
```  
// Expression encountered in code  
obj.name  
  
// How the compiler treats it  
(&obj)->name  
```  
  
 O operando esquerdo do `->*` e `.*` operadores (ponteiro para membro) são tratados da mesma forma que o `.` e `->` operadores (seleção de membro) em relação à correspondência de argumento.  
  
## <a name="restrictions"></a>Restrições  
 Várias restrições regem um conjunto de funções sobrecarregadas aceitável:  
  
-   Quaisquer duas funções em um conjunto de funções sobrecarregadas devem ter listas de argumentos diferentes.  
  
-   Funções sobrecarregadas com listas de argumentos dos mesmos tipos, com base apenas no tipo de retorno, são um erro.  
  
     **Seção específica da Microsoft**  
  
 Você pode sobrecarregar **operador novo** exclusivamente de acordo com o tipo de retorno — especificamente, com base no modificador de modelo de memória especificado.  
  
**Fim da seção específica da Microsoft**  
  
-   As funções membro não podem ser sobrecarregadas apenas com base em uma ser estática e a outra não.  
  
-   Declarações `typedef` não definem novos tipos. Elas introduzem sinônimos para tipos existentes. Elas não afetam o mecanismo de sobrecarga. Considere o código a seguir:  
  
    ```  
    typedef char * PSTR;  
  
    void Print( char *szToPrint );  
    void Print( PSTR szToPrint );  
    ```  
  
     As duas funções anteriores têm listas de argumento idênticas. `PSTR`é um sinônimo de tipo **char \* **. No escopo do membro, esse código gera um erro.  
  
-   Os tipos enumerados são tipos distintos e podem ser usados para distinguir as funções sobrecarregadas.  
  
-   Os tipos “matriz de” e “ponteiro para” são considerados idênticos para fins de distinção das funções sobrecarregadas. Isso é verdadeiro apenas para matrizes dimensionadas exclusivamente. Portanto, as funções sobrecarregadas seguintes entram em conflito e geram uma mensagem de erro:  
  
    ```  
    void Print( char *szToPrint );  
    void Print( char szToPrint[] );  
    ```  
  
     Para matrizes dimensionadas multiplamente, a segunda e todas as dimensões seguintes são consideradas parte do tipo. Portanto, elas são usadas na distinção das funções sobrecarregadas:  
  
    ```  
    void Print( char szToPrint[] );  
    void Print( char szToPrint[][7] );  
    void Print( char szToPrint[][9][42] );  
    ```  
  
## <a name="declaration-matching"></a>Correspondência de declaração  
 Quaisquer duas declarações de função do mesmo nome no mesmo escopo podem fazer referência à mesma função, ou duas funções discretas sobrecarregadas. Se as listas de argumento de declarações contiverem argumentos de tipos equivalentes (como descrito na seção anterior), as declarações de função se referem à mesma função. Se não, fazem referência a duas funções diferentes que são selecionadas usando a sobrecarga.  
  
 O escopo da classe é observado estritamente; em virtude disso, uma função declarada em uma classe base não está no mesmo escopo que uma função declarada em uma classe derivada. Se uma função em uma classe derivada for declarada com o mesmo nome de uma função na classe base, a função de classe derivada oculta a função da classe base em vez de causar a sobrecarga.  
  
 O escopo do bloco é observado estritamente; em virtude disso, uma função declarada em um escopo de arquivo não está no mesmo escopo que uma função declarada localmente. Se uma função declarada localmente tiver o mesmo nome de uma função declarada no escopo de arquivo, a função declarada localmente oculta a função do escopo de arquivo ao invés de causar a sobrecarga. Por exemplo:  
  
```  
// declaration_matching1.cpp  
// compile with: /EHsc  
#include <iostream>  
  
using namespace std;  
void func( int i )  
{  
    cout << "Called file-scoped func : " << i << endl;  
}  
  
void func( char *sz )  
{  
   cout << "Called locally declared func : " << sz << endl;  
}  
  
int main()  
{  
   // Declare func local to main.  
   extern void func( char *sz );  
  
   func( 3 );   // C2664 Error. func( int ) is hidden.  
   func( "s" );  
}  
```  
  
 O código anterior mostra duas definições da função `func`. A definição que usa um argumento do tipo `char *` é local para `main` devido à instrução `extern`. Consequentemente, a definição que usa um argumento do tipo `int` é ocultada, e a primeira chamada para `func` está em erro.  
  
 Para funções de membro sobrecarregadas, as versões diferentes da função podem receber privilégios de acesso diferentes. Elas são consideradas como ainda no escopo da classe envolvente e, portanto, são funções sobrecarregadas. Considere o seguinte código, no qual a função de membro `Deposit` é sobrecarregada; uma versão é pública, a outro, privada.  
  
 A finalidade deste exemplo é fornecer uma classe `Account` em que uma senha correta é necessária para executar depósitos. Isso é feito usando sobrecarga.  
  
 Observe que a chamada para `Deposit` em `Account::Deposit` chama a função membro particular. Essa chamada está correta pois `Account::Deposit` é uma função membro e, portanto, tem acesso a membros privados da classe.  
  
```  
// declaration_matching2.cpp  
class Account  
{  
public:  
   Account()  
   {  
   }  
   double Deposit( double dAmount, char *szPassword );  
  
private:  
   double Deposit( double dAmount )  
   {  
      return 0.0;  
   }  
   int Validate( char *szPassword )  
   {  
      return 0;  
   }  
  
};  
  
int main()  
{  
    // Allocate a new object of type Account.  
    Account *pAcct = new Account;  
  
    // Deposit $57.22. Error: calls a private function.  
    // pAcct->Deposit( 57.22 );  
  
    // Deposit $57.22 and supply a password. OK: calls a  
    //  public function.  
    pAcct->Deposit( 52.77, "pswd" );  
}  
  
double Account::Deposit( double dAmount, char *szPassword )  
{  
   if ( Validate( szPassword ) )  
      return Deposit( dAmount );  
   else  
      return 0.0;  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Funções (C++)](../cpp/functions-cpp.md)
