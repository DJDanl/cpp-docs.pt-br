---
title: "-DEBUG (gerar informações de depuração) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCLinkerTool.GenerateDebugInformation
- /debug
dev_langs:
- C++
helpviewer_keywords:
- DEBUG linker option
- /DEBUG linker option
- -DEBUG linker option
- PDB files
- debugging [C++], debug information files
- generate debug info linker option
- pdb files, generating debug info
- .pdb files, generating debug info
- debugging [C++], linker option
- program databases [C++]
ms.assetid: 1af389ae-3f8b-4d76-a087-1cdf861e9103
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6f9f424a2e71a3094c9e633cbe5779ef5d75fbe9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="debug-generate-debug-info"></a>/DEBUG (gerar informações de depuração)
```  
/DEBUG[:{FASTLINK|FULL|NONE}]  
```  
  
## <a name="remarks"></a>Comentários  

O **/Debug** opção cria informações de depuração para o executável.    
  
O vinculador coloca as informações de depuração em um arquivo de programa (PDB) de banco de dados. Atualiza o PDB durante compilações subsequentes do programa.  
  
Um executável (arquivo .exe ou DLL) criado para depuração contém o nome e caminho de PDB correspondente. O depurador lê o nome inserido e usa o PDB ao depurar o programa. O vinculador usa o nome base do programa e a extensão. PDB para nomear o banco de dados do programa e incorpora o caminho onde ele foi criado. Para substituir esse padrão, defina [/PDB](../../build/reference/pdb-use-program-database.md) e especifique um nome de arquivo diferente.  

O **/Debug: fastlink** opção deixa as informações de símbolo privada os produtos individuais de compilação usados para criar o arquivo executável. Ele gera um PDB limitado que indexa para as informações de depuração nos arquivos de objeto e usadas para criar o executável em vez de fazer uma cópia completa de bibliotecas. Essa opção pode vincular de dois a quatro vezes mais rápido a geração de PDB completa e é recomendada quando você estiver depurando localmente e tiver os compilação de produtos disponíveis. Esta limitado PDB não pode ser usado para depuração quando os produtos de compilação necessários não estão disponíveis, como quando o executável é implantado em outro computador. Em um prompt de comando do desenvolvedor, você pode usar a ferramenta mspdbcmf.exe para gerar um PDB completo desse PDB limitado. No Visual Studio, use os itens de menu do projeto ou de compilação para gerar um arquivo PDB completo para criar um PDB completo para o projeto ou solução.  
  
O **/Debug: full** opção move todas as informações de símbolo privada de produtos individuais de compilação (arquivos de objeto e bibliotecas) em um único PDB e pode ser a parte mais demorada do link. No entanto, o PDB completo pode ser usado para depurar o executável quando outros produtos de compilação não estiverem disponíveis, como quando o executável é implantado.  
  
O **/Debug: nenhum** opção gera um PDB.  
  
Quando você especifica **/Debug** sem opções adicionais, o vinculador assume como padrão **/Debug: full** de linha de comando e makefile compilações, versão cria no Visual Studio IDE e de depuração e versão cria no Visual Studio 2015 e versões anteriores. A partir do Visual Studio de 2017, o sistema de compilação no IDE assume como padrão **/Debug: fastlink** quando você especifica o **/Debug** opção para compilações de depuração. Outros padrões foram alterados para manter a compatibilidade com versões anteriores.  
  
O compilador [compatível C7](../../build/reference/z7-zi-zi-debug-information-format.md) (/ Z7) opção faz com que o compilador deixar as informações de depuração nos arquivos. obj. Você também pode usar o [banco de dados do programa](../../build/reference/z7-zi-zi-debug-information-format.md) opção de compilador (/Zi) para armazenar as informações de depuração em um PDB para o arquivo. obj. O vinculador procura PDB do objeto primeiro no caminho absoluto gravado no arquivo. obj, e, em seguida, no diretório que contém o arquivo. obj. Não é possível especificar o nome do arquivo PDB de um objeto ou o local para o vinculador.  
  
[/ INCREMENTAL](../../build/reference/incremental-link-incrementally.md) está implícita quando /DEBUG é especificado.  
  
/ DEBUG altera os padrões para o [/opt](../../build/reference/opt-optimizations.md) opção de REF de NOREF e ICF para NOICF, portanto, se você quiser que os padrões originais, você deve especificar explicitamente /OPT: ref ou /OPT: ICF.  
  
Não é possível criar um .exe ou. dll que contém informações de depuração. Depurar informações sempre são colocadas em um arquivo. obj ou. PDB.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique o **depuração** página de propriedades.  
  
4.  Modificar o **gerar informações de depuração** propriedade para habilitar a geração de PDB. Isso permite que /Debug: fastlink por padrão no Visual Studio de 2017.  
  
4.  Modificar o **gerar arquivo de banco de dados do programa completo** propriedade para habilitar /Debug: full para a geração de PDB completa para cada compilação incremental.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.GenerateDebugInformation%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)
