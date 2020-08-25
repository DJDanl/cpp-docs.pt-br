---
title: Classe nested_exception
ms.date: 11/04/2016
f1_keywords:
- exception/std::nested_exception
helpviewer_keywords:
- nested_exception class
ms.assetid: 5ae2c4ef-c7ad-4469-8a9e-a773e86bb000
ms.openlocfilehash: 4ab48f714e8b4de1a47674f1af8fe25467279f94
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88836433"
---
# <a name="nested_exception-class"></a>Classe nested_exception

A classe descreve uma exceção para uso com várias heranças. Ele captura a exceção atualmente manipulada e a armazena para uso posterior.

## <a name="syntax"></a>Sintaxe

```cpp
class nested_exception {
    public:
        nested_exception();
        nested_exception(const nested_exception&) = default;
        virtual ~nested_exception() = default; // access functions
};
```

## <a name="members"></a>Membros

### <a name="operators"></a>Operadores

|Nome|Descrição|
|-|-|
|[operador =](#op_as)|Operador de atribuição.|

### <a name="functions"></a>Funções

|Nome|Descrição|
|-|-|
|[rethrow_nested](#rethrow_nested)|Gera a exceção armazenada.|
|[nested_ptr](#nested_ptr)|Retorna a exceção armazenada.|

### <a name="operator"></a><a name="op_as"></a> operador =

```cpp
nested_exception& operator=(const nested_exception&) = default;
```

### <a name="nested_ptr"></a><a name="nested_ptr"></a> nested_ptr

```cpp
exception_ptr nested_ptr() const;
```

#### <a name="return-value"></a>Valor Retornado

A exceção armazenada capturada por este `nested_exception` objeto.

### <a name="rethrow_nested"></a><a name="rethrow_nested"></a> rethrow_nested

```cpp
[[noreturn]] void rethrow_nested() const;
```

#### <a name="remarks"></a>Comentários

Se `nested_ptr()` o retornar um ponteiro nulo, a função chamará `std::terminate()` . Caso contrário, ele gera a exceção armazenada capturada pelo **`*this`** .

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<exception>

**Namespace:** std

## <a name="see-also"></a>Confira também

[Classe de exceção](../standard-library/exception-class.md)\
[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
