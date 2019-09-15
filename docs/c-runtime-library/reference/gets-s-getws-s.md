---
title: gets_s, _getws_s
ms.date: 11/04/2016
api_name:
- _getws_s
- gets_s
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
- api-ms-win-crt-stdio-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _getws_s
- gets_s
helpviewer_keywords:
- getws_s function
- _getws_s function
- lines, getting
- streams, getting lines
- buffers, avoiding overruns
- buffer overruns
- buffers, buffer overruns
- gets_s function
- standard input, reading from
ms.assetid: 5880c36f-122c-4061-a1a5-aeeced6fe58c
ms.openlocfilehash: f282b4e8de12185a19e07374cf565788dc549136
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70954966"
---
# <a name="gets_s-_getws_s"></a>gets_s, _getws_s

Obtém uma linha do fluxo **stdin** . Estas versões de [gets, _getws](../../c-runtime-library/gets-getws.md) têm melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
char *gets_s(
   char *buffer,
   size_t sizeInCharacters
);
wchar_t *_getws_s(
   wchar_t *buffer,
   size_t sizeInCharacters
);
```

```cpp
template <size_t size>
char *gets_s( char (&buffer)[size] ); // C++ only

template <size_t size>
wchar_t *_getws_s( wchar_t (&buffer)[size] ); // C++ only
```

### <a name="parameters"></a>Parâmetros

*buffer*<br/>
Local de armazenamento para a cadeia de caracteres de entrada.

*sizeInCharacters*<br/>
O tamanho do buffer.

## <a name="return-value"></a>Valor de retorno

Retorna o *buffer* se for bem-sucedido. Um ponteiro **NULL** indica uma condição de erro ou de fim do arquivo. Use [ferror](ferror.md) ou [feof](feof.md) para determinar qual das condições ocorreu.

## <a name="remarks"></a>Comentários

A função **gets_s** lê uma linha do fluxo de entrada do **stdin** padrão e a armazena no *buffer*. A linha consiste em todos os caracteres até e incluindo o primeiro caractere de nova linha ('\n'). em seguida, **gets_s** substitui o caractere de nova linha por um caractere nulo (' \ 0 ') antes de retornar a linha. Por outro lado, a função **fgets_s** retém o caractere de nova linha.

Se o primeiro caractere lido for o caractere de fim de arquivo, um caractere nulo será armazenado no início do *buffer* e o **valor nulo** será retornado.

**_getws_s** é uma versão de caractere largo do **gets_s**; seu argumento e o valor de retorno são cadeias de caracteres largos.

Se o *buffer* for **nulo** ou *sizeInCharacters* for menor ou igual a zero, ou se o buffer for muito pequeno para conter a linha de entrada e o terminador nulo, essas funções invocarão um manipulador de parâmetro inválido, conforme descrito em [parâmetro Validação](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão **NULL** e definirá errno como **ERANGE**.

Em C++, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando a necessidade de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras por suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_getts_s**|**gets_s**|**gets_s**|**_getws_s**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**gets_s**|\<stdio.h>|
|**_getws_s**|\<stdio.h> ou \<wchar.h>|

Não há suporte para o console em aplicativos Plataforma Universal do Windows (UWP). Os identificadores de fluxo padrão associados ao console, **stdin**, **stdout**e **stderr**devem ser redirecionados antes que as funções de tempo de execução do C possam usá-los em aplicativos UWP. Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_gets_s.c
// This program retrieves a string from the stdin and
// prints the same string to the console.

#include <stdio.h>

int main( void )
{
   char line[21]; // room for 20 chars + '\0'
   gets_s( line, 20 );
   printf( "The line entered was: %s\n", line );
}
```

```Input
Hello there!
```

```Output
The line entered was: Hello there!
```

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[gets, _getws](../../c-runtime-library/gets-getws.md)<br/>
[fgets, fgetws](fgets-fgetws.md)<br/>
[fputs, fputws](fputs-fputws.md)<br/>
[puts, _putws](puts-putws.md)<br/>
