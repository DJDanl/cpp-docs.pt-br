---
title: "memcpy, wmemcpy | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "memcpy"
  - "wmemcpy"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
apitype: "DLLExport"
f1_keywords: 
  - "wmemcpy"
  - "memcpy"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função memcpy"
  - "Função wmemcpy"
ms.assetid: 34abb90b-bffb-46dc-a2f3-a5e9940839d6
caps.latest.revision: 21
caps.handback.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# memcpy, wmemcpy
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Bytes de cópias entre buffers.  Versões mais seguras dessas funções estão disponíveis; consulte [memcpy\_s, wmemcpy\_s](../../c-runtime-library/reference/memcpy-s-wmemcpy-s.md).  
  
## Sintaxe  
  
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
  
#### Parâmetros  
 `dest`  
 Novo buffer.  
  
 `src`  
 Buffer para copiar de.  
  
 `count`  
 Número de caracteres a serem copiados.  
  
## Valor de retorno  
 O valor de `dest`.  
  
## Comentários  
 `memcpy` cópias `count` bytes de `src` para `dest`; `wmemcpy` cópias `count` caracteres largos \(dois bytes\).  Se a origem e o destino se sobrepõem, o comportamento de `memcpy` é indefinido.  Use `memmove` para lidar com regiões sobrepostas.  
  
> [!IMPORTANT]
>  Certifique\-se de que o buffer de destino é o mesmo tamanho ou maior que o buffer de origem.  Para obter mais informações, consulte [Evitando saturações de buffer](http://msdn.microsoft.com/library/windows/desktop/ms717795).  
  
> [!IMPORTANT]
>  Porque muitos saturações de buffer e, portanto, possíveis explorações de segurança, têm foi rastreadas para uso impróprio de `memcpy`, essa função está listada entre as funções de "proibidas" pelo Security Development Lifecycle \(SDL\).  Você pode observar que algumas classes de biblioteca do VC \+ \+ continuam a usar `memcpy`.  Além disso, você pode observar que o otimizador do compilador do VC \+ \+, às vezes, emite chamadas para `memcpy`.  O produto Visual C\+\+ foi desenvolvido de acordo com o processo SDL e, portanto, o uso dessa função proibida foi intimamente avaliado.  No caso de biblioteca usá\-lo, as chamadas foram examinadas com cuidado para garantir que estouros de buffer não poderá passar essas chamadas.  No caso do compilador, às vezes, certos padrões de código são reconhecidos como idênticos para o padrão de `memcpy`, e, portanto, são substituídas por uma chamada à função.  Nesses casos, o uso de `memcpy` é não é mais seguro do que o original instruções teria sido; eles simplesmente foram otimizados para uma chamada para o desempenho adequado `memcpy` função.  Assim como o uso de funções de CRT "seguras" não garante a segurança \(eles somente dificultam a não ser seguro\), o uso de funções de "proibidos" não garante o perigo \(eles apenas exigem maior controle para garantir a segurança\).  
>   
>  Porque `memcpy` uso pelo compilador VC \+ \+ e bibliotecas foram examinado tão cuidadosamente, essas chamadas são permitidas no código que está em conformidade com o SDL.  `memcpy` chamadas introduzidas no código fonte do aplicativo só são compatíveis com o SDL quando foi revisado que usam por especialistas em segurança.  
  
 O `memcpy` e `wmemcpy` funções só serão substituídas se a constante `_CRT_SECURE_DEPRECATE_MEMORY` está definido antes da declaração de inclusão para que as funções a ser substituído, tal como no exemplo a seguir:  
  
```  
#define _CRT_SECURE_DEPRECATE_MEMORY  
#include <memory.h>  
```  
  
 ou  
  
```  
#define _CRT_SECURE_DEPRECATE_MEMORY  
#include <wchar.h>  
```  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`memcpy`|\< memory.h \> ou \< String. h \>|  
|`wmemcpy`|\< WCHAR. h \>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
 Consulte [memmove](../../c-runtime-library/reference/memmove-wmemmove.md) para obter um exemplo de como usar `memcpy`.  
  
## Consulte também  
 [Manipulação de buffer](../Topic/Buffer%20Manipulation.md)   
 [\_memccpy](../../c-runtime-library/reference/memccpy.md)   
 [memchr, wmemchr](../Topic/memchr,%20wmemchr.md)   
 [memcmp, wmemcmp](../../c-runtime-library/reference/memcmp-wmemcmp.md)   
 [memmove, wmemmove](../../c-runtime-library/reference/memmove-wmemmove.md)   
 [memset, wmemset](../../c-runtime-library/reference/memset-wmemset.md)   
 [strcpy\_s, wcscpy\_s, \_mbscpy\_s](../../c-runtime-library/reference/strcpy-s-wcscpy-s-mbscpy-s.md)   
 [strncpy\_s, \_strncpy\_s\_l, wcsncpy\_s, \_wcsncpy\_s\_l, \_mbsncpy\_s, \_mbsncpy\_s\_l](../Topic/strncpy_s,%20_strncpy_s_l,%20wcsncpy_s,%20_wcsncpy_s_l,%20_mbsncpy_s,%20_mbsncpy_s_l.md)