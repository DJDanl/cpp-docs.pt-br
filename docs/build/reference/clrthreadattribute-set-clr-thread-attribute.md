---
title: "/CLRTHREADATTRIBUTE (definir atributo de thread CLR) | Microsoft Docs"
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
  - "VC.Project.VCLinkerTool.CLRThreadAttribute"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /CLRTHREADATTRIBUTE"
  - "opção de vinculador -CLRTHREADATTRIBUTE"
ms.assetid: 4907e9ef-5031-446c-aecf-0a0b32fae1e8
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /CLRTHREADATTRIBUTE (definir atributo de thread CLR)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especificar explicitamente o atributo de threading para o ponto de entrada do programa de CLR.  
  
## Sintaxe  
  
```  
/CLRTHREADATTRIBUTE:{STA|MTA|NONE}  
```  
  
#### Parâmetros  
 MTA  
 Aplicar o atributo de MTAThreadAttribute ao ponto de entrada do programa.  
  
 NONE  
 Mesmo que não especificando \/CLRTHREADATTRIBUTE.  Permite que Common Language Runtime \(CLR\) define o atributo padrão de threading.  
  
 STA  
 Aplicar o atributo de STAThreadAttribute ao ponto de entrada do programa.  
  
## Comentários  
 Defina o atributo do thread é válida apenas ao criar um .exe, porque afeta o ponto de entrada do thread principal.  
  
 Se você usar o ponto de entrada padrão \(main ou wmain, por exemplo\) especifique o modelo de threading usando \/CLRTHREADATTRIBUTE ou colocando o atributo de threading \(STAThreadAttribute ou MTAThreadAttribute\) na função padrão de entrada.  
  
 Se você usar um ponto de entrada não padrão, especifique o modelo de threading usando \/CLRTHREADATTRIBUTE ou colocando o atributo de threading na função não padrão de entrada, e especifique o ponto de entrada não padrão com [\/ENTRY](../../build/reference/entry-entry-point-symbol.md).  
  
 Se o modelo de threading especificado no código\-fonte não concordar com o modelo de threading especificado com \/CLRTHREADATTRIBUTE, o vinculador ignorará \/CLRTHREADATTRIBUTE e aplicará o modelo de threading especificado no código\-fonte.  
  
 Será necessário que você use uma única threading, por exemplo, se seu programa de CLR hospeda um objeto COM que use uma única threading.  Se seu programa de CLR usa a várias threading, não poderá hospedar um objeto COM que use uma única threading.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Expanda o nó **Propriedades de Configuração**.  
  
3.  Expanda o nó **Vinculador**.  
  
4.  Selecione a página de propriedades **Avançadas**.  
  
5.  Modifique a propriedade de **Atributo da Thread CLR** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.CLRThreadAttribute%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)