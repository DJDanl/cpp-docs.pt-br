---
title: Usando e preservando registros no assembly embutido
ms.date: 08/30/2018
helpviewer_keywords:
- __asm keyword [C++], register values
- inline assembly, registers
- registers, inline assembly
- preserving registers
ms.assetid: dbcd7360-6f3e-4b22-9ee2-9f65ca6f2543
ms.openlocfilehash: 97db09ac7652c00e9599a6938f4114de080906c0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81318023"
---
# <a name="using-and-preserving-registers-in-inline-assembly"></a>Usando e preservando registros no assembly embutido

**Específico da Microsoft**

Em geral, você não deve assumir que um `__asm` registro terá um determinado valor quando um bloco começar. Os valores de registro não `__asm` são garantidos para serem preservados em blocos separados. Se você terminar um bloco de código inline e começar outro, você não poderá contar com os registros do segundo bloco para reter seus valores do primeiro bloco. Um `__asm` bloco herda os valores do registro resultantes do fluxo normal de controle.

Se você `__fastcall` usar a convenção de chamada, o compilador passa argumentos de função em registros em vez de na pilha. Isso pode criar problemas `__asm` em funções com blocos porque uma função não tem como dizer qual parâmetro está em qual registro. Se a função receber um parâmetro no EAX e armazena imediatamente outra coisa no EAX, o parâmetro original será perdido. Além disso, você deve preservar o registro ECX em qualquer função declarada com `__fastcall`.

Para evitar tais conflitos de registro, não use `__fastcall` a `__asm` convenção para funções que contenham um bloco. Se você `__fastcall` especificar a convenção globalmente com a opção /Gr `__asm` compilador, declare todas as funções que contenham um bloco com `__cdecl` ou `__stdcall`. (O `__cdecl` atributo diz ao compilador para usar a convenção de chamada C para essa função.) Se você não estiver compilando com /Gr, `__fastcall` evite declarar a função com o atributo.

Ao `__asm` usar para escrever a linguagem de montagem em funções C/C++, você não precisa preservar os registros EAX, EBX, ECX, EDX, ESI ou EDI. Por exemplo, no POWER2. Exemplo C em [Funções de escrita com conjunto inline,](../../assembler/inline/writing-functions-with-inline-assembly.md)a `power2` função não preserva o valor no registro EAX. No entanto, o uso desses registros afetará a qualidade do `__asm` código porque o alocador de registro não pode usá-los para armazenar valores entre blocos. Além disso, usando EBX, ESI ou EDI em código de montagem inline, você força o compilador a salvar e restaurar esses registros no prólogo e epílogo da função.

Você deve preservar outros registros que você usa (como Registros de DS, SS, `__asm` SP, BP e sinalizadores) para o escopo do bloco. Você deve preservar os registros ESP e EBP, a menos que você tenha alguma razão para alterá-los (para alternar pilhas, por exemplo). Veja também [a otimização da montagem inline](../../assembler/inline/optimizing-inline-assembly.md).

Alguns tipos de SSE requerem alinhamento de pilha de oito bytes, forçando o compilador a emitir código dinâmico de alinhamento de pilhas. Para poder acessar as variáveis locais e os parâmetros de função após o alinhamento, o compilador mantém dois ponteiros de quadro.  Se o compilador realizar a omissão do ponteiro de quadros (FPO), ele usará EBP e ESP.  Se o compilador não executar FPO, ele usará EBX e EBP. Para garantir que o código seja executado corretamente, não modifique o EBX no código asm se a função exigir alinhamento dinâmico da pilha, pois poderia modificar o ponteiro do quadro. Ou mova os tipos alinhados de oito bytes para fora da função ou evite usar o EBX.

> [!NOTE]
> Se o código de montagem em linha mudar o sinalizador de direção usando as instruções STD ou CLD, você deve restaurar o sinalizador ao seu valor original.

**Fim específico da Microsoft**

## <a name="see-also"></a>Confira também

[Montador Inline](../../assembler/inline/inline-assembler.md)<br/>
