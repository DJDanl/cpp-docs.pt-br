---
title: Classe directory_entry | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
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
dev_langs:
- C++
ms.assetid: 1827c67b-4137-4548-adb0-f955f7acaf08
caps.latest.revision: 17
author: corob-msft
ms.author: corob
manager: ghogen
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
ms.workload:
- cplusplus
ms.openlocfilehash: ba3dc5588cb035cb754ba43a6eeccb37b7ec0b79
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
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

## <a name="assign"></a>assign

```cpp
void assign(const std::experimental::filesystem::path& pval,
    file_status stat_arg = file_status(),
    file_status symstat_arg = file_status());
```

A função de membro atribui pval a mypath, stat a mystat e symstat a mysymstat.

## <a name="directoryentry"></a>directory_entry

```cpp
directory_entry() = default;
directory_entry(const directory_entry&) = default;
directory_entry(directory_entry&&) noexcept = default;
explicit directory_entry(const std::experimental::filesystem::path& pval,
    file_status stat_arg = file_status(),
    file_status symstat_arg = file_status());
```

Os construtores usados como padrão se comportam como esperado. O quarto construtor inicializa mypath em pval, mystat em stat_arg e mysymstat em symstat_arg.

## <a name="operator"></a>operator!=

```cpp
bool operator!=(const directory_entry& right) const noexcept;
```

A função de membro retorna !(*this == right).

## <a name="operator"></a>operator=

```cpp
directory_entry& operator=(const directory_entry&) = default;
directory_entry& operator=(directory_entry&&) noexcept = default;
```

Os operadores de atribuição de membro usados como padrão se comportam como esperado.

## <a name="operator"></a>operator==

```cpp
bool operator==(const directory_entry& right) const noexcept;
```

A função de membro retorna mypath == right.mypath.

## <a name="operatorlt"></a>Operador&lt;

```cpp
bool operator<(const directory_entry& right) const noexcept;
```

A função de membro retorna mypath &lt; right.mypath.

## <a name="operatorlt"></a>operator&lt;=

```cpp
bool operator&lt;=(const directory_entry& right) const noexcept;
```

A função de membro retorna !(right \< *this).

## <a name="operatorgt"></a>Operador&gt;

```cpp
bool operator&gt;(const directory_entry& right) const noexcept;
```

A função de membro retorna right \< *this.

## <a name="operatorgt"></a>operator&gt;=

```cpp
bool operator&gt;=(const directory_entry& right) const noexcept;
```

Retorna a função de membro! (* isso \< direito).

## <a name="operator-const-pathtype"></a>operator const path_type&

```cpp
operator const std::experimental::filesystem::path&() const;
```

O operador de membro retorna mypath.

## <a name="path"></a>path

```cpp
const std::experimental::filesystem::path& path() const noexcept;
```

A função de membro retorna mypath.

## <a name="replacefilename"></a>replace_filename

```cpp
void replace_filename(
    const std::experimental::filesystem::path& pval,
    file_status stat_arg = file_status(),
    file_status symstat_arg = file_status());
```

A função de membro substitui mypath por mypath.parent_path() / pval, mystat por stat_arg e mysymstat por symstat_arg

## <a name="status"></a>status

```cpp
file_status status() const;
file_status status(error_code& ec) const noexcept;
```

Ambas as funções de membro retornam mystat, possivelmente, primeiro alterado da seguinte maneira:

1. Se for status_known(mystat), não realizará nenhuma ação.

1. Caso contrário, se for !status_known(mysymstat) && !is_symlink(mysymstat), será mystat = mysymstat.

## <a name="symlinkstatus"></a>symlink_status

```cpp
file_status symlink_status() const;
file_status symlink_status(error_code& ec) const noexcept;
```

Ambas as funções de membro retornam mysymstat, possivelmente, primeiro alterado da seguinte maneira: se for status_known(mysymstat), nenhuma ação. Caso contrário, mysymstat = symlink_status(mypval).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<experimental/sistema de arquivos&gt;

**Namespace:** std::experimental::filesystem

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[\<filesystem&gt;](../standard-library/filesystem.md)<br/>
