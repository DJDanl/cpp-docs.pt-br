---
title: 'Método Module:: unregisterobjects | Microsoft Docs'
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
ms.openlocfilehash: 1ee7e6deeda17d2ac374b39edf70ab28fa1457fa
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42603375"
---
# <a name="moduleunregisterobjects-method"></a>Método Module::UnregisterObjects

Cancela o registro os objetos no módulo especificado para que outros aplicativos não podem se conectar a eles.

## <a name="syntax"></a>Sintaxe

```cpp
HRESULT UnregisterObjects(
   ModuleBase* module,
   const wchar_t* serverName);
```

### <a name="parameters"></a>Parâmetros

*módulo*  
Ponteiro para um módulo.

*ServerName*  
Um nome qualificado que especifica um subconjunto de objetos afetados por essa operação.

## <a name="return-value"></a>Valor de retorno

S_OK se essa operação for bem-sucedida; Caso contrário, um erro HRESULT que indica o motivo pelo qual esta operação falhou.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também
[Classe Module](../windows/module-class.md)