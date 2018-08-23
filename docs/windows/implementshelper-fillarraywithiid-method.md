---
title: 'Método implementshelper:: Fillarraywithiid | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::ImplementsHelper::FillArrayWithIid
dev_langs:
- C++
helpviewer_keywords:
- FillArrayWithIid method
ms.assetid: f60035ee-b7d6-4a08-966d-f88c646944c3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 876f2bde68c53a27c1c40e9206b6285b8562bd91
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42591133"
---
# <a name="implementshelperfillarraywithiid-method"></a>Método ImplementsHelper::FillArrayWithIid

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
void FillArrayWithIid(
   _Inout_ unsigned long *index,
   _Inout_ IID* iids) throw();
```

### <a name="parameters"></a>Parâmetros

*index*  
Um índice baseado em zero que indica o elemento de matriz inicial para esta operação. Quando essa operação for concluída, *índice* é incrementado em 1.

*IIDs*  
Uma matriz do tipo IIDs.

## <a name="remarks"></a>Comentários

Insere a ID de interface especificada pelo parâmetro de modelo inicial atual para o elemento da matriz especificada.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Estrutura ImplementsHelper](../windows/implementshelper-structure.md)  
[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)