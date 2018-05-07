---
title: __readdr | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- __readdr
dev_langs:
- C++
helpviewer_keywords:
- __readdr intrinsic
ms.assetid: 061b05da-c85e-4052-b392-106f14bb84f1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ee18591ea3729551f00267fef6e4594a45f673ed
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="readdr"></a>__readdr
Lê o valor do registro de depuração especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
unsigned         __readdr(unsigned int DebugRegister);  
unsigned __int64 __readdr(unsigned int DebugRegister);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `DebugRegister`  
 Registrar uma constante de 0 a 7 que identifica a depuração.  
  
## <a name="return-value"></a>Valor de retorno  
 O valor do registro de depuração especificado.  
  
## <a name="remarks"></a>Comentários  
 Esses intrínsecos estão disponíveis apenas no modo de kernel e as rotinas estão disponíveis apenas como intrínsecos.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`__readdr`|x86, [!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h >  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [__readeflags](../intrinsics/readeflags.md)