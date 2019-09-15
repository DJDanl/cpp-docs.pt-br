---
title: _CrtSetReportHook
ms.date: 11/04/2016
api_name:
- _CrtSetReportHook
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
- _CrtSetReportHook
- CrtSetReportHook
helpviewer_keywords:
- CrtSetReportHook function
- _CrtSetReportHook function
ms.assetid: 1ae7c64f-8c84-4797-9574-b59f00f7a509
ms.openlocfilehash: 77c1e499c66a76027e872783e256754ef72e465d
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70938507"
---
# <a name="_crtsetreporthook"></a>_CrtSetReportHook

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

O **_CrtSetReportHook** permite que um aplicativo use sua própria função de relatório no processo de relatório da biblioteca de depuração em tempo de execução do C. Como resultado, sempre que [_CrtDbgReport](crtdbgreport-crtdbgreportw.md) for chamado para gerar um relatório de depuração, a função de relatório do aplicativo será chamada primeiro. Essa funcionalidade permite que um aplicativo execute operações como filtrar relatórios de depuração para que ele possa se concentrar em tipos de alocação específicos ou enviar um relatório para os destinos não disponíveis usando **_CrtDbgReport**. Quando [_DEBUG](../../c-runtime-library/debug.md) não é definido, as chamadas para **_CrtSetReportHook** são removidas durante o pré-processamento.

Para obter uma versão mais robusta do **_CrtSetReportHook**, consulte [_CrtSetReportHook2](crtsetreporthook2-crtsetreporthookw2.md).

A função **_CrtSetReportHook** instala a nova função de relatório definida pelo cliente especificada em *reportHook* e retorna o gancho definido pelo cliente anterior. O seguinte exemplo demonstra como um gancho de relatório definido pelo cliente deve ser prototipado:

```C
int YourReportHook( int reportType, char *message, int *returnValue );
```

em que *reportType* é o tipo de relatório de depuração ( **_CRT_WARN**, **_CRT_ERROR**ou **_CRT_ASSERT**), *Message* é a mensagem de usuário de depuração totalmente montada a ser contida no relatório e **ReturnValue** é o valor especificado pela função de relatório definida pelo cliente que deve ser retornada por **_CrtDbgReport**. Para obter uma descrição completa dos tipos de relatório disponíveis, consulte a função [_CrtSetReportMode](crtsetreportmode.md).

Se a função de relatório definida pelo cliente manipular completamente a mensagem de depuração de modo que nenhum outro relatório seja necessário, a função deverá retornar **true**. Quando a função retorna **false**, **_CrtDbgReport** é chamado para gerar o relatório de depuração usando as configurações atuais para o tipo de relatório, o modo e o arquivo. Além disso, ao especificar o valor de retorno de **_CrtDbgReport** em **ReturnValue**, o aplicativo também pode controlar se ocorre uma interrupção de depuração. Para obter uma descrição completa de como o relatório de depuração é configurado e gerado, consulte **_CrtSetReportMode**, [_CrtSetReportFile](crtsetreportfile.md)e **_CrtDbgReport**.

Para obter mais informações sobre como usar outras funções em tempo de execução compatíveis com gancho e escrever suas próprias funções de gancho definidas pelo cliente, consulte [Gravação da função de gancho de depuração](/visualstudio/debugger/debug-hook-function-writing).

> [!NOTE]
> Se seu aplicativo for compilado com **/CLR** e a função de relatório for chamada depois que o aplicativo for encerrado principal, o CLR lançará uma exceção se a função de relatório chamar quaisquer funções do CRT.

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
