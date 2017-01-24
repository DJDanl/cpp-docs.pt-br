---
title: "/NXCOMPAT (compat&#237;vel com Preven&#231;&#227;o de Execu&#231;&#227;o de Dados) | Microsoft Docs"
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
  - "/NXCOMPAT"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /NXCOMPAT"
  - "opção de vinculador NXCOMPAT"
  - "opção de vinculador -NXCOMPAT"
ms.assetid: 5858e7ff-24d3-4ac3-9046-af2c9e220d9b
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /NXCOMPAT (compat&#237;vel com Preven&#231;&#227;o de Execu&#231;&#227;o de Dados)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Indica que um executável foi testado quanto a compatibilidade com o recurso do Windows Data Execution Prevention.  
  
## Sintaxe  
  
```  
/NXCOMPAT[:NO]  
```  
  
## Comentários  
 Por padrão, **\/NXCOMPAT** está ativado.  
  
 **\/NXCOMPAT:NO** pode ser usado para especificar explicitamente um executável como incompatível com Data Execution Prevention.  
  
 Para obter mais informações sobre a prevenção de execução de dados, consulte esses artigos:  
  
-   [Uma descrição detalhada do recurso de Prevenção de Execução de Dados \(DEP\)](http://go.microsoft.com/fwlink/?LinkID=157771) no site de suporte e na ajuda da Microsoft  
  
-   [Prevenção de execução de dados](http://go.microsoft.com/fwlink/?LinkID=157770) no site do MSDN  
  
-   [Prevenção de execução de dados \(Windows Embedded\)](http://go.microsoft.com/fwlink/?LinkID=157768) no site do MSDN  
  
### Para definir essa opção de vinculador no Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **Linha de Comando**.  
  
4.  Digite a opção na caixa **Opções Adicionais**.  
  
### Para definir essa opção de vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)