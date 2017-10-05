---
title: Ponteiros para membros | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- declarations, pointers
- class members, pointers to
- pointers, to members
- members, pointers to
- pointers, declarations
ms.assetid: f42ddb79-9721-4e39-95b1-c56b55591f68
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
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
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 98a6db086443c15964a1dcf0a345b2fbaccfa233
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="pointers-to-members"></a>Ponteiros para membros
As declarações dos ponteiros para os membros são casos especiais de declarações do ponteiro.  Elas são declaradas usando a seguinte sequência:  
  
```  
[storage-class-specifiers] [cv-qualifiers] type-specifiers [ms-modifier]qualified-name ::* [cv-qualifiers] identifier  
[= & qualified-name :: member-name];  
```  
  
1.  O especificador de declaração:  
  
    -   Um especificador de classe de armazenamento opcional.  
  
    -   Opcional **const** e/ou `volatile` especificadores.  
  
    -   O especificador de tipo: o nome de um tipo.  Este é o tipo de membro a ser apontado, não a classe.  
  
2.  O declarador:  
  
    -   Um modificador opcional específico da Microsoft. Para obter mais informações, consulte [modificadores específicos da Microsoft](../cpp/microsoft-specific-modifiers.md).  
  
    -   O nome qualificado da classe que contém os membros a serem apontados.   
  
    -   O operador ::.  
  
    -   O ** \* ** operador.  
  
    -   Opcional **const** e/ou `volatile` especificadores.  
  
    -   O identificador que nomeia o ponteiro para o membro.  
  
    -   Um inicializador opcional:  
  
 O ** = ** operador.  
  
 O ** & ** operador.  
  
 O nome qualificado da classe.  
  
 O operador `::`.  
  
 O nome de um membro não estático da classe de tipo apropriado.  
  
 Como sempre, vários declaradores (e quaisquer inicializadores associados) são permitidos em uma única declaração.  
  
 Um ponteiro para um membro de uma classe é diferente de um ponteiro regular somente porque tem as informações do tipo para o tipo do membro e para a classe a qual o membro pertence. Um ponteiro normal (tem o endereço de) identifica somente um único objeto na memória. Um ponteiro para um membro de uma classe identifica esse membro em qualquer instância da classe. O exemplo a seguir declara uma classe, `Window`, e alguns ponteiros para os dados de membro.  
  
```  
// pointers_to_members1.cpp  
class Window  
{  
public:  
   Window();                               // Default constructor.  
   Window( int x1, int y1,                 // Constructor specifying  
   int x2, int y2 );                       //  window size.  
bool SetCaption( const char *szTitle ); // Set window caption.  
   const char *GetCaption();               // Get window caption.  
   char *szWinCaption;                     // Window caption.  
};  
  
// Declare a pointer to the data member szWinCaption.  
char * Window::* pwCaption = &Window::szWinCaption;  
int main()  
{  
}  
```  
  
 No exemplo anterior, `pwCaption` é um ponteiro para qualquer membro da classe `Window` que tem o tipo **char\***. O tipo de `pwCaption` é `char * Window::*`. O fragmento de código a seguir declara ponteiros para as funções de membro `SetCaption` e `GetCaption`.  
  
```  
const char * (Window::*pfnwGC)() = &Window::GetCaption;  
bool (Window::*pfnwSC)( const char * ) = &Window::SetCaption;  
```  
  
 Os ponteiros `pfnwGC` e `pfnwSC` apontam para `GetCaption` e `SetCaption` da classe `Window`, respectivamente. O código copia informações para a legenda da janela diretamente usando o ponteiro para o membro `pwCaption`:  
  
```  
Window wMainWindow;  
Window *pwChildWindow = new Window;  
char   *szUntitled    = "Untitled -  ";  
int    cUntitledLen   = strlen( szUntitled );  
  
strcpy_s( wMainWindow.*pwCaption, cUntitledLen, szUntitled );  
(wMainWindow.*pwCaption)[cUntitledLen - 1] = '1';     //same as  
//wMainWindow.SzWinCaption [cUntitledLen - 1] = '1';  
strcpy_s( pwChildWindow->*pwCaption, cUntitledLen, szUntitled );   
(pwChildWindow->*pwCaption)[cUntitledLen - 1] = '2'; //same as //pwChildWindow->szWinCaption[cUntitledLen - 1] = '2';  
```  
  
 A diferença entre o **.\* ** e ** -> \* ** operadores (os operadores de ponteiro para membro) é que o **.\* ** operador seleciona membros devido a um objeto ou uma referência de objeto, enquanto o ** -> \* ** operador seleciona membros por meio de um ponteiro. (Para obter mais informações sobre esses operadores, consulte [expressões com operadores de ponteiro para membro](../cpp/pointer-to-member-operators-dot-star-and-star.md).)  
  
 O resultado dos operadores de ponteiro para membro é o tipo do membro — nesse caso, **char \* **.  
  
 O fragmento de código a seguir invoca as funções do membro `GetCaption` e `SetCaption` usando ponteiros para os membros:  
  
```  
// Allocate a buffer.  
enum {  
    sizeOfBuffer = 100  
};  
char szCaptionBase[sizeOfBuffer];  
  
// Copy the main window caption into the buffer  
//  and append " [View 1]".  
strcpy_s( szCaptionBase, sizeOfBuffer, (wMainWindow.*pfnwGC)() );  
strcat_s( szCaptionBase, sizeOfBuffer, " [View 1]" );  
// Set the child window's caption.  
(pwChildWindow->*pfnwSC)( szCaptionBase );  
```  
  
## <a name="restrictions-on-pointers-to-members"></a>Restrições em ponteiros para membros  
 O endereço de um membro estático não é um ponteiro para um membro. É um ponteiro normal para uma instância do membro estático. Porque existe apenas uma instância de um membro estático para todos os objetos de uma determinada classe, endereço-of comum **(&)** e desreferência **(\*)** operadores podem ser usados.  
  
## <a name="pointers-to-members-and-virtual-functions"></a>Ponteiros para membros e funções virtuais  
 Chamar uma função virtual por meio de uma função de ponteiro para membro funciona como se a função tivesse sido chamada diretamente; a função correta é procurada na tabela v e chamada.  
  
 A chave para as funções virtuais funcionarem, como sempre, é chamá-las por meio de um ponteiro para uma classe base. (Para obter mais informações sobre funções virtuais, consulte [funções virtuais](../cpp/virtual-functions.md).)  
  
 O código a seguir mostra como chamar uma função virtual com uma função de ponteiro para membro:  
  
```  
// virtual_functions.cpp  
// compile with: /EHsc  
#include <iostream>  
using namespace std;  
  
class Base  
{  
public:  
virtual void Print();  
};  
void (Base ::* bfnPrint)() = &Base :: Print;  
void Base :: Print()  
{  
cout << "Print function for class Base\n";  
}  
  
class Derived : public Base  
{  
public:  
void Print();  // Print is still a virtual function.  
};  
  
void Derived :: Print()  
{  
cout << "Print function for class Derived\n";  
}  
  
int main()  
{  
    Base   *bPtr;  
    Base    bObject;  
Derived dObject;  
bPtr = &bObject;    // Set pointer to address of bObject.  
(bPtr->*bfnPrint)();  
bPtr = &dObject;    // Set pointer to address of dObject.  
(bPtr->*bfnPrint)();  
}  
  
//Output: Print function for class Base  
Print function for class Derived  
```  
  
## <a name="see-also"></a>Consulte também  
 
