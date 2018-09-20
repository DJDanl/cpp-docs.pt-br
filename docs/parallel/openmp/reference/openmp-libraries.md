---
title: OpenMP bibliotecas | Microsoft Docs
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
ms.openlocfilehash: c9a4ccfefeaeb9446731027db44b849233bfefd6
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46391209"
---
# <a name="openmp-libraries"></a>OpenMP Bibliotecas

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

[Referência da biblioteca](../../../parallel/openmp/reference/openmp-library-reference.md)