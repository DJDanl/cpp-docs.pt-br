---
title: "-INCLUDE (forçar referências de símbolo) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /include
- VC.Project.VCLinkerTool.ForceSymbolReferences
dev_langs: C++
helpviewer_keywords:
- INCLUDE linker option
- force symbol references linker option
- symbol references linker force
- /INCLUDE linker option
- symbols, add to symbol table
- -INCLUDE linker option
ms.assetid: 4a039677-360a-480f-bd0b-448e239b449c
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 8caf060d278e7ac2c92c38ad58e9c4c55eab632c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="include-force-symbol-references"></a>/INCLUDE (forçar referências de símbolo)
```  
/INCLUDE:symbol  
```  
  
## <a name="remarks"></a>Comentários  
 em que:  
  
 `symbol`  
 Especifica um símbolo a ser adicionada à tabela de símbolos.  
  
## <a name="remarks"></a>Comentários  
 A opção /INCLUDE informa o vinculador para adicionar um símbolo especificado para a tabela de símbolos.  
  
 Para especificar vários símbolos, digite uma vírgula (,), um ponto e vírgula (;) ou um espaço entre os nomes de símbolos. Na linha de comando, especifique /INCLUDE:`symbol` uma vez para cada símbolo.  
  
 Resolve o vinculador `symbol` adicionando o objeto que contém a definição do símbolo para o programa. Esse recurso é útil para a inclusão de um objeto de biblioteca que, caso contrário, não deve ser vinculado ao programa.  
  
 Especificar um símbolo com essa opção substitui a remoção desse símbolo por [/OPT: REF](../../build/reference/opt-optimizations.md).  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique o **entrada** página de propriedades.  
  
4.  Modificar o **forçar referências de símbolo** propriedade.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.ForceSymbolReferences%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)