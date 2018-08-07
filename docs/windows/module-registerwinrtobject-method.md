---
title: 'Método Module:: registerwinrtobject | Microsoft Docs'
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
ms.openlocfilehash: 42ec736126e2381b00542bf71afca0b9db187df7
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39603751"
---
# <a name="moduleregisterwinrtobject-method"></a>Método Module::RegisterWinRTObject
Registra um ou mais objetos de tempo de execução do Windows para que outros aplicativos podem se conectar a eles.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
HRESULT RegisterWinRTObject(const wchar_t* serverName,  
   wchar_t** activatableClassIds,  
   WINRT_REGISTRATION_COOKIE* cookie,  
   unsigned int count)  
```  
  
### <a name="parameters"></a>Parâmetros  
 *ServerName*  
 Um nome que especifica um subconjunto de objetos afetados por essa operação.  
  
 *activatableClassIds*  
 Uma matriz de ativáveis CLSIDs para registrar.  
  
 *Cookie*  
 Um valor que identifica os objetos de classe que foram registrados. Esse valor é usado posteriormente para revoga o registro.  
  
 *count*  
 O número de objetos para registrar.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, um erro HRESULT, como CO_E_OBJISREG que indica o motivo pelo qual a operação falhou.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL
 
 ## <a name="see-also"></a>Consulte também
 [Classe Module](../windows/module-class.md)