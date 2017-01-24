---
title: "Aviso D9041 (linha de comando) | Microsoft Docs"
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
  - "D9041"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "D9041"
ms.assetid: ada8815f-4246-4e25-b57d-a7f16fa107cc
caps.latest.revision: 3
caps.handback.revision: 3
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso D9041 (linha de comando)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

valor inválido “valor” para “\/option”; supondo que o valor”; “ adicionar “\/analyze” às opções de linha de comando ao especificar esse aviso  
  
 Um número na análise de código foi adicionado a **\/wd**, a **\/we**, a **\/wo**, ou para a opção de linha de comando de **\/wl** sem especificar também a opção de linha de comando de **\/analyze** .  Para resolver esse erro, para adicionar a opção de linha de comando de **\/analyze** , ou para remover o número inválido de aviso da opção de linha de comando apropriado de **\/w** .  
  
## Exemplo  
 O exemplo de linha de comando gerencia o aviso D9041:  
  
```  
cl /EHsc /LD /wd6001 filename.cpp  
```  
  
 Para corrigir o aviso, adicione a opção de linha de comando de **\/analyze** .  Se **\/analyze** não tem suporte na versão do compilador, remova o número inválido de aviso da opção de **\/wd** .  
  
## Consulte também  
 [Erros de linha de comando D8000 até D9999](../../error-messages/tool-errors/command-line-errors-d8000-through-d9999.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)