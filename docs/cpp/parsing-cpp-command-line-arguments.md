---
title: Analisando argumentos de linha de comando do C++ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- quotation marks, command-line arguments
- double quotation marks
- command line [C++], parsing
- parsing, command-line arguments
- startup code, parsing command-line arguments
ms.assetid: e634e733-ac2f-4298-abe2-7e9288c94951
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a48e731e714f59a249e5fa689e046e94faf360e6
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46040213"
---
# <a name="parsing-c-command-line-arguments"></a>Analisando argumentos de linha de comando C++

**Seção específica da Microsoft**

O código de inicialização do Microsoft C/C++ usa as seguintes regras para interpretar os argumentos dados na linha de comando do sistema operacional:

- Os argumentos são delimitados por espaço em branco, que é um espaço ou uma tabulação.

- O caractere de acento circunflexo (^) não é reconhecido como um caractere de escape ou um delimitador. O caractere é completamente tratado pelo analisador de linha de comando no sistema operacional antes de ser passada para a matriz `argv` no programa.

- Uma cadeia de caracteres cercada por aspas duplas ("*cadeia de caracteres*") é interpretado como um único argumento, independentemente do espaço em branco contido. Uma cadeia de caracteres entre aspas pode ser inserida em um argumento.

- Aspas duplas precedidas por uma barra invertida (\\") são interpretados como um caractere literal de aspas duplas (").

- As barras invertidas são interpretadas literalmente, a menos que precedam imediatamente as aspas duplas.

- Se um número de barras invertidas mesmo for seguido por aspas duplas, uma barra invertida é colocada na matriz de `argv` para cada par de barras invertidas, e aspas duplas são interpretadas como um delimitador de cadeia de caracteres.

- Se um número ímpar de barras invertidas for seguido por aspas duplas, uma barra invertida é colocada na matriz de `argv` para cada par de barras invertidas, e aspas duplas são "ignoradas" pela barra invertida restante, causando a colocação de aspas duplas (") literais em `argv`.

## <a name="example"></a>Exemplo

O programa a seguir demonstra como argumentos de linha de comando são passados:

```cpp
// command_line_arguments.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;
int main( int argc,      // Number of strings in array argv
          char *argv[],   // Array of command-line argument strings
          char *envp[] )  // Array of environment variable strings
{
    int count;

    // Display each command-line argument.
    cout << "\nCommand-line arguments:\n";
    for( count = 0; count < argc; count++ )
         cout << "  argv[" << count << "]   "
                << argv[count] << "\n";
}
```

A tabela a seguir mostra exemplos de entrada e saídas esperadas, demonstrando as regras na lista acima.

### <a name="results-of-parsing-command-lines"></a>Resultados de linhas de comando de análise

|Entrada de linha de comando|argv[1]|argv[2]|argv[3]|
|-------------------------|---------------|---------------|---------------|
|`"abc" d e`|`abc`|`d`|`e`|
|`a\\b d"e f"g h`|`a\\b`|`de fg`|`h`|
|`a\\\"b c d`|`a\"b`|`c`|`d`|
|`a\\\\"b c" d e`|`a\\b c`|`d`|`e`|

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[main: inicialização do programa](../cpp/main-program-startup.md)