---
title: "/FD (recompila&#231;&#227;o m&#237;nima de IDE) | Microsoft Docs"
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
  - "/FD"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /FD (C++)"
  - "Opção de compilador FD [C++]"
  - "Opção de compilador -FD [C++]"
ms.assetid: 7ef21b8c-a448-4bb4-9585-a2a870028e17
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /FD (recompila&#231;&#227;o m&#237;nima de IDE)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

**\/FD** não é exposta aos usuários exceto na página de propriedades de [Linha de comando](../../ide/command-line-property-pages.md) da caixa de diálogo de **Páginas de Propriedades** de projeto criando c, se e somente se [\/Gm \(Habilitar a recriação mínima\)](../../build/reference/gm-enable-minimal-rebuild.md) também não é.  **\/FD** não tiver nenhum efeito diferente do ambiente de desenvolvimento.  **\/FD** não é exposta na saída de **cl \/?**.  
  
 Se você não habilita **\/Gm** no ambiente de desenvolvimento, **\/FD** será usado.  **\/FD** assegura que o arquivo de .idb tem informações adequadas de dependência.  **\/FD** é usado somente pelo ambiente de desenvolvimento, e não deve ser usado de linha de comando ou de um script de criação.  
  
## Consulte também  
 [Opções do arquivo de saída \(\/F\)](../../build/reference/output-file-f-options.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)