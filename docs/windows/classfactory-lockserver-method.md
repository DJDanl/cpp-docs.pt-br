---
title: 'Método ClassFactory:: Lockserver | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::ClassFactory::LockServer
dev_langs:
- C++
helpviewer_keywords:
- LockServer method
ms.assetid: 8d859815-956d-4f81-a5af-7cdee7e945de
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: ee858346fdb70e136edfbc562c2dfffb1f63e462
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39652364"
---
# <a name="classfactorylockserver-method"></a>Método ClassFactory::LockServer
Aumenta ou diminui o número de subjacente objetos que são controladas pelo atual **ClassFactory** objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
STDMETHOD(  
   LockServer  
)(BOOL fLock);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *Usam*  
 **True** para incrementar o número de objetos rastreados. **False** para diminuir o número de objetos rastreadas.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, E_FAIL.  
  
## <a name="remarks"></a>Comentários  
 **ClassFactory** mantém o controle de objetos em uma instância subjacente do [módulo](../windows/module-class.md) classe.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe ClassFactory](../windows/classfactory-class.md)