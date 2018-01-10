---
title: "-Gm (habilitar recompilação mínima) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCCLCompilerTool.MinimalRebuild
- /Gm
- /FD
- VC.Project.VCCLWCECompilerTool.MinimalRebuild
dev_langs: C++
helpviewer_keywords:
- /Gm compiler option [C++]
- minimal rebuild
- enable minimal rebuild compiler option [C++]
- Gm compiler option [C++]
- -Gm compiler option [C++]
ms.assetid: d8869ce0-d2ea-40eb-8dae-6d2cdb61dd59
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 8bc9ff065de2b83d50b6fa905fcc6d1123dbe829
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="gm-enable-minimal-rebuild"></a>/Gm (habilitar recompilação manual)
Habilita recompilação mínima, que determina se os arquivos de origem C++ que incluem definições de classe C++ alteradas (armazenadas nos arquivos de cabeçalho (.h)) precisam ser recompilados.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Gm  
```  
  
## <a name="remarks"></a>Comentários  
 O compilador armazena as informações de dependência entre arquivos de origem e definições de classe no arquivo .idb do projeto durante a primeira compilação. (Informações de dependência informam qual arquivo de origem depende de qual definição de classe, e quais. h a definição de arquivo está localizado em.) Compilações subsequentes usam as informações armazenadas no arquivo .idb para determinar se um arquivo de origem precisa ser compilado, mesmo que ele inclui um arquivo. h modificado.  
  
> [!NOTE]
>  A recompilação mínima conta com definições de classe que não mudem entre os arquivos incluídos. As definições de classe devem ser globais para um projeto (deve haver apenas uma definição de uma determinada classe), pois as informações de dependência no arquivo .idb são criadas para todo o projeto. Se você tiver mais de uma definição para uma classe no seu projeto, desabilite a recompilação mínima.  
  
 Como o vinculador incremental não oferece suporte para os metadados do Windows incluído nos arquivos. obj, usando o [/ZW (compilação de tempo de execução do Windows)](../../build/reference/zw-windows-runtime-compilation.md) opção, o **/GM manual** opção é incompatível com  **/ZW**.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **C/C++** pasta.  
  
3.  Clique o **geração de código** página de propriedades.  
  
4.  Modificar o **habilitar recriar mínimo** propriedade.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.MinimalRebuild%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)