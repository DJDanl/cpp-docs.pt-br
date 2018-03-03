---
title: "-FORCE (forçar saída de arquivo) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCLinkerTool.ForceLink
- /force
dev_langs:
- C++
helpviewer_keywords:
- FORCE linker option
- file output in linker
- /FORCE linker option
- -FORCE linker option
ms.assetid: b1e9a218-a5eb-4e60-a4a4-65b4be15e5da
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8ec19beec52a217df1237de41d0bd81ab447a56d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="force-force-file-output"></a>/FORCE (forçar saída de arquivo)
```  
/FORCE:[MULTIPLE|UNRESOLVED]  
```  
  
## <a name="remarks"></a>Comentários  
 A opção /FORCE informa o vinculador para criar um arquivo válido .exe ou DLL mesmo que um símbolo esteja referenciado mas não definido ou está definido de multiplicação.  
  
 A opção /FORCE pode ter um argumento opcional:  
  
-   Use /Force: Multiple para criar um arquivo de saída caso LINK ache mais de uma definição para um símbolo ou não.  
  
-   Use /FORCE: UNRESOLVED para criar um arquivo de saída caso LINK ache um símbolo indefinido ou não. / FORÇAR: não RESOLVIDO será ignorado se o símbolo de ponto de entrada não for resolvido.  
  
 /Force sem argumentos implica múltiplo e não resolvido.  
  
 Um arquivo criado com essa opção pode não funcionar conforme o esperado. O vinculador não será vinculado incrementalmente quando a opção /FORCE é especificada.  
  
 Se um módulo é compilado com **/clr**, **/Force** não criará uma imagem.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique o **linha de comando** página de propriedades.  
  
4.  Digite a opção para o **opções adicionais** caixa.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)