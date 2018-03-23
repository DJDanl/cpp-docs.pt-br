---
title: 'Método Runtimeclassbaset: | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::RuntimeClassBaseT::GetImplementedIIDS
dev_langs:
- C++
helpviewer_keywords:
- GetImplementedIIDS method
ms.assetid: adae54da-521d-4add-87f5-242fbd85f33b
caps.latest.revision: ''
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 478be22e54732cccddbc212cdb192c2847a1a235
ms.sourcegitcommit: 1d11412c8f5e6ddf4edded89e0ef5097cc89f812
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/22/2018
---
# <a name="runtimeclassbasetgetimplementediids-method"></a>Método RuntimeClassBaseT::GetImplementedIIDS
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename T>  
__forceinline static HRESULT GetImplementedIIDS(  
   _In_ T* implements,  
   _Out_ ULONG *iidCount,  
   _Deref_out_ _Deref_post_cap_(*iidCount) IID **iids  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo do parâmetro `implements`.  
  
 `implements`  
 Ponteiro para o tipo especificado pelo parâmetro `T`.  
  
 `iidCount`  
 O número máximo de IDs de interface para recuperar.  
  
 `iids`  
 Se essa operação for concluída com êxito, uma matriz das IDs implementadas pelo tipo de interface `T`.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, o HRESULT que descreve o erro.  
  
## <a name="remarks"></a>Comentários  
 Recupera uma matriz de IDs são implementados por um tipo específico de interface.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Estrutura RuntimeClassBaseT](../windows/runtimeclassbaset-structure.md)