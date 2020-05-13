---
title: Ponteiros (C++)
ms.date: 11/19/2019
description: Sobre ponteiros brutos e ponteiros inteligentes no Microsoft C++.
helpviewer_keywords:
- pointers (C++)
ms.assetid: 595387c5-8e58-4670-848f-344c7caf985e
ms.openlocfilehash: 485cee667fa288bff76fdeac7c9f229355c276d1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371912"
---
# <a name="pointers-c"></a>Ponteiros (C++)

Um ponteiro é uma variável que armazena o endereço de memória de um objeto. Os ponteiros são usados extensivamente em C e C++ para três propósitos principais:

- para alocar novos objetos na pilha,
- para passar funções para outras funções
- para iterar sobre elementos em matrizes ou outras estruturas de dados.

Na programação estilo C, *ponteiros brutos* são usados para todos esses cenários. No entanto, ponteiros brutos são a fonte de muitos erros sérios de programação. Portanto, seu uso é fortemente desencorajado, exceto quando eles fornecem um benefício significativo de desempenho e não há ambiguidade sobre qual ponteiro é o *ponteiro que* é responsável pela exclusão do objeto. O C++ moderno fornece *ponteiros inteligentes* para alocar *objetos, iterizadores* para atravessar estruturas de dados e *expressões lambda* para funções de passagem. Ao usar essas instalações de idioma e biblioteca em vez de ponteiros brutos, você tornará seu programa mais seguro, mais fácil de depurar e mais simples de entender e manter. Consulte [ponteiros inteligentes,](smart-pointers-modern-cpp.md) [erros de vida](../standard-library/iterators.md)e [expressões Lambda](lambda-expressions-in-cpp.md) para obter mais informações.

## <a name="in-this-section"></a>Nesta seção

- [Ponteiros brutos](raw-pointers.md)
- [Ponteiros const e voláteis](const-and-volatile-pointers.md)
- [novos e excluir operadores](new-and-delete-operators.md)
- [Ponteiros inteligentes](smart-pointers-modern-cpp.md)
- [Como: Criar e usar unique_ptr instâncias](how-to-create-and-use-unique-ptr-instances.md)
- [Como: Criar e usar shared_ptr instâncias](how-to-create-and-use-shared-ptr-instances.md)
- [Como: Criar e usar weak_ptr instâncias](how-to-create-and-use-weak-ptr-instances.md)
- [Como: Criar e usar as instâncias CComPtr e CComQIPtr](how-to-create-and-use-ccomptr-and-ccomqiptr-instances.md)

## <a name="see-also"></a>Confira também

[Iterators](../standard-library/iterators.md)</br>
[Expressões lambda](lambda-expressions-in-cpp.md)
