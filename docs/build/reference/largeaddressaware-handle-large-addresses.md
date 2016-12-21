---
title: "/LARGEADDRESSAWARE (identificar endere&#231;os grandes) | Microsoft Docs"
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
  - "VC.Project.VCLinkerTool.LargeAddressAware"
  - "/largeaddressaware"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /LARGEADDRESSAWARE"
  - "opção de vinculador LARGEADDRESSAWARE"
  - "opção de vinculador -LARGEADDRESSAWARE"
ms.assetid: a29756c8-e893-47a9-9750-1f0d25359385
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /LARGEADDRESSAWARE (identificar endere&#231;os grandes)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/LARGEADDRESSAWARE[:NO]  
```  
  
## Comentários  
 A opção \/LARGEADDRESSAWARE diz ao vinculador que o aplicativo pode tratar endereços de 2 gigabytes maiores.  Nos compiladores de 64 bits, essa opção é habilitada por padrão.  Nos compiladores de 32 bits, \/LARGEADDRESSAWARE:NO \/LARGEADDRESSAWARE será habilitado se não for especificado de outra forma na linha do vinculador.  
  
 Se um aplicativo tiver sido vinculado com \/LARGEADDRESSAWARE, o DUMPBIN [\/HEADERS](../../build/reference/headers.md) exibirá informações para esse efeito.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **Sistema** .  
  
4.  Modifique a propriedade de **Habilitar Endereços Grandes** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.LargeAddressAware%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)