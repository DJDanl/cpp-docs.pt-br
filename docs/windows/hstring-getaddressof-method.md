---
title: 'Método hstring:: Getaddressof | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HString::GetAddressOf
dev_langs:
- C++
ms.assetid: 6050decf-5f99-49f0-9497-1c8192c485ae
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e327e2818903396c154be7406ec325695b6b6982
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42613359"
---
# <a name="hstringgetaddressof-method"></a>Método HString::GetAddressOf

Recupera um ponteiro para o identificador subjacente de HSTRING.

## <a name="syntax"></a>Sintaxe

```cpp
HSTRING* GetAddressOf() throw()  
```

## <a name="return-value"></a>Valor de retorno

Um ponteiro para o identificador subjacente de HSTRING.

## <a name="remarks"></a>Comentários

Depois dessa operação, o valor de cadeia de caracteres do identificador subjacente de HSTRING é destruído.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="see-also"></a>Consulte também

[Classe HString](../windows/hstring-class.md)