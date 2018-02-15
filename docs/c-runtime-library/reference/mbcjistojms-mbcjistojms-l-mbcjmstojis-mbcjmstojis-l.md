---
title: _mbcjistojms, _mbcjistojms_l, _mbcjmstojis, _mbcjmstojis_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _mbcjistojms
- _mbcjmstojis
- _mbcjistojms_l
- _mbcjmstojis_l
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
- mbcjistojms
- _mbcjistojms
- _mbcjistojms_l
- _mbcjmstojis_l
- _mbcjmstojis
- mbcjmstojis_l
- mbcjistojms_l
- mbcjmstojis
dev_langs:
- C++
helpviewer_keywords:
- _mbcjmstojis_l function
- _mbcjistojms function
- mbcjmstojis function
- _mbcjistojms_l function
- _mbcjmstojis function
- mbcjistojms function
- mbcjmstojis_l function
- mbcjistojms_l function
ms.assetid: dece5127-b337-40a4-aa10-53320a2c9432
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a5d4d77f82a4d23093446f24c80b2c7eb9cb29c1
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="mbcjistojms-mbcjistojmsl-mbcjmstojis-mbcjmstojisl"></a>_mbcjistojms, _mbcjistojms_l, _mbcjmstojis, _mbcjmstojis_l
Converte entre caracteres JIS (Japan Industry Standard) e JMS (Japan Microsoft).  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, consulte [funções de CRT sem suporte em aplicativos de plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
unsigned int _mbcjistojms(  
   unsigned int c   
);  
unsigned int _mbcjistojms_l(  
   unsigned int c,  
   _locale_t locale  
);  
unsigned int _mbcjmstojis(  
   unsigned int c   
);  
unsigned int _mbcjmstojis_l(  
   unsigned int c,  
   _locale_t locale  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `c`  
 Caractere a ser convertido.  
  
 `local`  
 Localidade a usar.  
  
## <a name="return-value"></a>Valor de retorno  
 No Japão, essas funções retornarão um caractere convertido ou retornam 0 se nenhuma conversão for possível. Em uma localidade não japonesa, essas funções retornam o caractere passado.  
  
## <a name="remarks"></a>Comentários  
 A função `_mbcjistojms` converte um caractere JIS (Japan Industry Standard) em um caractere de Kanji Microsoft (Shift JIS). O caractere é convertido somente se o cliente potencial e trilha bytes estão no intervalo 0x21 - 0x7E. Se o byte inicial ou final estiver fora desse intervalo, `errno` será definido como `EILSEQ`. Para obter mais informações sobre esse e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
 O `_mbcjmstojis` função converte um caractere Shift JIS um caractere JIS. O caractere é convertido somente se o byte inicial estiver no intervalo 0x81-0x9F ou 0xE0 - 0xFC e o byte final está no intervalo 0x40-0x7E ou 0x80 - 0xFC. Observe que alguns pontos de código nesse intervalo não têm um caractere atribuído e, portanto, não podem ser convertidos.  
  
 O valor `c` deve ser um valor de 16 bits cujos 8 bits superiores representam o byte inicial do caractere a ser convertido e cujos 8 bits inferiores representem o byte final.  
  
 O valor de saída é afetado pela configuração da categoria `LC_CTYPE` da localidade; consulte [setlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções sem o sufixo `_l` usam a localidade atual desse comportamento dependente da localidade. As versões com o sufixo `_l` são idênticas, exceto por usarem o parâmetro de localidade passado em seu lugar. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Em versões anteriores, `_mbcjistojms` e `_mbcjmstojis` chamadas `jistojms` e `jmstojis`, respectivamente. `_mbcjistojms`, `_mbcjistojms_l`, `_mbcjmstojis` e `_mbcjmstojis_l` deve ser usado em vez disso.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_mbcjistojms`|\<mbstring.h>|  
|`_mbcjistojms_l`|\<mbstring.h>|  
|`_mbcjmstojis`|\<mbstring.h>|  
|`_mbcjmstojis_l`|\<mbstring.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Conversão de Dados](../../c-runtime-library/data-conversion.md)   
 [Rotinas _ismbb](../../c-runtime-library/ismbb-routines.md)