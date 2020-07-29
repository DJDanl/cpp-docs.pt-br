---
title: Descrição do argumento
ms.date: 11/04/2016
helpviewer_keywords:
- envp argument
- main function, syntax
- arguments [C++], for main function
- argv argument
- argc argument
ms.assetid: 91c2cbe3-9aca-4277-afa1-6137eb8fb704
ms.openlocfilehash: dd973c96c9056f6156976698dfc3695b00ebbbb7
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87200862"
---
# <a name="argument-description"></a>Descrição do argumento

O parâmetro `argc` nas funções **main** e **wmain** é um inteiro que especifica quantos argumentos são transmitidos ao programa na linha de comando. Como o nome do programa é considerado um argumento, o valor de `argc` é pelo menos um.

## <a name="remarks"></a>Comentários

O parâmetro `argv` é uma matriz de ponteiros para cadeias de caracteres de terminação nula que representam os argumentos do programa. Cada elemento da matriz aponta para uma representação de cadeia de caracteres de um argumento transmitido a **main** (ou a **wmain**). (Para obter informações sobre matrizes, consulte [declarações de matriz](../c-language/array-declarations.md).) O `argv` parâmetro pode ser declarado como uma matriz de ponteiros para o tipo **`char`** ( `char *argv[]` ) ou como um ponteiro para ponteiros para o tipo **`char`** ( `char **argv` ). Para **wmain**, o `argv` parâmetro pode ser declarado como uma matriz de ponteiros para Type **`wchar_t`** ( `wchar_t *argv[]` ) ou como um ponteiro para ponteiros para Type **`wchar_t`** ( `wchar_t **argv` ).

Por convenção, `argv`**[0]** é o comando com que o programa é invocado.  No entanto, é possível gerar um processo usando [CreateProcess](/windows/win32/api/processthreadsapi/nf-processthreadsapi-createprocessw) e, se você usar o primeiro e o segundo argumentos ( `lpApplicationName` e `lpCommandLine` ), `argv` **[0]** talvez não seja o nome do executável; use [GetModuleFileName](/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulefilenamew) para recuperar o nome do executável.

O último ponteiro (`argv[argc]`) é **NULL**. (Consulte [getenv](../c-runtime-library/reference/getenv-wgetenv.md) na *Referência da biblioteca em tempo de execução* para conhecer um método alternativo para obter informações sobre a variável de ambiente.)

**Específico da Microsoft**

O parâmetro `envp` é um ponteiro para uma matriz de cadeias de caracteres de terminação nula que representam os valores definidos nas variáveis de ambiente do usuário. O `envp` parâmetro pode ser declarado como uma matriz de ponteiros para **`char`** ( `char *envp[]` ) ou como um ponteiro para ponteiros para **`char`** ( `char **envp` ). Em uma função **wmain** , o `envp` parâmetro pode ser declarado como uma matriz de ponteiros para **`wchar_t`** ( `wchar_t *envp[]` ) ou como um ponteiro para ponteiros para **`wchar_t`** ( `wchar_t **envp` ). O encerramento da matriz é indicado por um ponteiro **NULL** \*. Observe que o bloco de ambiente transmitido para **main** ou **wmain** é uma cópia "congelada" do ambiente atual. Se você alterar posteriormente o ambiente por meio de uma chamada para _**putenv** ou `_wputenv` , o ambiente atual (como retornado por `getenv` / `_wgetenv` e as `_environ` `_wenviron` variáveis ou) será alterado, mas o bloco apontado por `envp` não será alterado. O parâmetro `envp` é compatível com ANSI em C, mas não em C++.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Execução principal da função e do programa](../c-language/main-function-and-program-execution.md)
