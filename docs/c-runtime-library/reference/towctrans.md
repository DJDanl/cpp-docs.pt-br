---
title: towctrans | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- towctrans
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
- towctrans
dev_langs:
- C++
helpviewer_keywords:
- towctrans function
ms.assetid: 1ed1e70d-7b31-490f-a7d9-42564b5924ca
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
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
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 94463769c6466d7a8fe4bec8f2c919df42f9f7da
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="towctrans"></a>towctrans
Transforma um caractere.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
wint_t towctrans(  
   wint_t c,  
   wctrans_t category   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `c`  
 O caractere que você deseja transformar.  
  
 `category`  
 Um identificador que contém o valor retornado de [wctrans](../../c-runtime-library/reference/wctrans.md).  
  
## <a name="return-value"></a>Valor de retorno  
 O caractere `c`, depois que `towctrans` usou a regra de transformação em `category`.  
  
## <a name="remarks"></a>Comentários  
 O valor de `category` deve ter sido retornado por uma chamada bem-sucedida anterior para [wctrans](../../c-runtime-library/reference/wctrans.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`towctrans`|\<wctype.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
 Consulte `wctrans` para obter uma amostra que usa `towctrans`.  
  
## <a name="see-also"></a>Consulte também  
 [Conversão de Dados](../../c-runtime-library/data-conversion.md)
