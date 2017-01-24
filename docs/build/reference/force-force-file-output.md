---
title: "/FORCE (for&#231;ar sa&#237;da de arquivo) | Microsoft Docs"
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
  - "VC.Project.VCLinkerTool.ForceLink"
  - "/force"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /FORCE"
  - "saída de arquivo no vinculador"
  - "opção de vinculador FORCE"
  - "opção de vinculador -FORCE"
ms.assetid: b1e9a218-a5eb-4e60-a4a4-65b4be15e5da
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /FORCE (for&#231;ar sa&#237;da de arquivo)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/FORCE:[MULTIPLE|UNRESOLVED]  
```  
  
## Comentários  
 A opção \/FORCE diz o vinculador para criar um arquivo .exe ou uma DLL válido mesmo se um símbolo é referenciado mas não multiplica definido ou está definido.  
  
 A opção \/FORCE pode ter um argumento opcional:  
  
-   Use \/FORCE:MULTIPLE para criar um arquivo de saída se o LINK localizar mais de uma definição para um símbolo.  
  
-   Use \/FORCE:UNRESOLVED para criar um arquivo de saída se o LINK localiza um símbolo indefinido. \/FORCE:UNRESOLVED será ignorado se o símbolo de ponto de entrada não for resolvido.  
  
 \/FORCE sem argumentos implica mais e não resolvido.  
  
 Um arquivo criado com essa opção não pode ser executado como esperado.  O vinculador não vinculará incremental quando a opção \/FORCE é especificada.  
  
 Se um módulo foi criado com **\/clr**, **\/FORCE** não criará uma imagem.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **Linha de Comando**.  
  
4.  Digite a opção na caixa de **Opções Adicionais** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)