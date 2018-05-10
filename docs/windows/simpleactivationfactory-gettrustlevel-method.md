---
title: 'Método Simpleactivationfactory: | Microsoft Docs'
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
ms.openlocfilehash: b08ce574a8370eb0029a702f8fa4a4b12c6e93c1
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="simpleactivationfactorygettrustlevel-method"></a>Método SimpleActivationFactory::GetTrustLevel
Obtém o nível de confiança de uma instância da classe especificada o `Base` parâmetro de modelo de classe.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
STDMETHOD(  
   GetTrustLevel  
)(_Out_ TrustLevel* trustLvl);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `trustLvl`  
 Quando essa operação for concluída, o nível de confiança do objeto de classe atual.  
  
## <a name="return-value"></a>Valor de retorno  
 Sempre S_OK.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe SimpleActivationFactory](../windows/simpleactivationfactory-class.md)