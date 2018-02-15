---
title: _get_fmode | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _get_fmode
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
- api-ms-win-crt-stdio-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- get_fmode
- _get_fmode
dev_langs:
- C++
helpviewer_keywords:
- _get_fmode function
- file translation [C++], default mode
- get_fmode function
ms.assetid: 22ea70e2-b9b5-422d-b514-64f4beaea45c
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: abfdd4d9b8838914a91b4db995fcaad573e80829
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="getfmode"></a>_get_fmode
Obtém o modo de conversão de arquivo padrão para operações de E/S de arquivo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
errno_t _get_fmode(   
   int * pmode   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [out] `pmode`  
 Um ponteiro para um inteiro a ser preenchido com o modo padrão atual: `_O_TEXT` ou `_O_BINARY`.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna zero se tiver êxito; um código de erro em caso de falha. Se `pmode` for `NULL`, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, `errno` será definido como `EINVAL` e a função retornará `EINVAL`.  
  
## <a name="remarks"></a>Comentários  
 A função obtém o valor da variável global [_fmode](../../c-runtime-library/fmode.md). Essa variável especifica o modo de conversão de arquivo padrão para operações de E/S de arquivo de fluxo e de baixo nível, como `_open`, `_pipe`, `fopen` e `freopen`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|-------------|---------------------|---------------------|  
|`_get_fmode`|\<stdlib.h>|\<fcntl.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
 Veja o exemplo em [_set_fmode](../../c-runtime-library/reference/set-fmode.md).  
  
## <a name="see-also"></a>Consulte também  
 [_fmode](../../c-runtime-library/fmode.md)   
 [_set_fmode](../../c-runtime-library/reference/set-fmode.md)   
 [_setmode](../../c-runtime-library/reference/setmode.md)   
 [E/S de texto e arquivo de modo binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md)