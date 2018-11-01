---
title: Ponteiros (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- declarators, pointers
- declarations, pointers
- pointers [C++]
- pointers, declarations
ms.assetid: 595387c5-8e58-4670-848f-344c7caf985e
ms.openlocfilehash: a258a71b8b89643ee98785ee9dfbf30cdf128db7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50667864"
---
# <a name="pointers-c"></a>Ponteiros (C++)

Os ponteiros são declarados usando a seguinte sequência:

> \[*especificadores de classe de armazenamento*] \[ *qualificadores cv*] *especificadores de tipo* \[ *ms-modifier*]  *Declarador* **;**

onde qualquer Declarador de ponteiro válido pode ser usado para *declarador*. A sintaxe de um declarador de ponteiro simples é a seguinte:

> __\*__ \[*qualificadores CV*] *identificador* \[ **=** *expressão*]

1. Os especificadores da declaração:

   - Um especificador de classe de armazenamento opcional. Para obter mais informações, consulte [especificadores](../cpp/specifiers.md).

   - Um recurso opcional **const** ou **volátil** palavra-chave para o tipo do objeto a ser apontado para a aplicação.

   - O especificador de tipo: o nome de um tipo que representa o tipo do objeto que será o alvo do ponteiro.

1. O declarador:

   - Um modificador opcional específico da Microsoft. Para obter mais informações, consulte [modificadores específicos da Microsoft](../cpp/microsoft-specific-modifiers.md).

   - O __\*__ operador.

   - Um recurso opcional **const** ou **volátil** aplicando ao próprio ponteiro de palavra-chave.

   - O identificador.

   - Um inicializador opcional.

O declarador de um ponteiro para função tem esta aparência:

> __(\*__  \[ *qualificadores cv*] *identificador* **) (** *lista de argumentos* **)** \[ *qualificadores cv*] \[ *especificação de exceção*] \[ **=** *expressão*] **;**

Para uma matriz de ponteiros, a sintaxe é semelhante a esta:

> __\*__ *identificador* **\[** \[ *expressão constante*] **]**

Vários declaradores e seus inicializadores podem aparecer juntos em uma única declaração em uma lista separada por vírgulas que segue o especificador da declaração.

Um exemplo simples de uma declaração de ponteiro é:

```cpp
char *pch;
```

A declaração acima Especifica que `pch` aponta para um objeto do tipo **char**.

Um exemplo mais complexo é:

```cpp
static unsigned int * const ptr;
```

A declaração acima Especifica que `ptr` é um ponteiro constante para um objeto do tipo **não assinados** **int** com duração de armazenamento estático.

O exemplo a seguir mostra como vários ponteiros são declarados e inicializados:

```cpp
static int *p = &i, *q = &j;
```

No exemplo anterior, ponteiros p e q apontam para objetos do tipo **int** e são inicializados com os endereços de i e j respectivamente.  O especificador de classe de armazenamento **estático** se aplica a ambos os ponteiros.

## <a name="example"></a>Exemplo

```cpp
// pointer.cpp
// compile with: /EHsc
#include <iostream>
int main() {
   int i = 1, j = 2; // local variables on the stack
   int *p;

   // a pointer may be assigned to "point to" the value of
   // another variable using the & (address of) operator
   p = & j;

   // since j was on the stack, this address will be somewhere
   // on the stack.  Pointers are printed in hex format using
   // %p and conventionally marked with 0x.
   printf_s("0x%p\n",  p);

   // The * (indirection operator) can be read as "the value
   // pointed to by".
   // Since p is pointing to j, this should print "2"
   printf_s("0x%p %d\n",  p, *p);

   // changing j will change the result of the indirection
   // operator on p.
   j = 7;
   printf_s("0x%p %d\n",  p, *p );

   // The value of j can also be changed through the pointer
   // by making an assignment to the dereferenced pointer
   *p = 10;
   printf_s("j is %d\n", j); // j is now 10

   // allocate memory on the heap for an integer,
   // initialize to 5
   p = new int(5);

   // print the pointer and the object pointed to
   // the address will be somewhere on the heap
   printf_s("0x%p %d\n",  p, *p);

   // free the memory pointed to by p
   delete p;

   // At this point, dereferencing p with *p would trigger
   // a runtime access violation.

   // Pointer arithmetic may be done with an array declared
   // on the stack or allocated on the heap with new.
   // The increment operator takes into account the size
   // of the objects pointed to.
   p = new int[5];
   for (i = 0; i < 5; i++, p++) {
      *p = i * 10;
      printf_s("0x%p %d\n", p, *p);
   }

   // A common expression seen is dereferencing in combination
   // with increment or decrement operators, as shown here.
   // The indirection operator * takes precedence over the
   // increment operator ++.
   // These are particularly useful in manipulating char arrays.
   char s1[4] = "cat";
   char s2[4] = "dog";
   char* p1 = s1;
   char* p2 = s2;

   // the following is a string copy operation
   while (*p1++ = *p2++);

   // s2 was copied into s1, so now they are both equal to "dog"
   printf_s("%s %s", s1, s2);
}
```

```Output
0x0012FEC8
0x0012FEC8 2
0x0012FEC8 7
j is 10
0x00320850 5
0x00320850 0
0x00320854 10
0x00320858 20
0x0032085C 30
0x00320860 40
dog dog
```

## <a name="example"></a>Exemplo

Outro exemplo ilustra o uso de ponteiros em estruturas de dados; neste caso, uma lista vinculada.

```cpp
// pointer_linkedlist.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;

struct NewNode {
   NewNode() : node(0){}
   int i;
   NewNode * node;
};

void WalkList(NewNode * ptr) {
   if (ptr != 0) {
      int i = 1;
      while (ptr->node != 0 ) {
         cout << "node " << i++ << " = " << ptr->i << endl;
         ptr = ptr->node;
      }
      cout << "node " << i++ << " = " << ptr->i << endl;
   }
}

void AddNode(NewNode ** ptr) {
   NewNode * walker = 0;
   NewNode * MyNewNode = new NewNode;
   cout << "enter a number: " << endl;
   cin >> MyNewNode->i;

   if (*ptr == 0)
      *ptr = MyNewNode;
   else  {
      walker = *ptr;
      while (walker->node != 0)
         walker = walker->node;

      walker->node = MyNewNode;
   }
}

int main() {
   char ans = ' ';
   NewNode * ptr = 0;
   do {
      cout << "a (add node)  d (display list)  q (quit)" << endl;
      cin >> ans;
      switch (ans) {
      case 'a':
         AddNode(&ptr);
         break;
      case 'd':
         WalkList(ptr);
         break;
      }
   } while (ans != 'q');
}
```

```Output
a
45
d
a
789
d
qa (add node)  d (display list)  q (quit)
enter a number:
a (add node)  d (display list)  q (quit)
node 1 = 45
a (add node)  d (display list)  q (quit)
enter a number:
a (add node)  d (display list)  q (quit)
node 1 = 45
node 2 = 789
a (add node)  d (display list)  q (quit)
```

## <a name="see-also"></a>Consulte também

[Operador de indireção: *](../cpp/indirection-operator-star.md)<br/>
[Operador address-of: &](../cpp/address-of-operator-amp.md)
