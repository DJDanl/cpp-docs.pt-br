---
title: "/DRIVER (driver de modo Kernel do Windows NT) | Microsoft Docs"
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
  - "VC.Project.VCLinkerTool.driver"
  - "/driver"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /DRIVER"
  - "opção de vinculador DRIVER"
  - "opção de vinculador -DRIVER"
  - "driver de modo kernel"
ms.assetid: aeee8e28-5d97-40f5-ba16-9f370fe8a1b8
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /DRIVER (driver de modo Kernel do Windows NT)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/DRIVER[:UPONLY | :WDM]  
```  
  
## Comentários  
 Use a opção do vinculador de \/DRIVER criar um driver do modo kernel do Windows NT.  
  
 **\/DRIVER:UPONLY** faz com que o vinculador adiciona o bit de **IMAGE\_FILE\_UP\_SYSTEM\_ONLY** as características no cabeçalho de saída para especificar que é um driver \(UP\) de monoprocessador.  O sistema operacional recusará carregar um driver de UP em um sistema \(MP\) de multiprocessador.  
  
 **\/DRIVER:WDM** faz com que o vinculador definir o bit de **IMAGE\_DLLCHARACTERISTICS\_WDM\_DRIVER** no campo opcional de DllCharacteristics de cabeçalho.  
  
 Se **\/DRIVER** não for especificado, estes bits não estão definidos pelo vinculador.  
  
 Se **\/DRIVER** for especificado:  
  
-   \/FIXED:NO é aplicado \([\/FIXED \(endereço básico fixo\)](../../build/reference/fixed-fixed-base-address.md)\).  
  
-   A extensão do arquivo de saída será .sys.  Use **\/OUT** para alterar o nome de arquivo e extensão padrão \([\/OUT \(nome do arquivo de saída\)](../../build/reference/out-output-file-name.md)\).  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **Sistema** .  
  
4.  Modifique a propriedade de **Driver** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
1.  Consulte `P:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.driver`.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)