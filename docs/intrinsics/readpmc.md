---
title: __readpmc | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- __readpmc
dev_langs:
- C++
helpviewer_keywords:
- Read Performance Monitoring Counters instruction
- __readpmc intrinsic
- rdpmc instruction
ms.assetid: 14ed45a6-28b6-4635-8437-a597c04b43d4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b0a5a172a7b0f8a309f1d8fd0762e098dc5d416a
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45720025"
---
# <a name="readpmc"></a>__readpmc
**Seção específica da Microsoft**  
  
 Gera o `rdpmc` instrução, que lê o desempenho de monitoramento do contador especificado por `counter`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
unsigned __int64 __readpmc(   
   unsigned long counter   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
*counter*<br/>
[in] O contador de desempenho de leitura.  
  
## <a name="return-value"></a>Valor de retorno  
 O valor do contador de desempenho especificado.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`__readpmc`|x86, x64|  
  
 **Arquivo de cabeçalho** \<intrin. h >  
  
## <a name="remarks"></a>Comentários  
 Esse intrínseco está disponível no modo de kernel apenas e a rotina só está disponível como um intrínseco.  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)