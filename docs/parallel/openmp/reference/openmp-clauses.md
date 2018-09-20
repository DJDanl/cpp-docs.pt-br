---
title: Cláusulas OpenMP | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
dev_langs:
- C++
ms.assetid: 806e7d8f-b204-4e4c-a12c-273ab540a7ca
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: afd0a8f66f9b0d027671629998597955b3aa69e9
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46378314"
---
# <a name="openmp-clauses"></a>Cláusulas OpenMP

Fornece links para as cláusulas usadas na API OpenMP.

Visual C++ suporta as seguintes cláusulas OpenMP:

|Cláusula|Descrição|
|------------|-----------------|
|[copyin](../../../parallel/openmp/reference/copyin.md)|Permite que os threads acessar o valor do thread mestre, para um [threadprivate](../../../parallel/openmp/reference/threadprivate.md) variável.|
|[copyprivate](../../../parallel/openmp/reference/copyprivate.md)|Especifica que uma ou mais variáveis devem ser compartilhadas entre todos os threads.|
|[default](../../../parallel/openmp/reference/default-openmp.md)|Especifica o comportamento de variáveis fora do escopo em uma região paralela.|
|[firstprivate](../../../parallel/openmp/reference/firstprivate.md)|Especifica que cada thread deve ter sua própria instância de uma variável, e que a variável deverá ser inicializada com o valor da variável, porque ele existe antes da construção parallel.|
|[if](../../../parallel/openmp/reference/if-openmp.md)|Especifica se deve ser executado um loop em paralelo ou em série.|
|[lastprivate](../../../parallel/openmp/reference/lastprivate.md)|Especifica que a versão do contexto delimitador da variável é definido igual da versão privada de qualquer thread que executa a iteração final (construção de loop) ou a última seção (#pragma seções).|
|[nowait](../../../parallel/openmp/reference/nowait.md)|Substitui a barreira implícita em uma diretiva.|
|[num_threads](../../../parallel/openmp/reference/num-threads.md)|Define o número de threads em uma equipe de thread.|
|[Ordenado](../../../parallel/openmp/reference/ordered-openmp-clauses.md)|Necessário em um paralelo [para](../../../parallel/openmp/reference/for-openmp.md) instrução se um [ordenados](../../../parallel/openmp/reference/ordered-openmp-directives.md) diretiva deve ser usada no loop.|
|[private](../../../parallel/openmp/reference/private-openmp.md)|Especifica que cada thread deve ter sua própria instância de uma variável.|
|[reduction](../../../parallel/openmp/reference/reduction.md)|Especifica que uma ou mais variáveis que são particulares para cada thread são o assunto de uma operação de redução no final da região paralela.|
|[schedule](../../../parallel/openmp/reference/schedule.md)|Aplica-se para o [para](../../../parallel/openmp/reference/for-openmp.md) diretiva.|
|[shared](../../../parallel/openmp/reference/shared-openmp.md)|Especifica que uma ou mais variáveis devem ser compartilhadas entre todos os threads.|

## <a name="see-also"></a>Consulte também

[OpenMP](../../../parallel/openmp/openmp-in-visual-cpp.md)<br/>
[Diretivas](../../../parallel/openmp/reference/openmp-directives.md)