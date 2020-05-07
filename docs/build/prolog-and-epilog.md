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

Cada função que aloca espaço de pilha, chama outras funções, salva registros não voláteis ou usa o tratamento de exceções deve ter um prólogo cujos limites de endereço são descritos nos dados de desenrolamento associados à entrada da respectiva tabela de funções. Para obter mais informações, consulte [manipulação de exceção de x64](../build/exception-handling-x64.md). O prólogo salva os registros de argumento em seus endereços residenciais, se necessário, envia registros não voláteis na pilha, aloca a parte fixa da pilha para locais e temporaries e, opcionalmente, estabelece um ponteiro de quadro. Os dados de desenrolação associados devem descrever a ação do prólogo e devem fornecer as informações necessárias para desfazer o efeito do código de prólogo.

Se a alocação fixa na pilha for mais de uma página (ou seja, maior que 4096 bytes), é possível que a alocação de pilha possa abranger mais de uma página de memória virtual e, portanto, a alocação deve ser verificada antes de ser alocada. Uma rotina especial que é chamável do prólogo e que não destrói nenhum dos registros de argumento é fornecida para essa finalidade.

O método preferencial para salvar registros não voláteis é movê-los para a pilha antes da alocação de pilha fixa. Se a alocação de pilha fixa for executada antes que os registros não voláteis sejam salvos, provavelmente será necessário um deslocamento de 32 bits para tratar da área de registro salva. (Relatavelmente, os envios de registros são tão rápidos quanto as movimentações e devem permanecer assim para o futuro próximo, apesar da dependência implícita entre Pushes.) Os registros não voláteis podem ser salvos em qualquer ordem. No entanto, o primeiro uso de um registro não volátil no prólogo deve ser salvá-lo.

## <a name="prolog-code"></a>Código de prólogo

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

Esse prólogo armazena o argumento Register RCX em seu local inicial, salva registros não voláteis R13-R15, aloca a parte fixa do quadro de pilha e estabelece um ponteiro de quadro que aponta 128 bytes para a área de alocação fixa. O uso de um deslocamento permite que mais da área de alocação fixa seja abordada com deslocamentos de um byte.

Se o tamanho fixo da alocação for maior ou igual a uma página da memória, uma função auxiliar deverá ser chamada antes de modificar RSP. Esse auxiliar, `__chkstk`, investiga o intervalo de pilha a ser alocado para garantir que a pilha seja estendida corretamente. Nesse caso, o exemplo de prólogo anterior seria:

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

O `__chkstk` auxiliar não modificará nenhum registro diferente de R10, R11 e os códigos de condição. Em particular, ele retornará RAX inalterado e deixará todos os registros não voláteis e os registros de passagem de argumentos não modificados.

## <a name="epilog-code"></a>Código epílogo

O código epílogo existe em cada saída para uma função. Enquanto que normalmente há apenas um prólogo, pode haver muitas epilogs. O código epílogo apara a pilha para seu tamanho de alocação fixo (se necessário), desaloca a alocação de pilha fixa, restaura os registros não voláteis, exibindo seus valores salvos da pilha e retorna.

O código epílogo deve seguir um conjunto estrito de regras para o código de liberação para desenrolar de forma confiável por meio de exceções e interrupções. Essas regras reduzem a quantidade de dados de desenrolamento necessários, pois nenhum dado extra é necessário para descrever cada epílogo. Em vez disso, o código de desenrolação pode determinar que um epílogo está sendo executado por meio da verificação por meio de um fluxo de código para identificar um epílogo.

Se nenhum ponteiro de quadro for usado na função, o epílogo deverá primeiro desalocar a parte fixa da pilha, os registros não voláteis serão exibidos e o controle será retornado para a função de chamada. Por exemplo,

```MASM
    add      RSP, fixed-allocation-size
    pop      R13
    pop      R14
    pop      R15
    ret
```

Se um ponteiro de quadro for usado na função, a pilha deverá ser cortada para sua alocação fixa antes da execução do epílogo. Essa ação não é tecnicamente parte do epílogo. Por exemplo, o epílogo a seguir poderia ser usado para desfazer o prólogo usado anteriormente:

```MASM
    lea      RSP, -128[R13]
    ; epilogue proper starts here
    add      RSP, fixed-allocation-size
    pop      R13
    pop      R14
    pop      R15
    ret
```

Na prática, quando um ponteiro de quadro é usado, não há um bom motivo para ajustar o RSP em duas etapas, de modo que o epílogo a seguir seria usado em vez disso:

```MASM
    lea      RSP, fixed-allocation-size - 128[R13]
    pop      R13
    pop      R14
    pop      R15
    ret
```

Esses formulários são os únicos válidos para um epílogo. Ele deve consistir em um `add RSP,constant` ou `lea RSP,constant[FPReg]`, seguido por uma série de zero ou mais Pops de registro de 8 bytes e `return` um ou `jmp`um. (Apenas um subconjunto `jmp` de instruções é permitido no epílogo. O subconjunto é exclusivamente a classe `jmp` de instruções com referências de memória ModRM em que o valor do campo ModRM mod é 00. O uso de `jmp` instruções no epílogo com valor de campo ModRM mod 01 ou 10 é proibido. Consulte a tabela A-15 no processador de arquitetura AMD x86-64 Manual do programador: Uso Geral e instruções do sistema, para obter mais informações sobre as referências ModRM permitidas.) Nenhum outro código pode aparecer. Em particular, nada pode ser agendado em um epílogo, incluindo o carregamento de um valor de retorno.

Quando um ponteiro de quadro não é usado, o epílogo deve `add RSP,constant` usar para desalocar a parte fixa da pilha. Em vez disso, `lea RSP,constant[RSP]` ele não pode usar. Essa restrição existe para que o código de desenrolação tenha menos padrões para reconhecer ao procurar epilogs.

Seguir essas regras permite que o código de desenrolate determine que um epílogo está sendo executado no momento e simule a execução do restante do epílogo para permitir a recriação do contexto da função de chamada.

## <a name="see-also"></a>Confira também

[Convenções de software x64](x64-software-conventions.md)
