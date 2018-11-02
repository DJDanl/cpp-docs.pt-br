---
title: Prólogo e epílogo
ms.date: 11/04/2016
ms.assetid: 0453ed1a-3ff1-4bee-9cc2-d6d3d6384984
ms.openlocfilehash: 2b54737edd46a5e108a211ee032889885be2b1da
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50543111"
---
# <a name="prolog-and-epilog"></a>Prólogo e epílogo

Todas as funções que aloca espaço em pilha, chamadas de outras funções, salva os registros não voláteis ou usa o tratamento de exceção devem ter um prólogo cujos limites de endereço são descritos nos dados de desenrolamento associados à entrada de tabela de função respectiva (consulte [(X64) de manipulação de exceção](../build/exception-handling-x64.md)). O prólogo salva argumento registros em seus endereços de base se necessário, envia os registros não voláteis na pilha, aloca a parte fixa da pilha para variáveis locais e os temporários e, opcionalmente, estabelece um ponteiro de quadro. Dados de desenrolamento associado deve descrever a ação de prólogo e deve fornecer as informações necessárias para desfazer o efeito do código de prólogo.

Se a alocação fixa na pilha é a mais de uma página (ou seja, maior que 4096 bytes), em seguida, é possível que a alocação da pilha pode abranger mais de uma página de memória virtual e, portanto, a alocação deve ser verificada antes, na verdade, ele é alocado. Uma rotina especial que pode ser chamado do prólogo e que não destrói qualquer um dos registros de argumento é fornecida para essa finalidade.

É o método preferencial para salvar os registros não voláteis para movê-los para a pilha antes da alocação de pilha fixa. Se a alocação de pilha fixa tiverem sido realizada antes dos registros não voláteis foram salvas, e em seguida, muito provavelmente um deslocamento de 32 bits seria necessário para endereço salvo registrar área (supostamente, envios por push de registros são simplesmente tão rápidos quanto move e devem permanecer para no futuro apesar da dependência implícita entre envios por push). Os registros não voláteis podem ser salvos em qualquer ordem. No entanto, o primeiro uso de um registro não volátil no prólogo deve ser para salvá-lo.

O código de prólogo típico pode ser:

```
mov       [RSP + 8], RCX
push   R15
push   R14
push   R13
sub      RSP, fixed-allocation-size
lea      R13, 128[RSP]
...
```

Este prólogo armazena o registro de argumento RCX em seu local de residência, não volátil de salva registra R13 R15, aloca a parte fixa da estrutura de pilhas e estabelece um ponteiro de quadro que aponta de 128 bytes para a área de alocação fixa. Um deslocamento permite que mais da área de alocação fixa sejam resolvidos com deslocamentos de um byte.

Se o tamanho de alocação fixa é maior que ou igual a uma página de memória, uma função auxiliar deve ser chamada antes de modificar RSP. Esse auxiliar, __chkstk, é responsável pela investigação do intervalo de pilha ser alocado, para garantir que a pilha é estendida corretamente. Nesse caso, o exemplo de prólogo anterior em vez disso, seria:

```
mov       [RSP + 8], RCX
push   R15
push   R14
push   R13
mov      RAX,  fixed-allocation-size
call   __chkstk
sub      RSP, RAX
lea      R13, 128[RSP]
...
```

O auxiliar __chkstk não modificará nenhum registro diferente R10, R11 e os códigos de condição. Em particular, ele retornará RAX inalterado e deixe os registros de todos os não-volátil e registros de passagem de argumentos sem modificações.

Código de epílogo existe em cada saída para uma função. Enquanto houver normalmente apenas um prólogo, pode haver vários epílogos. Código de epílogo corta a pilha para o tamanho de alocação fixa (se necessário), desaloca a alocação de pilha fixa, restaura os registros não voláteis por popping seus valores salvos da pilha e retorna.

O código de epílogo deve seguir um conjunto restrito de regras para o código de desenrolamento de forma confiável o desenrolamento por meio de exceções e interrupções. Isso reduz a quantidade de desenrolar dados necessários, porque nenhum dado extra é necessária para descrever cada epílogo. Em vez disso, o código de desenrolamento pode determinar que um epílogo está sendo executado por meio da verificação para frente por meio de um fluxo de código para identificar um epílogo.

Se nenhum ponteiro de quadro é usado na função e, em seguida, o epílogo deve primeiro desaloque a parte fixa da pilha, os registros não voláteis são removidos e controle é retornado à função de chamada. Por exemplo,

```
add      RSP, fixed-allocation-size
pop      R13
pop      R14
pop      R15
ret
```

Se um ponteiro de quadro é usado na função, a pilha deve ser cortada à sua alocação fixa antes da execução de epílogo. Isso é tecnicamente não faz parte de epílogo. Por exemplo, o epílogo seguir poderia ser usado para desfazer o prólogo usado anteriormente:

```
lea      RSP, -128[R13]
; epilogue proper starts here
add      RSP, fixed-allocation-size
pop      R13
pop      R14
pop      R15
ret
```

Na prática, quando um ponteiro de quadro é usado, não há nenhuma boa razão para ajustar RSP em duas etapas, para que o epílogo seguir seria usado em vez disso:

```
lea      RSP, fixed-allocation-size - 128[R13]
pop      R13
pop      R14
pop      R15
ret
```

Esses são os formulários válidos apenas para um epílogo. Ele deve consistir em um uma `add RSP,constant` ou `lea RSP,constant[FPReg]`, seguido por uma série de zero ou mais pops de registro de 8 bytes e um retorno ou um jmp. (Apenas um subconjunto das instruções jmp são permitidos no epílogo. Esses são exclusivamente de classe da jmps com ModRM referências de memória em que o campo de mod ModRM value 00. É proibido o uso de jmps no epílogo com valor de campo mod ModRM 01 ou 10. Tabela de consulte A-15 no Volume de Manual 3 do programador do AMD 64 x86 arquitetura: uso geral e instruções do sistema, para obter mais informações sobre as referências de ModRM permitidas.). Nenhum outro código pode aparecer. Em particular, nada pode ser programado dentro de um epílogo, incluindo o carregamento de um valor de retorno.

Observe que, quando um ponteiro de quadro não for usado, o epílogo deve usar `add RSP,constant` para desalocar a parte fixa da pilha. Ele não pode usar `lea RSP,constant[RSP]` em vez disso. Essa restrição existe para que o código de desenrolamento tem padrões menos reconhecer quando pesquisando epílogos.

Seguindo essas regras permite que o código de desenrolamento para determinar que atualmente está sendo executado um epílogo e para simular a execução do restante do epílogo para permitir que recriar o contexto da função de chamada.

## <a name="see-also"></a>Consulte também

[Convenções de software x64](../build/x64-software-conventions.md)