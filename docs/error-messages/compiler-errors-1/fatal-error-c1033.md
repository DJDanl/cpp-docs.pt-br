---
title: "Erro fatal C1033 | Microsoft Docs"
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
  - "C1033"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1033"
ms.assetid: 09976c03-8450-4cf7-8b43-1b91c2c2b9f9
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1033
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

não é possível abrir o pdb de base de dados do programa  
  
 Esse erro pode ser causado por um erro de disco.  
  
 No Visual C\+\+ .NET 2002, a localidade do usuário deve ser definida corretamente quando o nome do arquivo \(ou o caminho do diretório para o nome de arquivo\) contêm caracteres de MBCS.  Definir a localidade do sistema não é suficiente; a localidade do usuário deve ser definida para processar caracteres de MBCS.  
  
 Para obter mais informações, consulte [http:\/\/support.microsoft.com\/default.aspx?scid\=kb;en\-us;246007](http://support.microsoft.com/default.aspx?scid=kb;en-us;246007).