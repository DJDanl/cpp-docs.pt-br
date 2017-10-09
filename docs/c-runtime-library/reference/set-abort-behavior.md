---
title: _set_abort_behavior | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _set_abort_behavior
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
- api-ms-win-crt-runtime-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _set_abort_behavior
- set_abort_behavior
dev_langs:
- C++
helpviewer_keywords:
- aborting programs
- _set_abort_behavior function
- set_abort_behavior function
ms.assetid: 43918766-e4ba-4b1f-80e8-1a4a910cd452
caps.latest.revision: 26
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: edf31ccddfb9ab2eaa6de226ff4ec7eb09869438
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="setabortbehavior"></a>_set_abort_behavior
Especifica a ação a ser tomada quando um programa é terminado de maneira anormal.  
  
> [!NOTE]
>  Não use esse a função `abort` para desligar um aplicativo [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)], exceto em cenários de teste ou depuração. As formas programáticas ou de interface do usuário de fechar um aplicativo [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] não são permitidas de acordo com os [Requisitos de certificação de aplicativos do Windows 8](http://go.microsoft.com/fwlink/?LinkId=262889). Para obter mais informações, consulte [Ciclo de vida do aplicativo (aplicativos da Windows Store)](http://go.microsoft.com/fwlink/?LinkId=262853).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
unsigned int _set_abort_behavior(  
   unsigned int flags,  
   unsigned int mask  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `flags`  
 Novo valor dos sinalizadores `abort`.  
  
 [in] `mask`  
 Máscara para os bits dos sinalizadores `abort` a definir.  
  
## <a name="return-value"></a>Valor de retorno  
 O valor antigo dos sinalizadores.  
  
## <a name="remarks"></a>Comentários  
 Há dois sinalizadores `abort`: `_WRITE_ABORT_MSG` e `_CALL_REPORTFAULT`. `_WRITE_ABORT_MSG` determina se uma mensagem de texto útil é impressa quando um programa é encerrado de maneira anormal. A mensagem informa que o aplicativo tiver chamou a função `abort`. O comportamento padrão é imprimir a mensagem. `_CALL_REPORTFAULT`, se definido, especifica que um despejo de memória do Watson é gerado e relatado quando `abort` é chamada. Por padrão, o relatório do despejo de memória está habilitado em builds que não são do tipo DEBUG.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_set_abort_behavior`|\<stdlib.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```C  
// crt_set_abort_behavior.c  
// compile with: /TC  
#include <stdlib.h>  
  
int main()  
{  
   printf("Suppressing the abort message. If successful, this message"  
          " will be the only output.\n");  
   // Suppress the abort message  
   _set_abort_behavior( 0, _WRITE_ABORT_MSG);  
   abort();  
}  
```  
  
```Output  
Suppressing the abort message. If successful, this message will be the only output.  
```  
  
## <a name="see-also"></a>Consulte também  
 [abort](../../c-runtime-library/reference/abort.md)
