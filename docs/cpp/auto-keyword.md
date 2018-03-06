---
title: auto Keyword | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: 744a41c0-2510-4140-a1be-96257e722908
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 48c21ec8304fa5c56bb29f07eea4bec169fbda83
ms.sourcegitcommit: 4e01d36ffa64ea11bacf589f79d2f1df947e2510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2018
---
# <a name="auto-keyword"></a>Palavra-chave auto
A palavra-chave `auto` é um especificador de declaração. Porém, o padrão do C++ define um significado original e um significado revisado para essa palavra-chave. Antes de Visual C++ 2010, o `auto` palavra-chave declara uma variável no *automáticas* classe de armazenamento, ou seja, uma variável que possui um tempo de vida de local. Começando com Visual C++ 2010, o `auto` palavra-chave declara uma variável cujo tipo é deduzido da expressão de inicialização na sua declaração. O [/ZC: auto &#91;-&#93;](../build/reference/zc-auto-deduce-variable-type.md) o significado dos controles de opção de compilador o `auto` palavra-chave.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
auto declarator ;  
auto declarator initializer;  
```  
  
## <a name="remarks"></a>Comentários  
 A definição da palavra-chave `auto` muda na linguagem de programação C++, mas não na linguagem de programação C.  
  
 Os tópicos a seguir descrevem a palavra-chave `auto` e a opção de compilador correspondente:  
  
-   [auto](../cpp/auto-cpp.md) descreve a nova definição do `auto` palavra-chave.  
  
  
-   [/ZC: auto (deduzir tipo variável)](../build/reference/zc-auto-deduce-variable-type.md) descreve a opção de compilador que informa ao compilador que definição do `auto` palavra-chave a ser usado.  
  
## <a name="see-also"></a>Consulte também  
 [Palavras-chave](../cpp/keywords-cpp.md)