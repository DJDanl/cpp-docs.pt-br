---
title: _close | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _close
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
- _close
dev_langs:
- C++
helpviewer_keywords:
- _close function
- close function
- files [C++], closing
ms.assetid: 4708a329-8acf-4cd9-b7b0-a952e1897247
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
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: ddcd28eb65b174ba2e4bd901cf2556b99ac4de2c
ms.lasthandoff: 02/25/2017

---
# <a name="close"></a>_close
Fecha um arquivo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _close(   
   int fd   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `fd`  
 Descritor de arquivo que se refere ao arquivo aberto.  
  
## <a name="return-value"></a>Valor retornado  
 `_close` retornará 0 se o arquivo tiver sido fechado com êxito. Um valor retornado de -1 indica que há um erro.  
  
## <a name="remarks"></a>Comentários  
 A função `_close` fecha o arquivo associado a `fd`.  
  
 O descritor de arquivo e o identificador de arquivo do sistema operacional subjacente são fechados. Portanto, não será necessário chamar `CloseHandle` se o arquivo tiver sido aberto originalmente usando a função Win32 `CreateFile` e convertido em um descritor de arquivo usando `_open_osfhandle`.  
  
 Essa função valida seus parâmetros. Se `fd` for um descritor do arquivo inválido, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, a função retornará -1 e `errno` será definido como `EBADF`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|-------------|---------------------|---------------------|  
|`_close`|\<io.h>|\<errno.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
 Veja o exemplo de [_open](../../c-runtime-library/reference/open-wopen.md).  
  
## <a name="see-also"></a>Consulte também  
 [E/S de nível inferior](../../c-runtime-library/low-level-i-o.md)   
 [_chsize](../../c-runtime-library/reference/chsize.md)   
 [_creat, _wcreat](../../c-runtime-library/reference/creat-wcreat.md)   
 [_dup, _dup2](../../c-runtime-library/reference/dup-dup2.md)   
 [_open, _wopen](../../c-runtime-library/reference/open-wopen.md)   
 [_unlink, _wunlink](../../c-runtime-library/reference/unlink-wunlink.md)
