---
title: -CGTHREADS (Threads Compiladoras) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- /CGTHREADS linker option
- -CGTHREADS linker option
- CGTHREADS linker option
ms.assetid: 4b52cfdb-3702-470b-9580-fabeb1417488
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d717ffb3ed135ffe9e6f4ed2c55f925e3f10d86f
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45720519"
---
# <a name="cgthreads-compiler-threads"></a>/CGTHREADS (threads compiladoras)

Defina quantos threads cl.exe devem ser usados na otimização e na geração de códigos quando a geração de código vínculo-tempo for especificada.

## <a name="syntax"></a>Sintaxe

```
/CGTHREADS:[1-8]
```

## <a name="arguments"></a>Arguments

*número*<br/>
O máximo de threads que podem ser usados por cl.exe, no intervalo de 1 a 8.

## <a name="remarks"></a>Comentários

O **/CGTHREADS** opção especifica o número máximo de threads cl.exe usa em paralelo para as fases de otimização e geração de código da compilação quando o tempo de vinculação de geração de código ([/LTCG](../../build/reference/ltcg-link-time-code-generation.md)) é especificado. Por padrão, cl.exe usa quatro threads, como se **/CGTHREADS:4** foram especificadas. Se houver mais núcleos de processadores disponíveis, um valor de `number` maior poderá melhorar os tempos de compilação.

É possível especificar diversos níveis de paralelismo para uma compilação. O comutador msbuild.exe **/maxcpucount** Especifica o número de processos do MSBuild que podem ser executados em paralelo. O [/MP (compilar com vários processos)](../../build/reference/mp-build-with-multiple-processes.md) sinalizador do compilador Especifica o número de processos de cl.exe que compilam simultaneamente os arquivos de origem. O [/cgthreads](../../build/reference/cgthreads-code-generation-threads.md) opção do compilador Especifica o número de threads usados por cada processo cl.exe. Como o processador só pode executar uma quantidade certa de threads ao mesmo tempo devido à presença dos núcleos do processador, especificar valores altos para todas essas opções ao mesmo tempo não é útil e pode ser contraproducente. Para obter mais informações sobre como compilar projetos em paralelo, consulte [compilando vários projetos paralelamente](/visualstudio/msbuild/building-multiple-projects-in-parallel-with-msbuild).

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração**, **vinculador** pasta.

1. Selecione o **linha de comando** página de propriedades.

1. Modificar a **opções adicionais** propriedade incluir **/CGTHREADS:**`number`, onde `number` é um valor de 1 a 8 e, em seguida, escolha **Okey**.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do vinculador](../../build/reference/linker-options.md)<br/>
[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)