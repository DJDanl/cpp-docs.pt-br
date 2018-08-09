---
title: 'Método runtimeclassbaset:: Asiid | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::RuntimeClassBaseT::AsIID
dev_langs:
- C++
helpviewer_keywords:
- AsIID method
ms.assetid: 90d7df8a-cf9e-4eef-8837-bc1a25f3fa1a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 96b97bf2afa8897063e8303a04445f9957cc42c3
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40016633"
---
# <a name="runtimeclassbasetasiid-method"></a>Método RuntimeClassBaseT::AsIID
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
template<typename T>  
__forceinline static HRESULT AsIID(  
   _In_ T* implements,  
   REFIID riid,  
   _Deref_out_ void **ppvObject  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *T*  
 Um tipo que implementa a interface ID especificado pelo parâmetro *riid*.  
  
 *Implementa*  
 Uma variável do tipo especificado pelo parâmetro de modelo *T*.  
  
 *riid*  
 A ID de interface para recuperar.  
  
 *ppvObject*  
 Se essa operação for bem-sucedida, um ponteiro-para-um-ponteiro para a interface especificada pelo parâmetro *riid*.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, um HRESULT que descreve o erro.  
  
## <a name="remarks"></a>Comentários  
 Recupera um ponteiro para a ID de interface especificado.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Implements. h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Estrutura RuntimeClassBaseT](../windows/runtimeclassbaset-structure.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)