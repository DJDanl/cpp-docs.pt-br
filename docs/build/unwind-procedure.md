---
title: "Procedimento desenrolado | Microsoft Docs"
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
ms.assetid: 82c5d0ca-70be-4d1a-a306-bfe01c29159f
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Procedimento desenrolado
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A matriz de código de desenrolamento é classificada em ordem decrescente.  Quando ocorre uma exceção, o contexto completo é armazenado pelo sistema operacional em um registro de contexto.  A lógica de distribuição de exceção é chamado em seguida, que executa repetidamente as seguintes etapas para localizar um manipulador de exceção.  
  
1.  Use o RASGO atual armazenado no registro de contexto para procurar por uma entrada de tabela de RUNTIME\_FUNCTION que descreve a função atual \(ou funciona a parte, no caso de entradas encadeadas de UNWIND\_INFO\).  
  
2.  Se nenhuma entrada de tabela de função é encontrada, a seguir está em uma função de folha, e RSP abordará diretamente o ponteiro de retorno.  O ponteiro de retorno em \[\] RSP é armazenado no contexto atualizado, o RSP simulado é incrementado por 8, e a etapa 1 é repetida.  
  
3.  Se uma entrada de tabela de função é encontrada, o RASGO pode encontrar\-se dentro de três regiões a\) em um epílogo, b\) no prólogo, ou c\#\) no código que pode ser tratado por um manipulador de exceção.  
  
    -   A caixa\) se o RASGO está dentro de um epílogo, o controle está encerrando de função, não é possível que haja nenhum manipulador de exceção associada com essa exceção para essa função, e os efeitos de epílogo devem ser continuados para calcular o contexto de função do chamador.  Para determinar se o RASGO está dentro de um epílogo, o fluxo de código de RASGO é examinado sobre.  Se esse fluxo de código pode ser combinado a parte à direita de um epílogo legítimo, então está em um epílogo, e a parte restante de epílogo é simulada, com o registro de contexto atualizado como cada declaração é processada.  Após isso, a etapa 1 é repetida.  
  
    -   A caixa b\) se o RASGO se encontra dentro de prólogo, o controle não inseriu a função, não é possível que haja nenhum manipulador de exceção associada com essa exceção para essa função, e os efeitos de prólogo devem ser desfeitos para calcular o contexto de função do chamador.  O RASGO está dentro do prólogo se a distância de início da função ao RASGO é menor ou igual ao tamanho de prólogo codificado em informações de desenrolamento.  Os efeitos de prólogo são desenrolados digitalizando frente na matriz de códigos de desenrolamento para a primeira entrada com um deslocamento menor ou igual ao deslocamento de RASGO de início de função, então desfazendo o efeito de todos os itens restantes na matriz de código de desenrolamento.  A etapa 1 é repetida em seguida.  
  
    -   A caixa c\#\) se o RASGO não está dentro de um prólogo ou o epílogo e a função têm um manipulador de exceção \(UNW\_FLAG\_EHANDLER é definido\), o tratador específico de linguagem é chamado.  O manipulador verifique suas funções de filtragem de dados e de chamadas conforme apropriado.  O tratador específico de linguagem pode retornar a exceção que foi tratada ou que a pesquisa deve ser continuada.  Também pode iniciar um desenrolamento diretamente.  
  
4.  Se o tratador específico de linguagem retorna um status tratado, então a execução é continuada usando o registro original do contexto.  
  
5.  Se não houver nenhum manipulador de linguagem específica ou retorna o manipulador “continue um status de pesquisa”, então o registro de contexto deve ser desenrolado o estado do chamador.  Isso é feito processando qualquer desenrola os elementos da matriz de código, desfazendo o efeito de cada um.  A etapa 1 é repetida em seguida.  
  
 Quando encadeado desenrole informações estiver envolvido, essas etapas básicas são seguidos ainda.  A única diferença é que, ao andar a matriz de código de desenrolamento para desenrolar os efeitos de um prólogo, o final da matriz é alcançado uma vez, ele é vinculada no pai desenrola informações e o inteiros desenrolam a matriz de código encontrada há andados.  Isso que vinculam continue até que chegando em uma informações de desenrolamento sem o sinalizador de UNW\_CHAINED\_INFO e o passeio de suporte seu desenrola a matriz de código.  
  
 O menor conjunto de desenrola dados é 8 bytes.  Isso representaria uma função que atribuísse apenas 128 bytes de pilha ou de menos, e salvo possivelmente um registro permanente.  Este é também o tamanho de encadeado desenrola a estrutura de informações para um prólogo de comprimento zero sem desenrola códigos.  
  
## Consulte também  
 [Tratamento de exceções \(x64\)](../build/exception-handling-x64.md)