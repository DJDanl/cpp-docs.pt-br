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
ms.openlocfilehash: a7ccc2a941da079e14092af5b81dc537db4a48c0
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87215771"
---
# <a name="directory_iterator-class"></a>Classe directory_iterator

Descreve um iterador de entrada que percorre em sequência os nomes de arquivo em um diretório. Para um iterador `X` , a expressão `*X` é avaliada como um objeto da classe `directory_entry` que encapsula o nome do arquivo e qualquer coisa conhecida sobre seu status.

A classe armazena um objeto do tipo `path` , chamado `mydir` aqui para fins de exposição, que representa o nome do diretório a ser sequenciado, e um objeto do tipo `directory_entry` chamado `myentry` aqui, que representa o nome de arquivo atual na sequência de diretórios. Um objeto construído padrão do tipo `directory_entry` tem um `mydir` nome de caminho vazio e representa o iterador de fim de sequência.

Por exemplo, considerando o diretório `abc` com entradas `def` e `ghi` o código:

`for (directory_iterator next(path("abc")), end; next != end; ++next)     visit(next->path());`

chamará `visit` com os argumentos `path("abc/def")` e `path("abc/ghi")` .

Para obter mais informações e exemplos de código, consulte [Navegação do Sistema de Arquivos (C++)](../standard-library/file-system-navigation.md).

## <a name="syntax"></a>Sintaxe

```cpp
class directory_iterator;
```

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[directory_iterator](#directory_iterator)|Constrói um iterador de entrada que é sequenciado pelos nomes de dados em um diretório.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[increment](#increment)|Tenta avançar para o próximo nome de arquivo no diretório.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operador! =](#op_neq)|Retorna `!(*this == right)`.|
|[operador =](#op_as)|Os operadores de atribuição de membro usados como padrão se comportam como esperado.|
|[operador = =](#op_eq)|Retorna **`true`** somente se o **`*this`** e o *direito* forem iteradores de fim de sequência ou ambos não forem de fim de sequência-iteradores.|
|[operador](#op_star)|Retorna `myentry`.|
|[operador->](#op_cast)|Retorna `&**this`.|
|[operador + +](#op_increment)|Chama, `increment()` em seguida **`*this`** , retorna ou faz uma cópia do objeto, chama `increment()` e, em seguida, retorna a cópia.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<experimental/filesystem>

**Namespace:** std::experimental::filesystem

## <a name="directory_iteratordirectory_iterator"></a><a name="directory_iterator"></a>directory_iterator::d irectory_iterator

O primeiro construtor produz um iterador de fim de sequência. O segundo e terceiro construtores armazenam *PVal* em e, `mydir` em seguida, tentam abrir e ler `mydir` como um diretório. Se for bem-sucedido, eles armazenarão o primeiro nome de arquivo no diretório em `myentry` ; caso contrário, eles produzirão um iterador de fim de sequência.

Os construtores usados como padrão se comportam como esperado.

```cpp
directory_iterator() noexcept;
explicit directory_iterator(const path& pval);

directory_iterator(const path& pval, error_code& ec) noexcept;
directory_iterator(const directory_iterator&) = default;
directory_iterator(directory_iterator&&) noexcept = default;
```

### <a name="parameters"></a>parâmetros

*pval*\
O caminho do nome de arquivo armazenado.

*Comunidade*\
O código de erro de status.

*directory_iterator*\
O objeto armazenado.

## <a name="directory_iteratorincrement"></a><a name="increment"></a>directory_iterator:: incremento

A função tenta avançar para o próximo nome de arquivo no diretório. Se for bem-sucedido, ele armazenará esse nome de arquivo em `myentry` ; caso contrário, ele produzirá um iterador de fim de sequência.

```cpp
directory_iterator& increment(error_code& ec) noexcept;
```

## <a name="directory_iteratoroperator"></a><a name="op_neq"></a>directory_iterator:: Operator! =

O operador de membro retorna `!(*this == right)`.

```cpp
bool operator!=(const directory_iterator& right) const;
```

### <a name="parameters"></a>parâmetros

*Certo*\
O [directory_iterator](../standard-library/directory-iterator-class.md) sendo comparado com o `directory_iterator` .

## <a name="directory_iteratoroperator"></a><a name="op_as"></a>directory_iterator:: Operator =

Os operadores de atribuição de membro usados como padrão se comportam como esperado.

```cpp
directory_iterator& operator=(const directory_iterator&) = default;
directory_iterator& operator=(directory_iterator&&) noexcept = default;
```

### <a name="parameters"></a>parâmetros

*Certo*\
O [directory_iterator](../standard-library/directory-iterator-class.md) sendo copiado para o `directory_iterator` .

## <a name="directory_iteratoroperator"></a><a name="op_eq"></a>directory_iterator:: Operator = =

O operador de membro retornará **`true`** apenas se ambos **`*this`** e *direitos* forem iteradores de fim de sequência ou ambos não forem de fim de sequência-iteradores.

```cpp
bool operator==(const directory_iterator& right) const;
```

### <a name="parameters"></a>parâmetros

*Certo*\
O [directory_iterator](../standard-library/directory-iterator-class.md) sendo comparado com o `directory_iterator` .

## <a name="directory_iteratoroperator"></a><a name="op_star"></a>directory_iterator:: Operator *

O operador de membro retorna `myentry`.

```cpp
const directory_entry& operator*() const;
```

## <a name="directory_iteratoroperator-"></a><a name="op_cast"></a>operador directory_iterator:: Operator->

A função membro retorna `&**this`.

```cpp
const directory_entry * operator->() const;
```

## <a name="directory_iteratoroperator"></a><a name="op_increment"></a>directory_iterator:: operador + +

A primeira chamada de função de membro `increment()` , em seguida, retorna **`*this`** . A segunda função de membro faz uma cópia do objeto, chama `increment()` e, em seguida, retorna a cópia.

```cpp
directory_iterator& operator++();
directory_iterator& operator++(int);
```

### <a name="parameters"></a>parâmetros

*inteiro*\
O número de incrementos.

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[\<filesystem>](../standard-library/filesystem.md)\
[Navegação no sistema de arquivos (C++)](../standard-library/file-system-navigation.md)
