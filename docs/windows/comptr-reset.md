---
title: ComPtr::Reset | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
ms.assetid: aa6a46f7-f56b-4fd5-add0-7cea55f7abda
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 74f26f520be276de863c612718de8520bffc1219
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39649699"
---
# <a name="comptrreset"></a>ComPtr::Reset
Libera todas as referências para o ponteiro para a interface que está associado a este **ComPtr**.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
unsigned long Reset();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 O número de referências liberado, se houver.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe ComPtr](../windows/comptr-class.md)