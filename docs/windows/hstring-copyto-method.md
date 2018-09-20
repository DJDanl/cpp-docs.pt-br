---
title: 'Método hstring:: CopyTo | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
ms.assetid: a1fd2ef0-e175-4c18-927b-550e02a89e43
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: f8ea15c56bb974cc297c8fc396205d5f172e9bfd
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46388069"
---
# <a name="hstringcopyto-method"></a>Método HString::CopyTo

Copia o atual **HString** objeto para um objeto HSTRING.

## <a name="syntax"></a>Sintaxe

```cpp
HRESULT CopyTo(
   _Out_ HSTRING *str
   ) const throw();
```

### <a name="parameters"></a>Parâmetros

*str*<br/>
O HSTRING que recebe a cópia.

## <a name="remarks"></a>Comentários

Este método chama o [WindowsDuplicateString](https://msdn.microsoft.com/library/br224634.aspx) função.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="see-also"></a>Consulte também

[Classe HString](../windows/hstring-class.md)