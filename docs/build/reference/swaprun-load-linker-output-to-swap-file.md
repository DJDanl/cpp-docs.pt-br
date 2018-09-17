---
title: -SWAPRUN (carregar saída do vinculador para trocar arquivo) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCLinkerTool.SwapRunFromNet
- /swaprun
- VC.Project.VCLinkerTool.SwapRunFromCD
dev_langs:
- C++
helpviewer_keywords:
- -SWAPRUN linker option
- files [C++], LINK
- LINK tool [C++], output
- linker [C++], copying output to swap file
- swap file for linker output
- output files, linker
- /SWAPRUN linker option
- SWAPRUN linker option
ms.assetid: 4a1e7f46-4399-4161-8dfc-d6a71beaf683
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1867eb55f9ebcaba2d29f7b9b4b2f44a68164390
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45717490"
---
# <a name="swaprun-load-linker-output-to-swap-file"></a>/SWAPRUN (carregar saída do vinculador para trocar arquivo)

```
/SWAPRUN:{NET|CD}
```

## <a name="remarks"></a>Comentários

A opção /SWAPRUN informa o sistema operacional para primeiro copiar o vinculador a saída para um arquivo de permuta e, em seguida, executar a imagem a partir daí. Isso é um recurso do Windows NT 4.0 (e posterior).

Se NET é especificada, o sistema operacional primeiro copiar a imagem binária da rede para um arquivo de permuta e carregá-lo a partir daí. Essa opção é útil para aplicativos em execução na rede. Quando CD é especificado, o sistema operacional irá copiar a imagem em um disco removível para um arquivo de página e, em seguida, carregá-lo.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração de propriedades do projeto Visual C++](../../ide/working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **sistema** página de propriedades.

1. Modifique uma das seguintes propriedades:

   - **Execução de swap do CD**

   - **Execução de swap da rede**

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte as propriedades <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.SwapRunFromCD%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.SwapRunFromNet%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)