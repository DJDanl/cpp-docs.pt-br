---
title: gets, _getws
ms.date: 4/2/2020
api_name:
- _getws
- gets
- _o__getws
- _o_gets
api_location:
- msvcr80.dll
- msvcr90.dll
- msvcr120.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcrt.dll
- msvcr100.dll
- api-ms-win-crt-stdio-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _getts
- gets
- _getws
helpviewer_keywords:
- getws function
- getts function
- _getws function
- lines, getting
- streams, getting lines
- _getts function
- gets function
- standard input, reading from
ms.assetid: 1ec2dd4b-f801-48ea-97c2-892590f16024
ms.openlocfilehash: 1c60cf14334a0dcc0492b23da10a36c3219bb699
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82919909"
---
# <a name="gets-_getws"></a>gets, _getws

Obtém uma linha do fluxo `stdin`. Estão disponíveis versões mais seguras dessas funções; consulte [gets_s, _getws_s](../c-runtime-library/reference/gets-s-getws-s.md).

> [!IMPORTANT]
> Essas funções estão obsoletas. A partir do Visual Studio 2015, elas não estão disponíveis no CRT. As versões seguras dessas funções, gets_s e _getws_s, ainda estão disponíveis. Para obter informações sobre essas funções alternativas, consulte [gets_s, _getws_s](../c-runtime-library/reference/gets-s-getws-s.md).

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```
char *gets(
   char *buffer
);
wchar_t *_getws(
   wchar_t *buffer
);
template <size_t size>
char *gets(
   char (&buffer)[size]
); // C++ only
template <size_t size>
wchar_t *_getws(
   wchar_t (&buffer)[size]
); // C++ only
```

#### <a name="parameters"></a>Parâmetros

*completo*<br/>
Local de armazenamento para a cadeia de caracteres de entrada.

## <a name="return-value"></a>Valor retornado

Retorna o argumento se for bem-sucedido. Um ponteiro **NULL** indica uma condição de erro ou de fim do arquivo. Use [ferror](../c-runtime-library/reference/ferror.md) ou [feof](../c-runtime-library/reference/feof.md) para determinar qual das condições ocorreu. Se `buffer` for **NULL**, essas funções invocarão o manipulador de um parâmetro inválido, conforme descrito em [Validação de parâmetro](../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão **NULL** e definirão errno como `EINVAL`.

## <a name="remarks"></a>Comentários

A função `gets` lê uma linha do fluxo de entrada padrão `stdin` e a armazena em `buffer`. A linha consiste em todos os caracteres até e incluindo o primeiro caractere de nova linha ('\n'). `gets`, então, substitui o caractere de nova linha por um caractere nulo ('\0') antes de retornar a linha. Por sua vez, a função `fgets` retém o caractere de nova linha. `_getws` é uma versão de caractere largo de `gets`; seu argumento e o valor retornado são cadeias de caracteres largos.

> [!IMPORTANT]
> Como não há uma maneira de limitar o número de caracteres lidos por gets, entradas não confiáveis podem facilmente causar estouros de buffer. Use `fgets` em vez disso.

No C++, essas funções têm sobrecargas de modelo que invocam os equivalentes mais novos e seguros dessas funções. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../c-runtime-library/secure-template-overloads.md).

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|`_getts`|`gets`|`gets`|`_getws`|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|`gets`|\<stdio.h>|
|`_getws`|\<stdio.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```c
// crt_gets.c
// compile with: /WX /W3

#include <stdio.h>

int main( void )
{
   char line[21]; // room for 20 chars + '\0'
   gets( line );  // C4996
   // Danger: No way to limit input to 20 chars.
   // Consider using gets_s instead.
   printf( "The line entered was: %s\n", line );
}
```

Observe que uma entrada com mais de 20 caracteres saturará o buffer de linha e provavelmente fará com que o programa falhe.

```Output

Hello there!The line entered was: Hello there!
```

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../c-runtime-library/stream-i-o.md)<br/>
[fgets, fgetws](../c-runtime-library/reference/fgets-fgetws.md)<br/>
[fputs, fputws](../c-runtime-library/reference/fputs-fputws.md)<br/>
[puts, _putws](../c-runtime-library/reference/puts-putws.md)
