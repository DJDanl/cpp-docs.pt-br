---
title: nothrow (C++) | Microsoft Docs
ms.custom: ''
ms.date: 01/03/2018
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- nothrow_cpp
dev_langs:
- C++
helpviewer_keywords:
- __declspec keyword [C++], nothrow
- nothrow __declspec keyword
ms.assetid: 0a475139-459c-4ec6-99e8-7ecd0d7f44a3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 69a706577cf112c3d8a3b7748f72679f7213936d
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="nothrow-c"></a>nothrow (C++)

**Seção específica da Microsoft**

Um atributo `__declspec` estendido que pode ser usado na declaração de funções.

## <a name="syntax"></a>Sintaxe  
  
> *tipo de retorno* nothrow [*convenção de chamada*] *nome de função* ([*lista de argumentos*])

## <a name="remarks"></a>Comentários

É recomendável que todos os novos códigos usem o [noexcept](noexcept-cpp.md) operador em vez de `__declspec(nothrow)`.

Esse atributo diz ao compilador que a função declarada, e as funções que ela chama nunca lançam uma exceção. No entanto, ele não impõe a diretiva. Em outras palavras, ele nunca faz com que [std::terminate](../standard-library/exception-functions.md#terminate) a ser invocado, ao contrário de `noexcept`, ou em **std:c + + 17** (Visual Studio 2017 versão 15.5 e posterior), de modo `throw()`.

Com o modelo de tratamento de exceções síncronas, agora padrão, o compilador pode eliminar a mecânica de acompanhar o tempo de vida útil de determinados objetos desenroláveis nessa função e reduzir significativamente o tamanho do código. Dada a seguinte diretiva de pré-processador, as declarações de três função abaixo são equivalentes em **/std:c + + 14** modo:

```cpp
#define WINAPI __declspec(nothrow) __stdcall

void WINAPI f1();
void __declspec(nothrow) __stdcall f2();
void __stdcall f3() throw();
```

Em **/std:c + + 17** modo, `throw()` não é equivalente a outras pessoas que usam `__declspec(nothrow)` porque ele faz com que `std::terminate` a ser chamado se uma exceção é gerada da função.

O `void __stdcall f3() throw();` declaração usa a sintaxe definida por padrão o C++. No C++ 17 o `throw()` palavra-chave foi preterida.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[__declspec](../cpp/declspec.md)  
[noexcept](noexcept-cpp.md)  
[Palavras-chave](../cpp/keywords-cpp.md)  
