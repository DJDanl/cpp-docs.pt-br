---
title: Operador delete (C++)
ms.date: 11/04/2016
f1_keywords:
- delete_cpp
helpviewer_keywords:
- delete keyword [C++], syntax
- delete keyword [C++], deallocating objects
- delete keyword [C++]
ms.assetid: de39c900-3f57-489c-9598-dcb73c4b3930
ms.openlocfilehash: 5e4f5685ea1bb8cd7c405373ba774fe36af08672
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50524716"
---
# <a name="delete-operator-c"></a>Operador delete (C++)

Desaloca um bloco de memória.

## <a name="syntax"></a>Sintaxe

```
[::] delete cast-expression
[::] delete [ ] cast-expression
```

## <a name="remarks"></a>Comentários

O *cast-expression* argumento deve ser um ponteiro para um bloco de memória alocado anteriormente para um objeto criado com o [operador new](../cpp/new-operator-cpp.md). O **exclua** operador tem um resultado do tipo **void** e, portanto, não retorna um valor. Por exemplo:

```cpp
CDialog* MyDialog = new CDialog;
// use MyDialog
delete MyDialog;
```

Usando o **exclua** em um ponteiro para um objeto não alocado com **novos** tem resultados imprevisíveis. No entanto, você pode usar **excluir** em um ponteiro com o valor 0. Esse provisionamento significa que, quando **novos** retorna 0 em caso de falha, excluindo o resultado de uma falha na **novos** operação é inofensiva. Ver [novo e excluir operadores](../cpp/new-and-delete-operators.md) para obter mais informações.

O **novos** e **excluir** operadores também podem ser usados para tipos internos, inclusive matrizes. Se `pointer` fizer referência a uma matriz, coloque parênteses vazios antes de `pointer`:

```cpp
int* set = new int[100];
//use set[]
delete [] set;
```

Usando o **excluir** operador em um objeto desaloca sua memória. Um programa que remova a referência de um ponteiro após a exclusão do objeto pode ter resultados imprevisíveis ou falhar.

Quando **excluir** é usado para desalocar a memória para um objeto de classe do C++, o destruidor do objeto é chamado antes que a memória do objeto seja desalocada (se o objeto tem um destruidor).

Se o operando para o **excluir** operador é um l-value modificável, seu valor será indefinido após a exclusão do objeto.

## <a name="using-delete"></a>Usando delete

Há duas variantes sintáticas para o [operador delete](../cpp/delete-operator-cpp.md): uma para objetos únicos e outra para matrizes de objetos. O fragmento de código a seguir mostra como elas são diferentes:

```cpp
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

Para exemplos de uso **exclua**, consulte [operador new](../cpp/new-operator-cpp.md).

## <a name="how-delete-works"></a>Como delete funciona

O operador delete invoca a função **operador delete**.

Para objetos não é do tipo de classe ([classe](../cpp/class-cpp.md), [struct](../cpp/struct-cpp.md), ou [união](../cpp/unions.md)), o operador delete global é invocado. Em objetos do tipo de classe, o nome da função de desalocação é resolvido no escopo global se a expressão de exclusão começar com o operador unário de resolução de escopo (::). Caso contrário, o operador Delete invoca o destruidor para um objeto antes de desalocar a memória (se o ponteiro não for nulo). O operador delete pode ser definido em uma base por classe; se não houver nenhuma definição para uma classe específica, a exclusão global do operador é chamada. Se a expressão de exclusão for usada para desalocar um objeto da classe cujo tipo estático tem um destruidor virtual, a função de desalocação é resolvida pelo destruidor virtual do tipo dinâmico do objeto.

## <a name="see-also"></a>Consulte também

[Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Operadores new e delete](../cpp/new-and-delete-operators.md)