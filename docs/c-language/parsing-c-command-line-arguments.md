---
title: Analisando argumentos de linha de comando C
ms.date: 11/04/2016
helpviewer_keywords:
- quotation marks, command-line arguments
- double quotation marks
- command line, parsing
- parsing, command-line arguments
- startup code, parsing command-line arguments
ms.assetid: ffce8037-2811-45c4-8db4-1ed787859c80
ms.openlocfilehash: ace6d1b8295d0901ef22f3c354b32ad17e296e87
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75299085"
---
# <a name="parsing-c-command-line-arguments"></a>Analisando argumentos de linha de comando C

**Seção específica da Microsoft**

O código de inicialização do Microsoft C usa as seguintes regras para interpretar os argumentos dados na linha de comando do sistema operacional:

- Os argumentos são delimitados por espaço em branco, que é um espaço ou uma tabulação.

- Uma cadeia de caracteres cercada por aspas duplas são interpretadas como um único argumento, independentemente do espaço em branco contido. Uma cadeia de caracteres entre aspas pode ser inserida em um argumento. Observe que o acento circunflexo ( **^** ) não é reconhecido como um caractere de escape ou um delimitador.

- Aspas duplas precedidas por uma barra invertida, **\\"** , são interpretadas como um caractere literal de aspas duplas ( **"** ).

- As barras invertidas são interpretadas literalmente, a menos que precedam imediatamente as aspas duplas.

- Se um número par de barras invertidas for seguido por aspas duplas, então uma barra invertida ( **\\** ) será colocada na matriz `argv` para cada par de barras invertidas ( **\\\\** ); as aspas duplas ( **"** ) serão interpretadas como um delimitador de cadeia de caracteres.

- Se um número ímpar de barras invertidas for seguido por aspas duplas, então uma barra invertida ( **\\** ) será colocada na matriz `argv` para cada par de barras invertidas ( **\\\\** ); as aspas duplas serão interpretadas como uma sequência de escape pela barra invertida restante, causando a colocação de aspas duplas literais ( **"** ) em `argv`.

Esta lista ilustra as regras acima mostrando o resultado interpretado passado para `argv` por vários exemplos de argumentos de linha de comando. O resultado listado na segunda, terceira e quarta coluna são do programa de ARGS.C que segue a lista.

|Entrada de linha de comando|argv[1]|argv[2]|argv[3]|
|-------------------------|---------------|---------------|---------------|
|`"a b c" d e`|`a b c`|`d`|`e`|
|`"ab\"c" "\\" d`|`ab"c`|`\`|`d`|
|`a\\\b d"e f"g h`|`a\\\b`|`de fg`|`h`|
|`a\\\"b c d`|`a\"b`|`c`|`d`|
|`a\\\\"b c" d e`|`a\\b c`|`d`|`e`|

## <a name="example"></a>Exemplo

### <a name="code"></a>Código

```c
// Parsing_C_Commandline_args.c
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

## <a name="comments"></a>Comments

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

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Veja também

[Função main e execução do programa](../c-language/main-function-and-program-execution.md)
