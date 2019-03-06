---
title: 'Como: Depurar um Build de versão'
ms.date: 11/04/2016
helpviewer_keywords:
- debugging [C++], release builds
- release builds, debugging
ms.assetid: d333e4d1-4e6c-4384-84a9-cb549702da25
ms.openlocfilehash: 61baaa827feb1abcc03a0296574e56c993ce1681
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57412556"
---
# <a name="how-to-debug-a-release-build"></a>Como: Depurar um Build de versão

Você pode depurar um build de versão de um aplicativo.

### <a name="to-debug-a-release-build"></a>Para depurar um build de versão

1. Abra o **páginas de propriedade** caixa de diálogo para o projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Clique o **C/C++** nó. Definir **formato de informações de depuração** à [compatível com C7 (/ Z7)](../../build/reference/z7-zi-zi-debug-information-format.md) ou **banco de dados do programa (/Zi)**.

1. Expandir **vinculador** e clique no **geral** nó. Definir **habilitar vinculação Incremental** à [não (/ /INCREMENTAL: NO)](../../build/reference/incremental-link-incrementally.md).

1. Selecione o **depuração** nó. Definir **gerar informações de depuração** à [Sim (/debug)](../../build/reference/debug-generate-debug-info.md).

1. Selecione o **otimização** nó. Definir **referências** à [/OPT: REF](../../build/reference/opt-optimizations.md) e **habilitar dobra COMDAT** para [/OPT: ICF](../../build/reference/opt-optimizations.md).

1. Agora você pode depurar seu aplicativo de build de versão. Para encontrar um problema, percorrer o código (ou a depuração Just-In-Time de uso) até encontrar onde ocorre a falha e, em seguida, determinar os parâmetros incorretos ou código.

   Se um aplicativo funciona em uma compilação de depuração, mas falhará na compilação de versão, uma das otimizações do compilador pode expor um defeito no código-fonte. Para isolar o problema, desabilite otimizações selecionadas para cada arquivo de código-fonte até localizar o arquivo e a otimização que está causando o problema. (Para agilizar o processo, você pode dividir os arquivos em dois grupos, desabilitar a otimização de um grupo e quando você encontrar um problema em um grupo, continuar dividindo até isolar o problema de arquivo.)

   Você pode usar [/RTC](../../build/reference/rtc-run-time-error-checks.md) para tentar expor esses bugs em suas compilações de depuração.

   Para obter mais informações, consulte [otimizando seu código](../../build/reference/optimizing-your-code.md).

## <a name="see-also"></a>Consulte também

[Corrigindo problemas do build de versão](../../build/reference/fixing-release-build-problems.md)
