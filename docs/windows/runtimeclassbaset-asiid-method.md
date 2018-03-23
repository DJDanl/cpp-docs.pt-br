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
- implements/Microsoft::WRL::Details::RuntimeClassBaseT::AsIID
dev_langs:
- C++
helpviewer_keywords:
- AsIID method
ms.assetid: 90d7df8a-cf9e-4eef-8837-bc1a25f3fa1a
caps.latest.revision: ''
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 17d67ee58e9ecc3b0ef463d6af132fec3a1c0a2f
ms.sourcegitcommit: 1d11412c8f5e6ddf4edded89e0ef5097cc89f812
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/22/2018
---
# <a name="runtimeclassbasetasiid-method"></a>Método RuntimeClassBaseT::AsIID
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename T>  
__forceinline static HRESULT AsIID(  
   _In_ T* implements,  
   REFIID riid,  
   _Deref_out_ void **ppvObject  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Um tipo que implementa a ID de interface especificada pelo parâmetro `riid`.  
  
 `implements`  
 Uma variável do tipo especificado pelo parâmetro de modelo `T`.  
  
 `riid`  
 A ID de interface para recuperar.  
  
 `ppvObject`  
 Se essa operação for bem-sucedida, um ponteiro-para-um-ponteiro para a interface especificada pelo parâmetro `riid`.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, o HRESULT que descreve o erro.  
  
## <a name="remarks"></a>Comentários  
 Recupera um ponteiro para a ID de interface especificado.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Estrutura RuntimeClassBaseT](../windows/runtimeclassbaset-structure.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)