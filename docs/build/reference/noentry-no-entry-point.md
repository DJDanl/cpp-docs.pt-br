---
title: "/NOENTRY (sem ponto de entrada) | Microsoft Docs"
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
  - "VC.Project.VCLinkerTool.ResourceOnlyDLL"
  - "/noentry"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /NOENTRY [C++]"
  - "DLLs [C++], criando"
  - "pontos de entrada [C++], especificação de vinculador"
  - "opção de vinculador NOENTRY"
  - "opção de vinculador -NOENTRY"
  - "DLLs somente de recursos [C++], criando"
ms.assetid: 0214dd41-35ad-43ab-b892-e636e038621a
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /NOENTRY (sem ponto de entrada)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/NOENTRY  
```  
  
## Comentários  
 A opção \/NOENTRY é necessária para a criação de uma DLL apenas de recursos que não contenha códigos executáveis.  Para obter mais informações, consulte [Criando uma DLL somente de recurso](../../build/creating-a-resource-only-dll.md).  
  
 Use essa opção para impedir que o LINK vincule uma referência a `_main` na DLL.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto.  Para obter detalhes, consulte [Configurando as propriedades do projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Selecione a pasta **Vinculador**.  
  
3.  Selecione a página de propriedades **Avançado**.  
  
4.  Modifique a propriedade **Nenhum Ponto de Entrada**.  
  
### Para definir esta opção do vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.ResourceOnlyDLL%2A>.  
  
## Consulte também  
 [Criando uma DLL somente de recurso](../../build/creating-a-resource-only-dll.md)   
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)