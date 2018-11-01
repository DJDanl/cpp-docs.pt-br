---
title: Manipuladores de Fluxo de Saída com um Argumento (int ou long)
ms.date: 11/04/2016
helpviewer_keywords:
- output streams, int or long argument manipulators
ms.assetid: 338f3164-b5e2-4c5a-a605-7d9dc3629ca1
ms.openlocfilehash: e093512af2741329c58db0b613453f3388bacdf2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50530978"
---
# <a name="output-stream-manipulators-with-one-argument-int-or-long"></a>Manipuladores de Fluxo de Saída com um Argumento (int ou long)

A biblioteca de classes iostream fornece um conjunto de macros para criar manipuladores com parâmetros. Manipuladores com um único **int** ou **longo** argumento são um caso especial. Para criar um manipulador de fluxo de saída que aceita um único **int** ou **longo** argumento (como `setw`), você deve usar a macro smanip, que é definida no \<iomanip >. Este exemplo define um manipulador `fillblank` que insere um número especificado de espaços em branco no fluxo:

## <a name="example"></a>Exemplo

```cpp
// output_stream_manip.cpp
// compile with: /GR /EHsc
#include <iostream>
#include <iomanip>
using namespace std;

void fb( ios_base& os, int l )
{
   ostream *pos = dynamic_cast<ostream*>(&os);
   if (pos)
   {
      for( int i=0; i < l; i++ )
      (*pos) << ' ';
   };
}

_Smanip<int>
   __cdecl fillblank(int no)
   {
   return (_Smanip<int>(&fb, no));
   }

int main( )
{
   cout << "10 blanks follow" << fillblank( 10 ) << ".\n";
}
```

## <a name="see-also"></a>Consulte também

[Manipuladores personalizados com argumentos](../standard-library/custom-manipulators-with-arguments.md)<br/>
