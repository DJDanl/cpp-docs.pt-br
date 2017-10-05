---
title: palavra-chave auto | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- auto
- auto_cpp
dev_langs:
- C++
helpviewer_keywords:
- automatic storage class, auto keyword
- auto keyword
ms.assetid: 744a41c0-2510-4140-a1be-96257e722908
caps.latest.revision: 14
author: mikeblome
ms.author: mblome
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
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 0413fd47b486cf1613b7c249b93e6a3507a5577c
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

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
