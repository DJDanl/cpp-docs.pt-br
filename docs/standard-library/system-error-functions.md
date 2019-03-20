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
ms.openlocfilehash: 78be83af678b553babbf1cde3d96c1507940b611
ms.sourcegitcommit: 9e85c2e029d06b4c1c69837437468718b4d54908
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/19/2019
ms.locfileid: "58172901"
---
# <a name="ltsystemerrorgt-functions"></a>Funções &lt;system_error&gt;

||||
|-|-|-|
|[generic_category](#generic_category)|[make_error_code](#make_error_code)|[make_error_condition](#make_error_condition)|
|[system_category](#system_category)|||

## <a name="generic_category"></a> generic_category

Representa a categoria de erros genéricos.

```cpp
const error_category& generic_category() noexcept;
```

### <a name="remarks"></a>Comentários

O `generic_category` objeto é uma implementação de [error_category](../standard-library/error-category-class.md).

## <a name="make_error_code"></a>  make_error_code

Cria um objeto de código de erro.

```cpp
error_code make_error_code(std::errc error) noexcept;
```

### <a name="parameters"></a>Parâmetros

*error*\
O `std::errc` valor de enumeração para armazenar no objeto de código de erro.

### <a name="return-value"></a>Valor de retorno

O objeto de código de erro.

### <a name="remarks"></a>Comentários

## <a name="make_error_condition"></a>  make_error_condition

Cria um objeto de condição de erro.

```cpp
error_condition make_error_condition(std::errc error) noexcept;
```

### <a name="parameters"></a>Parâmetros

*error*\
O `std::errc` valor de enumeração para armazenar no objeto de código de erro.

### <a name="return-value"></a>Valor de retorno

O objeto de condição de erro.

### <a name="remarks"></a>Comentários

## <a name="system_category"></a>  system_category

Representa a categoria de erros causados por estouros de nível inferior do sistema.

```cpp
const error_category& system_category() noexcept;
```

### <a name="remarks"></a>Comentários

O `system_category` objeto é uma implementação de [error_category](../standard-library/error-category-class.md).

## <a name="see-also"></a>Consulte também

[\<system_error>](../standard-library/system-error.md)<br/>
