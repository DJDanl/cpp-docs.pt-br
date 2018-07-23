---
title: 'Método: unregisterobjects | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Module::UnregisterObjects
dev_langs:
- C++
helpviewer_keywords:
- UnregisterObjects method
ms.assetid: 3d8119a7-991d-45e9-b8c5-ed36c0be0332
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 7b711338c436eda3e64d9b51ef0d3137975d834a
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33874113"
---
# <a name="moduleunregisterobjects-method"></a>Método Module::UnregisterObjects
Cancela o registro de objetos no módulo especificado para que outros aplicativos não podem se conectar a eles.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
HRESULT UnregisterObjects(  
   ModuleBase* module,  
   const wchar_t* serverName);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `module`  
 Ponteiro para um módulo.  
  
 `serverName`  
 Um nome qualificado que especifica um subconjunto de objetos afetados por essa operação.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se essa operação for bem-sucedida; Caso contrário, um erro HRESULT que indica o motivo pelo qual esta operação falhou.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL
 
 ## <a name="see-also"></a>Consulte também
 [Classe Module](../windows/module-class.md)