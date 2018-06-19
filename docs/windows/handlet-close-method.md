---
title: 'Método Handlet: | Microsoft Docs'
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
ms.openlocfilehash: 4f0c1e47420106651cfe0526d6d212e9819a72ff
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33873245"
---
# <a name="handletclose-method"></a>Método HandleT::Close
Fecha o objeto HandleT atual.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void Close();  
```  
  
## <a name="remarks"></a>Comentários  
 O identificador subjacente a HandleT atual é fechado e o HandleT é definido para o estado inválido.  
  
 Se o identificador não fechar corretamente, uma exceção será gerada no thread de chamada.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe HandleT](../windows/handlet-class.md)