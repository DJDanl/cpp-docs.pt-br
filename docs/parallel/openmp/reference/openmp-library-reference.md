---
title: OpenMP Referência de biblioteca
ms.date: 03/20/2019
ms.assetid: a25188c6-edde-43d0-84b5-780e797b08fc
ms.openlocfilehash: 6f4bbeca54bff1fc44a3576362edca9c30926d5a
ms.sourcegitcommit: 14b292596bc9b9b883a9c58cd3e366b282a1f7b3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2019
ms.locfileid: "60124688"
---
# <a name="openmp-library-reference"></a>OpenMP Referência de biblioteca

Fornece links para construções usadas na API OpenMP.

A implementação do Visual C++ do OpenMP padrão inclui as seguintes construções.

|Constructo|Descrição|
|---------------|-----------------|
|[Diretivas](openmp-directives.md)|Fornece links para as diretivas usadas na API OpenMP.|
|[Cláusulas](openmp-directives.md)|Fornece links para as cláusulas usadas na API OpenMP.|
|[Funções](openmp-functions.md)|Fornece links para as funções usadas na API OpenMP.|
|[Variáveis de ambiente](openmp-environment-variables.md)|Fornece links para as variáveis de ambiente usadas na API OpenMP.|

O Visual C++ funções de biblioteca em tempo de execução OpenMP estão contidas em bibliotecas a seguir.

|Biblioteca de tempo de execução OpenMP|Características|
|------------------------------|---------------------|
|VCOMP.LIB|Threaded, vínculo dinâmico (biblioteca de importação para VCOMP. LIB).|
|VCOMPD.LIB|Threaded, vínculo dinâmico (biblioteca de importação para VCOMPD. TAMPA) (depuração)|

Se Debug é definido em uma compilação e se `#include omp.h` está no código-fonte, VCOMPD. LIB será a biblioteca de padrão, caso contrário, VCOMP. LIB será usado.

Você pode usar [/NODEFAULTLIB (ignorar bibliotecas)](../../../build/reference/nodefaultlib-ignore-libraries.md) para remover a biblioteca padrão e vincular explicitamente com a biblioteca de sua escolha.

As DLLs de OpenMP estão no diretório de pacotes redistribuíveis do Visual C++ e precisam ser distribuídas com aplicativos que usam o OpenMP.

## <a name="see-also"></a>Consulte também

[OpenMP](../../../parallel/openmp/openmp-in-visual-cpp.md)