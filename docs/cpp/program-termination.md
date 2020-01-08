---
title: C++encerramento do programa
ms.date: 12/10/2019
helpviewer_keywords:
- terminating execution
- quitting applications
- exiting applications
- programs [C++], terminating
ms.assetid: fa0ba9de-b5f1-4e7b-aa65-e7932068b48c
ms.openlocfilehash: a0e86cacd951327d39296a183be5ee4fbc36fd15
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75301334"
---
# <a name="c-program-termination"></a>C++encerramento do programa

No C++, você pode sair de um programa das seguintes maneiras:

- Chame a função [Exit](exit-function.md) .
- Chame a função [Abort](abort-function.md) .
- Execute uma instrução [Return](return-statement-cpp.md) de `main`.

## <a name="exit-function"></a>Função exit

A função [Exit](../c-runtime-library/reference/exit-exit-exit.md) , declarada em \<STDLIB. h >, encerra C++ um programa. O valor fornecido como um argumento para `exit` é retornado ao sistema operacional como código de retorno do programa ou código de saída. Por convenção, um código de retorno de zero indica que o programa foi encerrado com êxito. Você pode usar as constantes EXIT_FAILURE e EXIT_SUCCESS, também definidas em \<STDLIB. h >, para indicar o êxito ou a falha do seu programa.

Emitir uma instrução **Return** da função `main` é equivalente a chamar a função `exit` com o valor de retorno como seu argumento.

## <a name="abort-function"></a>Função abort

A função [Abort](../c-runtime-library/reference/abort.md) , também declarada no arquivo de inclusão padrão \<STDLIB. h >, encerra C++ um programa. A diferença entre `exit` e `abort` é que `exit` permite que C++ o processamento de encerramento de tempo de execução ocorra (os destruidores de objeto global serão chamados), enquanto `abort` encerra o programa imediatamente. A função `abort` ignora o processo de destruição normal para objetos estáticos globais inicializados. Ele também ignora qualquer processamento especial que foi especificado usando a função [atexit](../c-runtime-library/reference/atexit.md) .

## <a name="atexit-function"></a>Função atexit

Use a função [atexit](../c-runtime-library/reference/atexit.md) para especificar ações que são executadas antes do encerramento do programa. Nenhum objeto estático global inicializado antes da chamada para **atexit** é destruído antes da execução da função de processamento de saída.

## <a name="return-statement-in-main"></a>instrução de retorno no principal

Emitir uma instrução [Return](return-statement-cpp.md) de `main` é funcionalmente equivalente a chamar a função `exit`. Considere o exemplo a seguir:

```cpp
// return_statement.cpp
#include <stdlib.h>
int main()
{
    exit( 3 );
    return 3;
}
```

As instruções `exit` e **Return** no exemplo anterior são funcionalmente idênticas. No entanto, C++ o requer que as funções que têm tipos de retorno diferentes de **void** retornem um valor. A instrução **Return** permite que você retorne um valor de `main`.

## <a name="destruction-of-static-objects"></a>Destruição de objetos estáticos

Quando você chama `exit` ou executa uma instrução **Return** de `main`, os objetos estáticos são destruídos na ordem inversa de sua inicialização (após a chamada para `atexit`, se houver). O exemplo a seguir mostra como realizar essa inicialização e as tarefas de limpeza.

### <a name="example"></a>Exemplo

No exemplo a seguir, os objetos estáticos `sd1` e `sd2` são criados e inicializados antes da entrada para `main`. Depois que esse programa é encerrado usando a instrução **Return** , primeiro `sd2` é destruído e, em seguida, `sd1`. O destruidor da classe `ShowData` fecha os arquivos associados a esses objetos estáticos.

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

[main: inicialização do programa](main-program-startup.md)