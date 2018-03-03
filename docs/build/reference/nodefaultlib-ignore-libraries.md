---
title: -/NODEFAULTLIB (ignorar bibliotecas) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCLinkerTool.OVERWRITEAllDefaultLibraries
- VC.Project.VCLinkerTool.OVERWRITEDefaultLibraryNames
- /nodefaultlib
dev_langs:
- C++
helpviewer_keywords:
- default libraries, removing
- -NODEFAULTLIB linker option
- libraries, ignore
- NODEFAULTLIB linker option
- /NODEFAULTLIB linker option
- ignore libraries linker option
ms.assetid: 7270b673-6711-468e-97a7-c2925ac2be6e
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 24045fbbba41eb9d7ca1929a86d3dd599d3490ba
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="nodefaultlib-ignore-libraries"></a>/NODEFAULTLIB (ignorar bibliotecas)
```  
/NODEFAULTLIB[:library]   
```  
  
## <a name="remarks"></a>Comentários  
 em que:  
  
 *biblioteca*  
 Uma biblioteca que você deseja que o vinculador para ignorar ao resolver referências externas.  
  
## <a name="remarks"></a>Comentários  
 A opção /NODEFAULTLIB informa o vinculador para remover uma ou mais bibliotecas padrão da lista de bibliotecas que busca ao resolver referências externas.  
  
 Para criar um arquivo. obj que não contém referências a bibliotecas padrão, use [/Zl (omitir nome da biblioteca padrão)](../../build/reference/zl-omit-default-library-name.md).  
  
 Por padrão, /NODEFAULTLIB remove todas as bibliotecas padrão da lista de bibliotecas que busca ao resolver referências externas. Opcional *biblioteca* parâmetro permite que você remover uma biblioteca especificada ou bibliotecas da lista de bibliotecas que busca ao resolver referências externas. Especifica uma opção /NODEFAULTLIB para cada biblioteca que você deseja excluir.  
  
 O vinculador resolve referências a definições externas pesquisando primeiro nas bibliotecas que você especifique explicitamente, então padrão bibliotecas especificado com a opção /DEFAULTLIB e, em seguida, em bibliotecas padrão chamadas nos arquivos. obj.  
  
 /NODEFAULTLIB:*biblioteca* substitui [/DEFAULTLIB:](../../build/reference/defaultlib-specify-default-library.md)*biblioteca* quando o mesmo *biblioteca* nome é especificado em ambos.  
  
 Se você usar /NODEFAULTLIB, por exemplo, para criar seu programa sem a biblioteca de tempo de execução do C, você pode ter também use [/ENTRY](../../build/reference/entry-entry-point-symbol.md) para especificar o ponto de entrada (função) em seu programa. Para obter mais informações, consulte [Recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md).  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique o **entrada**página de propriedades.  
  
4.  Selecione o **ignorar todas as bibliotecas padrão** propriedade ou especificar uma lista das bibliotecas de que deseja ignorar no **ignorar biblioteca específica** propriedade. O **linha de comando** página de propriedades mostra o efeito das alterações feitas a essas propriedades.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.IgnoreDefaultLibraryNames%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.IgnoreAllDefaultLibraries%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)