---
title: Funções embutidas (C++)
ms.date: 10/09/2018
f1_keywords:
- __forceinline_cpp
- __inline_cpp
- inline_cpp
- __inline
- _inline
- __forceinline
- _forceinline
helpviewer_keywords:
- inline functions [C++], class members
ms.assetid: 355f120c-2847-4608-ac04-8dda18ffe10c
ms.openlocfilehash: b13007211857d84e4f3b33c80ed6b5beaf6f0bcf
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80178231"
---
# <a name="inline-functions-c"></a>Funções embutidas (C++)

Uma função definida no corpo de uma declaração de classe é uma função embutida.

## <a name="example"></a>Exemplo

Na seguinte declaração de classe, o construtor `Account` é uma função embutida. As funções de membro `GetBalance`, `Deposit`e `Withdraw` não são especificadas como **embutidas** , mas podem ser implementadas como funções embutidas.

```cpp
// Inline_Member_Functions.cpp
class Account
{
public:
    Account(double initial_balance) { balance = initial_balance; }
    double GetBalance();
    double Deposit( double Amount );
    double Withdraw( double Amount );
private:
    double balance;
};

inline double Account::GetBalance()
{
    return balance;
}

inline double Account::Deposit( double Amount )
{
    return ( balance += Amount );
}

inline double Account::Withdraw( double Amount )
{
    return ( balance -= Amount );
}
int main()
{
}
```

> [!NOTE]
>  Na declaração de classe, as funções foram declaradas sem a palavra-chave **embutida** . A palavra-chave **inline** pode ser especificada na declaração de classe; o resultado é o mesmo.

Uma determinada função de membro embutida deve ser declarada da mesma maneira em cada unidade de compilação. Essa restrição faz com que as funções embutidas se comportem como se fossem funções instanciadas. Além disso, deve haver exatamente uma definição de uma função embutida.

Uma função de membro de classe usa como padrão a ligação externa, a menos que uma definição para essa função contenha o especificador **embutido** . O exemplo anterior mostra que essas funções não precisam ser declaradas explicitamente com o especificador **embutido** ; o uso de **inline** na definição da função faz com que ela seja uma função embutida. No entanto, é ilegal redeclarar uma função como **embutida** após uma chamada para essa função.

## <a name="inline-__inline-and-__forceinline"></a>Inline, __inline e \__forceinline

Os especificadores **embutidos** e **__inline** instruem o compilador a inserir uma cópia do corpo da função em cada lugar em que a função é chamada.

A inserção (chamada de expansão embutida ou inlining) só ocorrerá se a análise de custo/benefício do compilador demonstrar que ela será lucrativa. A expansão embutida reduz a sobrecarga da chamada de função sobre os possíveis custos de um código maior.

A palavra-chave **__forceinline** substitui a análise de custo/benefício e conta com o julgamento do programador em vez disso. Tenha cuidado ao usar **__forceinline**. O uso indiscriminado de **__forceinline** pode resultar em um código maior, com apenas ganhos de desempenho marginal ou, em alguns casos, até perdas de desempenho (devido à maior paginação de um executável maior, por exemplo).

O uso das funções embutidas pode fazer com que seu programa seja mais rápido porque ele elimina a sobrecarga associada às chamadas de função. As funções com expansão embutida estão sujeitas a otimizações de código não disponíveis às funções normais.

O compilador trata as opções de expansão embutida e as palavras-chave como sugestões. Não há garantia de que as funções serão embutidas. Você não pode forçar o compilador a embutir uma função específica, mesmo com a palavra-chave **__forceinline** . Ao compilar com **/CLR**, o compilador não embutirá uma função se houver atributos de segurança aplicados à função.

A palavra-chave **inline** está disponível C++apenas no. As palavras-chave **__inline** e **__forceinline** estão disponíveis em C e C++. Para compatibilidade com versões anteriores, **_inline** e **_forceinline** são sinônimos de **__inline**e **__forceinline** , a menos que a opção do compilador [/za \(desabilitar extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) seja especificada.

A palavra-chave **inline** informa ao compilador que a expansão embutida é preferida. No entanto, o compilador pode criar uma instância separada da função (uma instância) e criar vínculos de chamada padrão em vez de inserir o código embutido. Os dois casos em que isso pode acontecer são:

- Funções recursivas.

- Funções às quais são feita referência por meio de um ponteiro em outro lugar na unidade de tradução.

Esses motivos podem interferir na inlinhagem, *como outras podem*, a critério do compilador; Você não deve depender do especificador **embutido** para fazer uma função ser embutida.

Como ocorre com funções normais, não há ordem definida de avaliação dos argumentos para uma função embutida. De fato, ela pode ser diferente da ordem na qual os argumentos são avaliados quando passados usando o protocolo comum de chamada de função.

A opção de otimização do compilador [/OB](../build/reference/ob-inline-function-expansion.md) ajuda a determinar se a expansão da função embutida realmente ocorre.

O [/LTCG](../build/reference/ltcg-link-time-code-generation.md) executa o embutimento entre módulos, independentemente de ter sido solicitado no código-fonte.

### <a name="example-1"></a>Exemplo 1

```cpp
// inline_keyword1.cpp
// compile with: /c
inline int max( int a , int b ) {
   if( a > b )
      return a;
   return b;
}
```

As funções de membro de uma classe podem ser declaradas de forma embutida usando a palavra-chave **embutida** ou colocando a definição de função dentro da definição de classe.

### <a name="example-2"></a>Exemplo 2

```cpp
// inline_keyword2.cpp
// compile with: /EHsc /c
#include <iostream>
using namespace std;

class MyClass {
public:
   void print() { cout << i << ' '; }   // Implicitly inline
private:
   int i;
};
```

**Seção específica da Microsoft**

A palavra-chave **__inline** é equivalente a **embutida**.

Mesmo com **__forceinline**, o compilador não pode embutir código em todas as circunstâncias. O compilador não pode embutir uma função se:

- A função ou o chamador forem compilados com /Ob0 (a opção padrão para compilações de depuração).

- A função e o chamador usam tipos diferentes de manipulação de exceções (manipulação de exceções do C++ em uma, manipulação de exceções estruturada no outro).

- A função tem uma lista de argumentos variável.

- A função usa o assembly embutido, a menos que compilada com /Og, /Ox, /O1 ou /O2.

- A função é recursiva e não acompanhada por **#pragma inline_recursion (on)** . Com o pragma, as funções recursivas são embutidas em uma profundidade padrão de 16 chamadas. Para reduzir a profundidade de inalinhamento, use [inline_depth](../preprocessor/inline-depth.md) pragma.

- A função é virtual e é chamada virtualmente. Chamadas diretas à funções virtuais podem ser embutidas.

- O programa usa o endereço da função e a chamada à função é feita pelo ponteiro. Chamadas diretas a funções que tiveram o endereço removido podem ser embutidas.

- A função também é marcada com o modificador de [__declspec](../cpp/declspec.md) [Naked](../cpp/naked-cpp.md) .

Se o compilador não puder embutir em linha uma função declarada com **__forceinline**, ele gerará um aviso de nível 1, exceto quando:

- A função é compilada usando/OD ou/Ob0. Nenhum inalinhamento é esperado nesses casos.

- A função é definida externamente, em uma biblioteca incluída ou em outra unidade de tradução, ou é um destino de chamada virtual ou alvo de chamada indireta. O compilador não pode identificar o código não embutido que ele não pode localizar na unidade de tradução atual.

Funções recursivas podem ser substituídas embutidas em uma profundidade especificada pelo [inline_depth](../preprocessor/inline-depth.md) pragma, até um máximo de 16 chamadas. Após essa profundidade, as chamadas de função recursivas são tratadas como chamadas a uma instância da função.  A profundidade até a qual as funções recursivas são examinadas por heurística embutida não pode exceder 16. O [inline_recursion](../preprocessor/inline-recursion.md) pragma controla a expansão embutida de uma função em expansão no momento. Consulte a opção de compilador/Ob ( [expansão de função embutida](../build/reference/ob-inline-function-expansion.md) ) para obter informações relacionadas.

**Fim da seção específica da Microsoft**

Para obter mais informações sobre como usar o especificador **embutido** , consulte:

- [Funções de membro de classe embutida](../cpp/inline-functions-cpp.md)

- [Definindo funções C++ embutidas com dllexport e dllimport](../cpp/defining-inline-cpp-functions-with-dllexport-and-dllimport.md)

## <a name="when-to-use-inline-functions"></a>Quando usar funções embutidas

As funções embutidas são usadas da melhor forma para funções pequenas, como acessar membros de dados particulares. A principal finalidade dessas funções de acesso de uma ou duas linhas é retornar informações de estado sobre objetos; as funções curtas são sensíveis à sobrecarga das chamadas de função. As funções mais longas proporcionalmente passam menos tempo na sequência de chamadas/retornos e se beneficiam menos do processo de embutir.

Uma classe de `Point` pode ser definida da seguinte maneira:

```cpp
// when_to_use_inline_functions.cpp
class Point
{
public:
    // Define "accessor" functions as
    //  reference types.
    unsigned& x();
    unsigned& y();
private:
    unsigned _x;
    unsigned _y;
};

inline unsigned& Point::x()
{
    return _x;
}
inline unsigned& Point::y()
{
    return _y;
}
int main()
{
}
```

Supondo que a manipulação de coordenadas seja uma operação relativamente comum em um cliente de uma classe desse tipo, a especificação das duas funções de acessador (`x` e `y` no exemplo anterior) como **embutida** normalmente economiza a sobrecarga em:

- Chamadas de função (inclusive passagem de parâmetros e colocação do endereço do objeto na pilha)

- Preservação do registro de ativação do chamador

- Configuração do novo registro de ativação

- Comunicação do valor de retorno

- Restauração do registro de ativação antigo

- Retorno

## <a name="inline-functions-vs-macros"></a>Funções embutidas versus macros

Embora as funções integradas sejam semelhantes a macros (porque o código da função é expandido no ponto de chamada em tempo de compilação), as funções integradas são analisadas pelo compilador, enquanto que as macros são expandidas pelo pré-processador. Como resultado, há várias diferenças importantes:

- As funções integradas seguem todos os protocolos de segurança de tipo impostos em funções normais.

- As funções embutidas são especificadas usando a mesma sintaxe de qualquer outra função, exceto que elas incluem a palavra-chave **inline** na declaração da função.

- As expressões transmitidas como argumentos para as funções integradas são avaliadas uma única vez. Em alguns casos, as expressões transmitidas como argumentos para macros podem ser avaliadas mais de uma vez.

O exemplo a seguir mostra uma macro que converte letras minúsculas em maiúsculas:

```cpp
// inline_functions_macro.c
#include <stdio.h>
#include <conio.h>

#define toupper(a) ((a) >= 'a' && ((a) <= 'z') ? ((a)-('a'-'A')):(a))

int main() {
   char ch;
   printf_s("Enter a character: ");
   ch = toupper( getc(stdin) );
   printf_s( "%c", ch );
}
//  Sample Input:  xyz
// Sample Output:  Z
```

A intenção da expressão `toupper(getc(stdin))` é que um caractere deve ser lido no dispositivo de console (`stdin`) e, se necessário, convertido em letras maiúsculas.

Devido à implementação da macro, `getc` é executado uma vez para determinar se o caractere é maior que ou igual a "a" e para determinar uma vez se ele é menor ou igual a "Z". Se estiver nesse intervalo, `getc` será executado novamente para converter o caractere para letras maiúsculas. Isso significa que o programa espera por dois ou três caracteres quando, de modo ideal, ele deve esperar apenas um.

As funções integradas corrigem o problema descrito anteriormente:

```cpp
// inline_functions_inline.cpp
#include <stdio.h>
#include <conio.h>

inline char toupper( char a ) {
   return ((a >= 'a' && a <= 'z') ? a-('a'-'A') : a );
}

int main() {
   printf_s("Enter a character: ");
   char ch = toupper( getc(stdin) );
   printf_s( "%c", ch );
}
```

```Output
Sample Input: a
Sample Output: A
```

## <a name="see-also"></a>Confira também

[noinline](../cpp/noinline.md)<br/>
[auto_inline](../preprocessor/auto-inline.md)
