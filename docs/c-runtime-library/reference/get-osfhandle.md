---
title: _get_osfhandle
ms.date: 4/2/2020
api_name:
- _get_osfhandle
- _o__get_osfhandle
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
- get_osfhandle
- _get_osfhandle
helpviewer_keywords:
- operating systems, getting file handles
- get_osfhandle function
- _get_osfhandle function
- file handles [C++], operating system
ms.assetid: 0bdd728a-4fd8-410b-8c9f-01a121135196
ms.openlocfilehash: a12c0c93ae15350a4b91a8aa905acb941f8b6a10
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81345039"
---
# <a name="_get_osfhandle"></a>_get_osfhandle

Recupera o identificador de arquivo do sistema operacional associado ao descritor do arquivo especificado.

## <a name="syntax"></a>Sintaxe

```C
intptr_t _get_osfhandle(
   int fd
);
```

### <a name="parameters"></a>Parâmetros

*Fd*<br/>
Um descritor de arquivo existente.

## <a name="return-value"></a>Valor retornado

Retorna uma alça de arquivo do sistema operacional se *fd* for válido. Caso contrário, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução continuar, ela retorna **INVALID_HANDLE_VALUE** (-1). Ele também define **errno** para **EBADF,** indicando uma alça de arquivo inválida. Para evitar um aviso quando o resultado for usado como uma alça de arquivo Win32, lance-o para um tipo **handle.**

> [!NOTE]
> Quando **stdin**, **stdout**e **stderr** não estão associados a um fluxo (por exemplo, em um aplicativo windows sem uma janela de console), os valores do descritor de arquivo para esses fluxos são devolvidos de [_fileno](fileno.md) como o valor especial -2. Da mesma forma, se você usar um 0, 1 ou 2 como parâmetro do descritor de arquivo em vez do resultado de uma chamada para **_fileno,** **_get_osfhandle** também retorna o valor especial -2 quando o descritor de arquivo não está associado a um fluxo, e não define **errno**. No entanto, este não é um valor de manipulação de arquivo válido, e chamadas subseqüentes que tentam usá-lo provavelmente falharão.

Para obter mais informações sobre **ebadf** e outros códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

Para fechar um arquivo cujo cabo de arquivo do sistema operacional (OS) é obtido por **_get_osfhandle,** chame [_close](close.md) no descritor de arquivo *fd*. Nunca ligue para **closehandle** no valor de retorno desta função. O cabo de arquivo do Sistema Operacional subjacente é de propriedade do descritor de arquivo *fd,* e é fechado quando [_close](close.md) é chamado em *fd*. Se o descritor de arquivo `FILE *` for de propriedade de `FILE *` um fluxo, então chamar [fclose](fclose-fcloseall.md) nesse fluxo fechará tanto o descritor de arquivo quanto o punho de arquivo do SISTEMA OPERACIONAL subjacente. Neste caso, não ligue [para _close](close.md) no descritor do arquivo.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_get_osfhandle**|\<io.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[_close](close.md)<br/>
[_creat, _wcreat](creat-wcreat.md)<br/>
[_dup, _dup2](dup-dup2.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
[\_open_osfhandle](open-osfhandle.md)
