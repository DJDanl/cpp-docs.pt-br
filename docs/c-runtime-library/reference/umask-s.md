---
title: _umask_s
ms.date: 4/2/2020
api_name:
- _umask_s
- _o__umask_s
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
- api-ms-win-crt-filesystem-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
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
ms.openlocfilehash: d590910d5f5092a78ad64c8f9ef0aa259211e226
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81362172"
---
# <a name="_umask_s"></a>_umask_s

Define a máscara de permissão de arquivo padrão. Uma versão de [_unmask](umask.md) com melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t _umask_s(
   int mode,
   int * pOldMode
);
```

### <a name="parameters"></a>Parâmetros

*Modo*<br/>
Configuração de permissão padrão.

*pOldMode*<br/>
O valor anterior da configuração de permissão.

## <a name="return-value"></a>Valor retornado

Retorna um código de erro se o *modo* não especificar um modo válido ou o ponteiro *pOldMode* for **NULL**.

### <a name="error-conditions"></a>Condições de erro

|*Modo*|*pOldMode*|Valor retornado|Conteúdo do *pOldMode*|
|------------|----------------|----------------------|--------------------------------|
|any|**NULO**|**Einval**|não modificado|
|modo inválido|any|**Einval**|não modificado|

Se uma das condições de erro acima ocorrer, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução continuar, **_umask_s** **retorna eINVAL** e define **errno** para **EINVAL**.

## <a name="remarks"></a>Comentários

A função **_umask_s** define a máscara de permissão de arquivo do processo atual para o modo especificado pelo *modo*. A máscara de permissão de arquivo modifica a configuração de permissão de novos arquivos criados por **_creat,** **_open**ou **_sopen**. Se um bit na máscara for 1, o bit correspondente no valor da permissão solicitada do arquivo será definido como 0 (não permitido). Se um bit na máscara for 0, o bit correspondente será deixado inalterado. A configuração de permissão para um novo arquivo não é definida até que o arquivo é seja fechado pela primeira vez.

O *pmode* de expressão inteiro contém uma ou ambas as seguintes constantes de manifesto, definidas em SYS\STAT. H:

|*Pmode*||
|-|-|
|**_S_IWRITE**|Gravação permitida.|
|**_S_IREAD**|Leitura permitida.|
|**_S_IREAD** \| **_S_IWRITE _S_IREAD**|Leitura e gravação permitidas.|

Quando ambas as constantes são dadas, elas são **|** unidas com o operador bitwise-OR ( ). Se o argumento do *modo* **for _S_IREAD,** a leitura não será permitida (o arquivo é somente gravação). Se o argumento do *modo* **for _S_IWRITE,** a escrita não é permitida (o arquivo é somente leitura). Por exemplo, se o bit de gravação estiver definido na máscara, quaisquer novos arquivos serão somente leitura. Observe que nos sistemas operacionais MS-DOS e Windows, todos os arquivos podem ser lidos; não é possível conceder permissão somente gravação. Portanto, definir a broca de leitura com **_umask_s** não tem efeito nos modos do arquivo.

Se *o pmode* não for uma combinação de uma das constantes manifestas ou incorporar um conjunto alternativo de constantes, a função simplesmente ignorará essas.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_umask_s**|\<io.h> e \<sys/stat.h> e \<sys/types.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Confira também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[E/S de nível inferior](../../c-runtime-library/low-level-i-o.md)<br/>
[_chmod, _wchmod](chmod-wchmod.md)<br/>
[_creat, _wcreat](creat-wcreat.md)<br/>
[_mkdir, _wmkdir](mkdir-wmkdir.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
[_umask](umask.md)<br/>
