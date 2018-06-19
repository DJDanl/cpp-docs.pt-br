---
title: 'Método Handlet: | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleT::Detach
dev_langs:
- C++
helpviewer_keywords:
- Detach method
ms.assetid: f7df0f90-fafb-4d1b-a215-a6c62941f6b0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 100d215099494c9b2714fd2c42dee69644a5006c
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33878457"
---
# <a name="handletdetach-method"></a>Método HandleT::Detach
Desassocia o objeto HandleT atual de seu identificador subjacente.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
typename HandleTraits::Type Detach();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 O identificador subjacente.  
  
## <a name="remarks"></a>Comentários  
 Quando essa operação for concluída, o HandleT atual é definida para o estado inválido.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe HandleT](../windows/handlet-class.md)