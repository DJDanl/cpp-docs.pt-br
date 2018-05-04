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
ms.openlocfilehash: 522cd693da1b4e1a72d11119f622d862413b409b
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="swaprun-load-linker-output-to-swap-file"></a>/SWAPRUN (carregar saída do vinculador para trocar arquivo)
```  
/SWAPRUN:{NET|CD}  
```  
  
## <a name="remarks"></a>Comentários  
 A opção /SWAPRUN informa o sistema operacional para primeiro copiar o vinculador de saída para um arquivo de troca e, em seguida, executar a imagem de lá. Este é um recurso do Windows NT 4.0 (e posterior).  
  
 Se NET é especificada, o sistema operacional será primeiro copiar a imagem binária da rede para um arquivo de permuta e carregá-lo de lá. Essa opção é útil para aplicativos em execução na rede. Quando o CD é especificado, o sistema operacional será copiar a imagem em um disco removível para um arquivo de página e, em seguida, carregá-lo.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique o **sistema** página de propriedades.  
  
4.  Modificar uma das seguintes propriedades:  
  
    -   **Execução de swap do CD**  
  
    -   **Execução de swap da rede**  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
1.  Consulte as propriedades <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.SwapRunFromCD%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.SwapRunFromNet%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)