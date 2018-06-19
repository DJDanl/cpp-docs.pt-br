---
title: 'Método: registerobjects | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Module::RegisterObjects
dev_langs:
- C++
helpviewer_keywords:
- RegisterObjects method
ms.assetid: db4077b7-068d-4534-aaa5-41b5444ccb49
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 986dcfff49529eedd8d495f4c37e19fa2b6cb8bc
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33875338"
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
  
 **Namespace:** Microsoft::WRL
 
## <a name="see-also"></a>Consulte também
[Classe Module](../windows/module-class.md)