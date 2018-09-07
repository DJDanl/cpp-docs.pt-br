---
title: Classe recursive_directory_iterator | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- filesystem/std::tr2::sys::recursive_directory_iterator
dev_langs:
- C++
ms.assetid: 79a061bd-5b64-404c-97e8-749c888c2ced
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 82df045c5a41767093e690ec35ffeb3d81032474
ms.sourcegitcommit: 761c5f7c506915f5a62ef3847714f43e9b815352
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/07/2018
ms.locfileid: "44110650"
---
# <a name="recursivedirectoryiterator-class"></a>Classe recursive_directory_iterator

Descreve um iterador de entrada que sequencia pelos nomes de arquivo em um diretório, possivelmente em ordem decrescente em subdiretórios, recursivamente. Para um iterador `X`, a expressão `*X` é avaliada como um objeto da classe `directory_entry` que encapsula o nome do arquivo e tudo conhecido sobre seu status.

Para obter mais informações e exemplos de código, consulte [Navegação do Sistema de Arquivos (C++)](../standard-library/file-system-navigation.md).

## <a name="syntax"></a>Sintaxe

```cpp
class recursive_directory_iterator;
```

## <a name="remarks"></a>Comentários

A classe de modelo armazena:

1. um objeto do tipo `stack<pair<directory_iterator, path>>`, chamado `mystack` aqui para fins de exposição, que representa o aninhamento de diretórios a ser sequenciado

1. um objeto do tipo `directory_entry` chamado `myentry` aqui, que representa o nome do arquivo atual na sequência de diretório

1. um objeto do tipo `bool`, chamado `no_push` aqui, que registra se o descendente recursivo em subdiretórios está desabilitado

1. um objeto do tipo `directory_options`, chamado `myoptions` aqui, que registra as opções estabelecidas na construção

Um objeto construído padrão do tipo `recursive_directory_entry` tem um iterador de fim de sequência no `mystack.top().first` e representa o iterador de fim de sequência. Por exemplo, considerando o diretório `abc` com entradas `def` (um diretório), `def/ghi`, e `jkl`, o código:

```cpp
for (recursive_directory_iterator next(path("abc")), end; next != end; ++next)
    visit(next->path());
```

chamará visita com os argumentos `path("abc/def/ghi")` e `path("abc/jkl")`. Você pode qualificar o sequenciamento por meio de uma subárvore de diretório de duas maneiras:

1. Um diretório symlink será verificado somente se você construir um `recursive_directory_iterator` com um `directory_options` argumento cujo valor é `directory_options::follow_directory_symlink`.

1. Se você chamar `disable_recursion_pending` , um diretório subsequente encontrado durante um incremento não será verificado recursivamente.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[recursive_directory_iterator](#recursive_directory_iterator)|Constrói um `recursive_directory_iterator`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[profundidade](#depth)|Retorna `mystack.size() - 1`, então `pval` está na profundidade zero.|
|[disable_recursion_pending](#disable_recursion_pending)|Repositórios **verdadeira** em `no_push`.|
|[increment](#increment)|Avança para o próximo nome de arquivo na sequência.|
|[options](#options)|Retorna `myoptions`.|
|[pop](#pop)|Retorna o próximo objeto.|
|[recursion_pending](#recursion_pending)|Retorna `!no_push`.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operator!=](#op_neq)|Retorna `!(*this == right)`.|
|[operator=](#op_as)|Os operadores de atribuição de membro usados como padrão se comportam como esperado.|
|[operator==](#op_eq)|Retorna **verdadeira** somente se os dois `*this` e *direita* forem iteradores de fim de sequência ou ambos são não fim-de-sequência-iteradores.|
|[operator*](#op_multiply)|Retorna `myentry`.|
|[operator->](#op_cast)|Retorna `&**this`.|
|[operator++](#op_increment)|Incrementa o `recursive_directory_iterator`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<filesystem >

**Namespace:** std::tr2::sys

## <a name="depth"></a> recursive_directory_iterator::Depth

Retorna `mystack.size() - 1`, então `pval` está na profundidade zero.

```cpp
int depth() const;
```

## <a name="disable_recursion_pending"></a> recursive_directory_iterator::disable_recursion_pending

Repositórios **verdadeira** em `no_push`.

```cpp
void disable_recursion_pending();
```

## <a name="increment"></a> recursive_directory_iterator::Increment

Avança para o próximo nome de arquivo na sequência.

```cpp
recursive_directory_iterator& increment(error_code& ec) noexcept;
```

### <a name="parameters"></a>Parâmetros

*EC*<br/>
Código de erro especificado.

### <a name="remarks"></a>Comentários

A função tenta avançar para o próximo nome de arquivo na sequência aninhada. Se for bem-sucedido, ela armazenará esse nome de arquivo no `myentry`; caso contrário, ele produz um iterador de fim de sequência.

## <a name="op_neq"></a> recursive_directory_iterator:: Operator! =

Retorna `!(*this == right)`.

```cpp
bool operator!=(const recursive_directory_iterator& right) const;
```

### <a name="parameters"></a>Parâmetros

*right*<br/>
O [recursive_directory_iterator](../standard-library/recursive-directory-iterator-class.md) para comparação.

## <a name="op_as"></a> recursive_directory_iterator:: Operator =

Os operadores de atribuição de membro usados como padrão se comportam como esperado.

```cpp
recursive_directory_iterator& operator=(const recursive_directory_iterator&) = default;
recursive_directory_iterator& operator=(recursive_directory_iterator&&) noexcept = default;
```

### <a name="parameters"></a>Parâmetros

*recursive_directory_iterator*<br/>
O [recursive_directory_iterator](../standard-library/recursive-directory-iterator-class.md) que está sendo copiado para o `recursive_directory_iterator`.

## <a name="op_eq"></a> recursive_directory_iterator:: Operator = =

Retorna **verdadeira** somente se os dois `*this` e *direita* forem iteradores de fim de sequência ou ambos são não fim-de-sequência-iteradores.

```cpp
bool operator==(const recursive_directory_iterator& right) const;
```

### <a name="parameters"></a>Parâmetros

*right*<br/>
O [recursive_directory_iterator](../standard-library/recursive-directory-iterator-class.md) para comparação.

## <a name="op_multiply"></a> recursive_directory_iterator:: Operator *

Retorna `myentry`.

```cpp
const directory_entry& operator*() const;
```

## <a name="op_cast"></a> recursive_directory_iterator:: Operator ->

Retorna `&**this`.

```cpp
const directory_entry * operator->() const;
```

## <a name="op_increment"></a> recursive_directory_iterator:: Operator + +

Incrementa o `recursive_directory_iterator`.

```cpp
recursive_directory_iterator& operator++();

recursive_directory_iterator& operator++(int);
```

### <a name="parameters"></a>Parâmetros

*int*<br/>
O incremento especificado.

### <a name="remarks"></a>Comentários

A primeira função membro chamará `increment()`, em seguida, retorna `*this`. A segunda função membro faz uma cópia do objeto, chamadas `increment()`, em seguida, retorna a cópia.

## <a name="options"></a> recursive_directory_iterator::Options

Retorna `myoptions`.

```cpp
directory_options options() const;
```

## <a name="pop"></a> recursive_directory_iterator:: pop

Retorna o próximo objeto.

```cpp
void pop();
```

### <a name="remarks"></a>Comentários

Se `depth() == 0` o objeto se torna um iterador de fim de sequência. Caso contrário, a função de membro termina a varredura do diretório atual (mais profundo) e retoma no próximo nível inferior.

## <a name="recursion_pending"></a> recursive_directory_iterator::recursion_pending

Retorna `!no_push`.

```cpp
bool recursion_pending() const;
```

## <a name="recursive_directory_iterator"></a> recursive_directory_iterator::recursive_directory_iterator

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

### <a name="parameters"></a>Parâmetros

*PVal*<br/>
O caminho especificado.

*error_code*<br/>
O código de erro especificada.

*aceita o*<br/>
As opções de diretório especificado.

*recursive_directory_iterator*<br/>
O `recursive_directory_iterator` do qual o `recursive_directory_iterator` construído é uma cópia.

### <a name="remarks"></a>Comentários

O primeiro construtor produz um iterador de fim de sequência. O repositório de segundo e terceiro construtores **falso** no `no_push` e `directory_options::none` no `myoptions`, em seguida, tentar abrir e ler *pval* como um diretório. Se for bem-sucedido, eles inicializam `mystack` e `myentry` para designar o primeiro nome de arquivo não diretório na sequência aninhada; caso contrário, produzirão um iterador de fim de sequência.

Os quarto e quintas construtores se comportam da mesma como o segundo e terceiro, exceto pelo fato de que eles primeiro armazenam *opts* em `myoptions`. Os construtores usados como padrão se comportam como esperado.

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[\<filesystem>](../standard-library/filesystem.md)<br/>
[Navegação no sistema de arquivos (C++)](../standard-library/file-system-navigation.md)<br/>
