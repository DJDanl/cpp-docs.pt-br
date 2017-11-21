---
title: memcpy, wmemcpy | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- memcpy
- wmemcpy
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
- wmemcpy
- memcpy
dev_langs: C++
helpviewer_keywords:
- wmemcpy function
- memcpy function
ms.assetid: 34abb90b-bffb-46dc-a2f3-a5e9940839d6
caps.latest.revision: "21"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 38c00e7d7c5eb9f4a1076ae3814c17a8062fe322
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="memcpy-wmemcpy"></a>memcpy, wmemcpy
Copia bytes entre buffers. Estão disponíveis versões mais seguras dessas funções, consulte [memcpy_s, wmemcpy_s](../../c-runtime-library/reference/memcpy-s-wmemcpy-s.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void *memcpy(  
   void *dest,  
   const void *src,  
   size_t count   
);  
wchar_t *wmemcpy(  
   wchar_t *dest,  
   const wchar_t *src,  
   size_t count  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `dest`  
 Novo buffer.  
  
 `src`  
 Buffer do qual copiar.  
  
 `count`  
 O número de caracteres a serem copiados.  
  
## <a name="return-value"></a>Valor de retorno  
 O valor de `dest`.  
  
## <a name="remarks"></a>Comentários  
 `memcpy` copia `count` bytes de `src` para `dest`, `wmemcpy` copia `count` caracteres largos (dois bytes). Se a origem e o destino se sobrepõem, o comportamento de `memcpy` é indefinido. Use `memmove` para lidar com regiões sobrepostas.  
  
> [!IMPORTANT]
>  Certifique-se de que o buffer de destino seja do mesmo tamanho ou maior que o buffer de origem. Para obter mais informações, consulte [Avoiding Buffer Overruns](http://msdn.microsoft.com/library/windows/desktop/ms717795) (Evitando estouros de buffer).  
  
> [!IMPORTANT]
>  Como muitas saturações e, portanto, potenciais explorações de segurança, foram rastreadas para o uso impróprio de `memcpy`, essa função é listada entre as funções “banidas” pelo SDL (Security Development Lifecycle).  Você pode observar que algumas classes de biblioteca do VC++ continuam a usar `memcpy`.  Além disso, você pode observar que o otimizador do compilador do VC++, às vezes, emite chamadas para `memcpy`.  O produto Visual C++ foi desenvolvido de acordo com o processo SDL e, portanto, o uso desta função proibida foi cuidadosamente avaliado.  No caso do uso dela pela biblioteca, as chamadas foram cuidadosamente examinadas para garantir que os estouros de buffer não serão permitidos por meio dessas chamadas.  No caso do compilador, às vezes, certos padrões de código são reconhecidos como idênticos ao padrão de `memcpy` e, portanto, são substituídos por uma chamada para a função.  Nesses casos, o uso de `memcpy` é não é mais inseguro do que as instruções originais seriam, elas simplesmente foram otimizadas para uma chamada para a função `memcpy` ajustada para o desempenho.  Assim como o uso de funções de CRT "seguras" não assegura a segurança (elas simplesmente fazem com que seja mais difícil de serem inseguras), o uso de funções “proibidas” não assegura o perigo (elas apenas exigem um exame maior para garantir a segurança).  
>   
>  Como o uso de `memcpy` pelas bibliotecas e pelo compilador VC++ foi examinado tão cuidadosamente, essas chamadas também são permitidas no código que de outra forma estão em conformidade com SDL.  As chamadas `memcpy` introduzidas no código-fonte do aplicativo estão em conformidade com o SDL apenas quando esse uso foi examinado pelos especialistas em segurança.  
  
 As funções `memcpy` e `wmemcpy` serão preteridas apenas se a constante `_CRT_SECURE_DEPRECATE_MEMORY` for definida antes da instrução de inclusão para que as funções sejam preteridas, como o exemplo a seguir:  
  
```  
#define _CRT_SECURE_DEPRECATE_MEMORY  
#include <memory.h>  
```  
  
 ou  
  
```  
#define _CRT_SECURE_DEPRECATE_MEMORY  
#include <wchar.h>  
```  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`memcpy`|\<memory.h> ou \<string.h>|  
|`wmemcpy`|\<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
 Consulte [memmove](../../c-runtime-library/reference/memmove-wmemmove.md) para encontrar um exemplo de como usar `memcpy`.  
  
## <a name="see-also"></a>Consulte também  
 [Manipulação de buffer](../../c-runtime-library/buffer-manipulation.md)   
 [_memccpy](../../c-runtime-library/reference/memccpy.md)   
 [memchr, wmemchr](../../c-runtime-library/reference/memchr-wmemchr.md)   
 [memcmp, wmemcmp](../../c-runtime-library/reference/memcmp-wmemcmp.md)   
 [memmove, wmemmove](../../c-runtime-library/reference/memmove-wmemmove.md)   
 [memset, wmemset](../../c-runtime-library/reference/memset-wmemset.md)   
 [strcpy_s, wcscpy_s, _mbscpy_s](../../c-runtime-library/reference/strcpy-s-wcscpy-s-mbscpy-s.md)   
 [strncpy_s, _strncpy_s_l, wcsncpy_s, _wcsncpy_s_l, _mbsncpy_s, _mbsncpy_s_l](../../c-runtime-library/reference/strncpy-s-strncpy-s-l-wcsncpy-s-wcsncpy-s-l-mbsncpy-s-mbsncpy-s-l.md)