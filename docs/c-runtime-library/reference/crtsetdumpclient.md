---
title: _CrtSetDumpClient | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _CrtSetDumpClient
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
apitype: DLLExport
f1_keywords:
- _CrtSetDumpClient
- CrtSetDumpClient
dev_langs:
- C++
helpviewer_keywords:
- _CrtSetDumpClient function
- CrtSetDumpClient function
ms.assetid: f3dd06d0-c331-4a12-b68d-25378d112033
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8d5fecc90b4b7259f1440a0a0d86277c769c4e16
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="crtsetdumpclient"></a>_CrtSetDumpClient

Instala uma função definida pelo aplicativo para despejar **client_block** digite blocos de memória (somente versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
_CRT_DUMP_CLIENT _CrtSetDumpClient( _CRT_DUMP_CLIENT dumpClient );
```

### <a name="parameters"></a>Parâmetros

*dumpClient*<br/>
Nova função de despejo de memória definida pelo cliente a ser vinculada ao processo de despejo de memória de depuração em tempo de execução C.

## <a name="return-value"></a>Valor de retorno

Retorna a função de despejo de bloco do cliente definida anteriormente.

## <a name="remarks"></a>Comentários

O **crtsetdumpclient** função permite que o aplicativo conectar-se com sua própria função para despejo objetos armazenados no **client_block** blocos de memória em tempo de execução do C depurar o processo de despejo de memória. Como resultado, sempre que uma depuração despejo função como [crtmemdumpallobjectssince](crtmemdumpallobjectssince.md) ou [crtdumpmemoryleaks](crtdumpmemoryleaks.md) Despeja um **client_block** bloco de memória, o aplicativo função de despejo de memória é chamada também. **Crtsetdumpclient** fornece um aplicativo com um método fácil para detecção de vazamentos de memória e validar ou relatar o conteúdo dos dados armazenados no **client_block** blocos. Quando [Debug](../../c-runtime-library/debug.md) não está definido, chamadas para **crtsetdumpclient** são removidos durante o pré-processamento.

O **crtsetdumpclient** função instala a nova função de despejo de memória definido pelo aplicativo especificada em *dumpClient* e retorna a função de despejo definido anteriormente. Este é um exemplo de uma função de despejo de bloco do cliente:

```C
void DumpClientFunction( void *userPortion, size_t blockSize );
```

O *userPortion* argumento é um ponteiro para o início da porção de dados de usuário do bloco de memória e *blockSize* Especifica o tamanho da memória alocada bloco em bytes. A função de despejo de bloco do cliente deve retornar **void**. O ponteiro para a função de despejo do cliente que é passado para **crtsetdumpclient** é do tipo **crt_dump_client**, conforme definido em crtdbg. h:

```C
typedef void (__cdecl *_CRT_DUMP_CLIENT)( void *, size_t );
```

Para obter mais informações sobre as funções que operam em **client_block** blocos de memória de tipo, consulte [funções de gancho do bloco de cliente](/visualstudio/debugger/client-block-hook-functions). A função [_CrtReportBlockType](crtreportblocktype.md) pode ser usada para retornar informações sobre tipos e subtipos de bloco.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_CrtSetDumpClient**|\<crtdbg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
[_CrtReportBlockType](crtreportblocktype.md)<br/>
[_CrtGetDumpClient](crtgetdumpclient.md)<br/>
