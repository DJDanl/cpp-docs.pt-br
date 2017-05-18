---
title: "Manipuladores de Fluxo de Saída com um Argumento (int ou long) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- output streams, int or long argument manipulators
ms.assetid: 338f3164-b5e2-4c5a-a605-7d9dc3629ca1
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 84cbc5d016f6796a1cab208a1d77b51ea2ac6ecb
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="output-stream-manipulators-with-one-argument-int-or-long"></a>Manipuladores de Fluxo de Saída com um Argumento (int ou long)
A biblioteca de classes iostream fornece um conjunto de macros para criar manipuladores com parâmetros. Manipuladores com um único argumento `int` ou `long` são um caso especial. Para criar um manipulador de fluxo de saída que aceita um único argumento `int` ou `long` (como `setw`), você deve usar a macro _Smanip, que é definida em \<iomanip >. Este exemplo define um manipulador `fillblank` que insere um número especificado de espaços em branco no fluxo:  
  
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


