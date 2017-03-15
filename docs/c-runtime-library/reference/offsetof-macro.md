---
title: Macro offsetof | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: ccffd202ae3f4d52dda49a8a81ba81097db624b6
ms.lasthandoff: 02/25/2017

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
