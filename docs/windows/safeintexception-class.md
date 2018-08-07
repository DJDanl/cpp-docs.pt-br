---
title: Classe SafeIntException | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- SafeIntException Class
dev_langs:
- C++
helpviewer_keywords:
- SafeIntException class
ms.assetid: 88bef958-1f48-4d55-ad4f-d1f9581a293a
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: cbcb04229ea0d60c7bc5abfeb1db3f671c92c6b8
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39604974"
---
# <a name="safeintexception-class"></a>Classe SafeIntException
O `SafeInt` classe usa **SafeIntException** para identificar o motivo pelo qual uma operação matemática não pode ser concluída.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class SafeIntException;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
 [SafeIntException::SafeIntException](../windows/safeintexception-safeintexception.md)  
 Cria uma **SafeIntException** objeto.  
  
## <a name="remarks"></a>Comentários  
 O [classe SafeInt](../windows/safeint-class.md) é a única classe que usa o **SafeIntException** classe.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [Classe SafeIntException](../windows/safeintexception-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** safeint  
  
 **Namespace:** MSL:: Utilities  
  
## <a name="see-also"></a>Consulte também  
 [Biblioteca SafeInt](../windows/safeint-library.md)   
 [Classe SafeInt](../windows/safeint-class.md)