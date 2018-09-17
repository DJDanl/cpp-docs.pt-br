---
title: SafeCast | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- SafeCast
dev_langs:
- C++
helpviewer_keywords:
- SafeCast function
ms.assetid: 55316729-8456-403a-9f96-59d4038f67af
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 2872f1639a11d537dd79b878a166a3afb5fd8667
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45719155"
---
# <a name="safecast"></a>SafeCast

Converte um tipo de número em outro tipo.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename T, typename U>
inline bool SafeCast (
   const T From,
   U& To
);
```

### <a name="parameters"></a>Parâmetros

*From*<br/>
[in] O número de origem a ser convertido. Isso deve ser do tipo `T`.

*To*<br/>
[out] Uma referência para o novo tipo de número. Isso deve ser do tipo `U`.

## <a name="return-value"></a>Valor de retorno

**True** se nenhum erro ocorrer; **falsos** se ocorrer um erro.

## <a name="remarks"></a>Comentários

Esse método é parte da [biblioteca SafeInt](../windows/safeint-library.md) e é projetado para uma operação de conversão único sem criar uma instância das [classe SafeInt](../windows/safeint-class.md).

> [!NOTE]
> Esse método só deve ser usado quando uma única operação deve ser protegida. Se houver várias operações, você deve usar o `SafeInt` classe em vez de chamar as funções individuais de autônomas.

Para obter mais informações sobre os tipos de modelo T e U, consulte [funções SafeInt](../windows/safeint-functions.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** safeint

**Namespace:** Microsoft::Utilities

## <a name="see-also"></a>Consulte também

[Funções SafeInt](../windows/safeint-functions.md)  
[Biblioteca SafeInt](../windows/safeint-library.md)  
[Classe SafeInt](../windows/safeint-class.md)