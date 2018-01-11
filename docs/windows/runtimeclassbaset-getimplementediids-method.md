---
title: "Método Runtimeclassbaset: | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: implements/Microsoft::WRL::Details::RuntimeClassBaseT::GetImplementedIIDS
dev_langs: C++
helpviewer_keywords: GetImplementedIIDS method
ms.assetid: adae54da-521d-4add-87f5-242fbd85f33b
caps.latest.revision: "4"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 25410ac57e1812d3f4648151afff4f97d413689b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="runtimeclassbasetgetimplementediids-method"></a>Método RuntimeClassBaseT::GetImplementedIIDS
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<  
   typename T  
>  
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