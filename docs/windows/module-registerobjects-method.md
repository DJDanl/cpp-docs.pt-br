---
title: "Método: registerobjects | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: module/Microsoft::WRL::Module::RegisterObjects
dev_langs: C++
helpviewer_keywords: RegisterObjects method
ms.assetid: db4077b7-068d-4534-aaa5-41b5444ccb49
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: fbff1d4c16c8cfb4f265760a6919637808efe28d
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="moduleregisterobjects-method"></a>Método Module::RegisterObjects
Registra objetos COM ou tempo de execução do Windows para que outros aplicativos possam se conectar a eles.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
HRESULT RegisterObjects(  
   ModuleBase* module,   
   const wchar_t* serverName);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `module`  
 Uma matriz de objetos COM ou tempo de execução do Windows.  
  
 `serverName`  
 Nome do servidor que criou os objetos.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, o HRESULT que indica o motivo da falha da operação.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft:: wrl
 
## <a name="see-also"></a>Consulte também
[Classe Module](../windows/module-class.md)