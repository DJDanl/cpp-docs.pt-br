---
title: /cgthreads (threads geradoras de código)
ms.date: 07/31/2020
f1_keywords:
- /cgthreads
helpviewer_keywords:
- /cgthreads compiler option (C++)
- -cgthreads compiler option (C++)
- cgthreads compiler option (C++)
- cgthreads
ms.assetid: 64bc768c-6caa-4baf-9dea-7cfa1ffb01c2
ms.openlocfilehash: 319a42ab68f02df6019ff283f1039ef3d561c4a0
ms.sourcegitcommit: f2a135d69a2a8ef1777da60c53d58fe06980c997
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/03/2020
ms.locfileid: "87520869"
---
# <a name="cgthreads-code-generation-threads"></a>`/cgthreads`(Threads de geração de código)

Define o número de threads cl.exe usados para otimização e geração de código.

## <a name="syntax"></a>Sintaxe

> **`/cgthreads1`**\
> **`/cgthreads2`**\
> **`/cgthreads3`**\
> **`/cgthreads4`**\
> **`/cgthreads5`**\
> **`/cgthreads6`**\
> **`/cgthreads7`**\
> **`/cgthreads8`**

## <a name="arguments"></a>Argumentos

**`cgthreadsN`**\
O número máximo de threads para cl.exe usar, em que *N* é um número no intervalo de 1 a 8.

## <a name="remarks"></a>Comentários

A **`cgthreads`** opção especifica o número máximo de threads que cl.exe usa em paralelo para as fases de geração de código e otimização da compilação. Observe que não pode haver nenhum espaço entre **`cgthreads`** e o argumento *Number* . Por padrão, cl.exe usa quatro threads, como se **`/cgthreads4`** foram especificados. Se mais núcleos de processador estiverem disponíveis, um valor de *número* maior poderá melhorar os tempos de compilação. Essa opção é especialmente útil quando combinada com [ `/GL` (otimização do programa inteiro)](gl-whole-program-optimization.md).

É possível especificar diversos níveis de paralelismo para uma compilação. A opção msbuild.exe **`/maxcpucount`** especifica o número de processos do MSBuild que podem ser executados em paralelo. O sinalizador do compilador [ `/MP` (Build com vários processos)](mp-build-with-multiple-processes.md) especifica o número de processos de cl.exe que compilam os arquivos de origem simultaneamente. A **`cgthreads`** opção especifica o número de threads usados por cada processo de cl.exe. O processador só pode executar o mesmo número de threads ao mesmo tempo que há núcleos de processador. Não é útil especificar valores maiores para todas essas opções ao mesmo tempo e pode ser comproductal. Para obter mais informações sobre como criar projetos em paralelo, consulte [criando vários projetos em paralelo](/visualstudio/msbuild/building-multiple-projects-in-parallel-with-msbuild).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**  >  página de propriedade de linha de comando**C/C++** Propriedades de configuração  >  **Command Line** .

1. Modifique a propriedade **Opções adicionais** para incluir **`cgthreadsN`** , em que *`N`* é um valor de 1 a 8 e, em seguida, selecione **OK**.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
