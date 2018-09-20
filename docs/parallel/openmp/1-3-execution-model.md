---
title: 1.3 modelo de execução | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 85ae8bc4-5bf0-45e0-a45f-02de9adaf716
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c284563a47d21abc9a1dacf045238449d64205d5
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46394004"
---
# <a name="13-execution-model"></a>1.3 Modelo de execução

O OpenMP usa o modelo de execução paralela de bifurcação-junção. Embora esse modelo de bifurcação-junção pode ser útil para solucionar uma variedade de problemas, um pouco sob medida para grandes aplicativos baseados em matriz. OpenMP destina-se aos programas de suporte que serão executado corretamente ambos como programas de paralelo (vários threads de execução e uma biblioteca de suporte completa OpenMP) e programas sequenciais (diretivas ignoradas e uma biblioteca de stubs de OpenMP simples). No entanto, é possível e tem permissão para desenvolver um programa que não se comportam corretamente quando executado em sequência. Além disso, diferentes graus de paralelismo podem resultar em resultados numéricos diferentes devido às alterações na associação de operações numéricas. Por exemplo, uma redução serial adição pode ter um padrão diferente de associações de adição de uma redução em paralela. Essas associações diferentes podem alterar os resultados da adição de ponto flutuante.

Um programa escrito com a API de C/C++ do OpenMP inicia a execução como um único thread de execução chamada a *dominar thread*. O thread mestre executa em uma região serial até que a primeira construção paralela é encontrada. Na API OpenMP C/C++, o **paralela** diretiva constitui uma construção paralela. Quando um constructo parallel for encontrado, o thread mestre cria uma equipe de threads e o mestre se torna o mestre da equipe. Cada thread em que a equipe executa as instruções na extensão dinâmica de uma região paralela, exceto para as construções de compartilhamento de trabalho. Constructos de compartilhamento de trabalho devem ser encontrados por todos os threads da equipe na mesma ordem e as instruções dentro do bloco estruturado associado são executadas por um ou mais dos threads. A barreira implícita no final de uma construção de compartilhamento de trabalho sem um `nowait` cláusula é executada por todos os threads da equipe.

Se um thread modificar um objeto compartilhado, ele afeta não apenas seu próprio ambiente de execução, mas também aqueles de outros threads no programa. A modificação é garantida para ser concluída, do ponto de vista de um dos outros threads, no próximo ponto de sequência (conforme definido no idioma base) somente se o objeto é declarado como volátil. Caso contrário, a modificação é garantido que seja concluída após o primeiro a modificação de thread, e, em seguida, (ou simultaneamente) encontrar outros threads, um **liberar** diretiva que especifica o objeto (implícita ou explicitamente). Observe que, quando o **liberar** diretivas são deduzidas por outras diretivas de OpenMP não são suficientes para garantir que a ordenação desejada de efeitos colaterais, é responsabilidade do programador para fornecer adicionais e explícitas  **liberar** diretivas.

Após a conclusão da construção paralela, os threads da equipe sincronizar em uma barreira implícita e somente o thread mestre continua a execução. Qualquer número de construções paralelas pode ser especificado em um único programa. Como resultado, um programa pode criar fork e unir várias vezes durante a execução.

A API de C/C++ do OpenMP permite aos programadores usar diretivas em funções, chamadas de dentro de construções paralelas. As diretivas que não aparecem na extensão de léxico de uma construção paralela, mas podem estar na extensão dinâmica são chamadas *órfãos* diretivas. Diretivas órfãos permitem que os programadores para executar as principais partes do programa de em paralelo com alterações mínimas somente para o programa sequencial. Com essa funcionalidade, os usuários podem construções paralelas em níveis superiores da árvore de chamadas do programa de código e usar diretivas para controlar a execução em qualquer uma das funções chamadas.

Funções que gravam no mesmo arquivo podem resultar em saída na qual os dados gravados por threads diferentes aparecem em ordem não determinística de saída de chamadas não sincronizadas para C e C++. Da mesma forma, não sincronizadas chamadas para funções que leiam do mesmo arquivo de entrada podem ler os dados em ordem não determinística. Uso não sincronizado de e/s, de modo que cada thread acessa um arquivo diferente, produz os mesmos resultados de execução serial das funções de e/s.