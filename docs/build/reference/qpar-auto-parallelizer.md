---
title: /Qpar (paralelizador automático)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCCLCompilerTool.EnableParallelCodeGeneration
ms.assetid: 33ecf49d-c0d5-4f34-bce3-84ff03f38918
ms.openlocfilehash: effe1ad7799022ea85184513de1dc48c72d6bfcb
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88839433"
---
# <a name="qpar-auto-parallelizer"></a>/Qpar (paralelizador automático)

Habilita o recurso [paralelizador automático automático](../../parallel/auto-parallelization-and-auto-vectorization.md) do compilador para paralelizar automaticamente loops em seu código.

## <a name="syntax"></a>Sintaxe

```
/Qpar
```

## <a name="remarks"></a>Comentários

Quando o compilador paralelize automaticamente loops no código, ele espalha a computação entre vários núcleos de processador. Um loop será paralelizado somente se o compilador determinar que é legal fazê-lo e que a paralelização melhoraria o desempenho.

As `#pragma loop()` diretivas estão disponíveis para ajudar o otimizador a paralelizar os loops específicos. Para obter mais informações, consulte [loop](../../preprocessor/loop.md).

Para obter informações sobre como habilitar mensagens de saída para o paralelizador automático automático, consulte [/Qpar-Report (nível de relatório de paralelizador automático automático)](qpar-report-auto-parallelizer-reporting-level.md).

### <a name="to-set-the-qpar-compiler-option-in-visual-studio"></a>Para definir a opção de compilador/Qpar no Visual Studio

1. No **Gerenciador de soluções**, abra o menu de atalho do projeto e, em seguida, escolha **Propriedades**.

1. Na caixa de diálogo **páginas de propriedades** , em **C/C++**, selecione **linha de comando**.

1. Na caixa **Opções adicionais** , digite `/Qpar` .

### <a name="to-set-the-qpar-compiler-option-programmatically"></a>Para definir a opção de compilador/Qpar programaticamente

- Use o exemplo de código em <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Confira também

[Opções de/q (operações de nível baixo)](q-options-low-level-operations.md)<br/>
[/Qpar-Report (nível de relatório do paralelizador automático automático)](qpar-report-auto-parallelizer-reporting-level.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[loop de #pragma ()](../../preprocessor/loop.md)<br/>
[Vetorização de código nativo no Visual Studio](/archive/blogs/nativeconcurrency/auto-vectorizer-in-visual-studio-2012-overview)
