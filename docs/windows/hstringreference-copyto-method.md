---
title: 'Método hstringreference:: CopyTo | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
ms.assetid: 179d9b14-1ced-4b16-b297-19ca1e92a462
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 22886621760ed53649d26180877b1463ec2d3f2d
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42592158"
---
# <a name="hstringreferencecopyto-method"></a>Método HStringReference::CopyTo

Copia o atual **HStringReference** objeto para um objeto HSTRING.

## <a name="syntax"></a>Sintaxe

```cpp
HRESULT CopyTo(
   _Out_ HSTRING *str
   ) const throw();
```

### <a name="parameters"></a>Parâmetros

*str*  
O HSTRING que recebe a cópia.

## <a name="remarks"></a>Comentários

Este método chama o [WindowsDuplicateString](http://msdn.microsoft.com/library/br224634.aspx) função.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="see-also"></a>Consulte também

[Classe HStringReference](../windows/hstringreference-class.md)