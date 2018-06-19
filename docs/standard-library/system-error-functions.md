---
title: Funções &lt;system_error&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
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
ms.openlocfilehash: 6135a3dc51b372c85545f01f52c70cbc6f236e64
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33855127"
---
# <a name="ltsystemerrorgt-functions"></a>Funções &lt;system_error&gt;

||||
|-|-|-|
|[generic_category](#generic_category)|[make_error_code](#make_error_code)|[make_error_condition](#make_error_condition)|
|[system_category](#system_category)|

## <a name="generic_category"></a>  generic_category

Representa a categoria de erros genéricos.

```cpp
extern const error_category& generic_category();
```

### <a name="remarks"></a>Comentários

O `generic_category` objeto é uma implementação de [error_category](../standard-library/error-category-class.md).

## <a name="make_error_code"></a>  make_error_code

Cria um objeto de código de erro.

```cpp
error_code make_error_code(generic_errno _Errno);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|`_Errno`|O valor de enumeração a ser armazenado no objeto de código de erro.|

### <a name="return-value"></a>Valor de retorno

O objeto de código de erro.

### <a name="remarks"></a>Comentários

## <a name="make_error_condition"></a>  make_error_condition

Cria um objeto de condição de erro.

```cpp
error_condition make_error_condition(generic_errno _Errno);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|`_Errno`|O valor de enumeração a ser armazenado no objeto de condição de erro.|

### <a name="return-value"></a>Valor de retorno

O objeto de condição de erro.

### <a name="remarks"></a>Comentários

## <a name="system_category"></a>  system_category

Representa a categoria de erros causados por estouros de nível inferior do sistema.

```cpp
extern const error_category& system_category();
```

### <a name="remarks"></a>Comentários

O `system_category` objeto é uma implementação de [error_category](../standard-library/error-category-class.md).

## <a name="see-also"></a>Consulte também

[<system_error>](../standard-library/system-error.md)<br/>
