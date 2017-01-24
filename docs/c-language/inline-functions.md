---
title: "Fun&#231;&#245;es embutidas | Microsoft Docs"
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
  - "C"
helpviewer_keywords: 
  - "código rápido"
  - "funções [C++], funções embutidas"
  - "funções embutidas, Palavra-chave __inline"
ms.assetid: 00f4b2ff-8ad0-4165-9f4c-2ef157d03f31
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#245;es embutidas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 A palavra\-chave `__inline` diz para o compilador substituir o código na definição de função para cada instância de uma chamada de função.  No entanto, a substituição ocorre apenas ao critério do compilador.  Por exemplo, o compilador não uma embute uma função se seu endereço já estiver em uso ou se for muito grande para embutir.  
  
 Para que uma função seja considerada candidata para embutir, ela deve usar a definição de função de novo estilo.  
  
 Use esse formato para especificar uma função embutida:  
  
 `__inline` *type*opt *function\-definition*`;`  
  
 O uso de funções embutidas gera código mais rápido e às vezes pode gerar código menor do que a chamada de função equivalente gera pelos seguintes motivos:  
  
-   Ela poupa o tempo necessário para executar chamadas de função.  
  
-   As funções embutidas pequenas, talvez três linhas ou menos, criam menos código do que a chamada de função equivalente porque o compilador não gera código para tratar de argumentos e um valor de retorno.  
  
-   As funções geradas embutidas estão sujeitas às otimizações de código não disponíveis para funções normais porque o compilador não executa otimizações entre procedimentos.  
  
 As funções que usam `__inline` não devem ser confundidas com o código de assembler embutido.  Consulte [Assembler embutido](../c-language/inline-assembler-c.md) para obter mais informações.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [inline, \_\_inline, \_\_forceinline](../misc/inline-inline-forceinline.md)