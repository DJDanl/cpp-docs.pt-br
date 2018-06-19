---
title: palavra-chave auto | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: 744a41c0-2510-4140-a1be-96257e722908
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 93b2f5e28dc0306a996b4c8bdb799122fe4646ab
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32409993"
---
# <a name="auto-keyword"></a>Palavra-chave auto
A palavra-chave `auto` é um especificador de declaração. Porém, o padrão do C++ define um significado original e um significado revisado para essa palavra-chave. Antes de Visual C++ 2010, o `auto` palavra-chave declara uma variável no *automáticas* classe de armazenamento, ou seja, uma variável que possui um tempo de vida de local. Começando com Visual C++ 2010, o `auto` palavra-chave declara uma variável cujo tipo é deduzido da expressão de inicialização na sua declaração. O [/ZC: auto&#91;-&#93; ](../build/reference/zc-auto-deduce-variable-type.md) opção de compilador controla o significado de `auto` palavra-chave.  
  
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