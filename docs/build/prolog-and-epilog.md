---
title: Prólogo e epílogo x64
ms.date: 12/17/2018
ms.assetid: 0453ed1a-3ff1-4bee-9cc2-d6d3d6384984
ms.openlocfilehash: d0b7444af6e434a09f6af5f5b1c144b46c79ad56
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81328439"
---
# <a name="x64-prolog-and-epilog"></a>Prólogo e epílogo x64

Cada função que aloca espaço de pilha, chama outras funções, salva registros não voláteis ou usa o tratamento de exceção deve ter um prólogo cujos limites de endereço são descritos nos dados de desenrolar associados à respectiva entrada da tabela de funções. Para obter mais informações, consulte [o tratamento de exceções x64](../build/exception-handling-x64.md). O prólogo salva registros de argumentos em seus endereços residenciais, se necessário, empurra registros não voláteis na pilha, aloca a parte fixa da pilha para locais e temporários e, opcionalmente, estabelece um ponteiro de quadro. Os dados de desenrolar associados devem descrever a ação do prólogo e devem fornecer as informações necessárias para desfazer o efeito do código de prólog.

Se a alocação fixa na pilha for superior a uma página (ou seja, maior que 4096 bytes), então é possível que a alocação de pilha possa abranger mais de uma página de memória virtual e, portanto, a alocação deve ser verificada antes de ser alocada. Uma rotina especial que é callable a partir do prólogo e que não destrói nenhum dos registros de argumentos é fornecido para este fim.

O método preferido para salvar registros não voláteis é movê-los para a pilha antes da alocação de pilha fixa. Se a alocação de pilha fixa for realizada antes que os registros não voláteis sejam salvos, provavelmente um deslocamento de 32 bits é necessário para abordar a área de registro salvo. (Supostamente, os impulsos dos registros são tão rápidos quanto os movimentos e devem permanecer assim para o futuro previsível, apesar da dependência implícita entre os pushes.) Registros não voláteis podem ser salvos em qualquer ordem. No entanto, o primeiro uso de um registro não volátil no prólogo deve ser para salvá-lo.

## <a name="prolog-code"></a>Código prólog

O código para um prólogo típico pode ser:

```MASM
    mov    [RSP + 8], RCX
    push   R15
    push   R14
    push   R13
    sub    RSP, fixed-allocation-size
    lea    R13, 128[RSP]
    ...
```

Este prólogo armazena o registro de argumentos RCX em sua localização inicial, salva registros não voláteis R13-R15, aloca a parte fixa do quadro de pilha e estabelece um ponteiro de quadro que aponta 128 bytes na área de alocação fixa. O uso de um deslocamento permite que mais da área de alocação fixa seja endereçada com deslocamentos de um byte.

Se o tamanho de alocação fixa for maior ou igual a uma página de memória, então uma função auxiliar deve ser chamada antes de modificar o RSP. Este ajudante, `__chkstk`sonda o intervalo de pilha a ser alocado para garantir que a pilha seja estendida corretamente. Nesse caso, o exemplo anterior do prólogo seria:

```MASM
    mov    [RSP + 8], RCX
    push   R15
    push   R14
    push   R13
    mov    RAX,  fixed-allocation-size
    call   __chkstk
    sub    RSP, RAX
    lea    R13, 128[RSP]
    ...
```

O `__chkstk` ajudante não modificará nenhum registro que não seja R10, R11 e os códigos de condição. Em particular, ele retornará o RAX inalterado e deixará todos os registros não voláteis e registros de passagem de argumentos sem modificações.

## <a name="epilog-code"></a>Código epílog

Código de epílog existe em cada saída para uma função. Considerando que normalmente há apenas um prólogo, pode haver muitos epílogos. O código epilog corta a pilha para o tamanho de alocação fixa (se necessário), desaloca a alocação de pilha fixa, restaura registros não voláteis, aparecendo seus valores salvos da pilha e retorna.

O código de epílog deve seguir um conjunto rigoroso de regras para que o código de desenrolar descontraida de forma confiável através de exceções e interrupções. Essas regras reduzem a quantidade de dados de sumidólucro necessários, porque não são necessários dados extras para descrever cada epílogo. Em vez disso, o código de desbobinamento pode determinar que um epílog está sendo executado através da varredura através de um fluxo de código para identificar um epílog.

Se nenhum ponteiro de quadro for usado na função, então o epílogo deve primeiro desalocar a parte fixa da pilha, os registros não voláteis são estourados e o controle é retornado à função de chamada. Por exemplo,

```MASM
    add      RSP, fixed-allocation-size
    pop      R13
    pop      R14
    pop      R15
    ret
```

Se um ponteiro de quadro for usado na função, a pilha deve ser aparada à sua alocação fixa antes da execução do epílogo. Esta ação tecnicamente não faz parte do epílogo. Por exemplo, o seguinte epílog pode ser usado para desfazer o prólogo usado anteriormente:

```MASM
    lea      RSP, -128[R13]
    ; epilogue proper starts here
    add      RSP, fixed-allocation-size
    pop      R13
    pop      R14
    pop      R15
    ret
```

Na prática, quando um ponteiro de quadro é usado, não há uma boa razão para ajustar rsp em duas etapas, de modo que o seguinte epílog seria usado em vez disso:

```MASM
    lea      RSP, fixed-allocation-size - 128[R13]
    pop      R13
    pop      R14
    pop      R15
    ret
```

Esses formulários são os únicos legais para um epílogo. Deve consistir de `add RSP,constant` `lea RSP,constant[FPReg]`um ou , seguido por uma série de zero `return` ou `jmp`mais 8 bytes de registro pops e a ou a . (Apenas um subconjunto de `jmp` instruções são permitidos no epílogo. O subconjunto é exclusivamente `jmp` a classe de instruções com referências de memória ModRM onde o valor de campo mod mod ModRM é 00. É proibido `jmp` o uso de instruções no epílogo com modRM mod valor de campo 01 ou 10. Consulte a Tabela A-15 no Volume Manual do Programador de Arquitetura AMD x86-64: Instruções gerais de propósito e sistema, para obter mais informações sobre as referências permitidas do ModRM.) Nenhum outro código pode aparecer. Em particular, nada pode ser agendado dentro de um epílogo, incluindo o carregamento de um valor de retorno.

Quando um ponteiro de quadro não é `add RSP,constant` usado, o epílogo deve ser usado para desalocar a parte fixa da pilha. Pode não `lea RSP,constant[RSP]` usar em vez disso. Essa restrição existe para que o código de descontração tenha menos padrões para reconhecer ao procurar por epílogs.

Seguir essas regras permite que o código de desenrolar determine que um epílogo está sendo executado e simular a execução do restante do epílogo para permitir a recriação do contexto da função de chamada.

## <a name="see-also"></a>Confira também

[x64 Convenções de Software](x64-software-conventions.md)
