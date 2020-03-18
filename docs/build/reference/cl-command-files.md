---
title: Arquivos de comando CL
ms.date: 11/04/2016
helpviewer_keywords:
- cl.exe compiler, command files
- command files
- command files, CL compiler
ms.assetid: ec3cea06-2af0-4fe9-a94c-119c9d31b3a9
ms.openlocfilehash: 1dc2d6bffe4d0681a04b875383215a0bbfc1a720
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79440258"
---
# <a name="cl-command-files"></a>Arquivos de comando CL

Um arquivo de comando é um arquivo de texto que contém opções e nomes de arquivos que, de outra forma, seriam digitados na [linha de comando](compiler-command-line-syntax.md) ou especificariam usando a [variável de ambiente CL](cl-environment-variables.md). O CL aceita um arquivo de comando do compilador como um argumento na variável de ambiente CL ou na linha de comando. Em vez da linha de comando ou da variável de ambiente CL, um arquivo de comando permite que você use várias linhas de opções e nomes de arquivo.

Opções e nomes de arquivos em um arquivo de comando são processados de acordo com o local de um nome de arquivo de comando dentro da variável de ambiente CL ou na linha de comando. No entanto, se a opção/link aparecer no arquivo de comando, todas as opções no restante da linha serão passadas para o vinculador. As opções nas linhas subsequentes no arquivo de comando e nas opções na linha de comando após a invocação do arquivo de comando ainda são aceitas como opções do compilador. Para obter mais informações sobre como a ordem das opções afeta sua interpretação, consulte [ordem das opções do CL](order-of-cl-options.md).

Um arquivo de comando não deve conter o comando CL. Cada opção deve começar e terminar na mesma linha; Não é possível usar a barra invertida ( **\\** ) para combinar uma opção em duas linhas.

Um arquivo de comando é especificado por um sinal de arroba ( **\@** ) seguido de um nome de arquivo; o nome do arquivo pode especificar um caminho absoluto ou relativo.

Por exemplo, se o seguinte comando estiver em um arquivo chamado RESP:

```
/Og /link LIBC.LIB
```

e você especifica o seguinte comando CL:

```
CL /Ob2 @RESP MYAPP.C
```

o comando para CL é o seguinte:

```
CL /Ob2 /Og MYAPP.C /link LIBC.LIB
```

Observe que a linha de comando e os comandos de arquivo de comando são efetivamente combinados.

## <a name="see-also"></a>Consulte também

[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[Opções do compilador MSVC](compiler-options.md)
