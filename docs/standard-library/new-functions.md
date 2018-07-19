---
title: Funções &lt;new&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- new/std::nothrow
- new/std::set_new_handler
ms.assetid: e250f06a-b025-4509-ae7a-5356d56aad7d
ms.openlocfilehash: f930fb43ea554e1dd445dabb382adecc6f67e35f
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38964949"
---
# <a name="ltnewgt-functions"></a>Funções &lt;new&gt;

|||
|-|-|
|[nothrow](#nothrow)|[set_new_handler](#set_new_handler)|

## <a name="nothrow"></a>  nothrow

Fornece um objeto a ser usado como um argumento para o **nothrow** as versões do **novos** e **excluir**.

```cpp
extern const std::nothrow_t nothrow;
```

### <a name="remarks"></a>Comentários

O objeto é usado como um argumento de função para corresponder ao tipo de parâmetro [std::nothrow_t](../standard-library/nothrow-t-structure.md).

### <a name="example"></a>Exemplo

Consulte [operador new](../standard-library/new-operators.md#op_new) e [operador new&#91;&#93;](../standard-library/new-operators.md#op_new_arr) para obter exemplos de como `std::nothrow_t` é usado como um parâmetro de função.

## <a name="set_new_handler"></a>  set_new_handler

Instala uma função de usuário que deve ser chamado quando **operador new** falhar ao tentar alocar memória.

```cpp
new_handler set_new_handler(new_handler Pnew) throw();
```

### <a name="parameters"></a>Parâmetros

*Pnew*  
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

## <a name="see-also"></a>Consulte também

[\<new>](../standard-library/new.md)<br/>
