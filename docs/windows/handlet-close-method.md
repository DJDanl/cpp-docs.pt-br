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
ms.openlocfilehash: 69f3f2c756d158954676f6fc42941b1b80f4345e
ms.sourcegitcommit: d5d6bb9945c3550b8e8864b22b3a565de3691fde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/06/2018
ms.locfileid: "39569912"
---
# <a name="handletclose-method"></a>Método HandleT::Close
Fecha o atual **HandleT** objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
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