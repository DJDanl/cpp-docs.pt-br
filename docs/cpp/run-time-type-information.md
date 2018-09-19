---
title: Informações de tipo de tempo de execução | Microsoft Docs
ms.custom: index-page
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- RTTI compiler option
- run-time type information
- run time, type checking
- type information, run-time type checking
- run-time checks, type checking
ms.assetid: becbd0e5-0439-4c61-854f-8a74f7160c54
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1244c05b7af94d69394c412a3c67864d6e75c337
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46050873"
---
# <a name="run-time-type-information"></a>Informações de tipo de tempo de execução

As informações de tipo em tempo de execução (RTTI) são um mecanismo que permite que o tipo de um objeto seja determinado durante a execução do programa. A RTTI foi adicionada à linguagem C++ porque muitos fornecedores de bibliotecas de classes implementavam essa funcionalidade de maneira independente. Isso causou incompatibilidades entre as bibliotecas. Assim, ficou claro que era necessário o suporte a informações de tipo em tempo de execução no nível da linguagem.

Para uma questão de clareza, esta discussão sobre a RTTI é quase que totalmente restrita a ponteiros. No entanto, os conceitos abordados também se aplicam a referências.

Há três principais elementos de linguagem C++ para as informações de tipo em tempo de execução:

- O [dynamic_cast](../cpp/dynamic-cast-operator.md) operador.

     Usado para a conversão de tipos polimorfos.

- O [typeid](../cpp/typeid-operator.md) operador.

     Usado para identificar o tipo exato de um objeto.

- O [type_info](../cpp/type-info-class.md) classe.

     Usado para manter as informações de tipo retornadas pela **typeid** operador.

## <a name="see-also"></a>Consulte também

[Conversão](../cpp/casting.md)