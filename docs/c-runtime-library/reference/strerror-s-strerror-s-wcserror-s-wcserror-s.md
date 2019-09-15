---
title: strerror_s, _strerror_s, _wcserror_s, __wcserror_s
ms.date: 11/04/2016
api_name:
- __wcserror_s
- _strerror_s
- _wcserror_s
- strerror_s
api_location:
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- wcserror_s
- __wcserror_s
- _tcserror_s
- _wcserror_s
- tcserror_s
- strerror_s
- _strerror_s
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
ms.openlocfilehash: f8d461566f748ce5af3d4b2aab443b5966c27dd7
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70958162"
---
# <a name="strerror_s-_strerror_s-_wcserror_s-__wcserror_s"></a>strerror_s, _strerror_s, _wcserror_s, __wcserror_s

Obtenha uma mensagem de erro do sistema (**strerror_s**, **_wcserror_s**) ou imprima uma mensagem de erro fornecida pelo usuário ( **_strerror_s**, **__wcserror_s**). Estas são versões de [strerror, _strerror, _wcserror, \__wcserror](strerror-strerror-wcserror-wcserror.md) com aprimoramentos de segurança, conforme descrito em [Recursos de Segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
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

### <a name="parameters"></a>Parâmetros

*buffer*<br/>
Buffer para conter a cadeia de caracteres de erro.

*numberOfElements*<br/>
Tamanho do buffer.

*errnum*<br/>
Número do erro.

*strErrMsg*<br/>
Mensagem fornecida pelo usuário.

## <a name="return-value"></a>Valor de retorno

Zero se for bem-sucedido ou um código de erro em caso de falha.

### <a name="error-condtions"></a>Condições de erro

|*buffer*|*numberOfElements*|*strErrMsg*|Conteúdo do *buffer*|
|--------------|------------------------|-----------------|--------------------------|
|**NULL**|qualquer|qualquer|N/D|
|qualquer|0|qualquer|não modificado|

## <a name="remarks"></a>Comentários

A função **strerror_s** mapeia *errnum* para uma cadeia de caracteres de mensagem de erro, retornando a cadeia de caracteres no *buffer*. **_strerror_s** não pega o número do erro; Ele usa o valor atual de **errno** para determinar a mensagem apropriada. Nem **strerror_s** nem **_strerror_s** realmente imprime a mensagem: Para isso, você precisa chamar uma função de saída, como [fprintf](fprintf-fprintf-l-fwprintf-fwprintf-l.md):

```C
if (( _access( "datafile",2 )) == -1 )
{
   _strerror_s(buffer, 80);
   fprintf( stderr, buffer );
}
```

Se *strErrMsg* for **NULL**, **_strerror_s** retornará uma cadeia de caracteres no *buffer* que contém a mensagem de erro do sistema para a última chamada de biblioteca que produziu um erro. A cadeia de caracteres de mensagens de erro é encerrada pelo caractere newline ('\n'). Se *strErrMsg* não for igual a **NULL**, **_strerror_s** retornará uma cadeia de caracteres no *buffer* contendo (em ordem) sua mensagem de cadeia de caracteres, dois-pontos, um espaço, a mensagem de erro do sistema para a última chamada de biblioteca produzindo um erro e uma nova linha espaço. Sua mensagem da cadeia de caracteres pode ter, no máximo, 94 caracteres de comprimento.

Essas funções truncarão a mensagem de erro se seu comprimento exceder *numberOfElements* -1. A cadeia de caracteres resultante no *buffer* é sempre terminada em nulo.

O número de erro real para **_strerror_s** é armazenado na variável [errno](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md). As mensagens de erro do sistema são acessadas por meio da variável [_sys_errlist](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md), que é uma matriz de mensagens ordenadas por número do erro. o **_strerror_s** acessa a mensagem de erro apropriada usando o valor **errno** como um índice para a variável **_sys_errlist**. O valor da variável [_sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) é definido como o número máximo de elementos na matriz **_sys_errlist** . Para produzir resultados precisos, chame **_strerror_s** imediatamente após uma rotina de biblioteca retornar com um erro. Caso contrário, as chamadas subsequentes para **strerror_s** ou **_strerror_s** podem substituir o valor **errno** .

**_wcserror_s** e **__wcserror_s** são versões de caracteres largos de **strerror_s** e **_strerror_s**, respectivamente.

Essas funções validam seus parâmetros. Se o buffer for **nulo** ou se o parâmetro de tamanho for 0, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md) . Se a execução puder continuar, as funções retornarão **EINVAL** e definirá **errno** como **EINVAL**.

**_strerror_s**, **_wcserror_s**e **__wcserror_s** não fazem parte da definição de ANSI, mas em vez disso são extensões da Microsoft para ela. Não os use para onde a portabilidade for desejada; para compatibilidade com ANSI, use **strerror_s** em vez disso.

No C++, o uso dessas funções é simplificado por sobrecargas de modelo. As sobrecargas podem inferir automaticamente o tamanho do buffer, eliminando a necessidade de especificar um argumento de tamanho. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

As versões de depuração dessas funções preenchem primeiro o buffer com 0xFD. Para desabilitar esse comportamento, use [_CrtSetDebugFillThreshold](crtsetdebugfillthreshold.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tcserror_s**|**strerror_s**|**strerror_s**|**_wcserror_s**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strerror_s**, **_strerror_s**|\<string.h>|
|**_wcserror_s**, **__wcserror_s**|\<string.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [perror](perror-wperror.md).

## <a name="see-also"></a>Consulte também

[Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)<br/>
[clearerr](clearerr.md)<br/>
[ferror](ferror.md)<br/>
[perror, _wperror](perror-wperror.md)<br/>
