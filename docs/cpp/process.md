---
title: "process | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "Process"
  - "process_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __declspec [C++], process"
  - "palavra-chave de processo __declspec"
ms.assetid: 60eecc2f-4eef-4567-b9db-aaed34733023
caps.latest.revision: 16
caps.handback.revision: 16
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# process
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especifica que o processo de aplicativo gerenciado deve ter uma única cópia de uma determinada variável global, variável de membro estática ou variável local estática compartilhada por todos os domínios de aplicativo no processo.  Isso serve basicamente para ser usado ao compilar com **\/clr:pure**, porque sob **\/clr:pure**, por padrão, as variáveis globais e estáticas são definidas por domínio de aplicativo.  Por padrão, ao compilar com **\/clr**, as variáveis globais e estáticas são definidas por processo \(não precisam usar `__declspec(process)`\).  
  
 Somente uma variável global, uma variável de membro estática ou uma variável local estática de tipo nativo podem ser marcadas com `__declspec(process)`.  
  
 Ao compilar com **\/clr:pure**, as variáveis marcadas como "por processo" também devem ser declaradas como `const`.  Isso assegura que as variáveis por processo não sejam alteradas em um domínio de aplicativo, gerando resultados inesperados em outro domínio de aplicativo.  O principal uso pretendido de `__declspec(process)` é habilitar a inicialização em tempo de compilação de uma variável global, variável de membro estática ou variável local estática sob **\/clr:pure**.  
  
 `process` só é válido quando se compila com [\/clr](../build/reference/clr-common-language-runtime-compilation.md) ou **\/clr:pure** e não é válido quando se compila com **\/clr:safe**.  
  
 Se você quiser que cada domínio de aplicativo tenha sua própria cópia de uma variável global, use [appdomain](../Topic/appdomain.md).  
  
 Consulte [Domínios de aplicativo e Visual C\+\+](../dotnet/application-domains-and-visual-cpp.md) para obter mais informações.  
  
## Consulte também  
 [\_\_declspec](../cpp/declspec.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)