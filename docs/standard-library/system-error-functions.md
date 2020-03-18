---
title: Funções &lt;system_error&gt;
ms.date: 03/15/2019
f1_keywords:
- system_error/std::generic_category
- system_error/std::make_error_code
- system_error/std::make_error_condition
- system_error/std::system_category
ms.assetid: 57d6f15f-f0b7-4e2f-80fe-31d3c320ee33
helpviewer_keywords:
- std::generic_category
- std::make_error_code
- std::make_error_condition
- std::system_category
ms.openlocfilehash: ab4d0d1ee810df8f719bba762262eb03bf899408
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79422419"
---
# <a name="ltsystem_errorgt-functions"></a>Funções &lt;system_error&gt;

## <a name="generic_category"></a>generic_category

Representa a categoria de erros genéricos.

```cpp
const error_category& generic_category() noexcept;
```

### <a name="remarks"></a>Comentários

O objeto `generic_category` é uma implementação de [error_category](../standard-library/error-category-class.md).

## <a name="is_error_code_enum_v"></a>is_error_code_enum_v

```cpp
template <class T> 
    inline constexpr bool is_error_code_enum_v = is_error_code_enum<T>::value;
```

## <a name="is_error_condition_enum_v"></a>is_error_condition_enum_v

```cpp
template <class T> 
    inline constexpr bool is_error_condition_enum_v = is_error_condition_enum<T>::value;
```

## <a name="make_error_code"></a>make_error_code

Cria um objeto de código de erro.

```cpp
error_code make_error_code(std::errc error) noexcept;
```

### <a name="parameters"></a>parâmetros

*erro*\
O `std::errc` valor de enumeração a ser armazenado no objeto de código de erro.

### <a name="return-value"></a>Valor retornado

O objeto de código de erro.

### <a name="remarks"></a>Comentários

## <a name="make_error_condition"></a>make_error_condition

Cria um objeto de condição de erro.

```cpp
error_condition make_error_condition(std::errc error) noexcept;
```

### <a name="parameters"></a>parâmetros

*erro*\
O `std::errc` valor de enumeração a ser armazenado no objeto de código de erro.

### <a name="return-value"></a>Valor retornado

O objeto de condição de erro.

### <a name="remarks"></a>Comentários

## <a name="system_category"></a>system_category

Representa a categoria de erros causados por estouros de nível inferior do sistema.

```cpp
const error_category& system_category() noexcept;
```

### <a name="remarks"></a>Comentários

O objeto `system_category` é uma implementação de [error_category](../standard-library/error-category-class.md).
