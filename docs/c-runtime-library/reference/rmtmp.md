---
title: _rmtmp
ms.date: 11/04/2016
apiname:
- _rmtmp
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
- rmtmp
- _rmtmp
helpviewer_keywords:
- removing temporary files
- _rmtmp function
- files [C++], temporary
- rmtmp function
- files [C++], removing
- temporary files [C++], removing
ms.assetid: 7419501e-2587-4f2a-b469-0dca07f84736
ms.openlocfilehash: bf4f2cff48e8660682fc8a00d10d9a1fe960a6a7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62357415"
---
# <a name="rmtmp"></a>_rmtmp

Exclui arquivos temporários.

## <a name="syntax"></a>Sintaxe

```C

int _rmtmp( void );
```

## <a name="return-value"></a>Valor de retorno

**rmtmp** retorna o número de arquivos temporários fechados e excluídos.

## <a name="remarks"></a>Comentários

O **rmtmp** função limpa todos os arquivos temporários no diretório atual. A função remove somente os arquivos criados pela **tmpfile**; usá-lo somente no mesmo diretório em que os arquivos temporários foram criados.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_rmtmp**|\<stdio.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

Veja o exemplo a seguir para [tmpfile](tmpfile.md).

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[_flushall](flushall.md)<br/>
[tmpfile](tmpfile.md)<br/>
[_tempnam, _wtempnam, tmpnam, _wtmpnam](tempnam-wtempnam-tmpnam-wtmpnam.md)<br/>
