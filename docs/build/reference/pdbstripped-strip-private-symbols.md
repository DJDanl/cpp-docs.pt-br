---
title: -PDBSTRIPPED (remover símbolos privados) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /pdbstripped
- VC.Project.VCLinkerTool.StripPrivateSymbols
dev_langs:
- C++
helpviewer_keywords:
- /PDBSTRIPPED linker option
- -PDBSTRIPPED linker option
- .pdb files, stripping private symbols
- PDB files, stripping private symbols
- PDBSTRIPPED linker option
ms.assetid: 9b9e0070-6a13-4142-8180-19c003fbbd55
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 331e490512afe8e9267eb1d0d370cbcf99aa99aa
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="pdbstripped-strip-private-symbols"></a>/PDBSTRIPPED (remover símbolos privados)
```  
/PDBSTRIPPED:pdb_file_name  
```  
  
## <a name="remarks"></a>Comentários  
 em que:  
  
 *pdb_file_name*  
 Um nome de usuário especificado para o banco de dados distribuído de programa (PDB) que o vinculador cria.  
  
## <a name="remarks"></a>Comentários  
 A opção /PDBSTRIPPED cria um segundo arquivo de programa (PDB) de banco de dados quando você criar a imagem de programa com o compilador ou vinculador opções que geram um arquivo PDB ([/Debug](../../build/reference/debug-generate-debug-info.md), [/Z7](../../build/reference/z7-zi-zi-debug-information-format.md), /Zd ou /Zi). Este segundo arquivo PDB omite os símbolos que você não desejaria enviar aos seus clientes. O segundo arquivo PDB conterá apenas:  
  
-   Símbolos públicos  
  
-   A lista de arquivos de objeto e as partes do executável para o qual eles contribuem  
  
-   Registros de depuração do quadro ponteiro otimização (FPO) usados para percorrer a pilha  
  
 O arquivo PDB extraído não conterá:  
  
-   Informações de tipo  
  
-   Informações de número de linha  
  
-   Símbolos de CodeView de arquivo por objeto, como aqueles para funções, variáveis locais e dados estáticos  
  
 O arquivo PDB completo ainda será gerado quando você usar /PDBSTRIPPED.  
  
 Se você não criar um arquivo PDB, /PDBSTRIPPED será ignorado.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique o **depurar** página de propriedades.  
  
4.  Modificar o **segmentar símbolos privados** propriedade.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.StripPrivateSymbols%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)