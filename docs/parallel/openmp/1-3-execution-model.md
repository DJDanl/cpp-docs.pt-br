---
title: "1.3 Execution Model | Microsoft Docs"
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
ms.assetid: 85ae8bc4-5bf0-45e0-a45f-02de9adaf716
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 1.3 Execution Model
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O OpenMP usa o modelo de bifurcação\-junção de execução em paralelo.  Embora esse modelo de bifurcação\-junção pode ser útil para solucionar vários problemas, ele é um pouco adaptado para grandes aplicativos baseados em array.  OpenMP destina\-se aos programas de suporte que serão executado corretamente ambos como paralelo programas \(vários threads de execução e uma biblioteca de suporte OpenMP completa\) e programas seqüenciais \(diretivas ignoradas e uma biblioteca de stubs OpenMP simple\).  No entanto, é possível e permitido para desenvolver um programa que não se comportar corretamente quando executado em seqüência.  Além disso, os diferentes graus de paralelismo podem resultar em resultados numéricos diferentes devido às alterações na associação de operações numéricas.  Por exemplo, uma redução de adição serial pode ter um padrão diferente de associações de adição de uma redução paralela.  Essas associações diferentes podem alterar os resultados da adição de ponto flutuante.  
  
 Um programa escrito com a API do C\/C\+\+ OpenMP iniciará a execução como um único thread de execução chamada de  *segmento mestre*.  O principal segmento executa em uma região serial até que a primeira construção paralela seja encontrada.  Na API OpenMP C\/C\+\+, o  **paralela** diretiva constitui uma construção em paralela.  Quando uma construção paralela é encontrada, o thread mestre cria uma equipe de threads e o mestre se torna mestre da equipe.  Cada thread na equipe executa as instruções na extensão dinâmica de uma região paralela, exceto para as construções de compartilhamento de trabalho.  Construções de compartilhamento de trabalho devem ser encontradas por todos os threads na equipe na mesma ordem e as instruções dentro do bloco estruturado associado são executadas por um ou mais segmentos.  A barreira implícita ao final de uma construção de compartilhamento de trabalho sem um `nowait` cláusula é executada por todos os threads na equipe.  
  
 Se um thread modifica um objeto compartilhado, ele afeta não apenas seu próprio ambiente de execução, mas também os outros segmentos no programa.  A modificação é garantida para estar completo, do ponto de vista de um dos outros threads, no ponto de seqüência próximo \(conforme definido no idioma base\) somente se o objeto for declarado para ser volátil.  Caso contrário, a modificação é garantida para ser concluída após o primeiro a modificação de thread, e, em seguida, \(ou simultaneamente\) outros threads, encontrar um  **liberar** diretiva que especifica o objeto \(implícita ou explicitamente\).  Observe que quando o  **liberar** as diretivas que estão implícitas por outras diretivas OpenMP não são suficientes para garantir a ordem desejada dos efeitos colaterais, é responsabilidade do programador para fornecer adicionais e explícito  **liberar** diretivas.  
  
 Após a conclusão da construção paralela, os threads na equipe sincronizar em uma barreira implícita e apenas o segmento principal continua a execução.  Qualquer número de construções paralelos pode ser especificado em um único programa.  Como resultado, um programa pode bifurcação e associação muitas vezes durante a execução.  
  
 A API do C\/C\+\+ OpenMP permite aos programadores usam as diretivas em funções chamadas a partir do construções paralelas.  As diretivas que não aparecem na extensão do léxica de uma construção em paralela, mas pode ser a razão na extensão dinâmica são chamadas de  *órfãos*  diretivas.  Diretivas órfãos possibilitam que os programadores executar partes principais de seu programa em paralelo com alterações mínimas somente para o programa seqüencial.  Com essa funcionalidade, os usuários podem código paralelas construções em níveis superiores da árvore de chamada do programa e usar as diretivas para controlar a execução em qualquer uma das funções de chamada.  
  
 Não sincronizadas chamadas c e C\+\+ saída funções gravadas para o mesmo arquivo podem resultar na saída em que os dados gravados por threads diferentes aparecem na ordem determinística.  Da mesma forma, não sincronizadas chamadas para funções que ler o mesmo arquivo de entrada podem ler os dados na ordem determinística.  Uso não sincronizado de i\/O, de modo que cada thread acessa um arquivo diferente, produz os mesmos resultados que a execução serial das funções de i\/O.