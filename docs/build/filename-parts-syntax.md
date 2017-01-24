---
title: "Sintaxe de partes do nome de arquivo | Microsoft Docs"
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
  - "sintaxe de partes de nome de arquivo em NMAKE"
  - "programa NMAKE, sintaxe"
  - "sintaxe, partes de nome de arquivo"
ms.assetid: 48fe38e0-3f3b-40e6-894c-330ee775a656
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Sintaxe de partes do nome de arquivo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

a sintaxe de Nome de arquivo partes em comandos representa componentes do primeiro nome de arquivo dependente \(que pode ser um dependente implícito\).  Os componentes de nome de arquivo são a unidade do arquivo, o caminho, o nome de base, e a extensão conforme especificado, porque não existe no disco.  Use **%s** para representar o nome de arquivo completo.  Use **%&#124;***partes*\[\]**F** \(um caractere de barra vertical segue o símbolo de porcentagem\) para representar partes do nome de arquivo, onde *as partes* pode ser nulo ou mais das letras, em qualquer ordem.  
  
|Letra|Descrição|  
|-----------|---------------|  
|Nenhuma letra|Nome completo \(mesmo que **%s**\)|  
|**d**|Unidade|  
|**p**|Path|  
|**f**|Nome da base de Arquivo|  
|**e**|Extensão de Arquivo|  
  
 Por exemplo, se o nome de arquivo é c:\\prog.exe:  
  
-   %s será c:\\prog.exe  
  
-   %&#124;F\- 2.0 será c:\\prog.exe  
  
-   %&#124;o dF será c  
  
-   %&#124;o PF será c:\\  
  
-   %&#124;fF será prog  
  
-   %&#124;eF é exe  
  
## Consulte também  
 [Comandos em um makefile](../build/commands-in-a-makefile.md)