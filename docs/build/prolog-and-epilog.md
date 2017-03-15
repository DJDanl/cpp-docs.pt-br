---
title: "Pr&#243;logo e ep&#237;logo | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 0453ed1a-3ff1-4bee-9cc2-d6d3d6384984
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Pr&#243;logo e ep&#237;logo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cada função que atribui o espaço de pilha, chama outras funções, salva registros permanentes, ou tratamento de exceção de dispositivo deve ter um prólogo cujos os limites de endereços são descritos nos dados de desenrolamento associados com a entrada de tabela respectiva de função \(consulte [Tratamento de exceções \(x64\)](../build/exception-handling-x64.md)\).  O prólogo salva registros de argumento em seus endereços domiciliários se necessário, registros permanentes de envia na pilha, atribui a parte fixa de pilha para locais e temporaries, e opcionalmente estabelece um ponteiro de quadro.  O desenrola associado a dados deve descrever a ação de prólogo e deve fornecer as informações necessárias para desfazer o efeito de código de prólogo.  
  
 Se a alocação fixa na pilha é mais de uma página \(isto é, maior que 4096 bytes\), então é possível que a alocação de pilha pode abranger mais de uma página de memória virtual e, portanto, a alocação devem ser marcadas antes que seja atribuída realmente.  Uma rotina especial que sejam acessível de prólogo e que não destrua alguns dos registros de argumento é fornecida essa finalidade.  
  
 O método preferido para salvar registros permanentes é movê\-los na pilha antes de alocação de pilha fixa.  Se a alocação de pilha fixa foi executada antes que os registros foram salvos permanentes, então um deslocamento de 32 bits foi necessário o mais provável endereçar a área exceto pelo fato do registro \(dependendo das informações recebidas, envia os registros são apenas tão rápido quanto move e devem permanecer bem para o futuro próximo independentemente de dependência implícita entre envia\).  Os registros permanentes podem ser salvos em qualquer ordem.  No entanto, o primeiro uso de um registro permanente no prólogo deve ser salve\-o.  
  
 O código para um prólogo típico pode ser:  
  
```  
mov       [RSP + 8], RCX  
push   R15  
push   R14  
push   R13  
sub      RSP, fixed-allocation-size  
lea      R13, 128[RSP]  
...  
```  
  
 Este prólogo armazena o registro RCX de argumento no local de início, salva os registros R13\-R15 permanentes, atribui a parte fixa quadro de pilha, e estabelece um ponteiro de quadro esse pontos 128 bytes na área fixa de alocação.  Usar um deslocamento permite que mais da área fixa de alocação sejam endereçadas com deslocamentos de um byte.  
  
 Se o tamanho fixo de alocação é maior ou igual a uma página de memória, uma função auxiliar deve ser chamada antes de alterar RSP.  Este auxiliar, \_\_chkstk, eleição é responsável pelo intervalo à\-estar\- atribuído a pilha, para garantir que a pilha é estendida corretamente.  Nesse caso, o exemplo anterior de prólogo seria em vez disso:  
  
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
  
 O auxiliar de \_\_chkstk não alterará os registros diferentes de R10, de R11, e os códigos de condição.  Em particular, retornará RAX inalterado e permitir que todos os registros e permanentes argumento\- passar registra inalterados.  
  
 O código de epílogo existe em cada saída para uma função.  Enquanto geralmente há apenas um prólogo, pode haver muitos epílogos.  As guarnições de código de epílogo a pilha ao seu tamanho fixo de alocação \(se necessário\), desalocam a alocação de pilha fixa, restauram registros permanentes aparecendo seus valores salvos de pilha, e retornam.  
  
 O código de epílogo deve seguir um conjunto de regras restrito para que o código do desenrolamento desenrole confiavelmente com exceções e as interrupções.  Isso reduz a quantidade de desenrola os dados necessários, porque nenhum dado extra é necessário para descrever cada epílogo.  Em vez disso, o código de desenrolamento pode determinar que um epílogo está sendo executado digitalizando frente através de um fluxo de código para identificar um epílogo.  
  
 Se nenhum ponteiro de quadro é usado na função, o epílogo deve primeiro desalocar a parte fixa de pilha, registros são aparecidos permanentes, e o controle é retornado para a função de chamada.  Por exemplo,  
  
```  
add      RSP, fixed-allocation-size  
pop      R13  
pop      R14  
pop      R15  
ret  
```  
  
 Se um ponteiro de quadro é usado na função, então a pilha deve ser aparada à alocação fixa antes da execução de epílogo.  Isso não é tecnicamente parte de epílogo.  Por exemplo, o seguinte epílogo pode ser usado para desfazer o prólogo usado anteriormente:  
  
```  
lea      RSP, -128[R13]  
; epilogue proper starts here  
add      RSP, fixed-allocation-size  
pop      R13  
pop      R14  
pop      R15  
ret  
```  
  
 Na prática, quando um ponteiro de quadro é usado, não há bom motivo ajustar RSP em duas etapas, o seguinte epílogo deve ser usado em vez disso:  
  
```  
lea      RSP, fixed-allocation-size – 128[R13]  
pop      R13  
pop      R14  
pop      R15  
ret  
```  
  
 Esses são os únicos formulários legais para um epílogo.  Deve consistir de `add RSP,constant` ou `lea RSP,constant[FPReg]`, seguido por uma série de zero ou mais 8 PNF de registro do byte e um retorno ou um jmp.  \(Somente um subconjunto das instruções de jmp é permitido em epílogo.  Esses são exclusivamente da classe de jmps com referências de memória de ModRM onde o valor do campo 00 mod de ModRM.  O uso de jmps no epílogo com valor do campo 01 ou 10 mod de ModRM é proibido.  Consulte a tabela A\-15 em massa manual 3 do programador da arquitetura de AMD x86\-64: Instruções de uso geral e do sistema, para obter mais informações sobre referências de ModRM permitidos.\).  Nenhum outro código pode aparecer.  Em particular, nada pode ser agendada em um epílogo, incluindo a carga de um valor de retorno.  
  
 Observe que, quando um ponteiro de quadro não for usado, o epílogo deve usar `add RSP,constant` desalocar a parte fixa de pilha.  Não pode usar `lea RSP,constant[RSP]` em vez disso.  Essa limitação existe para que o código de desenrolamento tem menos padrão para reconhecer ao procurar por epílogos.  
  
 Seguindo essas regras permite que o código de desenrolamento determinar que um epílogo está sendo executado atualmente e simular a execução do restante de epílogo para permitir recriar o contexto de função de chamada.  
  
## Consulte também  
 [Convenções de software x64](../build/x64-software-conventions.md)