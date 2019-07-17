---
title: Classe filesystem_error
ms.date: 09/10/2018
f1_keywords:
- filesystem/std::experimental::filesystem::filesystem_error
ms.assetid: c53aac27-c1fa-43e4-8967-48ea8ba1f172
ms.openlocfilehash: c3dbfc080f0a1494950016f42189d932be05b0f1
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68240736"
---
# <a name="filesystemerror-class"></a>Classe filesystem_error

Uma classe base para todas as exceções geradas para relatar um estouro de baixo nível no sistema.

## <a name="syntax"></a>Sintaxe

```cpp
class filesystem_error    : public system_error;
```

## <a name="remarks"></a>Comentários

A classe serve como a classe base para todas as exceções geradas para relatar um erro em funções \<filesystem >. Ele armazena um objeto do tipo `string`, chamado `mymesg` aqui para fins de explicação. Ele também armazena dois objetos do tipo `path`, chamado `mypval1` e `mypval2`.

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|||
|-|-|
|[filesystem_error](#filesystem_error)|Constrói um `filesystem_error` mensagem.|

### <a name="functions"></a>Funções

|||
|-|-|
|[path1](#path1)|Retorna `mypval1`|
|[path2](#path2)|Retorna `mypval2`|
|[what](#what)|Retorna um ponteiro para um `NTBS`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<filesystem >

**Namespace:** std::experimental::filesystem

## <a name="filesystem_error"></a> filesystem_error

O primeiro construtor constrói sua mensagem de *what_arg* e *ec*. O segundo construtor também constrói sua mensagem de *pval1*, que armazena em `mypval1`. O terceiro construtor também constrói sua mensagem de *pval1*, que armazena em `mypval1`e de *pval2*, que armazena em `mypval2`.

```cpp
filesystem_error(const string& what_arg,
    error_code ec);

filesystem_error(const string& what_arg,
    const path& pval1,
    error_code ec);

filesystem_error(const string& what_arg,
    const path& pval1,
    const path& pval2,
    error_code ec);
```

### <a name="parameters"></a>Parâmetros

*what_arg*\
Mensagem especificada.

*EC*\
Código de erro especificado.

*mypval1*\
Parâmetro adicional de mensagem especificada.

*mypval2*\
Parâmetro de mensagem especificado ainda mais.

## <a name="path1"></a> path1

A função membro retorna `mypval1`

```cpp
const path& path1() const noexcept;
```

## <a name="path2"></a> path2

A função membro retorna `mypval2`

```cpp
const path& path2() const noexcept;
```

## <a name="what"></a> o que

A função membro retorna um ponteiro para um `NTBS`, preferencialmente composto por `runtime_error::what()`, `system_error::what()`, `mymesg`, `mypval1.native_string()`, e `mypval2.native_string()`.

```cpp
const char *what() const noexcept;
```
