---
title: strerror_s, _strerror_s, _wcserror_s, __wcserror_s
ms.date: 4/2/2020
api_name:
- __wcserror_s
- _strerror_s
- _wcserror_s
- strerror_s
- _o__strerror_s
- _o__wcserror_s
- _o_strerror_s
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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: ef712ecb6236513d169b4a8836b1365b0aca0633
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81337363"
---
# <a name="strerror_s-_strerror_s-_wcserror_s-__wcserror_s"></a>strerror_s, _strerror_s, _wcserror_s, __wcserror_s

Obtenha uma mensagem de erro do sistema **(strerror_s**, **_wcserror_s)** ou imprima uma mensagem de erro fornecida pelo usuário **(_strerror_s**, **__wcserror_s**). Estas são versões de [strerror, _strerror, _wcserror, \__wcserror](strerror-strerror-wcserror-wcserror.md) com aprimoramentos de segurança, conforme descrito em [Recursos de Segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

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

*Buffer*<br/>
Buffer para conter a cadeia de caracteres de erro.

*Numberofelements*<br/>
Tamanho do buffer.

*errnum*<br/>
Número de erro.

*strErrMsg*<br/>
Mensagem fornecida pelo usuário.

## <a name="return-value"></a>Valor retornado

Zero se for bem-sucedido ou um código de erro em caso de falha.

### <a name="error-condtions"></a>Condições de erro

|*Buffer*|*Numberofelements*|*strErrMsg*|Conteúdo de *buffer*|
|--------------|------------------------|-----------------|--------------------------|
|**NULO**|any|any|n/d|
|any|0|any|não modificado|

## <a name="remarks"></a>Comentários

A **função strerror_s** *mapeia errnum* para uma seqüência de mensagens de erro, retornando a seqüência no *buffer*. **_strerror_s** não pega o número de erro; ele usa o valor atual de **errno** para determinar a mensagem apropriada. Nem **strerror_s** nem **_strerror_s** realmente imprime a mensagem: Para isso, você precisa chamar uma função de saída, como [fprintf](fprintf-fprintf-l-fwprintf-fwprintf-l.md):

```C
if (( _access( "datafile",2 )) == -1 )
{
   _strerror_s(buffer, 80);
   fprintf( stderr, buffer );
}
```

Se *strErrMsg* for **NULL**, **_strerror_s** retorna uma seqüência de *buffer* contendo a mensagem de erro do sistema para a última chamada de biblioteca que produziu um erro. A cadeia de caracteres de mensagens de erro é encerrada pelo caractere newline ('\n'). Se *strErrMsg* não for igual a **NULL,** então **_strerror_s** retorna uma seqüência de *buffer* contendo (em ordem) sua mensagem de string, um cólon, um espaço, a mensagem de erro do sistema para a última chamada da biblioteca produzindo um erro e um caractere newline. Sua mensagem da cadeia de caracteres pode ter, no máximo, 94 caracteres de comprimento.

Essas funções truncam a mensagem de erro se seu comprimento exceder *o númeroOfElements* -1. A seqüência resultante no *buffer* é sempre nula.

O número de erro real para **_strerror_s** é armazenado na variável [errno](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md). As mensagens de erro do sistema são acessadas por meio da variável [_sys_errlist](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md), que é uma matriz de mensagens ordenadas por número do erro. **_strerror_s** acessa a mensagem de erro apropriada usando o valor **errno** como índice para a variável **_sys_errlist**. O valor da variável [_sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) é definido como o número máximo de elementos na **matriz _sys_errlist.** Para produzir resultados precisos, ligue **_strerror_s** imediatamente após o retorno de uma rotina de biblioteca com um erro. Caso contrário, chamadas subseqüentes para **strerror_s** ou **_strerror_s** podem substituir o **valor errno.**

**_wcserror_s** e **__wcserror_s** são versões de grande porte de **strerror_s** e **_strerror_s,** respectivamente.

Essas funções validam seus parâmetros. Se o buffer for **NULO** ou se o parâmetro de tamanho for 0, o manipulador de parâmetros inválidos será invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md) . Se a execução for permitida, as funções retornam **eINVAL** e definem **errno** para **EINVAL**.

**_strerror_s**, **_wcserror_s**e **__wcserror_s** não fazem parte da definição ANSI, mas sim extensões da Microsoft para ele. Não os use onde a portabilidade é desejada; para compatibilidade ANSI, use **strerror_s** em vez disso.

No C++, o uso dessas funções é simplificado por sobrecargas de modelo. As sobrecargas podem inferir automaticamente o tamanho do buffer, eliminando a necessidade de especificar um argumento de tamanho. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

As versões da biblioteca de depuração dessas funções primeiro preenchem o buffer com 0xFE. Para desabilitar esse comportamento, use [_CrtSetDebugFillThreshold](crtsetdebugfillthreshold.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tcserror_s**|**strerror_s**|**strerror_s**|**_wcserror_s**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strerror_s** **_strerror_s**|\<string.h>|
|**_wcserror_s,** **__wcserror_s.**|\<string.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [perror](perror-wperror.md).

## <a name="see-also"></a>Confira também

[Manipulação de cordas](../../c-runtime-library/string-manipulation-crt.md)<br/>
[clearerr](clearerr.md)<br/>
[ferror](ferror.md)<br/>
[perror, _wperror](perror-wperror.md)<br/>
