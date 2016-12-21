---
title: "/CLRHEADER | Microsoft Docs"
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
  - "/CLRHEADER"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção /CLRHEADER (dumpbin)"
  - "opção dumpbin CLRHEADER"
  - "opção dumpbin -CLRHEADER"
ms.assetid: cf73424f-4541-47e2-b94e-69b95266ef2a
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /CLRHEADER
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/CLRHEADER file  
```  
  
## Comentários  
 onde:  
  
 `file`  
 Um arquivo de imagem compilado com [\/clr](../../build/reference/clr-common-language-runtime-compilation.md).  
  
## Comentários  
 CLRHEADER exibe informações sobre os cabeçalhos .NET usados em qualquer programa gerenciado.  A saída mostra o local e o tamanho, em bytes, do cabeçalho de .NET e seções no cabeçalho.  
  
 Somente a opção de DUMPBIN de [\/HEADERS](../../build/reference/headers.md) está disponível para uso em arquivos gerados com a opção do compilador de [\/GL](../../build/reference/gl-whole-program-optimization.md) .  
  
 Quando \/CLRHEADER é usado em um arquivo que será criado com \/clr, haverá uma seção de **clr Header:** na saída do dumpbin.  O valor de **flags** indica que opção \/clr foi usada:  
  
-   0  \-\- \/clr \(a imagem pode conter código nativo\).  
  
-   1 \-\- \/clr:safe \(a imagem, MSIL só pode ser executada em qualquer plataforma de CLR e, possivelmente verificável\).  
  
-   3 \-\- \/clr:pure \(a imagem é MSIL apenas, mas apenas capaz de execução nas plataformas x86\).  
  
 Você também pode programaticamente verificar se uma imagem foi criada para Common Language Runtime.  Para obter mais informações, consulte [Como determinar se uma imagem é nativa ou CLR](../Topic/How%20to:%20Determine%20if%20an%20Image%20is%20Native%20or%20CLR.md).  
  
## Consulte também  
 [Opções de DUMPBIN](../../build/reference/dumpbin-options.md)