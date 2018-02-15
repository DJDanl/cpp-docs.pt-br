---
title: wctype | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- wctype
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
- wctype
dev_langs:
- C++
helpviewer_keywords:
- wctype function
- wide characters
ms.assetid: 14aded12-4087-4123-bc48-db4e10999223
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 17006f31e02e7aed60a20e088502fe969059084c
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="wctype"></a>wctype
Determina uma regra de classificação para códigos de caracteres largos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
wctype_t wctype(  
   const char * property   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `property`  
 Cadeia de caracteres de propriedade.  
  
## <a name="return-value"></a>Valor de retorno  
 Se a categoria `LC_CTYPE` da localidade atual não definir nenhuma regra de classificação cujo nome corresponde à cadeia de propriedade `property`, a função retornará zero. Caso contrário, retornará um valor diferente de zero adequado para uso como o segundo argumento para uma chamada subsequente a [towctrans](../../c-runtime-library/reference/towctrans.md).  
  
## <a name="remarks"></a>Comentários  
 A função determina uma regra de classificação para códigos de caracteres largos. Os seguintes pares de chamadas têm o mesmo comportamento em todas as localidades (mas uma implementação pode definir regras de classificação adicionais até mesmo na localidade "C"):  
  
|Função|Mesmo que|  
|--------------|-------------|  
|`iswalnum(`  `c`  `)`|`iswctype(`  `c` `, wctype( "alnum" ) )`|  
|`iswalpha(`  `c`  `)`|`iswctype(`  `c` `, wctype( "alpha" ) )`|  
|`iswcntrl(`  `c`  `)`|`iswctype(`  `c` `, wctype( "cntrl" ) )`|  
|`iswdigit(`  `c`  `)`|`iswctype(`  `c` `, wctype( "digit" ) )`|  
|`iswgraph(`  `c`  `)`|`iswctype(`  `c` `, wctype( "graph" ) )`|  
|`iswlower(`  `c`  `)`|`iswctype(`  `c` `, wctype( "lower" ) )`|  
|`iswprint(`  `c`  `)`|`iswctype(`  `c` `, wctype( "print" ) )`|  
|`iswpunct(`  `c`  `)`|`iswctype(`  `c` `, wctype( "punct" ) )`|  
|`iswspace(`  `c`  `)`|`iswctype(`  `c` `, wctype( "space" ) )`|  
|`iswupper(`  `c`  `)`|`iswctype(`  `c` `, wctype( "upper" ) )`|  
|`iswxdigit(`  `c`  `)`|`iswctype(`  `c` `, wctype( "xdigit" ) )`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`wctype`|\<wctype.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="see-also"></a>Consulte também  
 [Conversão de Dados](../../c-runtime-library/data-conversion.md)   
 [setlocale, _wsetlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md)