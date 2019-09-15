---
title: _CrtMemDumpAllObjectsSince
ms.date: 11/04/2016
api_name:
- _CrtMemDumpAllObjectsSince
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
- CrtMemDumpAllObjectsSince
- _CrtMemDumpAllObjectsSince
helpviewer_keywords:
- _CrtMemDumpAllObjectsSince function
- CrtMemDumpAllObjectsSince function
ms.assetid: c48a447a-e6bb-475c-9271-a3021182a0dc
ms.openlocfilehash: 9e3793e9b88c593968b108e2801e24476417603c
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70942378"
---
# <a name="_crtmemdumpallobjectssince"></a>_CrtMemDumpAllObjectsSince

Despeja informações sobre objetos no heap a partir do início da execução do programa ou de um estado de heap especificado (somente versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
void _CrtMemDumpAllObjectsSince(
   const _CrtMemState *state
);
```

### <a name="parameters"></a>Parâmetros

*state*<br/>
Ponteiro para o estado de heap do qual o despejo será iniciado ou **NULL**.

## <a name="remarks"></a>Comentários

A função **_CrtMemDumpAllObjectsSince** despeja as informações de cabeçalho de depuração de objetos alocados no heap em um formulário legível pelo usuário. As informações de despejo podem ser usadas pelo aplicativo para acompanhar as alocações e detectar problemas de memória. Quando [_DEBUG](../../c-runtime-library/debug.md) não é definido, as chamadas para **_CrtMemDumpAllObjectsSince** são removidas durante o pré-processamento.

**_CrtMemDumpAllObjectsSince** usa o valor do parâmetro *State* para determinar onde iniciar a operação de despejo. Para começar a despejar de um estado de heap especificado, o parâmetro *State* deve ser um ponteiro para uma estrutura **_CrtMemState** que tenha sido preenchida por [_CrtMemCheckpoint](crtmemcheckpoint.md) antes de **_CrtMemDumpAllObjectsSince** ser chamado. Quando o *estado* é **nulo**, a função inicia o despejo desde o início da execução do programa.

Se o aplicativo tiver instalado uma função de gancho de despejo chamando [_CrtSetDumpClient](crtsetdumpclient.md), então todas as vezes **_CrtMemDumpAllObjectsSince** despejar informações sobre um tipo de bloco **_CLIENT_BLOCK** , ele chamará o despejo fornecido pelo aplicativo também funcionam. Por padrão, os blocos de tempo de execução C internos ( **_CRT_BLOCK**) não são incluídos nas operações de despejo de memória. A função [_CrtSetDbgFlag](crtsetdbgflag.md) pode ser usada para ativar o **_CRTDBG_CHECK_CRT_DF** bit de **_crtDbgFlag** para incluir esses blocos. Além disso, os blocos marcados como liberados ou ignorados ( **_FREE_BLOCK**, **_IGNORE_BLOCK**) não são incluídos no despejo de memória.

Para obter mais informações sobre as funções de estado de heap e a estrutura **_CrtMemState** , consulte [heap State Reporting Functions](/visualstudio/debugger/crt-debug-heap-details). Para obter mais informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap base, consulte [Detalhes do heap de depuração do CRT](/visualstudio/debugger/crt-debug-heap-details).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_CrtMemDumpAll-ObjectsSince**|\<crtdbg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

Para obter um exemplo de como usar o **_CrtMemDumpAllObjectsSince**, consulte [crt_dbg2](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/crt/crt_dbg2).

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
[_crtDbgFlag](../../c-runtime-library/crtdbgflag.md)<br/>
