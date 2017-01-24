---
title: "/DELAYLOAD (importa&#231;&#227;o de carga com atraso) | Microsoft Docs"
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
  - "/delayload"
  - "VC.Project.VCLinkerTool.DelayLoadDLLS"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /DELAYLOAD"
  - "carregamento atrasado de DLLs, Opção /DELAYLOAD"
  - "opção de vinculador DELAYLOAD"
  - "opção de vinculador -DELAYLOAD"
ms.assetid: 39ea0f1e-5c01-450f-9c75-2d9761ff9b28
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /DELAYLOAD (importa&#231;&#227;o de carga com atraso)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/DELAYLOAD:dllname  
  
```  
  
## Parâmetros  
 `dllname`  
 O nome de uma DLL que você deseja atrasar a carga.  
  
## Comentários  
 A opção \/DELAYLOAD faz com que a DLL especificada pelo `dllname` seja carregada apenas na primeira chamada pelo programa para uma função nessa DLL.  Para obter mais informações, consulte [Suporte de vinculador para DLLs carregadas com atraso](../../build/reference/linker-support-for-delay-loaded-dlls.md).  Você pode usar essa opção quantas vezes for necessário para especificar quantas DLLs desejar.  Você deve usar o Delayimp.lib quando vincular o programa ou pode implementar sua própria função auxiliar de carga com atraso.  
  
 A opção [\/DELAY](../../build/reference/delay-delay-load-import-settings.md) especifica opções de associação e carregamento para cada DLL de carga com atraso.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto.  Para obter detalhes, consulte [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Na pasta **Vinculador**, selecione a página de propriedades **Entrada**.  
  
3.  Modifique a propriedade **DLLs de Carga com Atraso**.  
  
### Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.DelayLoadDLLs%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)