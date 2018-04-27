---
title: Funções &lt;utility&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- utility/std::exchange
- utility/std::forward
- utility/std::make_pair
- utility/std::move
- utility/std::swap
ms.assetid: b1df38cd-3a59-4098-9c81-83342eb719a4
caps.latest.revision: 7
manager: ghogen
helpviewer_keywords:
- std::exchange [C++]
- std::forward [C++]
- std::make_pair [C++]
- std::move [C++]
- std::swap [C++]
ms.openlocfilehash: 20599ee24dbf8db033a91767ece30160c05cc8d8
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="ltutilitygt-functions"></a>Funções &lt;utility&gt;

||||
|-|-|-|
|[exchange](#exchange)|[forward](#forward)|[obter Função &lt;utility&gt;](#get)|
|[make_pair](#make_pair)|[move](#move)|[swap](#swap)|

## <a name="exchange"></a>  exchange

**(C++14)** Atribui um novo valor a um objeto e retorna seu antigo valor.

```cpp
template <class T, class Other = T>
T exchange(T& val, Other&& new_val)
```

### <a name="parameters"></a>Parâmetros

`val` O objeto que receberá o valor de new_val.

`new_val` O objeto cujo valor é copiado ou movido para o valor.

### <a name="remarks"></a>Comentários

Para tipos complexos, `exchange` evita que se copie o valor antigo quando um construtor move está disponível, evita que se copie o novo valor se for um objeto temporário ou tiver sido movido e aceita qualquer tipo como novo valor, usando qualquer operador de atribuição conversor. A função exchange é diferente de [std::swap](../standard-library/algorithm-functions.md#swap), pois o argumento à esquerda não é movido ou copiado para o argumento à direita.

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

## <a name="forward"></a>  forward

Converterá condicionalmente seu argumento em uma referência rvalue se o argumento for um rvalue ou referência rvalue. Isso restaura o rvalue-ness de um argumento para a função de encaminhamento como suporte ao encaminhamento perfeito.

```cpp
template <class Type>    // accepts lvalues
constexpr Type&& forward(typename remove_reference<Type>::type& Arg) noexcept

template <class Type>    // accepts everything else
constexpr Type&& forward(typename remove_reference<Type>::type&& Arg) noexcept
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|`Type`|O tipo do valor passado em `Arg`, que pode ser diferente do tipo de `Arg`. Geralmente determinado por um argumento de modelo da função de encaminhamento.|
|`Arg`|O argumento a ser convertido.|

### <a name="return-value"></a>Valor de retorno

Retornará uma referência rvalue para `Arg` se o valor passado em `Arg` era originalmente um rvalue ou uma referência a um rvalue; caso contrário, retornará `Arg` sem modificação do seu tipo.

### <a name="remarks"></a>Comentários

Você deve especificar um argumento de modelo explícito para chamar `forward`.

`forward` não encaminha seu argumento. Em vez disso, ao converter condicionalmente seu argumento em uma referência rvalue se ele originalmente era um rvalue ou referência rvalue, `forward` permite que o compilador execute a resolução de sobrecarga com conhecimento do tipo original do argumento encaminhado. O tipo aparente de um argumento para uma função de encaminhamento pode ser diferente do tipo original – por exemplo, quando um rvalue é usado como um argumento para uma função e é associado a um nome de parâmetro; ter um nome o torna um lvalue, independentemente de o valor realmente existir como um rvalue – `forward` restaura o rvalue-ness do argumento.

Restaurar o rvalue-ness do valor original de um argumento para executar a resolução de sobrecarga é conhecido como *encaminhamento perfeito*. O encaminhamento perfeito permite que uma função de modelo aceite um argumento do tipo de referência e restaure seu rvalue-ness quando for necessário para resolução de sobrecarga correta. Usando o encaminhamento perfeito, você pode preservar as semânticas de movimento para rvalues, além de evitar ter que fornecer sobrecargas para funções que variam apenas pelo tipo de referência de seus argumentos.

## <a name="get"></a>  get

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

`Index` O índice de base 0 do elemento designado.

`T1` O tipo do primeiro elemento do par.

`T2` O tipo do elemento segundo par.

`pr` O par selecionem.

### <a name="remarks"></a>Comentários

As funções modelo retornam uma referência a um elemento de seu argumento `pair`.

Para as sobrecargas indexadas, se o valor de `Index` for 0, as funções retornarão `pr.first` e se o valor de `Index` for 1, as funções retornarão `pr.second`. O tipo `RI` é o tipo do elemento retornado.

Para sobrecargas que não têm um parâmetro de Índice, o elemento a ser retornado é deduzido pelo argumento de tipo. Chamar `get<T>(Tuple)` produzirá um erro do compilador se `pr` contiver mais ou menos de um elemento do tipo T.

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

    /*
    Output:
    9 3.14
    1 0.27
    */

}
```

## <a name="make_pair"></a>  make_pair

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

`Val1` Valor que inicializa o primeiro elemento da `pair`.

`Val2` Valor que inicializa o segundo elemento do `pair`.

### <a name="return-value"></a>Valor de retorno

O objeto pair construído: `pair`< `T`, `U`>( `Val1`, `Val2`).

### <a name="remarks"></a>Comentários

`make_pair` converte o objeto do tipo [Classe reference_wrapper](../standard-library/reference-wrapper-class.md) para tipos de referência e converte matrizes decrescentes e funções em ponteiros.

No objeto `pair` retornado, `T` é determinado como se segue:

- Se o tipo de entrada `T` for `reference_wrapper<X>`, o tipo `T` retornado será `X&`.

- Caso contrário, o tipo `T` retornado será `decay<T>::type`. Se não houver suporte para a [Classe decay](../standard-library/decay-class.md), o tipo retornado `T` será o mesmo que o tipo de entrada `T`.

O tipo `U` retornado é determinado de forma semelhante do tipo de entrada `U`.

Uma vantagem de `make_pair` é que os tipos de objetos que estão sendo armazenados são determinados automaticamente pelo compilador e não precisam ser explicitamente especificados. Não use argumentos de modelo explícitos, como `make_pair<int, int>(1, 2)`, ao usar `make_pair`, pois ele é desnecessariamente detalhado e adiciona problemas complexos de referência rvalue que podem causar falha de compilação. Para este exemplo, a sintaxe correta seria `make_pair(1, 2)`

A função auxiliar `make_pair` também possibilita passar dois valores a uma função que exige um par como um parâmetro de entrada.

### <a name="example"></a>Exemplo

Para obter um exemplo de como usar a função auxiliar `make_pair` para declarar e inicializar um par, consulte [Estrutura pair](../standard-library/pair-structure.md).

## <a name="move"></a>  move

Converte incondicionalmente seu argumento em uma referência de rvalue e, assim, os sinais que podem ser movidos se seu tipo for habilitado para movimento.

```cpp
template <class Type>
constexpr typename remove_reference<Type>::type&& move(Type&& Arg) noexcept;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|`Type`|Um tipo deduzido do tipo do argumento passado em `Arg`, juntamente com as regras de recolhimento de referência.|
|`Arg`|O argumento a ser convertido. Embora o tipo de `Arg` pareça ser especificado como uma referência de rvalue, `move` também aceita argumentos lvalue, pois as referência de lvalue podem se associar a referências de rvalue.|

### <a name="return-value"></a>Valor de retorno

`Arg` como uma referência de rvalue, seja ou não seu tipo um tipo de referência.

### <a name="remarks"></a>Comentários

O argumento de modelo `Type` não é destinado a ser especificado explicitamente, mas a ser deduzido do tipo do valor passado em `Arg`. O tipo de `Type` é ainda ajustado de acordo com as regras de recolhimento de referência.

`move` não move seu argumento. Em vez disso, ao converter incondicionalmente seu argumento (que pode ser um lvalue) em uma referência de rvalue, ele permite que o compilador mova subsequentemente, em vez de copiar, o valor passado em `Arg` se seu tipo for habilitado para movimento. Se seu tipo não for habilitado para movimento, ele será copiado.

Se o valor passado em `Arg` for um lvalue, isto é, tiver um nome ou seu endereço puder ser usado, ele será invalidado quando a movimentação ocorrer. Não faça referência ao valor passado em `Arg` por seu nome ou endereço depois que for movido.

## <a name="swap"></a>  swap

Troca os elementos de dois objetos da [Estrutura pair](../standard-library/pair-structure.md).

```cpp
template <class T, class U>
void swap(pair<T, U>& left, pair<T, U>& right);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|`left`|Um objeto do tipo `pair`.|
|`right`|Um objeto do tipo `pair`.|

### <a name="remarks"></a>Comentários

Uma vantagem de `swap` é que os tipos de objetos que estão sendo armazenados são determinados automaticamente pelo compilador e não precisam ser explicitamente especificados. Não use argumentos de modelo explícitos, como `swap<int, int>(1, 2)`, ao usar `swap`, pois ele é desnecessariamente detalhado e adiciona problemas complexos de referência rvalue que podem causar falha de compilação.

## <a name="see-also"></a>Consulte também

[\<utility>](../standard-library/utility.md)<br/>
