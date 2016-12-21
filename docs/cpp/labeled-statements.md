---
title: "Instru&#231;&#245;es identificadas | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "goto"
  - "case"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Instrução rotulada"
  - "instruções, rotulado"
ms.assetid: 456a26d5-0fcc-4d1a-b71f-fa9ff3d73b91
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#245;es identificadas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Rótulos são usados para transferir o controle do programa diretamente para a instrução especificada.  
  
```  
identifier :  statement  
case constant-expression :  statement  
default :  statement  
```  
  
 O escopo de um rótulo é a função inteira na qual é declarado.  
  
## Comentários  
 Há três tipos de instruções rotuladas.  Todos usam dois\-pontos para separar qualquer tipo do rótulo da instrução.  O uso de rótulos padrão e case são específicos das instruções case.  
  
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
  
 A aparência de um rótulo *identifier* no programa de origem declara um rótulo.  Apenas uma instrução [goto](../cpp/goto-statement-cpp.md) pode transferir o controle para um rótulo *identifier*.  O fragmento de código a seguir ilustra o uso da instrução `goto` e de um rótulo *identifier*:  
  
 Um rótulo não pode aparecer sozinho: deve estar sempre anexado a uma instrução.  Se for necessário usar um rótulo sozinho, coloque uma instrução nula depois do rótulo.  
  
 O rótulo tem o escopo da função e não pode ser redeclarado dentro da função.  No entanto, o mesmo nome pode ser usado como um rótulo em funções diferentes.  
  
```  
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
  
 Rótulos que aparecem depois da palavra\-chave **case** não podem aparecer também fora de uma instrução `switch`.  \(Essa restrição também se aplica à palavra\-chave **default**.\) O seguinte fragmento de código mostra o uso correto de rótulos **case**:  
  
```  
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
  
## Rótulos na instrução case  
 Rótulos que aparecem depois da palavra\-chave **case** não podem aparecer também fora de uma instrução `switch`.  \(Essa restrição também se aplica à palavra\-chave **default**.\) O seguinte fragmento de código mostra o uso correto de rótulos **case**:  
  
```  
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
  
## Rótulos na instrução goto  
 A aparência de um rótulo *identifier* no programa de origem declara um rótulo.  Apenas um [goto](../cpp/goto-statement-cpp.md) instrução pode transferir o controle para um *identificador* rótulo.  O fragmento de código a seguir ilustra o uso do `goto` instrução e um *identificador* rótulo:  
  
 Um rótulo não pode aparecer sozinho: deve estar sempre anexado a uma instrução.  Se for necessário usar um rótulo sozinho, coloque uma instrução nula depois do rótulo.  
  
 O rótulo tem o escopo da função e não pode ser redeclarado dentro da função.  No entanto, o mesmo nome pode ser usado como um rótulo em funções diferentes.  
  
```  
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
  
## Consulte também  
 [Visão geral de instruções C\+\+](../cpp/overview-of-cpp-statements.md)   
 [Instrução switch \(C\+\+\)](../cpp/switch-statement-cpp.md)