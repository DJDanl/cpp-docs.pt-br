---
title: "1.3 modelo de execução | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: 85ae8bc4-5bf0-45e0-a45f-02de9adaf716
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ce9c2398b38effebbca428c811d86481ca94e7cd
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="13-execution-model"></a>1.3 Modelo de execução
OpenMP usa o modelo de associação de bifurcação de execução paralela. Embora esse modelo de associação de bifurcação pode ser útil para solucionar vários problemas, um pouco sob medida para aplicativos grandes baseada em conjunto. OpenMP destina-se aos programas de suporte que serão executados corretamente ambos como programas de paralelo (vários threads de execução e uma biblioteca de suporte OpenMP completa) e programas sequenciais (diretivas ignoradas e uma biblioteca de stubs OpenMP simple). No entanto, é possível e permissão para desenvolver um programa que não funcionam corretamente quando executadas sequencialmente. Além disso, diferentes graus de paralelismo podem causar resultados numéricos diferentes devido a alterações na associação de operações numéricas. Por exemplo, uma redução de adição serial pode ter um padrão diferente das associações de adição de uma redução em paralela. Essas associações diferentes podem alterar os resultados da adição de ponto flutuante.  
  
 Um programa gravado com a API do C/C++ OpenMP começa a ser executada como um único thread de execução chamada o *mestre thread*. O thread principal é executado em uma região de serial até que a primeira construção paralela é encontrada. Na API OpenMP C/C++, o **paralela** diretiva constitui uma construção paralela. Quando uma construção paralela é encontrada, o thread principal cria um grupo de threads e o mestre se torna o mestre da equipe. Cada thread na equipe executa as instruções na extensão dinâmica de uma região parallel, exceto para as construções de compartilhamento de trabalho. Construções de compartilhamento de trabalho devem ser encontradas por todos os threads da equipe na mesma ordem, e as instruções dentro do bloco estruturado associado são executadas por um ou mais threads. A barreira implicada ao final de uma construção de compartilhamento de trabalho sem um `nowait` cláusula é executada por todos os threads na equipe.  
  
 Se um thread de modificar um objeto compartilhado, ele afeta não apenas seu próprio ambiente de execução, mas também os outros segmentos no programa. A modificação é garantida para ser concluída, do ponto de vista de um dos outros threads, no próximo ponto de sequência (conforme definido no idioma básico) somente se o objeto é declarado como volátil. Caso contrário, a modificação é garantida para ser concluída após o primeiro a modificação de thread, e, em seguida, (ou simultaneamente) encontrar outros threads, um **liberar** diretiva que especifica o objeto (implícita ou explicitamente). Observe que, quando o **liberar** as diretivas são indicadas por outras diretivas OpenMP não são suficientes para garantir a ordem desejada dos efeitos colaterais, é responsabilidade do programador para fornecer adicionais e explícitas  **liberar** diretivas.  
  
 Após a conclusão da construção paralela, os threads da equipe de sincronizam uma barreira implícita e somente o thread principal continua a execução. Qualquer número de construções paralelas pode ser especificado em um único programa. Como resultado, um programa pode dividir e unir várias vezes durante a execução.  
  
 A API do C/C++ OpenMP permite aos programadores usar diretivas nas funções chamadas de dentro de construções paralelas. Diretivas que não aparecem na extensão de léxica de uma construção paralela, mas podem estar na extensão dinâmica são chamadas *órfãos* diretivas. Diretivas órfãos oferecem aos programadores a capacidade de executar as principais partes de seu programa em paralelo com alterações mínimas somente para o programa sequencial. Com essa funcionalidade, os usuários podem código paralelas construções em níveis superiores da árvore de chamadas de programa e usar as diretivas para controlar a execução em qualquer uma das funções de chamada.  
  
 Chamadas não sincronizadas para C e C++ saída funções que gravam no mesmo arquivo podem resultar na saída em que os dados gravados por threads diferentes aparecem na ordem não determinística. Da mesma forma, não sincronizadas chamadas para funções que leiam o mesmo arquivo de entrada podem ler os dados em ordem não determinística. Não sincronizado uso de e/s, de modo que cada thread acessa um arquivo diferente, produz os mesmos resultados que a execução serial das funções de e/s.