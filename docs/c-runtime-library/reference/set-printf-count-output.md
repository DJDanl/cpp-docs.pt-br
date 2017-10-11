---
title: _set_printf_count_output | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _set_printf_count_output
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
- set_printf_count_output
- _set_printf_count_output
dev_langs:
- C++
helpviewer_keywords:
- '%n format'
- set_printf_count_output function
- _set_printf_count_output function
ms.assetid: d8259ec5-764e-42d0-9169-72172e95163b
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: 8229146184b4d4d0cfbccd60f6c4209356db5f8f
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="setprintfcountoutput"></a>_set_printf_count_output
Habilite ou desabilite o suporte ao formato `%n` nas funções da família [printf, _printf_l, wprintf, _wprintf_l](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _set_printf_count_output(  
   int enable  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `enable`  
 Um valor diferente de zero para habilitar o suporte a `%n` ou 0 para desabilitar o suporte a `%n`.  
  
## <a name="property-valuereturn-value"></a>Valor de propriedade/Valor de retorno  
 O estado do suporte a `%n` antes de chamar essa função: diferente de zero se o suporte a `%n` foi habilitado, 0 se ele foi desabilitado.  
  
## <a name="remarks"></a>Comentários  
 Por motivos de segurança, o suporte para o especificador de formato `%n` é desabilitado por padrão em `printf` e todas as suas variantes. Se `%n` for encontrada em uma especificação de formato `printf`, o comportamento padrão será invocar o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Chamando `_set_printf_count_output` com um argumento diferente de zero fará com que `printf`-as funções da família interpretar `%n` conforme descrito em [sintaxe de especificação de formato: funções printf e and wprintf](../../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_set_printf_count_output`|\<stdio.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```C  
// crt_set_printf_count_output.c  
#include <stdio.h>  
  
int main()  
{  
   int e;  
   int i;  
   e = _set_printf_count_output( 1 );  
   printf( "%%n support was %sabled.\n",  
        e ? "en" : "dis" );  
   printf( "%%n support is now %sabled.\n",  
        _get_printf_count_output() ? "en" : "dis" );  
   printf( "12345%n6789\n", &i ); // %n format should set i to 5  
   printf( "i = %d\n", i );  
}  
```  
  
```Output  
%n support was disabled.  
%n support is now enabled.  
123456789  
i = 5  
```  
  
## <a name="see-also"></a>Consulte também  
 [_get_printf_count_output](../../c-runtime-library/reference/get-printf-count-output.md)
