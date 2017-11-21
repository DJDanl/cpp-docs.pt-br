---
title: strerror_s, _strerror_s, _wcserror_s, __wcserror_s | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- __wcserror_s
- _strerror_s
- _wcserror_s
- strerror_s
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
- api-ms-win-crt-runtime-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- wcserror_s
- __wcserror_s
- _tcserror_s
- _wcserror_s
- tcserror_s
- strerror_s
- _strerror_s
dev_langs: C++
helpviewer_keywords:
- __wcserror_s function
- error messages, printing
- tcserror_s function
- printing error messages
- strerror_s function
- _wcserror_s function
- _tcserror_s function
- _strerror_s function
- wcserror_s function
- error messages, getting
ms.assetid: 9e5b15a0-efe1-4586-b7e3-e1d7c31a03d6
caps.latest.revision: "21"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: d14c4fd98a9191e8a92d3f24dc24c19de2433e15
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="strerrors-strerrors-wcserrors-wcserrors"></a>strerror_s, _strerror_s, _wcserror_s, __wcserror_s
Receba uma mensagem de erro do sistema (`strerror_s`, `_wcserror_s`) ou imprima uma mensagem de erro fornecida pelo usuário (`_strerror_s`, `__wcserror_s`). Estas são versões de [strerror, _strerror, _wcserror, \__wcserror](../../c-runtime-library/reference/strerror-strerror-wcserror-wcserror.md) com aprimoramentos de segurança, conforme descrito em [Recursos de Segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
errno_t strerror_s(  
   char *buffer,  
   size_t numberOfElements,  
   int errnum   
);  
errno_t _strerror_s(  
   char *buffer,  
   size_t numberOfElements,  
   const char *strErrMsg   
);  
errno_t _wcserror_s(  
   wchar_t *buffer,  
   size_t numberOfElements,  
   int errnum   
);  
errno_t __wcserror_s(  
   wchar_t *buffer,  
   size_t numberOfElements,  
   const wchar_t *strErrMsg   
);  
template <size_t size>  
errno_t strerror_s(  
   char (&buffer)[size],  
   int errnum   
); // C++ only  
template <size_t size>  
errno_t _strerror_s(  
   char (&buffer)[size],  
   const char *strErrMsg   
); // C++ only  
template <size_t size>  
errno_t _wcserror_s(  
   wchar_t (&buffer)[size],  
   int errnum   
); // C++ only  
template <size_t size>  
errno_t __wcserror_s(  
   wchar_t (&buffer)[size],  
   const wchar_t *strErrMsg   
); // C++ only  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `buffer`  
 Buffer para conter a cadeia de caracteres de erro.  
  
 `numberOfElements`  
 Tamanho do buffer.  
  
 `errnum`  
 Número do erro.  
  
 `strErrMsg`  
 Mensagem fornecida pelo usuário.  
  
## <a name="return-value"></a>Valor de retorno  
 Zero se for bem-sucedido ou um código de erro em caso de falha.  
  
### <a name="error-condtions"></a>Condições de erro  
  
|`buffer`|`numberOfElements`|`strErrMsg`|Conteúdo de `buffer`|  
|--------------|------------------------|-----------------|--------------------------|  
|`NULL`|qualquer|qualquer|N/D|  
|qualquer|0|qualquer|não modificado|  
  
## <a name="remarks"></a>Comentários  
 A função `strerror_s` mapeia `errnum` para uma cadeia de caracteres de mensagens, retornando a cadeia de caracteres em `buffer`. `_strerror_s` não usa o número de erro; ele usa o valor atual de `errno` para determinar a mensagem apropriada. Nem `strerror_s` nem `_strerror_s` imprimem a mensagem: para fazer isso, você precisa chamar uma função de saída como [fprintf](../../c-runtime-library/reference/fprintf-fprintf-l-fwprintf-fwprintf-l.md):  
  
```  
if (( _access( "datafile",2 )) == -1 )  
{  
   _strerror_s(buffer, 80);  
   fprintf( stderr, buffer );  
}  
```  
  
 Se `strErrMsg` for `NULL`, `_strerror_s` retornará uma cadeia de caracteres em `buffer` contendo a mensagem de erro do sistema para a última chamada da biblioteca que tiver produzido um erro. A cadeia de caracteres de mensagens de erro é encerrada pelo caractere newline ('\n'). Se `strErrMsg` não for igual a `NULL`, então `_strerror_s` retornará um ponteiro para uma cadeia de caracteres em `buffer` contendo (nessa ordem) sua mensagem de cadeia de caracteres, dois-pontos, um espaço, a mensagem de erro do sistema para a última chamada da biblioteca que produz um erro e um caractere newline. Sua mensagem da cadeia de caracteres pode ter, no máximo, 94 caracteres de comprimento.  
  
 Essas funções truncarão a mensagem de erro se seu comprimento exceder `numberOfElements` -1. A cadeia de caracteres resultante em `buffer` é sempre terminada em nulo.  
  
 O número do erro real para `_strerror_s` é armazenado na variável [errno](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md). As mensagens de erro do sistema são acessadas por meio da variável [_sys_errlist](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md), que é uma matriz de mensagens ordenadas por número do erro. `_strerror_s` acessa a mensagem de erro apropriada usando o valor `errno` como um índice para a variável `_sys_errlist`. O valor da variável [_sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) é definido como o número máximo de elementos na matriz `_sys_errlist`. Para produzir resultados precisos, chame `_strerror_s` imediatamente após uma rotina da biblioteca retornar um erro. Caso contrário, chamadas subsequentes para `strerror_s` ou `_strerror_s` podem substituir o valor `errno`.  
  
 `_wcserror_s` e `__wcserror_s` são as versões de caractere largo de `strerror_s` e `_strerror_s`, respectivamente.  
  
 Essas funções validam seus parâmetros. Se o buffer for `NULL` ou se o parâmetro de tamanho for 0, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essas funções retornarão `EINVAL` e definirão `errno` como `EINVAL`.  
  
 `_strerror_s`, `_wcserror_s`, e `__wcserror_s` não fazem parte da definição de ANSI, mas em vez disso, são extensões da Microsoft para ele. Não use-as quando desejar portabilidade; para obter compatibilidade com ANSI, use `strerror_s` em seu lugar.  
  
 No C++, o uso dessas funções é simplificado por sobrecargas de modelo. As sobrecargas podem inferir automaticamente o tamanho do buffer, eliminando a necessidade de especificar um argumento de tamanho. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).  
  
 As versões de depuração dessas funções preenchem primeiro o buffer com 0xFD. Para desabilitar esse comportamento, use [_CrtSetDebugFillThreshold](../../c-runtime-library/reference/crtsetdebugfillthreshold.md).  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tcserror_s`|`strerror_s`|`strerror_s`|`_wcserror_s`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`strerror_s`, `_strerror_s`|\<string.h>|  
|`_wcserror_s`, `__wcserror_s`|\<string.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
 Veja o exemplo de [perror](../../c-runtime-library/reference/perror-wperror.md).  
  
## <a name="see-also"></a>Consulte também  
 [Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [clearerr](../../c-runtime-library/reference/clearerr.md)   
 [ferror](../../c-runtime-library/reference/ferror.md)   
 [perror, _wperror](../../c-runtime-library/reference/perror-wperror.md)