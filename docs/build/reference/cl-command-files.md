---
title: Arquivos de comando CL
description: O compilador MSVC permite que você especifique os arquivos de comando que contêm opções de linha de comando.
ms.date: 07/08/2020
helpviewer_keywords:
- cl.exe compiler, command files
- command files
- command files, CL compiler
ms.assetid: ec3cea06-2af0-4fe9-a94c-119c9d31b3a9
ms.openlocfilehash: 6deab4b11dcc6c53beb5b4fa8b014a56020c3420
ms.sourcegitcommit: 80c8a512b361bd84e38958beb1a1bf6db7434021
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/09/2020
ms.locfileid: "86180936"
---
# <a name="cl-command-files"></a>Arquivos de comando CL

Um arquivo de comando é um arquivo de texto que contém opções de compilador e nomes de arquivo. Ele fornece opções que seriam digitadas de outra forma na [linha de comando](compiler-command-line-syntax.md)ou especificamos usando a [variável de ambiente CL](cl-environment-variables.md). O CL aceita um arquivo de comando do compilador como um argumento, na variável de ambiente CL ou na linha de comando. Ao contrário da linha de comando ou da variável de ambiente CL, você pode usar várias linhas de opções e nomes de arquivos em um arquivo de comando.

Opções e nomes de arquivos em um arquivo de comando são processados quando um nome de arquivo de comando é exibido dentro da variável de ambiente CL ou na linha de comando. No entanto, se a **`/link`** opção aparecer no arquivo de comando, todas as opções no restante da linha serão passadas para o vinculador. As opções nas linhas posteriores no arquivo de comando e as opções na linha de comando após a invocação do arquivo de comando ainda são aceitas como opções do compilador. Para obter mais informações sobre como a ordem das opções afeta sua interpretação, consulte [ordem das opções do CL](order-of-cl-options.md).

Um arquivo de comando não deve conter o comando CL. Cada opção deve começar e terminar na mesma linha; Não é possível usar a barra invertida ( **`\`** ) para combinar uma opção em duas linhas.

Um arquivo de comando é especificado por um sinal de arroba ( **`@`** ) seguido de um nome de arquivo. O nome do arquivo pode especificar um caminho absoluto ou relativo.

Por exemplo, se o seguinte comando estiver em um arquivo chamado RESP:

```cmd
/Ot /link LIBC.LIB
```

e você especifica o seguinte comando CL:

```cmd
CL /Ob2 @RESP MYAPP.C
```

o comando para CL é o seguinte:

```cmd
CL /Ob2 /Ot MYAPP.C /link LIBC.LIB
```

Aqui você pode ver como a linha de comando e os comandos de arquivo de comando são efetivamente combinados.

## <a name="see-also"></a>Veja também

[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[Opções do compilador MSVC](compiler-options.md)
