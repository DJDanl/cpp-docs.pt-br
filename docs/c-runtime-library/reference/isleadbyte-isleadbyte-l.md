---
title: isleadbyte, _isleadbyte_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _isleadbyte_l
- isleadbyte
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
- api-ms-win-crt-string-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _istleadbyte
- _isleadbyte_l
- isleadbyte
dev_langs: C++
helpviewer_keywords:
- lead bytes
- _isleadbyte_l function
- _istleadbyte function
- istleadbyte function
- isleadbyte function
ms.assetid: 3b2bcf09-d82b-4803-9e80-59d04942802a
caps.latest.revision: "20"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: e6d679d634d14f3a762a6ef3d32d2ca4c5d4b6f0
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="isleadbyte-isleadbytel"></a>isleadbyte, _isleadbyte_l
Determina se um caractere é o byte inicial de um caractere multibyte.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, consulte [Funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int isleadbyte(  
   int c   
);  
int _isleadbyte_l(  
   int c   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `c`  
 Inteiro a ser testado.  
  
## <a name="return-value"></a>Valor de retorno  
 `isleadbyte` retornará um valor diferente de zero se o argumento satisfizer a condição de teste, ou 0 se não satisfizer. Na localidade "C" e em localidades de SBCS (conjunto de caracteres de um byte), `isleadbyte` sempre retorna 0.  
  
## <a name="remarks"></a>Comentários  
 A macro `isleadbyte` retornará um valor diferente de zero se o argumento for o primeiro byte de um caractere multibyte. `isleadbyte`produz um resultado significativo de qualquer argumento de número inteiro entre -1 (`EOF`) para `UCHAR_MAX` (0xFF), inclusive.  
  
 O tipo de argumento esperado de `isleadbyte` é `int`; se um caractere com sinal for passado, o compilador poderá convertê-lo em um inteiro pela extensão de sinal, gerando resultados imprevisíveis.  
  
 A versão dessa função com o sufixo `_l` é idêntica, exceto pelo fato de que ele usa a localidade passada em vez da localidade atual para seu comportamento que depende da localidade.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_istleadbyte`|Sempre retorna falso|**_** `isleadbyte`|Sempre retorna falso|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`isleadbyte`|\<ctype.h>|  
|`_isleadbyte_l`|\<ctype.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Classificação de byte](../../c-runtime-library/byte-classification.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Rotinas _ismbb](../../c-runtime-library/ismbb-routines.md)