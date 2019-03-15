---
title: /cgthreads (threads geradoras de código)
ms.date: 11/04/2016
f1_keywords:
- /cgthreads
helpviewer_keywords:
- /cgthreads compiler option (C++)
- -cgthreads compiler option (C++)
- cgthreads compiler option (C++)
- cgthreads
ms.assetid: 64bc768c-6caa-4baf-9dea-7cfa1ffb01c2
ms.openlocfilehash: df353eb255c731478863ed6088cafa1cc38053fb
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57807423"
---
# <a name="cgthreads-code-generation-threads"></a>/cgthreads (threads geradoras de código)

Define o número de threads cl.exe usados para otimização e geração de código.

## <a name="syntax"></a>Sintaxe

```
/cgthreads[1-8]
```

## <a name="arguments"></a>Arguments

*number*<br/>
O máximo de threads que podem ser usados por cl.exe, no intervalo de 1 a 8.

## <a name="remarks"></a>Comentários

O **/cgthreads** opção especifica o número máximo de threads cl.exe usa em paralelo para a otimização e o código de geração fases da compilação. Observe que não pode haver nenhum espaço entre **/cgthreads** e o `number` argumento. Por padrão, cl.exe usa quatro threads, como se **/cgthreads4** foram especificadas. Se houver mais núcleos de processadores disponíveis, um valor de `number` maior poderá melhorar os tempos de compilação. Essa opção é especialmente útil quando ele é combinado com [/GL (otimização de programa inteiro)](gl-whole-program-optimization.md).

É possível especificar diversos níveis de paralelismo para uma compilação. O comutador msbuild.exe **/maxcpucount** Especifica o número de processos do MSBuild que podem ser executados em paralelo. O [/MP (compilar com vários processos)](mp-build-with-multiple-processes.md) sinalizador do compilador Especifica o número de processos de cl.exe que compilam simultaneamente os arquivos de origem. O **/cgthreads** opção especifica o número de threads usados por cada processo cl.exe. Como o processador só pode executar uma quantidade certa de threads ao mesmo tempo devido à presença dos núcleos do processador, especificar valores altos para todas essas opções ao mesmo tempo não é útil e pode ser contraproducente. Para obter mais informações sobre como compilar projetos em paralelo, consulte [compilando vários projetos paralelamente](/visualstudio/msbuild/building-multiple-projects-in-parallel-with-msbuild).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração**, **C/C++** pasta.

1. Selecione o **linha de comando** página de propriedades.

1. Modificar a **opções adicionais** propriedade incluir **/cgthreads**`N`, onde `N` é um valor de 1 a 8 e, em seguida, selecione **Okey**.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
