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
ms.openlocfilehash: 22fa30a3662897b171245da194573ec17da2f64e
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39645182"
---
# <a name="simpleactivationfactorygettrustlevel-method"></a>Método SimpleActivationFactory::GetTrustLevel
Obtém o nível de confiança de uma instância da classe especificada pelo `Base` parâmetro de modelo de classe.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
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