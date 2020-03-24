---
title: Usando e preservando registros no assembly embutido
ms.date: 08/30/2018
helpviewer_keywords:
- __asm keyword [C++], register values
- inline assembly, registers
- registers, inline assembly
- preserving registers
ms.assetid: dbcd7360-6f3e-4b22-9ee2-9f65ca6f2543
ms.openlocfilehash: 51147a217ec56c525fc01e1b36a9381b9356ba4d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80169149"
---
# <a name="using-and-preserving-registers-in-inline-assembly"></a>Usando e preservando registros no assembly embutido

**Seção específica da Microsoft**

Em geral, você não deve supor que um registro terá um determinado valor quando um bloco de `__asm` começar. Não há garantia de que os valores de registro sejam preservados em blocos de `__asm` separados. Se você terminar um bloco de código embutido e começar outro, não poderá contar com os registros no segundo bloco para manter seus valores do primeiro bloco. Um bloco de `__asm` herda quaisquer valores de registro resultantes do fluxo de controle normal.

Se você usar a Convenção de chamada `__fastcall`, o compilador passará argumentos de função em registros em vez de na pilha. Isso pode criar problemas em funções com blocos de `__asm` porque uma função não tem como saber qual parâmetro é o registro. Se a função for receber um parâmetro no EAX e imediatamente armazenar outra coisa no EAX, o parâmetro original será perdido. Além disso, você deve preservar o Registro ECX em qualquer função declarada com `__fastcall`.

Para evitar esses conflitos de registro, não use a Convenção de `__fastcall` para funções que contêm um bloco de `__asm`. Se você especificar a Convenção de `__fastcall` globalmente com a opção de compilador/gr, declare cada função que contém um bloco de `__asm` com `__cdecl` ou `__stdcall`. (O atributo `__cdecl` informa ao compilador para usar a Convenção de chamada C para essa função.) Se você não estiver Compilando com/gr, evite declarar a função com o atributo `__fastcall`.

Ao usar `__asm` para gravar linguagem de assembly em CC++ /functions, você não precisa preservar os registros EAX, EBX, ecx, EDX, ESI ou EDI. Por exemplo, no POWER2. O exemplo C na [gravação de funções com assembly embutido](../../assembler/inline/writing-functions-with-inline-assembly.md), a função `power2` não preserva o valor no registro EAX. No entanto, o uso desses registros afetará a qualidade do código, pois o alocador de registro não pode usá-los para armazenar valores em blocos de `__asm`. Além disso, usando EBX, ESI ou EDI no código de assembly embutido, você força o compilador a salvar e restaurar esses registros no prólogo da função e epílogo.

Você deve preservar outros registros que usar (como registros DS, SS, SP, BP e flags) para o escopo do bloco de `__asm`. Você deve preservar os registros ESP e EBP, a menos que tenha algum motivo para alterá-los (para alternar as pilhas, por exemplo). Consulte também [otimizando assembly embutido](../../assembler/inline/optimizing-inline-assembly.md).

Alguns tipos de SSE exigem alinhamento de pilha de oito bytes, forçando o compilador a emitir o código de alinhamento de pilha dinâmico. Para poder acessar as variáveis locais e os parâmetros de função após o alinhamento, o compilador mantém dois ponteiros de quadro.  Se o compilador executar a omissão de ponteiros de quadro (FPO), ele usará EBP e ESP.  Se o compilador não executar FPO, ele usará EBX e EBP. Para garantir que o código seja executado corretamente, não modifique o EBX no código ASM se a função exigir alinhamento de pilha dinâmica, pois ele poderia modificar o ponteiro do quadro. Mova os tipos alinhados de oito bytes para fora da função ou Evite usar EBX.

> [!NOTE]
>  Se o código de assembly embutido alterar o sinalizador de direção usando as instruções padrão ou CLD, você deverá restaurar o sinalizador para seu valor original.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Assembler embutido](../../assembler/inline/inline-assembler.md)<br/>
