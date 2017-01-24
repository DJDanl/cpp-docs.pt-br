---
title: "Regras de consist&#234;ncia para uso por arquivo de cabe&#231;alhos pr&#233;-compilados | Microsoft Docs"
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
helpviewer_keywords: 
  - "Arquivos .pch, regras de consistência"
  - "arquivos PCH, regras de consistência"
  - "arquivos de cabeçalho pré-compilado, regras de consistência"
ms.assetid: afd49365-48bc-41f4-b700-fe8297b944a1
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Regras de consist&#234;ncia para uso por arquivo de cabe&#231;alhos pr&#233;-compilados
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A opção do compilador de [\/Yu](../../build/reference/yu-use-precompiled-header-file.md) permite especificar que o arquivo pré\-compilado \(PCH\) de cabeçalho a usar.  
  
 Quando você usa um PCH, o compilador assume o mesmo ambiente de criação — usando opções do compilador consistentes, pragmas, etc — que estava em vigor quando você criou o PCH, a menos que você especifica de outra forma.  Se o compilador detectar uma inconsistência, o emitirá um aviso e identifica a inconsistência sempre que possível.  Esses avisos não indica necessariamente um problema com o PCH; advertem\-no somente de conflitos possíveis.  Os requisitos de consistência para PCHs são descritos nas seções a seguir.  
  
## Consistência da opção do compilador  
 As seguintes opções do compilador podem disparar um aviso de inconsistência ao usar um PCH:  
  
-   Macros criados usando o pré\-processador \(\/D\) a opção deve ser a mesma entre a compilação que criou o PCH e a compilação atual.  O estado de constantes definidas não está marcada, mas os resultados imprevisíveis podem ocorrer se eles são alterados.  
  
-   PCHs não funciona com as opções de \/E e \/EP.  
  
-   PCHs deve ser criado usando a geração na opção de informações \(\/FR\) ou a opção de variáveis locais de exclusão \(\/Fr\) antes que as compilações subsequentes que usam o PCH podem usar essas opções.  
  
## C 7.0\-Compatible 2.0 \(\/Z7\)  
 Se essa opção for aplicado quando o PCH é criado, as compilações subsequentes que usam o PCH podem usar as informações de depuração.  
  
 Se a opção de C 7.0\-Compatible \(\/Z7\) não está em vigor quando o PCH é criado, as compilações subsequentes que usam o gatilho de PCH e \/Z7 um aviso.  Informações de depuração é colocada no arquivo do atual .obj, e símbolos locais definidos no PCH não estão disponíveis para o depurador.  
  
## Inclua a consistência de caminho  
 Um PCH não contém informações sobre o caminho de inclusão que estava em vigor quando foi criado.  Quando você usa um arquivo de .pch, o compilador sempre usa o caminho de inclusão especificado na compilação atual.  
  
## Consistência do arquivo de origem  
 Quando você especificar a opção pré\-compilado de Arquivo de cabeçalho de uso \(\/Yu\), o compilador ignora todas as políticas de pré\-processador \(inclusive pragmas\) que aparecem no código fonte que será pré\-compilado.  A compilação especificada por essas políticas de pré\-processador deve ser igual à compilação usada para a opção pré\-compilado de Arquivo de cabeçalho de criação \(\/Yc\).  
  
## Consistência de pragma  
 Os pragmas processados durante a criação de um PCH geralmente afetam o arquivo com que o PCH é usada subsequentemente.  Os pragmas de comentário e da mensagem não afetam o restante da compilação.  
  
 Os seguintes pragmas são retidos como parte de um PCH, e afetam o restante de uma compilação que use o PCH.  
  
||||  
|-|-|-|  
|alloc\_text|include\_alias|empacotar|  
|auto\_inline|init\_seg|pointers\_to\_members|  
|check\_stack|inline\_depth|setlocale|  
|code\_seg|inline\_recursion|vtordisp|  
|data\_seg|intrínseco|aviso|  
|função|optimize||  
  
## Consulte também  
 [Regras de consistência do cabeçalho pré\-compilado](../../build/reference/precompiled-header-consistency-rules.md)   
 [\/Yu \(usar arquivo de cabeçalho pré\-compilado\)](../../build/reference/yu-use-precompiled-header-file.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)