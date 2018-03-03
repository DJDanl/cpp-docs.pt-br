---
title: Usando e preservando registros em Assembly embutido | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- __asm keyword [C++], register values
- inline assembly, registers
- registers, inline assembly
- preserving registers
ms.assetid: dbcd7360-6f3e-4b22-9ee2-9f65ca6f2543
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 66805c6e9331f55beb01b13a536596c53e35049c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="using-and-preserving-registers-in-inline-assembly"></a>Usando e preservando registros no assembly embutido
## <a name="microsoft-specific"></a>Específico da Microsoft  
 Em geral, você não deve presumir que um registro terá um valor fornecido quando uma `__asm` bloco começa. Não há garantia de valores do registro a serem preservados em separado `__asm` blocos. Se você encerrar um bloco de código em linha e começar a outro, você não pode depender registra no segundo bloco para reter os valores do primeiro bloco. Um `__asm` bloco herda tudo o que registrar resultado de valores de fluxo de controle normal.  
  
 Se você usar o `__fastcall` convenção de chamada, o compilador passa os argumentos de função nos registros em vez de na pilha. Isso pode criar problemas em funções com `__asm` bloqueia porque uma função não tem como saber qual parâmetro está na qual registrar. Se a função ocorre receber um parâmetro em EAX e armazena algo em EAX imediatamente, o parâmetro original será perdido. Além disso, você deve preservar o registro ECX em qualquer função declarada com `__fastcall`.  
  
 Para evitar tais conflitos de registro, não use o `__fastcall` convenção para as funções que contêm um `__asm` bloco. Se você especificar o `__fastcall` convenção globalmente com a opção de compilador /Gr, declare que cada função contém um `__asm` bloco com `__cdecl` ou `__stdcall`. (O `__cdecl` atributo informa ao compilador para usar a convenção de chamada de C para essa função.) Se você não está compilando com /Gr, evite a declarar a função com o `__fastcall` atributo.  
  
 Ao usar `__asm` para gravar a linguagem de assembly em funções de C/C++, você não precisa preservar os registros EAX, EBX, ECX, EDX, ESI ou EDI. Por exemplo, em POWER2. Exemplo C [escrever funções com Assembly embutido](../../assembler/inline/writing-functions-with-inline-assembly.md), o `power2` função não preserva o valor no registro EAX. No entanto, usar esses registros afetará a qualidade do código porque o alocador de registro não pode usar para armazenar valores de `__asm` blocos. Além disso, usando EBX, ESI ou EDI no código de assembly embutido, forçar o compilador para salvar e restaurar esses registros no prólogo de função e epílogo.  
  
 Você deve preservar outros registros que você usar (por exemplo, DS, SS, SP, BP e registros de sinalizadores) para o escopo de `__asm` bloco. Você deve preservar os registros ESP e EBP a menos que você tenha alguma razão para alterá-los (para alternar pilhas, por exemplo). Consulte também [otimizando embutido Assembly](../../assembler/inline/optimizing-inline-assembly.md).  
  
 Alguns tipos de SSE exigem o alinhamento de pilha de oito bytes, forçando o compilador emitir código dinâmico de alinhamento de pilha. Para poder acessar as variáveis locais e os parâmetros de função após o alinhamento, o compilador mantém dois ponteiros do quadro.  Se o compilador executa omissão do ponteiro de quadro (FPO), ele usará EBP e ESP.  Se o compilador não executar FPO, ele usará EBX e EBP. Para garantir o código é executado corretamente, não modifique EBX no código asm se a função requer alinhamento de pilha dinâmico como ele poderia modificar o ponteiro de quadro. Mova os tipos de oito bytes alinhados sairá da função ou evite usar EBX.  
  
> [!NOTE]
>  Se seu código de assembly embutido altera o sinalizador de direção usando as instruções STD ou CLD, você deve restaurar o sinalizador para seu valor original.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Assembler embutido](../../assembler/inline/inline-assembler.md)