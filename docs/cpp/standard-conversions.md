---
title: Conversões padrão
ms.date: 11/19/2018
helpviewer_keywords:
- standard conversions, categories of
- L-values [C++]
- conversions, standard
ms.assetid: ce7ac8d3-5c99-4674-8229-0672de05528d
ms.openlocfilehash: aee100bdc7e8ba6dd7d06c6bca9ed39c09cf2d97
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62267266"
---
# <a name="standard-conversions"></a>Conversões padrão

A linguagem C++ define conversões entre seus tipos básicos. Ela também define conversões para o ponteiro, referência e tipos derivados de ponteiro ao membro. Essas conversões são chamadas *conversões padrão*.

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
    >  Os tipos definidos pelo usuário podem especificar suas próprias conversões. Conversão de tipos definidos pelo usuário é abordada [construtores](../cpp/constructors-cpp.md) e [conversões](../cpp/user-defined-type-conversions-cpp.md).

O código a seguir causa conversões (neste exemplo, promoções de integral):

```cpp
long  long_num1, long_num2;
int   int_num;

// int_num promoted to type long prior to assignment.
long_num1 = int_num;

// int_num promoted to type long prior to multiplication.
long_num2 = int_num * long_num2;
```

O resultado de uma conversão é um l-value somente se ela produzir um tipo de referência. Por exemplo, uma conversão definida pelo usuário é declarado como `operator int&()` retorna uma referência e é um l-value. No entanto, uma conversão declarada como `operator int()`retorna um objeto e não é um l-value.

## <a name="integral-promotions"></a>Promoções de integral

Os objetos de um tipo integral podem ser convertidos em outro tipo integral mais amplo (isto é, um tipo que pode representar um conjunto maior de valores). Esse tipo amplo de conversão é chamado de "promoção integral". Com a promoção integral, você pode usar o seguinte em uma expressão sempre que outro tipo integral puder ser usado:

- Objetos, literais e constantes do tipo **char** e **int curto**

- Tipos de enumeração

- **int** bit fields

- Enumeradores

As promoções C++ são "preservadoras de valores". Ou seja, o valor após a promoção tem a garantia de ser o mesmo que o valor anterior da promoção. Em promoções de preservação, objetos de tipos integrais mais curtos (como campos de bits ou objetos do tipo **char**) são promovidos para o tipo **int** se **int** pode representar o completo intervalo do tipo original. Se **int** não pode representar a gama completa de valores, em seguida, o objeto é promovido para o tipo **unsigned int**. Embora essa estratégia seja a mesma usada por ANSI C, as conversões de preservação de valores não preservam o "signedness" do objeto.

As promoções de preservação de valores e as promoções que preservam o signedness normalmente geram os mesmos resultados. Porém, elas poderão gerar resultados diferentes se o objeto promovido for um dos seguintes:

- Um operando do **/**, `%`, `/=`, `%=`, **<**, **\< =**, **>**, ou **>=**

   Esses operadores dependem do sinal para determinar o resultado. Portanto, as promoções de preservação de valores e de sinais geram resultados diferentes quando aplicadas a esses operandos.

- O operando da esquerda **>>** ou **>>=**

   Esses operadores tratam quantidades assinadas e não assinadas de maneiras diferentes ao executar uma operação de alternância. Para quantidades assinadas, alternar uma quantidade para a direita faz com que o bit de sinal seja propagado para posições de bits vagas. Para quantidades não assinadas, as posições de bit vagas são preenchidas com zeros.

- Um argumento para uma função ou um operando sobrecarregado de um operador sobrecarregado que depende de signedness do tipo desse operando para a correspondência do argumento. (Consulte [operadores sobrecarregados](../cpp/operator-overloading.md) para obter mais informações sobre como definir operadores sobrecarregados.)

## <a name="integral-conversions"></a>Conversões de integral

As conversões integrais são executadas entre tipos integrais. Os tipos integrais são **char**, **int**, e **longo** (e o **curto**, **assinado**e **sem sinal** versões desses tipos).

**Assinado em não assinado**

Os objetos de tipos integrais com sinal podem ser convertidos nos tipos sem sinal correspondentes. Quando essas conversões ocorrem, o padrão de bits real não se altera; porém, a interpretação dos dados é alterada. Considere este código:

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

No exemplo anterior, uma **1&gt;signed**, `i`, é definido e inicializado como um número negativo. A expressão `(u = i)` faz com que `i` a ser convertido em um **unsigned short** antes de atribuição para `u`.

**Não assinado em assinado**

Os objetos de tipos integrais sem sinal podem ser convertidos nos tipos com sinal correspondentes. No entanto, essa conversão poderá causar a interpretação errônea dos dados se o valor do objeto sem sinal estiver fora do intervalo representável pelo tipo com sinal, como é demonstrado no seguinte exemplo:

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

No exemplo anterior, `u` é um **unsigned short** objeto integral que deve ser convertido em uma quantidade com sinal para avaliar a expressão `(i = u)`. Porque seu valor não pode ser representado adequadamente em um **1&gt;signed**, os dados são interpretados incorretamente, conforme mostrado.

## <a name="floating-point-conversions"></a>Conversões de ponto flutuante

Um objeto de um tipo flutuante pode ser convertido com segurança em um tipo flutuante mais preciso; ou seja, a conversão não resulta em nenhuma perda de significação. Por exemplo, as conversões de **float** ao **duplo** ou de **double** para **longo duplo** são seguras e o valor é alterado.

Um objeto de um tipo flutuante também poderá ser convertido em um tipo menos preciso, se estiver em um intervalo que possa ser representado por esse tipo. (Consulte [limites de flutuação](../cpp/floating-limits.md) para os intervalos dos tipos flutuantes.) Se o valor original não puder ser representado com precisão, poderá ser convertido no próximo valor representável superior ou inferior. Se tal valor não existir, o resultado será indefinido. Considere o exemplo a seguir:

```cpp
cout << (float)1E300 << endl;
```

O valor máximo representável pelo tipo **float** é 3,402823466e38 — um número muito menor do que 1E300. Portanto, o número é convertido em infinito, e o resultado é "inf".

## <a name="conversions-between-integral-and-floating-point-types"></a>Conversões entre tipos de ponto flutuante e integral

Algumas expressões podem fazer com que os objetos de tipo flutuante sejam convertidos em tipos integrais, ou vice-versa. Quando um objeto do tipo integral é convertido em um tipo flutuante e o valor não pode ser representado exatamente, o resultado será o próximo valor maior ou menor representável.

Quando um objeto de tipo flutuante é convertido em um tipo integral, a parte fracionária é truncada. Nenhum arredondamento ocorre no processo de conversão. Esse truncamento significa que um número como 1,3 é convertido em 1 e-1.3 é convertido como -1.

## <a name="arithmetic-conversions"></a>Conversões aritméticas

Muitos operadores binários (discutidos [expressões com operadores binários](../cpp/expressions-with-binary-operators.md)) provocam conversões de operandos e produzem resultados da mesma maneira. A forma como esses operadores provocam conversões é chamada "conversões aritméticas usuais". As conversões aritméticas de operandos de tipos nativos diferentes são executadas como mostra a tabela a seguir. Os tipos Typedef se comportam de acordo com seus tipos nativos subjacentes.

### <a name="conditions-for-type-conversion"></a>Condições para a conversão de tipos

|Condições atendidas|Conversão|
|--------------------|----------------|
|Qualquer um dos operandos é do tipo **longo duplo**.|Outro operando será convertido ao tipo **longo duplo**.|
|Precede a condição não atendida e qualquer operando for do tipo **duplas**.|Outro operando será convertido ao tipo **duplas**.|
|Anterior condições não atendidas e qualquer operando for do tipo **float**.|Outro operando será convertido ao tipo **float**.|
|As condições anteriores não foram atendidas (nenhum dos operandos é de tipo flutuante).|As promoções de integral são executadas nos operandos, da seguinte forma:<br /><br />– Se qualquer operando for do tipo **unsigned long**, o outro operando será convertido ao tipo **unsigned long**.<br />-Se a condição anterior não atendidos e se qualquer operando for do tipo **longo** e o outro do tipo **unsigned int**, ambos os operandos são convertidos para o tipo **unsigned long**.<br />-Se as duas condições anteriores não forem atendidas e se qualquer operando for do tipo **longo**, o outro operando será convertido ao tipo **longo**.<br />-Se as três condições anteriores não forem atendidas e se qualquer operando for do tipo **int sem sinal**, o outro operando será convertido ao tipo **unsigned int**.<br />-Se nenhuma das condições anteriores for atendida, ambos os operandos serão convertidos ao tipo **int**.|

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

A primeira instrução no exemplo acima mostra a multiplicação de dois tipos integrais, `iVal` e `ulVal`. A condição atendida é que nenhum dos operandos é do tipo flutuante e um operando for do tipo **unsigned int**. Portanto, o outro operando, `iVal`, é convertido no tipo **unsigned int**. O resultado é atribuído a `dVal`. A condição atendida é que um operando é do tipo **duplas**; portanto, o **int sem sinal** resultado da multiplicação é convertido para o tipo **double**.

A segunda instrução no exemplo anterior mostra a adição de um **float** e um tipo integral, `fVal` e `ulVal`. O `ulVal` variável é convertida no tipo **float** (terceira condição na tabela). O resultado da adição é convertido no tipo **duplas** (segunda condição na tabela) e atribuídos a `dVal`.

## <a name="pointer-conversions"></a>Conversões de ponteiro

Os ponteiros podem ser convertidos durante a atribuição, a inicialização, a comparação e outras expressões.

### <a name="pointer-to-classes"></a>Ponteiro para classes

Há dois casos nos quais um ponteiro para uma classe pode ser convertido em um ponteiro para uma classe base.

O primeiros é quando a classe base especificada estiver acessível e a conversão for inequívoca. (Consulte [várias Classes Base](../cpp/multiple-base-classes.md) para obter mais informações sobre referências de classe base ambíguas.)

O acesso a uma classe base depende do tipo de herança usado na derivação. Considere a herança lustrada na figura a seguir.

![Gráfico de herança mostrando base&#45;classe de acessibilidade](../cpp/media/vc38xa1.gif "gráfico de herança mostrando base&#45;acessibilidade de classe") <br/>
Gráfico de herança para ilustração de acessibilidade a classe base

A tabela a seguir mostra a acessibilidade da classe base para a situação ilustrada na figura.

### <a name="base-class-accessibility"></a>Acessibilidade da classe base

|Tipo de função|Derivação|Conversão de<br /><br /> B * para um\* Legal?|
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

O segundo caso em que um ponteiro para uma classe pode ser convertido em um ponteiro para uma classe base é quando uma conversão de tipo explícita. (Consulte [operador de conversão de tipo explícito](explicit-type-conversion-operator-parens.md) para obter mais informações sobre conversões de tipo explícitas.)

O resultado dessa conversão é um ponteiro para o "subobjeto", a parte do objeto que é totalmente descrita pela classe base.

O código a seguir define duas classes, `A` e `B`, onde `B` é derivado de `A`. (Para obter mais informações sobre herança, consulte [Classes derivadas de](../cpp/inheritance-cpp.md).) Ele define `bObject`, um objeto do tipo `B`, e dois ponteiros (`pA` e `pB`) que apontam para o objeto.

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

O ponteiro `pA` é do tipo `A *`, o que pode ser interpretado como “ponteiro para um objeto do tipo `A`”. Os membros `bObject` `(`tais como `BComponent` e `BMemberFunc`) são exclusivos ao tipo `B` e, portanto, não estão acessíveis por meio de `pA`. O ponteiro `pA` permite acesso somente às características (funções membro e dados) do objeto que são definidas na classe `A`.

### <a name="pointer-to-function"></a>Ponteiro para função

Um ponteiro para uma função pode ser convertido no tipo `void *`, se tipo `void *` é grande o suficiente para reter esse ponteiro.

### <a name="pointer-to-void"></a>Ponteiro para void

Ponteiros para o tipo **void** podem ser convertidos em ponteiros para qualquer outro tipo, mas apenas com uma conversão de tipo explícito (ao contrário do C). Um ponteiro para qualquer tipo pode ser convertido implicitamente em um ponteiro para o tipo **void**. Um ponteiro para um objeto incompleto de um tipo pode ser convertido em um ponteiro para **void** (implicitamente) e vice-versa (explicitamente). O resultado dessa conversão é igual ao valor do ponteiro original. Um objeto é considerado incompleto se for declarado, mas informações disponíveis o suficiente para determinar seu tamanho ou a classe base.

Um ponteiro para qualquer objeto que não esteja **const** ou **volátil** pode ser convertido implicitamente em um ponteiro de tipo `void *`.

### <a name="const-and-volatile-pointers"></a>ponteiros const e volatile

C++ não fornece uma conversão padrão de um **const** ou **volátil** tipo para um tipo que não seja **const** ou **volátil**. No entanto, qualquer tipo de conversão pode ser especificado usando as conversões de tipos explícitas (inclusive as conversões que não são seguras).

> [!NOTE]
>  Os ponteiros C++ para os membros, exceto ponteiros para os membros estáticos, são diferentes dos ponteiros normais e não têm as mesmas conversões padrão. Os ponteiros para os membros estáticos são ponteiros normais e têm as mesmas conversões que ponteiros normais.

### <a name="null-pointer-conversions"></a>conversões de ponteiro nulo

Uma expressão de constante integral que é avaliada como zero, ou tal expressão convertida (estilo "cast") em um tipo ponteiro, é convertida em um ponteiro chamado "ponteiro nulo". Esse ponteiro garante a comparação de irregular a um ponteiro para qualquer objeto ou função válidos (exceto os ponteiros para objetos baseados, que podem ter o mesmo deslocamento e ainda o apontar para objetos diferentes).

No C++ 11 a [nullptr](../cpp/nullptr.md) tipo deve ser preferencial para o ponteiro nulo de estilo C.

### <a name="pointer-expression-conversions"></a>Conversões de expressão de ponteiro

Qualquer expressão com um tipo de matriz pode ser convertida em um ponteiro do mesmo tipo. O resultado da conversão é um ponteiro para o primeiro elemento da matriz. O exemplo a seguir demonstra essa conversão:

```cpp
char szPath[_MAX_PATH]; // Array of type char.
char *pszPath = szPath; // Equals &szPath[0].
```

Uma expressão que resulta em uma função que retorna um tipo específico é convertido em um ponteiro para uma função que retorna esse tipo, exceto quando:

- A expressão é usada como um operando para o operador address-of (**&**).

- A expressão é usada como um operando para o operador function-call.

## <a name="reference-conversions"></a>Conversões de referência

Uma referência a uma classe pode ser convertida em uma referência a uma classe base nos seguintes casos:

- A classe base especificada é acessível.

- A conversão é inequívoca. (Consulte [várias Classes Base](../cpp/multiple-base-classes.md) para obter mais informações sobre referências de classe base ambíguas.)

O resultado da conversão é um ponteiro para o subobjeto que representa a classe base.

## <a name="pointer-to-member"></a>Ponteiro para membro

Os ponteiros para membros de classe podem ser convertidos durante a atribuição, a inicialização, a comparação e outras expressões. Esta seção descreve as seguintes conversões de ponteiros para membros:

## <a name="pointer-to-base-class-member"></a>Ponteiro para membro de classe base

Um ponteiro para um membro de uma classe base pode ser convertido em um ponteiro para um membro de uma classe derivada dela, quando as seguintes condições são atendidas:

- A conversão inversa, de ponteiro para classe derivada em ponteiro para classe base, é acessível.

- Não há herança virtual entre a classe base e a classe derivada.

Quando o operando esquerdo é um ponteiro para um membro, o operando direito deve ser do tipo ponteiro para membro ou ser uma expressão de constante que é avaliada como 0. Essa atribuição só é válida nos seguintes casos:

- O operando direito é um ponteiro para um membro da mesma classe que o operando esquerdo.

- O operando esquerdo é um ponteiro para um membro de uma classe derivada, de forma pública e sem ambiguidade, da classe do operando direito.

## <a name="integral-constant-conversions"></a>Conversões de constante integrais

Uma expressão de constante integral que é avaliada como zero é convertida em um ponteiro chamado "ponteiro nulo". Esse ponteiro garante a comparação de irregular a um ponteiro para qualquer objeto ou função válidos (exceto os ponteiros para objetos baseados, que podem ter o mesmo deslocamento e ainda o apontar para objetos diferentes).

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

[Referência da linguagem C++](../cpp/cpp-language-reference.md)