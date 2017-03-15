---
title: "/TLBID (especificar ID do recurso para TypeLib) | Microsoft Docs"
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
  - "/tlbid"
  - "VC.Project.VCLinkerTool.TypeLibraryResourceID"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Arquivos .tlb, especificando a ID de recurso"
  - "Opção de vinculador /TLBID"
  - "arquivos tlb, especificando a ID de recurso"
  - "opção de vinculador TLBID"
  - "opção de vinculador -TLBID"
  - "bibliotecas de tipo, especificando a ID de recurso"
ms.assetid: 434b28a2-4656-4d52-ac82-8b18bf486fb2
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /TLBID (especificar ID do recurso para TypeLib)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/TLBID:id  
```  
  
## Comentários  
 onde:  
  
 `id`  
 Um valor especificado pelo usuário para uma biblioteca vinculador\- criada do tipo.  Substitui a ID do recurso padrão de 1.  
  
## Comentários  
 Ao criar um programa que usa atributos, o vinculador criará uma biblioteca de tipos.  O vinculador atribuirá uma ID de recurso de 1 para a biblioteca de tipos.  
  
 Se esse ID de recurso entra em conflito com um de seus recursos existentes, você pode especificar outro ID com \/TLBID.  O intervalo de valores que você pode passar a `id` é de 1 a 65535.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **IDL Inserida** .  
  
4.  Modifique a propriedade de **ID de Recurso TypeLib** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.TypeLibraryResourceID%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)