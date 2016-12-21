---
title: "/PGD (especificar banco de dados para otimiza&#231;&#245;es orientadas por perfil) | Microsoft Docs"
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
  - "VC.Project.VCLinkerTool.ProfileGuidedDatabase"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /PGD"
  - "opção de vinculador -PGD"
ms.assetid: 9f312498-493b-461f-886f-92652257e443
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /PGD (especificar banco de dados para otimiza&#231;&#245;es orientadas por perfil)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

\/PGD:`filename`  
  
## Comentários  
 onde:  
  
 `filename`  
 Especifica o nome do arquivo de .pgd que será usada para manter informações sobre o programa em execução.  
  
## Comentários  
 Ao usar [\/LTCG: PGINSTRUMENT](../../build/reference/ltcg-link-time-code-generation.md), use \/PGD para especificar um nome ou local não padrão para o arquivo de .pgd.  Se você não especificar \/PGD, o nome do arquivo de .pgd será o mesmo que o nome do arquivo de saída \(.exe ou .dll\) e será criado no mesmo diretório do qual o link foi chamado.  
  
 Ao usar \/LTCG:PGOPTIMIZE, use \/PGD para especificar o nome do arquivo de .pgd a ser usado para criar a imagem otimizada.  
  
 Para obter mais informações, consulte [Otimização orientada perfil](../../build/reference/profile-guided-optimizations.md).  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Expanda o nó **Propriedades de Configuração**.  
  
3.  Expanda o nó **Vinculador**.  
  
4.  Selecione a página de propriedades de **Otimização** .  
  
5.  Modifique a propriedade de **Banco de Dados Guiado por Perfil** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.ProfileGuidedDatabase%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)