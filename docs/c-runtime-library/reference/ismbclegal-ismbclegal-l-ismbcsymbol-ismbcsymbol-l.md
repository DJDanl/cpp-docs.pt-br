---
title: _ismbclegal, _ismbclegal_l, _ismbcsymbol, _ismbcsymbol_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _ismbclegal_l
- _ismbclegal
- _ismbcsymbol
- _ismbcsymbol_l
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
- api-ms-win-crt-multibyte-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- ismbcsymbol_l
- _ismbcsymbol_l
- _ismbcsymbol
- _ismbclegal_l
- _ismbclegal
- ismbclegal_l
- ismbcsymbol
- ismbclegal
dev_langs:
- C++
helpviewer_keywords:
- ismbcsymbol function
- ismbclegal_l function
- _istlegal_l function
- istlegal function
- _istlegal function
- _ismbcsymbol function
- _ismbclegal_l function
- ismbclegal function
- ismbcsymbol_l function
- _ismbclegal function
- _ismbcsymbol_l function
- istlegal_l function
ms.assetid: 31bf1ea5-b56f-4e28-b21e-b49a2cf93ffc
caps.latest.revision: 18
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
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: 8a7075b9a86aceda75b4934a74b405fc9e27a908
ms.contentlocale: pt-br
ms.lasthandoff: 04/01/2017

---
# <a name="ismbclegal-ismbclegall-ismbcsymbol-ismbcsymboll"></a>_ismbclegal, _ismbclegal_l, _ismbcsymbol, _ismbcsymbol_l
Verifica se um caractere multibyte é um caractere de símbolo ou legal.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, consulte [Funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _ismbclegal(  
   unsigned int c   
);  
int _ismbclegal_l(  
   unsigned int c,   
   _locale_t locale  
);  
int _ismbcsymbol(  
   unsigned int c   
);  
int _ismbcsymbol_l(  
   unsigned int c,  
   _locale_t locale  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `c`  
 Caractere a ser testado.  
  
 `locale`  
 Localidade a usar.  
  
## <a name="return-value"></a>Valor de retorno  
 Cada uma dessas rotinas retornará um valor diferente de zero se o caractere satisfizer a condição de teste ou 0 se não satisfizer. Se `c`<= 255 e houver uma rotina `_ismbb` correspondente (por exemplo, `_ismbcalnum` corresponder a `_ismbbalnum`), o resultado será o valor retornado da rotina `_ismbb` correspondente.  
  
## <a name="remarks"></a>Comentários  
 Cada uma dessas funções testa um determinado caractere multibyte quanto a uma determinada condição.  
  
 As versões dessas funções com o sufixo `_l` são idênticas, exceto por usarem a localidade passada em vez da localidade atual para seu comportamento que depende da localidade. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
|Rotina|Condição de teste|Exemplo da página de código 932|  
|-------------|--------------------|---------------------------|  
|`_ismbclegal`|Multibyte válido|Retornará um valor diferente de zero se e somente se o primeiro byte de `c` estiver dentro dos intervalos 0x81 – 0x9F ou 0xE0 – 0xFC, enquanto o segundo byte estiver dentro dos intervalos 0x40 – 0x7E ou 0x80 – FC.|  
|`_ismbcsymbol`|Símbolo multibyte|Retorna um valor diferente de zero se e somente se 0x8141<=`c`<=0x81AC.|  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_istlegal`|Sempre retorna falso|`_ismbclegal`|Sempre retorna falso.|  
|`_istlegal_l`|Sempre retorna falso|`_ismbclegal_l`|Sempre retorna falso.|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_ismbclegal,_ismbclegal_l`|\<mbstring.h>|  
|`_ismbcsymbol,_ismbcsymbol_l`|\<mbstring.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Classificação de caracteres](../../c-runtime-library/character-classification.md)   
 [Rotinas _ismbc](../../c-runtime-library/ismbc-routines.md)   
 [Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)   
 [Rotinas _ismbb](../../c-runtime-library/ismbb-routines.md)
