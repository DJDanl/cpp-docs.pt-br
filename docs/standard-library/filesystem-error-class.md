---
title: Classe filesystem_error
ms.date: 09/10/2018
f1_keywords:
- filesystem/std::experimental::filesystem::filesystem_error
ms.assetid: c53aac27-c1fa-43e4-8967-48ea8ba1f172
ms.openlocfilehash: add1e0da43a44c35f39c96e8d65e36aeea0d3afb
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50628976"
---
# <a name="filesystemerror-class"></a>Classe filesystem_error

Uma classe base para todas as exceções geradas para relatar um estouro de baixo nível no sistema.

## <a name="syntax"></a>Sintaxe

```cpp
class filesystem_error    : public system_error;
```

## <a name="remarks"></a>Comentários

A classe serve como a classe base para todas as exceções geradas para relatar um erro em funções \<filesystem >. Ele armazena um objeto do tipo `string`, chamado `mymesg` aqui para fins de explicação. Ele também armazena dois objetos do tipo `path`, chamado `mypval1` e `mypval2`.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[filesystem_error](#filesystem_error)|Constrói um `filesystem_error` mensagem.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[path1](#path1)|Retorna `mypval1`|
|[path2](#path2)|Retorna `mypval2`|
|[o que](#what)|Retorna um ponteiro para um `NTBS`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<filesystem >

**Namespace:** std::experimental::filesystem

## <a name="filesystem_error"></a> filesystem_error:: filesystem_error

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

*what_arg*<br/>
Mensagem especificada.

*EC*<br/>
Código de erro especificado.

*mypval1*<br/>
Parâmetro adicional de mensagem especificada.

*mypval2*<br/>
Parâmetro de mensagem especificado ainda mais.

## <a name="path1"></a> filesystem_error::path1

A função membro retorna `mypval1`

```cpp
const path& path1() const noexcept;
```

## <a name="path2"></a> filesystem_error::path2

A função membro retorna `mypval2`

```cpp
const path& path2() const noexcept;
```

## <a name="what"></a> filesystem_error::What

A função membro retorna um ponteiro para um `NTBS`, preferencialmente composto por `runtime_error::what()`, `system_error::what()`, `mymesg`, `mypval1.native_string()`, e `mypval2.native_string()`.

```cpp
const char *what() const noexcept;
```

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[Classe system_error](../standard-library/system-error-class.md)<br/>
[\<filesystem>](../standard-library/filesystem.md)<br/>
[\<exception>](../standard-library/exception.md)<br/>
