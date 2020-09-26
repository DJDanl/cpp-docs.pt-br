---
title: Encerramento do programa C++
description: Descreve as maneiras de exit um programa em linguagem C++.
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
ms.openlocfilehash: fd0c7699ae032b5551f4fbc37eb3b7fa999a168f
ms.sourcegitcommit: d9c94dcabd94537e304be0261b3263c2071b437b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/25/2020
ms.locfileid: "91352915"
---
# <a name="c-program-termination"></a>Encerramento do programa C++

Em C++, você pode exit um programa das seguintes maneiras:

- Chame a [exit](../c-runtime-library/reference/exit-exit-exit.md) função.
- Chame a [abort](../c-runtime-library/reference/abort.md) função.
- Execute uma [return](return-statement-cpp.md) instrução de `main` .

## <a name="no-locexit-function"></a>Função exit

A [exit](../c-runtime-library/reference/exit-exit-exit.md) função, declarada em \<stdlib.h> , encerra um programa em C++. O valor fornecido como um argumento para `exit` é return Ed para o sistema operacional como return código ou código do programa exit . Por convenção, um return código zero significa que o programa foi concluído com êxito. Você pode usar as constantes EXIT_FAILURE e EXIT_SUCCESS, também definidas no \<stdlib.h> , para indicar o êxito ou a falha do seu programa.

A emissão de uma **`return`** instrução da `main` função é equivalente à chamada da `exit` função com o return valor como seu argumento.

## <a name="no-locabort-function"></a>Função abort

A [abort](../c-runtime-library/reference/abort.md) função, também declarada no arquivo de inclusão padrão \<stdlib.h> , encerra um programa em C++. A diferença entre o `exit` e `abort` o é que `exit` permite que o processamento de encerramento de tempo de execução do C++ ocorra (destruidores de objeto global serão chamados), enquanto `abort` encerra o programa imediatamente. A `abort` função ignora o processo de destruição normal para objetos estáticos globais inicializados. Ele também ignora qualquer processamento especial que foi especificado usando a [atexit](../c-runtime-library/reference/atexit.md) função.

## <a name="no-locatexit-function"></a>Função atexit

Use a [atexit](../c-runtime-library/reference/atexit.md) função para especificar ações que são executadas antes do encerramento do programa. Nenhum objeto estático global inicializado antes da chamada para **atexit** é destruído antes da execução da exit função de processamento.

## <a name="no-locreturn-statement-in-no-locmain"></a>return instrução em main

A emissão [return](return-statement-cpp.md) de uma instrução de `main` é funcionalmente equivalente à chamada da `exit` função. Considere o seguinte exemplo:

```cpp
// return_statement.cpp
#include <stdlib.h>
int main()
{
    exit( 3 );
    return 3;
}
```

As `exit` **`return`** instruções e no exemplo anterior são funcionalmente idênticas. No entanto, o C++ requer que funções com return tipos diferentes de **`void`** return um valor. A **`return`** instrução permite que você tenha return um valor de `main` .

## <a name="destruction-of-static-objects"></a>Destruição de objetos estáticos

Quando você chama `exit` ou executa uma **`return`** instrução de `main` , os objetos estáticos são destruídos na ordem inversa de sua inicialização (após a chamada para `atexit` se houver). O exemplo a seguir mostra como realizar essa inicialização e as tarefas de limpeza.

### <a name="example"></a>Exemplo

No exemplo a seguir, os objetos estáticos `sd1` e `sd2` são criados e inicializados antes da entrada para `main` . Depois que este programa termina usando a **`return`** instrução, o primeiro `sd2` é destruído e, em seguida, `sd1` . O destruidor da classe `ShowData` fecha os arquivos associados a esses objetos estáticos.

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

## <a name="see-also"></a>Confira também

[main argumentos de linha de comando e de função](main-function-command-line-args.md)
