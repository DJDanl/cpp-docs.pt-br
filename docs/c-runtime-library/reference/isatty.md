---
title: _isatty
ms.date: 4/2/2020
api_name:
- _isatty
- _o__isatty
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
- _isatty
helpviewer_keywords:
- isatty function
- character device checking
- _isatty function
- checking character devices
ms.assetid: 9f1b2e87-0cd7-4079-b187-f2b7ca15fcbe
ms.openlocfilehash: c9611c2bd55ebc1602a73e4c71518716ea100420
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81343896"
---
# <a name="_isatty"></a>_isatty

Determina se um descritor de arquivo está associado a um dispositivo de caracteres.

## <a name="syntax"></a>Sintaxe

```C
int _isatty( int fd );
```

### <a name="parameters"></a>Parâmetros

*Fd*<br/>
Descritor de arquivo que se refere ao dispositivo a ser testado.

## <a name="return-value"></a>Valor retornado

**_isatty** retorna um valor não zero se o descritor estiver associado a um dispositivo de caractere. Caso contrário, **_isatty** retorna 0.

## <a name="remarks"></a>Comentários

A função **_isatty** determina se *fd* está associado a um dispositivo de caractere (um terminal, console, impressora ou porta serial).

Esta função valida o parâmetro *fd.* Se *fd* for um ponteiro de arquivo ruim, o manipulador de parâmetros inválidos é invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução continuar, a função retorna 0 e define **errno** para **EBADF**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_isatty**|\<io.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Bibliotecas

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

```C
// crt_isatty.c
/* This program checks to see whether
* stdout has been redirected to a file.
*/

#include <stdio.h>
#include <io.h>

int main( void )
{
   if( _isatty( _fileno( stdout ) ) )
      printf( "stdout has not been redirected to a file\n" );
   else
      printf( "stdout has been redirected to a file\n");
}
```

### <a name="sample-output"></a>Saída de exemplo

```Output
stdout has not been redirected to a file
```

## <a name="see-also"></a>Confira também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
