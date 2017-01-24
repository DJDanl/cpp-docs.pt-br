---
title: "Erro fatal C1037 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "C1037"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1037"
ms.assetid: 79103bca-ccfb-42e7-aef9-9b90c15b162f
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1037
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

não é possível abrir o arquivo de objeto  
  
 O arquivo de objeto especificado por [\/Fo](../../build/reference/fo-object-file-name.md) não pode ser aberto.  
  
### Para corrigir verificando as possíveis causas  
  
1.  Nome de arquivo inválido.  
  
2.  Memória insuficiente para abrir o arquivo.  
  
3.  Outro processo está usando o arquivo.  
  
4.  Um arquivo somente leitura tem o mesmo nome.  
  
 No Visual C\+\+ .NET \(versão 1300 do compilador\), há um bug que requer que a localidade do usuário para definir corretamente quando o nome do arquivo \(ou o caminho de diretório para o nome do arquivo\) contém caracteres MBCS. Definir a localidade do sistema não é suficiente; a localidade do usuário deve ser configurada para processar caracteres MBCS.