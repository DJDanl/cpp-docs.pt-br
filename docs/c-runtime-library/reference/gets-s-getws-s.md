---
title: gets_s, _getws_s | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _getws_s
- gets_s
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
- _getws_s
- gets_s
dev_langs:
- C++
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
caps.latest.revision: 29
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: efd4e458fa71fd6dcd93d47350c998a4a410cc65
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="getss-getwss"></a>gets_s, _getws_s

Obtém uma linha do **stdin** fluxo. Estas versões de [gets, _getws](../../c-runtime-library/gets-getws.md) têm melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

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

Retorna *buffer* se for bem-sucedido. Um **nulo** ponteiro indica uma condição de erro ou o final do arquivo. Use [ferror](ferror.md) ou [feof](feof.md) para determinar qual das condições ocorreu.

## <a name="remarks"></a>Comentários

O **gets_s** função lê uma linha do fluxo de entrada padrão **stdin** e armazena em *buffer*. A linha consiste em todos os caracteres até e incluindo o primeiro caractere de nova linha ('\n'). **gets_s** substitui o caractere de nova linha com um caractere nulo ('\0') antes de retornar a linha. Em contraste, o **fgets_s** função retém o caractere de nova linha.

Se o primeiro caractere de leitura é o caractere de final de arquivo, um caractere null será armazenado no início do *buffer* e **nulo** é retornado.

**getws_s** é uma versão de caractere largo de **gets_s**; o argumento e o valor de retorno são cadeias de caracteres do caractere largo.

Se *buffer* é **nulo** ou *sizeInCharacters* é menor ou igual a zero ou se o buffer é muito pequeno para conter a linha de entrada e o terminador nulo, chamar essas funções um manipulador de parâmetro inválido, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, essas funções retornam **nulo** e defina errno como **ERANGE**.

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

Não há suporte para o console em aplicativos do Windows UWP (plataforma Universal). Os identificadores de fluxo padrão que estão associados com o console, **stdin**, **stdout**, e **stderr**, deverá ser redirecionado para funções de tempo de execução C podem usá-los em aplicativos UWP . Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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
