---
title: Definições de argumento
ms.date: 11/04/2016
helpviewer_keywords:
- envp argument
- main function, arguments
- arguments [C++], for main function
- argv argument
- argc argument
ms.assetid: 6148cbf3-ebe8-44f2-b277-de4b723991c7
ms.openlocfilehash: 14e5ea3a051d81828c5f88ac16df60b6ebb5b559
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69498812"
---
# <a name="argument-definitions"></a>Definições de argumento

Os argumentos do protótipo

```cpp
int main( int argc, char* argv[], char* envp[]);
int wmain( int argc, wchar_t* argv[], wchar_t* envp[]);
```

permitem uma análise conveniente dos argumentos na linha de comando e, opcionalmente, acesso a variáveis de ambiente. As definições dos argumentos são as seguintes:

*argc*<br/>
Um inteiro que contém a contagem de argumentos que seguem em *argv*. O parâmetro *argc* é sempre maior ou igual a 1.

*argv*<br/>
Uma matriz de cadeias de caracteres terminadas em nulo que representam argumentos de linha de comando inseridos pelo usuário do programa. Por convenção, `argv[0]` é o comando com o qual o programa é invocado, `argv[1]` é o primeiro argumento de linha de comando `argv[argc]`e assim por diante, que é sempre nulo. Consulte [Personalizando o processamento de linha de comando](../cpp/customizing-cpp-command-line-processing.md) para obter informações sobre como suprimir o processamento de linha de comando.

O primeiro argumento de linha de comando sempre é `argv[1]` e o último é `argv[argc - 1]`.

> [!NOTE]
> Por convenção, `argv[0]` é o comando com o qual o programa é invocado.  No entanto, é possível gerar um processo usando [CreateProcess](/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulefilenamew) e, se você usar o primeiro e o segundo argumentos (*lpApplicationName* e *lpCommandLine*) `argv[0]` , talvez não seja o nome do executável; use [GetModuleFileName ](/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulefilenamew)para recuperar o nome do executável e seu caminho totalmente qualificado.

## <a name="microsoft-specific"></a>Específico da Microsoft

*envp*<br/>
A matriz *envp* , que é uma extensão comum em muitos sistemas UNIX, é usada na Microsoft C++. Trata-se de uma matriz de cadeias de caracteres que representam as variáveis definidas no ambiente do usuário. Essa matriz é encerrada por uma entrada NULL. Ele pode ser declarado como uma matriz de ponteiros para Char`char *envp[]`() ou como um ponteiro para ponteiros para`char **envp` **Char** (). Se o seu programa `wmain` usar em `main`vez de, use o tipo de dados **wchar_t** em vez de **Char**. O bloco de ambiente passou `main` para `wmain` e é uma cópia "congelada" do ambiente atual. Se você alterar posteriormente o ambiente por meio de uma `putenv` chamada `_wputenv`para ou, o ambiente atual (como `getenv` retornado `_wgetenv` por or `_environ` e `_wenviron` a variável or) será alterado, mas o bloco apontado por envp não será alterado. Consulte [Personalizando o processamento de linha de comando](../cpp/customizing-cpp-command-line-processing.md) para obter informações sobre como suprimir o processamento do ambiente. Esse argumento é compatível com ANSI em C, mas não em C++.

**Fim da seção específica da Microsoft**

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como usar os argumentos *argc*, *argv*e *envp* para `main`:

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

## <a name="see-also"></a>Consulte também

[main: inicialização de programa](../cpp/main-program-startup.md)