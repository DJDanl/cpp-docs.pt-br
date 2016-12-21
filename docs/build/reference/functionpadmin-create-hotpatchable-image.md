---
title: "/FUNCTIONPADMIN (Criar imagem hotpatchable) | Microsoft Docs"
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
  - "/functionpadmin"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /FUNCTIONPADMIN"
  - "opção de vinculador -FUNCTIONPADMIN"
ms.assetid: 25b02c13-1add-4fbd-add9-fcb30eb2cae7
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /FUNCTIONPADMIN (Criar imagem hotpatchable)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Preparar uma imagem hotpatching.  
  
## Sintaxe  
  
```  
/FUNCTIONPADMIN[:space]  
```  
  
## Comentários  
 where,  
  
 `space` \(opcional\)  
 A quantidade de preenchimento a adicionar ao início de cada função, 5, 6, ou 16. imagens x86 exigem cinco bytes de preenchimento, as imagens de x64 exigem 6 bytes, e as imagens criadas para a família de processador Itanium exigem 16 bytes de preenchimento no início de cada função.  
  
 Por padrão, o compilador adicionará a quantidade de espaço correta para a imagem, com base no tipo de computador da imagem.  
  
 Para que o vinculador gerencia uma imagem hotpatchable, os arquivos de .obj devem ter sido criados com [\/hotpatch \(Criar imagem hotpatchable\)](../../build/reference/hotpatch-create-hotpatchable-image.md).  
  
 Quando você compila e vincular uma imagem com uma única chamada de cl.exe, **\/hotpatch** implica **\/functionpadmin**.  
  
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