---
title: Encerramento do programa C++
description: 'Descreve as maneiras de :::no-loc(exit)::: um programa em linguagem C++.'
ms.date: 01/15/2020
helpviewer_keywords:
- terminating execution
- quitting applications
- :::no-loc(exit):::ing applications
- programs [C++], terminating
ms.assetid: fa0ba9de-b5f1-4e7b-aa65-e7932068b48c
no-loc:
- ':::no-loc(exit):::'
- ':::no-loc(abort):::'
- ':::no-loc(return):::'
- ':::no-loc(main):::'
- ':::no-loc(atexit):::'
- ':::no-loc(void):::'
ms.openlocfilehash: 216aef5dbe8d110f9d75d43b5009b89fc5bfda51
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227173"
---
# <a name="c-program-termination"></a>Encerramento do programa C++

Em C++, você pode :::no-loc(exit)::: um programa das seguintes maneiras:

- Chame a [:::no-loc(exit):::](:::no-loc(exit):::-function.md) função.
- Chame a [:::no-loc(abort):::](:::no-loc(abort):::-function.md) função.
- Execute uma [:::no-loc(return):::](:::no-loc(return):::-statement-cpp.md) instrução de `:::no-loc(main):::` .

## <a name="no-locexit-function"></a>Função :::no-loc(exit):::

A [:::no-loc(exit):::](../c-runtime-library/reference/:::no-loc(exit):::-:::no-loc(exit):::-:::no-loc(exit):::.md) função, declarada em \<stdlib.h> , encerra um programa em C++. O valor fornecido como um argumento para `:::no-loc(exit):::` é :::no-loc(return)::: Ed para o sistema operacional como :::no-loc(return)::: código ou código do programa :::no-loc(exit)::: . Por convenção, um :::no-loc(return)::: código zero significa que o programa foi concluído com êxito. Você pode usar as constantes EXIT_FAILURE e EXIT_SUCCESS, também definidas no \<stdlib.h> , para indicar o êxito ou a falha do seu programa.

A emissão de uma **`:::no-loc(return):::`** instrução da `:::no-loc(main):::` função é equivalente à chamada da `:::no-loc(exit):::` função com o :::no-loc(return)::: valor como seu argumento.

## <a name="no-locabort-function"></a>Função :::no-loc(abort):::

A [:::no-loc(abort):::](../c-runtime-library/reference/:::no-loc(abort):::.md) função, também declarada no arquivo de inclusão padrão \<stdlib.h> , encerra um programa em C++. A diferença entre o `:::no-loc(exit):::` e `:::no-loc(abort):::` o é que `:::no-loc(exit):::` permite que o processamento de encerramento de tempo de execução do C++ ocorra (destruidores de objeto global serão chamados), enquanto `:::no-loc(abort):::` encerra o programa imediatamente. A `:::no-loc(abort):::` função ignora o processo de destruição normal para objetos estáticos globais inicializados. Ele também ignora qualquer processamento especial que foi especificado usando a [:::no-loc(atexit):::](../c-runtime-library/reference/:::no-loc(atexit):::.md) função.

## <a name="no-locatexit-function"></a>Função :::no-loc(atexit):::

Use a [:::no-loc(atexit):::](../c-runtime-library/reference/:::no-loc(atexit):::.md) função para especificar ações que são executadas antes do encerramento do programa. Nenhum objeto estático global inicializado antes da chamada para **:::no-loc(atexit):::** é destruído antes da execução da :::no-loc(exit)::: função de processamento.

## <a name="no-locreturn-statement-in-no-locmain"></a>:::no-loc(return):::instrução em:::no-loc(main):::

A emissão [:::no-loc(return):::](:::no-loc(return):::-statement-cpp.md) de uma instrução de `:::no-loc(main):::` é funcionalmente equivalente à chamada da `:::no-loc(exit):::` função. Considere o exemplo a seguir:

```cpp
// :::no-loc(return):::_statement.cpp
#include <stdlib.h>
int :::no-loc(main):::()
{
    :::no-loc(exit):::( 3 );
    :::no-loc(return)::: 3;
}
```

As `:::no-loc(exit):::` **`:::no-loc(return):::`** instruções e no exemplo anterior são funcionalmente idênticas. No entanto, o C++ requer que funções com :::no-loc(return)::: tipos diferentes de **`:::no-loc(void):::`** :::no-loc(return)::: um valor. A **`:::no-loc(return):::`** instrução permite que você tenha :::no-loc(return)::: um valor de `:::no-loc(main):::` .

## <a name="destruction-of-static-objects"></a>Destruição de objetos estáticos

Quando você chama `:::no-loc(exit):::` ou executa uma **`:::no-loc(return):::`** instrução de `:::no-loc(main):::` , os objetos estáticos são destruídos na ordem inversa de sua inicialização (após a chamada para `:::no-loc(atexit):::` se houver). O exemplo a seguir mostra como realizar essa inicialização e as tarefas de limpeza.

### <a name="example"></a>Exemplo

No exemplo a seguir, os objetos estáticos `sd1` e `sd2` são criados e inicializados antes da entrada para `:::no-loc(main):::` . Depois que este programa termina usando a **`:::no-loc(return):::`** instrução, o primeiro `sd2` é destruído e, em seguida, `sd1` . O destruidor da classe `ShowData` fecha os arquivos associados a esses objetos estáticos.

```cpp
// using_:::no-loc(exit):::_or_:::no-loc(return):::1.cpp
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
   :::no-loc(void)::: Disp( char *szData ) {
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

int :::no-loc(main):::() {
   sd1.Disp( "hello to default device\n" );
   sd2.Disp( "hello to file hello.dat\n" );
}
```

Outra maneira de escrever o código é declarar os objetos `ShowData` com escopo de bloco, permitindo que eles sejam destruídos quando saírem do escopo:

```cpp
int :::no-loc(main):::() {
   ShowData sd1, sd2( "hello.dat" );

   sd1.Disp( "hello to default device\n" );
   sd2.Disp( "hello to file hello.dat\n" );
}
```

## <a name="see-also"></a>Confira também

[:::no-loc(main):::argumentos de linha de comando e de função](:::no-loc(main):::-function-command-line-args.md)
