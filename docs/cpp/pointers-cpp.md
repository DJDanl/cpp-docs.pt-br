---
title: "Ponteiros | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "declarações, ponteiros"
  - "declaradores, ponteiros"
  - "ponteiros"
  - "ponteiros, declarações"
ms.assetid: 595387c5-8e58-4670-848f-344c7caf985e
caps.latest.revision: 14
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Ponteiros
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os ponteiros são declarados usando a seguinte sequência:  
  
```  
[storage-class-specifiers] [cv-qualifiers] type-specifiers   
[ms-modifier] declarator ;  
```  
  
 onde qualquer declarador de ponteiro válido pode ser usado para `declarator`.  A sintaxe de um declarador de ponteiro simples é a seguinte:  
  
```  
* [cv-qualifiers] identifier [= expression]  
```  
  
 1.  Os especificadores da declaração:  
  
-   Um especificador de classe de armazenamento opcional.  Para obter mais informações, consulte [Especificadores](../cpp/specifiers.md).  
  
-   Uma palavra\-chave `const` ou `volatile` opcional que se aplica ao tipo do objeto que será o alvo do ponteiro.  
  
-   O especificador de tipo: o nome de um tipo que representa o tipo do objeto que será o alvo do ponteiro.  
  
 2.  O declarador:  
  
-   Um modificador opcional específico da Microsoft.  Para obter mais informações, consulte [Modificadores específicos da Microsoft](../Topic/Microsoft-Specific%20Modifiers.md).  
  
-   O operador `*`.  
  
-   Uma palavra\-chave `const` ou `volatile` opcional que se aplica ao próprio ponteiro.  
  
-   O identificador.  
  
-   Um inicializador opcional.  
  
 O declarador de um ponteiro para função tem esta aparência:  
  
```  
(* [cv-qualifiers] identifier )( argument-list ) [cv-qualifers]  
[exception specification] [= expression];  
```  
  
-   Para uma matriz de ponteiros, a sintaxe é semelhante a esta:  
  
```  
* identifier [ [ constant-expression ] ]  
```  
  
-   No entanto, os declaradores de ponteiro podem ser mais complexos.  Para obter mais informações, consulte [Declaradores](http://msdn.microsoft.com/pt-br/8a7b9b51-92bd-4ac0-b3fe-0c4abe771838).  
  
-   Vários declaradores e seus inicializadores podem aparecer juntos em uma única declaração em uma lista separada por vírgulas que segue o especificador da declaração.  
  
 Um exemplo simples de uma declaração de ponteiro é:  
  
```  
char *pch;  
```  
  
 A declaração acima especifica que `pch` aponta para um objeto do tipo `char`.  
  
 Um exemplo mais complexo é:  
  
```  
static unsigned int * const ptr;  
```  
  
 A declaração acima especifica que `ptr` é um ponteiro de constante para um objeto do tipo `unsigned` `int` com duração de armazenamento estático.  
  
 O exemplo a seguir mostra como vários ponteiros são declarados e inicializados:  
  
```  
static int *p = &i, *q = &j;  
```  
  
 No exemplo acima, os ponteiros p e q apontam para objetos do tipo `int` e são inicializados para os endereços de i e j respectivamente.  O especificador de classe de armazenamento `static` se aplica aos dois ponteiros.  
  
## Exemplo  
  
```  
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
  
  **0x0012FEC8**  
**0x0012FEC8 2**  
**0x0012FEC8 7**  
**j is 10**  
**0x00320850 5**  
**0x00320850 0**  
**0x00320854 10**  
**0x00320858 20**  
**0x0032085C 30**  
**0x00320860 40**  
**dog dog**   
## Exemplo  
 Outro exemplo ilustra o uso de ponteiros em estruturas de dados; neste caso, uma lista vinculada.  
  
```  
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
  
  **`a 45 d a 789 d q`a \(add node\)  d \(display list\)  q \(quit\)**  
**enter a number:**   
**a \(add node\)  d \(display list\)  q \(quit\)**  
**node 1 \= 45**  
**a \(add node\)  d \(display list\)  q \(quit\)**  
**enter a number:**   
**a \(add node\)  d \(display list\)  q \(quit\)**  
**node 1 \= 45**  
**node 2 \= 789**  
**a \(add node\)  d \(display list\)  q \(quit\)**   
## Consulte também  
 [C\+\+ Abstract Declarators](http://msdn.microsoft.com/pt-br/e7e18c18-0cad-4450-942b-d27e1d4dd088)   
 [Adição de tipos de ponteiro](../misc/addition-of-pointer-types.md)   
 [Operador de indireção: \*](../cpp/indirection-operator-star.md)   
 [Operador Address\-of: &](../cpp/address-of-operator-amp.md)