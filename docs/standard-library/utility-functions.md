---
title: Funções &lt;utility&gt;
ms.date: 11/04/2016
f1_keywords:
- utility/std::exchange
- utility/std::forward
- utility/std::make_pair
- utility/std::move
- utility/std::swap
ms.assetid: b1df38cd-3a59-4098-9c81-83342eb719a4
helpviewer_keywords:
- std::exchange [C++]
- std::forward [C++]
- std::make_pair [C++]
- std::move [C++]
- std::swap [C++]
ms.openlocfilehash: 723b077500b9b741445efcd8574fb26cd53e5fc7
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78854850"
---
# <a name="ltutilitygt-functions"></a>Funções &lt;utility&gt;

## <a name="asconst"></a>as_const

```cpp
template <class T> constexpr add_const_t<T>& as_const(T& t) noexcept;
template <class T> void as_const(const T&&) = delete;
```

### <a name="return-value"></a>Valor retornado

Retorna *T*.

## <a name="declval"></a>declval

```cpp
template <class T> add_rvalue_reference_t<T> declval() noexcept;  // as unevaluated operand
```

## <a name="exchange"></a>transferência

**(C++14)** Atribui um novo valor a um objeto e retorna seu antigo valor.

```cpp
template <class T, class Other = T>
    T exchange(T& val, Other&& new_val)
```

### <a name="parameters"></a>Parâmetros

*valor*\
O objeto que receberá o valor de new_val.

*new_val*\
O objeto cujo valor é copiado ou movido para val.

### <a name="remarks"></a>Comentários

Para tipos complexos, `exchange` evita que se copie o valor antigo quando um construtor move está disponível, evita que se copie o novo valor se for um objeto temporário ou tiver sido movido e aceita qualquer tipo como novo valor, usando qualquer operador de atribuição conversor. A função Exchange é diferente de [std:: swap](../standard-library/algorithm-functions.md#swap) , pois o argumento esquerdo não é movido ou copiado para o argumento à direita.

### <a name="example"></a>Exemplo

O exemplo a seguir mostra como usar `exchange`. No mundo real, `exchange` é mais útil com objetos grandes de cópia cara:

```cpp
#include <utility>
#include <iostream>

using namespace std;

struct C
{
   int i;
   //...
};

int main()
{
   // Use brace initialization
   C c1{ 1 };
   C c2{ 2 };
   C result = exchange(c1, c2);
   cout << "The old value of c1 is: " << result.i << endl;
   cout << "The new value of c1 after exchange is: " << c1.i << endl;

   return 0;
}
```

```Output
The old value of c1 is: 1
The new value of c1 after exchange is: 2
```

## <a name="forward"></a>avançada

Converterá condicionalmente seu argumento em uma referência rvalue se o argumento for um rvalue ou referência rvalue. Isso restaura o rvalue-ness de um argumento para a função de encaminhamento como suporte ao encaminhamento perfeito.

```cpp
template <class Type>    // accepts lvalues
    constexpr Type&& forward(typename remove_reference<Type>::type& Arg) noexcept

template <class Type>    // accepts everything else
    constexpr Type&& forward(typename remove_reference<Type>::type&& Arg) noexcept
```

### <a name="parameters"></a>Parâmetros

*Tipo*\
O tipo do valor passado em *ARG*, que pode ser diferente do tipo de *ARG*. Geralmente determinado por um argumento de modelo da função de encaminhamento.

*Arg*\
O argumento a ser convertido.

### <a name="return-value"></a>Valor retornado

Retorna uma referência rvalue a *ARG* se o valor passado em *ARG* era originalmente um Rvalue ou uma referência a um Rvalue; caso contrário, retorna *ARG* sem modificar seu tipo.

### <a name="remarks"></a>Comentários

Você deve especificar um argumento de modelo explícito para chamar `forward`.

`forward` não encaminha seu argumento. Em vez disso, ao converter condicionalmente seu argumento em uma referência rvalue se ele originalmente era um rvalue ou referência rvalue, `forward` permite que o compilador execute a resolução de sobrecarga com conhecimento do tipo original do argumento encaminhado. O tipo aparente de um argumento para uma função de encaminhamento pode ser diferente do seu tipo original — por exemplo, quando um Rvalue é usado como um argumento para uma função e está associado a um nome de parâmetro; ter um nome torna-o um lvalue, com qualquer valor que realmente exista como um Rvalue — `forward` restaura o rvalue-qualidade do argumento.

Restaurar o rvalue-qualidade do valor original de um argumento para fazer a resolução de sobrecarga é conhecido como *encaminhamento perfeito*. O encaminhamento perfeito permite que uma função de modelo aceite um argumento do tipo de referência e restaure seu rvalue-ness quando for necessário para resolução de sobrecarga correta. Usando o encaminhamento perfeito, você pode preservar as semânticas de movimento para rvalues, além de evitar ter que fornecer sobrecargas para funções que variam apenas pelo tipo de referência de seus argumentos.

## <a name="from_chars"></a>from_chars

```cpp
from_chars_result from_chars(const char* first, const char* last, see below& value, int base = 10);

from_chars_result from_chars(const char* first, const char* last, float& value, chars_format fmt = chars_format::general); 

from_chars_result from_chars(const char* first, const char* last, double& value, chars_format fmt = chars_format::general); 

from_chars_result from_chars(const char* first, const char* last, long double& value, chars_format fmt = chars_format::general);
```

## <a name="get"></a>Obter

Obtém um elemento de um objeto `pair`, por posição no índice ou por tipo.

```cpp
// get reference to element at Index in pair Pr
template <size_t Index, class T1, class T2>
    constexpr tuple_element_t<Index, pair<T1, T2>>&
    get(pair<T1, T2>& Pr) noexcept;

// get reference to element T1 in pair Pr
template <class T1, class T2>
    constexpr T1& get(pair<T1, T2>& Pr) noexcept;

// get reference to element T2 in pair Pr
template <class T2, class T1>
    constexpr T2& get(pair<T1, T2>& Pr) noexcept;

// get const reference to element at Index in pair Pr
template <size_t Index, class T1, class T2>
    constexpr const tuple_element_t<Index, pair<T1, T2>>&
    get(const pair<T1, T2>& Pr) noexcept;

// get const reference to element T1 in pair Pr
template <class T1, class T2>
    constexpr const T1& get(const pair<T1, T2>& Pr) noexcept;

// get const reference to element T2 in pair Pr
template <class T2, class T1>
    constexpr const T2& get(const pair<T1, T2>& Pr) noexcept;

// get rvalue reference to element at Index in pair Pr
template <size_t Index, class T1, class T2>
    constexpr tuple_element_t<Index, pair<T1, T2>>&&
    get(pair<T1, T2>&& Pr) noexcept;

// get rvalue reference to element T1 in pair Pr
template <class T1, class T2>
    constexpr T1&& get(pair<T1, T2>&& Pr) noexcept;

// get rvalue reference to element T2 in pair Pr
template <class T2, class T1>
    constexpr T2&& get(pair<T1, T2>&& Pr) noexcept;
```

### <a name="parameters"></a>Parâmetros

*Index*\
O índice de base 0 do elemento escolhido.

\ *T1*
O tipo do primeiro elemento do par.

*T2*\
O tipo do segundo elemento do par.

*pr*\
O par do qual selecionar.

### <a name="remarks"></a>Comentários

As funções modelo retornam uma referência a um elemento de seu argumento `pair`.

Para as sobrecargas indexadas, se o valor do *índice* for 0, as funções retornarão `pr.first` e se o valor do *índice* for 1, as funções retornarão `pr.second`. O tipo `RI` é o tipo do elemento retornado.

Para as sobrecargas que não têm um parâmetro de índice, o elemento a ser retornado é deduzido pelo argumento de tipo. Chamar `get<T>(Tuple)` produzirá um erro do compilador se *PR* contiver mais ou menos de um elemento do tipo t.

### <a name="example"></a>Exemplo

```cpp
#include <utility>
#include <iostream>
using namespace std;
int main()
{

    typedef pair<int, double> MyPair;

    MyPair c0(9, 3.14);

    // get elements by index
    cout << " " << get<0>(c0);
    cout << " " << get<1>(c0) << endl;

    // get elements by type (C++14)
    MyPair c1(1, 0.27);
    cout << " " << get<int>(c1);
    cout << " " << get<double>(c1) << endl;
}
```

```Output
9 3.14
1 0.27
```

## <a name="index_sequence"></a>index_sequence

```cpp
template<size_t... I>
    using index_sequence = integer_sequence<size_t, I...>;
```

## <a name="index_sequence_for"></a>index_sequence_for

```cpp
template<class... T>
    using index_sequence_for = make_index_sequence<sizeof...(T)>;
```

## <a name="make_index_sequence"></a>make_index_sequence

```cpp
template<size_t N>
    using make_index_sequence = make_integer_sequence<size_t, N>;
```

## <a name="make_integer_sequence"></a>make_integer_sequence

```cpp
template<class T, T N>
    using make_integer_sequence = integer_sequence<T, see below >;
```

## <a name="make_pair"></a>make_pair

Uma função de modelo que você pode usar para construir objetos do tipo `pair`, em que os tipos de componente são automaticamente escolhidos com base nos tipos de dados que são transmitidos como parâmetros.

```cpp
template <class T, class U>
    pair<T, U> make_pair(T& Val1, U& Val2);

template <class T, class U>
    pair<T, U> make_pair(T& Val1, U&& Val2);

template <class T, class U>
    pair<T, U> make_pair(T&& Val1, U& Val2);

template <class T, class U>
    pair<T, U> make_pair(T&& Val1, U&& Val2);
```

### <a name="parameters"></a>Parâmetros

\ *val1*
O valor que inicializa o primeiro elemento de `pair`.

\ *Val2*
O valor que inicializa o segundo elemento de `pair`.

### <a name="return-value"></a>Valor retornado

O objeto de par que é construído: `pair`<`T`,`U`> (`Val1`, `Val2`).

### <a name="remarks"></a>Comentários

`make_pair` converte o objeto do tipo [Classe reference_wrapper](../standard-library/reference-wrapper-class.md) para tipos de referência e converte matrizes decrescentes e funções em ponteiros.

No objeto `pair` retornado, `T` é determinado como se segue:

- Se o tipo de entrada `T` for `reference_wrapper<X>`, o tipo `T` retornado será `X&`.

- Caso contrário, o tipo `T` retornado será `decay<T>::type`. Se a [classe decaimento](../standard-library/decay-class.md) não tiver suporte, o tipo retornado `T` será o mesmo que o tipo de entrada `T`.

O tipo `U` retornado é determinado de forma semelhante do tipo de entrada `U`.

Uma vantagem do `make_pair` é que os tipos de objetos que estão sendo armazenados são determinados automaticamente pelo compilador e não precisam ser especificados explicitamente. Não use argumentos de modelo explícitos, como `make_pair<int, int>(1, 2)` ao usar `make_pair` porque ele é detalhado e adiciona problemas de referência de rvalue complexos que podem causar falha de compilação. Para este exemplo, a sintaxe correta seria `make_pair(1, 2)`

A função auxiliar `make_pair` também possibilita passar dois valores a uma função que exige um par como um parâmetro de entrada.

### <a name="example"></a>Exemplo

Para obter um exemplo de como usar a função auxiliar `make_pair` para declarar e inicializar um par, consulte [Estrutura pair](../standard-library/pair-structure.md).

## <a name="move"></a>prosseguir

Converte incondicionalmente seu argumento em uma referência de rvalue e, assim, os sinais que podem ser movidos se seu tipo for habilitado para movimento.

```cpp
template <class Type>
    constexpr typename remove_reference<Type>::type&& move(Type&& Arg) noexcept;
```

### <a name="parameters"></a>Parâmetros

*Tipo*\
Um tipo deduzido do tipo de argumento passado em *ARG*, junto com as regras de recolhimento de referência.

*Arg*\
O argumento a ser convertido. Embora o tipo de *ARG* pareça ser especificado como uma referência rvalue, `move` também aceita argumentos lvalue porque as referências lvalue podem se associar a referências rvalue.

### <a name="return-value"></a>Valor retornado

`Arg` como uma referência de rvalue, seja ou não seu tipo um tipo de referência.

### <a name="remarks"></a>Comentários

O *tipo* de argumento de modelo não deve ser especificado explicitamente, mas deve ser deduzido do tipo de valor passado em *ARG*. O tipo de *tipo* é ainda mais ajustado de acordo com as regras de recolhimento de referência.

`move` não move seu argumento. Em vez disso, ao converter incondicionalmente seu argumento — que pode ser um lvalue — para uma referência rvalue, ele permite que o compilador mova-se subsequentemente, em vez de copiar, o valor passado em *ARG* se seu tipo for habilitado para movimentação. Se o seu tipo não estiver habilitado para movimentação, ele será copiado em seu lugar.

Se o valor passado em *ARG* for um lvalue — ou seja, ele tiver um nome ou seu endereço pode ser obtido — ele será invalidado quando ocorrer a movimentação. Não se refere ao valor passado em *ARG* por seu nome ou endereço depois de ser movido.

## <a name="moveif"></a>move_if_noexcept

```cpp
template <class T> constexpr conditional_t< !is_nothrow_move_constructible_v<T> && is_copy_constructible_v<T>, const T&, T&&> move_if_noexcept(T& x) noexcept;
```

## <a name="swap"></a>permuta

Troca os elementos de dois objetos de estrutura de tipo ou [par](../standard-library/pair-structure.md) .

```cpp
template <class T>
    void swap(T& left, T& right) noexcept(see below );
template <class T, size_t N>
    void swap(T (&left)[N], T (&right)[N]) noexcept(is_nothrow_swappable_v<T>);
template <class T, class U>
    void swap(pair<T, U>& left, pair<T, U>& right);
```

### <a name="parameters"></a>Parâmetros

\ *à esquerda*
Um objeto do tipo ou do tipo `pair`.

\ *à direita*
Um objeto do tipo ou do tipo `pair`.

### <a name="remarks"></a>Comentários

Uma vantagem do `swap` é que os tipos de objetos que estão sendo armazenados são determinados automaticamente pelo compilador e não precisam ser especificados explicitamente. Não use argumentos de modelo explícitos, como `swap<int, int>(1, 2)` ao usar `swap` porque ele é detalhado e adiciona problemas de referência de rvalue complexos que podem causar falha de compilação.

## <a name="to_chars"></a>to_chars

```cpp
to_chars_result to_chars(char* first, char* last, see below value, int base = 10);
to_chars_result to_chars(char* first, char* last, float value); 
to_chars_result to_chars(char* first, char* last, double value); 
to_chars_result to_chars(char* first, char* last, long double value);
to_chars_result to_chars(char* first, char* last, float value, chars_format fmt); 
to_chars_result to_chars(char* first, char* last, double value, chars_format fmt); 
to_chars_result to_chars(char* first, char* last, long double value, chars_format fmt);
to_chars_result to_chars(char* first, char* last, float value, chars_format fmt, int precision); 
to_chars_result to_chars(char* first, char* last, double value, chars_format fmt, int precision); 
to_chars_result to_chars(char* first, char* last, long double value, chars_format fmt, int precision);
```

### <a name="remarks"></a>Comentários

Converte o valor em uma cadeia de caracteres preenchendo o intervalo `[first, last)`, em que `[first, last)` é necessário para ser um intervalo válido.
