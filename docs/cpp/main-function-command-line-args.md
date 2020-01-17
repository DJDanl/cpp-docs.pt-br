---
title: main de função e argumentos de linha deC++comando ()
description: A função main é o ponto de entrada para C++ um programa.
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
ms.openlocfilehash: 33753e30304a9bb63c135979d3f20098e6b6401a
ms.sourcegitcommit: e93f3e6a110fe38bc642055bdf4785e620d4220f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/16/2020
ms.locfileid: "76123897"
---
# <a name="opno-locmain-function-and-command-line-arguments"></a>main de função e argumentos de linha de comando

Todos C++ os programas devem ter uma função `main`. Se você tentar compilar um C++ projeto *. exe* sem uma função main, o compilador gerará um erro. (Bibliotecas de vínculo dinâmico e bibliotecas de static não têm uma função `main`.) A função `main` é onde o código-fonte começa a execução, mas antes que um programa insira a função `main`, todos os membros da classe static sem inicializadores explícitos são definidos como zero. No Microsoft C++, os objetos de static global também são inicializados antes da entrada para `main`. Várias restrições se aplicam à função `main` que não se aplicam a C++ outras funções. A função `main`:

- Não pode ser sobrecarregado (consulte [sobrecarga de função](function-overloading.md)).
- Não pode ser declarado como **inline** .
- Não pode ser declarado como **static** .
- Não pode ter seu endereço removido.
- Não pode ser chamada.

A função main não tem uma declaração, pois ela está incorporada à linguagem. Se tiver feito isso, a sintaxe da declaração para `main` ficaria assim:

```cpp
int main();
int main(int argc, char *argv[], char *envp[]);
```

**Seção específica da Microsoft**

Se os arquivos de origem usarem caracteres largos Unicode, você poderá usar `wmain`, que é a versão de caractere largo do `main`. A sintaxe de declaração para `wmain` é a seguinte:

```cpp
int wmain( );
int wmain(int argc, wchar_t *argv[], wchar_t *envp[]);
```

Você também pode usar `_tmain`, que é definido em TCHAR. h. `_tmain` resolve para `main`, a menos que _UNICODE seja definido. Nesse caso, `_tmain` resolve a `wmain`.

Se nenhum valor de retorno for especificado, o compilador fornecerá um valor de retorno igual a zero. Como alternativa, as funções `main` e `wmain` podem ser declaradas como retorno **void** (nenhum valor de retorno). Se você declarar `main` ou `wmain` como retorno **void** , não poderá retornar um código de exit para o processo pai ou sistema operacional usando uma instrução [Return](../cpp/return-statement-in-program-termination-cpp.md) . Para retornar um código de exit quando `main` ou `wmain` é declarado como **void** , você deve usar a função [exit](../cpp/exit-function.md) .

**Fim da seção específica da Microsoft**

## <a name="command-line-arguments"></a>Argumentos de linha de comando

Os argumentos para `main` ou `wmain` permitem uma análise de linha de comando conveniente de argumentos e, opcionalmente, o acesso às variáveis de ambiente. Os tipos para `argc` e `argv` são definidos pela linguagem. Os nomes `argc`, `argv`e `envp` são tradicionais, mas você pode nomeá-los como desejar.

```cpp
int main( int argc, char* argv[], char* envp[]);
int wmain( int argc, wchar_t* argv[], wchar_t* envp[]);
```

As definições dos argumentos são as seguintes:

*argc*<br/>
Um inteiro que contém a contagem de argumentos que seguem em *argv* . O parâmetro *argc* é sempre maior ou igual a 1.

*argv*<br/>
Uma matriz de cadeias de caracteres terminadas em nulo que representam argumentos de linha de comando inseridos pelo usuário do programa. Por convenção, `argv[0]` é o comando com o qual o programa é invocado, `argv[1]` é o primeiro argumento de linha de comando, e assim por diante, até `argv[argc]`, que é sempre nulo. Consulte [Personalizando o processamento de linha de comando](../cpp/customizing-cpp-command-line-processing.md) para obter informações sobre como suprimir o processamento de linha de comando.

O primeiro argumento de linha de comando sempre é `argv[1]` e o último é `argv[argc - 1]`.

> [!NOTE]
> Por convenção, `argv[0]` é o comando com o qual o programa é invocado. No entanto, é possível gerar um processo usando [CreateProcess](/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulefilenamew) e, se você usar o primeiro e o segundo argumentos (*lpApplicationName* e *lpCommandLine*), `argv[0]` talvez não seja o nome do executável; Use [GetModuleFileName](/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulefilenamew) para recuperar o nome do executável e seu caminho totalmente qualificado.

**Seção específica da Microsoft**

*envp*<br/>
A matriz de *envp* , que é uma extensão comum em muitos sistemas UNIX, é usada na C++Microsoft. Trata-se de uma matriz de cadeias de caracteres que representam as variáveis definidas no ambiente do usuário. Essa matriz é terminada por uma entrada NULL. Ele pode ser declarado como uma matriz de ponteiros para **char** (`char *envp[]`) ou como um ponteiro para ponteiros para **char** (`char **envp`). Se seu programa usar `wmain` em vez de `main`, use o tipo de dados **wchar_t** em vez de **char** . O bloco de ambiente passado para `main` e `wmain` é uma cópia "congelada" do ambiente atual. Se você alterar posteriormente o ambiente por meio de uma chamada para `putenv` ou `_wputenv`, o ambiente atual (como retornado por `getenv` ou `_wgetenv` e a `_environ` ou `_wenviron` variável) será alterado, mas o bloco apontado por envp não será alterado. Consulte [Personalizando o processamento de linha de comando](../cpp/customizing-cpp-command-line-processing.md) para obter informações sobre como suprimir o processamento do ambiente. Esse argumento é compatível com ANSI em C, mas não em C++.

**Fim da seção específica da Microsoft**

### <a name="example"></a>Exemplo

O exemplo a seguir mostra como usar os argumentos *argc* , *argv* e *envp* para `main`:

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

## <a name="parsing-c-command-line-arguments"></a>Analisando C++ argumentos de linha de comando

**Seção específica da Microsoft**

O código de inicialização do Microsoft C/C++ usa as seguintes regras para interpretar os argumentos dados na linha de comando do sistema operacional:

- Os argumentos são delimitados por espaço em branco, que é um espaço ou uma tabulação.

- O caractere de acento circunflexo (^) não é reconhecido como um caractere de escape ou um delimitador. O caractere é completamente tratado pelo analisador de linha de comando no sistema operacional antes de ser passada para a matriz `argv` no programa.

- Uma cadeia de caracteres entre aspas duplas ("*String*") é interpretada como um único argumento, independentemente do espaço em branco contido em. Uma cadeia de caracteres entre aspas pode ser inserida em um argumento.

- Aspas duplas precedidas por uma barra invertida (\\") são interpretados como um caractere literal de aspas duplas (").

- As barras invertidas são interpretadas literalmente, a menos que precedam imediatamente as aspas duplas.

- Se um número de barras invertidas mesmo for seguido por aspas duplas, uma barra invertida é colocada na matriz de `argv` para cada par de barras invertidas, e aspas duplas são interpretadas como um delimitador de cadeia de caracteres.

- Se um número ímpar de barras invertidas for seguido por aspas duplas, uma barra invertida é colocada na matriz de `argv` para cada par de barras invertidas, e aspas duplas são "ignoradas" pela barra invertida restante, causando a colocação de aspas duplas (") literais em `argv`.

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

|Entrada de linha de comando|argv[1]|argv[2]|argv[3]|
|-------------------------|---------------|---------------|---------------|
|`"abc" d e`|`abc`|`d`|`e`|
|`a\\b d"e f"g h`|`a\\b`|`de fg`|`h`|
|`a\\\"b c d`|`a\"b`|`c`|`d`|
|`a\\\\"b c" d e`|`a\\b c`|`d`|`e`|

**Fim da seção específica da Microsoft**

## <a name="wildcard-expansion"></a>Expansão de curinga

**Seção específica da Microsoft**

Você pode usar caracteres curinga — o ponto de interrogação (?) e o asterisco (*) — para especificar argumentos de nome de arquivo e caminho na linha de comando.

Os argumentos de linha de comando são manipulados por uma rotina chamada `_setargv` (ou `_wsetargv` no ambiente de caracteres largos), que por padrão não expande curingas em cadeias de caracteres separadas na matriz de cadeia `argv`. Para obter mais informações sobre como habilitar a expansão de curinga, consulte [expandindo argumentos curinga](../c-language/expanding-wildcard-arguments.md).

**Fim da seção específica da Microsoft**

## <a name="customizing-c-command-line-processing"></a>Personalizando processamento de linha de comando C++

**Seção específica da Microsoft**

Se o seu programa não utiliza argumentos de linha de comando, é possível economizar um pequeno espaço suprimindo o uso da rotina de biblioteca que executa o processamento de linha de comando. Essa rotina é chamada de `_setargv` e é descrita na [expansão de curinga](../cpp/wildcard-expansion.md). Para suprimir seu uso, defina uma rotina que não faz nada no arquivo que contém a função `main` e nomeie-o `_setargv`. A chamada para `_setargv` é então satisfeita pela sua definição de `_setargv`, e a versão da biblioteca não é carregada.

Da mesma forma, se você nunca acessar a tabela de ambiente por meio do argumento `envp`, poderá fornecer sua própria rotina vazia a ser usada no lugar de `_setenvp`, a rotina de processamento de ambiente. Assim como com a função `_setargv`, `_setenvp` deve ser declarado como **extern "C"** .

Seu programa pode fazer chamadas para o `spawn` ou `exec` família de rotinas na biblioteca de tempo de execução do C. Se tiver, você não deverá suprimir a rotina de processamento de ambiente, pois essa rotina é usada para passar um ambiente do processo pai para o processo filho.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Veja também

[Conceitos básicos](../cpp/basic-concepts-cpp.md)
