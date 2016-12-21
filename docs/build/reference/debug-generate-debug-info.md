---
title: "/DEBUG (gerar informa&#231;&#245;es de depura&#231;&#227;o) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "VC.Project.VCLinkerTool.GenerateDebugInformation"
  - "/debug"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "arquivos .pdb, gerando informações de depuração"
  - "Opção de vinculador /DEBUG"
  - "opção de vinculador DEBUG"
  - "opção de vinculador -DEBUG"
  - "depurando [C++], arquivos de informações de depuração"
  - "depurando [C++], Opção de vinculador "
  - "opção de vinculador gerar informações de depuração"
  - "arquivos PDB"
  - "arquivos pdb, gerando informações de depuração"
  - "bancos de dados de programa [C++]"
ms.assetid: 1af389ae-3f8b-4d76-a087-1cdf861e9103
caps.latest.revision: 11
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /DEBUG (gerar informa&#231;&#245;es de depura&#231;&#227;o)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/DEBUG  
```  
  
## Comentários  
 A opção \/DEBUG cria informações de depuração para o arquivo ou a DLL.  
  
 O vinculador coloca informações de depuração em um base de dados \(PDB\) do programa.  Atualiza o PDB durante construções subsequentes do programa.  
  
 Um arquivo .exe ou uma DLL criado depurando contém o nome e o caminho PDB correspondente.  O depurador ler o nome inserido e usa o PDB quando você depura o programa.  O vinculador usa o nome de base de programa e a extensão .pdb para nomear a base de dados do programa, e digite o caminho em que foi criado.  Para substituir essa opção, defina [\/PDB](../../build/reference/pdb-use-program-database.md) e especificar um nome de arquivo diferente.  
  
 A opção de [Somente números de linha](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md) \(\/Zd\) ou de [C7 compatível](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md) do compilador \(\/Z7\) faz com que o compilador deixe informações de depuração nos arquivos de .obj.  Você também pode usar a opção do compilador de [Base de dados do programa](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md) \(\/Zi\) armazenar informações de depuração em um PDB para o arquivo de .obj.  O vinculador procurar o PDB do objeto no primeiro caminho absoluto gravado no arquivo de .obj e, no diretório que contém o arquivo de .obj.  Você não pode especificar o nome de arquivo PDB ou o local de um objeto para o vinculador.  
  
 [\/INCREMENTAL](../../build/reference/incremental-link-incrementally.md) é implícita quando \/DEBUG é especificado.  
  
 \/DEBUG altera as opções para a opção de [\/OPT](../../build/reference/opt-optimizations.md) de referência a NOREF e de ICF a NOICF \(isso, você precisará especificar explicitamente \/OPT: Referência ou \/OPT: ICF\).  
  
 Consulte o artigo da Base de Dados de Conhecimento Q121366, INFO: Arquivos PDB e de DBG \- o que são e como eles funcionam, para obter mais informações sobre arquivos de .PDB e de .DBG.  Você pode localizar artigos da Base de Dados de Conhecimento na Biblioteca MSDN, ou em [http:\/\/support.microsoft.com](http://support.microsoft.com/).  
  
 Não é possível criar um ou um arquivo .dll que contém informações de depuração.  Informações de depuração sempre é colocada em um arquivo .pdb.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **Depuração** .  
  
4.  Modifique a propriedade de **Gerar informações de depuração** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.GenerateDebugInformation%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)