---
title: Classe directory_iterator
ms.date: 09/10/2018
f1_keywords:
- filesystem/std::experimental::filesystem::directory_iterator
- filesystem/std::experimental::filesystem::_Directory_iterator::_Directory_iterator
- filesystem/std::experimental::filesystem::directory_iterator::directory_iterator
- filesystem/std::experimental::filesystem::directory_iterator::increment
- filesystem/std::experimental::filesystem::directory_iterator::operator=
- filesystem/std::experimental::filesystem::directory_iterator::operator==
- filesystem/std::experimental::filesystem::directory_iterator::operator!=
- filesystem/std::experimental::filesystem::directory_iterator::operator*
- filesystem/std::experimental::filesystem::directory_iterator::operator-&gt;
- filesystem/std::experimental::filesystem::directory_iterator::operator++
ms.assetid: dca2ecf8-3e69-4644-a83d-705061e10cc8
helpviewer_keywords:
- std::experimental::filesystem::directory_iterator
- std::experimental::filesystem::_Directory_iterator::_Directory_iterator
- std::experimental::filesystem::directory_iterator
- std::experimental::filesystem::directory_iterator::directory_iterator
- std::experimental::filesystem::directory_iterator::increment
- std::experimental::filesystem::directory_iterator::operator=
- std::experimental::filesystem::directory_iterator::operator==
- std::experimental::filesystem::directory_iterator::operator!=
- std::experimental::filesystem::directory_iterator::operator*
- std::experimental::filesystem::directory_iterator::operator-&gt;
- std::experimental::filesystem::directory_iterator::operator++
ms.openlocfilehash: 6763f2a96b771fadbec311cf8740352fff53e29a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50610185"
---
# <a name="directoryiterator-class"></a>Classe directory_iterator

Descreve um iterador de entrada que percorre em sequência os nomes de arquivo em um diretório. Para um iterador `X`, a expressão `*X` é avaliada como um objeto da classe `directory_entry` que encapsula o nome do arquivo e tudo conhecido sobre seu status.

A classe armazena um objeto do tipo `path`, chamado `mydir` aqui para fins de exposição, que representa o nome do diretório a ser sequenciado, e um objeto do tipo `directory_entry` chamado `myentry` aqui, que representa o atual nome do arquivo na sequência de diretório. Um objeto construído padrão do tipo `directory_entry` possui um vazio `mydir` pathname e representa o iterador de fim de sequência.

Por exemplo, considerando o diretório `abc` com entradas `def` e `ghi`, o código:

`for (directory_iterator next(path("abc")), end; next != end; ++next)     visit(next->path());`

chamará `visit` com os argumentos `path("abc/def")` e `path("abc/ghi")`.

Para obter mais informações e exemplos de código, consulte [Navegação do Sistema de Arquivos (C++)](../standard-library/file-system-navigation.md).

## <a name="syntax"></a>Sintaxe

```cpp
class directory_iterator;
```

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[directory_iterator](#directory_iterator)|Constrói um iterador de entrada que sequencia pelos nomes de arquivo em um diretório.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[increment](#increment)|Tenta Avançar para o próximo nome de arquivo no diretório.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operator!=](#op_neq)|Retorna `!(*this == right)`.|
|[operator=](#op_as)|Os operadores de atribuição de membro usados como padrão se comportam como esperado.|
|[operator==](#op_eq)|Retorna **verdadeira** somente se os dois `*this` e *direita* forem iteradores de fim de sequência ou ambos são não fim-de-sequência-iteradores.|
|[operator*](#op_star)|Retorna `myentry`.|
|[operator->](#op_cast)|Retorna `&**this`.|
|[operator++](#op_increment)|Chamadas `increment()`, em seguida, retorna `*this`, ou faz uma cópia do objeto, chamadas `increment()`, em seguida, retorna a cópia.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<experimental/filesystem>

**Namespace:** std::experimental::filesystem

## <a name="directory_iterator"></a> directory_iterator::directory_iterator

O primeiro construtor produz um iterador de fim de sequência. O repositório de segundo e terceiro construtores *pval* na `mydir`, em seguida, tentar abrir e ler `mydir` como um diretório. Se for bem-sucedido, eles armazenam o primeiro nome de arquivo no diretório em `myentry`; caso contrário, produzirão um iterador de fim de sequência.

Os construtores usados como padrão se comportam como esperado.

```cpp
directory_iterator() noexcept;
explicit directory_iterator(const path& pval);

directory_iterator(const path& pval, error_code& ec) noexcept;
directory_iterator(const directory_iterator&) = default;
directory_iterator(directory_iterator&&) noexcept = default;
```

### <a name="parameters"></a>Parâmetros

*PVal*<br/>
O caminho do nome de arquivo armazenado.

*EC*<br/>
O código de erro de status.

*directory_iterator*<br/>
O objeto armazenado.

## <a name="increment"></a> directory_iterator::Increment

A função tenta avançar para o próximo nome de arquivo no diretório. Se for bem-sucedido, ela armazenará esse nome de arquivo no `myentry`; caso contrário, ele produz um iterador de fim de sequência.

```cpp
directory_iterator& increment(error_code& ec) noexcept;
```

## <a name="op_neq"></a> directory_iterator:: Operator! =

O operador de membro retorna `!(*this == right)`.

```cpp
bool operator!=(const directory_iterator& right) const;
```

### <a name="parameters"></a>Parâmetros

*right*<br/>
O [directory_iterator](../standard-library/directory-iterator-class.md) que estão sendo comparados para o `directory_iterator`.

## <a name="op_as"></a> directory_iterator:: Operator =

Os operadores de atribuição de membro usados como padrão se comportam como esperado.

```cpp
directory_iterator& operator=(const directory_iterator&) = default;
directory_iterator& operator=(directory_iterator&&) noexcept = default;
```

### <a name="parameters"></a>Parâmetros

*right*<br/>
O [directory_iterator](../standard-library/directory-iterator-class.md) que está sendo copiado para o `directory_iterator`.

## <a name="op_eq"></a> directory_iterator:: Operator = =

O operador de membro retorna **verdadeira** somente se os dois `*this` e *direita* forem iteradores de fim de sequência ou ambos são não fim-de-sequência-iteradores.

```cpp
bool operator==(const directory_iterator& right) const;
```

### <a name="parameters"></a>Parâmetros

*right*<br/>
O [directory_iterator](../standard-library/directory-iterator-class.md) que estão sendo comparados para o `directory_iterator`.

## <a name="op_star"></a> directory_iterator:: Operator *

O operador de membro retorna `myentry`.

```cpp
const directory_entry& operator*() const;
```

## <a name="op_cast"></a> directory_iterator:: Operator ->

A função membro retorna `&**this`.

```cpp
const directory_entry * operator->() const;
```

## <a name="op_increment"></a> directory_iterator:: Operator + +

A primeira função membro chamará `increment()`, em seguida, retorna `*this`. A segunda função membro faz uma cópia do objeto, chamadas `increment()`, em seguida, retorna a cópia.

```cpp
directory_iterator& operator++();
directory_iterator& operator++(int);
```

### <a name="parameters"></a>Parâmetros

*int*<br/>
O número de incrementos.

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[\<filesystem>](../standard-library/filesystem.md)<br/>
[Navegação no sistema de arquivos (C++)](../standard-library/file-system-navigation.md)<br/>
