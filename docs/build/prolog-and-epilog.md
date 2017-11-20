---
title: "Prólogo e epílogo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 0453ed1a-3ff1-4bee-9cc2-d6d3d6384984
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: c382f3a35b87dd6eeb21975ef692afd4127816d8
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="prolog-and-epilog"></a>Prólogo e epílogo
Cada função que aloca espaço de pilha, chamadas de outras funções, salva os registros não volátil ou usa o tratamento de exceção devem ter um prólogo cujos endereço limites descritos nos dados de desenrolamento associados à entrada de tabela do respectivos função (consulte [(X64) de tratamento de exceção](../build/exception-handling-x64.md)). O prólogo salva argumento registros em seus endereços de base se necessário, envia registros não volátil na pilha, aloca a parte fixa da pilha de locais e de longa e opcionalmente estabelece um ponteiro de quadro. Dados desenrolados associado deve descrever a ação de prólogo e forneça as informações necessárias para desfazer o efeito do código de prólogo.  
  
 Se a alocação fixa na pilha é a mais de uma página (ou seja, maior do que 4096 bytes), em seguida, é possível que a alocação da pilha pode abranger mais de uma página de memória virtual e, portanto, a alocação deve ser verificada antes que ela é realmente alocada. Uma rotina especial que é chamado de prólogo e que não destrói qualquer um dos registros de argumento é fornecida para essa finalidade.  
  
 É o método preferencial para salvar registros não volátil para movê-las para a pilha antes da alocação da pilha fixa. Se a alocação da pilha fixa foram realizada antes dos registros não volátil foram salvos, em seguida, muito provavelmente um deslocamento de 32 bits é necessário para o endereço salvo registrar área (supostamente, verificações de registros são apenas tão rápidas quanto move e devem permanecer de um futuro apesar da dependência implícita entre envios por push). Registros não volátil podem ser salvo em qualquer ordem. No entanto, o primeiro uso de um registro não volátil no prólogo deve ser para salvá-lo.  
  
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
  
 Este prólogo armazena o registro de argumento RCX na posição inicial, não salva volátil registra R13 R15 aloca a parte fixa do quadro de pilhas e estabelece um ponteiro de quadro que aponta 128 bytes para a área de alocação fixa. Um deslocamento permite que mais da área de alocação fixa sejam resolvidos com deslocamentos de um byte.  
  
 Se o tamanho de alocação fixa é maior que ou igual a uma página de memória, uma função auxiliar deve ser chamada antes de modificar RSP. Este auxiliar, __chkstk, é responsável pela sondagem do intervalo de pilha ser alocado, para garantir que a pilha é estendida corretamente. Nesse caso, o exemplo de prólogo anterior em vez disso, seria:  
  
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
  
 O auxiliar __chkstk não modificará quaisquer registros diferentes R10, R11 e os códigos de condição. Em particular, ele retornará RAX inalterado e deixe registra todos os não volátil e registros de passagem de argumento sem modificações.  
  
 Código de epílogo existe em cada saída para uma função. Enquanto houver normalmente apenas um prólogo, pode haver muitos epilogs. Código de epílogo corta a pilha para o tamanho de alocação fixa (se necessário), desaloca a alocação da pilha fixa, restaura registros não volátil, tirando seus valores salvos da pilha e retorna.  
  
 O código de epílogo deve seguir um conjunto restrito de regras para o código de desenrolamento confiável desenrolamento por meio de exceções e interrupções. Isso reduz a quantidade de desenrolamento dados necessários, porque nenhum dado extra é necessária para descrever cada epílogo. Em vez disso, o código de desenrolamento pode determinar que um epílogo está sendo executado por meio do exame forward por meio de um fluxo de código para identificar um epílogo.  
  
 Se nenhum ponteiro de quadro é usado na função, em seguida, o epílogo primeiro deverá desalocar a parte fixa da pilha, os registros não volátil são disparados e controle é retornado para a função de chamada. Por exemplo,  
  
```  
add      RSP, fixed-allocation-size  
pop      R13  
pop      R14  
pop      R15  
ret  
```  
  
 Se um ponteiro de quadro é usado na função, a pilha deve ser cortada para sua alocação fixa antes da execução de epílogo. Isso é tecnicamente não faz parte do epílogo. Por exemplo, epílogo a seguir pode ser usado para desfazer o prólogo usado anteriormente:  
  
```  
lea      RSP, -128[R13]  
; epilogue proper starts here  
add      RSP, fixed-allocation-size  
pop      R13  
pop      R14  
pop      R15  
ret  
```  
  
 Na prática, quando é usado um ponteiro de quadro, não há nenhuma boa razão para ajustar RSP em duas etapas, portanto o seguir epílogo seria usado em vez disso:  
  
```  
lea      RSP, fixed-allocation-size - 128[R13]  
pop      R13  
pop      R14  
pop      R15  
ret  
```  
  
 Esses são os formulários válidos somente para um epílogo. Ele deve consistir em uma `add RSP,constant` ou `lea RSP,constant[FPReg]`, seguido por uma série de zero ou mais pops de registro de 8 bytes e um retorno ou um jmp. (Apenas um subconjunto de instruções jmp são permitidas de epílogo. Esses são exclusivamente da classe do jmps com referências de memória ModRM onde o campo mod ModRM valor 00. É proibido o uso de jmps em epílogo com valor de campo mod ModRM 01 ou 10. Consulte tabela A-15 do programador AMD x86-64 arquitetura Manual Volume 3: geral e instruções de sistema, para obter mais informações sobre as referências de ModRM permitidas.). Nenhum outro código pode aparecer. Em particular, nada pode ser agendado em um epílogo, incluindo o carregamento de um valor de retorno.  
  
 Observe que, quando um ponteiro de quadro não for usado, o epílogo deve usar `add RSP,constant` desalocar a parte fixa da pilha. Ele não pode usar `lea RSP,constant[RSP]` em vez disso. Essa restrição existe para que o código de desenrolamento tenha menos padrões para reconhecer quando procurando epilogs.  
  
 Essas regras a seguir permite que o código de desenrolamento para determinar se um epílogo está sendo executado atualmente e para simular a execução do restante epílogo para permitir a recriar o contexto da função de chamada.  
  
## <a name="see-also"></a>Consulte também  
 [Convenções de software x64](../build/x64-software-conventions.md)