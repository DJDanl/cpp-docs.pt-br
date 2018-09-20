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
ms.openlocfilehash: 496b1ccac5b998ba08f4e2eccfe31ffd18f2c37d
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46431782"
---
# <a name="moduleregisterwinrtobject-method"></a>Método Module::RegisterWinRTObject

Registra um ou mais objetos de tempo de execução do Windows para que outros aplicativos podem se conectar a eles.

## <a name="syntax"></a>Sintaxe

```cpp
HRESULT RegisterWinRTObject(const wchar_t* serverName,
   wchar_t** activatableClassIds,
   WINRT_REGISTRATION_COOKIE* cookie,
   unsigned int count)  
```

### <a name="parameters"></a>Parâmetros

*ServerName*<br/>
Um nome que especifica um subconjunto de objetos afetados por essa operação.

*activatableClassIds*<br/>
Uma matriz de ativáveis CLSIDs para registrar.

*Cookie*<br/>
Um valor que identifica os objetos de classe que foram registrados. Esse valor é usado posteriormente para revoga o registro.

*count*<br/>
O número de objetos para registrar.

## <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um erro HRESULT, como CO_E_OBJISREG que indica o motivo pelo qual a operação falhou.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe Module](../windows/module-class.md)