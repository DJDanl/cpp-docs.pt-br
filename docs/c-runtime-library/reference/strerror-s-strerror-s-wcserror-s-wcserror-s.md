---
title: strerror_s, _strerror_s, _wcserror_s, __wcserror_s
ms.date: 11/04/2016
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
ms.openlocfilehash: 00ff9d0df1a78d07eaa509201fb998b30396cc4c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62353814"
---
# <a name="strerrors-strerrors-wcserrors-wcserrors"></a>strerror_s, _strerror_s, _wcserror_s, __wcserror_s

Receber uma mensagem de erro do sistema (**strerror_s**, **wcserror_s**) ou imprimir uma mensagem de erro fornecida pelo usuário (**strerror_s**, **wcserror_s** ). Estas são versões de [strerror, _strerror, _wcserror, \__wcserror](strerror-strerror-wcserror-wcserror.md) com aprimoramentos de segurança, conforme descrito em [Recursos de Segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

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

|*buffer*|*numberOfElements*|*strErrMsg*|Conteúdo de *buffer*|
|--------------|------------------------|-----------------|--------------------------|
|**NULL**|qualquer|qualquer|N/D|
|qualquer|0|qualquer|não modificado|

## <a name="remarks"></a>Comentários

O **strerror_s** função mapas *errnum* para uma cadeia de caracteres de mensagem de erro, retornando a cadeia de caracteres no *buffer*. **strerror_s** não tem o número de erro; ele usa o valor atual da **errno** para determinar a mensagem apropriada. Nem **strerror_s** nem **strerror_s** imprimem a mensagem: Para fazer isso, você precisa chamar uma função de saída, como [fprintf](fprintf-fprintf-l-fwprintf-fwprintf-l.md):

```C
if (( _access( "datafile",2 )) == -1 )
{
   _strerror_s(buffer, 80);
   fprintf( stderr, buffer );
}
```

Se *strErrMsg* é **nulo**, **strerror_s** retorna uma cadeia de caracteres *buffer* que contém a mensagem de erro do sistema para a última chamada da biblioteca que produziu um erro. A cadeia de caracteres de mensagens de erro é encerrada pelo caractere newline ('\n'). Se *strErrMsg* não é igual a **nulo**, em seguida, **strerror_s** retorna uma cadeia de caracteres *buffer* contendo (nessa ordem) sua mensagem de cadeia de caracteres, um dois-pontos, um espaço, a mensagem de erro do sistema para a última chamada da biblioteca produzir um erro e um caractere de nova linha. Sua mensagem da cadeia de caracteres pode ter, no máximo, 94 caracteres de comprimento.

Essas funções truncarão a mensagem de erro se seu comprimento exceder *numberOfElements* -1. A cadeia de caracteres resultante no *buffer* é sempre terminada em nulo.

O número do erro real para **strerror_s** é armazenado na variável [errno](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md). As mensagens de erro do sistema são acessadas por meio da variável [_sys_errlist](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md), que é uma matriz de mensagens ordenadas por número do erro. **strerror_s** acessa a mensagem de erro apropriada usando o **errno** valor como um índice para a variável **sys_errlist**. O valor da variável [sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) é definido como o número máximo de elementos na **sys_errlist** matriz. Para produzir resultados precisos, chame **strerror_s** imediatamente após uma rotina da biblioteca retorna um erro. Caso contrário, chamadas subsequentes para **strerror_s** ou **strerror_s** pode substituir o **errno** valor.

**wcserror_s** e **wcserror_s** são versões de caractere largo de **strerror_s** e **strerror_s**, respectivamente.

Essas funções validam seus parâmetros. Se o buffer for **nulo** ou se o parâmetro de tamanho é 0, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md) . Se a execução puder continuar, as funções retornam **EINVAL** e defina **errno** para **EINVAL**.

**strerror_s**, **wcserror_s**, e **wcserror_s** não fazem parte da definição de ANSI, mas em vez disso, são extensões da Microsoft. Não usá-los quando se desejar portabilidade; para compatibilidade ANSI, use **strerror_s** em vez disso.

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
