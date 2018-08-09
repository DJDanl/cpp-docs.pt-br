---
title: 'Método Module:: registerobjects | Microsoft Docs'
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
ms.openlocfilehash: 04281b87584d10d36f5f2eeea05dfae0923b2d9f
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40013308"
---
# <a name="moduleregisterobjects-method"></a>Método Module::RegisterObjects
Registra os objetos COM ou tempo de execução do Windows para que outros aplicativos podem se conectar a eles.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
HRESULT RegisterObjects(  
   ModuleBase* module,   
   const wchar_t* serverName);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *módulo*  
 Uma matriz de objetos COM ou tempo de execução do Windows.  
  
 *ServerName*  
 Nome do servidor que criou os objetos.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o motivo pelo qual a operação falhou.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL
 
## <a name="see-also"></a>Consulte também
[Classe Module](../windows/module-class.md)