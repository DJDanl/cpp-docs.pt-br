---
title: _ftell_nolock, _ftelli64_nolock | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _ftelli64_nolock
- _ftell_nolock
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
- _ftelli64_nolock
- ftelli64_nolock
- ftell_nolock
- _ftell_nolock
dev_langs:
- C++
helpviewer_keywords:
- ftelli64_nolock function
- _ftelli64_nolock function
- _ftell_nolock function
- ftell_nolock function
- file pointers [C++], getting current position
ms.assetid: 84e68b0a-32f8-4c4a-90ad-3f2387685ede
caps.latest.revision: 13
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
ms.openlocfilehash: 401d52ba5d52addb8192aabe5824c57fa9075e33
ms.lasthandoff: 02/25/2017

---
# <a name="ftellnolock-ftelli64nolock"></a>_ftell_nolock, _ftelli64_nolock
Obtém a posição atual de um ponteiro de arquivo sem bloquear o thread.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
long _ftell_nolock(   
   FILE *stream   
);  
__int64 _ftelli64_nolock(   
   FILE *stream   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `stream`  
 Têm como destino a estrutura `FILE`.  
  
## <a name="return-value"></a>Valor de retorno  
 O mesmo que `ftell` e `_ftelli64`. Para obter mais informações, consulte [ftell, _ftelli64](../../c-runtime-library/reference/ftell-ftelli64.md)**.**  
  
## <a name="remarks"></a>Comentários  
 Essas funções são versões sem bloqueio de `ftell` e `_ftelli64`, respectivamente. Elas são idênticas a `ftell` e `_ftelli64`, exceto pelo fato de não serem protegidas contra interferência de outros threads. Essas funções podem ser mais rápidas, porque não incorrem na sobrecarga de bloquear outros threads. Use estas funções apenas em contextos thread-safe, como aplicativos de thread único ou em que o escopo de chamada já trata do isolamento de threads.  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|Cabeçalho opcional|  
|--------------|---------------------|---------------------|  
|`ftell_nolock`|\<stdio.h>|\<errno.h>|  
|`_ftelli64_nolock`|\<stdio.h>|\<errno.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 [System::IO::FileStream::Position](https://msdn.microsoft.com/en-us/library/system.io.filestream.position.aspx)  
  
## <a name="see-also"></a>Consulte também  
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fgetpos](../../c-runtime-library/reference/fgetpos.md)   
 [fseek, _fseeki64](../../c-runtime-library/reference/fseek-fseeki64.md)   
 [_lseek, _lseeki64](../../c-runtime-library/reference/lseek-lseeki64.md)   
 [ftell, _ftelli64](../../c-runtime-library/reference/ftell-ftelli64.md)
