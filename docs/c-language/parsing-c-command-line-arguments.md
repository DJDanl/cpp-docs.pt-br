---
title: Analisando argumentos de linha de comando C
description: Saiba como o código de inicialização do tempo de execução do Microsoft C interpreta argumentos de linha de comando para criar os parâmetros argv e argc.
ms.date: 11/09/2020
helpviewer_keywords:
- quotation marks, command-line arguments
- double quotation marks
- double quote marks
- command line, parsing
- parsing, command-line arguments
- startup code, parsing command-line arguments
ms.assetid: ffce8037-2811-45c4-8db4-1ed787859c80
ms.openlocfilehash: 92921e91ee6bb37b2bf7b702a1b31ed045187b59
ms.sourcegitcommit: b38485bb3a9d479e0c5d64ffc3d841fa2c2b366f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/10/2020
ms.locfileid: "94441249"
---
# <a name="parsing-c-command-line-arguments"></a>Analisando argumentos de linha de comando C

**Específico da Microsoft**

O código de inicialização do Microsoft C usa as seguintes regras para interpretar os argumentos dados na linha de comando do sistema operacional:

- Os argumentos são delimitados por espaço em branco, que é um espaço ou uma tabulação.

- O primeiro argumento ( `argv[0]` ) é tratado especialmente. Ele representa o nome do programa. Como ele deve ser um nome de caminho válido, partes entre aspas duplas ( **`"`** ) são permitidas. As aspas duplas não são incluídas na `argv[0]` saída. As partes entre aspas duplas impedem a interpretação de um espaço ou caractere de tabulação como o final do argumento. As regras posteriores desta lista não se aplicam.

- Uma cadeia de caracteres entre aspas duplas é interpretada como um único argumento, independentemente de conter ou não espaço em branco. Uma cadeia de caracteres entre aspas pode ser inserida em um argumento. O cursor ( **`^`** ) não é reconhecido como um caractere de escape ou delimitador. Dentro de uma cadeia de caracteres entre aspas, um par de aspas duplas é interpretado como uma aspa dupla de escape simples. Se a linha de comando terminar antes de uma marca de aspas duplas de fechamento ser encontrada, todos os caracteres lidos até agora serão gerados como o último argumento.

- Uma aspa dupla precedida por uma barra invertida ( **`\"`** ) é interpretada como uma aspa dupla literal ( **`"`** ).

- As barras invertidas são interpretadas literalmente, a menos que precedam imediatamente uma aspa dupla.

- Se um número par de barras invertidas for seguido por uma aspa dupla, uma barra invertida ( **`\`** ) será colocada na `argv` matriz para cada par de barras invertidas ( **`\\`** ), e a marca de aspas duplas ( **`"`** ) será interpretada como um delimitador de cadeia de caracteres.

- Se um número ímpar de barras invertidas for seguido por uma aspa dupla, uma barra invertida ( **`\`** ) será colocada na `argv` matriz para cada par de barras invertidas ( **`\\`** ). A marca de aspas duplas é interpretada como uma sequência de escape pela barra invertida restante, fazendo com que uma aspa dupla literal ( **`"`** ) seja colocada `argv` .

Esta lista ilustra as regras acima mostrando o resultado interpretado passado para `argv` por vários exemplos de argumentos de linha de comando. O resultado listado na segunda, terceira e quarta coluna são do programa de ARGS.C que segue a lista.

|Entrada de linha de comando|argv[1]|argv[2]|argv[3]|
|-------------------------|---------------|---------------|---------------|
|`"a b c" d e`|`a b c`|`d`|`e`|
|`"ab\"c" "\\" d`|`ab"c`|`\`|`d`|
|`a\\\b d"e f"g h`|`a\\\b`|`de fg`|`h`|
|`a\\\"b c d`|`a\"b`|`c`|`d`|
|`a\\\\"b c" d e`|`a\\b c`|`d`|`e`|
|`a"b"" c d`|`ab" c d`|||

## <a name="example"></a>Exemplo

### <a name="code"></a>Código

```c
// ARGS.C illustrates the following variables used for accessing
// command-line arguments and environment variables:
// argc  argv  envp
//

#include <stdio.h>

int main( int argc, // Number of strings in array argv
char *argv[],      // Array of command-line argument strings
char **envp )      // Array of environment variable strings
{
    int count;

    // Display each command-line argument.
    printf_s( "\nCommand-line arguments:\n" );
    for( count = 0; count < argc; count++ )
        printf_s( "  argv[%d]   %s\n", count, argv[count] );

    // Display each environment variable.
    printf_s( "\nEnvironment variables:\n" );
    while( *envp != NULL )
        printf_s( "  %s\n", *(envp++) );

    return;
}
```

## <a name="comments"></a>Comentários

Um exemplo de resultado deste programa é:

```
Command-line arguments:
  argv[0]   C:\MSC\TEST.EXE

Environment variables:
  COMSPEC=C:\NT\SYSTEM32\CMD.EXE

  PATH=c:\nt;c:\binb;c:\binr;c:\nt\system32;c:\word;c:\help;c:\msc;c:\;
  PROMPT=[$p]
  TEMP=c:\tmp
  TMP=c:\tmp
  EDITORS=c:\binr
  WINDIR=c:\nt
```

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Execução principal da função e do programa](../c-language/main-function-and-program-execution.md)
