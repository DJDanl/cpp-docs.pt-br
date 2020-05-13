---
title: Ponteiros para membros
ms.date: 11/04/2016
helpviewer_keywords:
- declarations, pointers
- class members [C++], pointers to
- pointers, to members
- members [C++], pointers to
- pointers, declarations
ms.assetid: f42ddb79-9721-4e39-95b1-c56b55591f68
ms.openlocfilehash: adffacc3ddc08679d7db4e17e027d8a7dbe8a92b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81320329"
---
# <a name="pointers-to-members"></a>Ponteiros para membros

As declarações dos ponteiros para os membros são casos especiais de declarações do ponteiro.  Eles são declarados usando a seguinte seqüência:

> *os especificadores de classe de armazenamento*optam<sub>por</sub> *cv-qualifiers*<sub>optar por</sub> *tipo-especificador* *ms-modificador*<sub>optar</sub> *nome* **`::*`** qualificado *cv-qualifiers* *opt-qualifiers* <sub>optr</sub> *pm-initializer*<sub>opt optoptopt</sub>**`;`**

1. O especificador de declaração:

   - Um especificador de classe de armazenamento opcional.

   - **Const** opcional e especificadores **voláteis.**

   - O especificador de tipo: o nome de um tipo. É o tipo de membro a ser apontado, não a classe.

1. O declarador:

   - Um modificador opcional específico da Microsoft. Para obter mais informações, consulte [modificadores específicos da Microsoft](../cpp/microsoft-specific-modifiers.md).

   - O nome qualificado da classe que contém os membros a serem apontados.

   - O __`::`__ operador.

   - O __`*`__ operador.

   - **Const** opcional e especificadores **voláteis.**

   - O identificador que nomeia o ponteiro para o membro.

1. Um inicializador opcional de ponteiro para membro:

   - O **`=`** operador.

   - O **`&`** operador.

   - O nome qualificado da classe.

   - O __`::`__ operador.

   - O nome de um membro não estático da classe do tipo apropriado.

Como sempre, vários declaradores (e quaisquer inicializadores associados) são permitidos em uma única declaração. Um ponteiro para membro não pode apontar para um membro estático **`void`** da classe, um membro do tipo de referência ou .

Um ponteiro para um membro de uma classe difere de um ponteiro normal: ele tem tanto informações de tipo para o tipo de membro quanto para a classe a que o membro pertence. Um ponteiro normal (tem o endereço de) identifica somente um único objeto na memória. Um ponteiro para um membro de uma classe identifica esse membro em qualquer instância da classe. O exemplo a seguir declara uma classe, `Window`, e alguns ponteiros para os dados de membro.

```cpp
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

No exemplo anterior, `pwCaption` está um ponteiro `Window` para qualquer membro `char*`de classe que seja do tipo . O tipo de `pwCaption` é `char * Window::*`. O fragmento de código a seguir declara ponteiros para as funções de membro `SetCaption` e `GetCaption`.

```cpp
const char * (Window::*pfnwGC)() = &Window::GetCaption;
bool (Window::*pfnwSC)( const char * ) = &Window::SetCaption;
```

Os ponteiros `pfnwGC` e `pfnwSC` apontam para `GetCaption` e `SetCaption` da classe `Window`, respectivamente. O código copia informações para a legenda da janela diretamente usando o ponteiro para o membro `pwCaption`:

```cpp
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

A diferença **`.*`** entre **`->*`** os operadores (os operadores de ponteiro **`.*`** para membro) é que o operador **`->*`** seleciona membros dadas a uma referência de objeto ou objeto, enquanto o operador seleciona membros através de um ponteiro. Para obter mais informações sobre esses operadores, consulte [Expressões com operadores de ponteiro para membro](../cpp/pointer-to-member-operators-dot-star-and-star.md).

O resultado dos operadores de ponteiro para membro é o tipo do membro. Nesse caso, use `char *`.

O fragmento de código a seguir invoca as funções do membro `GetCaption` e `SetCaption` usando ponteiros para os membros:

```cpp
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

O endereço de um membro estático não é um ponteiro para um membro. É um ponteiro regular para a única instância do membro estático. Apenas uma instância de um membro estático existe para todos os objetos de uma determinada classe. Isso significa que você pode usar**&** o endereço<strong>\*</strong>comum de ( ) e desreferenciar ( ) operadores.

## <a name="pointers-to-members-and-virtual-functions"></a>Ponteiros para membros e funções virtuais

Invocar uma função virtual através de uma função pointer-to-member funciona como se a função tivesse sido chamada diretamente. A função correta é examinada na tabela v e invocada.

A chave para as funções virtuais funcionarem, como sempre, é chamá-las por meio de um ponteiro para uma classe base. (Para obter mais informações sobre funções virtuais, consulte [Funções Virtuais](../cpp/virtual-functions.md).)

O código a seguir mostra como chamar uma função virtual com uma função de ponteiro para membro:

```cpp
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
