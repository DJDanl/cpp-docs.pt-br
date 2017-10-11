---
title: nothrow (C++) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- nothrow_cpp
dev_langs:
- C++
helpviewer_keywords:
- __declspec keyword [C++], nothrow
- nothrow __declspec keyword
ms.assetid: 0a475139-459c-4ec6-99e8-7ecd0d7f44a3
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: c74490229e2ef54e7947f5e8fedda6057ecccb70
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="nothrow-c"></a>nothrow (C++)
**Seção específica da Microsoft**  
  
 Um atributo `__declspec` estendido que pode ser usado na declaração de funções.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
return-type __declspec(nothrow) [call-convention] function-name ([argument-list])  
```  
  
## <a name="remarks"></a>Comentários  
 Esse atributo diz ao compilador que a função declarada, e as funções que ela chama nunca lançam uma exceção. Com o modelo de tratamento de exceções síncronas, agora padrão, o compilador pode eliminar a mecânica de acompanhar o tempo de vida útil de determinados objetos desenroláveis nessa função e reduzir significativamente o tamanho do código. Dada a política de pré-processador a seguir, as três declarações de função abaixo são equivalentes:  
  
```  
#define WINAPI __declspec(nothrow) __stdcall   
  
void WINAPI f1();  
void __declspec(nothrow) __stdcall f2();  
void __stdcall f3() throw();  
```  
  
 Usar `void __declspec(nothrow) __stdcall f2();` tem a vantagem de poder usar uma definição de API, como ilustrado pela instrução `#define`, para especificar `nothrow` facilmente em um conjunto de funções. A terceira declaração`, void __stdcall f3() throw();` é a sintaxe definida pelo padrão C++.  
  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [declspec](../cpp/declspec.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)
