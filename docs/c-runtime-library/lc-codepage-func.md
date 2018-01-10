---
title: ___lc_codepage_func | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname: ___lc_codepage_func
apilocation:
- msvcr120.dll
- msvcr110_clr0400.dll
- msvcr80.dll
- msvcr100.dll
- msvcr90.dll
- msvcr110.dll
- msvcrt.dll
apitype: DLLExport
f1_keywords:
- lc_codepage_func
- ___lc_codepage_func
dev_langs: C++
helpviewer_keywords: ___lc_codepage_func
ms.assetid: 6a663bd0-5a63-4a2f-9507-872ec1582aae
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 8532984c8557b095753c0e8cf30b6e63d8b01ce0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="lccodepagefunc"></a>___lc_codepage_func
Função CRT interna. Recupera a página de código atual do thread.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
UINT ___lc_codepage_func(void);  
```  
  
## <a name="return-value"></a>Valor retornado  
 A página de código atual do thread.  
  
## <a name="remarks"></a>Comentários  
 `___lc_codepage_func` é uma função CRT interna usada por outras funções CRT para obter a página de código atual do armazenamento local do thread para os dados do CRT. Essas informações também estão disponíveis usando a função [_get_current_locale](../c-runtime-library/reference/get-current-locale.md).  
  
 Uma *página de código* é um mapeamento dos códigos de um ou dois bytes para caracteres individuais. Diferentes páginas de código contêm caracteres especiais diferentes, que geralmente são personalizados para um idioma ou um grupo de idiomas. Para obter mais informações sobre páginas de códigos, consulte [Páginas de código](../c-runtime-library/code-pages.md).  
  
 Funções CRT internas são específicas da implementação e estão sujeitas a alteração em cada versão. Não recomendamos usá-las no seu código.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`___lc_codepage_func`|crt\src\setlocal.h|  
  
## <a name="see-also"></a>Consulte também  
 [_get_current_locale](../c-runtime-library/reference/get-current-locale.md)   
 [setlocale, _wsetlocale](../c-runtime-library/reference/setlocale-wsetlocale.md)   
 [_create_locale, _wcreate_locale](../c-runtime-library/reference/create-locale-wcreate-locale.md)   
 [_free_locale](../c-runtime-library/reference/free-locale.md)