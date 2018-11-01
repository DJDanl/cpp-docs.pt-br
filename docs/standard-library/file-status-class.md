---
title: Classe file_status
ms.date: 09/10/2018
f1_keywords:
- filesystem/std::experimental::filesystem::file_status
- filesystem/std::experimental::filesystem::file_status::operator=
- filesystem/std::experimental::filesystem::file_status::type
- filesystem/std::experimental::filesystem::file_status::permissions
ms.assetid: 9781840e-ad22-44dd-ad79-0fabaa94bac4
helpviewer_keywords:
- std::experimental::filesystem::file_status
- std::experimental::filesystem::file_status::operator=
- std::experimental::filesystem::file_status::type
- std::experimental::filesystem::file_status::permissions
ms.openlocfilehash: 81ce4ecc1673087db8e985f94e297798dd712a6e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50630614"
---
# <a name="filestatus-class"></a>Classe file_status

Encapsula um [file_type](../standard-library/filesystem-enumerations.md#file_type) e [perms](../standard-library/filesystem-enumerations.md#perms) de arquivo.

## <a name="syntax"></a>Sintaxe

```cpp
class file_status;
```

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[file_status](#file_status)|Constrói um wrapper para [file_type](../standard-library/filesystem-enumerations.md#file_type) e o arquivo [perms](../standard-library/filesystem-enumerations.md#perms).|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[type](#type)|Obtém ou define o `file_type`.|
|[permissions](#permissions)|Obtém ou define as permissões de arquivo.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operator=](#op_as)|Os operadores de atribuição de membro usados como padrão se comportam como esperado.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<filesystem >

**Namespace:** std::experimental::filesystem, std::experimental::filesystem

## <a name="file_status"></a> file_status:: file_status

Constrói um wrapper para [file_type](../standard-library/filesystem-enumerations.md#file_type) e o arquivo [perms](../standard-library/filesystem-enumerations.md#perms).

```cpp
explicit file_status(
   file_type ftype = file_type::none,
   perms mask = perms::unknown) noexcept;

file_status(const file_status&) noexcept = default;

file_status(file_status&&) noexcept = default;

~file_status() noexcept = default;
```

### <a name="parameters"></a>Parâmetros

*ftype*<br/>
Especificado `file_type`, o padrão é `file_type::none`.

*Máscara*<br/>
Arquivo especificado `perms`, o padrão é `perms::unknown`.

*file_status*<br/>
O objeto armazenado.

## <a name="op_as"></a> file_status::Operator =

Os operadores de atribuição de membro usados como padrão se comportam como esperado.

```cpp
file_status& operator=(const file_status&) noexcept = default;
file_status& operator=(file_status&&) nexcept = default;
```

### <a name="parameters"></a>Parâmetros

*file_status*<br/>
O [file_status](../standard-library/file-status-class.md) que está sendo copiado para o `file_status`.

## <a name="type"></a> Tipo

Obtém ou define o `file_type`.

```cpp
file_type type() const noexcept
void type(file_type ftype) noexcept
```

### <a name="parameters"></a>Parâmetros

*ftype*<br/>
Especificado `file_type`.

## <a name="permissions"></a> Permissões

Obtém ou define as permissões de arquivo.

Use o setter para tornar um arquivo `readonly` ou remova o `readonly` atributo.

```cpp
perms permissions() const noexcept
void permissions(perms mask) noexcept
```

### <a name="parameters"></a>Parâmetros

*Máscara*<br/>
Especificado `perms`.

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[Classe path](../standard-library/path-class.md)<br/>
[\<filesystem>](../standard-library/filesystem.md)<br/>
