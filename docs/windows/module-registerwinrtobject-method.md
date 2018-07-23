---
title: 'Método: registerwinrtobject | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Module::RegisterWinRTObject
dev_langs:
- C++
helpviewer_keywords:
- RegisterWinRTObject method
ms.assetid: a2782c9c-b9c5-4e4b-9c8d-ef513aea20c5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 097bf70ebd280d9494ff70ea1d80f53615f3d898
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33874948"
---
# <a name="moduleregisterwinrtobject-method"></a>Método Module::RegisterWinRTObject
Registra um ou mais objetos de tempo de execução do Windows para que outros aplicativos possam se conectar a eles.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
HRESULT RegisterWinRTObject(const wchar_t* serverName,  
   wchar_t** activatableClassIds,  
   WINRT_REGISTRATION_COOKIE* cookie,  
   unsigned int count)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `serverName`  
 Um nome que especifica um subconjunto de objetos afetados por essa operação.  
  
 `activatableClassIds`  
 Uma matriz de ativáveis CLSIDs para registrar.  
  
 `cookie`  
 Um valor que identifica os objetos de classe que foram registrados. Esse valor é usado posteriormente para revogar o registro.  
  
 `count`  
 O número de objetos para registrar.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, um erro HRESULT como CO_E_OBJISREG que indica o motivo da falha da operação.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL
 
 ## <a name="see-also"></a>Consulte também
 [Classe Module](../windows/module-class.md)