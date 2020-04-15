---
title: Sobrecarga de função
ms.date: 03/27/2019
helpviewer_keywords:
- function overloading [C++], about function overloading
- function overloading
- declaring functions [C++], overloading
ms.assetid: 3c9884cb-1d5e-42e8-9a49-6f46141f929e
ms.openlocfilehash: a59c0e27a4500cb20ef42e9a55b4eb0004e07f65
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368917"
---
# <a name="function-overloading"></a>Sobrecarga de função

O C++ permite a especificação de mais de uma função do mesmo nome no mesmo escopo. Essas funções são chamadas de funções *sobrecarregadas.* Funções sobrecarregadas permitem que você forneça semântica diferente para uma função, dependendo dos tipos e número de argumentos.

Por exemplo, `print` uma função `std::string` que leva um argumento pode executar tarefas muito diferentes daquela que leva um argumento de tipo **duplo**. A sobrecarga salva você de ter `print_string` que `print_double`usar nomes como ou . No momento da compilação, o compilador escolhe qual sobrecarga usar com base no tipo de argumentos passados pelo chamador.  Se você `print(42.0)`ligar, `void print(double d)` então a função será invocada. Se você `print("hello world")`ligar, `void print(std::string)` então a sobrecarga será invocada.

Você pode sobrecarregar as funções dos membros e as funções não-membros. A tabela a seguir mostra quais partes de uma declaração de função C++ usa para diferenciar entre grupos de funções com o mesmo nome no mesmo escopo.

### <a name="overloading-considerations"></a>Considerações de sobrecarga

|Elemento de declaração de função|Usado para sobrecarga?|
|----------------------------------|---------------------------|
|Tipo de retorno de função|Não|
|Número de argumentos|Sim|
|Tipo de argumentos|Sim|
|Presença ou ausência de reticências|Sim|
|Uso de nomes **de tipo**|Não|
|Limites de matriz não especificados|Não|
|**const** ou **volátil**|Sim, quando aplicado a toda a função|
|[Qualificadores de ref](#ref-qualifiers)|Sim|

## <a name="example"></a>Exemplo

O exemplo a seguir ilustra como a sobrecarga pode ser usada.

```cpp
// function_overloading.cpp
// compile with: /EHsc
#include <iostream>
#include <math.h>
#include <string>

// Prototype three print functions.
int print(std::string s);             // Print a string.
int print(double dvalue);            // Print a double.
int print(double dvalue, int prec);  // Print a double with a
                                     //  given precision.
using namespace std;
int main(int argc, char *argv[])
{
    const double d = 893094.2987;
    if (argc < 2)
    {
        // These calls to print invoke print( char *s ).
        print("This program requires one argument.");
        print("The argument specifies the number of");
        print("digits precision for the second number");
        print("printed.");
        exit(0);
    }

    // Invoke print( double dvalue ).
    print(d);

    // Invoke print( double dvalue, int prec ).
    print(d, atoi(argv[1]));
}

// Print a string.
int print(string s)
{
    cout << s << endl;
    return cout.good();
}

// Print a double in default precision.
int print(double dvalue)
{
    cout << dvalue << endl;
    return cout.good();
}

//  Print a double in specified precision.
//  Positive numbers for precision indicate how many digits
//  precision after the decimal point to show. Negative
//  numbers for precision indicate where to round the number
//  to the left of the decimal point.
int print(double dvalue, int prec)
{
    // Use table-lookup for rounding/truncation.
    static const double rgPow10[] = {
        10E-7, 10E-6, 10E-5, 10E-4, 10E-3, 10E-2, 10E-1,
        10E0, 10E1,  10E2,  10E3,  10E4, 10E5,  10E6 };
    const int iPowZero = 6;

    // If precision out of range, just print the number.
    if (prec < -6 || prec > 7)
    {
        return print(dvalue);
    }
    // Scale, truncate, then rescale.
    dvalue = floor(dvalue / rgPow10[iPowZero - prec]) *
        rgPow10[iPowZero - prec];
    cout << dvalue << endl;
    return cout.good();
}
```

O código anterior mostra a sobrecarga da função `print` no escopo do arquivo.

O argumento padrão não é considerado parte do tipo de função. Portanto, não é usado na seleção de funções sobrecarregadas. Duas funções que diferem apenas nos argumentos padrão são consideradas várias definições em vez de funções sobrecarregadas.

Argumentos padrão não podem ser fornecidos para operadores sobrecarregados.

## <a name="argument-matching"></a>Correspondência de argumento

As funções sobrecarregadas são selecionadas para corresponder melhor declarações de função no escopo atual aos argumentos fornecidos na chamada de função. Se uma função apropriada for localizada, essa função é chamada. "Adequado" neste contexto significa:

- Uma correspondência exata foi encontrada.

- Uma conversão trivial foi executada.

- Uma promoção integral foi executada.

- Uma conversão padrão para o tipo de argumento desejado existe.

- Uma conversão definida pelo usuário (operador ou construtor de conversão) para o tipo de argumento desejado existe.

- Argumentos representados por reticências foram encontrados.

O compilador cria um conjunto de funções candidatas para cada argumento. As funções candidatas são funções em que o argumento real nessa posição pode ser convertido no tipo do argumento formal.

Um conjunto de “melhores funções correspondentes” é criado para cada argumento, e a função selecionada é a interseção de todos os conjuntos. Se a interseção contiver mais de uma função, a sobrecarga é ambígua e gera um erro. A função que é selecionada sempre é uma correspondência melhor de que todas as outras funções no grupo para no mínimo um argumento. Se não houver um vencedor claro, a chamada de função gera um erro.

Observe as seguintes declarações (as funções são marcadas `Variant 1`, `Variant 2` e `Variant 3`, para identificação na discussão a seguir):

```cpp
Fraction &Add( Fraction &f, long l );       // Variant 1
Fraction &Add( long l, Fraction &f );       // Variant 2
Fraction &Add( Fraction &f, Fraction &f );  // Variant 3

Fraction F1, F2;
```

Considere o seguinte instrução:

```cpp
F1 = Add( F2, 23 );
```

A instrução anterior compila dois conjuntos:

|Conjunto 1: Funções candidatas que têm o primeiro argumento do tipo fração|Conjunto 2: Funções do candidato cujo segundo argumento pode ser convertido em tipo **int**|
|--------------------------------------------------------------------------|-----------------------------------------------------------------------------------|
|Variant 1|Variante 1 (**int** pode ser convertido em **longo** usando uma conversão padrão)|
|Variante 3||

Funções no Conjunto 2 são funções para as quais há conversões implícitas do tipo parâmetro real para o tipo de parâmetro formal, e entre essas funções há uma função para a qual o "custo" de converter o tipo de parâmetro real para seu tipo de parâmetro formal é o menor.

A interseção desses dois conjuntos é a Variant 1. Um exemplo de uma chamada de função ambígua é:

```cpp
F1 = Add( 3, 6 );
```

A chamada de função anterior compila os seguintes conjuntos:

|Conjunto 1: Funções do candidato que têm primeiro argumento de tipo **int**|Conjunto 2: Funções do candidato que têm segundo argumento de tipo **int**|
|---------------------------------------------------------------------|----------------------------------------------------------------------|
|Variante 2 (**int** pode ser convertido em **longo** usando uma conversão padrão)|Variante 1 (**int** pode ser convertido em **longo** usando uma conversão padrão)|

Como a intersecção desses dois conjuntos está vazia, o compilador gera uma mensagem de erro.

Para correspondência de argumentos, uma função com *argumentos* padrão n é tratada como *n*+1 funções separadas, cada uma com um número diferente de argumentos.

As reticências (...) atuam como um curinga; elas correspondem a qualquer argumento real. Pode levar a muitos conjuntos ambíguos, se você não projetar seus conjuntos de funções sobrecarregados com extremo cuidado.

> [!NOTE]
> A ambiguidade das funções sobrecarregadas não pode ser determinada até que uma chamada de função seja encontrada. Nesse ponto, os conjuntos são compilados para cada argumento na chamada de função, e você pode determinar se há uma sobrecarga inequívoca. Isso significa que as ambiguidades podem permanecer em seu código até que sejam evocadas por uma chamada de função específica.

## <a name="argument-type-differences"></a>Diferenças de tipo de argumento

As funções sobrecarregadas diferenciam-se entre os tipos de argumento que têm inicializadores diferentes. Portanto, um argumento de um determinado tipo e uma referência a esse tipo são considerados iguais para fins de sobrecarga. Eles são considerados iguais porque têm os mesmos inicializadores. Por exemplo, `max( double, double )` é considerado o mesmo que `max( double &, double & )`. Declarar essas duas funções causa um erro.

Pela mesma razão, os argumentos de função de um tipo modificado por **const** ou **volátil** não são tratados de forma diferente do tipo base para fins de sobrecarga.

No entanto, o mecanismo de sobrecarga de função pode distinguir entre referências que são qualificadas por **const** e **volátil** e referências ao tipo base. Ele torna possível o código como o seguinte:

```cpp
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

```Output
Over default constructor
Over&
Over default constructor
const Over&
Over default constructor
volatile Over&
```

Ponteiros para **objetos const** e **voláteis** também são considerados diferentes de ponteiros para o tipo base para fins de sobrecarga.

## <a name="argument-matching-and-conversions"></a>Correspondência de argumentos e conversões

Quando o compilador tenta corresponder argumentos reais com os argumentos em declarações de função, ele pode fornecer conversões padrão ou definidas pelo usuário para obter o tipo correto se nenhuma correspondência exata for encontrada. A aplicação de conversões está sujeita a estas regras:

- As sequências de conversões que contêm mais de uma conversão definida pelo usuário não são consideradas.

- As sequências de conversões que podem ser encurtadas removendo as conversões intermediárias não são consideradas.

A sequência de conversões resultante, se houver, será considerada a melhor sequência de correspondência. Existem várias maneiras de converter um objeto de tipo **int** para digitar **long não assinado** usando conversões padrão (descritas em [Conversões Padrão](../cpp/standard-conversions.md)):

- Converta de **int** para **longo** e, em seguida, de **longo** para **longo não assinado**.

- Converta de **int** para **long não assinado**.

A primeira sequência, embora atinja o objetivo desejado, não é a melhor sequência de correspondência - existe uma sequência mais curta.

A tabela a seguir mostra um grupo de conversões, as conversões triviais chamadas, que têm um efeito limitado na determinação de qual sequência é a melhor correspondência. As instâncias em que as conversões triviais afetam a escolha de sequência são abordadas na lista após a tabela.

### <a name="trivial-conversions"></a>Conversões triviais

|Converter do tipo|Converter no tipo|
|-----------------------|---------------------|
|*nome de tipo*|*nome de tipo***&**|
|*nome de tipo***&**|*nome de tipo*|
|*nome de tipo* **[ ]**|*nome de tipo*__\*__|
|*nome de tipo* **(lista** *de argumentos)* **)**|**(nome** __\*__ de **digite) (lista** *de argumentos)* **)** *type-name*|
|*nome de tipo*|**const** *tipo-nome*|
|*nome de tipo*|**nome** *de tipo* volátil|
|*nome de tipo*__\*__|**const** *tipo-nome*__\*__|
|*nome de tipo*__\*__|**nome** *de tipo* volátil__\*__|

A sequência em que as conversões são executadas é a seguinte:

1. Correspondência exata. Uma correspondência exata entre os tipos com que a função é chamada e os tipos declarados no protótipo da função sempre é a melhor correspondência. As sequências de conversões triviais são classificadas como correspondências exatas. No entanto, sequências que não fazem nenhuma dessas conversões são consideradas melhores do que sequências que se convertem:

   - Do ponteiro, do ponteiro`type` <strong>\*</strong> ao **const** (para **const).** `type` <strong>\*</strong>

   - Do ponteiro, do ponteiro`type` <strong>\*</strong> para **volátil** (para **volátil).** `type` <strong>\*</strong>

   - Da referência, à referência`type` **&** ao **const** (ao **const** `type` **&**).

   - Da referência à **volatile** referência`type` **&** ao volátil (a **volátil).** `type` **&**

1. Correspondência usando promoções. Qualquer seqüência não classificada como uma correspondência exata que contenha apenas promoções integrais, conversões de **flutuação** para **dupla**, e conversões triviais são classificadas como uma correspondência usando promoções. Embora não seja tão boa quanto a correspondência exata, a correspondência usando promoções é melhor do que a correspondência usando conversões padrão.

1. Correspondência usando conversões padrão. Qualquer sequência não classificada como correspondência exata ou correspondência usando promoções que contém somente conversões padrão e conversões triviais é classificada como correspondência usando conversões padrão. Nessa categoria, as seguintes regras são aplicadas:

   - A conversão de um ponteiro para uma classe derivada, para um ponteiro para `void *` `const void *`uma classe de base direta ou indireta é preferível a converter para ou .

   - A conversão de um ponteiro em uma classe derivada, em um ponteiro em uma classe base gera uma correspondência melhor quanto mais próxima a classe base estiver de uma classe base direta. Suponhamos que a hierarquia de classes seja a ilustrada na figura a seguir.

![Gráfico de conversões preferidas](../cpp/media/vc391t1.gif "Gráfico de conversões preferidas") <br/>
Gráfico mostrando conversões preferidas

A conversão do tipo `D*` no tipo `C*` é preferível à conversão do tipo `D*` no tipo `B*`. Da mesma forma, a conversão do tipo `D*` no tipo `B*` é preferível à conversão do tipo `D*` no tipo `A*`.

Essa mesma regra se aplica para referenciar conversões. A conversão do tipo `D&` no tipo `C&` é preferível à conversão do tipo `D&` no tipo `B&`.

Essa mesma regra se aplica às conversões de ponteiro em membro. A conversão do tipo `T D::*` no tipo `T C::*` é preferível à conversão do tipo `T D::*` no tipo `T B::*`, e assim por diante (onde `T` é o tipo do membro).

A regra anterior só se aplica ao longo de um caminho específico de derivação. Considere o gráfico mostrado na figura a seguir.

![Herança&#45;múltipla que mostra conversões preferenciais](../cpp/media/vc391t2.gif "Herança&#45;múltipla que mostra conversões preferenciais") <br/>
Gráfico de herança múltipla que mostra conversões preferidas

A conversão do tipo `C*` no tipo `B*` é preferível à conversão do tipo `C*` no tipo `A*`. A razão é que eles estão no mesmo caminho, e `B*` é mais próximo. No entanto, `C*` a `D*` conversão de tipo para `A*`tipo não é preferível à conversão para tipo; não há preferência porque as conversões seguem caminhos diferentes.

1. Correspondência com conversões definidas pelo usuário. Esta seqüência não pode ser classificada como uma correspondência exata, uma partida usando promoções ou uma correspondência usando conversões padrão. A sequência deve conter apenas conversões definidas pelo usuário, conversões padrão ou conversões triviais para ser classificada como correspondência com conversões definidas pelo usuário. Uma correspondência com conversões definidas pelo usuário é considerada uma correspondência melhor do que uma correspondência com um sinal de reticências, mas tão boa quanto uma correspondência com conversões padrão.

1. Correspondência com um sinal de reticências. Qualquer sequência que corresponda a reticências na declaração é classificada como correspondência com um sinal de reticências. É considerado o jogo mais fraco.

As conversões definidas pelo usuário são aplicadas quando não há promoção ou conversão. Essas conversões são selecionadas com base no tipo do argumento que está sendo correspondido. Considere o código a seguir:

```cpp
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

As conversões definidas pelo `UDC` usuário disponíveis para classe são do tipo **int** e tipo **longo**. Portanto, o compilador considera conversões para o tipo do objeto que está sendo correspondido: `UDC`. Uma conversão para **int** existe, e ela é selecionada.

Durante o processo de correspondência de argumentos, as conversões padrão podem ser aplicadas ao argumento e ao resultado de uma conversão definida pelo usuário. Portanto, o código a seguir funciona:

```cpp
void LogToFile( long l );
...
UDC udc;
LogToFile( udc );
```

No exemplo anterior, a conversão definida pelo usuário, o `udc` operador **longo,** é invocada para converter para digitar **comprimento**. Se nenhuma conversão definida pelo usuário para o **tipo tivesse** sido definida, `UDC` a conversão teria procedido da seguinte forma: O tipo teria sido convertido para digitar **int** usando a conversão definida pelo usuário. Em seguida, a conversão padrão de tipo **int** para **tipo longo** teria sido aplicada para coincidir com o argumento na declaração.

Se quaisquer conversões definidas pelo usuário forem necessárias para corresponder a um argumento, as conversões padrão não serão usadas ao avaliar a melhor correspondência. Mesmo que mais de uma função de candidato exija uma conversão definida pelo usuário, as funções são consideradas iguais. Por exemplo:

```cpp
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

Ambas as `Func` versões requerem uma conversão definida pelo usuário para converter o tipo **int** para o argumento do tipo de classe. As conversões possíveis são:

- Converter de tipo **int** para tipo `UDC1` (uma conversão definida pelo usuário).

- Converter de **tipo int** para tipo **longo;** em seguida, `UDC2` converter para tipo (uma conversão de duas etapas).

Embora a segunda exija tanto uma conversão padrão quanto a conversão definida pelo usuário, as duas conversões ainda são consideradas iguais.

> [!NOTE]
> As conversões definidas pelo usuário são consideradas conversão por construção ou conversão por inicialização (função de conversão). Ambos os métodos são considerados iguais ao considerar a melhor correspondência.

## <a name="argument-matching-and-the-this-pointer"></a>Correspondência de argumentos e o ponteiro deste

As funções dos membros da classe são tratadas de forma diferente, dependendo se são declaradas como **estáticas**. Como as funções não estáticas têm um argumento implícito que fornece **este** ponteiro, as funções não estáticas são consideradas com um argumento a mais do que funções estáticas; caso contrário, eles são declarados de forma idêntica.

Essas funções de membro não estático exigem que o implícito **deste** ponteiro corresponda ao tipo de objeto através do qual a função está sendo chamada, ou, para operadores sobrecarregados, eles exigem que o primeiro argumento corresponda ao objeto no qual o operador está sendo aplicado. (Para obter mais informações sobre operadores sobrecarregados, consulte [Operadores sobrecarregados](../cpp/operator-overloading.md).)

Ao contrário de outros argumentos em funções sobrecarregadas, nenhum objeto temporário é introduzido e nenhuma conversão é tentada ao tentar corresponder ao argumento **deste** ponteiro.

Quando `->` o operador de seleção de membros `class_name`é usado para acessar `class_name * const`uma função membro de classe, o argumento **deste** ponteiro tem um tipo de . Se os membros forem declarados **const** `const class_name * const` ou `volatile class_name * const` **voláteis,** os tipos são e, respectivamente.

O operador de seleção de membro `.` funciona exatamente da mesma maneira, exceto que um operador `&` (address-of) implícito tem um prefixo no nome do objeto. O exemplo a seguir mostra como isso funciona:

```cpp
// Expression encountered in code
obj.name

// How the compiler treats it
(&obj)->name
```

Os operadores de `->*` operadores esquerdos e `.*` (ponteiro para membro) `.` `->` são tratados da mesma forma que os operadores e (seleção de membros) em relação à correspondência de argumentos.

## <a name="ref-qualifiers-on-member-functions"></a><a name="ref-qualifiers"></a>Ref-qualifiers em funções de membro

Os qualificadores de ref tornam possível sobrecarregar uma função de membro com base em se o objeto apontado por **isso** é um valor ou um valor.  Esse recurso pode ser usado para evitar operações de cópia desnecessárias em cenários onde você opta por não fornecer acesso ponteiro aos dados. Por exemplo, `C` suponha que a classe inicialize alguns dados em `get_data()`sua construtora e retorne uma cópia desses dados na função membro . Se um objeto `C` de tipo é um valor que está prestes a ser `get_data() &&` destruído, então o compilador escolherá a sobrecarga, que move os dados em vez de copiá-los.

```cpp
#include <iostream>
#include <vector>

using namespace std;

class C
{

public:
    C() {/*expensive initialization*/}
    vector<unsigned> get_data() &
    {
        cout << "lvalue\n";
        return _data;
    }
    vector<unsigned> get_data() &&
    {
        cout << "rvalue\n";
        return std::move(_data);
    }

private:
    vector<unsigned> _data;
};

int main()
{
    C c;
    auto v = c.get_data(); // get a copy. prints "lvalue".
    auto v2 = C().get_data(); // get the original. prints "rvalue"
    return 0;
}
```

## <a name="restrictions-on-overloading"></a>Restrições à sobrecarga

Várias restrições regem um conjunto de funções sobrecarregadas aceitável:

- Quaisquer duas funções em um conjunto de funções sobrecarregadas devem ter listas de argumentos diferentes.

- Funções sobrecarregadas com listas de argumentos dos mesmos tipos, com base apenas no tipo de retorno, são um erro.

     **Específico da Microsoft**

Você pode sobrecarregar o **operador novo** apenas com base no tipo de retorno — especificamente, com base no modificador de modelo de memória especificado.

**Fim específico da Microsoft**

- As funções dos membros não podem ser sobrecarregadas apenas com base em uma estático e a outra não estático.

- as declarações **de tiponão** definem novos tipos; eles introduzem sinônimos para os tipos existentes. Eles não afetam o mecanismo de sobrecarga. Considere o código a seguir:

    ```cpp
    typedef char * PSTR;

    void Print( char *szToPrint );
    void Print( PSTR szToPrint );
    ```

   As duas funções anteriores têm listas de argumento idênticas. `PSTR`é um sinônimo `char *`de tipo. No escopo do membro, esse código gera um erro.

- Os tipos enumerados são tipos distintos e podem ser usados para distinguir as funções sobrecarregadas.

- Os tipos "matriz de" e "ponteiro para" são considerados idênticos para fins de distinção entre funções sobrecarregadas, mas apenas para matrizes singly dimensionadas. É por isso que essas funções sobrecarregadas se conflitom e geram uma mensagem de erro:

    ```cpp
    void Print( char *szToPrint );
    void Print( char szToPrint[] );
    ```

   Para matrizes dimensionadas multiplamente, a segunda e todas as dimensões seguintes são consideradas parte do tipo. Portanto, elas são usadas na distinção das funções sobrecarregadas:

    ```cpp
    void Print( char szToPrint[] );
    void Print( char szToPrint[][7] );
    void Print( char szToPrint[][9][42] );
    ```

## <a name="overloading-overriding-and-hiding"></a>Sobrecarga, substituição e ocultação

Quaisquer duas declarações de função do mesmo nome no mesmo escopo podem fazer referência à mesma função, ou duas funções discretas sobrecarregadas. Se as listas de argumento de declarações contiverem argumentos de tipos equivalentes (como descrito na seção anterior), as declarações de função se referem à mesma função. Se não, fazem referência a duas funções diferentes que são selecionadas usando a sobrecarga.

O escopo da classe é estritamente observado; portanto, uma função declarada em uma classe base não está no mesmo escopo de uma função declarada em uma classe derivada. Se uma função em uma classe derivada for declarada com o mesmo nome de uma função virtual na classe base, a função de classe derivada *substitui* a função de classe base. Para obter mais informações, consulte [Funções Virtuais](../cpp/virtual-functions.md).

Se a função de classe base não for declarada como 'virtual', diz-se que a função de classe derivada a *oculta.* Tanto a substituição quanto a ocultação são distintas da sobrecarga.

O escopo do bloco é estritamente observado; portanto, uma função declarada no escopo do arquivo não está no mesmo escopo de uma função declarada localmente. Se uma função declarada localmente tiver o mesmo nome de uma função declarada no escopo de arquivo, a função declarada localmente oculta a função do escopo de arquivo ao invés de causar a sobrecarga. Por exemplo:

```cpp
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

O código anterior mostra duas definições da função `func`. A definição que leva `char *` um argumento `main` de tipo é local para por causa da **declaração extern.** Portanto, a definição que leva um argumento de tipo **int** está oculta, e a primeira chamada para `func` está errada.

Para funções de membro sobrecarregadas, as versões diferentes da função podem receber privilégios de acesso diferentes. Elas são consideradas como ainda no escopo da classe envolvente e, portanto, são funções sobrecarregadas. Considere o seguinte código, no qual a função de membro `Deposit` é sobrecarregada; uma versão é pública, a outro, privada.

A finalidade deste exemplo é fornecer uma classe `Account` em que uma senha correta é necessária para executar depósitos. É feito usando sobrecarga.

A chamada `Deposit` `Account::Deposit` para dentro chama a função de membro privado. Esta chamada está `Account::Deposit` correta porque é uma função de membro, e tem acesso aos membros privados da classe.

```cpp
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

## <a name="see-also"></a>Confira também

[Funções (C++)](../cpp/functions-cpp.md)
