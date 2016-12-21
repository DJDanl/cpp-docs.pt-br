---
title: "&lt; stdexcept &gt; | Microsoft Docs"
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
  - "std.<stdexcept>"
  - "std::<stdexcept>"
  - "<stdexcept>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho stdexcept"
ms.assetid: 495c10b1-1e60-4514-9f8f-7fda11a2f522
caps.latest.revision: 19
caps.handback.revision: 19
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt; stdexcept &gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define várias classes padrão usadas para relatórios de exceções. As classes formam uma hierarquia de derivação derivada da classe [exceção](../standard-library/exception-class1.md) e incluem dois tipos gerais de exceções: erros de tempo de execução e erros lógicos. Os erros lógicos são causados erros do programador. Eles derivam de classe base logic_error e incluem:  
  
-   `domain_error`  
  
-   `invalid_argument`  
  
-   `length_error`  
  
-   `out_of_range`  
  
 Os erros de tempo de execução ocorrerem devido a erros nas funções de biblioteca ou no sistema de tempo de execução. Eles derivam de classe base runtime_error e incluem:  
  
-   `overflow_error`  
  
-   `range_error`  
  
-   `underflow_error`  
  
### <a name="classes"></a>Classes  
  
|||  
|-|-|  
|[Classe domain_error](../standard-library/domain-error-class.md)|A classe serve como a classe base para todas as exceções geradas para relatar um erro de domínio.|  
|[Classe invalid_argument](../standard-library/invalid-argument-class.md)|A classe serve como a classe base para todas as exceções geradas para relatar um argumento inválido.|  
|[Classe length_error](../Topic/length_error%20Class.md)|A classe serve como a classe base para todas as exceções geradas para relatar uma tentativa de gerar um objeto muito longo para ser especificado.|  
|[Classe logic_error](../standard-library/logic-error-class.md)|A classe serve como a classe base para todas as exceções geradas para relatar erros supostamente detectáveis antes de executa o programa, como violações de pré-condições lógicas.|  
|[Classe out_of_range](../standard-library/out-of-range-class.md)|A classe serve como a classe base para todas as exceções geradas para relatar um argumento que está fora do intervalo válido.|  
|[Classe overflow_error](../standard-library/overflow-error-class.md)|A classe serve como a classe base para todas as exceções geradas para relatar um estouro aritmético.|  
|[Classe range_error](../standard-library/range-error-class.md)|A classe serve como a classe base para todas as exceções geradas para relatar um erro de intervalo.|  
|[Classe runtime_error](../Topic/runtime_error%20Class.md)|A classe serve como a classe base para todas as exceções geradas para relatar erros provavelmente podem ser detectados somente quando o programa é executado.|  
|[Classe underflow_error](../standard-library/underflow-error-class.md)|A classe serve como a classe base para todas as exceções geradas para relatar um estouro aritmético.|  
  
## <a name="see-also"></a>Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Segurança de threads na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)

