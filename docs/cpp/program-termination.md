---
title: C++encerramento do programa
description: Descreve as maneiras de exit um C++programa em idioma.
ms.date: 01/15/2020
helpviewer_keywords:
- terminating execution
- quitting applications
- exiting applications
- programs [C++], terminating
ms.assetid: fa0ba9de-b5f1-4e7b-aa65-e7932068b48c
no-loc:
- exit
- abort
- return
- main
- atexit
- void
ms.openlocfilehash: f83c9d5da5b0a1127603a97fd7946e9cca43a7a5
ms.sourcegitcommit: e93f3e6a110fe38bc642055bdf4785e620d4220f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/16/2020
ms.locfileid: "76123949"
---
# <a name="c-program-termination"></a>C++encerramento do programa

No C++, você pode exit um programa das seguintes maneiras:

- Chame a função [exit](exit-function.md) .
- Chame a função [abort](abort-function.md) .
- Execute uma instrução [return](return-statement-cpp.md) da `main`.

## <a name="opno-locexit-function"></a>Função exit

A função [exit](../c-runtime-library/reference/exit-exit-exit.md) , declarada em \<STDLIB. h >, encerra C++ um programa. O valor fornecido como um argumento para `exit` é retornado ao sistema operacional como código de return do programa ou código de exit. Por convenção, um código de return zero significa que o programa foi concluído com êxito. Você pode usar as constantes EXIT_FAILURE e EXIT_SUCCESS, também definidas em \<STDLIB. h >, para indicar o êxito ou a falha do seu programa.

A emissão de uma instrução **return** da função `main` é equivalente a chamar a função `exit` com o valor return como seu argumento.

## <a name="opno-locabort-function"></a>Função abort

A função [abort](../c-runtime-library/reference/abort.md) , também declarada no arquivo de inclusão padrão \<STDLIB. h >, encerra C++ um programa. A diferença entre `exit` e `abort` é que `exit` permite que C++ o processamento de encerramento de tempo de execução ocorra (os destruidores de objeto global serão chamados), enquanto `abort` encerra o programa imediatamente. A função `abort` ignora o processo de destruição normal para objetos estáticos globais inicializados. Ele também ignora qualquer processamento especial que foi especificado usando a função [atexit](../c-runtime-library/reference/atexit.md) .

## <a name="opno-locatexit-function"></a>Função atexit

Use a função [atexit](../c-runtime-library/reference/atexit.md) para especificar ações que são executadas antes do encerramento do programa. Nenhum objeto estático global inicializado antes da chamada para **atexit** é destruído antes da execução da função de processamento de exit.

## <a name="opno-locreturn-statement-in-opno-locmain"></a>return instrução em main

A emissão de uma instrução de [return](return-statement-cpp.md) de `main` é funcionalmente equivalente à chamada da função `exit`. Considere o exemplo a seguir:

```cpp
// return_statement.cpp
#include <stdlib.h>
int main()
{
    exit( 3 );
    return 3;
}
```

As instruções `exit` e **return** no exemplo anterior são funcionalmente idênticas. No entanto, C++ o requer que as funções que têm tipos de return diferentes de **void** return um valor. A instrução **return** permite return um valor de `main`.

## <a name="destruction-of-static-objects"></a>Destruição de objetos estáticos

Quando você chama `exit` ou executa uma instrução **return** da `main`, os objetos estáticos são destruídos na ordem inversa de sua inicialização (após a chamada para `atexit`, se houver). O exemplo a seguir mostra como realizar essa inicialização e as tarefas de limpeza.

### <a name="example"></a>Exemplo

No exemplo a seguir, os objetos estáticos `sd1` e `sd2` são criados e inicializados antes da entrada para `main`. Depois que este programa é encerrado usando a instrução **return** , o primeiro `sd2` é destruído e, em seguida, `sd1`. O destruidor da classe `ShowData` fecha os arquivos associados a esses objetos estáticos.

```cpp
// using_exit_or_return1.cpp
#include <stdio.h>
class ShowData {
public:
   // Constructor opens a file.
   ShowData( const char *szDev ) {
   errno_t err;
      err = fopen_s(&OutputDev, szDev, "w" );
   }

   // Destructor closes the file.
   ~ShowData() { fclose( OutputDev ); }

   // Disp function shows a string on the output device.
   void Disp( char *szData ) {
      fputs( szData, OutputDev );
   }
private:
   FILE *OutputDev;
};

//  Define a static object of type ShowData. The output device
//   selected is "CON" -- the standard output device.
ShowData sd1 = "CON";

//  Define another static object of type ShowData. The output
//   is directed to a file called "HELLO.DAT"
ShowData sd2 = "hello.dat";

int main() {
   sd1.Disp( "hello to default device\n" );
   sd2.Disp( "hello to file hello.dat\n" );
}
```

Outra maneira de escrever o código é declarar os objetos `ShowData` com escopo de bloco, permitindo que eles sejam destruídos quando saírem do escopo:

```cpp
int main() {
   ShowData sd1, sd2( "hello.dat" );

   sd1.Disp( "hello to default device\n" );
   sd2.Disp( "hello to file hello.dat\n" );
}
```

## <a name="see-also"></a>Veja também

[main de função e argumentos de linha de comando](main-function-command-line-args.md)
