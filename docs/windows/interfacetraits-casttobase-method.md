---
title: 'Método interfacetraits:: Casttobase | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::InterfaceTraits::CastToBase
dev_langs:
- C++
helpviewer_keywords:
- CastToBase method
ms.assetid: 0591a017-0adf-4358-b946-eb0a307ce7f2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 473656f25c4ba08e011bef8f938cea54bdc51d6d
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46424892"
---
# <a name="interfacetraitscasttobase-method"></a>Método InterfaceTraits::CastToBase

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename T>
static __forceinline Base* CastToBase(
   _In_ T* ptr
);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo do parâmetro *ptr*.

*ptr*<br/>
Ponteiro para um tipo *T*.

## <a name="return-value"></a>Valor de retorno

Um ponteiro para `Base`.

## <a name="remarks"></a>Comentários

Converte o ponteiro especificado para um ponteiro para `Base`.

Para obter mais informações sobre `Base`, consulte a seção Typedefs públicos [estrutura InterfaceTraits](../windows/interfacetraits-structure.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Estrutura InterfaceTraits](../windows/interfacetraits-structure.md)<br/>
[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)