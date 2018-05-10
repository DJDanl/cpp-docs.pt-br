---
title: Bibliotecas OpenMP | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
dev_langs:
- C++
ms.assetid: f89abf97-67e3-4327-bc30-43f85b9533a2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 46bd287ff8a020a4d5d7775afdb12f5571d43294
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
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