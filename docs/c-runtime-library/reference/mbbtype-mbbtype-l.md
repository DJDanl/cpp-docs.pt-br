---
title: _mbbtype, _mbbtype_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _mbbtype
- _mbbtype_l
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
- _mbbtype_l
- mbbtype
- mbbtype_l
- _mbbtype
dev_langs:
- C++
helpviewer_keywords:
- _mbbtype function
- _mbbtype_l function
- mbbtype function
- mbbtype_l function
ms.assetid: b8e34b40-842a-4298-aa39-0bd2d8e51c2a
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
ms.openlocfilehash: e7b9c7aed7205e6cac428a0f627525f9484afc5a
ms.contentlocale: pt-br
ms.lasthandoff: 04/01/2017

---
# <a name="mbbtype-mbbtypel"></a>_mbbtype, _mbbtype_l
Retorna o tipo de byte, com base no byte anterior.  
  
> [!IMPORTANT]
>  Essa API não pode ser usada em aplicativos executados no [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)]. Para obter mais informações, consulte [Funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _mbbtype(  
   unsigned char c,  
   int type   
);  
int _mbbtype_l(  
   unsigned char c,  
   int type,  
   _locale_t locale  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `c`  
 O caractere a ser testado.  
  
 `type`  
 O tipo de byte para o qual testar.  
  
 `locale`  
 A localidade a ser usada.  
  
## <a name="return-value"></a>Valor de retorno  
 O `_mbbtype` retorna o tipo de byte em uma cadeia de caracteres. Essa decisão é contextual, conforme especificado pelo valor de `type`, que fornece a condição de teste do controle. `type` é o tipo do byte anterior na cadeia de caracteres. As constantes de manifesto na tabela a seguir são definidas em Mbctype.h.  
  
|Valor de `type`|O `_mbbtype` testa para|Valor retornado|`c`|  
|---------------------|--------------------------|------------------|---------|  
|Qualquer valor exceto 1|Byte único ou byte inicial válido|`_MBC_SINGLE` (0)|Byte único (0x20 - 0x7E, 0xA1 - 0xDF)|  
|Qualquer valor exceto 1|Byte único ou byte inicial válido|`_MBC_LEAD` (1)|Levar bytes de caracteres multibyte (0x81 - 0x9F, 0xE0 - 0xFC)|  
|Qualquer valor exceto 1|Byte único ou byte inicial válido|`_MBC_ILLEGAL`<br /><br /> ( -1)|Caractere inválido (qualquer valor exceto 0x20 - 0x7E, 0xA1 - 0xDF, 0x81 - 0x9F, 0xE0 - 0xFC|  
|1|Byte final válido|`_MBC_TRAIL` (2)|À direita de bytes de caracteres multibyte (0x40 - 0x7E, 0x80 - 0xFC)|  
|1|Byte final válido|`_MBC_ILLEGAL`<br /><br /> ( -1)|Caractere inválido (qualquer valor exceto 0x20 - 0x7E, 0xA1 - 0xDF, 0x81 - 0x9F, 0xE0 - 0xFC|  
  
## <a name="remarks"></a>Comentários  
 A função `_mbbtype` determina o tipo de um byte em um caractere multibyte. Se o valor de `type` for qualquer valor exceto 1, `_mbbtype` testará para um byte único ou byte inicial de um caractere multibyte. Se o valor de `type` for 1, `_mbbtype` testará para um byte final válido de um caractere multibyte.  
  
 O valor de saída é afetado pela configuração da categoria `LC_CTYPE` da localidade. Consulte [setlocale, _wsetlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md) para obter mais informações. A versão `_mbbtype` dessa função usa a localidade atual desse comportamento dependente da localidade. A versão `_mbbtype_l` é idêntica, exceto por usar o parâmetro de localidade passado em seu lugar. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Em versões anteriores, `_mbbtype` era chamado `chkctype`. Para códigos novos, use `_mbbtype`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|-------------|---------------------|---------------------|  
|`_mbbtype`|\<mbstring.h>|\<mbctype.h>*|  
|`_mbbtype_l`|\<mbstring.h>|\<mbctype.h>*|  
  
 \* Para obter definições de constantes de manifesto que são usadas como valores retornados.  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Classificação de byte](../../c-runtime-library/byte-classification.md)
