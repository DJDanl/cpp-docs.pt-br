---
title: Bibliotecas de OpenMP
ms.date: 10/24/2018
ms.assetid: f89abf97-67e3-4327-bc30-43f85b9533a2
ms.openlocfilehash: 75f772c953a2120a02f72d8bdfc73c1baaaef390
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50530332"
---
# <a name="openmp-libraries"></a>Bibliotecas de OpenMP

Discute os arquivos. lib que compõem as bibliotecas de tempo de execução OpenMP no Visual C++.

As bibliotecas a seguir contêm as funções da biblioteca de tempo de execução OpenMP do Visual C++.

|Biblioteca de tempo de execução OpenMP|Características|
|------------------------------|---------------------|
|VCOMP.LIB|Threaded, vínculo dinâmico (biblioteca de importação para VCOMP. LIB).|
|VCOMPD.LIB|Threaded, vínculo dinâmico (biblioteca de importação para VCOMPD. TAMPA) (depuração)|

Se Debug é definido em uma compilação e se `#include omp.h` está no código-fonte, VCOMPD. LIB será a biblioteca padrão. Caso contrário, VCOMP. LIB será usado.

Você pode usar [/NODEFAULTLIB (ignorar bibliotecas)](../../../build/reference/nodefaultlib-ignore-libraries.md) para remover a biblioteca padrão e vincular explicitamente com a biblioteca de sua escolha.

As DLLs de OpenMP estão no diretório de pacotes redistribuíveis do Visual C++ e precisam ser distribuídas com aplicativos que usam o OpenMP.

## <a name="see-also"></a>Consulte também

[Referência da biblioteca](openmp-library-reference.md)
