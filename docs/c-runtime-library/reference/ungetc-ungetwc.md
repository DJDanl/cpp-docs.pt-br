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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: 484af7b72f860a8a9d12cf0b62444871caad4675
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81361292"
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

*C*<br/>
O caractere a ser enviado.

*fluxo*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="return-value"></a>Valor retornado

Se for bem-sucedida, cada uma dessas funções retorna o argumento do caractere *c*. Se *c* não puder ser empurrado para trás ou se nenhum caractere tiver sido lido, o fluxo de entrada será inalterado e **ungetc** retorna **EOF**; **ungetwc** retorna **WEOF**. Se *o fluxo* for **NULO,** o manipulador de parâmetros inválidos é invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, **o EOF** ou **o WEOF** são devolvidos e **errno** é definido **como EINVAL**.

Para obter informações sobre esses e outros códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

A função **ungetc** empurra o caractere *c* de volta para o *fluxo* e limpa o indicador de fim do arquivo. O fluxo deve estar aberto para leitura. Uma operação de leitura subseqüente no *fluxo* começa com *c*. Uma tentativa de empurrar **o EOF** para o fluxo usando **ungetc** é ignorada.

Caracteres colocados no fluxo por **ungetc** podem ser apagados se **fflush**, [fseek](fseek-fseeki64.md), **fsetpos**, ou [rebobinar](rewind.md) é chamado antes que o caractere seja lido a partir do fluxo. O indicador de posição do arquivo terá o valor que tinha antes que os caracteres foram enviados de volta. O armazenamento externo correspondente para o fluxo não é alterado. Em uma chamada **ungetc** bem-sucedida contra um fluxo de texto, o indicador de posição de arquivo não é especificado até que todos os caracteres push-back sejam lidos ou descartados. Em cada chamada **ungetc** bem sucedida contra um fluxo binário, o indicador de posição de arquivo é decretado; se seu valor foi 0 antes de uma chamada, o valor é indefinido após a chamada.

Os resultados são imprevisíveis se **ungetc** for chamado duas vezes sem uma operação de leitura ou posicionamento de arquivo entre as duas chamadas. Após uma chamada para **fscanf**, uma chamada para **ungetc** pode falhar a menos que outra operação de leitura (como **getc**) tenha sido realizada. Isso porque o próprio **fscanf** chama **ungetc**.

**ungetwc** é uma versão de amplo caráter de **ungetc**. No entanto, em cada chamada **de ungetwc** bem sucedida contra um texto ou fluxo binário, o valor do indicador de posição de arquivo não é especificado até que todos os caracteres push-back sejam lidos ou descartados.

Essas funções são thread-safe e bloqueiam dados confidenciais durante a execução. Para ver uma versão sem bloqueio, consulte [_ungetc_nolock, _ungetwc_nolock](ungetc-nolock-ungetwc-nolock.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_ungettc**|**ungetc**|**ungetc**|**ungetwc**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**ungetc**|\<stdio.h>|
|**ungetwc**|\<stdio.h> ou \<wchar.h>|

O console não é suportado em aplicativos Universal Windows Platform (UWP). As alças de fluxo padrão associadas ao console, **stdin**, **stdout**e **stderr,** devem ser redirecionadas antes que as funções de tempo de execução C possam usá-las em aplicativos UWP. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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
