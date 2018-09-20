---
title: 'Operador hstring:: Operator = | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HString::operator=
dev_langs:
- C++
ms.assetid: 8e68c1ff-bc57-4526-810e-af3c284b4e30
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 8e528bed14f3f6f3b35270975833bdd17fd777db
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46422643"
---
# <a name="hstringoperator-operator"></a>Operador HString::Operator=

Move o valor de outro **HString** objeto atual **HString** objeto.

## <a name="syntax"></a>Sintaxe

```cpp
HString& operator=(HString&& other) throw()  
```

### <a name="parameters"></a>Parâmetros

*other*<br/>
Um existente **HString** objeto.

## <a name="remarks"></a>Comentários

O valor de existente *outras* objeto é copiado para a atual **HString** objeto e, em seguida, o *outros* objeto é destruído.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="see-also"></a>Consulte também

[Classe HString](../windows/hstring-class.md)