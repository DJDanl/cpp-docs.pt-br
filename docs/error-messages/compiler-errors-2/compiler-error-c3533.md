---
title: Erro do compilador C3533 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3533
dev_langs:
- C++
helpviewer_keywords:
- C3533
ms.assetid: a68b1ba5-466e-4190-a1a4-505ccfe548b7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6201f59e3ccefaa920f79f9b9889bd187fb2e0b0
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46042553"
---
# <a name="compiler-error-c3533"></a>Erro do compilador C3533

'type': um parâmetro não pode ter um tipo que contenha 'auto'

Um parâmetro de modelo ou método não pode ser declarado com o `auto` palavra-chave se o padrão [/ZC: auto](../../build/reference/zc-auto-deduce-variable-type.md) opção do compilador está em vigor.

### <a name="to-correct-this-error"></a>Para corrigir este erro

1. Remover o `auto` palavra-chave da declaração de parâmetro.

## <a name="example"></a>Exemplo

O exemplo a seguir produz C3533 porque ele declara um parâmetro de função com o `auto` palavra-chave e ele é compilado com **/ZC: auto**.

```
// C3533a.cpp
// Compile with /Zc:auto
void f(auto j) {} // C3533
```

## <a name="example"></a>Exemplo

O exemplo a seguir produz C3533 no modo c++14, porque ele declara um parâmetro de modelo com o `auto` palavra-chave e ele é compilado com **/ZC: auto**. (No c++17, esta é uma definição válida de um modelo de classe com um parâmetro único modelo sem tipo cujo tipo é deduzido.)

```
// C3533b.cpp
// Compile with /Zc:auto
template<auto T> class C {}; // C3533
```

## <a name="see-also"></a>Consulte também

[Palavra-chave auto](../../cpp/auto-keyword.md)<br/>
[/Zc:auto (deduzir tipo de variável)](../../build/reference/zc-auto-deduce-variable-type.md)
