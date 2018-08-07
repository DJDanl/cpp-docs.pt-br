---
title: 'Método Module:: Create | Microsoft Docs'
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
ms.openlocfilehash: c0d49a6f0b5172b0971f755fc61b7767f0f4427d
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39603297"
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
  
### <a name="parameters"></a>Parâmetros  
 *T*  
 Tipo de módulo.  
  
 *retorno de chamada*  
 Chamado quando o último objeto de instância do módulo é liberado.  
  
 *object*  
 O *objeto* e *método* parâmetros são usados em combinação. Aponta para o último objeto de instância quando o último objeto de instância no módulo é liberado.  
  
 *Método*  
 O *objeto* e *método* parâmetros são usados em combinação. Aponta para o método do último objeto de instância quando o último objeto de instância no módulo é liberado.  
  
## <a name="return-value"></a>Valor de retorno  
 Referência para o módulo.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
[Classe Module](../windows/module-class.md)