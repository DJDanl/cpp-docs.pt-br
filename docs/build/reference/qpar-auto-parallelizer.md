---
title: /Qpar (paralelizador automático)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCCLCompilerTool.EnableParallelCodeGeneration
ms.assetid: 33ecf49d-c0d5-4f34-bce3-84ff03f38918
ms.openlocfilehash: c1ddea73c5aa8d3e7e70b45834cb04154bf3b4bb
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62319220"
---
# <a name="qpar-auto-parallelizer"></a>/Qpar (paralelizador automático)

Permite que o [Paralelizador automático](../../parallel/auto-parallelization-and-auto-vectorization.md) recurso do compilador automaticamente paralelizar loops no código.

## <a name="syntax"></a>Sintaxe

```
/Qpar
```

## <a name="remarks"></a>Comentários

Quando o compilador paraleliza automaticamente loops no código, ele distribui a computação em vários núcleos de processador. Um loop é paralelizado somente se o compilador determina o que é legal para fazê-lo e essa paralelização melhorar o desempenho.

O `#pragma loop()` diretivas estão disponíveis para ajudar o otimizador de paralelizar loops específicos. Para obter mais informações, consulte [loop](../../preprocessor/loop.md).

Para obter informações sobre como habilitar as mensagens de saída para paralelizador automático, consulte [/Qpar-report (nível de relatórios do Paralelizador automático)](qpar-report-auto-parallelizer-reporting-level.md).

### <a name="to-set-the-qpar-compiler-option-in-visual-studio"></a>Para definir a opção de compilador /Qpar no Visual Studio

1. No **Gerenciador de Soluções**, abra o menu de atalho para o projeto e escolha **Propriedades**.

1. No **páginas de propriedades** caixa de diálogo **C/C++**, selecione **linha de comando**.

1. No **opções adicionais** , digite `/Qpar`.

### <a name="to-set-the-qpar-compiler-option-programmatically"></a>Para definir a opção de compilador /Qpar programaticamente

- Use o exemplo de código em <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções /Q (operações de nível baixo)](q-options-low-level-operations.md)<br/>
[/Qpar-report (nível de relatórios do paralelizador automático)](qpar-report-auto-parallelizer-reporting-level.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[#pragma loop()](../../preprocessor/loop.md)<br/>
[Programação paralela em código nativo](https://blogs.msdn.microsoft.com/nativeconcurrency/2012/04/12/auto-vectorizer-in-visual-studio-2012-overview/)
