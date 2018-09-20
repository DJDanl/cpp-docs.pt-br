---
title: SafeSubtract | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- SafeSubtract
dev_langs:
- C++
helpviewer_keywords:
- SafeSubtract function
ms.assetid: c2712ddc-173f-46a1-b09c-e7ebbd9e68b2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 264a5ccbda8100e7e7fb951a2a8d30e983105efa
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46375327"
---
# <a name="safesubtract"></a>SafeSubtract

Subtrai dois números de uma maneira que proteja contra estouro.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename T, typename U>
inline bool SafeSubtract (
   T t,
   U u,
   T& result
) throw ();
```

### <a name="parameters"></a>Parâmetros

*t*<br/>
[in] O primeiro número na subtração. Isso deve ser do tipo `T`.

*u*<br/>
[in] O número para subtrair de *t*. Isso deve ser do tipo `U`.

*resultado*<br/>
[out] O parâmetro em que **SafeSubtract** armazena o resultado.

## <a name="return-value"></a>Valor de retorno

**True** se nenhum erro ocorrer; **falsos** se ocorrer um erro.

## <a name="remarks"></a>Comentários

Esse método é parte da [biblioteca SafeInt](../windows/safeint-library.md) e é projetado para uma operação de subtração único sem criar uma instância das [classe SafeInt](../windows/safeint-class.md).

> [!NOTE]
> Esse método só deve ser usado quando uma operação matemática única deve ser protegida. Se houver várias operações, você deve usar o `SafeInt` classe em vez de chamar as funções individuais de autônomas.

Para obter mais informações sobre os tipos de modelo `T` e `U`, consulte [funções SafeInt](../windows/safeint-functions.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** safeint

**Namespace:** Microsoft::Utilities

## <a name="see-also"></a>Consulte também

[Funções SafeInt](../windows/safeint-functions.md)<br/>
[Biblioteca SafeInt](../windows/safeint-library.md)<br/>
[Classe SafeInt](../windows/safeint-class.md)<br/>
[SafeAdd](../windows/safeadd.md)