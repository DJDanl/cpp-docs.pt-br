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
ms.openlocfilehash: 1234c667426937f5d40937c5f2bcc72949e827ae
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40012388"
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