---
title: "Refer&#234;ncias (C++) | Microsoft Docs"
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
  - "declarações, referências"
  - "objetos [C++], referenciando"
  - "referências"
  - "referências, declarando"
  - "referências, para ponteiros"
  - "referenciando objetos, sintaxe de declarador"
ms.assetid: 68156f7f-97a0-4b66-b26d-b25ade5e3bd8
caps.latest.revision: 12
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Refer&#234;ncias (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma referência, como um ponteiro, armazena o endereço de um objeto que está localizado em outro lugar na memória.  Ao contrário de um ponteiro, uma referência depois que ele é inicializado não pode ser feita se referir a um objeto diferente ou definido como null.  Há dois tipos de referências: referências lvalue que se referem a um nome variável e rvalue referências que se referem a um [objeto temporário](../cpp/temporary-objects.md).  A & operador significa uma referência de lvalue e a & & operador significa uma referência de rvalue ou uma referência universal \(rvalue ou l\-value\), dependendo do contexto.  
  
 As referências podem ser declaradas usando a seguinte sintaxe:  
  
```  
[storage-class-specifiers] [cv-qualifiers] type-specifiers   
[ms-modifier] declarator [= expression];  
```  
  
 Qualquer declarador válido que especifique uma referência pode ser usado.  A menos que se trate de uma referência para um tipo de matriz ou função, a seguinte sintaxe simplificada se aplica:  
  
```  
[storage-class-specifiers] [cv-qualifiers] type-specifiers [& or &&]   
[cv-qualifiers] identifier [= expression];  
```  
  
 As referências são declaradas usando a seguinte sequência:  
  
 1.  Os especificadores da declaração:  
  
-   Um especificador de classe de armazenamento opcional.  
  
-   Qualificadores opcionais **const** e\/ou `volatile`.  
  
-   O especificador de tipo: o nome de um tipo.  
  
-   2.  O declarador:  
  
-   Um modificador opcional específico da Microsoft.  Para obter mais informações, consulte [Modificadores específicos da Microsoft](../Topic/Microsoft-Specific%20Modifiers.md).  
  
-   A & operador ou & & operador.  
  
-   Qualificadores opcionais **const** e\/ou `volatile`.  
  
-   O identificador.  
  
 3.  Um inicializador opcional.  
  
 Os formatos mais complexos de declaradores associados a ponteiros para matrizes e funções também se aplicam às referências a matrizes e funções; consulte os tópicos sobre [ponteiros](../cpp/pointers-cpp.md) e [declaradores](http://msdn.microsoft.com/pt-br/8a7b9b51-92bd-4ac0-b3fe-0c4abe771838).  
  
 Vários declaradores e inicializadores podem aparecer em uma lista separada por vírgulas após um único especificador de declaração.  Por exemplo:  
  
```  
int &i;   
int &i, &j;   
```  
  
 As referências, os ponteiros e os objetos podem ser declarados juntos:  
  
```  
int &ref, *ptr, k;   
```  
  
 Uma referência contém o endereço de um objeto, mas se comporta sintaticamente como um objeto.  
  
 No programa a seguir, observe que o nome do objeto, `Today`, e a referência ao objeto, `TodayRef`, podem ser usados de forma idêntica em programas:  
  
## Exemplo  
  
```  
// references.cpp  
#include <stdio.h>  
struct S {  
   short i;  
};  
  
int main() {  
   S  s;   // Declare the object.  
   S& SRef = s;   // Declare the reference.  
   s.i = 3;  
  
   printf_s("%d\n", s.i);  
   printf_s("%d\n", SRef.i);  
  
   SRef.i = 4;  
   printf_s("%d\n", s.i);  
   printf_s("%d\n", SRef.i);  
}  
```  
  
  **3**  
**3**  
**4**  
**4**   
## Comentário  
 Tópicos desta seção:  
  
-   [Argumentos de funções de tipo de referência](../cpp/reference-type-function-arguments.md)  
  
-   [Retornos de funções de tipo de referência](../cpp/reference-type-function-returns.md)  
  
-   [Referências a ponteiros](../cpp/references-to-pointers.md)  
  
## Consulte também  
 [Inicializando referências](../misc/initializing-references.md)