---
title: _RPT, _RPTF, _RPTW, _RPTFW Macros | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 14
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Machine Translation
ms.sourcegitcommit: a82768750e6a7837bb81edd8a51847f83c294c20
ms.openlocfilehash: ca0ae546af28c342db2e452bec432ced0437738a
ms.contentlocale: pt-br
ms.lasthandoff: 04/04/2017

---
# <a name="rpt-rptf-rptw-rptfw-macros"></a>Macros _RPT, _RPTF, _RPTW, _RPTFW
Rastreia o progresso de um aplicativo gerando um relatório de depuração (somente versão de depuração). Observe que *n* especifica o número de argumentos em `args` e pode ser 0, 1, 2, 3, 4 ou 5.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 `reportType`  
 Tipo de relatório: `_CRT_WARN`, `_CRT_ERROR` ou `_CRT_ASSERT`.  
  
 `format`  
 Cadeia de caracteres de controle de formato usada para criar a mensagem do usuário.  
  
 `args`  
 Argumentos de substituição usados por `format`.  
  
## <a name="remarks"></a>Comentários  
 Todas essas macros levar o `reportType` e `format` parâmetros. Além disso, eles também podem adotar até quatro argumentos adicionais, representados pelo número acrescentado ao nome da macro. Por exemplo, `_RPT0` e `_RPTF0` não adotam nenhum argumento adicional, `_RPT1` e `_RPTF1` adotam `arg1`, `_RPT2` e `_RPTF2` adotam `arg1` e `arg2`, e assim por diante.  
  
 As macros `_RPT` e `_RPTF` são semelhantes à função [printf](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md), pois podem ser usadas para controlar o andamento de um aplicativo durante o processo de depuração. No entanto, essas macros são mais flexíveis que `printf` porque elas não precisam ser colocadas em instruções `#ifdef` para impedi-las de serem chamadas em um build comercial de um aplicativo. Essa flexibilidade é obtida usando a macro [_DEBUG](../../c-runtime-library/debug.md); as macros `_RPT` e `_RPTF` estão disponíveis somente quando o sinalizador `_DEBUG` é definido. Quando `_DEBUG` não está definido, as chamadas para essas macros são removidas durante o pré-processamento.  
  
 As macros `_RPTW` e `_RPTFW` são versões de caracteres largos dessas macros. Elas são como `wprintf` e adotam cadeias de caracteres largos como argumentos.  
  
 As macros `_RPT` chamam a função [_CrtDbgReport](../../c-runtime-library/reference/crtdbgreport-crtdbgreportw.md) para gerar um relatório de depuração com uma mensagem do usuário. As macros `_RPTW` chamam a função `_CrtDbgReportW` para gerar o mesmo relatório com caracteres largos. As macros `_RPTF` e `_RPTFW` criam um relatório de depuração com arquivo de origem e o número de linha em que a macro de relatório foi chamada, além da mensagem do usuário. A mensagem do usuário é criada substituindo os argumentos `arg`[*n*] na cadeia de caracteres `format` usando as mesmas regras definidas pela função [printf](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md).  
  
 `_CrtDbgReport` ou `_CrtDbgReportW` geram o relatório de depuração e determinam seu destino com base nos modos de relatório atual e no arquivo definido para `reportType`. As funções [_CrtSetReportMode](../../c-runtime-library/reference/crtsetreportmode.md) e [_CrtSetReportFile](../../c-runtime-library/reference/crtsetreportfile.md) são usadas para definir os destinos de cada tipo de relatório.  
  
 Se uma macro `_RPT` é chamada e nenhuma `_CrtSetReportMode` nem `_CrtSetReportFile` tiver sido chamada, as mensagens são exibidas da seguinte maneira.  
  
|Tipo de relatório|Destino de saída|  
|-----------------|------------------------|  
|`_CRT_WARN`|O texto de aviso não é exibido.|  
|`_CRT_ERROR`|Uma janela pop-up. Mesmo que se `_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_WNDW);` tivesse sido especificado.|  
|`_CRT_ASSERT`|Mesmo que `_CRT_ERROR`.|  
  
 Quando o destino é uma janela de mensagem de depuração e o usuário escolhe o botão **Tentar novamente**, `_CrtDbgReport` ou `_CrtDbgReportW` retornam 1, fazendo com que essas macros iniciem o depurador, desde que a depuração JIT (Just-In-Time) esteja habilitada. Para obter mais informações sobre como usar essas macros como um mecanismo de tratamento de erro de depuração, consulte [Usando macros para verificação e relatórios](/visualstudio/debugger/macros-for-reporting).  
  
 Há duas outras macros que geram um relatório de depuração. A macro [_ASSERT](../../c-runtime-library/reference/assert-asserte-assert-expr-macros.md) gera um relatório, mas somente quando o argumento de expressão é avaliado como FALSE. [_ASSERTE](../../c-runtime-library/reference/assert-asserte-assert-expr-macros.md) é exatamente igual a `_ASSERT`, mas inclui a expressão com falha no relatório gerado.  
  
## <a name="requirements"></a>Requisitos  
  
|Macro|Cabeçalho necessário|  
|-----------|---------------------|  
|Macros `_RPT`|\<crtdbg.h>|  
|Macros `_RPTF`|\<crtdbg.h>|  
|Macros `_RPTW`|\<crtdbg.h>|  
|Macros `_RPTFW`|\<crtdbg.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="libraries"></a>Libraries  
 Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
 Embora essas macros sejam obtidas com a inclusão de Crtdbg.h, o aplicativo deve ser vinculado a uma dessas bibliotecas de depuração, pois essas macros chamam outras funções de tempo de execução.  
  
## <a name="example"></a>Exemplo  
 Veja o exemplo no tópico [_ASSERT](../../c-runtime-library/reference/assert-asserte-assert-expr-macros.md).  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)
