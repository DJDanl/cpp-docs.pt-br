---
title: Classe enable_if
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::enable_if
helpviewer_keywords:
- enable_if class
- enable_if
ms.assetid: c6b8d41c-a18f-4e30-a39e-b3aa0e8fd926
ms.openlocfilehash: b6990dba20643b35dde36a492d40c3e3e76ae0b4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50591874"
---
# <a name="enableif-class"></a>Classe enable_if

Condicionalmente cria uma instância de um tipo para resolução de sobrecarga SFINAE. O typedef aninhado `enable_if<Condition,Type>::type` existe — e é um sinônimo de `Type`— se e somente se `Condition` é **true**.

## <a name="syntax"></a>Sintaxe

```cpp
template <bool B, class T = void>
struct enable_if;
```

### <a name="parameters"></a>Parâmetros

*B*<br/>
O valor que determina a existência do tipo resultante.

*T*<br/>
O tipo a instanciar se *B* é verdadeiro.

## <a name="remarks"></a>Comentários

Se *B* for true, `enable_if<B, T>` tem um typedef aninhado chamado "tipo" que é um sinônimo de *T*.

Se *B* é false, `enable_if<B, T>` não tem um typedef aninhado chamado "tipo".

Este modelo de alias é fornecido:

```cpp
template <bool B, class T = void>
using enable_if_t = typename enable_if<B,T>::type;
```

Em C++, a falha de substituição de parâmetros de modelo não é um erro em si – isso é chamado de *SFINAE* (Falha de substituição não é um erro). Em geral, `enable_if` é usado para remover candidatos da resolução de sobrecarga (ou seja, seleciona o conjunto de sobrecarga) de modo que uma definição possa ser rejeitada a favor de outra. Isso está de acordo com o comportamento SFINAE. Para obter informações sobre SFINAE, consulte [Falha de substituição não é um erro](http://go.microsoft.com/fwlink/p/?linkid=394798) na Wikipédia.

Seguem quatro cenários de exemplo:

- Cenário 1: Definindo a disposição do tipo de retorno de uma função:

```cpp
    template <your_stuff>
typename enable_if<your_condition, your_return_type>::type
    yourfunction(args) {// ...
}
// The alias template makes it more concise:
    template <your_stuff>
enable_if_t<your_condition, your_return_type>
yourfunction(args) {// ...
}
```

- Cenário 2: Adicionando um parâmetro de função com um argumento padrão:

```cpp
    template <your_stuff>
your_return_type_if_present
    yourfunction(args, enable_if_t<your condition, FOO> = BAR) {// ...
}
```

- Cenário 3: Adicionando um parâmetro de modelo com um argumento padrão:

```cpp
    template <your_stuff, typename Dummy = enable_if_t<your_condition>>
rest_of_function_declaration_goes_here
```

- Cenário 4: Se a sua função tiver um argumento não modelado, você poderá encapsular seu tipo:

```cpp
    template <typename T>
void your_function(const T& t,
    enable_if_t<is_something<T>::value, const string&>
s) {// ...
}
```

O Cenário 1 não funciona com construtores e operadores de conversão porque eles não possuem tipos de retorno.

O Cenário 2 deixa o parâmetro sem nome. Você poderia dizer `::type Dummy = BAR`, mas o nome `Dummy` é irrelevante, e atribuir um nome a ele provavelmente acionará um aviso de "parâmetro sem referência". Você precisa escolher um tipo de parâmetro de função `FOO` e um argumento padrão `BAR`.  Você poderia dizer **int** e `0`, mas, em seguida, os usuários do seu código acidentalmente enviariam à função um número inteiro extra que seria ignorado. Em vez disso, é recomendável que você use `void **` e qualquer um dos `0` ou **nullptr** porque quase nada pode ser convertido para `void **`:

```cpp
template <your_stuff>
your_return_type_if_present
yourfunction(args, typename enable_if<your_condition, void **>::type = nullptr) {// ...
}
```

O Cenário 2 também funciona para construtores comuns.  Porém, não funciona para os operadores de conversão porque eles não podem assumir parâmetros extras.  Também não funciona para construtores [variadic](../cpp/ellipses-and-variadic-templates.md) porque adicionar parâmetros extras torna um pacote de parâmetro de função um contexto não deduzido e, portanto, não atende o objetivo de `enable_if`.

O Cenário 3 usa o nome `Dummy`, mas é opcional. Apenas "`typename = typename`" funcionaria, mas se você achar que parece estranho, pode usar um nome "falso"; apenas não use um que também possa ser usado na definição da função. Se não der um tipo a `enable_if`, ele assume nulo como padrão, e isso é perfeitamente razoável, pois você não se importa com o que `Dummy` é. Isso funciona para tudo, incluindo operadores de conversão e construtores [variadic](../cpp/ellipses-and-variadic-templates.md).

O Cenário 4 funciona em construtores que não têm tipos de retorno e, portanto, soluciona a limitação de disposição do Cenário 1.  Porém, o Cenário 4 está limitado a argumentos de função não modelados, que nem sempre estão disponíveis.  (Usar o Cenário 4 em um argumento de função modelado impede que a dedução do argumento de modelo funcione nele.)

`enable_if` é eficiente, mas também perigoso de usado incorretamente.  Uma vez que seu objetivo é fazer os candidatos desaparecerem antes da resolução de sobrecarga, quando mal utilizado, seus efeitos podem ser muito confusos.  Seguem algumas recomendações:

- Não use `enable_if` para selecionar entre implementações no momento da compilação. Jamais grave um `enable_if` para `CONDITION` e outro para `!CONDITION`.  Em vez disso, use um padrão *despacho de marca*, por exemplo, um algoritmo que selecione implementações dependendo dos pontos fortes dos iteradores recebidos.

- Não use `enable_if` para aplicar requisitos.  Se desejar validar parâmetros de modelo e se a validação falhar, causar um erro em vez de selecionar outra implementação, use [static_assert](../cpp/static-assert.md).

- Use `enable_if` quando tiver um conjunto de sobrecarga que torne ambíguo o código que, de outra forma, seria bom.  Isso ocorre com mais frequência ao converter construtores implicitamente.

## <a name="example"></a>Exemplo

Este exemplo explica como a função [std::make_pair()](../standard-library/utility-functions.md#make_pair) do modelo da biblioteca padrão C++ aproveita `enable_if`.

```cpp
void func(const pair<int, int>&);

void func(const pair<string, string>&);

func(make_pair("foo", "bar"));
```

Neste exemplo, `make_pair("foo", "bar")` retorna `pair<const char *, const char *>`. A resolução de sobrecarga precisa determinar que `func()` você deseja. `pair<A, B>` tem um construtor de conversão implícita de `pair<X, Y>`.  Isso não é novidade, tinha no C++98. Porém, no C++98/03, a assinatura do construtor de conversão implícita sempre existe, mesmo que seja `pair<int, int>(const pair<const char *, const char *>&)`.  Resolução de sobrecarga não se importa com que uma tentativa de instanciar esse construtor exploda terrivelmente porque `const char *` não é implicitamente conversível para **int**; ele olha apenas assinaturas, antes da função são definições criar uma instância.  Portanto, o código de exemplo é ambíguo, pois não existem assinaturas para converter `pair<const char *, const char *>` para `pair<int, int>` e `pair<string, string>`.

C++11 solucionou essa ambiguidade usando `enable_if` para garantir que `pair<A, B>(const pair<X, Y>&)` exista **apenas** quando `const X&` puder ser implicitamente convertido para `A` e `const Y&` puder ser implicitamente convertido para `B`.  Isso permite que a resolução de sobrecarga determine que `pair<const char *, const char *>` não pode ser convertido para `pair<int, int>` e que a sobrecarga que obtém `pair<string, string>` é viável.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
