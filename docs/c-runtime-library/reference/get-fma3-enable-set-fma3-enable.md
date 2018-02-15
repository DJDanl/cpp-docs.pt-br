---
title: _get_FMA3_enable, _set_FMA3_enable | Microsoft Docs
ms.custom: 
ms.date: 6/13/2017
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _get_FMA3_enable
- _set_FMA3_enable
apilocation:
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
- api-ms-win-crt-runtime-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _get_FMA3_enable
- _set_FMA3_enable
- math/_get_FMA3_enable
- math/_set_FMA3_enable
dev_langs:
- C++
helpviewer_keywords:
- _get_FMA3_enable
- _set_FMA3_enable
ms.assetid: 4c1dc4bc-e86b-451b-9211-5a2ba6c98ee4
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4875306575d58b1baf341a5ed3c2a919c995c704
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="getfma3enable-setfma3enable"></a>_get_FMA3_enable, _set_FMA3_enable
Obtém ou define um sinalizador que especifica se as funções de ponto flutuante de biblioteca de matemática transcendentais usarem FMA3 instruções no código compilado para X64 plataformas.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _set_FMA3_enable(int flag);
int _get_FMA3_enable();
```  
  
### <a name="parameters"></a>Parâmetros
*flag*  
Definido como 1 para habilitar as implementações de FMA3 das funções de ponto flutuante de biblioteca de matemática transcendentais em X64 plataformas, ou 0 para usar as implementações que não usam FMA3 instruções.
  
## <a name="return-value"></a>Valor de retorno  
Um valor diferente de zero, se as implementações de FMA3 das funções de ponto flutuante de biblioteca de matemática transcendentais estiverem habilitadas. Caso contrário, zero.  
  
## <a name="remarks"></a>Comentários  
Use o `_set_FMA3_enable` função para habilitar ou desabilitar o uso de instruções FMA3 as funções de ponto flutuante de matemática transcendentais na biblioteca do CRT. O valor de retorno reflete a implementação em uso depois da alteração. Se a CPU não dá suporte a instruções FMA3, essa função não pode habilitá-las na biblioteca, e o valor de retorno é zero. Use `_get_FMA3_enable` para obter o estado atual da biblioteca. Por padrão, em X64 plataformas, o código de inicialização do CRT detecta se a CPU dá suporte a instruções FMA3 e habilita ou desabilita as implementações de FMA3 na biblioteca.
  
Como as implementações de FMA3 usam algoritmos diferentes, pequenas diferenças no resultado de cálculos podem ser observável quando as implementações de FMA3 estão habilitadas ou desabilitadas, ou entre os computadores que não oferecem suporte a FMA3 ou. Para obter mais informações, consulte [problemas de migração de ponto flutuante](../../porting/floating-point-migration-issues.md).

## <a name="requirements"></a>Requisitos  
  
O `_set_FMA3_enable` e `_get_FMA3_enable` funções estão disponíveis somente em X64 versões do CRT.  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_set_FMA3_enable` <br /><br /> `_get_FMA3_enable`| C: \<math.h><br /><br /> C++: \<cmath > ou \<math.h >|  
  
As funções `_set_FMA3_enable` e `_get_FMA3_enable` são específicas da Microsoft. Para obter informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)
[problemas de migração de ponto flutuante](../../porting/floating-point-migration-issues.md)  