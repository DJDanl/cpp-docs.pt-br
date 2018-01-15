---
title: 'Hstringreference:: Operator operador = | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: corewrappers/Microsoft::WRL::Wrappers::HStringReference::operator=
dev_langs: C++
ms.assetid: ea100ed3-e566-4c9e-b6a8-f296088dea9c
caps.latest.revision: "2"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 097e89ab4ae2d3b6ddaacb2fa52b811c1577ef72
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="hstringreferenceoperator-operator"></a>Operador HStringReference::Operator=
Move o valor de outro objeto HStringReference ao objeto HStringReference atual.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
HStringReference& operator=(HStringReference&& other) throw()  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `other`  
 Um objeto HStringReference existente.  
  
## <a name="remarks"></a>Comentários  
 O valor existente `other` objeto é copiado para o objeto HStringReference atual e, em seguida, o `other` objeto é destruído.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe HStringReference](../windows/hstringreference-class.md)