---
title: "Método ClassFactory: | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: module/Microsoft::WRL::ClassFactory::LockServer
dev_langs: C++
helpviewer_keywords: LockServer method
ms.assetid: 8d859815-956d-4f81-a5af-7cdee7e945de
caps.latest.revision: "5"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5f646f198d884e677b622a312cfdb6187802e1c6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="classfactorylockserver-method"></a>Método ClassFactory::LockServer
Aumenta ou diminui o número de base de objetos que são controlados pelo objeto ClassFactory atual.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
STDMETHOD(  
   LockServer  
)(BOOL fLock);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `fLock`  
 `true`para incrementar o número de objetos rastreados. `false`para diminuir o número de objetos rastreados.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, E_FAIL.  
  
## <a name="remarks"></a>Comentários  
 ClassFactory mantém o controle de objetos em uma instância subjacente do [módulo](../windows/module-class.md) classe.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Classe ClassFactory](../windows/classfactory-class.md)