---
title: 'Método interfacetraits:: Fillarraywithiid | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::InterfaceTraits::FillArrayWithIid
dev_langs:
- C++
helpviewer_keywords:
- FillArrayWithIid method
ms.assetid: 73583177-adc9-4fcb-917d-fa7e6d07c990
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: c5163ea5922141faf0c4b28deb147672938997a1
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46375411"
---
# <a name="interfacetraitsfillarraywithiid-method"></a>Método InterfaceTraits::FillArrayWithIid

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
__forceinline static void FillArrayWithIid(
   _Inout_ unsigned long &index,
   _In_ IID* iids
);
```

### <a name="parameters"></a>Parâmetros

*index*<br/>
Ponteiro para um campo que contém um valor de índice baseado em zero.

*IIDs*<br/>
Uma matriz de IDs de interface.

## <a name="remarks"></a>Comentários

Atribui a ID de interface do `Base` ao elemento de matriz especificado pelo argumento de índice.

O nome dessa API, ao contrário do elemento de apenas uma matriz é modificado; não é a matriz inteira.

Para obter mais informações sobre `Base`, consulte a seção Typedefs públicos [estrutura InterfaceTraits](../windows/interfacetraits-structure.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Estrutura InterfaceTraits](../windows/interfacetraits-structure.md)<br/>
[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)