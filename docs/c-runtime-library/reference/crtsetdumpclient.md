---
title: _CrtSetDumpClient
ms.date: 11/04/2016
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
helpviewer_keywords:
- _CrtSetDumpClient function
- CrtSetDumpClient function
ms.assetid: f3dd06d0-c331-4a12-b68d-25378d112033
ms.openlocfilehash: 09f319f6298dbec6b229b2923bd86fc9b50314de
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64342989"
---
# <a name="crtsetdumpclient"></a>_CrtSetDumpClient

Instala uma função definida pelo aplicativo para despejar **client_block** blocos de memória (somente versão de depuração) do tipo.

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

O **crtsetdumpclient** função permite que o aplicativo vincule sua própria função para despejar objetos armazenados no **client_block** processo de despejo de memória de depuração de blocos de memória em tempo de execução do C. Como resultado, sempre que uma depuração função de despejo, como [crtmemdumpallobjectssince](crtmemdumpallobjectssince.md) ou [crtdumpmemoryleaks](crtdumpmemoryleaks.md) Despeja um **client_block** bloco de memória, o aplicativo função de despejo é chamada também. **Crtsetdumpclient** fornece um aplicativo com um método fácil para detectar vazamentos de memória e para validação ou relatório do conteúdo dos dados armazenados no **client_block** blocos. Quando [Debug](../../c-runtime-library/debug.md) não está definido, as chamadas a **crtsetdumpclient** são removidas durante o pré-processamento.

O **crtsetdumpclient** função instala a nova função de despejo definida pelo aplicativo especificada em *dumpClient* e retorna a função de despejo definida anteriormente. Este é um exemplo de uma função de despejo de bloco do cliente:

```C
void DumpClientFunction( void *userPortion, size_t blockSize );
```

O *userPortion* argumento é um ponteiro para o início da parte de dados do usuário do bloco de memória e *blockSize* Especifica o tamanho da memória alocada bloco em bytes. A função de despejo de bloco de cliente deve retornar **void**. O ponteiro para a função de despejo do cliente que é passado para **crtsetdumpclient** é do tipo **crt_dump_client**, conforme definido em crtdbg. h:

```C
typedef void (__cdecl *_CRT_DUMP_CLIENT)( void *, size_t );
```

Para obter mais informações sobre as funções que operam em **client_block** blocos de memória do tipo, consulte [funções de gancho de bloco de cliente](/visualstudio/debugger/client-block-hook-functions). A função [_CrtReportBlockType](crtreportblocktype.md) pode ser usada para retornar informações sobre tipos e subtipos de bloco.

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
