---
title: Bibliotecas OpenMP | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: f89abf97-67e3-4327-bc30-43f85b9533a2
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 5c0f009c26789fd771d55dab5fcfe5f342aa03b1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="openmp-libraries"></a>OpenMP Bibliotecas
Discute os arquivos. lib que compõem as bibliotecas de tempo de execução de OpenMP no Visual C++.  
  
 As bibliotecas a seguir contêm as funções da biblioteca de tempo de execução OpenMP do Visual C++.  
  
|Biblioteca de tempo de execução OpenMP|Características|  
|------------------------------|---------------------|  
|VCOMP. LIB|Link dinâmico, multithread (biblioteca de importação para VCOMP. LIB).|  
|VCOMPD. LIB|Link dinâmico, multithread (biblioteca de importação para VCOMPD. TAMPA) (depuração)|  
  
 Se Debug está definido em uma compilação e `#include omp.h` está no código-fonte, VCOMPD. LIB será a biblioteca padrão. Caso contrário, VCOMP. LIB será usado.  
  
 Você pode usar [/NODEFAULTLIB (ignorar bibliotecas)](../../../build/reference/nodefaultlib-ignore-libraries.md) para remover o bibliotecário padrão e vincular explicitamente com a biblioteca de sua escolha.  
  
 As DLLs OpenMP estão na pasta redistribuível do Visual C++ e precisam ser distribuídas com aplicativos que usam OpenMP.  
  
## <a name="see-also"></a>Consulte também  
 [Referência da biblioteca](../../../parallel/openmp/reference/openmp-library-reference.md)