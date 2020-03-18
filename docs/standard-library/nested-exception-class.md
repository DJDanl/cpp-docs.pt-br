---
title: Classe nested_exception
ms.date: 11/04/2016
f1_keywords:
- exception/std::nested_exception
helpviewer_keywords:
- nested_exception class
ms.assetid: 5ae2c4ef-c7ad-4469-8a9e-a773e86bb000
ms.openlocfilehash: ed58eb6cc074b54ae6801d2b11089af9a79f8c8f
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79441621"
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

|||
|-|-|
|[operator=](#op_as)||

### <a name="functions"></a>{1&gt;Funções&lt;1}

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

#### <a name="return-value"></a>Valor retornado

A exceção armazenada capturada por este objeto de `nested_exception`.

### <a name="rethrow_nested"></a>rethrow_nested

```cpp
[[noreturn]] void rethrow_nested() const;
```

#### <a name="remarks"></a>Comentários

Se `nested_ptr()` retornar um ponteiro nulo, a função chamará `std::terminate()`. Caso contrário, ele lança a exceção armazenada capturada por `*this`.

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** exceção de \<>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[classe de exceção](../standard-library/exception-class.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
