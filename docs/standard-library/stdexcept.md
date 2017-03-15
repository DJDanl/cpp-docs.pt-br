---
title: '&lt;stdexcept&gt; | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- std.<stdexcept>
- std::<stdexcept>
- <stdexcept>
dev_langs:
- C++
helpviewer_keywords:
- stdexcept header
ms.assetid: 495c10b1-1e60-4514-9f8f-7fda11a2f522
caps.latest.revision: 19
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: a01f0cf531196d59815eb87f03ee9d8a15574088
ms.lasthandoff: 02/25/2017

---
# <a name="ltstdexceptgt"></a>&lt;stdexcept&gt;
Define várias classes padrão usadas para relatórios de exceções. As classes, todas derivadas da classe [exception](../standard-library/exception-class.md), formam uma hierarquia de derivação e incluem dois tipos gerais de exceções: erros em tempo de execução e erros lógicos. Os erros lógicos são causados por erros do programador. Eles derivam da classe base logic_error e incluem:  
  
-   `domain_error`  
  
-   `invalid_argument`  
  
-   `length_error`  
  
-   `out_of_range`  
  
 Os erros em tempo de execução ocorrem devido a erros nas funções de biblioteca ou no sistema de tempo de execução. Eles derivam da classe base runtime_error e incluem:  
  
-   `overflow_error`  
  
-   `range_error`  
  
-   `underflow_error`  
  
### <a name="classes"></a>Classes  
  
|||  
|-|-|  
|[Classe domain_error](../standard-library/domain-error-class.md)|A classe serve como a classe base para todas as exceções geradas para relatar um erro de domínio.|  
|[Classe invalid_argument](../standard-library/invalid-argument-class.md)|A classe serve como a classe base para todas as exceções geradas para relatar um argumento inválido.|  
|[Classe length_error](../standard-library/length-error-class.md)|A classe serve como a classe base para todas as exceções geradas para relatar uma tentativa de gerar um objeto muito longo para ser especificado.|  
|[Classe logic_error](../standard-library/logic-error-class.md)|A classe serve como classe base para todas as exceções geradas para relatar erros supostamente detectáveis antes da execução do programa, como violações de pré-condições lógicas.|  
|[Classe out_of_range](../standard-library/out-of-range-class.md)|A classe serve como a classe base para todas as exceções geradas para relatar um argumento fora de seu intervalo válido.|  
|[Classe overflow_error](../standard-library/overflow-error-class.md)|A classe serve como a classe base para todas as exceções geradas para relatar um estouro aritmético.|  
|[Classe range_error](../standard-library/range-error-class.md)|A classe serve como a classe base para todas as exceções geradas para relatar um erro de alcance.|  
|[Classe runtime_error](../standard-library/runtime-error-class.md)|A classe serve como classe base para todas as exceções geradas para relatar erros supostamente detectáveis somente durante a execução do programa.|  
|[Classe underflow_error](../standard-library/underflow-error-class.md)|A classe serve como a classe base para todas as exceções geradas para relatar um estouro negativo aritmético.|  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)


