---
title: 'Método handlet:: Close | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleT::Close
dev_langs:
- C++
helpviewer_keywords:
- Close method
ms.assetid: 1b9d597c-abcf-4028-a068-0344560009f6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 7cbe76cdea5c8fadef818ede1d63d88e4437bdae
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39651061"
---
# <a name="handletclose-method"></a>Método HandleT::Close
Fecha o atual **HandleT** objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
void Close();  
```  
  
## <a name="remarks"></a>Comentários  
 O identificador subjacente ao atual **HandleT** for fechada e o **HandleT** é definido como o estado inválido.  
  
 Se o identificador não fechar corretamente, uma exceção é gerada no thread de chamada.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe HandleT](../windows/handlet-class.md)