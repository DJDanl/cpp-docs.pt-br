---
title: SafeAdd | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- SafeAdd
dev_langs:
- C++
helpviewer_keywords:
- SafeAdd function
ms.assetid: 3f82b91d-59fe-4ee1-873b-d056182fa8be
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: ada0997a03cefbec4bcc4faa26ad4eaf8c176ff2
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45704881"
---
# <a name="safeadd"></a>SafeAdd

Adiciona dois números de uma maneira que proteja contra estouro.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename T, typename U>
inline bool SafeAdd (
   T t,
   U u,
   T& result
) throw ();
```

### <a name="parameters"></a>Parâmetros

*t*<br/>
[in] O primeiro número a adicionar. Isso deve ser do tipo T.

*u*<br/>
[in] O segundo número a adicionar. Isso deve ser do tipo u

*resultado*<br/>
[out] O parâmetro em que **SafeAdd** armazena o resultado.

## <a name="return-value"></a>Valor de retorno

**True** se nenhum erro ocorrer; **falsos** se ocorrer um erro.

## <a name="remarks"></a>Comentários

Esse método é parte da [biblioteca SafeInt](../windows/safeint-library.md) e é projetado para uma operação de adição único sem criar uma instância das [classe SafeInt](../windows/safeint-class.md).

> [!NOTE]
> Esse método só deve ser usado quando uma operação matemática única deve ser protegida. Se houver várias operações, você deve usar o `SafeInt` classe em vez de chamar as funções individuais de autônomas.

Para obter mais informações sobre os tipos de modelo T e U, consulte [funções SafeInt](../windows/safeint-functions.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** safeint

**Namespace:** Microsoft::Utilities

## <a name="see-also"></a>Consulte também

[Funções SafeInt](../windows/safeint-functions.md)  
[Biblioteca SafeInt](../windows/safeint-library.md)  
[Classe SafeInt](../windows/safeint-class.md)  
[SafeSubtract](../windows/safesubtract.md)