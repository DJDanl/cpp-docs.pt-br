---
title: "/ALLOWBIND (evitar associa&#231;&#227;o de DLL) | Microsoft Docs"
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
  - "VC.Project.VCLinkerTool.PreventDLLBinding"
  - "/allowbind"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /ALLOWBIND"
  - "opções de vinculador ALLOWBIND"
  - "opções de vinculador -ALLOWBIND"
  - "DLLs de associação"
  - "DLLs [C++], impedindo a associação"
  - "impedindo a associação de DLL"
ms.assetid: 30e37e24-12e4-407e-988a-39d357403598
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /ALLOWBIND (evitar associa&#231;&#227;o de DLL)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/ALLOWBIND[:NO]  
```  
  
## Comentários  
 \/ALLOWBIND:NO define um bit no cabeçalho de uma DLL, o que indica ao Bind.exe que não é possível associar a imagem.  Talvez você não queira que uma DLL seja vinculada caso ela tenha sido assinada digitalmente \(a associação invalida a assinatura\).  
  
 É possível editar uma DLL existente para a funcionalidade \/ALLOWBIND com a opção [\/ALLOWBIND](../../build/reference/allowbind.md) do utilitário EDITBIN.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto.  Para obter detalhes, consulte [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Expanda **Propriedades de Configuração**, **Vinculador** e selecione **Linha de Comando**.  
  
3.  Insira `/ALLOWBIND:NO` em **Opções Adicionais**.  
  
### Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)   
 [Função BindImage](http://msdn.microsoft.com/library/windows/desktop/ms679278.aspx)   
 [Função BindImageEx](http://msdn.microsoft.com/library/windows/desktop/ms679279.aspx)