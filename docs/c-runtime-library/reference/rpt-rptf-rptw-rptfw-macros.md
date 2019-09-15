---
title: Macros _RPT, _RPTF, _RPTW, _RPTFW
ms.date: 11/04/2016
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
ms.openlocfilehash: 567fe0a68f5adad6f5d90ef3da9d673a75bb83a6
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70949080"
---
# <a name="_rpt-_rptf-_rptw-_rptfw-macros"></a>Macros _RPT, _RPTF, _RPTW, _RPTFW

Rastreia o progresso de um aplicativo gerando um relatório de depuração (somente versão de depuração). Observe que *n* especifica o número de argumentos em *args* e pode ser 0, 1, 2, 3, 4 ou 5.

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
Tipo de relatório: **_CRT_WARN**, **_CRT_ERROR**ou **_CRT_ASSERT**.

*format*<br/>
Cadeia de caracteres de controle de formato usada para criar a mensagem do usuário.

*args*<br/>
Argumentos de substituição usados pelo *formato*.

## <a name="remarks"></a>Comentários

Todas essas macros usam os parâmetros *reportType* e *Format* . Além disso, eles também podem adotar até quatro argumentos adicionais, representados pelo número acrescentado ao nome da macro. Por exemplo, **_RPT0** e **_RPTF0** não têm argumentos adicionais, **_RPT1** e **_RPTF1** usam *arg1*, **_RPT2** e **_RPTF2** usam *arg1* e **arg2**, e assim por diante.

As macros **_RPT** e **_RPTF** são semelhantes à função [printf](printf-printf-l-wprintf-wprintf-l.md) , pois podem ser usadas para rastrear o progresso de um aplicativo durante o processo de depuração. No entanto, essas macros são mais flexíveis do que **printf** porque não precisam ser colocadas em **#ifdef** instruções para impedir que elas sejam chamadas em uma compilação de varejo de um aplicativo. Essa flexibilidade é obtida usando a macro [_DEBUG](../../c-runtime-library/debug.md) ; as macros **_RPT** e **_RPTF** só estão disponíveis quando o sinalizador **_DEBUG** é definido. Quando **_DEBUG** não é definido, as chamadas para essas macros são removidas durante o pré-processamento.

As macros **_RPTW** e **_RPTFW** são versões de caracteres largos dessas macros. Eles são como **wprintf** e assumem cadeias de caracteres largos como argumentos.

As macros **_RPT** chamam a função [_CrtDbgReport](crtdbgreport-crtdbgreportw.md) para gerar um relatório de depuração com uma mensagem de usuário. As macros **_RPTW** chamam a função _ **CrtDbgReportW** para gerar o mesmo relatório com caracteres largos. As macros **_RPTF** e **_RPTFW** criam um relatório de depuração com o arquivo de origem e o número de linha em que a macro de relatório foi chamada, além da mensagem de usuário. A mensagem de usuário é criada substituindo os argumentos **ARG**[*n*] na cadeia de caracteres de *formato* , usando as mesmas regras definidas pela função [printf](printf-printf-l-wprintf-wprintf-l.md) .

**_CrtDbgReport** ou _ _ **CrtDbgReportW** gera o relatório de depuração e determina seus destinos com base nos modos de relatório atuais e no arquivo definido para *reportType*. As funções [_CrtSetReportMode](crtsetreportmode.md) e [_CrtSetReportFile](crtsetreportfile.md) são usadas para definir os destinos de cada tipo de relatório.

Se uma macro **_RPT** for chamada e nenhum **_CrtSetReportMode** nem **_CrtSetReportFile** for chamado, as mensagens serão exibidas da seguinte maneira.

|Tipo de relatório|Destino de saída|
|-----------------|------------------------|
|**_CRT_WARN**|O texto de aviso não é exibido.|
|**_CRT_ERROR**|Uma janela pop-up. Mesmo que se `_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_WNDW);` tivesse sido especificado.|
|**_CRT_ASSERT**|O mesmo que **_CRT_ERROR**.|

Quando o destino é uma janela de mensagem de depuração e o usuário escolhe o botão de **repetição** , **_CrtDbgReport** ou _ **CrtDbgReportW** retorna 1, fazendo com que essas macros iniciem o depurador, desde que a depuração Just-in-time (JIT) esteja habilitada. Para obter mais informações sobre como usar essas macros como um mecanismo de tratamento de erro de depuração, consulte [Usando macros para verificação e relatórios](/visualstudio/debugger/macros-for-reporting).

Há duas outras macros que geram um relatório de depuração. A macro [_ASSERT](assert-asserte-assert-expr-macros.md) gera um relatório, mas somente quando o argumento de expressão é avaliado como FALSE. [_ASSERTE](assert-asserte-assert-expr-macros.md) é exatamente como **_ASSERT**, mas inclui a expressão com falha no relatório gerado.

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
