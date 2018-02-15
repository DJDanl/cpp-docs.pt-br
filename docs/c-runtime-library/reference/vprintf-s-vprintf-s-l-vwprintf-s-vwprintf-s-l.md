---
title: vprintf_s, _vprintf_s_l, vwprintf_s, _vwprintf_s_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _vwprintf_s_l
- vwprintf_s
- _vprintf_s_l
- vprintf_s
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
- vprintf_s
- vwprintf_s
- _vtprintf_s
dev_langs:
- C++
helpviewer_keywords:
- vwprintf_s_l function
- _vwprintf_s_l function
- vwprintf_s function
- _vtprintf_s_l function
- vprintf_s_l function
- vtprintf_s_l function
- _vtprintf_s function
- vtprintf_s function
- _vprintf_s_l function
- formatted text [C++]
- vprintf_s function
ms.assetid: cf864996-a530-4b40-9c30-54c4cef439c8
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9293954a4b1f6748ff9b4845baf2d56c1621015f
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="vprintfs-vprintfsl-vwprintfs-vwprintfsl"></a>vprintf_s, _vprintf_s_l, vwprintf_s, _vwprintf_s_l
Grava saída formatada usando um ponteiro para uma lista de argumentos. Essas versões de [vprintf, _vprintf_l, vwprintf, _vwprintf_l](../../c-runtime-library/reference/vprintf-vprintf-l-vwprintf-vwprintf-l.md) têm aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int vprintf_s(  
   const char *format,  
   va_list argptr   
);  
int _vprintf_s_l(  
   const char *format,  
   locale_t locale,  
   va_list argptr   
);  
int vwprintf_s(  
   const wchar_t *format,  
   va_list argptr   
);  
int _vwprintf_s_l(  
   const wchar_t *format,  
   locale_t locale,  
   va_list argptr   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `format`  
 Especificação de formato.  
  
 `argptr`  
 Ponteiro para a lista de argumentos.  
  
 `locale`  
 A localidade a ser usada.  
  
 Para obter mais informações, consulte [Especificações de formato](../../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md).  
  
## <a name="return-value"></a>Valor de retorno  
 `vprintf_s` e `vwprintf_s` retornam o número de caracteres gravados, sem incluir o caractere nulo de terminação nem um valor negativo, se ocorrer um erro de saída. Se `format` for um ponteiro nulo, se a contagem for zero ou se a cadeia de caracteres de formato contiver caracteres de formatação inválidos, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão -1 e definirão `errno` como `EINVAL`.  
  
 Para obter informações sobre esses e outros códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 Cada uma dessas funções usa um ponteiro para uma lista de argumentos e, em seguida, formata e grava os dados fornecidos no `stdout`.  
  
 As versões seguras dessas funções são diferentes das versões `vprintf` e `vwprintf` apenas no sentido de que as versões seguras verificam se a cadeia de caracteres de contém caracteres de formatação válidos.  
  
 `vwprintf_s` é a versão de caractere largo de `vprintf_s`; as duas funções se comportam de forma idêntica quando o fluxo é aberto no modo ANSI. Atualmente, `vprintf_s` não dá suporte para a saída em um fluxo UNICODE.  
  
 As versões dessas funções com o sufixo `_l` são idênticas, com a exceção de usarem o parâmetro de localidade passado, em vez da localidade do thread atual.  
  
> [!IMPORTANT]
>  Verifique se `format` não é uma cadeia de caracteres definida pelo usuário. Para obter mais informações, consulte [Avoiding Buffer Overruns](http://msdn.microsoft.com/library/windows/desktop/ms717795) (Evitando estouros de buffer).  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_vtprintf_s`|`vprintf_s`|`vprintf_s`|`vwprintf_s`|  
|`_vtprintf_s_l`|`_vprintf_s_l`|`_vprintf_s_l`|`_vwprintf_s_l`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalhos opcionais|  
|-------------|---------------------|----------------------|  
|`vprintf_s`, `_vprintf_s_l`|\<stdio.h> e \<stdarg.h>|\<varargs.h>*|  
|`vwprintf_s`, `_vwprintf_s_l`|\<stdio.h> ou \<wchar.h> e \<stdarg.h>|\<varargs.h>*|  
  
 \* Necessário para compatibilidade com UNIX V.  
  
Não há suporte para o console em aplicativos do Windows UWP (plataforma Universal). Os identificadores de fluxo padrão que estão associados com o console, `stdin`, `stdout`, e `stderr`, deverá ser redirecionado para funções de tempo de execução C podem usá-los em aplicativos UWP. Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).
  
## <a name="see-also"></a>Consulte também  
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [Funções vprintf](../../c-runtime-library/vprintf-functions.md)   
 [fprintf, _fprintf_l, fwprintf, _fwprintf_l](../../c-runtime-library/reference/fprintf-fprintf-l-fwprintf-fwprintf-l.md)   
 [printf, _printf_l, wprintf, _wprintf_l](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)   
 [sprintf, _sprintf_l, swprintf, _swprintf_l, \__swprintf_l](../../c-runtime-library/reference/sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md)   
 [va_arg, va_copy, va_end, va_start](../../c-runtime-library/reference/va-arg-va-copy-va-end-va-start.md)