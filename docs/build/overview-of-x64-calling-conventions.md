---
title: Visão geral de convenções de chamada de x64
ms.date: 11/04/2016
ms.assetid: a05db5eb-0844-4d9d-8b92-b1b2434be0ea
ms.openlocfilehash: 37ba3c68310af938f382f88ab4f339166589b96b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50444184"
---
# <a name="overview-of-x64-calling-conventions"></a>Visão geral de convenções de chamada de x64

Duas diferenças importantes entre o x86 e x64 são a capacidade de endereçamento de 64 bits e um conjunto simples de 16 a 64-bit registra para uso geral. Dado o conjunto de registro expandida, x64 usa o [fastcall](../cpp/fastcall.md) convenção de chamada e um modelo de tratamento de exceções com base em RISC. O `__fastcall` convenção usa registros para os primeiros quatro argumentos e o quadro de pilha para passar argumentos adicionais.

A opção de compilador a seguir ajuda a otimizar o aplicativo para x64:

- [/favor (otimizar para especificações da arquitetura)](../build/reference/favor-optimize-for-architecture-specifics.md)

## <a name="calling-convention"></a>Convenção de chamada

X64 Interface binária do aplicativo (ABI) usa uma convenção de chamada de fast-chamada quatro registrar por padrão. Espaço é alocado na pilha de chamadas como um armazenamento de sombra para os receptores salvar esses registros. Há uma correspondência estrita entre os argumentos para uma chamada de função e os registros usados para esses argumentos. Qualquer argumento que não se encaixa em 8 bytes ou não é 1, 2, 4 ou 8 bytes, deve ser passado por referência. Não há nenhuma tentativa para distribuir um único argumento entre vários registros. X87 registro de pilha não é usada. Ele pode ser usado pelo receptor, mas deve ser considerado volátil em chamadas de função. Ponto flutuante de todas as operações são executadas usando a 16 registros XMM registra. Argumentos inteiros são passados nos registradores RCX, RDX, R8 e R9. Os argumentos são passados em XMM0L, XMM1L, XMM2L e XMM3L de ponto flutuante. argumentos de 16 bytes são passados por referência. Passar o parâmetro é descrito detalhadamente no [passagem de parâmetro](../build/parameter-passing.md). Além desses registros, XMM5, R10, R11, XMM4 e RAX são considerados voláteis. Todos os outros registros são não-volátil. Registrar uso está documentado em detalhes no [registrar o uso](../build/register-usage.md) e [chamador/receptor salvo registra](../build/caller-callee-saved-registers.md).

O chamador é responsável por alocar espaço para os parâmetros para o receptor e sempre deve alocar espaço suficiente para armazenar quatro parâmetros de registro, mesmo se o receptor não tem muitos parâmetros. Isso simplifica o suporte para funções da linguagem C sem protótipo e funções do C/C++ vararg. Para funções vararg ou unprototyped, qualquer ponto flutuante de valores deve ser duplicada no registro de uso geral correspondente. Todos os parâmetros além os quatro primeiros devem ser armazenados na pilha, acima o armazenamento de sombra para os quatro primeiros, antes da chamada. Detalhes da função vararg podem ser encontradas no [Varargs](../build/varargs.md). Informações de função sem protótipo são detalhadas na [funções sem protótipo](../build/unprototyped-functions.md).

## <a name="alignment"></a>Alinhamento

A maioria das estruturas são alinhadas com seu alinhamento natural. As principais exceções são o ponteiro de pilha e `malloc` ou `alloca` memória, que são alinhados com 16 bytes para ajudar o desempenho. Alinhamento acima de 16 bytes deve ser feito manualmente, mas como 16 bytes é um tamanho de alinhamento comum para operações de registros de MMX, isso deve funcionar para a maioria dos códigos. Para obter mais informações sobre o layout da estrutura e o alinhamento, consulte [tipos e armazenamento](../build/types-and-storage.md). Para obter informações sobre o layout de pilha, consulte [uso da pilha](../build/stack-usage.md).

## <a name="unwindability"></a>Unwindability

Funções de folha são funções que não são alterados a qualquer registros não voláteis. Uma função não-folha pode mudar RSP não-volátil, por exemplo, chamando uma função ou a alocação de espaço de pilha adicionais para variáveis locais. Para recuperar os registros não voláteis quando uma exceção é manipulada, funções de não-folha devem ser anotadas com os dados estáticos que descreve como desenrolar corretamente a função em uma instrução de arbitrária. Esses dados são armazenados como *pdata*, ou dados de procedimento, que por sua vez, refere-se ao *xdata*, com exceção de manipulação de dados. O xdata contém as informações de desenrolamento e pode apontar para pdata adicional ou uma função de manipulador de exceção. Prólogos e epílogos são altamente restritos para que eles possam ser descritos adequadamente xdata. O ponteiro de pilha deve ser alinhado a 16 bytes em qualquer região do código que não faça parte de um epílogo ou prólogo, exceto nas funções de folha. Funções folha podem desenroladas simplesmente simulando um retorno, portanto, não são necessárias pdata e xdata. Para obter detalhes sobre a estrutura adequada da função Prólogos e epílogos, consulte [prólogo e epílogo](../build/prolog-and-epilog.md). Para obter mais informações sobre o tratamento de exceção e a manipulação de exceção e desenrolamento de pdata e xdata, consulte [(x64) de tratamento de exceções](../build/exception-handling-x64.md).

## <a name="see-also"></a>Consulte também

[Convenções de software x64](../build/x64-software-conventions.md)