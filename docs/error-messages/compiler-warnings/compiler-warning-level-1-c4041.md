---
title: "Compilador C4041 de aviso (n&#237;vel 1) | Microsoft Docs"
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
  - "C4041"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4041"
ms.assetid: 107ee9fd-4b88-4f22-a18f-a20726831095
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4041 de aviso (n&#237;vel 1)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

limite do compilador: encerrando a saída do navegador  
  
 Informações sobre o navegador excedeu o limite do compilador.  
  
 Esse aviso pode ser causado por compilar com [\/FR](../../build/reference/fr-fr-create-dot-sbr-file.md) \(informações de navegador incluindo variáveis locais\).  
  
### Para corrigir, usando as seguintes soluções possíveis  
  
1.  Compile com \/Fr \(informações do navegador sem variáveis locais\).  
  
2.  Desabilite a saída do navegador \(compilar sem \/FR ou \/Fr\).