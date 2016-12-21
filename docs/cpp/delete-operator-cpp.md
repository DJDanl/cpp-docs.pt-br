---
title: "Operador delete (C++) | Microsoft Docs"
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
  - "delete_cpp"
  - "delete"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "palavra-chave delete [C++]"
  - "palavra-chave delete [C++], desalocando objetos"
  - "palavra-chave delete [C++], sintaxe"
ms.assetid: de39c900-3f57-489c-9598-dcb73c4b3930
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operador delete (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Desaloca um bloco de memória.  
  
## Sintaxe  
  
```  
[::] delete cast-expression  
[::] delete [ ] cast-expression  
```  
  
## Comentários  
 O argumento *expressão de conversão* deve ser um ponteiro para um bloco de memória alocado anteriormente para um objeto criado com o [novo operador](../cpp/new-operator-cpp.md).  O operador **delete** tem um resultado do tipo `void` e, portanto, não retorna um valor.  Por exemplo:  
  
```  
CDialog* MyDialog = new CDialog;  
// use MyDialog  
delete MyDialog;  
```  
  
 Usar **delete** em um ponteiro para um objeto não alocado com **new** tem resultados imprevisíveis.  No entanto, você pode usar **delete** em um ponteiro com o valor 0.  Esse provisionamento significa que, quando **new** retorna 0 em falha, a exclusão do resultado de uma falha na operação **new** é inofensiva.  Consulte [Os operadores New e Delete](../cpp/new-and-delete-operators.md) para obter mais informações.  
  
 Os operadores **new** e **delete** também podem ser usados para tipos internos, inclusive matrizes.  Se `pointer` fizer referência a uma matriz, coloque parênteses vazios antes de `pointer`:  
  
```  
int* set = new int[100];  
//use set[]  
delete [] set;  
```  
  
 Usar o operador **delete** em um objeto desaloca sua memória.  Um programa que remova a referência de um ponteiro após a exclusão do objeto pode ter resultados imprevisíveis ou falhar.  
  
 Quando **delete** é usado para desalocar a memória para o objeto de classe do C\+\+, o destruidor do objeto é chamado antes que a memória do objeto seja desalocada \(se o objeto tiver um destruidor\).  
  
 Se o operando para o operador **delete** for um l\-value modificável, seu valor será indefinido após a exclusão do objeto.  
  
## Usando delete  
 Há duas variantes sintáticas para o [operador Delete](../cpp/delete-operator-cpp.md): uma para objetos únicos e o outra para matrizes de objetos.  O fragmento de código a seguir mostra como elas são diferentes:  
  
```  
// expre_Using_delete.cpp  
struct UDType   
{  
};  
  
int main()  
{  
   // Allocate a user-defined object, UDObject, and an object  
   //  of type double on the free store using the  
   //  new operator.  
   UDType *UDObject = new UDType;  
   double *dObject = new double;  
   // Delete the two objects.  
   delete UDObject;  
   delete dObject;   
   // Allocate an array of user-defined objects on the  
   // free store using the new operator.  
   UDType (*UDArr)[7] = new UDType[5][7];  
   // Use the array syntax to delete the array of objects.  
   delete [] UDArr;  
}  
```  
  
 Os dois casos a seguir produzem resultados indefinidos: usando o formato da matriz de exclusão \(delete \[ \]\) em um objeto e usando o formulário que não de matriz de exclusão em uma matriz.  
  
## Exemplo  
 Para obter exemplos de uso de **delete**, consulte [Operador new](../cpp/new-operator-cpp.md).  
  
## Como delete funciona  
 O [operador Delete](../cpp/delete-operator-cpp.md) invoca a função [de exclusão do operador](../Topic/operator%20delete%20Function.md).  
  
 Para objetos que não forem do tipo de classe \([classe](../cpp/class-cpp.md), [estrutura](../cpp/struct-cpp.md) ou [união](../cpp/unions.md)\), o operador global de exclusão será invocado.  Em objetos do tipo de classe, o nome da função de desalocação é resolvido no escopo global se a expressão de exclusão começar com o operador unário de resolução de escopo \(::\).  Caso contrário, o operador Delete invoca o destruidor para um objeto antes de desalocar a memória \(se o ponteiro não for nulo\).  O operador delete pode ser definido em uma base por classe; se não houver nenhuma definição para uma classe específica, a exclusão global do operador é chamada.  Se a expressão de exclusão for usada para desalocar um objeto da classe cujo tipo estático tem um destruidor virtual, a função de desalocação é resolvida pelo destruidor virtual do tipo dinâmico do objeto.  
  
## Consulte também  
 [Expressões com operadores unários](../Topic/Expressions%20with%20Unary%20Operators.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)   
 [Operadores new e delete](../cpp/new-and-delete-operators.md)   
 [Função operator delete](../Topic/operator%20delete%20Function.md)