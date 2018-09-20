---
title: 'Método interfacetraits:: Cancastto | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::InterfaceTraits::CanCastTo
dev_langs:
- C++
helpviewer_keywords:
- CanCastTo method
ms.assetid: 275847cb-69ea-42bf-910f-05ba6ef8b48d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 705b495e3f6d626a742fd1a63989c8cc658446a4
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46379653"
---
# <a name="interfacetraitscancastto-method"></a>Método InterfaceTraits::CanCastTo

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename T>
static __forceinline bool CanCastTo(
   _In_ T* ptr,
   REFIID riid,
   _Deref_out_ void **ppv
);
```

### <a name="parameters"></a>Parâmetros

*ptr*<br/>
O nome de um ponteiro para um tipo.

*riid*<br/>
A ID de interface do `Base`.

*ppv*<br/>
Se essa operação for bem-sucedida, *ppv* aponta para a interface especificada pelo `Base`. Caso contrário, *ppv* é definido como **nullptr**.

## <a name="return-value"></a>Valor de retorno

**Verdadeiro** se essa operação for bem-sucedida e *ptr* é convertido em um ponteiro para `Base`; caso contrário, **false** .

## <a name="remarks"></a>Comentários

Indica se o ponteiro especificado pode ser convertido em um ponteiro para `Base`.

Para obter mais informações sobre `Base`, consulte o **Typedefs públicos** seção [estrutura InterfaceTraits](../windows/interfacetraits-structure.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Estrutura InterfaceTraits](../windows/interfacetraits-structure.md)<br/>
[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)