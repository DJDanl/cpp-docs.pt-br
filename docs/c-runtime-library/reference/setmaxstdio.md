---
title: _setmaxstdio | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _setmaxstdio
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
- setmaxstdio
- _setmaxstdio
dev_langs:
- C++
helpviewer_keywords:
- maximum open files
- _setmaxstdio function
- setmaxstdio function
- open files, maximum
ms.assetid: 9e966875-9ff5-47c4-9b5f-e79e83b70249
caps.latest.revision: 12
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: 1ad2bb0cd27d24d7051f782b4ed72a1014fb5ec6
ms.contentlocale: pt-br
ms.lasthandoff: 04/01/2017

---
# <a name="setmaxstdio"></a>_setmaxstdio
Define o máximo para o número de arquivos abertos simultaneamente no nível `stdio`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _setmaxstdio(  
   int newmax   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `newmax`  
 Novo máximo para o número de arquivos abertos simultaneamente no nível `stdio`.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna `newmax` se bem-sucedido; caso contrário, de -1.  
  
 Se `newmax` é menor que `_IOB_ENTRIES` ou superior ao número máximo de identificadores disponíveis no sistema operacional, o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função retornará um valor –1 e definirá `errno` como `EINVAL`.  
  
 Para obter informações sobre esses e outros códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 A função `_setmaxstdio` altera o valor máximo para o número de arquivos que podem ser abertos simultaneamente no nível `stdio`.  
  
 A E/S em tempo de execução de C agora dá suporte a muito mais arquivos abertos em plataformas Win32 do que nas versões anteriores. Até 2.048 arquivos podem ser abertos simultaneamente no [nível lowio](../../c-runtime-library/low-level-i-o.md) (ou seja, abertos e acessados por meio das famílias de funções de E/S `_open`, `_read`, `_write` e assim por diante). Até 512 arquivos podem ser abertos simultaneamente no [nível stdio](../../c-runtime-library/stream-i-o.md) (ou seja, abertos e acessados por meio das famílias de funções `fopen`, `fgetc`, `fputc` e assim por diante). O limite de 512 arquivos abertos no nível `stdio` pode ser elevado para um máximo de 2.048 por meio da função `_setmaxstdio`.  
  
 Devido ao fato das funções no nível `stdio` como `fopen` serem compiladas sobre as funções `lowio`, o número máximo de 2.048 é um limite superior rígido para o número de arquivos abertos simultaneamente acessados por meio da biblioteca em tempo de execução de C.  
  
> [!NOTE]
>  Esse limite pode estar além do que tem suporte por uma determinada plataforma Win32 e sua respectiva configuração.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_setmaxstdio`|\<stdio.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
 Consulte [_getmaxstdio](../../c-runtime-library/reference/getmaxstdio.md) para obter um exemplo de como usar `_setmaxstdio`.  
  
## <a name="see-also"></a>Consulte também  
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)
