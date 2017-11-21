---
title: __readcr4 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: __readcr4
dev_langs: C++
helpviewer_keywords: __readcr4 intrinsic
ms.assetid: b841a27b-fe0d-4ee9-b76b-f91d3eb061fa
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 2438ea27d7d8bee1636b4885d83562752e41c3ff
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="readcr4"></a>__readcr4
**Seção específica da Microsoft**  
  
 Lê o registro de CR4 e retorna seu valor.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
unsigned __int64 __readcr4(void);  
```  
  
## <a name="return-value"></a>Valor de retorno  
 O valor no registro CR4.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`__readcr4`|x86, [!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h >  
  
## <a name="remarks"></a>Comentários  
 Esse intrínseco só está disponível no modo kernel e a rotina só está disponível como um intrínseco.  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)