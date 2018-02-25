---
title: Bibliotecas OpenMP | Microsoft Docs
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
ms.assetid: f89abf97-67e3-4327-bc30-43f85b9533a2
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 760e7d138ab71244419ff71960948d4d10f125eb
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="openmp-libraries"></a>OpenMP Bibliotecas
Discute os arquivos. lib que compõem as bibliotecas de tempo de execução de OpenMP no Visual C++.  
  
 As bibliotecas a seguir contêm as funções da biblioteca de tempo de execução OpenMP do Visual C++.  
  
|Biblioteca de tempo de execução OpenMP|Características|  
|------------------------------|---------------------|  
|VCOMP.LIB|Link dinâmico, multithread (biblioteca de importação para VCOMP. LIB).|  
|VCOMPD.LIB|Link dinâmico, multithread (biblioteca de importação para VCOMPD. TAMPA) (depuração)|  
  
 Se Debug está definido em uma compilação e `#include omp.h` está no código-fonte, VCOMPD. LIB será a biblioteca padrão. Caso contrário, VCOMP. LIB será usado.  
  
 Você pode usar [/NODEFAULTLIB (ignorar bibliotecas)](../../../build/reference/nodefaultlib-ignore-libraries.md) para remover o bibliotecário padrão e vincular explicitamente com a biblioteca de sua escolha.  
  
 As DLLs OpenMP estão na pasta redistribuível do Visual C++ e precisam ser distribuídas com aplicativos que usam OpenMP.  
  
## <a name="see-also"></a>Consulte também  
 [Referência da biblioteca](../../../parallel/openmp/reference/openmp-library-reference.md)