---
title: PonteirosC++()
ms.date: 11/19/2019
description: Sobre ponteiros brutos e ponteiros C++inteligentes na Microsoft.
helpviewer_keywords:
- pointers (C++)
ms.assetid: 595387c5-8e58-4670-848f-344c7caf985e
ms.openlocfilehash: 21dcc55048e9e378f370f25254e1910b05e49d69
ms.sourcegitcommit: 654aecaeb5d3e3fe6bc926bafd6d5ace0d20a80e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2019
ms.locfileid: "74246418"
---
# <a name="pointers-c"></a>PonteirosC++()

Um ponteiro é uma variável que armazena o endereço de memória de um objeto. Os ponteiros são usados extensivamente em C C++ e para três finalidades principais:

- para alocar novos objetos no heap,
- para passar funções para outras funções
- para iterar sobre elementos em matrizes ou outras estruturas de dados.

Na programação em estilo C, *ponteiros brutos* são usados para todos esses cenários. No entanto, os ponteiros brutos são a fonte de muitos erros sérios de programação. Portanto, seu uso é fortemente desencorajado, exceto onde eles fornecem um benefício de desempenho significativo e não há nenhuma ambiguidade sobre qual ponteiro é o *ponteiro proprietário* responsável pela exclusão do objeto. O C++ moderno fornece *ponteiros inteligentes* para alocar objetos, *iteradores* para atravessar estruturas de dados e *expressões lambda* para passar funções. Usando esses recursos de biblioteca e de linguagem em vez de ponteiros brutos, você tornará seu programa mais seguro, mais fácil de depurar e mais simples de entender e manter. Consulte [ponteiros inteligentes](smart-pointers-modern-cpp.md), [iteradores](../standard-library/iterators.md)e [expressões lambda](lambda-expressions-in-cpp.md) para obter mais informações.

## <a name="in-this-section"></a>Nesta seção

- [Ponteiros brutos](raw-pointers.md)
- [Ponteiros const e voláteis](const-and-volatile-pointers.md)
- [operadores New e Delete](new-and-delete-operators.md)
- [Ponteiros inteligentes](smart-pointers-modern-cpp.md)
- [Como criar e usar instâncias de unique_ptr](how-to-create-and-use-unique-ptr-instances.md)
- [Como criar e usar instâncias de shared_ptr](how-to-create-and-use-shared-ptr-instances.md)
- [Como criar e usar instâncias de weak_ptr](how-to-create-and-use-weak-ptr-instances.md)
- [Como: criar e usar instâncias CComPtr e CComQIPtr](how-to-create-and-use-ccomptr-and-ccomqiptr-instances.md)

## <a name="see-also"></a>Consulte também

[Iteradores](../standard-library/iterators.md)</br>
[Expressões lambda](lambda-expressions-in-cpp.md)
