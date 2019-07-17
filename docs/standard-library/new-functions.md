---
title: Funções &lt;new&gt;
ms.date: 11/04/2016
f1_keywords:
- new/std::get_new_handler
- new/std::nothrow
- new/std::set_new_handler
ms.assetid: e250f06a-b025-4509-ae7a-5356d56aad7d
ms.openlocfilehash: c912e5be07ea0ebdd3148d30c80c39a5f8cfa1a5
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68243661"
---
# <a name="ltnewgt-functions"></a>Funções &lt;new&gt;

## <a name="get_new_handler"></a> get_new_handler

```cpp
new_handler get_new_handler() noexcept;
```

### <a name="remarks"></a>Comentários

Retorna o atual `new_handler`.

## <a name="launder"></a> launder

```cpp
template <class T>
    constexpr T* launder(T* ptr) noexcept;
```

### <a name="parameters"></a>Parâmetros

*PTR*\
O endereço de um byte na memória que contém um objeto cujo tipo é semelhante ao *T*.

### <a name="return-value"></a>Valor de retorno

Um valor do tipo *T\**  que aponta para X.

### <a name="remarks"></a>Comentários

Também conhecido como uma barreira de otimização do ponteiro.

Usado como uma expressão constante quando o valor do argumento pode ser usado em uma expressão constante. Um byte de armazenamento é acessível por meio de um valor de ponteiro que aponta para um objeto se dentro do armazenamento ocupado por outro objeto, um objeto com um ponteiro semelhante.

### <a name="example"></a>Exemplo

```cpp
struct X { const int n; };

X *p = new X{3};
const int a = p->n;
new (p) X{5}; // p does not point to new object because X::n is const
const int b = p->n; // undefined behavior
const int c = std::launder(p)->n; // OK
```

## <a name="nothrow"></a> nothrow

Fornece um objeto a ser usado como um argumento para o **nothrow** as versões do **novos** e **excluir**.

```cpp
extern const std::nothrow_t nothrow;
```

### <a name="remarks"></a>Comentários

O objeto é usado como um argumento de função para corresponder ao tipo de parâmetro [std::nothrow_t](../standard-library/nothrow-t-structure.md).

### <a name="example"></a>Exemplo

Consulte [operador new](../standard-library/new-operators.md#op_new) e [operador new&#91;&#93;](../standard-library/new-operators.md#op_new_arr) para obter exemplos de como `std::nothrow_t` é usado como um parâmetro de função.

## <a name="set_new_handler"></a> set_new_handler

Instala uma função de usuário que deve ser chamado quando **operador new** falhar ao tentar alocar memória.

```cpp
new_handler set_new_handler(new_handler Pnew) throw();
```

### <a name="parameters"></a>Parâmetros

*Pnew*\
O `new_handler` a serem instalados.

### <a name="return-value"></a>Valor de retorno

0 na primeira chamada e o anterior `new_handler` em chamadas subsequentes.

### <a name="remarks"></a>Comentários

A função armazenará *Pnew* em uma static [novo manipulador](../standard-library/new-typedefs.md#new_handler) ponteiro que ele mantém e, em seguida, retorna o valor armazenado anteriormente no ponteiro. O novo manipulador é usado pelo [operador new](../standard-library/new-operators.md#op_new)(**size_t**).

### <a name="example"></a>Exemplo

```cpp
// new_set_new_handler.cpp
// compile with: /EHsc
#include<new>
#include<iostream>

using namespace std;
void __cdecl newhandler( )
{
   cout << "The new_handler is called:" << endl;
   throw bad_alloc( );
   return;
}

int main( )
{
   set_new_handler (newhandler);
   try
   {
      while ( 1 )
      {
         new int[5000000];
         cout << "Allocating 5000000 ints." << endl;
      }
   }
   catch ( exception e )
   {
      cout << e.what( ) << endl;
   }
}
```

```Output
Allocating 5000000 ints.
Allocating 5000000 ints.
Allocating 5000000 ints.
Allocating 5000000 ints.
Allocating 5000000 ints.
Allocating 5000000 ints.
Allocating 5000000 ints.
Allocating 5000000 ints.
Allocating 5000000 ints.
Allocating 5000000 ints.
Allocating 5000000 ints.
Allocating 5000000 ints.
Allocating 5000000 ints.
Allocating 5000000 ints.
Allocating 5000000 ints.
Allocating 5000000 ints.
Allocating 5000000 ints.
Allocating 5000000 ints.
Allocating 5000000 ints.
Allocating 5000000 ints.
Allocating 5000000 ints.
Allocating 5000000 ints.
Allocating 5000000 ints.
Allocating 5000000 ints.
The new_handler is called:
bad allocation
```
