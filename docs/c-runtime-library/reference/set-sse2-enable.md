---
title: _set_SSE2_enable | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _set_SSE2_enable
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
- api-ms-win-crt-math-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _set_SSE2_enable
- set_SSE2_enable
dev_langs:
- C++
helpviewer_keywords:
- _set_SSE2_enable function
- Streaming SIMD Extensions 2 instructions
- set_SSE2_enable function
ms.assetid: 55db895d-fc1e-475a-9110-b781a9bb51c5
caps.latest.revision: 19
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 158ce2d16db5a37870ea55c548796d975065f422
ms.lasthandoff: 02/25/2017

---
# <a name="setsse2enable"></a>_set_SSE2_enable
Habilita ou desabilita o uso de instruções SSE2 ([Extensões SIMD de Streaming 2](http://msdn.microsoft.com/en-us/f98440eb-73a9-4f96-b203-ac41bb6701ea)) em rotinas de matemática CRT. (Esta função não está disponível em arquiteturas x64 porque SSE2 está habilitado por padrão.)  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _set_SSE2_enable(  
   int flag  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `flag`  
 1 para habilitar a implementação SSE2; 0 para desabilitar a implementação SSE2. Por padrão, a implementação SSE2 está habilitada nos processadores que dão suporte a ela.  
  
## <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a implementação de SSE2 está habilitada; zero se SSE2 implementação está desabilitada.  
  
## <a name="remarks"></a>Comentários  
 As seguintes funções têm implementações SSE2 que podem ser habilitadas usando `_set_SSE2_enable`:  
  
-   [atan](../../c-runtime-library/reference/atan-atanf-atanl-atan2-atan2f-atan2l.md)  
  
-   [ceil](../../c-runtime-library/reference/ceil-ceilf-ceill.md)  
  
-   [exp](../../c-runtime-library/reference/exp-expf.md)  
  
-   [floor](../../c-runtime-library/reference/floor-floorf-floorl.md)  
  
-   [log](../../c-runtime-library/reference/log-logf-log10-log10f.md)  
  
-   [log10](../../c-runtime-library/reference/log-logf-log10-log10f.md)  
  
-   [modf](../../c-runtime-library/reference/modf-modff-modfl.md)  
  
-   [pow](../../c-runtime-library/reference/pow-powf-powl.md)  
  
 As implementações de SSE2 dessas funções podem gerar respostas um pouco diferentes que as implementações padrão porque valores intermediários SSE2 são as quantidades de ponto flutuante de 64 bits, mas os valores intermediários de implementação padrão são quantidades de ponto flutuante de 80 bits.  
  
> [!NOTE]
>  Se você usar a opção do compilador [/Oi (gerar funções intrínsecas)](../../build/reference/oi-generate-intrinsic-functions.md) para compilar o projeto, poderá parecer que `_set_SSE2_enable` não tem nenhum efeito. A opção do compilador `/Oi` concede ao compilador a autoridade para usar intrínsecos para substituir chamadas CRT; esse comportamento substitui o efeito de `_set_SSE2_enable`. Se você quiser assegurar que `/Oi` não substitua `_set_SSE2_enable`, deverá usar `/Oi-` para compilar seu projeto. Isso também pode ser uma boa prática ao usar outros comutadores do compilador que impliquem em `/Oi`.  
  
 A implementação de SSE2 é usada apenas se todas as exceções estão mascaradas. Use [_control87, _controlfp](../../c-runtime-library/reference/control87-controlfp-control87-2.md) para mascarar exceções.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_set_SSE2_enable`|\<math.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_set_SSE2_enable.c  
// processor: x86  
#include <math.h>  
#include <stdio.h>  
  
int main()  
{  
   int i = _set_SSE2_enable(1);  
  
   if (i)  
      printf("SSE2 enabled.\n");  
   else  
      printf("SSE2 not enabled; processor does not support SSE2.\n");  
}  
```  
  
 **Saída**  
  
 `SSE2 enabled.`  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).  
  
## <a name="see-also"></a>Consulte também  
 [Recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md)
