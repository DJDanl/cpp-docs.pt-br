---
title: "/FA, /Fa (listando arquivo) | Microsoft Docs"
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
  - "VC.Project.VCCLWCECompilerTool.AssemblerListingLocation"
  - "VC.Project.VCCLCompilerTool.ConfigureASMListing"
  - "VC.Project.VCCLWCECompilerTool.AssemblerOutput"
  - "VC.Project.VCCLCompilerTool.AssemblerListingLocation"
  - "/fa"
  - "VC.Project.VCCLCompilerTool.AssemblerOutput"
  - "VC.Project.VCCLCompilerTool.UseUnicodeForAssemblerListing"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /FA (C++)"
  - "listagem somente de assemblies"
  - "Opção de compilador FA [C++]"
  - "Opção de compilador -FA [C++]"
  - "listando tipo de arquivo"
ms.assetid: c7507d0e-c69d-44f9-b8e2-d2c398697402
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /FA, /Fa (listando arquivo)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Cria um arquivo de listagem que contém o código do assembly.  
  
## Sintaxe  
  
```  
/FA[c|s|u]  
/Fapathname  
```  
  
## Comentários  
 Os argumentos controlam a geração de código de máquina do código\-fonte e e da extensão de arquivo de listagem.  
  
 A tabela a seguir descreve os vários valores a **\/FA**.  É possível especificar mais de um valor a **\/FA**.  Por exemplo, você pode especificar **\/FAsu**.  
  
|Opção|Conteúdo de listagem e extensão de arquivo|  
|-----------|------------------------------------------------|  
|**\/FA**|Código do assembly; .asm|  
|**\/FAc**|Código do computador e o assembly; .cod|  
|**\/FAs**|Código de origem e do assembly; .asm<br /><br /> Se **\/FAcs** for especificado, a extensão de arquivo será .cod|  
|**\/FAu**|Faz com que o arquivo de saída a ser criado no formato de UTF\-8, com um marcador de ordem de byte.  Por padrão, a codificação do arquivo é ANSI, mas uso **\/FAu** se você desejar um arquivo de listagem que exibe corretamente em todo o sistema, ou se você estiver usando arquivo de código\-fonte Unicode como entrada para o compilador.<br /><br /> Se **\/FAsu** for especificado, e se um arquivo de código\-fonte usa a codificação Unicode diferente de UTF\-8, as linhas de código no arquivo de .asm não podem exibir corretamente.|  
  
 Por padrão, o arquivo de listagem obtém o mesmo nome de base que o arquivo de origem.  Você pode alterar o nome do arquivo de listagem e do diretório onde é criada usando a opção de **\/Fa** .  
  
|uso de \/Fa|Resultado|  
|-----------------|---------------|  
|**\/Fa**|Um *source\_file*.asm é criado para cada arquivo de código\-fonte na compilação.|  
|**\/Fa** *filename*|*filename*.asm é colocado no diretório atual.  Válido apenas ao criar um único arquivo de código\-fonte.|  
|**\/Fa** *filename.extension*|*filename.extension* é colocado no diretório atual.  Válido apenas ao criar um único arquivo de código\-fonte.|  
|**\/Fa** *directory*\\|Um *source\_file*.asm é criado e colocado em *directory* especificado para cada arquivo de código\-fonte na compilação.  Observe a barra invertida à direita necessário.  Apenas os caminhos em disco atual são permitidos.|  
|**\/Fa** *directory*\\*filename*|*filename*.asm é colocado em `directory`especificado.  Válido apenas ao criar um único arquivo de código\-fonte.|  
|**\/Fa** *directory*\\*filename.extension*|*filename.extension* é colocado em `directory`especificado.  Válido apenas ao criar um único arquivo de código\-fonte.|  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades de **ARQUIVOS DE SAÍDA** .  
  
4.  Modifique **Localização da Lista ASM** \(**\/Fa**\) ou a propriedade de **Saída do Assembler** \(**\/FA**\) \(**\/FAu** deve ser especificado na página de propriedades de **Linha de Comando** , a caixa de **Opções Adicionais** .  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AssemblerListingLocation%2A> ou <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AssemblerOutput%2A>.  Para especificar **\/FAu**, consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## Exemplo  
 A linha de comando a seguir gerenciar uma origem e um computador código combinados HELLO.cod chamado listagem:  
  
```  
CL /FAcs HELLO.CPP  
```  
  
## Consulte também  
 [Opções do arquivo de saída \(\/F\)](../../build/reference/output-file-f-options.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)   
 [Especificando o nome de caminho](../Topic/Specifying%20the%20Pathname.md)