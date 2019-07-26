---
title: Classe directory_entry
ms.date: 09/10/2018
f1_keywords:
- filesystem/std::experimental::filesystem::directory_entry
- filesystem/std::experimental::filesystem::directory_entry::operator const std::experimental::filesystem::path &
- filesystem/std::experimental::filesystem::directory_entry::directory_entry
- filesystem/std::experimental::filesystem::directory_entry::operator=
- filesystem/std::experimental::filesystem::directory_entry::assign
- filesystem/std::experimental::filesystem::directory_entry::replace_filename
- filesystem/std::experimental::filesystem::directory_entry::path
- filesystem/std::experimental::filesystem::directory_entry::status
- filesystem/std::experimental::filesystem::directory_entry::symlink_status
- filesystem/std::experimental::filesystem::directory_entry::operator&lt;
- filesystem/std::experimental::filesystem::directory_entry::operator==
- filesystem/std::experimental::filesystem::directory_entry::operator!=
- filesystem/std::experimental::filesystem::directory_entry::operator&lt;=
- filesystem/std::experimental::filesystem::directory_entry::operator&gt;
- filesystem/std::experimental::filesystem::directory_entry::operator&gt;=
ms.assetid: 1827c67b-4137-4548-adb0-f955f7acaf08
helpviewer_keywords:
- std::experimental::filesystem::directory_entry
- std::experimental::filesystem::directory_entry::operator const std::experimental::filesystem::path &
- std::experimental::filesystem::directory_entry::directory_entry
- std::experimental::filesystem::directory_entry::operator=
- std::experimental::filesystem::directory_entry::assign
- std::experimental::filesystem::directory_entry::replace_filename
- std::experimental::filesystem::directory_entry::path
- std::experimental::filesystem::directory_entry::status
- std::experimental::filesystem::directory_entry::symlink_status
- std::experimental::filesystem::directory_entry::operator&lt;
- std::experimental::filesystem::directory_entry::operator==
- std::experimental::filesystem::directory_entry::operator!=
- std::experimental::filesystem::directory_entry::operator&lt;=
- std::experimental::filesystem::directory_entry::operator&gt;
- std::experimental::filesystem::directory_entry::operator&gt;=
ms.openlocfilehash: 35b0dc55bf5db2f799d9ade28cd5968ceab3332b
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68458953"
---
# <a name="directoryentry-class"></a>Classe directory_entry

Descreve um objeto que é retornado por `*X`, em que *X* é um [directory_iterator](../standard-library/directory-iterator-class.md) ou um [recursive_directory_iterator](../standard-library/recursive-directory-iterator-class.md).

## <a name="syntax"></a>Sintaxe

```cpp
class directory_entry;
```

## <a name="remarks"></a>Comentários

A classe armazena um objeto do tipo [path](../standard-library/path-class.md). O `path` armazenado pode ser uma instância da [Classe path](../standard-library/path-class.md) ou de um tipo derivado de `path`. Ele também armazena dois valores [file_type](../standard-library/filesystem-enumerations.md#file_type): um que representa o que é conhecido sobre o status do nome do arquivo armazenado e outro que representa o que é conhecido sobre o status do link simbólico do nome do arquivo.

Para obter mais informações e exemplos de código, consulte [Navegação do Sistema de Arquivos (C++)](../standard-library/file-system-navigation.md).

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[directory_entry](#directory_entry)|Os construtores usados como padrão se comportam como esperado. O quarto construtor inicializa `mypath` para *PVal*, `mystat` para *stat_arg*e `mysymstat` para *symstat_arg*.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[assign](#assign)|A função de membro atribui *PVal* a `mypath`, *stat* to `mystat`e *symstat* a `mysymstat`.|
|[path](#path)|A função membro retorna `mypath`.|
|[replace_filename](#replace_filename)|A função membro substitui `mypath` por `mypath.parent_path()`  /  *PVal* ,`mystat` por *stat_arg* e`mysymstat` por *symstat_arg*|
|[status](#status)|Ambas as funções de `mystat` membro retornam possivelmente alteradas pela primeira vez.|
|[symlink_status](#symlink_status)|Ambas as funções de `mysymstat` membro retornam possivelmente alteradas pela primeira vez.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operator!=](#op_neq)|Substitui os elementos da lista por uma cópia de outra lista.|
|[operator=](#op_as)|Os operadores de atribuição de membro usados como padrão se comportam como esperado.|
|[operator==](#op_eq)|Retorna `mypath == right.mypath`.|
|[operator<](#op_lt)|Retorna `mypath < right.mypath`.|
|[operator<=](#op_lteq)|Retorna `!(right < *this)`.|
|[operator>](#op_gt)|Retorna `right < *this`.|
|[operator>=](#op_gteq)|Retorna `!(*this < right)`.|
|[operador const path_type &](#path_type)|Retorna `mypath`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<experimental/sistema de arquivos&gt;

**Namespace:** std::experimental::filesystem

## <a name="assign"></a>Cancele

A função membro atribui *PVal* a `mypath`, *stat_arg* para `mystat`e symstat_arg para.  `mysymstat`

```cpp
void assign(const std::experimental::filesystem::path& pval,
    file_status stat_arg = file_status(),
    file_status symstat_arg = file_status());
```

### <a name="parameters"></a>Parâmetros

*pval*\
O caminho do nome de arquivo armazenado.

*stat_arg*\
O status do nome do arquivo armazenado.

*symstat_arg*\
O status do link simbólico do nome do arquivo armazenado.

## <a name="directory_entry"></a> directory_entry

Os construtores usados como padrão se comportam como esperado. O quarto construtor inicializa `mypath` para *PVal*, `mystat` para *stat_arg*e `mysymstat` para *symstat_arg*.

```cpp
directory_entry() = default;
directory_entry(const directory_entry&) = default;
directory_entry(directory_entry&&) noexcept = default;
explicit directory_entry(const std::experimental::filesystem::path& pval,
    file_status stat_arg = file_status(),
    file_status symstat_arg = file_status());
```

### <a name="parameters"></a>Parâmetros

*pval*\
O caminho do nome de arquivo armazenado.

*stat_arg*\
O status do nome do arquivo armazenado.

*symstat_arg*\
O status do link simbólico do nome do arquivo armazenado.

## <a name="op_neq"></a>operador! =

A função membro retorna `!(*this == right)`.

```cpp
bool operator!=(const directory_entry& right) const noexcept;
```

### <a name="parameters"></a>Parâmetros

*Certo*\
O [directory_entry](../standard-library/directory-entry-class.md) que está sendo comparado `directory_entry`com o.

## <a name="op_as"></a>operador =

Os operadores de atribuição de membro usados como padrão se comportam como esperado.

```cpp
directory_entry& operator=(const directory_entry&) = default;
directory_entry& operator=(directory_entry&&) noexcept = default;
```

### <a name="parameters"></a>Parâmetros

*Certo*\
O [directory_entry](../standard-library/directory-entry-class.md) que está sendo copiado para o `directory_entry`.

## <a name="op_eq"></a>operador = =

A função membro retorna `mypath == right.mypath`.

```cpp
bool operator==(const directory_entry& right) const noexcept;
```

### <a name="parameters"></a>Parâmetros

*Certo*\
O [directory_entry](../standard-library/directory-entry-class.md) que está sendo comparado `directory_entry`com o.

## <a name="op_lt"></a> Operador&lt;

A função membro retorna `mypath < right.mypath`.

```cpp
bool operator<(const directory_entry& right) const noexcept;
```

### <a name="parameters"></a>Parâmetros

*Certo*\
O [directory_entry](../standard-library/directory-entry-class.md) que está sendo comparado `directory_entry`com o.

## <a name="op_lteq"></a> operador&lt;=

A função membro retorna `!(right < *this)`.

```cpp
bool operator&lt;=(const directory_entry& right) const noexcept;
```

### <a name="parameters"></a>Parâmetros

*Certo*\
O [directory_entry](../standard-library/directory-entry-class.md) que está sendo comparado `directory_entry`com o.

## <a name="op_gt"></a> Operador&gt;

A função membro retorna `right < *this`.

```cpp
bool operator&gt;(const directory_entry& right) const noexcept;
```

### <a name="parameters"></a>Parâmetros

*Certo*\
O [directory_entry](../standard-library/directory-entry-class.md) que está sendo comparado `directory_entry`com o.

## <a name="op_gteq"></a> operador&gt;=

A função membro retorna `!(*this < right)`.

```cpp
bool operator&gt;=(const directory_entry& right) const noexcept;
```

### <a name="parameters"></a>Parâmetros

*Certo*\
O [directory_entry](../standard-library/directory-entry-class.md) que está sendo comparado `directory_entry`com o.

## <a name="path_type"></a>operador const path_type &

O operador de membro retorna `mypath`.

```cpp
operator const std::experimental::filesystem::path&() const;
```

## <a name="path"></a>Multi-Path

A função membro retorna `mypath`.

```cpp
const std::experimental::filesystem::path& path() const noexcept;
```

## <a name="replace_filename"></a>replace_filename

A função membro substitui `mypath` por `mypath.parent_path()`  /  *PVal* ,`mystat` por *stat_arg* e`mysymstat` por *symstat_arg*

```cpp
void replace_filename(
    const std::experimental::filesystem::path& pval,
    file_status stat_arg = file_status(),
    file_status symstat_arg = file_status());
```

### <a name="parameters"></a>Parâmetros

*pval*\
O caminho do nome de arquivo armazenado.

*stat_arg*\
O status do nome do arquivo armazenado.

*symstat_arg*\
O status do link simbólico do nome do arquivo armazenado.

## <a name="status"></a>Estado

Ambas as funções de `mystat` membro retornam possivelmente alteradas pela seguinte maneira:

1. Se `status_known(mystat)` não fizer nada.

1. Caso contrário, `!status_known(mysymstat) && !is_symlink(mysymstat)` se `mystat = mysymstat`for.

```cpp
file_status status() const;
file_status status(error_code& ec) const noexcept;
```

### <a name="parameters"></a>Parâmetros

*Comunidade*\
O código de erro de status.

## <a name="symlink_status"></a>symlink_status

Ambas as funções de `mysymstat` membro retornam possivelmente alteradas pela seguinte maneira: Se `status_known(mysymstat)` não fizer nada. Caso contrário, `mysymstat = symlink_status(mypval)`.

```cpp
file_status symlink_status() const;
file_status symlink_status(error_code& ec) const noexcept;
```

### <a name="parameters"></a>Parâmetros

*Comunidade*\
O código de erro de status.

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[\<filesystem&gt;](../standard-library/filesystem.md)
