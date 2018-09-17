---
title: __writedr | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- __writedr
dev_langs:
- C++
helpviewer_keywords:
- __writedr intrinsic
ms.assetid: ac55c1ee-df2f-41d4-a429-6f369d2a934d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b559edf26c847404d718440e86037cab4026297b
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45704945"
---
# <a name="writedr"></a>__writedr
Grava o valor especificado para o registro de depuração especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void __writedr(unsigned DebugRegister, unsigned DebugValue);  
void __writedr(unsigned DebugRegister, unsigned __int64 DebugValue);  
```  
  
#### <a name="parameters"></a>Parâmetros  
*DebugRegister*<br/>
[in] Registre-se um número de 0 a 7 que identifica a depuração.  
  
*DebugValue*<br/>
[in] Registre-se um valor a ser gravado para a depuração.  
  
## <a name="remarks"></a>Comentários  
 Esses intrínsecos estão disponíveis somente no modo kernel e as rotinas estão disponíveis apenas como intrínsecos.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`__writedr`|x86, x64|  
  
 **Arquivo de cabeçalho** \<intrin. h >  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [__readdr](../intrinsics/readdr.md)