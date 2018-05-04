---
title: Expressões de constante C++ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- constant expressions, syntax
- constant expressions
- expressions [C++], constant
ms.assetid: b07245a5-4c21-4589-b503-e6ffd631996f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d71427c7176d8448d861c6dd7602b6bc91941737
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="c-constant-expressions"></a>Expressões de constante C++
Um *constante* valor é aquele que não é alterado. C++ fornece duas palavras-chave para ativar expressar a intenção de que um objeto não se destina a ser modificada e para impor essa intenção.  
  
 O C++ requer expressões constantes — expressões que são avaliadas como uma constante — para declarações de:  
  
-   Limites de matriz  
  
-   Seletores em instruções case  
  
-   Especificação de comprimento do campo de bits  
  
-   Inicializadores de enumeração  
  
 Os únicos operandos que são válidos em expressões constantes são:  
  
-   Literais  
  
-   Constantes de enumeração  
  
-   Valores declarados como const que são inicializados com expressões constantes  
  
-   Expressões `sizeof`  
  
 As constantes não integral devem ser convertidas (explicitamente ou implicitamente) em tipos integrais para serem válidas em uma expressão constante. Portanto, o código a seguir é válido:  
  
```  
const double Size = 11.0;  
char chArray[(int)Size];  
```  
  
 Conversões explícitas de tipos integrais são válidas em expressões de constante; todos os outros tipos e tipos derivados são ilegais exceto quando usado como operandos para o `sizeof` operador.  
  
 O operador vírgula e os operadores de atribuição não podem ser usados em expressões constantes.  
  
## <a name="see-also"></a>Consulte também  
 [Tipos de expressões](../cpp/types-of-expressions.md)