---
title: "Aviso LNK4075 (Ferramentas de Vinculador) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "LNK4075"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK4075"
ms.assetid: f39ad3f9-c263-4cf0-9d70-259fc56ac96d
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso LNK4075 (Ferramentas de Vinculador)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

ignorando “opção” devido à especificação “option2”  
  
 A segunda opção substitui a primeira.  
  
 As opções mutuamente exclusiva do vinculador estão sendo especificadas.  Examine suas opções do vinculador.  Onde as opções do vinculador são especificadas depende de como você está criando o projeto.  
  
-   Se você estiver criando no ambiente de desenvolvimento, examine as páginas de propriedades do vinculador para o projeto e, consulte onde as duas opções do vinculador estão sendo especificadas.  Consulte [Como: Especificar propriedades do projeto com páginas de propriedades](../Topic/How%20to:%20Specify%20Project%20Properties%20with%20Property%20Pages.md) para obter mais informações.  
  
-   Se você construir na linha de comando, examine as opções do vinculador especificadas lá.  
  
-   Se você compila com scripts de criação, examine de seus scripts para ver onde essas opções do vinculador estão sendo especificadas.  
  
 Quando você localiza em que as opções mutuamente exclusiva do vinculador é especificado, remover uma das opções do vinculador.  
  
 Alguns exemplos específicos:  
  
-   Se você vincular um módulo que foi compilado com **\/ZI**, o que implica um padrão interna do vinculador chamou \/EDITANDCONTINUE, e um módulo que foi compilado com: \/OPTReferência, \/OPT: ICF, ou \/INCREMENTAL: NOT, que não implicam nenhuma \/EDITANDCONTINUE, você obterá LNK4075.  Consulte [\/Z7, \/Zi, \/ZI \(depurar formato de informações\)](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md) para maiores informações.