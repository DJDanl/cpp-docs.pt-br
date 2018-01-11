---
title: _CrtSetReportHook | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname: _CrtSetReportHook
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
dev_langs: C++
helpviewer_keywords:
- CrtSetReportHook function
- _CrtSetReportHook function
ms.assetid: 1ae7c64f-8c84-4797-9574-b59f00f7a509
caps.latest.revision: "13"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 4c1fb85ab41c02bb9f604f024f86ebb42706eeda
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="crtsetreporthook"></a>_CrtSetReportHook
Instala uma função de relatório definida pelo cliente vinculando-a ao processo de relatório de depuração em tempo de execução C (somente versão de depuração).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
_CRT_REPORT_HOOK _CrtSetReportHook(   
   _CRT_REPORT_HOOK reportHook   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `reportHook`  
 Nova função de relatório definida pelo cliente a ser vinculada ao processo de relatório de depuração em tempo de execução C.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna a função de relatório anterior definida pelo cliente.  
  
## <a name="remarks"></a>Comentários  
 `_CrtSetReportHook` permite que um aplicativo use sua própria função de relatório no processo de relatório da biblioteca de depuração em tempo de execução C. Como resultado, sempre que [_CrtDbgReport](../../c-runtime-library/reference/crtdbgreport-crtdbgreportw.md) for chamado para gerar um relatório de depuração, a função de relatório do aplicativo será chamada primeiro. Essa funcionalidade permite que um aplicativo execute operações como filtragem de relatórios de depuração, para ele possa se concentrar em tipos de alocação específicos ou enviar um relatório para os destinos não disponíveis com o uso de `_CrtDbgReport`. Quando [_DEBUG](../../c-runtime-library/debug.md) não está definido, as chamadas a `_CrtSetReportHook` são removidas durante o pré-processamento.  
  
 Para obter uma versão mais robusta de `_CrtSetReportHook`, consulte [_CrtSetReportHook2](../../c-runtime-library/reference/crtsetreporthook2-crtsetreporthookw2.md).  
  
 A função `_CrtSetReportHook` instala a nova função de relatório definida pelo cliente especificada em `reportHook` e retorna o gancho anterior definido pelo cliente. O seguinte exemplo demonstra como um gancho de relatório definido pelo cliente deve ser prototipado:  
  
```  
int YourReportHook( int reportType, char *message, int *returnValue );  
```  
  
 em que `reportType` é o tipo de relatório de depuração (`_CRT_WARN`, `_CRT_ERROR` ou `_CRT_ASSERT`), `message` é a mensagem do usuário de depuração totalmente montada a ser contida no relatório e `returnValue` é o valor especificado pela função de relatório definida pelo cliente que deve ser retornada por `_CrtDbgReport`. Para obter uma descrição completa dos tipos de relatório disponíveis, consulte a função [_CrtSetReportMode](../../c-runtime-library/reference/crtsetreportmode.md).  
  
 Se a função de relatório definida pelo cliente manipular totalmente a mensagem de depuração, de modo que nenhum relatório adicional seja necessário, a função deverá retornar `TRUE`. Quando a função retorna `FALSE`, `_CrtDbgReport` é chamado para gerar o relatório de depuração usando as configurações atuais para o tipo de relatório, modo e arquivo. Além disso, ao especificar o valor retornado `_CrtDbgReport` em `returnValue`, o aplicativo também poderá controlar se uma interrupção de depuração deverá ocorrer. Para obter uma descrição completa de como o relatório de depuração é configurado e gerado, consulte `_CrtSetReportMode`, [_CrtSetReportFile](../../c-runtime-library/reference/crtsetreportfile.md) e `_CrtDbgReport`.  
  
 Para obter mais informações sobre como usar outras funções em tempo de execução compatíveis com gancho e escrever suas próprias funções de gancho definidas pelo cliente, consulte [Gravação da função de gancho de depuração](/visualstudio/debugger/debug-hook-function-writing).  
  
> [!NOTE]
>  Se o aplicativo for compilado com `/clr` e a função de relatório for chamada depois que o aplicativo tiver saído da principal, o CLR gerará uma exceção, caso a função de relatório chame todas as funções CRT.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_CrtSetReportHook`|\<crtdbg.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="libraries"></a>Libraries  
 Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)   
 [_CrtGetReportHook](../../c-runtime-library/reference/crtgetreporthook.md)