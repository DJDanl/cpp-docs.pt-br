---
title: 'Método runtimeclassbaset:: Getimplementediids | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::RuntimeClassBaseT::GetImplementedIIDS
dev_langs:
- C++
helpviewer_keywords:
- GetImplementedIIDS method
ms.assetid: adae54da-521d-4add-87f5-242fbd85f33b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 15db0be600d61992d48c2f1cf90d6543057b5090
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46376066"
---
# <a name="runtimeclassbasetgetimplementediids-method"></a>Método RuntimeClassBaseT::GetImplementedIIDS

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename T>
__forceinline static HRESULT GetImplementedIIDS(
   _In_ T* implements,
   _Out_ ULONG *iidCount,
   _Deref_out_ _Deref_post_cap_(*iidCount) IID **iids
);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo dos *implementa* parâmetro.

*Implementa*<br/>
Ponteiro para o tipo especificado pelo parâmetro *T*.

*iidCount*<br/>
O número máximo de IDs de interface para recuperar.

*IIDs*<br/>
Se essa operação for concluída com êxito, uma matriz de IDs implementadas pelo tipo de interface *T*.

## <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que descreve o erro.

## <a name="remarks"></a>Comentários

Recupera uma matriz de IDs que são implementadas por um tipo especificado de interface.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Estrutura RuntimeClassBaseT](../windows/runtimeclassbaset-structure.md)