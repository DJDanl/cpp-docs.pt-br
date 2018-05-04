---
title: Operador Delete (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- delete_cpp
dev_langs:
- C++
helpviewer_keywords:
- delete keyword [C++], syntax
- delete keyword [C++], deallocating objects
- delete keyword [C++]
ms.assetid: de39c900-3f57-489c-9598-dcb73c4b3930
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3b523f5c10cbd28dfb2d584ea8241bc1518cf925
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="delete-operator-c"></a>Operador delete (C++)
Desaloca um bloco de memória.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
[::] delete cast-expression  
[::] delete [ ] cast-expression  
```  
  
## <a name="remarks"></a>Comentários  
 O *expressão de conversão* argumento deve ser um ponteiro para um bloco de memória alocada anteriormente para um objeto criado com o [novo operador](../cpp/new-operator-cpp.md). O **excluir** operador tem um resultado do tipo `void` e, portanto, não retorna um valor. Por exemplo:  
  
```  
CDialog* MyDialog = new CDialog;  
// use MyDialog  
delete MyDialog;  
```  
  
 Usando **excluir** em um ponteiro para um objeto não alocado com **novo** fornece resultados imprevisíveis. No entanto, você pode usar **excluir** em um ponteiro com o valor 0. Esta disposição significa que, quando **novo** retorna 0 em caso de falha, excluindo o resultado de uma falha **novo** operação é inofensiva. Consulte [o novo e excluir operadores](../cpp/new-and-delete-operators.md) para obter mais informações.  
  
 O **novo** e **excluir** operadores também podem ser usados para tipos internos, inclusive matrizes. Se `pointer` fizer referência a uma matriz, coloque parênteses vazios antes de `pointer`:  
  
```  
int* set = new int[100];  
//use set[]  
delete [] set;  
```  
  
 Usando o **excluir** operador em um objeto anula a alocação de memória. Um programa que remova a referência de um ponteiro após a exclusão do objeto pode ter resultados imprevisíveis ou falhar.  
  
 Quando **excluir** é usado para desalocar memória para um objeto de classe do C++, destruidor do objeto é chamado antes que a memória do objeto é desalocada (se o objeto tem um destruidor).  
  
 Se o operando para o **excluir** operador é um l-value modificável, seu valor será indefinido depois que o objeto é excluído.  
  
## <a name="using-delete"></a>Usando delete  
 Há duas variantes de sintaxe para a [operador delete](../cpp/delete-operator-cpp.md): um para objetos únicos e outro para matrizes de objetos. O fragmento de código a seguir mostra como elas são diferentes:  
  
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
  
 Os dois casos a seguir produzem resultados indefinidos: usando o formato da matriz de exclusão (delete [ ]) em um objeto e usando o formulário que não de matriz de exclusão em uma matriz.  
  
## <a name="example"></a>Exemplo  
 Para obter exemplos de como usar **excluir**, consulte [novo operador](../cpp/new-operator-cpp.md).  
  
## <a name="how-delete-works"></a>Como delete funciona  
 O operador delete invoca a função **operador delete**.  
  
 Para objetos não é do tipo de classe ([classe](../cpp/class-cpp.md), [struct](../cpp/struct-cpp.md), ou [união](../cpp/unions.md)), o operador de exclusão global é invocado. Em objetos do tipo de classe, o nome da função de desalocação é resolvido no escopo global se a expressão de exclusão começar com o operador unário de resolução de escopo (::). Caso contrário, o operador Delete invoca o destruidor para um objeto antes de desalocar a memória (se o ponteiro não for nulo). O operador delete pode ser definido em uma base por classe; se não houver nenhuma definição para uma classe específica, a exclusão global do operador é chamada. Se a expressão de exclusão for usada para desalocar um objeto da classe cujo tipo estático tem um destruidor virtual, a função de desalocação é resolvida pelo destruidor virtual do tipo dinâmico do objeto.  
  
## <a name="see-also"></a>Consulte também  
 [Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [Operadores new e delete](../cpp/new-and-delete-operators.md)   
 
