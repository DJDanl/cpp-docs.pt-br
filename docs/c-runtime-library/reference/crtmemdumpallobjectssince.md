---
title: _CrtMemDumpAllObjectsSince | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _CrtMemDumpAllObjectsSince
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
- CrtMemDumpAllObjectsSince
- _CrtMemDumpAllObjectsSince
dev_langs:
- C++
helpviewer_keywords:
- _CrtMemDumpAllObjectsSince function
- CrtMemDumpAllObjectsSince function
ms.assetid: c48a447a-e6bb-475c-9271-a3021182a0dc
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 24cf01facaba326c36454ea5410da8dbb05848f2
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32396863"
---
# <a name="crtmemdumpallobjectssince"></a>_CrtMemDumpAllObjectsSince

Despeja informações sobre objetos no heap a partir do início da execução do programa ou de um estado de heap especificado (somente versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
void _CrtMemDumpAllObjectsSince(
   const _CrtMemState *state
);
```

### <a name="parameters"></a>Parâmetros

*estado* ponteiro para o estado de heap para iniciar o despejo de ou **nulo**.

## <a name="remarks"></a>Comentários

O **crtmemdumpallobjectssince** função Despeja as informações de cabeçalho de depuração de objetos alocados no heap em um formato legível ao usuário. As informações de despejo podem ser usadas pelo aplicativo para acompanhar as alocações e detectar problemas de memória. Quando [Debug](../../c-runtime-library/debug.md) não está definido, chamadas para **crtmemdumpallobjectssince** são removidos durante o pré-processamento.

**Crtmemdumpallobjectssince** usa o valor de *estado* parâmetro para determinar onde iniciar a operação de despejo. Para iniciar o despejo de um estado de heap especificado, o *estado* parâmetro deve ser um ponteiro para um **crtmemstate** estrutura que tenha sido preenchida pelo [crtmemcheckpoint](crtmemcheckpoint.md) antes **Crtmemdumpallobjectssince** foi chamado. Quando *estado* é **nulo**, a função começa o despejo desde o início da execução do programa.

Se o aplicativo tiver instalado uma função de gancho de despejo chamando [crtsetdumpclient](crtsetdumpclient.md), em seguida, sempre **crtmemdumpallobjectssince** Despeja informações sobre um **client_block** tipo de bloco, ele chama a função de despejo fornecidas pelo aplicativo também. Por padrão, os blocos de tempo de execução C internos (**crt_block**) não são incluídas em operações de despejo de memória. O [crtsetdbgflag](crtsetdbgflag.md) função pode ser usada para ativar o **crtdbg_check_crt_df** um pouco de **crtdbgflag** para incluir esses blocos. Além disso, os blocos marcados como liberados ou ignorados (**_FREE_BLOCK**, **_IGNORE_BLOCK**) não são incluídos no despejo de memória.

Para obter mais informações sobre funções de estado de heap e a **crtmemstate** estrutura, consulte [funções de emissão de relatórios de estado de Heap](/visualstudio/debugger/crt-debug-heap-details). Para obter mais informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap base, consulte [Detalhes do heap de depuração do CRT](/visualstudio/debugger/crt-debug-heap-details).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_CrtMemDumpAll-ObjectsSince**|\<crtdbg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

Para obter um exemplo de como usar **crtmemdumpallobjectssince**, consulte [crt_dbg2](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/crt/crt_dbg2).

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
[_crtDbgFlag](../../c-runtime-library/crtdbgflag.md)<br/>
