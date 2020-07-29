---
title: Manipuladores de Fluxo de Saída com um Argumento (int ou long)
ms.date: 11/04/2016
helpviewer_keywords:
- output streams, int or long argument manipulators
ms.assetid: 338f3164-b5e2-4c5a-a605-7d9dc3629ca1
ms.openlocfilehash: 203797eef95e3dab0c079e35baefcea99c3b966d
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87217656"
---
# <a name="output-stream-manipulators-with-one-argument-int-or-long"></a>Manipuladores de Fluxo de Saída com um Argumento (int ou long)

A biblioteca de classes iostream fornece um conjunto de macros para criar manipuladores com parâmetros. Os manipuladores com um **`int`** único **`long`** argumento ou são um caso especial. Para criar um fluxo de saída manipulador que aceita um **`int`** único **`long`** argumento ou (como `setw` ), você deve usar a macro _Smanip, que é definida em \<iomanip> . Este exemplo define um manipulador `fillblank` que insere um número especificado de espaços em branco no fluxo:

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

## <a name="see-also"></a>Confira também

[Manipuladores personalizados com argumentos](../standard-library/custom-manipulators-with-arguments.md)
