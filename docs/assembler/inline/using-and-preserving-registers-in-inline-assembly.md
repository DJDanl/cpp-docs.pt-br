---
title: Usando e preservando registros no assembly embutido
ms.date: 08/30/2018
helpviewer_keywords:
- __asm keyword [C++], register values
- inline assembly, registers
- registers, inline assembly
- preserving registers
ms.assetid: dbcd7360-6f3e-4b22-9ee2-9f65ca6f2543
ms.openlocfilehash: 99ca0093bb27e859854dfd1ca64addea923e5a5c
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87191502"
---
# <a name="using-and-preserving-registers-in-inline-assembly"></a>Usando e preservando registros no assembly embutido

**Específico da Microsoft**

Em geral, você não deve supor que um registro terá um determinado valor quando um **`__asm`** bloco for iniciado. Não há garantia de que os valores de registro sejam preservados em **`__asm`** blocos separados. Se você terminar um bloco de código embutido e começar outro, não poderá contar com os registros no segundo bloco para manter seus valores do primeiro bloco. Um **`__asm`** bloco herda quaisquer valores de registro resultantes do fluxo de controle normal.

Se você usar a **`__fastcall`** Convenção de chamada, o compilador passará os argumentos da função em registros em vez de na pilha. Isso pode criar problemas em funções com **`__asm`** blocos, pois uma função não tem como saber qual parâmetro é o registro. Se a função for receber um parâmetro no EAX e imediatamente armazenar outra coisa no EAX, o parâmetro original será perdido. Além disso, você deve preservar o registro de ECX em qualquer função declarada com **`__fastcall`** .

Para evitar esses conflitos de registro, não use a **`__fastcall`** Convenção para funções que contêm um **`__asm`** bloco. Se você especificar a **`__fastcall`** Convenção globalmente com a opção de compilador/gr, declare cada função que contém um **`__asm`** bloco com **`__cdecl`** ou **`__stdcall`** . (O **`__cdecl`** atributo informa ao compilador para usar a Convenção de chamada C para essa função.) Se você não estiver Compilando com/gr, evite declarar a função com o **`__fastcall`** atributo.

Ao usar o **`__asm`** para gravar a linguagem do assembly em funções do C/C++, você não precisa preservar os registros EAX, EBX, ecx, EDX, ESI ou EDI. Por exemplo, no POWER2. O exemplo C em [gravando funções com assembly embutido](../../assembler/inline/writing-functions-with-inline-assembly.md), a `power2` função não preserva o valor no registro EAX. No entanto, o uso desses registros afetará a qualidade do código, pois o alocador de registro não pode usá-los para armazenar valores entre **`__asm`** blocos. Além disso, usando EBX, ESI ou EDI no código de assembly embutido, você força o compilador a salvar e restaurar esses registros no prólogo da função e epílogo.

Você deve preservar outros registros que usar (como registros DS, SS, SP, BP e flags) para o escopo do **`__asm`** bloco. Você deve preservar os registros ESP e EBP, a menos que tenha algum motivo para alterá-los (para alternar as pilhas, por exemplo). Consulte também [otimizando assembly embutido](../../assembler/inline/optimizing-inline-assembly.md).

Alguns tipos de SSE exigem alinhamento de pilha de oito bytes, forçando o compilador a emitir o código de alinhamento de pilha dinâmico. Para poder acessar as variáveis locais e os parâmetros de função após o alinhamento, o compilador mantém dois ponteiros de quadro.  Se o compilador executar a omissão de ponteiros de quadro (FPO), ele usará EBP e ESP.  Se o compilador não executar FPO, ele usará EBX e EBP. Para garantir que o código seja executado corretamente, não modifique o EBX no código ASM se a função exigir alinhamento de pilha dinâmica, pois ele poderia modificar o ponteiro do quadro. Mova os tipos alinhados de oito bytes para fora da função ou Evite usar EBX.

> [!NOTE]
> Se o código de assembly embutido alterar o sinalizador de direção usando as instruções padrão ou CLD, você deverá restaurar o sinalizador para seu valor original.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Assembler embutido](../../assembler/inline/inline-assembler.md)<br/>
