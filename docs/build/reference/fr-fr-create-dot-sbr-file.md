---
title: -De Fr -FR, (criar. Arquivos SBR) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCCLWCECompilerTool.BrowseInformation
- VC.Project.VCCLCompilerTool.BrowseInformation
- /fr
- VC.Project.VCCLCompilerTool.BrowseInformationFile
- VC.Project.VCCLWCECompilerTool.BrowseInformationFile
dev_langs:
- C++
helpviewer_keywords:
- /FR compiler option [C++]
- -FR compiler option [C++]
- FR compiler option [C++]
- symbolic browser information
ms.assetid: 3fd8f88b-3924-4feb-9393-287036a28896
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 911ab24407f74391186568df58f5111253c41cae
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="fr-fr-create-sbr-file"></a>/FR, /Fr (criar arquivo .Sbr)
Cria arquivos. SBR.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/FR[pathname[\filename]]  
/Fr[pathname[\filename]]  
```  
  
## <a name="remarks"></a>Comentários  
 Durante o processo de compilação, a Microsoft procurar informações de arquivo manutenção Utility (BSCMAKE) usa esses arquivos para criar um. Arquivos BSC, que é usado para exibir informações de procura.  
  
 **/FR** cria um arquivo. SBR com informações simbólicas completas.  
  
 **/FR** cria um arquivo. SBR sem informações em variáveis locais.  
  
 Se você não especificar `filename`, o arquivo. SBR obtém o mesmo nome base do arquivo de origem.  
  
 **/FR** é preterido; use **/FR** em vez disso. Para obter mais informações, consulte preteridos e removidos opções do compilador em [opções do compilador listadas por categoria](../../build/reference/compiler-options-listed-by-category.md).  
  
> [!NOTE]
>  Não altere a extensão. SBR. BSCMAKE requer os arquivos intermediários para ter a extensão.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  No painel de navegação, escolha o **C/C++**, **procurar informações** página de propriedades.  
  
3.  Modificar o **Procurar arquivo de informações** ou **permitem procurar informações** propriedade.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.BrowseInformation%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.BrowseInformationFile%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Arquivo de saída (/ F) opções](../../build/reference/output-file-f-options.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)   
 [Especificando o nome de caminho](../../build/reference/specifying-the-pathname.md)