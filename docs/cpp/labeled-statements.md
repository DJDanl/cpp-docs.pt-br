---
title: Instruções de rotulado | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- labeled statement
- statements, labeled
ms.assetid: 456a26d5-0fcc-4d1a-b71f-fa9ff3d73b91
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f5c5d626f51778782f41f4f16b7e23ad4c5acb73
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39404441"
---
# <a name="labeled-statements"></a>Instruções rotuladas
Rótulos são usados para transferir o controle do programa diretamente para a instrução especificada.  
  
```  
identifier :  statement  
case constant-expression :  statement  
default :  statement  
```  
  
 O escopo de um rótulo é a função inteira na qual é declarado.  
  
## <a name="remarks"></a>Comentários  
 Há três tipos de instruções rotuladas. Todos usam dois-pontos para separar qualquer tipo do rótulo da instrução. O uso de rótulos padrão e case são específicos das instruções case.  
  
```cpp  
#include <iostream>   
using namespace std;   
  
void test_label(int x) {  
  
    if (x == 1){  
        goto label1;  
    }  
    goto label2;  
  
label1:  
    cout << "in label1" << endl;  
    return;  
  
label2:  
    cout << "in label2" << endl;  
    return;  
}  
  
int main() {  
    test_label(1);  // in label1   
    test_label(2);  // in label2  
}  
```  
  
 **A instrução goto**  
  
 A aparência de um *identificador* rótulo no programa de origem declara um rótulo. Somente um [goto](../cpp/goto-statement-cpp.md) instrução pode transferir o controle para um *identificador* rótulo. O fragmento de código a seguir ilustra o uso do **goto** instrução e um *identificador* rótulo:  
  
 Um rótulo não pode aparecer sozinho: deve estar sempre anexado a uma instrução. Se for necessário usar um rótulo sozinho, coloque uma instrução nula depois do rótulo.  
  
 O rótulo tem o escopo da função e não pode ser redeclarado dentro da função. No entanto, o mesmo nome pode ser usado como um rótulo em funções diferentes.  
  
```cpp 
// labels_with_goto.cpp  
// compile with: /EHsc  
#include <iostream>  
int main() {  
   using namespace std;  
   goto Test2;  
  
   cout << "testing" << endl;  
  
   Test2:  
      cerr << "At Test2 label." << endl;  
}  
  
//Output: At Test2 label.  
```  
  
 **A instrução case**  
  
 Rótulos que aparecem depois de **caso** palavra-chave também não pode aparecer fora de uma **alternar** instrução. (Essa restrição também se aplica a **padrão** palavra-chave.) O fragmento de código a seguir mostra o uso correto de **caso** rótulos:  
  
```cpp 
// Sample Microsoft Windows message processing loop.  
switch( msg )  
{  
   case WM_TIMER:    // Process timer event.  
      SetClassWord( hWnd, GCW_HICON, ahIcon[nIcon++] );  
      ShowWindow( hWnd, SW_SHOWNA );  
      nIcon %= 14;  
      Yield();  
      break;  
  
   case WM_PAINT:  
      memset( &ps, 0x00, sizeof(PAINTSTRUCT) );  
      hDC = BeginPaint( hWnd, &ps );   
      EndPaint( hWnd, &ps );  
      break;  
  
   default:  
      // This choice is taken for all messages not specifically  
      //  covered by a case statement.  
  
      return DefWindowProc( hWnd, Message, wParam, lParam );  
      break;  
}  
```  
  
## <a name="labels-in-the-case-statement"></a>Rótulos na instrução case  
 Rótulos que aparecem depois de **caso** palavra-chave também não pode aparecer fora de uma **alternar** instrução. (Essa restrição também se aplica a **padrão** palavra-chave.) O fragmento de código a seguir mostra o uso correto de **caso** rótulos:  
  
```cpp 
// Sample Microsoft Windows message processing loop.  
switch( msg )  
{  
   case WM_TIMER:    // Process timer event.  
      SetClassWord( hWnd, GCW_HICON, ahIcon[nIcon++] );  
      ShowWindow( hWnd, SW_SHOWNA );  
      nIcon %= 14;  
      Yield();  
      break;  
  
   case WM_PAINT:  
      // Obtain a handle to the device context.  
      // BeginPaint will send WM_ERASEBKGND if appropriate.  
  
      memset( &ps, 0x00, sizeof(PAINTSTRUCT) );  
      hDC = BeginPaint( hWnd, &ps );  
  
      // Inform Windows that painting is complete.  
  
      EndPaint( hWnd, &ps );  
      break;  
  
   case WM_CLOSE:  
      // Close this window and all child windows.  
  
      KillTimer( hWnd, TIMER1 );  
      DestroyWindow( hWnd );  
      if ( hWnd == hWndMain )  
         PostQuitMessage( 0 );  // Quit the application.  
      break;  
  
   default:  
      // This choice is taken for all messages not specifically  
      //  covered by a case statement.  
  
      return DefWindowProc( hWnd, Message, wParam, lParam );  
      break;  
}  
```  
  
## <a name="labels-in-the-goto-statement"></a>Rótulos na instrução goto  
 A aparência de um *identificador* rótulo no programa de origem declara um rótulo. Somente um [goto](../cpp/goto-statement-cpp.md) instrução pode transferir o controle para um *identificador* rótulo. O fragmento de código a seguir ilustra o uso do **goto** instrução e um *identificador* rótulo:  
  
 Um rótulo não pode aparecer sozinho: deve estar sempre anexado a uma instrução. Se for necessário usar um rótulo sozinho, coloque uma instrução nula depois do rótulo.  
  
 O rótulo tem o escopo da função e não pode ser redeclarado dentro da função. No entanto, o mesmo nome pode ser usado como um rótulo em funções diferentes.  
  
```cpp 
// labels_with_goto.cpp  
// compile with: /EHsc  
#include <iostream>  
int main() {  
   using namespace std;  
   goto Test2;  
  
   cout << "testing" << endl;  
  
   Test2:  
      cerr << "At Test2 label." << endl;  
// At Test2 label.  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral de instruções C++](../cpp/overview-of-cpp-statements.md)   
 [Instrução switch (C++)](../cpp/switch-statement-cpp.md)