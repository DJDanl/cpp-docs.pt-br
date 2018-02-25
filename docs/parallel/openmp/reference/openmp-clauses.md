---
title: "Cláusulas OpenMP | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
ms.assetid: 806e7d8f-b204-4e4c-a12c-273ab540a7ca
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a63dacb8da2b7c4b1c7264cfccc6d2839db1b8b1
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="openmp-clauses"></a>Cláusulas OpenMP
Fornece links para cláusulas usadas na API do OpenMP.  
  
 As seguintes cláusulas OpenMP pela linguagem Visual C++:  
  
|Cláusula|Descrição|  
|------------|-----------------|  
|[copyin](../../../parallel/openmp/reference/copyin.md)|Permite que os threads acessar o valor do thread principal, para um [threadprivate](../../../parallel/openmp/reference/threadprivate.md) variável.|  
|[copyprivate](../../../parallel/openmp/reference/copyprivate.md)|Especifica que uma ou mais variáveis devem ser compartilhados entre todos os threads.|  
|[default](../../../parallel/openmp/reference/default-openmp.md)|Especifica o comportamento de variáveis sem escopo em uma região parallel.|  
|[firstprivate](../../../parallel/openmp/reference/firstprivate.md)|Especifica que cada thread deve ter sua própria instância de uma variável, e que a variável deve ser inicializada com o valor da variável, porque ele existe antes da construção paralela.|  
|[if](../../../parallel/openmp/reference/if-openmp.md)|Especifica se um loop deve ser executado em paralelo ou em série.|  
|[lastprivate](../../../parallel/openmp/reference/lastprivate.md)|Especifica que a versão do contexto delimitador da variável é definida igual à versão particular de qualquer thread que executa a iteração final (construção de loop) ou a última seção (#pragma seções).|  
|[nowait](../../../parallel/openmp/reference/nowait.md)|Substitui a barreira implícita em uma diretiva.|  
|[num_threads](../../../parallel/openmp/reference/num-threads.md)|Define o número de segmentos em uma equipe de thread.|  
|[ordered](../../../parallel/openmp/reference/ordered-openmp-clauses.md)|Necessário em um paralelo [para](../../../parallel/openmp/reference/for-openmp.md) instrução se um [ordenados](../../../parallel/openmp/reference/ordered-openmp-directives.md) diretiva é usada no loop.|  
|[private](../../../parallel/openmp/reference/private-openmp.md)|Especifica que cada thread deve ter sua própria instância de uma variável.|  
|[reduction](../../../parallel/openmp/reference/reduction.md)|Especifica que uma ou mais variáveis que são particulares a cada thread são o assunto de uma operação de redução no final da região de dados paralelo.|  
|[schedule](../../../parallel/openmp/reference/schedule.md)|Aplica-se para o [para](../../../parallel/openmp/reference/for-openmp.md) diretiva.|  
|[shared](../../../parallel/openmp/reference/shared-openmp.md)|Especifica que uma ou mais variáveis devem ser compartilhados entre todos os threads.|  
  
## <a name="see-also"></a>Consulte também  
 [OpenMP](../../../parallel/openmp/openmp-in-visual-cpp.md)   
 [Diretivas](../../../parallel/openmp/reference/openmp-directives.md)