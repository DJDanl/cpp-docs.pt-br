---
title: Classe filesystem_error | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- filesystem/std::experimental::filesystem::filesystem_error
dev_langs:
- C++
ms.assetid: c53aac27-c1fa-43e4-8967-48ea8ba1f172
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e1acf34f8478bc075b53780f1e48df125c22608b
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33845486"
---
# <a name="filesystemerror-class"></a>Classe filesystem_error

Uma classe base para todas as exceções geradas para relatar um estouro de baixo nível no sistema.

## <a name="syntax"></a>Sintaxe

```cpp
class filesystem_error    : public system_error;
```

## <a name="remarks"></a>Comentários

A classe serve como a classe base para todas as exceções geradas para relatar um erro em funções \<filesystem >. Ela armazena um objeto do tipo cadeia de caracteres, chamado mymesg aqui para fins de exposição. Ela também armazena dois objetos do tipo caminho, chamados mypval1 e mypval2.

## <a name="filesystemerrorfilesystemerror"></a>filesystem_error::filesystem_error

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

O primeiro construtor constrói sua mensagem de what_arg e ec. O segundo construtor também constrói sua mensagem de pval1, que armazena em mypval1. O terceiro construtor também constrói sua mensagem de pval1, que armazena em mypval1, em de pval2, que armazena em mypval2.

## <a name="filesystemerrorpath1"></a>filesystem_error::path1

```cpp
const path& path1() const noexcept;
```

A função membro retorna mypval1

## <a name="filesystemerrorpath2"></a>filesystem_error::path2

```cpp
const path& path2() const noexcept;
```

A função membro retorna mypval2

## <a name="filesystemerrorwhat"></a>filesystem_error::what

```cpp
const char *what() const noexcept;
```

A função membro retorna um ponteiro para um NTBS, preferencialmente composto por runtime_error::what(), system_error::what(), mymesg, mypval1.native_string() e mypval2.native_string().

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<filesystem >

**Namespace:** std::experimental::filesystem

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[Classe system_error](../standard-library/system-error-class.md)<br/>
[\<filesystem>](../standard-library/filesystem.md)<br/>
[\<exception>](../standard-library/exception.md)<br/>
