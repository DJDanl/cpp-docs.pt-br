---
title: :::no-loc(main):::argumentos de linha de comando e de função (C++)
description: 'A :::no-loc(main)::: função é o ponto de entrada para um programa C++.'
ms.date: 01/15/2019
ms.assetid: c6568ee6-40ab-4ae8-aa44-c99e232f64ac
no-loc:
- ':::no-loc(main):::'
- ':::no-loc(wmain):::'
- ':::no-loc(inline):::'
- ':::no-loc(static):::'
- ':::no-loc(_tmain):::'
- ':::no-loc(void):::'
- ':::no-loc(exit):::'
- ':::no-loc(argc):::'
- ':::no-loc(argv):::'
- ':::no-loc(envp):::'
- ':::no-loc(CreateProcess):::'
- ':::no-loc(GetModuleFileName):::'
- ':::no-loc(char):::'
- ':::no-loc(wchar_t):::'
- ':::no-loc(extern):::'
ms.openlocfilehash: 9fe7c7a0808584a70bffa541903866b3de364e5f
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213314"
---
# <a name="no-locmain-function-and-command-line-arguments"></a>:::no-loc(main):::argumentos de linha de comando e de função

Todos os programas C++ devem ter uma `:::no-loc(main):::` função. Se você tentar compilar um projeto C++ *. exe* sem uma :::no-loc(main)::: função, o compilador gerará um erro. (Bibliotecas de vínculo dinâmico e :::no-loc(static)::: bibliotecas não têm uma `:::no-loc(main):::` função.) A `:::no-loc(main):::` função é onde o código-fonte começa a execução, mas antes de um programa entrar na `:::no-loc(main):::` função, todos os :::no-loc(static)::: membros da classe sem inicializadores explícitos são definidos como zero. No Microsoft C++, os :::no-loc(static)::: objetos globais também são inicializados antes da entrada para `:::no-loc(main):::` . Várias restrições se aplicam à `:::no-loc(main):::` função que não se aplica a outras funções do C++. A `:::no-loc(main):::` função:

- Não pode ser sobrecarregado (consulte [sobrecarga de função](function-overloading.md)).
- Não pode ser declarado como **`:::no-loc(inline):::`** .
- Não pode ser declarado como **`:::no-loc(static):::`** .
- Não pode ter seu endereço removido.
- Não pode ser chamada.

A :::no-loc(main)::: função não tem uma declaração, pois ela está incorporada à linguagem. Se tiver feito isso, a sintaxe da declaração para `:::no-loc(main):::` ficaria assim:

```cpp
int :::no-loc(main):::();
int :::no-loc(main):::(int :::no-loc(argc):::, :::no-loc(char)::: *:::no-loc(argv):::[], :::no-loc(char)::: *:::no-loc(envp):::[]);
```

**Específico da Microsoft**

Se os arquivos de origem usarem acters de largura Unicode :::no-loc(char)::: , você poderá usar `:::no-loc(wmain):::` o, que é a :::no-loc(char)::: versão de grande acter do `:::no-loc(main):::` . A sintaxe de declaração para `:::no-loc(wmain):::` é a seguinte:

```cpp
int :::no-loc(wmain):::( );
int :::no-loc(wmain):::(int :::no-loc(argc):::, :::no-loc(wchar_t)::: *:::no-loc(argv):::[], :::no-loc(wchar_t)::: *:::no-loc(envp):::[]);
```

Você também pode usar `:::no-loc(_tmain):::` , que é definido em t :::no-loc(char)::: . h. `:::no-loc(_tmain):::`resolve para a `:::no-loc(main):::` menos que _UNICODE seja definido. Nesse caso, `:::no-loc(_tmain):::` resolve a `:::no-loc(wmain):::`.

Se nenhum valor de retorno for especificado, o compilador fornecerá um valor de retorno igual a zero. Como alternativa, as `:::no-loc(main):::` `:::no-loc(wmain):::` funções e podem ser declaradas como retornando **`:::no-loc(void):::`** (nenhum valor de retorno). Se você declarar `:::no-loc(main):::` ou `:::no-loc(wmain):::` retornar **`:::no-loc(void):::`** , não poderá retornar um :::no-loc(exit)::: código para o processo pai ou sistema operacional usando uma instrução [Return](../cpp/return-statement-in-program-termination-cpp.md) . Para retornar um :::no-loc(exit)::: código quando `:::no-loc(main):::` ou `:::no-loc(wmain):::` é declarado como **`:::no-loc(void):::`** , você deve usar a [:::no-loc(exit):::](../cpp/:::no-loc(exit):::-function.md) função.

**FINAL específico da Microsoft**

## <a name="command-line-arguments"></a>Argumentos de linha de comando

Os argumentos para `:::no-loc(main):::` ou `:::no-loc(wmain):::` permitem a análise de linha de comando conveniente de argumentos e, opcionalmente, o acesso a variáveis de ambiente. Os tipos para `:::no-loc(argc):::` e `:::no-loc(argv):::` são definidos pela linguagem. Os nomes `:::no-loc(argc):::` , `:::no-loc(argv):::` e `:::no-loc(envp):::` são tradicionais, mas você pode nomeá-los como desejar.

```cpp
int :::no-loc(main):::( int :::no-loc(argc):::, :::no-loc(char):::* :::no-loc(argv):::[], :::no-loc(char):::* :::no-loc(envp):::[]);
int :::no-loc(wmain):::( int :::no-loc(argc):::, :::no-loc(wchar_t):::* :::no-loc(argv):::[], :::no-loc(wchar_t):::* :::no-loc(envp):::[]);
```

As definições dos argumentos são as seguintes:

*:::no-loc(argc):::*<br/>
Um inteiro que contém a contagem de argumentos que acompanham *:::no-loc(argv):::* . O *:::no-loc(argc):::* parâmetro é sempre maior ou igual a 1.

*:::no-loc(argv):::*<br/>
Uma matriz de cadeias de caracteres terminadas em nulo que representam argumentos de linha de comando inseridos pelo usuário do programa. Por convenção, `:::no-loc(argv):::[0]` é o comando com o qual o programa é invocado, `:::no-loc(argv):::[1]` é o primeiro argumento de linha de comando e assim por diante, `:::no-loc(argv):::[:::no-loc(argc):::]` que é sempre nulo. Consulte [Personalizando o processamento de linha de comando](../cpp/customizing-cpp-command-line-processing.md) para obter informações sobre como suprimir o processamento de linha de comando.

O primeiro argumento de linha de comando sempre é `:::no-loc(argv):::[1]` e o último é `:::no-loc(argv):::[:::no-loc(argc)::: - 1]`.

> [!NOTE]
> Por convenção, `:::no-loc(argv):::[0]` é o comando com o qual o programa é invocado. No entanto, é possível gerar um processo usando [:::no-loc(CreateProcess):::](/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulefilenamew) e se você usar o primeiro e o segundo argumentos (*LpApplicationName* e *lpCommandLine*), `:::no-loc(argv):::[0]` talvez não seja o nome do executável; use [:::no-loc(GetModuleFileName):::](/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulefilenamew) para recuperar o nome do executável e seu caminho totalmente qualificado.

**Específico da Microsoft**

*:::no-loc(envp):::*<br/>
A *:::no-loc(envp):::* matriz, que é uma extensão comum em muitos sistemas UNIX, é usada no Microsoft C++. Trata-se de uma matriz de cadeias de caracteres que representam as variáveis definidas no ambiente do usuário. Essa matriz é encerrada por uma entrada NULL. Ele pode ser declarado como uma matriz de ponteiros para **`:::no-loc(char):::`** ( `:::no-loc(char)::: *:::no-loc(envp):::[]` ) ou como um ponteiro para ponteiros para **`:::no-loc(char):::`** ( `:::no-loc(char)::: **:::no-loc(envp):::` ). Se o seu programa usar `:::no-loc(wmain):::` em vez de `:::no-loc(main):::` , use o **`:::no-loc(wchar_t):::`** tipo de dados em vez de **`:::no-loc(char):::`** . O bloco de ambiente passou para `:::no-loc(main):::` e `:::no-loc(wmain):::` é uma cópia "congelada" do ambiente atual. Se você alterar posteriormente o ambiente por meio de uma chamada para `putenv` ou `_wputenv` , o ambiente atual (como retornado por `getenv` or `_wgetenv` e a `_environ` `_wenviron` variável or) será alterado, mas o bloco apontado por :::no-loc(envp)::: não será alterado. Consulte [Personalizando o processamento de linha de comando](../cpp/customizing-cpp-command-line-processing.md) para obter informações sobre como suprimir o processamento do ambiente. Esse argumento é compatível com ANSI em C, mas não em C++.

**FINAL específico da Microsoft**

### <a name="example"></a>Exemplo

O exemplo a seguir mostra como usar os *:::no-loc(argc):::* *:::no-loc(argv):::* argumentos, e *:::no-loc(envp):::* para `:::no-loc(main):::` :

```cpp
// argument_definitions.cpp
// compile with: /EHsc
#include <iostream>
#include <string.h>

using namespace std;
int :::no-loc(main):::( int :::no-loc(argc):::, :::no-loc(char)::: *:::no-loc(argv):::[], :::no-loc(char)::: *:::no-loc(envp):::[] ) {
    int iNumberLines = 0;    // Default is no line numbers.

    // If /n is passed to the .exe, display numbered listing
    // of environment variables.

    if ( (:::no-loc(argc)::: == 2) && _stricmp( :::no-loc(argv):::[1], "/n" ) == 0 )
         iNumberLines = 1;

    // Walk through list of strings until a NULL is encountered.
    for( int i = 0; :::no-loc(envp):::[i] != NULL; ++i ) {
        if( iNumberLines )
            cout << i << ": " << :::no-loc(envp):::[i] << "\n";
    }
}
```

## <a name="parsing-c-command-line-arguments"></a>Analisando argumentos de linha de comando C++

**Específico da Microsoft**

O código de inicialização do Microsoft C/C++ usa as seguintes regras para interpretar os argumentos dados na linha de comando do sistema operacional:

- Os argumentos são delimitados por espaço em branco, que é um espaço ou uma tabulação.

- O cursor :::no-loc(char)::: acter (^) não é reconhecido como um acter de escape :::no-loc(char)::: ou delimitador. O :::no-loc(char)::: acter é manipulado completamente pelo analisador de linha de comando no sistema operacional antes de ser passado para `:::no-loc(argv):::` a matriz no programa.

- Uma cadeia de caracteres entre aspas duplas ("*String*") é interpretada como um único argumento, independentemente do espaço em branco contido em. Uma cadeia de caracteres entre aspas pode ser inserida em um argumento.

- Aspas duplas precedidas por uma barra invertida ( \\ ") é interpretada como uma aspa dupla literal :::no-loc(char)::: acter (").

- As barras invertidas são interpretadas literalmente, a menos que precedam imediatamente as aspas duplas.

- Se um número de barras invertidas mesmo for seguido por aspas duplas, uma barra invertida é colocada na matriz de `:::no-loc(argv):::` para cada par de barras invertidas, e aspas duplas são interpretadas como um delimitador de cadeia de caracteres.

- Se um número ímpar de barras invertidas for seguido por uma aspa dupla, uma barra invertida será colocada na `:::no-loc(argv):::` matriz para cada par de barras invertidas e as aspas duplas serão "escapadas" pela :::no-loc(main)::: barra invertida, fazendo com que uma aspa dupla literal (") seja colocada em `:::no-loc(argv):::` .

### <a name="example"></a>Exemplo

O programa a seguir demonstra como argumentos de linha de comando são passados:

```cpp
// command_line_arguments.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;
int :::no-loc(main):::( int :::no-loc(argc):::,      // Number of strings in array :::no-loc(argv):::
          :::no-loc(char)::: *:::no-loc(argv):::[],   // Array of command-line argument strings
          :::no-loc(char)::: *:::no-loc(envp):::[] )  // Array of environment variable strings
{
    int count;

    // Display each command-line argument.
    cout << "\nCommand-line arguments:\n";
    for( count = 0; count < :::no-loc(argc):::; count++ )
         cout << "  :::no-loc(argv):::[" << count << "]   "
                << :::no-loc(argv):::[count] << "\n";
}
```

A tabela a seguir mostra exemplos de entrada e saídas esperadas, demonstrando as regras na lista acima.

### <a name="results-of-parsing-command-lines"></a>Resultados da análise de linhas de comando

|Entrada de linha de comando|:::no-loc(argv):::[1]|:::no-loc(argv):::[2]|:::no-loc(argv):::Beta|
|-------------------------|---------------|---------------|---------------|
|`"abc" d e`|`abc`|`d`|`e`|
|`a\\b d"e f"g h`|`a\\b`|`de fg`|`h`|
|`a\\\"b c d`|`a\"b`|`c`|`d`|
|`a\\\\"b c" d e`|`a\\b c`|`d`|`e`|

**FINAL específico da Microsoft**

## <a name="wildcard-expansion"></a>Expansão de curinga

**Específico da Microsoft**

Você pode usar caracteres curinga — o ponto de interrogação (?) e o asterisco (*) — para especificar argumentos de nome de arquivo e caminho na linha de comando.

Os argumentos de linha de comando são tratados por uma rotina chamada `_set:::no-loc(argv):::` (ou `_wset:::no-loc(argv):::` no ambiente de Wide- :::no-loc(char)::: acter), que, por padrão, não expande curingas em cadeias de caracteres separadas na `:::no-loc(argv):::` matriz de cadeias. Para obter mais informações sobre como habilitar a expansão de curinga, consulte [expandindo argumentos curinga](../c-language/expanding-wildcard-arguments.md).

**FINAL específico da Microsoft**

## <a name="customizing-c-command-line-processing"></a>Personalizando processamento de linha de comando C++

**Específico da Microsoft**

Se o seu programa não utiliza argumentos de linha de comando, é possível economizar um pequeno espaço suprimindo o uso da rotina de biblioteca que executa o processamento de linha de comando. Essa rotina é chamada `_set:::no-loc(argv):::` e é descrita na [expansão de curinga](../cpp/wildcard-expansion.md). Para suprimir seu uso, defina uma rotina que não faz nada no arquivo que contém a `:::no-loc(main):::` função e nomeie-o `_set:::no-loc(argv):::` . A chamada para `_set:::no-loc(argv):::` é então satisfeita pela sua definição de `_set:::no-loc(argv):::` e a versão da biblioteca não é carregada.

Da mesma forma, se você nunca acessar a tabela de ambiente por meio do `:::no-loc(envp):::` argumento, poderá fornecer sua própria rotina vazia a ser usada no lugar da `_set:::no-loc(envp):::` rotina de processamento de ambiente. Assim como com a `_set:::no-loc(argv):::` função, `_set:::no-loc(envp):::` deve ser declarado como ** :::no-loc(extern)::: "C"**.

Seu programa pode fazer chamadas para a `spawn` `exec` família de rotinas ou na biblioteca de tempo de execução do C. Se tiver, você não deverá suprimir a rotina de processamento de ambiente, pois essa rotina é usada para passar um ambiente do processo pai para o processo filho.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Conceitos básicos](../cpp/basic-concepts-cpp.md)
