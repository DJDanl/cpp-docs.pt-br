---
title: 'Método simpleactivationfactory:: Gettrustlevel | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::SimpleActivationFactory::GetTrustLevel
dev_langs:
- C++
ms.assetid: 99aa9bc9-d954-4a6f-902b-4abe00e43039
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b5a1838c153dc7a0a4def9f98e5e043e36ae9414
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42603839"
---
# <a name="simpleactivationfactorygettrustlevel-method"></a>Método SimpleActivationFactory::GetTrustLevel

Obtém o nível de confiança de uma instância da classe especificada pelo `Base` parâmetro de modelo de classe.

## <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(
   GetTrustLevel
)(_Out_ TrustLevel* trustLvl);
```

### <a name="parameters"></a>Parâmetros

*trustLvl*  
Quando essa operação for concluída, o nível de confiança do objeto da classe atual.

## <a name="return-value"></a>Valor de retorno

Sempre S_OK.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe SimpleActivationFactory](../windows/simpleactivationfactory-class.md)