---
title: Como depurar um build da versão
ms.date: 11/04/2016
helpviewer_keywords:
- debugging [C++], release builds
- release builds, debugging
ms.assetid: d333e4d1-4e6c-4384-84a9-cb549702da25
ms.openlocfilehash: 6d93fac4e980085c322acb55e6f8758e6cea0a00
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62188951"
---
# <a name="how-to-debug-a-release-build"></a>Como depurar um build da versão

Você pode depurar uma compilação de versão de um aplicativo.

### <a name="to-debug-a-release-build"></a>Para depurar uma compilação de versão

1. Abra a caixa de diálogo **páginas de propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](working-with-project-properties.md).

1. Clique no nó **C/C++** . Defina o **formato de informações de depuração** como [compatível com C7 (/Z7)](reference/z7-zi-zi-debug-information-format.md) ou **banco de dados de programa (/Zi)**.

1. Expanda o **vinculador** e clique no nó **geral** . Defina **habilitar vinculação incremental** como [não (/incremental: no)](reference/incremental-link-incrementally.md).

1. Selecione o nó de **depuração** . Defina **gerar informações de depuração** como [Sim (/debug)](reference/debug-generate-debug-info.md).

1. Selecione o nó **otimização** . Defina **referências** para [/OPT: REF](reference/opt-optimizations.md) e **habilitar o dobramento COMDAT** para [/OPT: ICF](reference/opt-optimizations.md).

1. Agora você pode depurar seu aplicativo de Build de versão. Para encontrar um problema, percorra o código (ou use a depuração Just-in-time) até encontrar o local em que a falha ocorre e, em seguida, determine os parâmetros ou o código incorretos.

   Se um aplicativo funcionar em uma compilação de depuração, mas falhar em uma compilação de versão, uma das otimizações do compilador poderá estar expondo um defeito no código-fonte. Para isolar o problema, desabilite as otimizações selecionadas para cada arquivo de código-fonte até localizar o arquivo e a otimização que está causando o problema. (Para agilizar o processo, você pode dividir os arquivos em dois grupos, desabilitar a otimização em um grupo e, quando encontrar um problema em um grupo, continuar dividindo até isolar o arquivo de problema).

   Você pode usar o [/RTC](reference/rtc-run-time-error-checks.md) para tentar expor esses bugs em suas compilações de depuração.

   Para obter mais informações, consulte [otimizando seu código](optimizing-your-code.md).

## <a name="see-also"></a>Confira também

[Corrigindo problemas de compilação da versão](fixing-release-build-problems.md)
