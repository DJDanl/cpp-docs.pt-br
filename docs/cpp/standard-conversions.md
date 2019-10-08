---
title: Conversões padrão
ms.date: 10/02/2019
helpviewer_keywords:
- standard conversions, categories of
- L-values [C++]
- conversions, standard
ms.assetid: ce7ac8d3-5c99-4674-8229-0672de05528d
ms.openlocfilehash: c51a5ea5aaabb27babb9e4cd355721742088d31e
ms.sourcegitcommit: c51b2c665849479fa995bc3323a22ebe79d9d7ce
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/07/2019
ms.locfileid: "71998905"
---
# <a name="standard-conversions"></a>Conversões padrão

A linguagem C++ define conversões entre seus tipos básicos. Ela também define conversões para o ponteiro, referência e tipos derivados de ponteiro ao membro. Essas conversões são chamadas de *conversões padrão*.

Esta seção aborda as seguintes conversões padrão:

- Promoções de integral

- Conversões de integral

- Conversões flutuantes

- Conversões flutuantes e integrais

- Conversões aritméticas

- Conversões de ponteiro

- Conversões de referência

- Conversões de ponteiro ao membro

  > [!NOTE]
  > Os tipos definidos pelo usuário podem especificar suas próprias conversões. A conversão de tipos definidos pelo usuário é abordada em [construtores](../cpp/constructors-cpp.md) e [conversões](../cpp/user-defined-type-conversions-cpp.md).

O código a seguir causa conversões (neste exemplo, promoções de integral):

```cpp
long  long_num1, long_num2;
int   int_num;

// int_num promoted to type long prior to assignment.
long_num1 = int_num;

// int_num promoted to type long prior to multiplication.
long_num2 = int_num * long_num2;
```

O resultado de uma conversão é um l-value somente se ela produzir um tipo de referência. Por exemplo, uma conversão definida pelo usuário declarada como `operator int&()` retorna uma referência e é um l-Value. No entanto, uma conversão declarada como `operator int()` retorna um objeto e não é um l-Value.

## <a name="integral-promotions"></a>Promoções de integral

Objetos de um tipo integral podem ser convertidos em outro tipo integral mais amplo, ou seja, um tipo que pode representar um conjunto maior de valores. Esse tipo de ampliação de conversão é chamado de *promoção integral*. Com a promoção integral, você pode usar os seguintes tipos em uma expressão onde quer que outro tipo integral possa ser usado:

- Objetos, literais e constantes do tipo **Char** e **int curta**

- Tipos de enumeração

- campos de bit **int**

- Enumeradores

C++as promoções são "de preservação de valor", pois o valor após a promoção tem a garantia de ser igual ao valor antes da promoção. Nas promoções de preservação de valor, os objetos de tipos de integral mais curtos (como campos de bits ou objetos do tipo **Char**) são promovidos para o tipo **int** se **int** puder representar o intervalo completo do tipo original. Se **int** não puder representar o intervalo completo de valores, o objeto será promovido para tipo **int não assinado**.  Embora essa estratégia seja a mesma usada pelas conversões padrão C, a preservação de valores não preserva a "assinatura" do objeto.

As promoções de preservação de valores e as promoções que preservam o signedness normalmente geram os mesmos resultados. No entanto, eles podem produzir resultados diferentes se o objeto promovido aparecer como:

- Um operando de `/`, `%`, `/=`, `%=`, `<`, `<=`, `>` ou `>=`

   Esses operadores dependem do sinal para determinar o resultado. A preservação de valor e a preservação de promoções geram resultados diferentes quando aplicadas a esses operandos.

- O operando esquerdo de `>>` ou `>>=`

   Esses operadores tratam quantidades assinadas e não assinados de forma diferente em uma operação de deslocamento. Para quantidades assinadas, uma operação de deslocamento à direita propaga o bit de sinal para as posições de bits vagadas, enquanto as posições de bits vagadas são preenchidas com zero em quantidades não assinadas.

- Um argumento para uma função sobrecarregada ou o operando de um operador sobrecarregado, que depende da assinatura do tipo de operando para correspondência de argumento. Para obter mais informações sobre como definir operadores sobrecarregados, consulte [operadores sobrecarregados](../cpp/operator-overloading.md).

## <a name="integral-conversions"></a>Conversões de integral

*Conversões integrais* são conversões entre tipos integrais. Os tipos integrais **são char**, **Short** (ou **int curto**), **int**, **Long**e **Long Long.** Esses tipos podem ser qualificados com **assinada** **ou não assinado,** e **não assinados** pode ser usado como abreviação para **int não assinado**.

### <a name="signed-to-unsigned"></a>Assinado para não assinado

Os objetos de tipos integrais com sinal podem ser convertidos nos tipos sem sinal correspondentes. Quando essas conversões ocorrem, o padrão de bit real não é alterado. No entanto, a interpretação dos dados é alterada. Considere este código:

```cpp
#include <iostream>

using namespace std;
int main()
{
    short  i = -3;
    unsigned short u;

    cout << (u = i) << "\n";
}
// Output: 65533
```

No exemplo anterior, um **curto assinado**, `i`, é definido e inicializado com um número negativo. A expressão `(u = i)` faz com que `i` sejam convertidos em um **curto não assinado** antes da atribuição para `u`.

### <a name="unsigned-to-signed"></a>Não assinado para assinado

Os objetos de tipos integrais sem sinal podem ser convertidos nos tipos com sinal correspondentes. No entanto, se o valor não assinado estiver fora do intervalo representável do tipo assinado, o resultado não terá o valor correto, conforme demonstrado no exemplo a seguir:

```cpp
#include <iostream>

using namespace std;
int main()
{
short  i;
unsigned short u = 65533;

cout << (i = u) << "\n";
}
//Output: -3
```

No exemplo anterior, `u` é um objeto integral **curto não assinado** que deve ser convertido em uma quantidade assinada para avaliar a expressão `(i = u)`. Como seu valor não pode ser adequadamente representado em um **curto assinado**, os dados são interpretados incorretamente, conforme mostrado.

## <a name="floating-point-conversions"></a>Conversões de ponto flutuante

Um objeto de um tipo flutuante pode ser convertido com segurança em um tipo flutuante mais preciso; ou seja, a conversão não resulta em nenhuma perda de significação. Por exemplo, as conversões de **float** para **Double** ou de **Double** para **Long double** são seguras e o valor não é alterado.

Um objeto de um tipo flutuante também pode ser convertido para um tipo menos preciso, se ele estiver em um intervalo representável por esse tipo. (Consulte [limites flutuantes](../cpp/floating-limits.md) para os intervalos de tipos flutuantes.) Se o valor original não for reapresentável precisamente, ele poderá ser convertido para o próximo valor mais alto ou mais baixo representeble. O resultado será indefinido se nenhum valor desse tipo existir. Considere o exemplo a seguir:

```cpp
cout << (float)1E300 << endl;
```

O valor máximo representável pelo tipo **float** é 3.402823466 E38 – um número muito menor que 1E300. Portanto, o número é convertido em infinito e o resultado é "inf".

## <a name="conversions-between-integral-and-floating-point-types"></a>Conversões entre tipos integral e de ponto flutuante

Algumas expressões podem fazer com que os objetos de tipo flutuante sejam convertidos em tipos integrais, ou vice-versa. Quando um objeto do tipo integral é convertido em um tipo flutuante, e o valor original não é reapresentável exatamente, o resultado é o próximo valor mais alto ou mais baixo representeble.

Quando um objeto de tipo flutuante é convertido em um tipo integral, a parte fracionária é *truncada*ou arredondada para zero. Um número como 1,3 é convertido em 1 e-1,3 é convertido em-1. Se o valor truncado for maior do que o maior valor representável, ou menor que o menor valor representável, o resultado será indefinido.

## <a name="arithmetic-conversions"></a>Conversões aritméticas

Muitos operadores binários (discutidos em [expressões com operadores binários](../cpp/expressions-with-binary-operators.md)) causam conversões de operandos e geram resultados da mesma maneira. As conversões desses operadores causam chamadas de *conversões aritméticas usuais*. Conversões aritméticas de operandos que têm tipos nativos diferentes são feitas, conforme mostrado na tabela a seguir. Os tipos Typedef se comportam de acordo com seus tipos nativos subjacentes.

### <a name="conditions-for-type-conversion"></a>Condições para conversão de tipo

|Condições atendidas|Conversão|
|--------------------|----------------|
|Qualquer operando é do tipo **longo Duplo**.|Outro operando é convertido para um tipo **longo de Double**.|
|A condição anterior não foi atendida e o operando é do tipo **Double**.|Outro operando é convertido para o tipo **Double**.|
|As condições anteriores não foram atendidas e o operando é do tipo **float**.|Outro operando é convertido para o tipo **float**.|
|As condições anteriores não foram atendidas (nenhum dos operandos é de tipo flutuante).|Os operandos obtêm promoções integrais da seguinte maneira:<br /><br />-Se qualquer operando for do tipo **sem sinal**, o outro operando será convertido para o tipo **sem sinal**.<br />-Se a condição anterior não for atendida e se um dos operandos for do tipo **Long** e o outro do tipo **int sem sinal**, ambos os operandos serão convertidos para o tipo **não assinado longo**.<br />-Se as duas condições anteriores não forem atendidas e se um dos operandos for do tipo **Long**, o outro operando será convertido para o tipo **Long**.<br />-Se as três condições anteriores não forem atendidas, e se qualquer operando for do tipo **não assinado int**, o outro operando será convertido para tipo **int não assinado**.<br />-Se nenhuma das condições anteriores for atendida, ambos os operandos serão convertidos no tipo **int**.|

O código a seguir ilustra as regras de conversão descritas na tabela:

```cpp
double dVal;
float fVal;
int iVal;
unsigned long ulVal;

int main() {
   // iVal converted to unsigned long
   // result of multiplication converted to double
   dVal = iVal * ulVal;

   // ulVal converted to float
   // result of addition converted to double
   dVal = ulVal + fVal;
}
```

A primeira instrução no exemplo acima mostra a multiplicação de dois tipos integrais, `iVal` e `ulVal`. A condição atendida é que nenhum operando é do tipo flutuante e um operando é do tipo **não assinado int**. Portanto, o outro operando, `iVal`, é convertido para o tipo **int não assinado**. O resultado é então atribuído a `dVal`. A condição atendida aqui é que um operando é do tipo **Double**, portanto, o resultado **int não assinado** da multiplicação é convertido para o tipo **Double**.

A segunda instrução no exemplo anterior mostra a adição de um **float** e um tipo integral: `fVal` e `ulVal`. A variável `ulVal` é convertida no tipo **float** (terceira condição na tabela). O resultado da adição é convertido para o tipo **Double** (segunda condição na tabela) e atribuído a `dVal`.

## <a name="pointer-conversions"></a>Conversões de ponteiro

Os ponteiros podem ser convertidos durante a atribuição, a inicialização, a comparação e outras expressões.

### <a name="pointer-to-classes"></a>Ponteiro para classes

Há dois casos nos quais um ponteiro para uma classe pode ser convertido em um ponteiro para uma classe base.

O primeiros é quando a classe base especificada estiver acessível e a conversão for inequívoca. Para obter mais informações sobre referências de classe base ambíguas, consulte [várias classes base](../cpp/multiple-base-classes.md).

O acesso a uma classe base depende do tipo de herança usado na derivação. Considere a herança lustrada na figura a seguir.

![Grafo de herança mostrando&#45;]o grafo de herança de acessibilidade da classe base(../cpp/media/vc38xa1.gif "mostrando a acessibilidade da classe base&#45;") <br/>
Gráfico de herança para ilustração de acessibilidade a classe base

A tabela a seguir mostra a acessibilidade da classe base para a situação ilustrada na figura.

|Tipo de função|Derivação|Conversão de<br /><br /> B * para um @ no__t-0 legal?|
|----------------------|----------------|-------------------------------------------|
|Função externa (fora do escopo da classe)|Particular|Não|
||Protegido|Não|
||Público|Sim|
|Função membro B (no escopo de B)|Particular|Sim|
||Protegido|Sim|
||Público|Sim|
|Função membro C (no escopo de C)|Particular|Não|
||Protegido|Sim|
||Público|Sim|

O segundo caso em que um ponteiro para uma classe pode ser convertido em um ponteiro para uma classe base é quando uma conversão de tipo explícita. Para obter mais informações sobre conversões de tipo explícitas, consulte [operador de conversão de tipo explícito](explicit-type-conversion-operator-parens.md).

O resultado de tal conversão é um ponteiro para o *subobjeto*, a parte do objeto que é completamente descrito pela classe base.

O código a seguir define duas classes, `A` e `B`, onde `B` é derivado de `A`. (Para obter mais informações sobre herança, consulte [classes derivadas](../cpp/inheritance-cpp.md).) Ele define `bObject`, um objeto do tipo `B`, e dois ponteiros (`pA` e `pB`) que apontam para o objeto.

```cpp
// C2039 expected
class A
{
public:
    int AComponent;
    int AMemberFunc();
};

class B : public A
{
public:
    int BComponent;
    int BMemberFunc();
};
int main()
{
   B bObject;
   A *pA = &bObject;
   B *pB = &bObject;

   pA->AMemberFunc();   // OK in class A
   pB->AMemberFunc();   // OK: inherited from class A
   pA->BMemberFunc();   // Error: not in class A
}
```

O ponteiro `pA` é do tipo `A *`, o que pode ser interpretado como “ponteiro para um objeto do tipo `A`”. Os membros de `bObject` (como `BComponent` e `BMemberFunc`) são exclusivos do tipo `B` e, portanto, são inacessíveis por meio de `pA`. O ponteiro `pA` permite acesso somente às características (funções membro e dados) do objeto que são definidas na classe `A`.

### <a name="pointer-to-function"></a>Ponteiro para função

Um ponteiro para uma função pode ser convertido para o tipo `void *`, se o tipo `void *` for grande o suficiente para manter esse ponteiro.

### <a name="pointer-to-void"></a>Ponteiro para void

Ponteiros para tipo **void** podem ser convertidos em ponteiros para qualquer outro tipo, mas apenas com uma conversão explícita de tipo (ao contrário de C). Um ponteiro para qualquer tipo pode ser convertido implicitamente em um ponteiro para digitar **void**. Um ponteiro para um objeto incompleto de um tipo pode ser convertido em um ponteiro para **void** (implicitamente) e voltar (explicitamente). O resultado dessa conversão é igual ao valor do ponteiro original. Um objeto é considerado incompleto se for declarado, mas não há informações suficientes disponíveis para determinar seu tamanho ou classe base.

Um ponteiro para qualquer objeto que não seja **const** ou **volátil** pode ser convertido implicitamente em um ponteiro do tipo `void *`.

### <a name="const-and-volatile-pointers"></a>Ponteiros const e volatile

C++não fornece uma conversão padrão de um tipo **const** ou **volátil** para um tipo que não é **const** ou **volátil**. No entanto, qualquer tipo de conversão pode ser especificado usando as conversões de tipos explícitas (inclusive as conversões que não são seguras).

> [!NOTE]
> C++ponteiros para membros, exceto ponteiros para membros estáticos, são diferentes dos ponteiros normais e não têm as mesmas conversões padrão. Os ponteiros para os membros estáticos são ponteiros normais e têm as mesmas conversões que ponteiros normais.

### <a name="null-pointer-conversions"></a>conversões de ponteiro NULL

Uma expressão constante integral que é avaliada como zero, ou tal conversão de expressão em um tipo de ponteiro, é convertida em um ponteiro chamado de *ponteiro NULL*. Esse ponteiro sempre compara desigual a um ponteiro para qualquer objeto ou função válida. Uma exceção é ponteiros para objetos baseados, que podem ter o mesmo deslocamento e ainda apontar para objetos diferentes.

No C++ 11, o tipo [nullptr](../cpp/nullptr.md) deve ser preferível ao ponteiro NULL de estilo C.

### <a name="pointer-expression-conversions"></a>Conversões de expressão de ponteiro

Qualquer expressão com um tipo de matriz pode ser convertida em um ponteiro do mesmo tipo. O resultado da conversão é um ponteiro para o primeiro elemento da matriz. O exemplo a seguir demonstra essa conversão:

```cpp
char szPath[_MAX_PATH]; // Array of type char.
char *pszPath = szPath; // Equals &szPath[0].
```

Uma expressão que resulta em uma função que retorna um tipo específico é convertido em um ponteiro para uma função que retorna esse tipo, exceto quando:

- A expressão é usada como um operando para o operador address-of ( **&** ).

- A expressão é usada como um operando para o operador function-call.

## <a name="reference-conversions"></a>Conversões de referência

Uma referência a uma classe pode ser convertida em uma referência a uma classe base nesses casos:

- A classe base especificada está acessível.

- A conversão é inequívoca. (Para obter mais informações sobre referências de classe base ambíguas, consulte [várias classes base](../cpp/multiple-base-classes.md).)

O resultado da conversão é um ponteiro para o subobjeto que representa a classe base.

## <a name="pointer-to-member"></a>Ponteiro para membro

Os ponteiros para membros de classe podem ser convertidos durante a atribuição, a inicialização, a comparação e outras expressões. Esta seção descreve as seguintes conversões de ponteiros para membros:

### <a name="pointer-to-base-class-member"></a>Ponteiro para membro da classe base

Um ponteiro para um membro de uma classe base pode ser convertido em um ponteiro para um membro de uma classe derivada dela, quando as seguintes condições são atendidas:

- A conversão inversa, de ponteiro para classe derivada em ponteiro para classe base, é acessível.

- Não há herança virtual entre a classe base e a classe derivada.

Quando o operando esquerdo é um ponteiro para um membro, o operando direito deve ser do tipo ponteiro para membro ou ser uma expressão de constante que é avaliada como 0. Essa atribuição só é válida nos seguintes casos:

- O operando direito é um ponteiro para um membro da mesma classe que o operando esquerdo.

- O operando esquerdo é um ponteiro para um membro de uma classe derivada, de forma pública e sem ambiguidade, da classe do operando direito.

### <a name="null-pointer-to-member-conversions"></a>ponteiro nulo para conversões de membro

Uma expressão constante integral que é avaliada como zero é convertida em um ponteiro nulo. Esse ponteiro sempre compara desigual a um ponteiro para qualquer objeto ou função válida. Uma exceção é ponteiros para objetos baseados, que podem ter o mesmo deslocamento e ainda apontar para objetos diferentes.

O código a seguir ilustra a definição de um ponteiro para o membro `i` na classe `A`. O ponteiro, `pai`, é inicializado como 0, que é o ponteiro nulo.

```cpp
class A
{
public:
int i;
};

int A::*pai = 0;

int main()
{
}
```

## <a name="see-also"></a>Consulte também

[C++referência de linguagem](../cpp/cpp-language-reference.md)