---
title: _RTC_SetErrorFuncW | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _RTC_SetErrorFuncW
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
- _RTC_SetErrorFuncW
- RTC_SetErrorFuncW
dev_langs:
- C++
helpviewer_keywords:
- run-time errors
- RTC_SetErrorFuncW function
- _RTC_error_fnW typedef
- _RTC_SetErrorFuncW function
- RTC_error_fnW typedef
ms.assetid: b3e0d71f-1bd3-4c37-9ede-2f638eb3c81a
caps.latest.revision: 15
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: 9c340310feb94ac181049c01d3ab1efaee2002c3
ms.contentlocale: pt-br
ms.lasthandoff: 04/01/2017

---
# <a name="rtcseterrorfuncw"></a>_RTC_SetErrorFuncW
Designa uma função como o manipulador para relatar RTCs (verificações de erro em tempo de execução).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      _RTC_error_fnW _RTC_SetErrorFuncW(  
   _RTC_error_fnW function   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `function`  
 O endereço da função que manipulará verificações de erro em tempo de execução.  
  
## <a name="return-value"></a>Valor de retorno  
 A função de erro definida anteriormente ou `NULL` se não houver nenhuma função definida anteriormente.  
  
## <a name="remarks"></a>Comentários  
 Use apenas `_RTC_SetErrorFuncW` no novo código. `_RTC_SetErrorFunc` só é incluída na biblioteca para fins de compatibilidade com versões anteriores.  
  
 O retorno de chamada `_RTC_SetErrorFuncW` se aplica somente ao componente ao qual ele estava vinculado, não globalmente.  
  
 Verifique se o endereço que você passa para `_RTC_SetErrorFuncW` pertence a uma função de tratamento de erro válida.  
  
 Se um erro foi atribuído um tipo de -1 usando [RTC_SetErrorType](../../c-runtime-library/reference/rtc-seterrortype.md), a função de tratamento de erros não for chamado.  
  
 Antes de chamar essa função, você deve chamar primeiro uma das funções de inicialização de verificação de erro em tempo de execução. Para obter mais informações, consulte [Usando verificações de tempo de execução sem a Biblioteca em Tempo de Execução C](/visualstudio/debugger/using-run-time-checks-without-the-c-run-time-library).  
  
 **_RTC_error_fnW** é definido da seguinte forma:  
  
 **typedef int (__cdecl \*_RTC_error_fnW)(int**  `errorType` **, const wchar_t \*** *filename* **, int**  *linenumber* **, const wchar_t \*** `moduleName` **, const wchar_t \*** *format* **, ...);**  
  
 em que:  
  
 `errorType`  
 O tipo de erro que é especificado pelo [_RTC_SetErrorType](../../c-runtime-library/reference/rtc-seterrortype.md).  
  
 *filename*  
 O arquivo de origem no qual a falha ocorreu ou nulo se nenhuma informação de depuração estiver disponível.  
  
 *linenumber*  
 A linha em *filename* em que a falha ocorreu ou 0 se nenhuma informação de depuração estiver disponível.  
  
 `moduleName`  
 A DLL ou o nome do executável em que a falha ocorreu.  
  
 *format*  
 A cadeia de estilo printf para exibir uma mensagem de erro usando os parâmetros restantes. O primeiro argumento do VA_ARGLIST é o número de erro RTC que ocorreu.  
  
 Para obter um exemplo que mostra como usar **_RTC_error_fnW**, consulte [Personalização de verificações em tempo de execução nativo](/visualstudio/debugger/native-run-time-checks-customization).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_RTC_SetErrorFuncW`|\<rtcapi.h>|  
  
 Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="libraries"></a>Libraries  
 Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="see-also"></a>Consulte também  
 [_CrtDbgReport, _CrtDbgReportW](../../c-runtime-library/reference/crtdbgreport-crtdbgreportw.md)   
 [Verificação de erros em tempo de execução](../../c-runtime-library/run-time-error-checking.md)
