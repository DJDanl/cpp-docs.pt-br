---
title: "Conformidade com ANSI C | Microsoft Docs"
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
  - "Ansi"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "ANSI [C++], Padrão C"
  - "compatibilidade [C++], ANSI C"
  - "conformidade com ANSI C"
  - "convenções [C++], extensões da Microsoft"
  - "convenções de nomenclatura de extensões da Microsoft"
  - "convenções de nomenclatura [C++], biblioteca da Microsoft"
  - "sublinhados"
  - "sublinhados, à esquerda"
ms.assetid: 6be271bf-eecf-491a-a928-0ee2dd60e3b9
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Conformidade com ANSI C
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A convenção de nomenclatura para todos os identificadores microsoft específicos no sistema de tempo de execução \(como funções, macros, constantes, variáveis, e definições de tipo\) é ANSI\- compatível.  Nesta documentação, qualquer função de tempo de execução e que os padrões de ANSI\/ISO C for notada como sendo ANSI compatível.  Os aplicativos ANSI\- correspondentes devem usar somente essas funções correspondentes ANSI.  
  
 Os nomes de funções específicas da microsoft e variáveis globais começam com um sublinhado único.  Esses nomes podem ser substituída apenas localmente, no escopo do código.  Por exemplo, quando você inclui arquivos de cabeçalho de tempo de execução da Microsoft, você pode ainda assim poderá substituir a função microsoft específica nomeada `_open` declarando uma variável local com o mesmo nome.  Porém, você não pode usar esse nome para seu próprio função global ou variável global.  
  
 Os nomes de macros microsoft específicos e constantes manifestas começam com dois sublinhados, ou com um único sublinhado principal imediatamente seguido por uma letra maiúscula.  O escopo desses identificadores é absoluto.  Por exemplo, você não pode usar o microsoft identificador específico **\_UPPER** por isso.  
  
## Consulte também  
 [Compatibilidade](../c-runtime-library/compatibility.md)