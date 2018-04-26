---
title: _CrtSetReportHook | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _CrtSetReportHook
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
- _CrtSetReportHook
- CrtSetReportHook
dev_langs:
- C++
helpviewer_keywords:
- CrtSetReportHook function
- _CrtSetReportHook function
ms.assetid: 1ae7c64f-8c84-4797-9574-b59f00f7a509
caps.latest.revision: 13
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: faa7e5726555ef8000cd393f8f2f7061024095ed
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="crtsetreporthook"></a>_CrtSetReportHook

Instala uma função de relatório definida pelo cliente vinculando-a ao processo de relatório de depuração em tempo de execução C (somente versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
_CRT_REPORT_HOOK _CrtSetReportHook(
   _CRT_REPORT_HOOK reportHook
);
```

### <a name="parameters"></a>Parâmetros

*reportHook*<br/>
Nova função de relatório definida pelo cliente a ser vinculada ao processo de relatório de depuração em tempo de execução C.

## <a name="return-value"></a>Valor de retorno

Retorna a função de relatório anterior definida pelo cliente.

## <a name="remarks"></a>Comentários

**Crtsetreporthook** permite que um aplicativo para usar seu próprio relatório de função para a biblioteca de depuração do tempo de execução C processo de relatório. Como resultado, sempre que [_CrtDbgReport](crtdbgreport-crtdbgreportw.md) for chamado para gerar um relatório de depuração, a função de relatório do aplicativo será chamada primeiro. Essa funcionalidade permite que um aplicativo executar operações como a filtragem para ele possa se concentrar em tipos específicos de alocação ou enviar um relatório para destinos não está disponíveis por meio de relatórios de depuração **crtdbgreport**. Quando [Debug](../../c-runtime-library/debug.md) não está definido, chamadas para **crtsetreporthook** são removidos durante o pré-processamento.

Para obter uma versão mais robusta **crtsetreporthook**, consulte [crtsetreporthook2](crtsetreporthook2-crtsetreporthookw2.md).

O **crtsetreporthook** função instala o novo relatório função especificada em definida pelo cliente *reportHook* e retorna o gancho anterior definido pelo cliente. O seguinte exemplo demonstra como um gancho de relatório definido pelo cliente deve ser prototipado:

```C
int YourReportHook( int reportType, char *message, int *returnValue );
```

onde *reportType* é o tipo de relatório de depuração (**_CRT_WARN**, **_CRT_ERROR**, ou **_CRT_ASSERT**), *mensagem* é a mensagem de usuário totalmente montado de depuração a ser contido no relatório, e **returnValue** é o valor especificado, o cliente definido pelo relatório que deve ser retornada pela função **_ CrtDbgReport**. Para obter uma descrição completa dos tipos de relatório disponíveis, consulte a função [_CrtSetReportMode](crtsetreportmode.md).

Se a função de relatório definida pelo cliente completamente trata a mensagem de depuração, de modo que nenhum relatório adicional é necessária, a função deve retornar **TRUE**. Quando a função retorna **FALSE**, **crtdbgreport** é chamado para gerar o relatório de depuração usando as configurações atuais para o tipo de relatório, o modo e o arquivo. Além disso, especificando o **crtdbgreport** retornar o valor em **returnValue**, o aplicativo também pode controlar se ocorrer uma interrupção de depuração. Para obter uma descrição completa de como o relatório de depuração está configurado e gerado, consulte **CrtSetReportMode**, [crtsetreportfile](crtsetreportfile.md), e **crtdbgreport**.

Para obter mais informações sobre como usar outras funções em tempo de execução compatíveis com gancho e escrever suas próprias funções de gancho definidas pelo cliente, consulte [Gravação da função de gancho de depuração](/visualstudio/debugger/debug-hook-function-writing).

> [!NOTE]
> Se seu aplicativo é compilado com **/clr** e a função de relatório é chamada depois que o aplicativo foi encerrado principal, o CLR lançará uma exceção se a função de relatório chama todas as funções CRT.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_CrtSetReportHook**|\<crtdbg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
[_CrtGetReportHook](crtgetreporthook.md)<br/>
