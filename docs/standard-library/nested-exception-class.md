---
title: Classe nested_exception
ms.date: 11/04/2016
f1_keywords:
- exception/std::bad_exception
helpviewer_keywords:
- bad_exception class
ms.assetid: 5ae2c4ef-c7ad-4469-8a9e-a773e86bb000
ms.openlocfilehash: 5741b3aa255f915500f5fe79ab5374c8c86f8814
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68460186"
---
# <a name="nestedexception-class"></a>Classe nested_exception

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

|||
|-|-|
|[operator=](#op_as)||

### <a name="functions"></a>Funções

|||
|-|-|
|[rethrow_nested](#rethrow_nested)|Gera a exceção armazenada.|
|[nested_ptr](#nested_ptr)|Retorna a exceção armazenada.|

### <a name="op_as"></a>operador =

```cpp
nested_exception& operator=(const nested_exception&) = default;
```

### <a name="nested_ptr"></a>nested_ptr

```cpp
exception_ptr nested_ptr() const;
```

#### <a name="return-value"></a>Valor de retorno

A exceção armazenada capturada `nested_exception` por este objeto.

### <a name="rethrow_nested"></a>rethrow_nested

```cpp
[[noreturn]] void rethrow_nested() const;
```

#### <a name="remarks"></a>Comentários

Se `nested_ptr()` o retornar um ponteiro nulo, a função `std::terminate()`chamará. Caso contrário, ele gera a exceção armazenada `*this`capturada pelo.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<exception>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Classe de exceção](../standard-library/exception-class.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
