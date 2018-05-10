---
title: 'Método Module: | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Module::Create
dev_langs:
- C++
helpviewer_keywords:
- Create method
ms.assetid: bfa97fd7-5226-4604-92a5-3b9697053e64
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 99ede64c239909956f1f767db34a2a6a14c02314
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
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

 