---
title: _set_SSE2_enable | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 424bdd9eed44f35b21a78b97b8e418f6c8a3c985
ms.sourcegitcommit: 185e11ab93af56ffc650fe42fb5ccdf1683e3847
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/29/2018
---
# <a name="setsse2enable"></a>_set_SSE2_enable
Habilita ou desabilita o uso de instruções de extensões Streaming SIMD 2 (SSE2) em rotinas de matemática CRT. (Esta função não está disponível em arquiteturas x64 porque SSE2 está habilitado por padrão.)  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md)