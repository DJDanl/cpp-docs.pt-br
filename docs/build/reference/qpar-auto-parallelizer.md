---
title: -Qpar (Paralelizador automático) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCCLCompilerTool.EnableParallelCodeGeneration
dev_langs:
- C++
ms.assetid: 33ecf49d-c0d5-4f34-bce3-84ff03f38918
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a701183becc7a561ca778dea383fdb57181d8da4
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45710769"
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

Para obter informações sobre como habilitar as mensagens de saída para paralelizador automático, consulte [/Qpar-report (nível de relatórios do Paralelizador automático)](../../build/reference/qpar-report-auto-parallelizer-reporting-level.md).

### <a name="to-set-the-qpar-compiler-option-in-visual-studio"></a>Para definir a opção de compilador /Qpar no Visual Studio

1. No **Gerenciador de Soluções**, abra o menu de atalho para o projeto e escolha **Propriedades**.

1. No **páginas de propriedades** caixa de diálogo **C/C++**, selecione **linha de comando**.

1. No **opções adicionais** , digite `/Qpar`.

### <a name="to-set-the-qpar-compiler-option-programmatically"></a>Para definir a opção de compilador /Qpar programaticamente

- Use o exemplo de código em <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[/Q opções (operações de nível baixo)](../../build/reference/q-options-low-level-operations.md)
[/Qpar-report (nível de Paralelizador automático relatórios)](../../build/reference/qpar-report-auto-parallelizer-reporting-level.md)
[opções do compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)<br/>
[#pragma loop()&lt;3](../../preprocessor/loop.md)
[programação paralela em código nativo](https://blogs.msdn.microsoft.com/nativeconcurrency/2012/04/12/auto-vectorizer-in-visual-studio-2012-overview/)