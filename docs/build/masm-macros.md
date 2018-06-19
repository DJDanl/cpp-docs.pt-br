---
title: Macros MASM | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 21410432-72fc-4795-bc93-e78123f9f14f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 403220306a2585b1506a990664eaa2ec8f2ac1a3
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32368688"
---
# <a name="masm-macros"></a>Macros MASM
Para simplificar o uso do [Pseudo-operações brutas](../build/raw-pseudo-operations.md), há um conjunto de macros, definido em ksamd64.inc, que pode ser usado para criar Prólogos procedimento típico e epilogues.  
  
## <a name="remarks"></a>Comentários  
  
|Macro|Descrição|  
|-----------|-----------------|  
|alloc_stack(n)|Aloca um quadro de pilha de n bytes (usando rsp sub, n) e emite apropriada desenrolar informações (n. allocstack)|  
|save_reg reg, loc|Salva um registro não volátil reg na pilha em loc deslocamento RSP e emite informações sobre o desenrolamento apropriada. (reg. savereg, loc)|  
|push_reg reg|Envia um registro não volátil reg na pilha e emite informações sobre o desenrolamento apropriada. (reg. pushreg)|  
|rex_push_reg reg|Salvar um registro não volátil na pilha usando um envio por push de 2 bytes e emite apropriada desenrolar informações (reg. pushreg), isso deve ser usado se o envio por push é a primeira instrução na função para garantir que a função é para patch a quente.|  
|save_xmm128 reg, loc|Salva um não volátil XMM registrar reg na pilha em loc deslocamento RSP e emite apropriada desenrolar informações (reg. savexmm128, loc)|  
|set_frame reg, deslocamento|Define o reg de registro de quadro para ser o RSP + deslocamento (usando um mov ou um sal) e emite apropriada desenrolar informações (.set_frame reg, deslocamento)|  
|push_eflags|Envia o eflags com uma instrução pushfq e emite apropriada desenrolar informações (.alloc_stack 8)|  
  
 Aqui está um prólogo da função de exemplo com o uso correto de macros:  
  
```  
SkFrame struct   
Fill    dq ?; fill to 8 mod 16   
SavedRdi dq ?; saved register RDI   
SavedRsi dq ?; saved register RSI   
SkFrame ends  
  
sampleFrame struct  
Filldq?; fill to 8 mod 16  
SavedRdidq?; Saved Register RDI   
SavedRsi  dq?; Saved Register RSI  
sampleFrame ends  
  
sample2 PROC FRAME  
alloc_stack(sizeof sampleFrame)  
save_reg rdi, sampleFrame.SavedRdi  
save_reg rsi, sampleFrame.SavedRsi  
.end_prolog  
  
; function body  
  
mov rsi, sampleFrame.SavedRsi[rsp]  
mov rdi, sampleFrame.SavedRdi[rsp]  
  
; Here’s the official epilog  
  
add rsp, (sizeof sampleFrame)  
ret  
sample2 ENDP  
```  
  
## <a name="see-also"></a>Consulte também  
 [Desenrolar auxiliares para MASM](../build/unwind-helpers-for-masm.md)