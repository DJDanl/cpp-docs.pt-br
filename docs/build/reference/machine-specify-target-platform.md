---
title: "/MACHINE (especificar plataforma de destino) | Microsoft Docs"
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
  - "VC.Project.VCLinkerTool.TargetMachine"
  - "/machine"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /MACHINE"
  - "opção de vinculador MACHINE"
  - "opção de vinculador -MACHINE"
  - "arquivos de mapa, criando vinculador"
  - "plataforma de destino"
ms.assetid: 8d41bf4b-7e53-4ab9-9085-d852b08d31c2
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /MACHINE (especificar plataforma de destino)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/MACHINE:{ARM|EBC|X64|X86}  
```  
  
## Comentários  
 A opção \/MACHINE especifica a plataforma de destino para o programa.  
  
 Normalmente, você não tem que especificar a opção \/MACHINE.  O LINK infere o tipo de computador dos arquivos de .obj.  Entretanto, em algumas circunstâncias, o LINK não pode determinar o tipo de computador e não emite [o vinculador de ferramentas do erro LNK1113](../../error-messages/tool-errors/linker-tools-error-lnk1113.md).  Se esse erro ocorrer, especifique \/MACHINE.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **Avançado** .  
  
4.  Modifique a propriedade de **Computador de Destino** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.TargetMachine%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)