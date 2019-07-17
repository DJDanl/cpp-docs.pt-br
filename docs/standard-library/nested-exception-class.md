---
title: Classe de nested_exception
ms.date: 11/04/2016
f1_keywords:
- exception/std::bad_exception
helpviewer_keywords:
- bad_exception class
ms.assetid: 5ae2c4ef-c7ad-4469-8a9e-a773e86bb000
ms.openlocfilehash: a568a8d9a3817883656406d63c3dd948539bb385
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68268518"
---
# <a name="nestedexception-class"></a>Classe de nested_exception

A classe descreve uma exceção para uso com herança múltipla. Ele captura a exceção tratada no momento e armazena-o para uso posterior.

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
|[rethrow_nested](#rethrow_nested)|Lança a exceção armazenada.|
|[nested_ptr](#nested_ptr)|Retorna a exceção armazenada.|

### <a name="op_as"></a> operador =

```cpp
nested_exception& operator=(const nested_exception&) = default;
```

### <a name="nested_ptr"></a> nested_ptr

```cpp
exception_ptr nested_ptr() const;
```

#### <a name="return-value"></a>Valor de retorno

A exceção armazenada capturada por este `nested_exception` objeto.

### <a name="rethrow_nested"></a> rethrow_nested

```cpp
[[noreturn]] void rethrow_nested() const;
```

#### <a name="remarks"></a>Comentários

Se `nested_ptr()` retorna um ponteiro nulo, as chamadas de função `std::terminate()`. Caso contrário, ele gera a exceção armazenada capturada pelo `*this`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<exception>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Classe exception](../standard-library/exception-class.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
