---
title: vector&lt;bool&gt;::reference::operator bool | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- operatorbool
- vector<bool>::reference::operatorbool
- bool
- std::vector<bool>::reference::operatorbool
dev_langs:
- C++
helpviewer_keywords:
- BOOL operator
- reference::operator bool
ms.assetid: b0e57869-18cc-4296-9061-da502f30120d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 00ccd9e9ffbab78534c5b6417b7567ba03d007ab
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38963674"
---
# <a name="vectorltboolgtreferenceoperator-bool"></a>vector&lt;bool&gt;::reference::operator bool

Fornece uma conversão implícita da `vector<bool>::reference` à **bool**.

## <a name="syntax"></a>Sintaxe

```cpp
operator bool() const;
```

## <a name="return-value"></a>Valor de retorno

O valor booliano do elemento do objeto [vector\<bool>](../standard-library/vector-bool-class.md).

## <a name="remarks"></a>Comentários

O objeto `vector<bool>` não pode ser modificado por esse operador.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<vector>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[vetor\<bool >:: classe de referência](../standard-library/vector-bool-reference-class.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
