---
title: _CrtSetReportMode | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _CrtSetReportMode
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
- _CrtSetReportMode
- CrtSetReportMode
dev_langs:
- C++
helpviewer_keywords:
- _CrtSetReportMode function
- CrtSetReportMode function
ms.assetid: 3ecc6a12-afdd-4242-b046-8187ff6d4b36
caps.latest.revision: 15
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
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: b7e3cb7562fb63467ef0e0ee28861936fb820fa3
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="crtsetreportmode"></a>_CrtSetReportMode
Especifica o destino ou os destinos para um tipo de relatório específico gerado por `_CrtDbgReport` e por macros que chamam [_CrtDbgReport, _CrtDbgReportW](../../c-runtime-library/reference/crtdbgreport-crtdbgreportw.md), como [Macros _ASSERT, _ASSERTE, _ASSERT_EXPR](../../c-runtime-library/reference/assert-asserte-assert-expr-macros.md), [Macros _ASSERT, _ASSERTE, _ASSERT_EXPR](../../c-runtime-library/reference/assert-asserte-assert-expr-macros.md), [Macros _RPT, _RPTF, _RPTW, _RPTFW](../../c-runtime-library/reference/rpt-rptf-rptw-rptfw-macros.md) e [Macros _RPT, _RPTF, _RPTW, _RPTFW](../../c-runtime-library/reference/rpt-rptf-rptw-rptfw-macros.md) (somente versão de depuração).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _CrtSetReportMode(   
   int reportType,  
   int reportMode   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `reportType`  
 Tipo de relatório: `_CRT_WARN`, `_CRT_ERROR` e `_CRT_ASSERT`.  
  
 `reportMode`  
 Novos modos de relatório para `reportType`.  
  
## <a name="return-value"></a>Valor de retorno  
 Após a conclusão bem-sucedida, `_CrtSetReportMode` retorna os modos de relatório anteriores para o tipo de relatório especificado em `reportType`. Se um valor inválido for passado como `reportType` ou um modo inválido for especificado para `reportMode`, `_CrtSetReportMode` invocará o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essa função definirá `errno` como `EINVAL` e retornará -1. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 `_CrtSetReportMode` especifica o destino de saída para `_CrtDbgReport`. Como as macros `_ASSERT`, `_ASSERTE`, `_RPT` e `_RPTF` chamam `_CrtDbgReport`, `_CrtSetReportMode` especifica o destino de saída do texto especificado com essas macros.  
  
 Quando [_DEBUG](../../c-runtime-library/debug.md) não está definido, as chamadas a `_CrtSetReportMode` são removidas durante o pré-processamento.  
  
 Se você não chamar `_CrtSetReportMode` para definir o destino da saída das mensagens, os seguintes padrões entrarão em vigor:  
  
-   Erros e falhas de declaração são direcionados para uma janela de mensagem de depuração.  
  
-   Os avisos de aplicativos do Windows são enviados para a janela de saída do depurador.  
  
-   Os avisos de aplicativos do console não são exibidos.  
  
 A tabela a seguir lista os tipos de relatório definidos em Crtdbg.h.  
  
|Tipo de relatório|Descrição|  
|-----------------|-----------------|  
|`_CRT_WARN`|Avisos, mensagens e informações que não precisam de atenção imediata.|  
|`_CRT_ERROR`|Erros, problemas irrecuperáveis e problemas que exigem atenção imediata.|  
|`_CRT_ASSERT`|Falhas de declaração (expressões declaradas que são avaliadas como `FALSE`).|  
  
 A função `_CrtSetReportMode` atribui o novo modo de relatório especificado em `reportMode` ao tipo de relatório especificado em `reportType` e retorna o modo de relatório definido anteriormente para `reportType`. A tabela a seguir lista as opções disponíveis para `reportMode` e o comportamento resultante de `_CrtDbgReport`. Essas opções são definidas como sinalizadores de bits em Crtdbg.h.  
  
|Modo do relatório|Comportamento de _CrtDbgReport|  
|-----------------|-----------------------------|  
|`_CRTDBG_MODE_DEBUG`|Grava a mensagem na janela de saída do depurador.|  
|`_CRTDBG_MODE_FILE`|Grava a mensagem em um identificador de arquivo fornecido pelo usuário. [_CrtSetReportFile](../../c-runtime-library/reference/crtsetreportfile.md) deve ser chamado para definir o arquivo ou o fluxo específico a ser usado como o destino.|  
|`_CRTDBG_MODE_WNDW`|Cria uma caixa de mensagem para exibir a mensagem junto com os botões `Abort`, `Retry` e `Ignore`.|  
|`_CRTDBG_REPORT_MODE`|Retorna `reportMode` para o `reportType` especificado:<br /><br /> 1   `_CRTDBG_MODE_FILE`<br /><br /> 2   `_CRTDBG_MODE_DEBUG`<br /><br /> 4   `_CRTDBG_MODE_WNDW`|  
  
 Cada tipo de relatório pode ser relatado usando um, dois ou três modos ou nenhum modo. Portanto, é possível ter mais de um destino definido para um único tipo de relatório. Por exemplo, o seguinte fragmento de código faz com que as falhas de declaração sejam enviadas para uma janela de mensagem de depuração e para `stderr`:  
  
```  
_CrtSetReportMode( _CRT_ASSERT, _CRTDBG_MODE_FILE | _CRTDBG_MODE_WNDW );  
_CrtSetReportFile( _CRT_ASSERT, _CRTDBG_FILE_STDERR );  
```  
  
 Além disso, os modos de relatório para cada tipo de relatório podem ser controlados separadamente. Por exemplo, é possível especificar que um `reportType` de `_CRT_WARN` seja enviado para uma cadeia de caracteres de depuração de saída, enquanto `_CRT_ASSERT` seja exibido usando uma janela de mensagem de depuração e enviado para `stderr`, conforme ilustrado anteriormente.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|-------------|---------------------|---------------------|  
|`_CrtSetReportMode`|\<crtdbg.h>|\<errno.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
 **Bibliotecas:** somente versões de depuração dos [Recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md).  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)
