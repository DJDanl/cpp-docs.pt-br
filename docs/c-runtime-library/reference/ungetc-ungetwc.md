---
title: ungetc, ungetwc
ms.date: 4/2/2020
api_name:
- ungetwc
- ungetc
- _o_ungetc
- _o_ungetwc
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
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _ungettc
- ungetwc
- ungetc
helpviewer_keywords:
- ungetwc function
- ungettc function
- characters, pushing back onto stream
- _ungettc function
- ungetc function
ms.assetid: e0754f3a-b4c6-408f-90c7-e6387b830d84
ms.openlocfilehash: 406ce7d8befd1d9e9e6a065f2549bacf46d2fd6e
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82915977"
---
# <a name="ungetc-ungetwc"></a>ungetc, ungetwc

Envia um caractere de volta para o fluxo.

## <a name="syntax"></a>Sintaxe

```C
int ungetc(
   int c,
   FILE *stream
);
wint_t ungetwc(
   wint_t c,
   FILE *stream
);
```

### <a name="parameters"></a>Parâmetros

*&*<br/>
O caractere a ser enviado.

*fluxo*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="return-value"></a>Valor retornado

Se for bem-sucedida, cada uma dessas funções retornará o argumento de caractere *c*. Se *c* não puder ser enviado de volta ou se nenhum caractere tiver sido lido, o fluxo de entrada será inalterado e **ungetc** retornará **EOF**; **ungetwc** retorna **WEOF**. Se o *fluxo* for **nulo**, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **EOF** ou **WEOF** será retornado e **errno** será definido como **EINVAL**.

Para obter informações sobre esses e outros códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

A função **ungetc** envia o caractere *c* de volta para o *fluxo* e limpa o indicador de fim de arquivo. O fluxo deve estar aberto para leitura. Uma operação de leitura subsequente no *fluxo* começa com *c*. Uma tentativa de enviar **EOF** para o fluxo usando **ungetc** é ignorada.

Os caracteres colocados no fluxo por **ungetc** poderão ser apagados se **fflush**, [fseek](fseek-fseeki64.md), **fsetpos**ou [retrocesso](rewind.md) for chamado antes de o caractere ser lido do fluxo. O indicador de posição do arquivo terá o valor que tinha antes que os caracteres foram enviados de volta. O armazenamento externo correspondente para o fluxo não é alterado. Em uma chamada **ungetc** bem-sucedida em relação a um fluxo de texto, o indicador de posição de arquivo não é especificado até que todos os caracteres enviados por push sejam lidos ou descartados. Em cada chamada de **ungetc** bem-sucedida em relação a um fluxo binário, o indicador de posição de arquivo é decrementado; Se seu valor era 0 antes de uma chamada, o valor é indefinido após a chamada.

Os resultados serão imprevisíveis se **ungetc** for chamado duas vezes sem uma operação de leitura ou de posicionamento de arquivo entre as duas chamadas. Após uma chamada para **fscanf**, uma chamada para **ungetc** pode falhar, a menos que outra operação de leitura (como **getc**) tenha sido executada. Isso ocorre porque o próprio **fscanf** chama **ungetc**.

**ungetwc** é uma versão de caractere largo do **ungetc**. No entanto, em cada chamada **ungetwc** bem-sucedida em um fluxo de texto ou binário, o valor do indicador de posição de arquivo não é especificado até que todos os caracteres enviados por push sejam lidos ou descartados.

Essas funções são thread-safe e bloqueiam dados confidenciais durante a execução. Para ver uma versão sem bloqueio, consulte [_ungetc_nolock, _ungetwc_nolock](ungetc-nolock-ungetwc-nolock.md).

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_ungettc**|**ungetc**|**ungetc**|**ungetwc**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**ungetc**|\<stdio.h>|
|**ungetwc**|\<stdio.h> ou \<wchar.h>|

Não há suporte para o console em aplicativos Plataforma Universal do Windows (UWP). Os identificadores de fluxo padrão associados ao console, **stdin**, **stdout**e **stderr**devem ser redirecionados antes que as funções de tempo de execução do C possam usá-los em aplicativos UWP. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_ungetc.c
// This program first converts a character
// representation of an unsigned integer to an integer. If
// the program encounters a character that is not a digit,
// the program uses ungetc to replace it in the  stream.
//

#include <stdio.h>
#include <ctype.h>

int main( void )
{
   int ch;
   int result = 0;

   // Read in and convert number:
   while( ((ch = getchar()) != EOF) && isdigit( ch ) )
      result = result * 10 + ch - '0';    // Use digit.
   if( ch != EOF )
      ungetc( ch, stdin );                // Put nondigit back.
   printf( "Number = %d\nNext character in stream = '%c'",
            result, getchar() );
}
```

```Output

      521aNumber = 521
Next character in stream = 'a'
```

## <a name="see-also"></a>Confira também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[getc, getwc](getc-getwc.md)<br/>
[putc, putwc](putc-putwc.md)<br/>
