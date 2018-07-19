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
ms.openlocfilehash: fef56154f34f645b279ffccd99915d366388cb06
ms.sourcegitcommit: 76fd30ff3e0352e2206460503b61f45897e60e4f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/13/2018
ms.locfileid: "39026696"
---
# <a name="c-constant-expressions"></a>Expressões de constante C++
Um *constante* valor é um que não é alterada. C++ fornece duas palavras-chave para que você possa expressar a intenção de que um objeto não se destina a ser modificado e para forçar essa intenção.  
  
O C++ requer expressões constantes — expressões que são avaliadas como uma constante — para declarações de:  
  
 -   Limites de matriz  
      
 -   Seletores em instruções case  
      
 -   Especificação de comprimento do campo de bits  
      
 -   Inicializadores de enumeração  
  
Os únicos operandos que são válidos em expressões constantes são:  
  
 -   Literais  
      
 -   Constantes de enumeração  
      
 -   Valores declarados como const que são inicializados com expressões constantes  
      
 -   **sizeof** expressões  
  
As constantes não integral devem ser convertidas (explicitamente ou implicitamente) em tipos integrais para serem válidas em uma expressão constante. Portanto, o código a seguir é válido:  
  
```cpp 
const double Size = 11.0;  
char chArray[(int)Size];  
```  
  
Conversões explícitas em tipos integrais são válidas em expressões constantes; todos os outros tipos e tipos derivados são inválidos, exceto quando usados como operandos para o `sizeof` operador.  
  
O operador vírgula e os operadores de atribuição não podem ser usados em expressões constantes.  
  
## <a name="see-also"></a>Consulte também  
 [Tipos de expressões](../cpp/types-of-expressions.md)