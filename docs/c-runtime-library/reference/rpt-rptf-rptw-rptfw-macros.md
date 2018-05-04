---
title: _RPT, _RPTF, _RPTW, _RPTFW Macros | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
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
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a53a069138b4e54988be008917e5ca2b24fa0a6c
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="rpt-rptf-rptw-rptfw-macros"></a>Macros _RPT, _RPTF, _RPTW, _RPTFW

Rastreia o progresso de um aplicativo gerando um relatório de depuração (somente versão de depuração). Observe que *n* Especifica o número de argumentos em *args* e pode ser 0, 1, 2, 3, 4 ou 5.

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

*reportType* tipo de relatório: **_CRT_WARN**, **_CRT_ERROR**, ou **_CRT_ASSERT**.

*formato* cadeia de caracteres de controle de formato usada para criar a mensagem do usuário.

*argumentos* argumentos de substituição usados por *formato*.

## <a name="remarks"></a>Comentários

Todas essas macros levar o *reportType* e *formato* parâmetros. Além disso, eles também podem adotar até quatro argumentos adicionais, representados pelo número acrescentado ao nome da macro. Por exemplo, **rpt0** e **rptf0** levar sem argumentos adicionais, **rpt1** e **rptf1** levar *arg1*, **Rpt2** e **rptf2** levar *arg1* e **arg2**, e assim por diante.

O **RPT** e **rptf** macros são semelhantes a [printf](printf-printf-l-wprintf-wprintf-l.md) funcionar, pois eles podem ser usados para rastrear o progresso de um aplicativo durante o processo de depuração. No entanto, essas macros são mais flexíveis que **printf** porque eles não precisam ser colocados entre **#ifdef** instruções para impedir que está sendo chamado em uma versão comercial de um aplicativo. Essa flexibilidade é obtida usando o [Debug](../../c-runtime-library/debug.md) macro; o **RPT** e **rptf** macros estão disponíveis somente quando o **Debug** sinalizador é definido. Quando **Debug** é chamadas para essas macros não definida, são removidas durante o pré-processamento.

O **rptw** e **rptfw** macros são versões de caractere largo dessas macros. Elas são como **and wprintf** e tomar as cadeias de caracteres largos como argumentos.

O **RPT** macros chamada a [crtdbgreport](crtdbgreport-crtdbgreportw.md) função para gerar um relatório de depuração com uma mensagem do usuário. O **rptw** macros chamada a **CrtDbgReportW** função para gerar o mesmo relatório com caracteres largos. O **rptf** e **rptfw** macros criar um relatório de depuração com o número de arquivos e linhas de origem onde a macro de relatório foi chamada, além para a mensagem do usuário. A mensagem de usuário é criada, substituindo o **arg**[*n*] argumentos para o *formato* de cadeia de caracteres, usando as mesmas regras definidas pelo [printf](printf-printf-l-wprintf-wprintf-l.md)função.

**Crtdbgreport** ou **CrtDbgReportW** gera o relatório de depuração e determina seus destinos com base nos modos de relatório atual e um arquivo definido para *reportType*. As funções [_CrtSetReportMode](crtsetreportmode.md) e [_CrtSetReportFile](crtsetreportfile.md) são usadas para definir os destinos de cada tipo de relatório.

Se um **RPT** é chamada de macro e nenhum **CrtSetReportMode** nem **crtsetreportfile** tiver sido chamado, as mensagens são exibidas como a seguir.

|Tipo de relatório|Destino de saída|
|-----------------|------------------------|
|**_CRT_WARN**|O texto de aviso não é exibido.|
|**_CRT_ERROR**|Uma janela pop-up. Mesmo que se `_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_WNDW);` tivesse sido especificado.|
|**_CRT_ASSERT**|Mesmo que **_CRT_ERROR**.|

Quando o destino é uma janela de mensagem de depuração e o usuário escolhe o **novamente** botão, **crtdbgreport** ou **CrtDbgReportW** retorna 1, fazendo com que essas macros iniciar o o depurador, desde que a depuração do just-in-time (JIT) está habilitada. Para obter mais informações sobre como usar essas macros como um mecanismo de tratamento de erro de depuração, consulte [Usando macros para verificação e relatórios](/visualstudio/debugger/macros-for-reporting).

Há duas outras macros que geram um relatório de depuração. A macro [_ASSERT](assert-asserte-assert-expr-macros.md) gera um relatório, mas somente quando o argumento de expressão é avaliado como FALSE. [Asserte](assert-asserte-assert-expr-macros.md) é exatamente com **Assert**, mas inclui a expressão com falha no relatório gerado.

## <a name="requirements"></a>Requisitos

|Macro|Cabeçalho necessário|
|-----------|---------------------|
|**RPT** macros|\<crtdbg.h>|
|**Rptf** macros|\<crtdbg.h>|
|**Rptw** macros|\<crtdbg.h>|
|**Rptfw** macros|\<crtdbg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).

Embora essas macros sejam obtidas com a inclusão de Crtdbg.h, o aplicativo deve ser vinculado a uma dessas bibliotecas de depuração, pois essas macros chamam outras funções de tempo de execução.

## <a name="example"></a>Exemplo

Veja o exemplo no tópico [_ASSERT](assert-asserte-assert-expr-macros.md).

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
