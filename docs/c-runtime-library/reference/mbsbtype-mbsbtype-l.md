---
title: _mbsbtype, _mbsbtype_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _mbsbtype_l
- _mbsbtype
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
- mbsbtype
- mbsbtype_l
- _mbsbtype_l
- _mbsbtype
dev_langs: C++
helpviewer_keywords:
- _mbsbtype function
- mbsbtype function
- _mbsbtype_l function
- mbsbtype_l function
ms.assetid: 0d5dd91a-d32d-4f98-ac57-98dfc9e98eac
caps.latest.revision: "19"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 05c106136c36d09b06e5b168a0c582b87c306d93
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="mbsbtype-mbsbtypel"></a>_mbsbtype, _mbsbtype_l
Retorna o tipo de byte em uma cadeia de caracteres.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, consulte [Funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _mbsbtype(  
   const unsigned char *mbstr,  
   size_t count   
);  
int _mbsbtype_l(  
   const unsigned char *mbstr,  
   size_t count,  
   _locale_t locale   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `mbstr`  
 Endereço de uma sequência de caracteres multibyte.  
  
 `count`  
 Deslocamento do byte do início da cadeia de caracteres.  
  
 `locale`  
 Localidade a usar.  
  
## <a name="return-value"></a>Valor de retorno  
 `_mbsbtype`e `_mbsbtype_l` retorna um valor inteiro que indica o resultado do teste no byte especificado. As constantes de manifesto na tabela a seguir são definidas em Mbctype.h.  
  
|Valor retornado|Tipo de byte|  
|------------------|---------------|  
|`_MBC_SINGLE` (0)|Caractere de um byte. Por exemplo, na página de código 932, `_mbsbtype` retornará 0 se o byte especificado está dentro do intervalo 0x20-0x7E ou 0xA1 - 0xDF.|  
|`_MBC_LEAD` (1)|Byte inicial do caractere multibyte. Por exemplo, na página de código 932, `_mbsbtype` retornará 1 se o byte especificado está dentro do intervalo 0x81-0x9F ou 0xE0 - 0xFC.|  
|`_MBC_TRAIL` (2)|Byte à direita do caractere multibyte. Por exemplo, na página de código 932, `_mbsbtype` retorna 2 se o byte especificado está dentro do intervalo 0x40-0x7E ou 0x80 - 0xFC.|  
|`_MBC_ILLEGAL` (-1)|Cadeia de caracteres `NULL`, caractere inválido ou byte `NULL` encontrado antes do byte no deslocamento `count` em `mbstr`.|  
  
## <a name="remarks"></a>Comentários  
 A função `_mbsbtype` determina o tipo de um byte em uma cadeia de caracteres multibyte. A função examina somente os bytes no deslocamento `count` no `mbstr`, ignorando os caracteres inválidos antes do byte especificado.  
  
 O valor de saída é afetado pela configuração da categoria `LC_CTYPE` da localidade; consulte [setlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md) para obter mais informações. A versão dessa função sem o sufixo `_l` usa a localidade atual desse comportamento dependente da localidade. A versão com o sufixo `_l` é idêntica, exceto por usar o parâmetro de localidade passado em seu lugar. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Se a cadeia de caracteres de entrada for `NULL`, o manipulador de parâmetro inválido será invocado, como descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, `errno` será definido como `EINVAL` e a função retornará `_MBC_ILLEGAL`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|-------------|---------------------|---------------------|  
|`_mbsbtype`|\<mbstring.h>|\<mbctype.h>*|  
|`_mbsbtype_l`|\<mbstring.h>|\<mbctype.h>*|  
  
 \* Para constantes de manifesto usadas como valores retornados.  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Classificação de byte](../../c-runtime-library/byte-classification.md)