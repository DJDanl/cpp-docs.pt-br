---
title: main argumentos de linha de comando e de função (C++)
description: A main função é o ponto de entrada para um programa C++.
ms.date: 01/15/2019
ms.assetid: c6568ee6-40ab-4ae8-aa44-c99e232f64ac
no-loc:
- main
- wmain
- inline
- static
- _tmain
- void
- exit
- argc
- argv
- envp
- CreateProcess
- GetModuleFileName
- char
- wchar_t
- extern
ms.openlocfilehash: b27668c3c7ce77e4369af144bb8be4efb695e522
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91499809"
---
# <a name="no-locmain-function-and-command-line-arguments"></a>main argumentos de linha de comando e de função

Todos os programas C++ devem ter uma `main` função. Se você tentar compilar um projeto C++ *. exe* sem uma main função, o compilador gerará um erro. (Bibliotecas de vínculo dinâmico e static bibliotecas não têm uma `main` função.) A `main` função é onde o código-fonte começa a execução, mas antes de um programa entrar na `main` função, todos os static membros da classe sem inicializadores explícitos são definidos como zero. No Microsoft C++, os static objetos globais também são inicializados antes da entrada para `main` . Várias restrições se aplicam à `main` função que não se aplica a outras funções do C++. A `main` função:

- Não pode ser sobrecarregado (consulte [sobrecarga de função](function-overloading.md)).
- Não pode ser declarado como **`inline`** .
- Não pode ser declarado como **`static`** .
- Não pode ter seu endereço removido.
- Não pode ser chamada.

A main função não tem uma declaração, pois ela está incorporada à linguagem. Se tiver feito isso, a sintaxe da declaração para `main` ficaria assim:

```cpp
int main();
int main(int argc, char *argv[], char *envp[]);
```

**Específico da Microsoft**

Se os arquivos de origem usarem acters de largura Unicode char , você poderá usar `wmain` o, que é a char versão de grande acter do `main` . A sintaxe de declaração para `wmain` é a seguinte:

```cpp
int wmain( );
int wmain(int argc, wchar_t *argv[], wchar_t *envp[]);
```

Você também pode usar `_tmain` , que é definido em t char . h. `_tmain` resolve para a `main` menos que _UNICODE seja definido. Nesse caso, `_tmain` resolve a `wmain`.

Se nenhum valor de retorno for especificado, o compilador fornecerá um valor de retorno igual a zero. Como alternativa, as `main` `wmain` funções e podem ser declaradas como retornando **`void`** (nenhum valor de retorno). Se você declarar `main` ou `wmain` retornar **`void`** , não poderá retornar um exit código para o processo pai ou sistema operacional usando uma instrução [Return](./program-termination.md) . Para retornar um exit código quando `main` ou `wmain` é declarado como **`void`** , você deve usar a [exit](./program-termination.md) função.

**FINAL específico da Microsoft**

## <a name="command-line-arguments"></a>Argumentos de linha de comando

Os argumentos para `main` ou `wmain` permitem a análise de linha de comando conveniente de argumentos e, opcionalmente, o acesso a variáveis de ambiente. Os tipos para `argc` e `argv` são definidos pela linguagem. Os nomes `argc` , `argv` e `envp` são tradicionais, mas você pode nomeá-los como desejar.

```cpp
int main( int argc, char* argv[], char* envp[]);
int wmain( int argc, wchar_t* argv[], wchar_t* envp[]);
```

As definições dos argumentos são as seguintes:

*argc*<br/>
Um inteiro que contém a contagem de argumentos que acompanham *argv* . O *argc* parâmetro é sempre maior ou igual a 1.

*argv*<br/>
Uma matriz de cadeias de caracteres terminadas em nulo que representam argumentos de linha de comando inseridos pelo usuário do programa. Por convenção, `argv[0]` é o comando com o qual o programa é invocado, `argv[1]` é o primeiro argumento de linha de comando e assim por diante, `argv[argc]` que é sempre nulo. Consulte [Personalizando o processamento de linha de comando]() para obter informações sobre como suprimir o processamento de linha de comando.

O primeiro argumento de linha de comando sempre é `argv[1]` e o último é `argv[argc - 1]`.

> [!NOTE]
> Por convenção, `argv[0]` é o comando com o qual o programa é invocado. No entanto, é possível gerar um processo usando [CreateProcess](/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulefilenamew) e se você usar o primeiro e o segundo argumentos (*LpApplicationName* e *lpCommandLine*), `argv[0]` talvez não seja o nome do executável; use [GetModuleFileName](/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulefilenamew) para recuperar o nome do executável e seu caminho totalmente qualificado.

**Específico da Microsoft**

*envp*<br/>
A *envp* matriz, que é uma extensão comum em muitos sistemas UNIX, é usada no Microsoft C++. Trata-se de uma matriz de cadeias de caracteres que representam as variáveis definidas no ambiente do usuário. Essa matriz é encerrada por uma entrada NULL. Ele pode ser declarado como uma matriz de ponteiros para **`char`** ( `char *envp[]` ) ou como um ponteiro para ponteiros para **`char`** ( `char **envp` ). Se o seu programa usar `wmain` em vez de `main` , use o **`wchar_t`** tipo de dados em vez de **`char`** . O bloco de ambiente passou para `main` e `wmain` é uma cópia "congelada" do ambiente atual. Se você alterar posteriormente o ambiente por meio de uma chamada para `putenv` ou `_wputenv` , o ambiente atual (como retornado por `getenv` or `_wgetenv` e a `_environ`  `_wenviron` variável or) será alterado, mas o bloco apontado por envp não será alterado. Consulte [Personalizando o processamento de linha de comando]() para obter informações sobre como suprimir o processamento do ambiente. Esse argumento é compatível com ANSI em C, mas não em C++.

**FINAL específico da Microsoft**

### <a name="example"></a>Exemplo

O exemplo a seguir mostra como usar os *argc* *argv* argumentos, e *envp* para `main` :

```cpp
// argument_definitions.cpp
// compile with: /EHsc
#include <iostream>
#include <string.h>

using namespace std;
int main( int argc, char *argv[], char *envp[] ) {
    int iNumberLines = 0;    // Default is no line numbers.

    // If /n is passed to the .exe, display numbered listing
    // of environment variables.

    if ( (argc == 2) && _stricmp( argv[1], "/n" ) == 0 )
         iNumberLines = 1;

    // Walk through list of strings until a NULL is encountered.
    for( int i = 0; envp[i] != NULL; ++i ) {
        if( iNumberLines )
            cout << i << ": " << envp[i] << "\n";
    }
}
```

## <a name="parsing-c-command-line-arguments"></a>Analisando argumentos de linha de comando C++

**Específico da Microsoft**

O código de inicialização do Microsoft C/C++ usa as seguintes regras para interpretar os argumentos dados na linha de comando do sistema operacional:

- Os argumentos são delimitados por espaço em branco, que é um espaço ou uma tabulação.

- O cursor char acter (^) não é reconhecido como um acter de escape char ou delimitador. O char acter é manipulado completamente pelo analisador de linha de comando no sistema operacional antes de ser passado para `argv` a matriz no programa.

- Uma cadeia de caracteres entre aspas duplas ("*String*") é interpretada como um único argumento, independentemente do espaço em branco contido em. Uma cadeia de caracteres entre aspas pode ser inserida em um argumento.

- Aspas duplas precedidas por uma barra invertida ( \\ ") é interpretada como uma aspa dupla literal char acter (").

- As barras invertidas são interpretadas literalmente, a menos que precedam imediatamente as aspas duplas.

- Se um número de barras invertidas mesmo for seguido por aspas duplas, uma barra invertida é colocada na matriz de `argv` para cada par de barras invertidas, e aspas duplas são interpretadas como um delimitador de cadeia de caracteres.

- Se um número ímpar de barras invertidas for seguido por uma aspa dupla, uma barra invertida será colocada na `argv` matriz para cada par de barras invertidas e as aspas duplas serão "escapadas" pela main barra invertida, fazendo com que uma aspa dupla literal (") seja colocada em `argv` .

### <a name="example"></a>Exemplo

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

### <a name="results-of-parsing-command-lines"></a>Resultados da análise de linhas de comando

|Entrada de linha de comando|argv[1]|argv[2]|argvBeta|
|-------------------------|---------------|---------------|---------------|
|`"abc" d e`|`abc`|`d`|`e`|
|`a\\b d"e f"g h`|`a\\b`|`de fg`|`h`|
|`a\\\"b c d`|`a\"b`|`c`|`d`|
|`a\\\\"b c" d e`|`a\\b c`|`d`|`e`|

**FINAL específico da Microsoft**

## <a name="wildcard-expansion"></a>Expansão de curinga

**Específico da Microsoft**

Você pode usar caracteres curinga — o ponto de interrogação (?) e o asterisco (*) — para especificar argumentos de nome de arquivo e caminho na linha de comando.

Os argumentos de linha de comando são tratados por uma rotina chamada `_setargv` (ou `_wsetargv` no ambiente de Wide- char acter), que, por padrão, não expande curingas em cadeias de caracteres separadas na `argv` matriz de cadeias. Para obter mais informações sobre como habilitar a expansão de curinga, consulte [expandindo argumentos curinga](../c-language/expanding-wildcard-arguments.md).

**FINAL específico da Microsoft**

## <a name="customizing-c-command-line-processing"></a>Personalizando processamento de linha de comando C++

**Específico da Microsoft**

Se o seu programa não utiliza argumentos de linha de comando, é possível economizar um pequeno espaço suprimindo o uso da rotina de biblioteca que executa o processamento de linha de comando. Essa rotina é chamada `_setargv` e é descrita na [expansão de curinga](). Para suprimir seu uso, defina uma rotina que não faz nada no arquivo que contém a `main` função e nomeie-o `_setargv` . A chamada para `_setargv` é então satisfeita pela sua definição de `_setargv` e a versão da biblioteca não é carregada.

Da mesma forma, se você nunca acessar a tabela de ambiente por meio do `envp` argumento, poderá fornecer sua própria rotina vazia a ser usada no lugar da `_setenvp` rotina de processamento de ambiente. Assim como com a `_setargv` função, `_setenvp` deve ser declarado como ** extern "C"**.

Seu programa pode fazer chamadas para a `spawn` `exec` família de rotinas ou na biblioteca de tempo de execução do C. Se tiver, você não deverá suprimir a rotina de processamento de ambiente, pois essa rotina é usada para passar um ambiente do processo pai para o processo filho.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Consulte também

[Conceitos básicos](../cpp/basic-concepts-cpp.md)
