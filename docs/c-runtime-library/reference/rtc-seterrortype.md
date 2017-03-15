---
title: _RTC_SetErrorType | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _RTC_SetErrorType
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
- RTC_SetErrorType
- _RTC_SetErrorType
dev_langs:
- C++
helpviewer_keywords:
- run-time errors
- RTC_SetErrorType function
- _RTC_SetErrorType function
ms.assetid: f5f99be7-d357-4b11-b8f5-ddd3428f2b06
caps.latest.revision: 13
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
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: da5f95812b750da5f337eb459cf136b7eb827c5c
ms.lasthandoff: 02/25/2017

---
# <a name="rtcseterrortype"></a>_RTC_SetErrorType
Associa um erro que é detectado pelas RTCs (verificações de erro em tempo de execução) com um tipo. O manipulador de erro processa a saída dos erros do tipo especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      int _RTC_SetErrorType(  
   _RTC_ErrorNumber errnum,  
   int ErrType   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *errnum*  
 Um número entre zero e um a menos do que o valor retornado por [_RTC_NumErrors](../../c-runtime-library/reference/rtc-numerrors.md).  
  
 *ErrType*  
 O valor a ser atribuído a esse *errnum*. Por exemplo, você pode usar **_CRT_ERROR**. Se você estiver usando `_CrtDbgReport` como seu manipulador de erro, *ErrType* só poderá ser um dos símbolos definidos em [_CrtSetReportMode](../../c-runtime-library/reference/crtsetreportmode.md). Se você tiver seu próprio manipulador de erro ([_RTC_SetErrorFunc](../../c-runtime-library/reference/rtc-seterrorfunc.md)), poderá ter tantos *ErrType*s quantos *errnum*s.  
  
 Um *ErrType* de _RTC_ERRTYPE_IGNORE tem um significado especial para `_CrtSetReportMode`; o erro será ignorado.  
  
## <a name="return-value"></a>Valor de retorno  
 O valor anterior para o tipo de erro `type`.  
  
## <a name="remarks"></a>Comentários  
 Por padrão, todos os erros são definidos como *ErrType* = 1, que corresponde a **_CRT_ERROR**. Para obter mais informações sobre os tipos de erro padrão como **_CRT_ERROR**, consulte [_CrtDbgReport](../../c-runtime-library/reference/crtdbgreport-crtdbgreportw.md).  
  
 Antes de chamar essa função, você deve chamar primeiro uma das funções de inicialização de verificação de erro em tempo de execução; consulte [Usando as verificações de tempo de execução sem a Biblioteca em Tempo de Execução C](/visualstudio/debugger/using-run-time-checks-without-the-c-run-time-library)  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_RTC_SetErrorType`|\<rtcapi.h>|  
  
 Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="libraries"></a>Libraries  
 Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).  
  
## <a name="see-also"></a>Consulte também  
 [_RTC_GetErrDesc](../../c-runtime-library/reference/rtc-geterrdesc.md)   
 [Verificação de erros em tempo de execução](../../c-runtime-library/run-time-error-checking.md)
