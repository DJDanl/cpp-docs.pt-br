---
title: __pctype_func | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname: __pctype_func
apilocation:
- msvcrt.dll
- msvcr110_clr0400.dll
- msvcr110.dll
- msvcr120.dll
- msvcr90.dll
- msvcr100.dll
- msvcr80.dll
apitype: DLLExport
f1_keywords: __pctype_func
dev_langs: C++
helpviewer_keywords: __pctype_func
ms.assetid: d52b8add-d07d-4516-a22f-e836cde0c57f
caps.latest.revision: "2"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 239779bf4515615f25ff83be9221b1040d936a7f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="pctypefunc"></a>__pctype_func
Recupera um ponteiro para uma matriz de informações de classificação de caracteres.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
const unsigned short *__pctype_func(  
   )  
```  
  
## <a name="return-value"></a>Valor retornado  
 Um ponteiro para uma matriz de informações de classificação de caracteres.  
  
## <a name="remarks"></a>Comentários  
 As informações na tabela de classificação de caracteres destina-se apenas a uso interno e são usadas por várias funções que classificam caracteres do tipo `char`. Para obter mais informações, consulte a seção `Remarks` de [_pctype, _pwctype, _wctype, _mbctype, _mbcasemap](../c-runtime-library/pctype-pwctype-wctype-mbctype-mbcasemap.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|__pctype_func|ctype.h|  
  
## <a name="see-also"></a>Consulte também  
 [_pctype, _pwctype, _wctype, _mbctype, _mbcasemap](../c-runtime-library/pctype-pwctype-wctype-mbctype-mbcasemap.md)