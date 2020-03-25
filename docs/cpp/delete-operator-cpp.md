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
ms.openlocfilehash: 2ffb307aa3eb6bb8d253129a550c95342ad497bc
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80189462"
---
# <a name="delete-operator-c"></a>Operador delete (C++)

Desaloca um bloco de memória.

## <a name="syntax"></a>Sintaxe

> [`::`] `delete` *expressão cast*\
> [`::`] `delete []` *expressão CAST*

## <a name="remarks"></a>Comentários

O argumento *Cast-Expression* deve ser um ponteiro para um bloco de memória alocada anteriormente para um objeto criado com o [operador New](../cpp/new-operator-cpp.md). O operador **delete** tem um resultado do tipo **void** e, portanto, não retorna um valor. Por exemplo:

```cpp
CDialog* MyDialog = new CDialog;
// use MyDialog
delete MyDialog;
```

O uso de **delete** em um ponteiro para um objeto não alocado com **New** fornece resultados imprevisíveis. No entanto, você pode usar **delete** em um ponteiro com o valor 0. Essa provisão significa que, quando o **novo** retorna 0 em caso de falha, a exclusão do resultado de uma **nova** operação com falha é inofensiva. Para obter mais informações, consulte [os operadores New e Delete](../cpp/new-and-delete-operators.md).

Os operadores **New** e **delete** também podem ser usados para tipos internos, incluindo matrizes. Se `pointer` se referir a uma matriz, coloque colchetes vazios (`[]`) antes de `pointer`:

```cpp
int* set = new int[100];
//use set[]
delete [] set;
```

O uso do operador **delete** em um objeto desaloca sua memória. Um programa que remova a referência de um ponteiro após a exclusão do objeto pode ter resultados imprevisíveis ou falhar.

Quando **delete** é usado para desalocar memória para C++ um objeto de classe, o destruidor do objeto é chamado antes de a memória do objeto ser desalocada (se o objeto tiver um destruidor).

Se o operando para o operador **delete** for um valor l modificável, seu valor será indefinido depois que o objeto for excluído.

Se a opção de compilador [/SDL (habilitar verificações de segurança adicionais)](/cpp/build/reference/sdl-enable-additional-security-checks) for especificada, o operando para o operador **delete** será definido como um valor inválido depois que o objeto for excluído.

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

Os dois casos a seguir produzem resultados indefinidos: usando a forma de matriz de Delete (`delete []`) em um objeto e usando a forma nonarray de Delete em uma matriz.

## <a name="example"></a>Exemplo

Para obter exemplos de como usar **delete**, consulte [New Operator](../cpp/new-operator-cpp.md).

## <a name="how-delete-works"></a>Como excluir funciona

O operador Delete invoca a função de **exclusão do operador**.

Para objetos que não são do tipo de classe ([Class](../cpp/class-cpp.md), [struct](../cpp/struct-cpp.md)ou [Union](../cpp/unions.md)), o operador global Delete é invocado. Para objetos do tipo de classe, o nome da função de desalocação será resolvido no escopo global se a expressão de exclusão começar com o operador unário de resolução de escopo (`::`). Caso contrário, o operador Delete invoca o destruidor para um objeto antes de desalocar a memória (se o ponteiro não for nulo). O operador delete pode ser definido em uma base por classe; se não houver nenhuma definição para uma classe específica, a exclusão global do operador é chamada. Se a expressão de exclusão for usada para desalocar um objeto da classe cujo tipo estático tem um destruidor virtual, a função de desalocação é resolvida pelo destruidor virtual do tipo dinâmico do objeto.

## <a name="see-also"></a>Confira também

[Expressões com operadores Unários](../cpp/expressions-with-unary-operators.md)\
\ [palavras-chave](../cpp/keywords-cpp.md)
[Operadores new e delete](../cpp/new-and-delete-operators.md)
