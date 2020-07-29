---
title: Especificador de classe de armazenamento estático
ms.date: 11/04/2016
helpviewer_keywords:
- static variables, specifier
- storage classes, static
- static storage class specifiers
ms.assetid: 9bce361e-919b-46b9-8148-40d7ab0eb024
ms.openlocfilehash: e84e2745c6077f038f47295119936a1ad6431bdd
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87229487"
---
# <a name="static-storage-class-specifier"></a>Especificador de classe de armazenamento estático

Uma variável declarada no nível interno com o **`static`** especificador de classe de armazenamento tem um tempo de vida global, mas só é visível dentro do bloco no qual é declarada. Para cadeias de caracteres constantes, o uso do **`static`** é útil porque minimiza a sobrecarga da inicialização frequente em funções chamadas com frequência.

## <a name="remarks"></a>Comentários

Se você não inicializar uma variável explicitamente **`static`** , ela será inicializada como 0 por padrão. Dentro de uma função, **`static`** faz com que o armazenamento seja alocado e serve como uma definição. As variáveis estáticas internas fornecem armazenamento particular e permanente que só pode ser visto por uma única função.

## <a name="see-also"></a>Confira também

[Classes de armazenamento C](c-storage-classes.md)<br/>
[Classes de armazenamento (C++)](../cpp/storage-classes-cpp.md)
