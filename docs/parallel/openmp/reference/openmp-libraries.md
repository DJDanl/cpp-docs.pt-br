---
title: Bibliotecas OpenMP | Documentos do Microsoft
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
ms.assetid: f89abf97-67e3-4327-bc30-43f85b9533a2
caps.latest.revision: 9
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 1f5948c7921d28b677c4287bd54aecaee1f5766e
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="openmp-libraries"></a>OpenMP Bibliotecas
Discute os arquivos. lib que compõem as bibliotecas de tempo de execução de OpenMP no Visual C++.  
  
 As seguintes bibliotecas contêm as funções de biblioteca de tempo de execução do Visual C++ OpenMP.  
  
|Biblioteca de tempo de execução do OpenMP|Características|  
|------------------------------|---------------------|  
|VCOMP. LIB|Multithread, dynamic link (biblioteca de importação para VCOMP. LIB).|  
|VCOMPD. LIB|Multithread, dynamic link (biblioteca de importação para VCOMPD. TAMPA) (depuração)|  
  
 Se Debug é definido em uma compilação e se `#include omp.h` está no código-fonte, VCOMPD. LIB será a biblioteca padrão. Caso contrário, VCOMP. LIB será usado.  
  
 Você pode usar [/NODEFAULTLIB (ignorar bibliotecas)](../../../build/reference/nodefaultlib-ignore-libraries.md) para remover a biblioteca padrão e vincular explicitamente com a biblioteca de sua escolha.  
  
 As DLLs de OpenMP no Visual C++ redistribuível diretório e precisam ser distribuídos com aplicativos que usam OpenMP.  
  
## <a name="see-also"></a>Consulte também  
 [Referência da biblioteca](../../../parallel/openmp/reference/openmp-library-reference.md)
