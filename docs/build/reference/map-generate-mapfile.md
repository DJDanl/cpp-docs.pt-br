---
title: "/MAP (gerar mapfile) | Microsoft Docs"
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
  - "/map"
  - "VC.Project.VCLinkerTool.MapFileName"
  - "VC.Project.VCLinkerTool.GenerateMapFile"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /MAP"
  - "opção de vinculador gerar arquivo de mapa"
  - "opção de vinculador MAP"
  - "opção de vinculador -MAP"
  - "opção de vinculador de arquivo de mapa"
  - "arquivos de mapa, criando vinculador"
  - "arquivos de mapa, informações sobre o programa que está sendo vinculado"
  - "arquivos de mapa, especificando o nome do arquivo"
ms.assetid: 9ccce53d-4e36-43da-87b0-7603ddfdea63
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /MAP (gerar mapfile)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/MAP[:filename]  
```  
  
## Comentários  
 onde:  
  
 *filename*  
 Um nome especificado pelo usuário para o mapfile.  Substitui o nome padrão.  
  
## Comentários  
 A opção \/MAP diz o vinculador para criar um mapfile.  
  
 Por padrão, o vinculador nomes do mapfile com o nome de base de programa e a extensão .map.  *O nome de arquivo* opcional permite que você substitua o nome padrão para um mapfile.  
  
 Um mapfile é um arquivo de texto que contém as seguintes informações sobre o programa que está sendo vinculado:  
  
-   O nome do módulo, que é o nome do arquivo de base  
  
-   O carimbo de data\/hora do cabeçalho do arquivo de programa \(não do sistema de arquivos\)  
  
-   Uma lista de grupos no programa, com endereço de início de cada grupo \(como *a seção*:*deslocamento*\), comprimento, nome do grupo, e da classe  
  
-   Uma lista de símbolos públicos, com cada endereço \(como a *seção*:*deslocamento*\), nome de símbolo, endereço comum, e arquivo de .obj onde o símbolo é definido  
  
-   O ponto de entrada \(como a *seção*:*deslocamento*\)  
  
 A opção de [\/MAPINFO](../../build/reference/mapinfo-include-information-in-mapfile.md) especifica informações adicionais para ser incluída no mapfile.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **Depurar** .  
  
4.  Modifique a propriedade de **Gerar Arquivo de Mapa** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.GenerateMapFile%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.MapFileName%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)