---
title: Definições de argumento | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- envp argument
- main function, arguments
- arguments [C++], for main function
- argv argument
- argc argument
ms.assetid: 6148cbf3-ebe8-44f2-b277-de4b723991c7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4a401caad212978372bcb02b412fa8a9648b7170
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37942354"
---
# <a name="argument-definitions"></a>Definições de argumento
Os argumentos do protótipo  
  
```cpp 
  
int main( int argc, char* argv[], char* envp[]);
int wmain( int argc, wchar_t* argv[], wchar_t* envp[]);  
```  
  
 permitem uma análise conveniente dos argumentos na linha de comando e, opcionalmente, acesso a variáveis de ambiente. As definições dos argumentos são as seguintes:  
  
 *argc*  
 Um inteiro que contém a contagem de argumentos que se seguem em *argv*. O *argc* parâmetro é sempre maior que ou igual a 1.  
  
 *argv*  
 Uma matriz de cadeias de caracteres terminadas em nulo que representam argumentos de linha de comando inseridos pelo usuário do programa. Por convenção, `argv` **[0]** é o comando com a qual o programa é invocado, `argv` **[1]** é o primeiro argumento de linha de comando e assim por diante, até `argv`  **[**`argc`**]**, que é sempre nulo. Ver [Personalizando o processamento de linha de comando](../cpp/customizing-cpp-command-line-processing.md) para obter informações sobre como suprimir o processamento de linha de comando.  
  
 O primeiro argumento de linha de comando é sempre `argv` **[1]** e o último é `argv` **[** `argc` - 1 **]**.  
  
> [!NOTE]
>  Por convenção, `argv`**[0]** é o comando com que o programa é invocado.  No entanto, é possível gerar um processo usando [CreateProcess](http://msdn.microsoft.com/library/windows/desktop/ms683197) e, se você usar o primeiro e segundo argumentos (`lpApplicationName` e `lpCommandLine`), `argv` **[0]** pode não ser o nome do executável; Use [GetModuleFileName](http://msdn.microsoft.com/library/windows/desktop/ms683197) para recuperar o nome do executável e o caminho totalmente qualificado.  
  
## <a name="microsoft-specific"></a>Específico da Microsoft  
 *envp*  
 O *envp* matriz, que é uma extensão comum em muitos sistemas UNIX, é usada no Microsoft C++. Trata-se de uma matriz de cadeias de caracteres que representam as variáveis definidas no ambiente do usuário. Essa matriz é encerrada por uma entrada NULL. Ela pode ser declarada como uma matriz de ponteiros para **char (char** \*envp []**)** ou como um ponteiro para ponteiros para **char (char** \* \* envp **)**. Se seu programa usa **wmain** em vez de **principal**, use o **wchar_t** em vez de **char**. O bloco de ambiente passado para **principal** e **wmain** é uma cópia "congelada" do ambiente atual. Se você alterar subsequentemente o ambiente por meio de uma chamada para **putenv** ou `_wputenv`, o ambiente atual (conforme retornado por `getenv` / `_wgetenv` e o `_environ` /  `_wenviron` variável) será alteração, mas o bloco apontado por envp não será alterado. Ver [Personalizando o processamento de linha de comando](../cpp/customizing-cpp-command-line-processing.md) para obter informações sobre como suprimir o processamento de ambiente. Esse argumento é compatível com ANSI em C, mas não em C++.  
  
**Fim da seção específica da Microsoft**  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra como usar o *argc*, *argv*, e *envp* argumentos a serem **principal**:  
  
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
 [main: inicialização do programa](../cpp/main-program-startup.md)