---
title: Usando saída ou retorno
ms.date: 11/04/2016
f1_keywords:
- Exit
helpviewer_keywords:
- exit function
- return keyword [C++], using for program termination
ms.assetid: b5136c5c-2505-4229-8691-2a1d6a98760b
ms.openlocfilehash: d60084c0d07d3eeb3f49a1fea53de04d150a701b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62152716"
---
# <a name="using-exit-or-return"></a>Usando saída ou retorno

Quando você chama **saia** ou execute uma **retornar** instrução from `main`, objetos estáticos são destruídos na ordem inversa da inicialização. O exemplo a seguir mostra como realizar essa inicialização e as tarefas de limpeza.

## <a name="example"></a>Exemplo

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

No exemplo anterior, os objetos estáticos `sd1` e `sd2` são criados e inicializados antes da entrada em `main`. Depois que esse programa terminar de usar o **retornar** instrução, primeiro `sd2` é destruído e, em seguida, `sd1`. O destruidor da classe `ShowData` fecha os arquivos associados a esses objetos estáticos.

Outra maneira de escrever o código é declarar os objetos `ShowData` com escopo de bloco, permitindo que eles sejam destruídos quando saírem do escopo:

```cpp
int main() {
   ShowData sd1, sd2( "hello.dat" );

   sd1.Disp( "hello to default device\n" );
   sd2.Disp( "hello to file hello.dat\n" );
}
```

## <a name="see-also"></a>Consulte também

[Considerações de término adicionais](../cpp/additional-termination-considerations.md)