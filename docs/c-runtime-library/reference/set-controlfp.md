---
title: _set_controlfp | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname: _set_controlfp
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
- set_controlfp
- _set_controlfp
dev_langs: C++
helpviewer_keywords:
- set_controlfp function
- floating-point functions, setting control word
- _set_controlfp function
ms.assetid: e0689d50-f68a-4028-a9c1-fb23eedee4ad
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 132680e529c8f38b5eb69e778b6e635bd424b412
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="setcontrolfp"></a>_set_controlfp
Define a palavra de controle de ponto flutuante.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void __cdecl _set_controlfp(  
    unsigned int newControl,  
    unsigned int mask  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `newControl`  
 Novos valores de bit da palavra de controle.  
  
 `mask`  
 Máscara para novos bits da palavra de controle a ser definida.  
  
## <a name="return-value"></a>Valor de retorno  
 Nenhum.  
  
## <a name="remarks"></a>Comentários  
 O `_set_controlfp` é semelhante ao `_control87`, mas ele apenas define a palavra de controle de ponto flutuante como `newControl`. Os bits nos valores indicam o estado do controle de ponto flutuante. O estado do controle de ponto flutuante permite que o programa altere os modos de precisão, arredondamento e infinito no pacote de matemática de ponto flutuante. Também é possível usar `_set_controlfp` para mascarar ou remover a máscara das exceções de ponto flutuante. Para obter mais informações, consulte [_control87, _controlfp, \__control87_2](../../c-runtime-library/reference/control87-controlfp-control87-2.md).  
  
 Esta função é substituída durante a compilação com [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md) porque o common language runtime suporta apenas a precisão de ponto flutuante padrão.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|Compatibilidade|  
|-------------|---------------------|-------------------|  
|`_set_controlfp`|\<float.h>|Somente processador x86|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="see-also"></a>Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [_clear87, _clearfp](../../c-runtime-library/reference/clear87-clearfp.md)   
 [_status87, _statusfp, _statusfp2](../../c-runtime-library/reference/status87-statusfp-statusfp2.md)