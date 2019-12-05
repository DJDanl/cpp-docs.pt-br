---
title: OpenMP Referência de biblioteca
ms.date: 12/02/2019
ms.assetid: a25188c6-edde-43d0-84b5-780e797b08fc
ms.openlocfilehash: b61eb356b782b3cd17557827734a706e0761a2a8
ms.sourcegitcommit: 8762a3f9b5476b4dee03f0ee8064ea606550986e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/04/2019
ms.locfileid: "74810743"
---
# <a name="openmp-library-reference"></a>OpenMP Referência de biblioteca

Fornece links para construções usadas na API de OpenMP.

A implementação C++ visual do padrão de OpenMP inclui as seguintes construções.

|Construir|Descrição|
|---------------|-----------------|
|[Diretivas](openmp-directives.md)|Fornece links para diretivas usadas na API de OpenMP.|
|[Cláusulas](openmp-clauses.md)|Fornece links para as cláusulas usadas na API de OpenMP.|
|[Funções](openmp-functions.md)|Fornece links para funções usadas na API de OpenMP.|
|[Variáveis de ambiente](openmp-environment-variables.md)|Fornece links para variáveis de ambiente usadas na API de OpenMP.|

As funções C++ de biblioteca de tempo de execução de OpenMP do Visual estão contidas nas bibliotecas a seguir.

|Biblioteca de tempo de execução de OpenMP|Características|
|------------------------------|---------------------|
|VCOMP.LIB|Link dinâmico multithread (biblioteca de importação para VCOMP140. DLL).|
|VCOMPD.LIB|Link dinâmico multithread (biblioteca de importação para VCOMP140D. DLL) (depuração)|

Se _DEBUG for definido em uma compilação e se `#include <omp.h>` estiver no código-fonte, VCOMPD. LIB será a lib padrão, caso contrário, VCOMP. LIB será usado.

Você pode usar [/NODEFAULTLIB (ignorar bibliotecas)](../../../build/reference/nodefaultlib-ignore-libraries.md) para remover a lib padrão e vincular explicitamente com a lib de sua escolha.

As DLLs de OpenMP estão no diretório C++ Visual redistribuível e precisam ser distribuídas com aplicativos que usam OpenMP.

## <a name="see-also"></a>Consulte também

[OpenMP](../../../parallel/openmp/openmp-in-visual-cpp.md)
