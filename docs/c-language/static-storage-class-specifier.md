---
title: Especificador de classe de armazenamento estático
ms.date: 11/04/2016
helpviewer_keywords:
- static variables, specifier
- storage classes, static
- static storage class specifiers
ms.assetid: 9bce361e-919b-46b9-8148-40d7ab0eb024
ms.openlocfilehash: ef85ee4d757cb9579431427fba7b46a0e5ac905f
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56148225"
---
# <a name="static-storage-class-specifier"></a>Especificador de classe de armazenamento estático

Uma variável declarada no nível interno com o especificador de classe de armazenamento **static** tem um tempo de vida global, mas pode ser visto somente dentro do bloco em que é declarado. Para cadeias de caracteres constantes, usar **static** é útil porque reduz a sobrecarga de inicializações frequentes nas funções chamadas com frequência.

## <a name="remarks"></a>Comentários

Se você não inicializar explicitamente uma variável **static**, ela será inicializada como 0 por padrão. Dentro de uma função, **static** faz com que o armazenamento seja alocado e sirva como uma definição. As variáveis estáticas internas fornecem armazenamento particular e permanente que só pode ser visto por uma única função.

## <a name="see-also"></a>Consulte também

[Classes de armazenamento C](c-storage-classes.md)<br/>
[Classes de armazenamento (C++)](../cpp/storage-classes-cpp.md)
