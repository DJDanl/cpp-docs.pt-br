---
title: _CrtSetReportHook
ms.date: 11/04/2016
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
helpviewer_keywords:
- CrtSetReportHook function
- _CrtSetReportHook function
ms.assetid: 1ae7c64f-8c84-4797-9574-b59f00f7a509
ms.openlocfilehash: 7dcb916ea920751618ffa6a4afbcde8df5e35cba
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64343042"
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

**Crtsetreporthook** permite que um aplicativo para usar seu próprio relatório de função para a processo de relatório da biblioteca de depuração em tempo de execução C. Como resultado, sempre que [_CrtDbgReport](crtdbgreport-crtdbgreportw.md) for chamado para gerar um relatório de depuração, a função de relatório do aplicativo será chamada primeiro. Essa funcionalidade permite que um aplicativo executar operações como filtragem para ele possa se concentrar em tipos específicos de alocação ou enviar um relatório para destinos não está disponíveis por meio de relatórios de depuração **crtdbgreport**. Quando [Debug](../../c-runtime-library/debug.md) não está definido, as chamadas a **crtsetreporthook** são removidas durante o pré-processamento.

Para obter uma versão mais robusta **crtsetreporthook**, consulte [_CrtSetReportHook2](crtsetreporthook2-crtsetreporthookw2.md).

O **crtsetreporthook** função instala a nova função especificada em de relatório definida pelo cliente *reportHook* e retorna o gancho anterior definido pelo cliente. O seguinte exemplo demonstra como um gancho de relatório definido pelo cliente deve ser prototipado:

```C
int YourReportHook( int reportType, char *message, int *returnValue );
```

em que *reportType* é o tipo de relatório de depuração (**_CRT_WARN**, **crt_error**, ou **_CRT_ASSERT**), *mensagem* é a mensagem do usuário de depuração totalmente montada a ser contido no relatório, e **returnValue** é o valor especificado pela definida pelo cliente reporting que deve ser retornada pela função **_ CrtDbgReport**. Para obter uma descrição completa dos tipos de relatório disponíveis, consulte a função [_CrtSetReportMode](crtsetreportmode.md).

Se a função de relatório definida pelo cliente manipular totalmente a mensagem de depuração, de modo que nenhum relatório adicional é necessária, a função deve retornar **verdadeira**. Quando a função retornará **falsos**, **crtdbgreport** é chamado para gerar o relatório de depuração usando as configurações atuais para o tipo de relatório, modo e arquivo. Além disso, especificando o **crtdbgreport** retornar valor no **returnValue**, o aplicativo também pode controlar se ocorrer uma interrupção de depuração. Para obter uma descrição completa de como o relatório de depuração é configurado e gerado, consulte **CrtSetReportMode**, [crtsetreportfile](crtsetreportfile.md), e **crtdbgreport**.

Para obter mais informações sobre como usar outras funções em tempo de execução compatíveis com gancho e escrever suas próprias funções de gancho definidas pelo cliente, consulte [Gravação da função de gancho de depuração](/visualstudio/debugger/debug-hook-function-writing).

> [!NOTE]
> Se seu aplicativo for compilado com **/clr** e a função de relatório é chamada depois que o aplicativo foi encerrado principal, o CLR gerará uma exceção se a função de relatório chama todas as funções CRT.

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
