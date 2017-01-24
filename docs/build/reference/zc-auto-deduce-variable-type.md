---
title: "/Zc:auto (deduzir tipo vari&#225;vel) | Microsoft Docs"
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
  - "/Zc:auto"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "opções de compilador /Zc (C++)"
  - "Deduzir tipo de variável (C++)"
  - "opções de compilador Zc (C++)"
  - "opções de compilador -Zc (C++)"
ms.assetid: 5f5bc102-44c3-4688-bbe1-080594dcee5c
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Zc:auto (deduzir tipo vari&#225;vel)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A opção **\/Zc:auto\[\-\]** do compilador instrui o compilador sobre como usar a [palavra\-chave "auto"](../../cpp/auto-keyword.md) para declarar variáveis.  Se você especificar a opção padrão, **\/Zc:auto**, o compilador deduzirá o tipo de variável declarada com base em sua expressão de inicialização.  Se você especificar  **\/Zc:auto\-**, o compilador alocará a variável na classe de armazenamento automática.  
  
## Sintaxe  
  
```  
/Zc:auto[-]  
```  
  
## Comentários  
 O padrão C\+\+ define um significado original e um significado revisado para a palavra\-chave `auto`.  Antes de [!INCLUDE[cpp_dev10_long](../Token/cpp_dev10_long_md.md)], a palavra\-chave declara uma variável na classe de armazenamento automática, ou seja, uma variável que tem tempo de vida local.  Começando com [!INCLUDE[cpp_dev10_long](../Token/cpp_dev10_long_md.md)], a palavra\-chave deduz o tipo de variável com base na expressão de inicialização da declaração. Use a opção **\/Zc:auto\[\-\]** do compilador para instruí\-lo a usar o significado original ou revisado da palavra\-chave `auto`.  
  
 O compilador emite uma mensagem de diagnóstico pertinente se o uso da palavra\-chave `auto` for contrário à opção atual do compilador.  Para obter mais informações, consulte [Palavra\-chave auto](../../cpp/auto-keyword.md).  Para obter mais informações sobre problemas de conformidade com o Visual C\+\+, consulte [Comportamento não padrão](../Topic/Nonstandard%20Behavior.md).  
  
### Para definir essa opção do compilador no Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto.  Para obter detalhes, consulte [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique no nó **Propriedades de Configuração**.  
  
3.  Clique no nó **C\/C\+\+**.  
  
4.  Clique no nó **Linha de Comando**.  
  
5.  Adicione **\/Zc:auto** ou **\/Zc:auto\-** ao painel **Opções Adicionais:**.  
  
## Consulte também  
 [\/Zc \(conformidade\)](../../build/reference/zc-conformance.md)   
 [Palavra\-chave auto](../../cpp/auto-keyword.md)