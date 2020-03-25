---
title: Informações de tipo de tempo de execução
ms.custom: index-page
ms.date: 11/04/2016
helpviewer_keywords:
- RTTI compiler option
- run-time type information
- run time, type checking
- type information, run-time type checking
- run-time checks, type checking
ms.assetid: becbd0e5-0439-4c61-854f-8a74f7160c54
ms.openlocfilehash: 195274d7bcef0ff4d82383a8ec828ca9267573b0
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80178932"
---
# <a name="run-time-type-information"></a>Informações de tipo de tempo de execução

As informações de tipo em tempo de execução (RTTI) são um mecanismo que permite que o tipo de um objeto seja determinado durante a execução do programa. A RTTI foi adicionada à linguagem C++ porque muitos fornecedores de bibliotecas de classes implementavam essa funcionalidade de maneira independente. Isso causou incompatibilidades entre as bibliotecas. Assim, ficou claro que era necessário o suporte a informações de tipo em tempo de execução no nível da linguagem.

Para uma questão de clareza, esta discussão sobre a RTTI é quase que totalmente restrita a ponteiros. No entanto, os conceitos abordados também se aplicam a referências.

Há três principais elementos de linguagem C++ para as informações de tipo em tempo de execução:

- O operador de [dynamic_cast](../cpp/dynamic-cast-operator.md) .

   Usado para a conversão de tipos polimorfos.

- O operador [typeid](../cpp/typeid-operator.md) .

   Usado para identificar o tipo exato de um objeto.

- A classe [type_info](../cpp/type-info-class.md) .

   Usado para armazenar as informações de tipo retornadas pelo operador **typeid** .

## <a name="see-also"></a>Confira também

[Conversão](../cpp/casting.md)
