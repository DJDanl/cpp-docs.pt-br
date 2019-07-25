---
title: Manipuladores de Fluxo de Saída com um Argumento (int ou long)
ms.date: 11/04/2016
helpviewer_keywords:
- output streams, int or long argument manipulators
ms.assetid: 338f3164-b5e2-4c5a-a605-7d9dc3629ca1
ms.openlocfilehash: 93e4de25323514eb4105814b565dc3ddc3fbb737
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68453005"
---
# <a name="output-stream-manipulators-with-one-argument-int-or-long"></a>Manipuladores de Fluxo de Saída com um Argumento (int ou long)

A biblioteca de classes iostream fornece um conjunto de macros para criar manipuladores com parâmetros. Os manipuladores com um único argumento **int** ou **Long** são um caso especial. Para criar um fluxo de saída manipulador que aceita um único argumento **inteiro** ou **longo** ( `setw`like), você deve usar a macro _Smanip, que é definida \<em iomanip >. Este exemplo define um manipulador `fillblank` que insere um número especificado de espaços em branco no fluxo:

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

[Manipuladores personalizados com argumentos](../standard-library/custom-manipulators-with-arguments.md)
