---
title: "Cláusulas OpenMP | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: 806e7d8f-b204-4e4c-a12c-273ab540a7ca
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: bc55bdd98a733efb872f5311911402b2ff9938f3
ms.lasthandoff: 02/25/2017

---
# <a name="openmp-clauses"></a>Cláusulas OpenMP
Fornece links para cláusulas usadas na API do OpenMP.  
  
 Visual C++ suporta as seguintes cláusulas OpenMP:  
  
|Cláusula|Descrição|  
|------------|-----------------|  
|[copyin](../../../parallel/openmp/reference/copyin.md)|Permite que os threads acessar o valor do thread principal, para um [threadprivate](../../../parallel/openmp/reference/threadprivate.md) variável.|  
|[copyprivate](../../../parallel/openmp/reference/copyprivate.md)|Especifica que uma ou mais variáveis devem ser compartilhados entre todos os threads.|  
|[default](../../../parallel/openmp/reference/default-openmp.md)|Especifica o comportamento de variáveis sem escopo em uma região paralela.|  
|[firstprivate](../../../parallel/openmp/reference/firstprivate.md)|Especifica que cada thread deve ter sua própria instância de uma variável, e que a variável deve ser inicializada com o valor da variável, pois ela existe antes da construção parallel.|  
|[Se](../../../parallel/openmp/reference/if-openmp.md)|Especifica se deve ser executado um loop em paralelo ou em série.|  
|[lastprivate](../../../parallel/openmp/reference/lastprivate.md)|Especifica que a versão do contexto delimitador da variável é definida igual à versão particular de qualquer thread que executa a iteração final (construção de loop) ou a última seção (#pragma seções).|  
|[nowait](../../../parallel/openmp/reference/nowait.md)|Substitui a barreira implícita em uma diretiva.|  
|[num_threads](../../../parallel/openmp/reference/num-threads.md)|Define o número de threads em uma equipe de thread.|  
|[ordenado](../../../parallel/openmp/reference/ordered-openmp-clauses.md)|Necessário em paralelo [para](../../../parallel/openmp/reference/for-openmp.md) instrução se um [ordenados](../../../parallel/openmp/reference/ordered-openmp-directives.md) diretiva deve ser usada no loop.|  
|[private](../../../parallel/openmp/reference/private-openmp.md)|Especifica que cada thread deve ter sua própria instância de uma variável.|  
|[redução](../../../parallel/openmp/reference/reduction.md)|Especifica que uma ou mais variáveis que são particulares a cada thread são o assunto de uma operação de redução no final da região paralela.|  
|[agenda](../../../parallel/openmp/reference/schedule.md)|Aplica-se para o [para](../../../parallel/openmp/reference/for-openmp.md) diretiva.|  
|[compartilhado](../../../parallel/openmp/reference/shared-openmp.md)|Especifica que uma ou mais variáveis devem ser compartilhados entre todos os threads.|  
  
## <a name="see-also"></a>Consulte também  
 [OpenMP](../../../parallel/openmp/openmp-in-visual-cpp.md)   
 [Diretivas](../../../parallel/openmp/reference/openmp-directives.md)
