---
title: Operador delete (C++)
ms.date: 08/12/2019
f1_keywords:
- delete_cpp
helpviewer_keywords:
- delete keyword [C++], syntax
- delete keyword [C++], deallocating objects
- delete keyword [C++]
ms.assetid: de39c900-3f57-489c-9598-dcb73c4b3930
ms.openlocfilehash: 19f92e2aa62adf1ede4c0e6ab1187fd9e4106e68
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87221686"
---
# <a name="delete-operator-c"></a>Operador delete (C++)

Desaloca um bloco de memória.

## <a name="syntax"></a>Sintaxe

> [ `::` ] `delete` *expressão de conversão*\
> [ `::` ] `delete []` *expressão de conversão*

## <a name="remarks"></a>Comentários

O argumento *Cast-Expression* deve ser um ponteiro para um bloco de memória alocada anteriormente para um objeto criado com o [operador New](../cpp/new-operator-cpp.md). O **`delete`** operador tem um resultado do tipo **`void`** e, portanto, não retorna um valor. Por exemplo:

```cpp
CDialog* MyDialog = new CDialog;
// use MyDialog
delete MyDialog;
```

O uso **`delete`** de um ponteiro para um objeto não alocado com o **`new`** fornece resultados imprevisíveis. No entanto, você pode usar **`delete`** em um ponteiro com o valor 0. Essa provisão significa que, quando **`new`** retorna 0 em caso de falha, a exclusão do resultado de uma operação com falha **`new`** é inofensiva. Para obter mais informações, consulte [os operadores New e Delete](../cpp/new-and-delete-operators.md).

Os **`new`** **`delete`** operadores e também podem ser usados para tipos internos, incluindo matrizes. Se se `pointer` referir a uma matriz, coloque colchetes vazios ( `[]` ) antes de `pointer` :

```cpp
int* set = new int[100];
//use set[]
delete [] set;
```

O uso do **`delete`** operador em um objeto desaloca sua memória. Um programa que remova a referência de um ponteiro após a exclusão do objeto pode ter resultados imprevisíveis ou falhar.

Quando **`delete`** é usado para desalocar memória para um objeto de classe C++, o destruidor do objeto é chamado antes de a memória do objeto ser desalocada (se o objeto tiver um destruidor).

Se o operando para o **`delete`** operador for um valor l modificável, seu valor será indefinido depois que o objeto for excluído.

Se a opção de compilador [/SDL (habilitar verificações de segurança adicionais)](/cpp/build/reference/sdl-enable-additional-security-checks) for especificada, o operando para o **`delete`** operador será definido como um valor inválido depois que o objeto for excluído.

## <a name="using-delete"></a>Usando delete

Há duas variantes sintáticas para o [operador Delete](../cpp/delete-operator-cpp.md): uma para objetos únicos e a outra para matrizes de objetos. O fragmento de código a seguir mostra como diferem:

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

Os dois casos a seguir produzem resultados indefinidos: usando a forma de matriz de Delete ( `delete []` ) em um objeto e usando a forma nonarray de Delete em uma matriz.

## <a name="example"></a>Exemplo

Para obter exemplos de como usar **`delete`** , consulte [novo operador](../cpp/new-operator-cpp.md).

## <a name="how-delete-works"></a>Como excluir funciona

O operador Delete invoca a função de **exclusão do operador**.

Para objetos que não são do tipo de classe ([Class](../cpp/class-cpp.md), [struct](../cpp/struct-cpp.md)ou [Union](../cpp/unions.md)), o operador global Delete é invocado. Para objetos do tipo de classe, o nome da função de desalocação será resolvido no escopo global se a expressão de exclusão começar com o operador unário de resolução de escopo ( `::` ). Caso contrário, o operador Delete invoca o destruidor para um objeto antes de desalocar a memória (se o ponteiro não for nulo). O operador delete pode ser definido em uma base por classe; se não houver nenhuma definição para uma classe específica, a exclusão global do operador é chamada. Se a expressão de exclusão for usada para desalocar um objeto da classe cujo tipo estático tem um destruidor virtual, a função de desalocação é resolvida pelo destruidor virtual do tipo dinâmico do objeto.

## <a name="see-also"></a>Confira também

[Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)\
[Palavras-chave](../cpp/keywords-cpp.md)\
[Operadores New e Delete](../cpp/new-and-delete-operators.md)
