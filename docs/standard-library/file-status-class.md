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
ms.openlocfilehash: 60ced1f60c811f585928f47c6cfd5e695d0c4085
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68457747"
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
|[file_status](#file_status)|Constrói um wrapper para [file_type](../standard-library/filesystem-enumerations.md#file_type) e arquivo [perms](../standard-library/filesystem-enumerations.md#perms).|

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

**Cabeçalho:** \<> do sistema de arquivos

**Namespace:** std::experimental::filesystem, std::experimental::filesystem

## <a name="file_status"></a> file_status::file_status

Constrói um wrapper para [file_type](../standard-library/filesystem-enumerations.md#file_type) e arquivo [perms](../standard-library/filesystem-enumerations.md#perms).

```cpp
explicit file_status(
   file_type ftype = file_type::none,
   perms mask = perms::unknown) noexcept;

file_status(const file_status&) noexcept = default;

file_status(file_status&&) noexcept = default;

~file_status() noexcept = default;
```

### <a name="parameters"></a>Parâmetros

*fType*\
Especificado `file_type`, o padrão é `file_type::none`.

*mascara*\
Arquivo `perms`especificado, o padrão é `perms::unknown`.

*file_status*\
O objeto armazenado.

## <a name="op_as"></a> file_status::operator=

Os operadores de atribuição de membro usados como padrão se comportam como esperado.

```cpp
file_status& operator=(const file_status&) noexcept = default;
file_status& operator=(file_status&&) nexcept = default;
```

### <a name="parameters"></a>Parâmetros

*file_status*\
O [file_status](../standard-library/file-status-class.md) que está sendo copiado para o `file_status`.

## <a name="type"></a>Escreva

Obtém ou define o `file_type`.

```cpp
file_type type() const noexcept
void type(file_type ftype) noexcept
```

### <a name="parameters"></a>Parâmetros

*fType*\
Especificado `file_type`.

## <a name="permissions"></a>permissões

Obtém ou define as permissões de arquivo.

Use o setter para criar um arquivo `readonly` ou remover o `readonly` atributo.

```cpp
perms permissions() const noexcept
void permissions(perms mask) noexcept
```

### <a name="parameters"></a>Parâmetros

*mascara*\
Especificado `perms`.

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Classe path](../standard-library/path-class.md)\
[\<filesystem>](../standard-library/filesystem.md)
