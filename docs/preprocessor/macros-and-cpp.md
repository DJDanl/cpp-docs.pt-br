---
title: Macros e C++ | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- macros, C++
- macros
ms.assetid: 83a344c1-73c9-4ace-8b93-cccfb62c6133
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b2af5a370502069befa4a9410e8b324ccc3756e6
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="macros-and-c"></a>Macros e C++
C++ oferece recursos novos. Alguns deles substituem os oferecidos pelo pré-processador ANSI C. Esses novos recursos aprimoram a segurança do tipo e a previsibilidade da linguagem:  
  
-   No C++, objetos declarado como **const** podem ser usados em expressões de constante. Isso permite que os programas declarem as constantes que têm informações de tipo e valor e as enumerações que podem ser exibidas simbolicamente com o depurador. Usar a política de pré-processador `#define` para definir constantes não é um procedimento tão preciso. Nenhum armazenamento é alocado para um **const** , a menos que uma expressão que usa seu endereço encontra-se no programa do objeto.  
  
-   O recurso da função integrada C++ substitui macros de tipo de função. As vantagens de usar funções integradas sobre as macros são:  
  
    -   Segurança de tipo. As funções integradas estão sujeitas à mesma verificação de tipo que as funções normais. As macros não são do tipo seguro.  
  
    -   Corrija a manipulação de argumentos que têm efeitos colaterais. As funções integradas avaliam as expressões fornecidas como argumentos antes de inserir o corpo da função. Portanto, não há nenhuma possibilidade de uma expressão com efeitos colaterais não seja segura.  
  
 Para obter mais informações sobre funções embutidas, consulte [inline, inline, \__forceinline](../cpp/inline-functions-cpp.md).  
  
 Para compatibilidade com versões anteriores, todas as instalações de pré-processadores que existiam em ANSI C e nas especificações anteriores do C++ são preservadas para o Microsoft C++.  
  
## <a name="see-also"></a>Consulte também  
 [Macros predefinidas](../preprocessor/predefined-macros.md)   
 [Macros (C/C++)](../preprocessor/macros-c-cpp.md)