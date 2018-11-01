---
title: _umask_s
ms.date: 11/04/2016
apiname:
- _umask_s
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
- api-ms-win-crt-filesystem-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- unmask_s
- _umask_s
helpviewer_keywords:
- masks, file-permission-setting
- _umask_s function
- masks
- file permissions [C++]
- umask_s function
- files [C++], permission settings for
ms.assetid: 70898f61-bf2b-4d8d-8291-0ccaa6d33145
ms.openlocfilehash: 878a22cb2884c36e792ff8dead1453582addb5b4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50480660"
---
# <a name="umasks"></a>_umask_s

Define a máscara de permissão de arquivo padrão. Uma versão de [_unmask](umask.md) com melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t _umask_s(
   int mode,
   int * pOldMode
);
```

### <a name="parameters"></a>Parâmetros

*modo*<br/>
Configuração de permissão padrão.

*pOldMode*<br/>
O valor anterior da configuração de permissão.

## <a name="return-value"></a>Valor de retorno

Retorna um código de erro se *modo* não especifica um modo válido ou o *pOldMode* ponteiro for **nulo**.

### <a name="error-conditions"></a>Condições de Erro

|*modo*|*pOldMode*|Valor retornado|Conteúdo de *pOldMode*|
|------------|----------------|----------------------|--------------------------------|
|qualquer|**NULL**|**EINVAL**|não modificado|
|modo inválido|qualquer|**EINVAL**|não modificado|

Se uma das condições de erro acima ocorrer, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **umask_s** retorna **EINVAL** e define **errno** para **EINVAL**.

## <a name="remarks"></a>Comentários

O **umask_s** função define a máscara de permissão de arquivo do processo atual para o modo especificado por *modo*. A máscara de permissão de arquivo modifica a configuração de permissão de novos arquivos criados pela **Creat**, **Open**, ou **sopen**. Se um bit na máscara for 1, o bit correspondente no valor da permissão solicitada do arquivo será definido como 0 (não permitido). Se um bit na máscara for 0, o bit correspondente será deixado inalterado. A configuração de permissão para um novo arquivo não é definida até que o arquivo é seja fechado pela primeira vez.

A expressão de inteiro *pmode* contém uma ou ambas das seguintes constantes de manifesto, definidas em SYS\STAT. H:

|*pmode*||
|-|-|
|**S_IWRITE**|Gravação permitida.|
|**S_IREAD**|Leitura permitida.|
|**S_IREAD** \| **S_IWRITE**|Leitura e gravação permitidas.|

Quando as duas constantes são informadas, elas são unidas com o operador OR bit a bit ( **|** ). Se o *modo* argumento é **s_iread**, leitura não será permitida (o arquivo é somente gravação). Se o *modo* argumento é **s_iwrite**, gravação não é permitida (o arquivo é somente leitura). Por exemplo, se o bit de gravação estiver definido na máscara, quaisquer novos arquivos serão somente leitura. Observe que nos sistemas operacionais MS-DOS e Windows, todos os arquivos podem ser lidos; não é possível conceder permissão somente gravação. Portanto, definir a bit de leitura **umask_s** não tem nenhum efeito sobre os modos do arquivo.

Se *pmode* não é uma combinação de uma das constantes de manifesto nem incorporar um conjunto alternativo de constantes, a função simplesmente irá ignorar os.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_umask_s**|\<io.h> e \<sys/stat.h> e \<sys/types.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_umask_s.c
/* This program uses _umask_s to set
* the file-permission mask so that all future
* files will be created as read-only files.
* It also displays the old mask.
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <io.h>
#include <stdio.h>

int main( void )
{
   int oldmask, err;

   /* Create read-only files: */
   err = _umask_s( _S_IWRITE, &oldmask );
   if (err)
   {
      printf("Error setting the umask.\n");
      exit(1);
   }
   printf( "Oldmask = 0x%.4x\n", oldmask );
}
```

```Output
Oldmask = 0x0000
```

## <a name="see-also"></a>Consulte também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[E/S de nível inferior](../../c-runtime-library/low-level-i-o.md)<br/>
[_chmod, _wchmod](chmod-wchmod.md)<br/>
[_creat, _wcreat](creat-wcreat.md)<br/>
[_mkdir, _wmkdir](mkdir-wmkdir.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
[_umask](umask.md)<br/>
