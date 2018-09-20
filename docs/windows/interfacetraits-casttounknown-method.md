---
title: 'Método interfacetraits:: Casttounknown | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::InterfaceTraits::CastToUnknown
dev_langs:
- C++
helpviewer_keywords:
- CastToUnknown method
ms.assetid: aca47fa0-3c60-47f2-a73c-258f7160adff
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: c75e02136c626d72215a2af79d1391863e9f494c
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46382656"
---
# <a name="interfacetraitscasttounknown-method"></a>Método InterfaceTraits::CastToUnknown

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename T>
static __forceinline IUnknown* CastToUnknown(
   _In_ T* ptr
);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo do parâmetro *ptr*.

*ptr*<br/>
Ponteiro para o tipo *T*.

## <a name="return-value"></a>Valor de retorno

Ponteiro para o IUnknown do qual `Base` é derivado.

## <a name="remarks"></a>Comentários

Converte o ponteiro especificado para um ponteiro para `IUnknown`.

Para obter mais informações sobre `Base`, consulte a seção Typedefs públicos [estrutura InterfaceTraits](../windows/interfacetraits-structure.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Estrutura InterfaceTraits](../windows/interfacetraits-structure.md)<br/>
[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)