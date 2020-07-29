---
title: _CrtSetDumpClient
ms.date: 11/04/2016
api_name:
- _CrtSetDumpClient
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _CrtSetDumpClient
- CrtSetDumpClient
helpviewer_keywords:
- _CrtSetDumpClient function
- CrtSetDumpClient function
ms.assetid: f3dd06d0-c331-4a12-b68d-25378d112033
ms.openlocfilehash: fd2b037ce10f708ab133f31a20636438b0d04b93
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87234257"
---
# <a name="_crtsetdumpclient"></a>_CrtSetDumpClient

Instala uma função definida pelo aplicativo para despejar os blocos de memória do tipo **_CLIENT_BLOCK** (somente versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
_CRT_DUMP_CLIENT _CrtSetDumpClient( _CRT_DUMP_CLIENT dumpClient );
```

### <a name="parameters"></a>parâmetros

*dumpClient*<br/>
Nova função de despejo de memória definida pelo cliente a ser vinculada ao processo de despejo de memória de depuração em tempo de execução C.

## <a name="return-value"></a>Valor retornado

Retorna a função de despejo de bloco do cliente definida anteriormente.

## <a name="remarks"></a>Comentários

A função **_CrtSetDumpClient** permite que o aplicativo conecte sua própria função para despejar objetos armazenados em **_CLIENT_BLOCK** blocos de memória no processo de despejo de memória de depuração de tempo de execução C. Como resultado, sempre que uma função de despejo de depuração como [_CrtMemDumpAllObjectsSince](crtmemdumpallobjectssince.md) ou [_CrtDumpMemoryLeaks](crtdumpmemoryleaks.md) despeja um bloco de memória **_CLIENT_BLOCK** , a função de despejo do aplicativo também é chamada. O **_CrtSetDumpClient** fornece um aplicativo com um método fácil para detectar vazamentos de memória e validar ou relatar o conteúdo dos dados armazenados em blocos de **_CLIENT_BLOCK** . Quando [_DEBUG](../../c-runtime-library/debug.md) não é definido, as chamadas para **_CrtSetDumpClient** são removidas durante o pré-processamento.

A função **_CrtSetDumpClient** instala a nova função de despejo definida pelo aplicativo especificada em *dumpClient* e retorna a função de despejo definida anteriormente. Este é um exemplo de uma função de despejo de bloco do cliente:

```C
void DumpClientFunction( void *userPortion, size_t blockSize );
```

O argumento *Userportation* é um ponteiro para o início da parte de dados do usuário do bloco de memória e *BlockSize* especifica o tamanho do bloco de memória alocado em bytes. A função de despejo de bloco de cliente deve retornar **`void`** . O ponteiro para a função de despejo de cliente que é transmitido para **_CrtSetDumpClient** é do tipo **_CRT_DUMP_CLIENT**, conforme definido em CRTDBG. h:

```C
typedef void (__cdecl *_CRT_DUMP_CLIENT)( void *, size_t );
```

Para obter mais informações sobre as funções que operam em blocos de memória de tipo **_CLIENT_BLOCK** , consulte [funções de gancho de bloco de cliente](/visualstudio/debugger/client-block-hook-functions). A função [_CrtReportBlockType](crtreportblocktype.md) pode ser usada para retornar informações sobre tipos e subtipos de bloco.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_CrtSetDumpClient**|\<crtdbg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Bibliotecas

Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Confira também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
[_CrtReportBlockType](crtreportblocktype.md)<br/>
[_CrtGetDumpClient](crtgetdumpclient.md)<br/>
