---
title: Operadores &lt;new&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- new/std::operator delete
- new/std::operator new
ms.assetid: d1af4b56-9a95-4c65-ab01-bf43e982c7bd
author: corob-msft
ms.author: corob
ms.openlocfilehash: 327e37d1f13691eca049c98e8b1ab314b393a608
ms.sourcegitcommit: b92ca0b74f0b00372709e81333885750ba91f90e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/16/2018
ms.locfileid: "42539163"
---
# <a name="ltnewgt-operators"></a>Operadores &lt;new&gt;

||||
|-|-|-|
|[operador delete](#op_delete)|[operador delete[]](#op_delete_arr)|[operador new](#op_new)|
|[operador new[]](#op_new_arr)|

## <a name="op_delete"></a>  operador delete

A função que é chamada por uma expressão delete para desalocar o armazenamento de objetos individuais.

```cpp
void operator delete(void* ptr) throw();

void operator delete(void *,
    void*) throw();

void operator delete(void* ptr,
    const std::nothrow_t&) throw();
```

### <a name="parameters"></a>Parâmetros

*PTR* o ponteiro cujo valor é renderizado como inválido pela exclusão.

### <a name="remarks"></a>Comentários

A primeira função é chamada por uma expressão delete para renderizar o valor de *ptr* inválido. O programa pode definir uma função com essa assinatura de função que substitui a versão padrão definida pela biblioteca padrão C++. O comportamento necessário é aceitar um valor de *ptr* que é nulo ou que foi retornado por uma chamada anterior a [operador new](../standard-library/new-operators.md#op_new)(**size_t**).

O comportamento padrão para um valor nulo *ptr* é fazer nada. Qualquer outro valor de *ptr* deve ser um valor retornado anteriormente por uma chamada conforme descrita anteriormente. O comportamento padrão para um valor não nulo dos *ptr* é recuperar o armazenamento alocado pela chamada anterior. Não é especificado em quais condições parte ou todo esse armazenamento recuperado será alocado por uma chamada subsequente para `operator new`(**size_t**), ou para qualquer um dos `calloc`( **size_t**), `malloc`( **size_t**), ou `realloc`( **void\***, **size_t**).

A segunda função será chamada por uma expressão delete de posicionamento correspondente a uma nova expressão do formulário **new**( **std::size_t**). Ela não faz nada.

A terceira função é chamada por uma expressão delete de posicionamento correspondente a uma nova expressão do formulário **new**( **std::size_t**, **conststd::nothrow_t&**). O programa pode definir uma função com essa assinatura de função que substitui a versão padrão definida pela biblioteca padrão C++. O comportamento necessário é aceitar um valor de `ptr` que é nulo ou que foi retornado por uma chamada anterior para `operator new`( **size_t**). O comportamento padrão é avaliar **exclua**(`ptr`).

### <a name="example"></a>Exemplo

Ver [operador new](../standard-library/new-operators.md#op_new) para obter um exemplo que usam **operador delete**.

## <a name="op_delete_arr"></a>  operador delete[]

A função que é chamada por uma expressão delete para desalocar o armazenamento para uma matriz de objetos.

```cpp
void operator delete[](void* ptr) throw();

void operator delete[](void *,
    void*) throw();

void operator delete[](void* ptr,
    const std::nothrow_t&) throw();
```

### <a name="parameters"></a>Parâmetros

*PTR* o ponteiro cujo valor é renderizado como inválido pela exclusão.

### <a name="remarks"></a>Comentários

A primeira função é chamada uma `delete[]` expressão para renderizar o valor de *ptr* inválido. O programa pode ser substituído porque pode definir uma função com essa assinatura de função que substitui a versão padrão definida pela biblioteca padrão C++. O comportamento necessário é aceitar um valor de *ptr* que é nulo ou que foi retornado por uma chamada anterior a [operador new&#91;&#93;](../standard-library/new-operators.md#op_new_arr)(**size_t**). O comportamento padrão para um valor nulo *ptr* é fazer nada. Qualquer outro valor de *ptr* deve ser um valor retornado anteriormente por uma chamada conforme descrita anteriormente. O comportamento padrão para um valor não nulo dos *ptr* é recuperar o armazenamento alocado pela chamada anterior. Não é especificado em quais condições parte ou todo esse armazenamento recuperado será alocado por uma chamada subsequente para [operador new](../standard-library/new-operators.md#op_new)(**size_t**), ou para qualquer um dos `calloc`(**size_t**), `malloc`(**size_t**), ou `realloc`( **void\***, **size_t**).

A segunda função é chamada por um posicionamento `delete[]` expressão correspondente a uma `new[]` expressão da forma `new[]`(**std:: size_t**). Ela não faz nada.

A terceira função é chamada por uma expressão delete de posicionamento correspondente a uma expressão `new[]` do formulário `new[]`( **std::size_t**, **const std::nothrow_t&**). O programa pode definir uma função com essa assinatura de função que substitui a versão padrão definida pela biblioteca padrão C++. O comportamento necessário é aceitar um valor de *ptr* que é nulo ou que foi retornado por uma chamada anterior ao operador `new[]`(**size_t**). O comportamento padrão é avaliar `delete[]`( `ptr`).

### <a name="example"></a>Exemplo

Consulte [operador new&#91;&#93;](../standard-library/new-operators.md#op_new_arr) para obter exemplos do uso de `operator delete[]`.

## <a name="op_new"></a>  operador new

A função que é chamada por uma expressão new para alocar o armazenamento de objetos individuais.

```cpp
void* operator new(std::size_t count) throw(bad_alloc);

void* operator new(std::size_t count,
    const std::nothrow_t&) throw();

void* operator new(std::size_t count,
    void* ptr) throw();
```

### <a name="parameters"></a>Parâmetros

*Contagem de* o número de bytes de armazenamento a ser alocado.

*PTR* o ponteiro a ser retornado.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o endereço de byte mais baixo do armazenamento alocado recentemente. Ou *ptr*.

### <a name="remarks"></a>Comentários

A primeira função é chamada por uma nova expressão para alocar `count` bytes de armazenamento adequadamente alinhados para representar qualquer objeto desse tamanho. O programa pode definir uma função alternativa com essa assinatura de função que substitui a versão padrão definida pela biblioteca padrão C++ e, portanto, é substituível.

É o comportamento necessário para retornar um ponteiro não nulo apenas se o armazenamento puder ser alocado conforme solicitado. Cada alocação produz um ponteiro para o armazenamento separado de qualquer outro armazenamento alocado. A ordem e a proximidade de armazenamento alocado por chamadas sucessivas não estão especificadas. O valor armazenado inicial não é especificado. O ponteiro retornado aponta para o início (endereço mais baixo de byte) do armazenamento alocado. Se a contagem for zero, o valor retornado não será comparado de modo igual a qualquer outro valor retornado pela função.

O comportamento padrão é executar um loop. Dentro do loop, a função primeiro tenta alocar o armazenamento solicitado. Não é especificado se a tentativa envolve uma chamada para `malloc`( **size_t**). Se a tentativa for bem-sucedida, a função retornará um ponteiro para o armazenamento alocado. Caso contrário, a função chama o [manipulador new](../standard-library/new-typedefs.md#new_handler) designado. Se a função chamada retornar, o loop se repete. O loop é encerrado quando uma tentativa de alocar o armazenamento solicitado é bem-sucedida ou quando uma função chamada não retorna.

O comportamento necessário de um manipulador new é executar uma das seguintes operações:

- Disponibilizar mais armazenamento para alocação e retornar.

- Chame o **anular** ou **sair**(`int`).

- Lançar um objeto do tipo **bad_alloc.**

O comportamento padrão de um [manipulador new](../standard-library/new-typedefs.md#new_handler) é lançar um objeto do tipo `bad_alloc`. Um ponteiro nulo designa o manipulador new padrão.

A ordem e proximidade de armazenamento alocado por chamadas sucessivas para `operator new`(**size_t**) não for especificado, assim como os valores iniciais armazenados lá.

A segunda função é chamada por uma nova expressão de substituição para alocar `count` bytes de armazenamento adequadamente alinhados para representar qualquer objeto desse tamanho. O programa pode definir uma função alternativa com essa assinatura de função que substitui a versão padrão definida pela biblioteca padrão C++ e, portanto, é substituível.

O comportamento padrão é retornar `operator new`(`count`) se a função for bem-sucedida. Caso contrário, ele retornará um ponteiro nulo.

A terceira função é chamada por uma expressão **new** de posicionamento do formulário **new** ( *args*) T. Aqui, *args* consiste em um ponteiro de objeto único. Isso pode ser útil para criar um objeto em um endereço conhecido. A função retorna *ptr*.

Para liberar o armazenamento alocado por **operador new**, chame [operador delete](../standard-library/new-operators.md#op_delete).

Para obter informações sobre o comportamento de lançamento ou não lançamento de new, consulte [Operadores new e delete](../cpp/new-and-delete-operators.md).

### <a name="example"></a>Exemplo

```cpp
// new_op_new.cpp
// compile with: /EHsc
#include<new>
#include<iostream>

using namespace std;

class MyClass
{
public:
   MyClass( )
   {
      cout << "Construction MyClass." << this << endl;
   };

   ~MyClass( )
   {
      imember = 0; cout << "Destructing MyClass." << this << endl;
   };
   int imember;
};

int main( )
{
   // The first form of new delete
   MyClass* fPtr = new MyClass;
   delete fPtr;

   // The second form of new delete
   MyClass* fPtr2 = new( nothrow ) MyClass;
   delete fPtr2;

   // The third form of new delete
   char x[sizeof( MyClass )];
   MyClass* fPtr3 = new( &x[0] ) MyClass;
   fPtr3 -> ~MyClass();
   cout << "The address of x[0] is : " << ( void* )&x[0] << endl;
}
```

## <a name="op_new_arr"></a>  operador new[]

A função de alocação que é chamada por uma expressão new para alocar o armazenamento para uma matriz de objetos.

```cpp
void* operator new[](std::size_t count) throw(std::bad_alloc);

void* operator new[](std::size_t count,
    const std::nothrow_t&) throw();

void* operator new[](std::size_t count,
    void* ptr) throw();
```

### <a name="parameters"></a>Parâmetros

*Contagem de* o número de bytes de armazenamento a ser alocado para o objeto de matriz.

*PTR* o ponteiro a ser retornado.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o endereço de byte mais baixo do armazenamento alocado recentemente. Ou *ptr*.

### <a name="remarks"></a>Comentários

A primeira função é chamada por uma expressão `new[]` para alocar `count` bytes de armazenamento adequadamente alinhados para representar qualquer objeto de matriz desse tamanho ou menor. O programa pode definir uma função com essa assinatura de função que substitui a versão padrão definida pela biblioteca padrão C++. O comportamento necessário é a mesma usada para [operador new](../standard-library/new-operators.md#op_new)(**size_t**). O comportamento padrão é retornar `operator new`( `count`).

A segunda função é chamada por uma expressão `new[]` de substituição para alocar `count` bytes de armazenamento adequadamente alinhados para representar qualquer objeto de matriz desse tamanho. O programa pode definir uma função com essa assinatura de função que substitui a versão padrão definida pela biblioteca padrão C++. O comportamento padrão é retornar **operatornew**(`count`) se a função for bem-sucedida. Caso contrário, ele retornará um ponteiro nulo.

A terceira função é chamada por uma expressão `new[]` de posicionamento do formulário **new** ( *args*) **T**[ **N**]. Aqui, *args* consiste em um ponteiro de objeto único. A função retorna `ptr`.

Para liberar o armazenamento alocado por `operator new[]`, chame o [operador delete&#91;&#93;](../standard-library/new-operators.md#op_delete_arr).

Para obter informações sobre o comportamento de lançamento ou não lançamento de new, consulte [Operadores new e delete](../cpp/new-and-delete-operators.md).

### <a name="example"></a>Exemplo

```cpp
// new_op_alloc.cpp
// compile with: /EHsc
#include <new>
#include <iostream>

using namespace std;

class MyClass {
public:
   MyClass() {
      cout << "Construction MyClass." << this << endl;
   };

   ~MyClass() {
      imember = 0; cout << "Destructing MyClass." << this << endl;
      };
   int imember;
};

int main() {
   // The first form of new delete
   MyClass* fPtr = new MyClass[2];
   delete[ ] fPtr;

   // The second form of new delete
   char x[2 * sizeof( MyClass ) + sizeof(int)];

   MyClass* fPtr2 = new( &x[0] ) MyClass[2];
   fPtr2[1].~MyClass();
   fPtr2[0].~MyClass();
   cout << "The address of x[0] is : " << ( void* )&x[0] << endl;

   // The third form of new delete
   MyClass* fPtr3 = new( nothrow ) MyClass[2];
   delete[ ] fPtr3;
}
```

## <a name="see-also"></a>Consulte também

[\<new>](../standard-library/new.md)<br/>
