---
title: Macro offsetof | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apilocation:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
apitype: DLLExport
f1_keywords:
- offsetof
dev_langs:
- C++
helpviewer_keywords:
- structure members, offset
- offsetof macro
ms.assetid: f3b4eb16-a882-4d38-afc9-eebd976a7352
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a70bb2823f29caf3f76224bfb91c3c9642bbdcf1
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="offsetof-macro"></a>Macro offsetof
Recupera o deslocamento de um membro do início de sua estrutura pai.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      size_t offsetof(  
   structName,  
   memberName   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *structName*  
 Nome da estrutura de dados pai.  
  
 `memberName`  
 Nome do membro na estrutura de dados pai para o qual determinar o deslocamento.  
  
## <a name="return-value"></a>Valor de retorno  
 `offsetof` retorna o deslocamento em bytes do membro especificado do início de sua estrutura de dados pai. É indefinido para campos de bits.  
  
## <a name="remarks"></a>Comentários  
 O macro `offsetof` retorna o deslocamento em bytes do `memberName` desde o início da estrutura especificado por *structName* como um valor do tipo `size_t`. Você pode especificar tipos com a palavra-chave `struct`.  
  
> [!NOTE]
>  `offsetof` não é uma função e não pode ser descrito usando um protótipo de C.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`offsetof`|\<stddef.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="libraries"></a>Libraries  
 Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="see-also"></a>Consulte também  
 [Alocação de Memória](../../c-runtime-library/memory-allocation.md)