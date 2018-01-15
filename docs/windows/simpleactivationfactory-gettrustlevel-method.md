---
title: "Método Simpleactivationfactory: | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: module/Microsoft::WRL::SimpleActivationFactory::GetTrustLevel
dev_langs: C++
ms.assetid: 99aa9bc9-d954-4a6f-902b-4abe00e43039
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 608f67267b8a82341ff3beb3e27f8e0eb9891c8a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Classe SimpleActivationFactory](../windows/simpleactivationfactory-class.md)