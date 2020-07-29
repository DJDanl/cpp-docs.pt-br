---
title: Classe recursive_directory_iterator
ms.date: 09/10/2018
f1_keywords:
- filesystem/std::tr2::sys::recursive_directory_iterator
ms.assetid: 79a061bd-5b64-404c-97e8-749c888c2ced
ms.openlocfilehash: 0f9bdc3edd7f5798afaa8d170adc35708a6aafa2
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87217617"
---
# <a name="recursive_directory_iterator-class"></a>Classe recursive_directory_iterator

Descreve um iterador de entrada que é sequenciado pelos nomes de dados em um diretório, possivelmente decrescente em subdiretórios de forma recursiva. Para um iterador `X` , a expressão `*X` é avaliada como um objeto da classe `directory_entry` que encapsula o nome do arquivo e qualquer coisa conhecida sobre seu status.

Para obter mais informações e exemplos de código, consulte [Navegação do Sistema de Arquivos (C++)](../standard-library/file-system-navigation.md).

## <a name="syntax"></a>Sintaxe

```cpp
class recursive_directory_iterator;
```

## <a name="remarks"></a>Comentários

O modelo de classe armazena:

1. um objeto do tipo `stack<pair<directory_iterator, path>>` , chamado `mystack` aqui para fins de exposição, que representa o aninhamento de diretórios a serem sequenciados

1. um objeto do tipo `directory_entry` chamado `myentry` aqui, que representa o nome de arquivo atual na sequência de diretórios

1. um objeto do tipo **`bool`** , chamado `no_push` aqui, que registra se os descendente recursivos em subdiretórios estão desabilitados

1. um objeto do tipo `directory_options` , chamado `myoptions` aqui, que registra as opções estabelecidas na construção

Um objeto construído padrão do tipo `recursive_directory_entry` tem um iterador de fim de sequência em `mystack.top().first` e representa o iterador de fim de sequência. Por exemplo, considerando o diretório `abc` com entradas `def` (um diretório), `def/ghi` e `jkl` , o código:

```cpp
for (recursive_directory_iterator next(path("abc")), end; next != end; ++next)
    visit(next->path());
```

chamará a visita com os argumentos `path("abc/def/ghi")` e `path("abc/jkl")` . Você pode qualificar o sequenciamento por meio de uma subárvore de diretório de duas maneiras:

1. Um diretório symlink será verificado somente se você construir um `recursive_directory_iterator` com um `directory_options` argumento cujo valor seja `directory_options::follow_directory_symlink` .

1. Se você chamar `disable_recursion_pending` , um diretório subsequente encontrado durante um incremento não será examinado recursivamente.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[recursive_directory_iterator](#recursive_directory_iterator)|Constrói um `recursive_directory_iterator`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[Detalhado](#depth)|Retorna `mystack.size() - 1` , portanto, `pval` é de profundidade zero.|
|[disable_recursion_pending](#disable_recursion_pending)|Armazena **`true`** em `no_push` .|
|[increment](#increment)|Avança para o próximo nome de arquivo em sequência.|
|[options](#options)|Retorna `myoptions`.|
|[pop](#pop)|Retorna o próximo objeto.|
|[recursion_pending](#recursion_pending)|Retorna `!no_push`.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operador! =](#op_neq)|Retorna `!(*this == right)`.|
|[operador =](#op_as)|Os operadores de atribuição de membro usados como padrão se comportam como esperado.|
|[operador = =](#op_eq)|Retorna **`true`** somente se o **`*this`** e o *direito* forem iteradores de fim de sequência ou ambos não forem de fim de sequência-iteradores.|
|[operador](#op_multiply)|Retorna `myentry`.|
|[operador->](#op_cast)|Retorna `&**this`.|
|[operador + +](#op_increment)|Incrementa o `recursive_directory_iterator` .|

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<filesystem>

**Namespace:** std::tr2::sys

## <a name="recursive_directory_iteratordepth"></a><a name="depth"></a>recursive_directory_iterator::d epth

Retorna `mystack.size() - 1` , portanto, `pval` é de profundidade zero.

```cpp
int depth() const;
```

## <a name="recursive_directory_iteratordisable_recursion_pending"></a><a name="disable_recursion_pending"></a>recursive_directory_iterator::d isable_recursion_pending

Armazena **`true`** em `no_push` .

```cpp
void disable_recursion_pending();
```

## <a name="recursive_directory_iteratorincrement"></a><a name="increment"></a>recursive_directory_iterator:: incremento

Avança para o próximo nome de arquivo em sequência.

```cpp
recursive_directory_iterator& increment(error_code& ec) noexcept;
```

### <a name="parameters"></a>parâmetros

*Comunidade*\
Código de erro especificado.

### <a name="remarks"></a>Comentários

A função tenta avançar para o próximo nome de arquivo na sequência aninhada. Se for bem-sucedido, ele armazenará esse nome de arquivo em `myentry` ; caso contrário, ele produzirá um iterador de fim de sequência.

## <a name="recursive_directory_iteratoroperator"></a><a name="op_neq"></a>recursive_directory_iterator:: Operator! =

Retorna `!(*this == right)`.

```cpp
bool operator!=(const recursive_directory_iterator& right) const;
```

### <a name="parameters"></a>parâmetros

*Certo*\
A [recursive_directory_iterator](../standard-library/recursive-directory-iterator-class.md) para comparação.

## <a name="recursive_directory_iteratoroperator"></a><a name="op_as"></a>recursive_directory_iterator:: Operator =

Os operadores de atribuição de membro usados como padrão se comportam como esperado.

```cpp
recursive_directory_iterator& operator=(const recursive_directory_iterator&) = default;
recursive_directory_iterator& operator=(recursive_directory_iterator&&) noexcept = default;
```

### <a name="parameters"></a>parâmetros

*recursive_directory_iterator*\
O [recursive_directory_iterator](../standard-library/recursive-directory-iterator-class.md) sendo copiado para o `recursive_directory_iterator` .

## <a name="recursive_directory_iteratoroperator"></a><a name="op_eq"></a>recursive_directory_iterator:: Operator = =

Retorna **`true`** somente se o **`*this`** e o *direito* forem iteradores de fim de sequência ou ambos não forem de fim de sequência-iteradores.

```cpp
bool operator==(const recursive_directory_iterator& right) const;
```

### <a name="parameters"></a>parâmetros

*Certo*\
A [recursive_directory_iterator](../standard-library/recursive-directory-iterator-class.md) para comparação.

## <a name="recursive_directory_iteratoroperator"></a><a name="op_multiply"></a>recursive_directory_iterator:: Operator *

Retorna `myentry`.

```cpp
const directory_entry& operator*() const;
```

## <a name="recursive_directory_iteratoroperator-"></a><a name="op_cast"></a>operador recursive_directory_iterator:: Operator->

Retorna `&**this`.

```cpp
const directory_entry * operator->() const;
```

## <a name="recursive_directory_iteratoroperator"></a><a name="op_increment"></a>recursive_directory_iterator:: operador + +

Incrementa o `recursive_directory_iterator` .

```cpp
recursive_directory_iterator& operator++();

recursive_directory_iterator& operator++(int);
```

### <a name="parameters"></a>parâmetros

*inteiro*\
O incremento especificado.

### <a name="remarks"></a>Comentários

A primeira chamada de função de membro `increment()` , em seguida, retorna **`*this`** . A segunda função de membro faz uma cópia do objeto, chama `increment()` e, em seguida, retorna a cópia.

## <a name="recursive_directory_iteratoroptions"></a><a name="options"></a>recursive_directory_iterator:: opções

Retorna `myoptions`.

```cpp
directory_options options() const;
```

## <a name="recursive_directory_iteratorpop"></a><a name="pop"></a>recursive_directory_iterator::p op

Retorna o próximo objeto.

```cpp
void pop();
```

### <a name="remarks"></a>Comentários

Se `depth() == 0` o objeto se tornar um iterador de fim de sequência. Caso contrário, a função de membro termina a varredura do diretório atual (mais profundo) e retoma no próximo nível inferior.

## <a name="recursive_directory_iteratorrecursion_pending"></a><a name="recursion_pending"></a>recursive_directory_iterator:: recursion_pending

Retorna `!no_push`.

```cpp
bool recursion_pending() const;
```

## <a name="recursive_directory_iteratorrecursive_directory_iterator"></a><a name="recursive_directory_iterator"></a>recursive_directory_iterator:: recursive_directory_iterator

Constrói um `recursive_directory_iterator`.

```cpp
recursive_directory_iterator() noexcept;
explicit recursive_directory_iterator(const path& pval);

recursive_directory_iterator(const path& pval,
    error_code& ec) noexcept;
recursive_directory_iterator(const path& pval,
    directory_options opts);

recursive_directory_iterator(const path& pval,
    directory_options opts,
    error_code& ec) noexcept;
recursive_directory_iterator(const recursive_directory_iterator&) = default;
recursive_directory_iterator(recursive_directory_iterator&&) noexcept = default;
```

### <a name="parameters"></a>parâmetros

*pval*\
O caminho especificado.

*error_code*\
O código de erro especificado.

*opts*\
As opções de diretório especificadas.

*recursive_directory_iterator*\
O `recursive_directory_iterator` do qual o `recursive_directory_iterator` construído é uma cópia.

### <a name="remarks"></a>Comentários

O primeiro construtor produz um iterador de fim de sequência. O segundo e terceiro construtores são armazenados **`false`** no `no_push` e `directory_options::none` no e `myoptions` , em seguida, tentam abrir e ler *PVal* como um diretório. Se for bem-sucedido, eles serão inicializados `mystack` e `myentry` para designar o primeiro nome de arquivo que não seja de diretório na sequência aninhada; caso contrário, eles produzirão um iterador de fim de sequência.

O quarto e o quinto construtores têm o mesmo comportamento que o segundo e o terceiro, exceto que eles primeiro armazenam as *optas* por eles `myoptions` . Os construtores usados como padrão se comportam como esperado.

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[\<filesystem>](../standard-library/filesystem.md)\
[Navegação no sistema de arquivos (C++)](../standard-library/file-system-navigation.md)
