---
title: Macros _RPT, _RPTF, _RPTW, _RPTFW
ms.date: 11/04/2016
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
- RPT3
- RPTF4
- _RPT4
- RPT1
- _RPTF0
- RPTF3
- _RPTF4
- RPTF1
- RPT4
- _RPT1
- _RPT0
- RPT0
- _RPTF2
- RPTF0
- _RPT3
- _RPT2
- _RPTF3
- RPT2
- _RPTF1
helpviewer_keywords:
- debugging [CRT], using macros
- _RPTW3 macro
- _RPT0 macro
- RPTW4 macro
- _RPTF3 macro
- _RPTW4 macro
- RPTF4 macro
- RPTFW2 macro
- RPTW macros
- RPT1 macro
- _RPTF macros
- RPTFW3 macro
- _RPTW0 macro
- _RPTF0 macro
- macros, debugging with
- _RPTW2 macro
- RPTF3 macro
- RPT3 macro
- RPT0 macro
- _RPT macros
- RPTW3 macro
- _RPTFW macros
- debug reporting macros
- RPTF macros
- RPT macros
- _RPTW macros
- RPTF2 macro
- _RPTF1 macro
- _RPT1 macro
- _RPT4 macro
- _RPTFW2 macro
- _RPTFW1 macro
- RPTF0 macro
- _RPT2 macro
- RPTFW macros
- _RPTW1 macro
- _RPTFW0 macro
- RPT4 macro
- _RPT3 macro
- _RPTFW3 macro
- _RPTF4 macro
- _RPTFW4 macro
- _RPTF2 macro
- RPTW0 macro
- RPTFW4 macro
- RPTFW0 macro
- RPTW2 macro
- RPTF1 macro
- RPT2 macro
- RPTFW1 macro
- RPTW1 macro
ms.assetid: a5bf8b30-57f7-4971-8030-e773b7a1ae13
ms.openlocfilehash: 61748cca2cdfcc2d72b6943bfeedd9597009e20b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62357481"
---
# <a name="rpt-rptf-rptw-rptfw-macros"></a>Macros _RPT, _RPTF, _RPTW, _RPTFW

Rastreia o progresso de um aplicativo gerando um relatório de depuração (somente versão de depuração). Observe que *n* Especifica o número de argumentos na *args* e pode ser 0, 1, 2, 3, 4 ou 5.

## <a name="syntax"></a>Sintaxe

```C
_RPT
      n
      (
   reportType,
   format,
...[args]
);
_RPTFn(
   reportType,
   format,
   [args]
);
_RPTWn(
   reportType,
   format
   [args]
);
_RPTFWn(
   reportType,
   format
   [args]
);
```

### <a name="parameters"></a>Parâmetros

*reportType*<br/>
Tipo de relatório: **_CRT_WARN**, **crt_error**, ou **_CRT_ASSERT**.

*format*<br/>
Cadeia de caracteres de controle de formato usada para criar a mensagem do usuário.

*args*<br/>
Argumentos de substituição usados pelo *formato*.

## <a name="remarks"></a>Comentários

Todas essas macros adotam os *reportType* e *formato* parâmetros. Além disso, eles também podem adotar até quatro argumentos adicionais, representados pelo número acrescentado ao nome da macro. Por exemplo, **_RPT0** e **_RPTF0** adotam nenhum argumento adicional, **_RPT1** e **_RPTF1** levar *arg1*, **_RPT2** e **_RPTF2** levar *arg1* e **arg2**e assim por diante.

O **macros RPT** e **rptf** macros são semelhantes para o [printf](printf-printf-l-wprintf-wprintf-l.md) funcionar, pois eles podem ser usados para controlar o progresso de um aplicativo durante o processo de depuração. No entanto, essas macros são mais flexíveis do que **printf** porque eles não precisam ser colocados entre **#ifdef** instruções para impedir que está sendo chamado em um build comercial de um aplicativo. Essa flexibilidade é obtida usando o [Debug](../../c-runtime-library/debug.md) macro; o **macros RPT** e **rptf** macros estão disponíveis somente quando o **Debug** sinalizador é definido. Quando **Debug** não é definidos, chamadas para essas macros são removidas durante o pré-processamento.

O **rptw** e **rptfw** macros são versões de caractere largo dessas macros. Elas são como **wprintf** e tomar as cadeias de caracteres largos como argumentos.

O **macros RPT** macros chamada a [crtdbgreport](crtdbgreport-crtdbgreportw.md) função para gerar um relatório de depuração com uma mensagem do usuário. O **rptw** macros chamada a **CrtDbgReportW** função para gerar o mesmo relatório com caracteres largos. O **rptf** e **rptfw** macros de criar um relatório de depuração com o número de arquivo e de linha de código-fonte em que a macro de relatório foi chamada, além para a mensagem do usuário. A mensagem do usuário é criada substituindo o **arg**[*n*] argumentos para o *formato* de cadeia de caracteres, usando as mesmas regras definidas pelo [printf](printf-printf-l-wprintf-wprintf-l.md)função.

**Crtdbgreport** ou **CrtDbgReportW** gera o relatório de depuração e determina seus destinos com base nos modos de relatório atual e um arquivo definido para *reportType*. As funções [_CrtSetReportMode](crtsetreportmode.md) e [_CrtSetReportFile](crtsetreportfile.md) são usadas para definir os destinos de cada tipo de relatório.

Se um **macros RPT** macro é chamada e nem **CrtSetReportMode** nem **crtsetreportfile** tiver sido chamado, as mensagens são exibidas da seguinte maneira.

|Tipo de relatório|Destino de saída|
|-----------------|------------------------|
|**_CRT_WARN**|O texto de aviso não é exibido.|
|**_CRT_ERROR**|Uma janela pop-up. Mesmo que se `_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_WNDW);` tivesse sido especificado.|
|**_CRT_ASSERT**|Mesmo que **crt_error**.|

Quando o destino é uma janela de mensagem de depuração e o usuário escolhe o **repetir** botão **crtdbgreport** ou **CrtDbgReportW** retorna 1, fazendo com que essas macros iniciar o o depurador, desde que a depuração do just-in-time (JIT) está habilitada. Para obter mais informações sobre como usar essas macros como um mecanismo de tratamento de erro de depuração, consulte [Usando macros para verificação e relatórios](/visualstudio/debugger/macros-for-reporting).

Há duas outras macros que geram um relatório de depuração. A macro [_ASSERT](assert-asserte-assert-expr-macros.md) gera um relatório, mas somente quando o argumento de expressão é avaliado como FALSE. [Asserte](assert-asserte-assert-expr-macros.md) é exatamente igual **macros Assert**, mas inclui a expressão com falha no relatório gerado.

## <a name="requirements"></a>Requisitos

|Macro|Cabeçalho necessário|
|-----------|---------------------|
|**_RPT** macros|\<crtdbg.h>|
|**_RPTF** macros|\<crtdbg.h>|
|**_RPTW** macros|\<crtdbg.h>|
|**_RPTFW** macros|\<crtdbg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).

Embora essas macros sejam obtidas com a inclusão de Crtdbg.h, o aplicativo deve ser vinculado a uma dessas bibliotecas de depuração, pois essas macros chamam outras funções de tempo de execução.

## <a name="example"></a>Exemplo

Veja o exemplo no tópico [_ASSERT](assert-asserte-assert-expr-macros.md).

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
