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
ms.openlocfilehash: cb436acae117c78bfa5c752b905bd3f4f910e9da
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45707844"
---
# <a name="masm-macros"></a>Macros MASM

Para simplificar o uso do [pseudo-operações brutas](../build/raw-pseudo-operations.md), há um conjunto de macros, definidas em ksamd64.inc, que pode ser usado para criar o procedimento típico Prólogos e epílogos.

## <a name="remarks"></a>Comentários

|Macro|Descrição|
|-----------|-----------------|
|alloc_stack(n)|Aloca um quadro de pilha de n bytes (usando rsp sub, n) e emite informações (. allocstack n) de desenrolamento apropriado|
|reg save_reg, loc|Salva um registro não volátil reg na pilha no RSP loc de deslocamento e emite informações de desenrolamento apropriado. (reg. savereg, loc)|
|reg push_reg|Envia um registro não volátil reg na pilha e emite informações de desenrolamento apropriado. (reg. pushreg)|
|reg rex_push_reg|Salvar um registro não volátil na pilha usando um envio por push de 2 bytes e emite informações (reg. pushreg), isso deve ser usado se o envio por push for a primeira instrução na função para garantir que a função é para patch a quente de desenrolamento apropriado.|
|reg save_xmm128, loc|Salva um não-volátil registrar registros de MMX reg na pilha no RSP loc de deslocamento e emite informações (reg. savexmm128, loc) de desenrolamento apropriado|
|reg set_frame, deslocamento|Define o reg de registro de quadro para ser o RSP + deslocamento (usando um mov ou um sal) e emite informações (reg .set_frame, deslocamento) de desenrolamento apropriado|
|push_eflags|Envia por push o eflags com uma instrução de pushfq e emite informações (.alloc_stack 8) de desenrolamento apropriado|

Aqui está um prólogo da função de exemplo com o uso correto das macros:

```asm
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