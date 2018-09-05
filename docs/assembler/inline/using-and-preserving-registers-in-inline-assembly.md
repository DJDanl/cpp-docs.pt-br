---
title: Usando e preservando registros no Assembly embutido | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- __asm keyword [C++], register values
- inline assembly, registers
- registers, inline assembly
- preserving registers
ms.assetid: dbcd7360-6f3e-4b22-9ee2-9f65ca6f2543
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 60506f53eb1933e5acbb03318edada82a8904386
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43677012"
---
# <a name="using-and-preserving-registers-in-inline-assembly"></a>Usando e preservando registros no assembly embutido

**Seção específica da Microsoft**

Em geral, você não deve presumir que um registro terá um determinado valor quando um `__asm` bloco começa. Valores do registro não são garantidos sejam preservados em separado `__asm` blocos. Se você encerrar um bloco de código embutido e iniciar outro, você não pode contar os registros no bloco de segunda a manter seus valores do primeiro bloco. Um `__asm` bloco herda tudo o que registrar resultado de valores de fluxo de controle normal.

Se você usar o `__fastcall` convenção de chamada, o compilador passa os argumentos de função em registros, em vez de na pilha. Isso pode criar problemas em funções com `__asm` bloqueia porque uma função não tem como saber qual parâmetro é no qual registrar. Se a função acontece receber um parâmetro no EAX e imediatamente armazena algo em EAX, o parâmetro original será perdido. Além disso, você deve preservar o registrador ecx em qualquer função declarada com `__fastcall`.

Para evitar tais conflitos de registro, não use o `__fastcall` convenção para as funções que contêm um `__asm` bloco. Se você especificar o `__fastcall` convenção globalmente com a opção de compilador /Gr, declare cada função que contém uma `__asm` bloco com `__cdecl` ou `__stdcall`. (O `__cdecl` atributo diz ao compilador para usar a convenção de chamada de C para essa função.) Se você não estiver compilando com /Gr, evite declarar a função com o `__fastcall` atributo.

Ao usar `__asm` para gravar a linguagem de assembly em funções do C/C++, você não precisa preservar os registros EAX, EBX, ECX, EDX, ESI ou EDI. Por exemplo, em POWER2. Exemplo C [escrevendo funções com Assembly embutido](../../assembler/inline/writing-functions-with-inline-assembly.md), o `power2` função não preserva o valor no registro de eax. No entanto, usar esses registros afetará a qualidade do código porque o alocador de registro não pode usar para armazenar os valores em `__asm` blocos. Além disso, usando EBX, ESI ou EDI no código de assembly embutido, forçar o compilador para salvar e restaurar esses registros no prólogo da função e do epílogo.

Você deve preservar a outros registros que você usar (por exemplo, DS, SS, SP, BP e registros de sinalizadores) para o escopo do `__asm` bloco. Você deve preservar os registros ESP e EBP, a menos que você tenha algum motivo para alterá-los (para alternar as pilhas de, por exemplo). Consulte também [otimizando o Assembly de embutido](../../assembler/inline/optimizing-inline-assembly.md).

Alguns tipos de SSE exigem o alinhamento de pilha de oito bytes, forçar o compilador emita um código dinâmico de alinhamento de pilha. Para ser capaz de acessar as variáveis locais e os parâmetros de função após o alinhamento, o compilador mantém dois ponteiros de quadro.  Se o compilador executa a omissão do ponteiro de quadro (FPO), ele usará EBP e ESP.  Se o compilador não executa FPO, ele usará o EBX e EBP. Para garantir que o código é executado corretamente, não modifique EBX no código do asm se a função exige alinhamento de pilha dinâmica conforme ele poderia modificar o ponteiro de quadro. Mova os tipos de oito bytes alinhados da função ou evitar o uso de EBX.

> [!NOTE]
>  Se seu código de assembly embutido for alterado usando as instruções STD ou CLD o sinalizador de direção, você deve restaurar o sinalizador para seu valor original.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Assembler embutido](../../assembler/inline/inline-assembler.md)<br/>