---
title: 'Hstring:: Operator operador = | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: corewrappers/Microsoft::WRL::Wrappers::HString::operator=
dev_langs: C++
ms.assetid: 8e68c1ff-bc57-4526-810e-af3c284b4e30
caps.latest.revision: "2"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5abaa00030b301607c19def42920cb01eb72600a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="hstringoperator-operator"></a>Operador HString::Operator=
Move o valor de outro objeto HString ao objeto HString atual.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
HString& operator=(HString&& other) throw()  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `other`  
 Um objeto HString existente.  
  
## <a name="remarks"></a>Comentários  
 O valor existente `other` objeto é copiado para o objeto HString atual e, em seguida, o `other` objeto é destruído.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe HString](../windows/hstring-class.md)