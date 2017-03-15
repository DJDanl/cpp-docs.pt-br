---
title: "Criando texto de arquivo embutido | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "arquivos embutidos, criando texto"
  - "programa NMAKE, arquivos embutidos"
  - "texto, arquivo embutido"
ms.assetid: b8a332ed-8244-4ff8-89e6-029d7f659725
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Criando texto de arquivo embutido
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os arquivos temporários ou embutidos são permanentes.  
  
## Sintaxe  
  
```  
  
      inlinetext  
.  
.  
.  
<<[KEEP | NOKEEP]  
```  
  
## Comentários  
 Especifique *o inlinetext* na primeira linha após o comando.  Marcar o final com os colchetes angulares duplas \(\<\<\) no início de uma linha separada.  O arquivo contém todo o *inlinetext* antes de colchetes de restrição.  *O inlinetext* pode ter expansões e substituições macro, mas não políticas ou comentários de makefile.  Espaços, as guias, e os caracteres de nova linha são tratados literal.  
  
 Um arquivo temporário existir para a duração da sessão e pode ser reutilizado por outros comandos.  Especifique **KEEP** após os colchetes angulares de fechamento para reter o arquivo após a sessão de NMAKE; um arquivo sem nome é preservado em disco com o nome de arquivo gerado.  Não especifique **NOKEEP** ou nada para um arquivo temporário.  **KEEP** e **NOKEEP** não diferenciam maiúsculas de minúsculas.  
  
## Consulte também  
 [Arquivos embutidos em um makefile](../build/inline-files-in-a-makefile.md)