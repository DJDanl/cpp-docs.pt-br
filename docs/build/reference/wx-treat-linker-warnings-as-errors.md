---
title: "/WX (tratar avisos do vinculador como erros) | Microsoft Docs"
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
  - "/WX"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /WX"
  - "opção de vinculador WX"
  - "opção de vinculador -WX"
ms.assetid: e4ba97c7-93f7-43ae-a4bb-d866790926c9
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /WX (tratar avisos do vinculador como erros)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/WX[:NO]  
```  
  
## Comentários  
 \/WX não provoca nenhum arquivo de saída a ser gerado se o vinculador gerencie um aviso.  
  
 Isso é semelhante a **\/WX** para o compilador \(consulte [\/w, \/W0, \/W1, \/W2, \/W3, \/W4, \/w1, \/w2, \/w3, \/w4, \/Wall, \/wd, \/, \/wo, \/Wv, \/WX \(nível de aviso\)](../../build/reference/compiler-option-warning-level.md) para obter mais informações\).  Porém, especificar **\/WX** para a compilação não significa que **\/WX** também se realizará aplicado para a fase de link; você deve especificar explicitamente **\/WX** para cada ferramenta.  
  
 Por default, **\/WX** não está ativo.  Para tratar avisos do vinculador como erros, especifique **\/WX**.  **\/WX:NO** é o mesmo que não especificando **\/WX**.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **Linha de Comando**.  
  
4.  Digite a opção na caixa de **Opções Adicionais** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)