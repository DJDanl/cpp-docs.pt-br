---
title: 'Método runtimeclass:: QueryInterface | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::RuntimeClass::QueryInterface
dev_langs:
- C++
helpviewer_keywords:
- QueryInterface method
ms.assetid: 8f01f4a1-3fa2-4a8e-88c6-03629236cb9f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: d76e2e7041948021cb36e563acef7ca712e73842
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40015189"
---
# <a name="runtimeclassqueryinterface-method"></a>Método RuntimeClass::QueryInterface
Recupera um ponteiro para a ID de interface especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
STDMETHOD(  
   QueryInterface  
)  
   (REFIID riid,   
   _Deref_out_ void **ppvObject);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *riid*  
 Uma ID de interface.  
  
 *ppvObject*  
 Quando este opereation for concluída, um ponteiro para a interface especificada pelo *riid* parâmetro.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Implements. h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe RuntimeClass](../windows/runtimeclass-class.md)