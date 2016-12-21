---
title: "/ALIGN (alinhamento da se&#231;&#227;o) | Microsoft Docs"
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
  - "VC.Project.VCLinkerTool.Alignment"
  - "/align"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /ALIGN"
  - "opção de vinculador ALIGN"
  - "opção de vinculador -ALIGN"
  - "alinhamento de seção"
  - "sections"
  - "sections, especificando alinhamento"
ms.assetid: f2f8ac24-e90e-4bea-8205-f2960a3b1740
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /ALIGN (alinhamento da se&#231;&#227;o)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/ALIGN[:number]  
```  
  
## Comentários  
 onde:  
  
 `number`  
 O valor de alinhamento.  
  
## Comentários  
 A opção \/ALIGN especifica o alinhamento de cada seção dentro do espaço de endereço linear de programa.  O argumento de `number` em bytes é e deve ser uma potência de dois.  A opção é 4K \(4096\).  O vinculador emite um aviso se o alinhamento gerenciar uma imagem inválido.  
  
 A menos que você esteja escrevendo um aplicativo como um driver de dispositivo, você não precisa alterar o alinhamento.  
  
 É possível alterar o alinhamento de uma seção específica com o parâmetro alinhe à opção de [\/SECTION](../../build/reference/section-specify-section-attributes.md) .  
  
 O valor de alinhamento que você especifica não pode ser menor que o alinhamento da seção maior.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **Linha de Comando**.  
  
4.  Digite a opção na caixa de **Opções Adicionais** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)