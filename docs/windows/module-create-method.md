---
title: 'Método Module: | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Module::Create
dev_langs:
- C++
helpviewer_keywords:
- Create method
ms.assetid: bfa97fd7-5226-4604-92a5-3b9697053e64
caps.latest.revision: ''
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e566b34140c0b82072c8469cd8d965f807e244ec
ms.sourcegitcommit: 1d11412c8f5e6ddf4edded89e0ef5097cc89f812
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/22/2018
---
# <a name="modulecreate-method"></a>Método Module::Create
Cria uma instância de um módulo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
WRL_NOTHROW static Module& Create();  
template<typename T>  
WRL_NOTHROW static Module& Create(  
   T callback  
);  
template<typename T>  
WRL_NOTHROW static Module& Create(  
   _In_ T* object,  
   _In_ void (T::* method)()  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Tipo de módulo.  
  
 `callback`  
 Chamado quando o último objeto de instância do módulo é liberado.  
  
 `object`  
 O `object` e `method` parâmetros são usados em combinação. Aponta para o último objeto de instância quando o último objeto de instância no módulo é liberado.  
  
 `method`  
 O `object` e `method` parâmetros são usados em combinação. Aponta para o método do objeto de última instância, quando o último objeto de instância no módulo é liberado.  
  
## <a name="return-value"></a>Valor de retorno  
 Referência ao módulo.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
[Classe Module](../windows/module-class.md)

 