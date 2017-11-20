---
title: ___mb_cur_max_func, ___mb_cur_max_l_func, __p___mb_cur_max, __mb_cur_max | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- ___mb_cur_max_l_func
- __p___mb_cur_max
- ___mb_cur_max_func
- __mb_cur_max
apilocation:
- msvcr110_clr0400.dll
- msvcr110.dll
- msvcr80.dll
- msvcr100.dll
- msvcrt.dll
- msvcr90.dll
- msvcr120.dll
apitype: DLLExport
f1_keywords:
- ___mb_cur_max_func
- ___mb_cur_max_l_func
- __p___mb_cur_max
- __mb_cur_max
dev_langs: C++
helpviewer_keywords:
- __mb_cur_max
- ___mb_cur_max_func
- ___mb_cur_max_l_func
- __p___mb_cur_max
ms.assetid: 60d36108-1ca7-45a6-8ce7-68a91f13e3a1
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: c071ddafad89dc284aebea2dc49d74385feb91da
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="mbcurmaxfunc-mbcurmaxlfunc-pmbcurmax-mbcurmax"></a>___mb_cur_max_func, ___mb_cur_max_l_func, __p___mb_cur_max, __mb_cur_max
Função CRT interna. Recupera o número máximo de bytes em um caractere multibyte para o código de idioma atual ou especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
int ___mb_cur_max_func(void);  
int ___mb_cur_max_l_func(_locale_t locale);  
int * __p___mb_cur_max(void);  
#define __mb_cur_max (___mb_cur_max_func())  
```  
  
#### <a name="parameters"></a>Parâmetros  
 localidade  
 A estrutura do código de idioma a partir da qual o resultado deve ser recuperado. Caso esse valor seja nulo, o código de idioma do thread atual será usado.  
  
## <a name="return-value"></a>Valor de retorno  
 Recupera o número máximo de bytes em um caractere multibyte para o código de idioma de thread atual ou especificado.  
  
## <a name="remarks"></a>Comentários  
 Essa é uma função interna que o CRT usa para recuperar o valor atual da macro [MB_CUR_MAX](../c-runtime-library/mb-cur-max.md) do armazenamento local do thread. Recomendamos o uso da macro `MB_CUR_MAX` no seu código para fins de portabilidade.  
  
 A macro `__mb_cur_max` é uma maneira conveniente de chamar a função `___mb_cur_max_func()`. A função `__p___mb_cur_max` é definida para fins de compatibilidade com o Visual C++ 5.0 e versões anteriores.  
  
 Funções CRT internas são específicas da implementação e estão sujeitas a alteração em cada versão. Não recomendamos usá-las no seu código.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`___mb_cur_max_func`, `___mb_cur_max_l_func`, `__p___mb_cur_max`|\<ctype.h>, \<stdlib.h>|  
  
## <a name="see-also"></a>Consulte também  
 [MB_CUR_MAX](../c-runtime-library/mb-cur-max.md)