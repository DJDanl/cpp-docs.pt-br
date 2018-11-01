---
title: 2.7.2.1 private
ms.date: 11/04/2016
ms.assetid: 079b4b84-f2b3-4050-a0ac-289493c36b3d
ms.openlocfilehash: c1a2560eb80c848605698c435e3a0f0f7e66b75a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50536949"
---
# <a name="2721-private"></a>2.7.2.1 private

O `private` cláusula declara as variáveis na lista de variável a ser privadas para cada thread em uma equipe. A sintaxe do `private` cláusula é da seguinte maneira:

```
private(variable-list)
```

O comportamento de uma variável especificada em um `private` cláusula é da seguinte maneira. Um novo objeto com duração automática de armazenamento é alocado para a construção. O tamanho e o alinhamento do novo objeto são determinados pelo tipo da variável. Essa alocação ocorre uma vez para cada thread na equipe, e um construtor padrão é invocado para um objeto de classe, se necessário; Caso contrário, o valor inicial é indeterminado.  O objeto original referenciado pela variável de tem um valor indeterminado durante a entrada para a construção, não deve ser modificado na extensão dinâmico da construção e tem um valor indeterminado após a saída da construção.

Na extensão de léxica da construção de diretiva, a variável referenciar o novo objeto privado alocado pelo thread.

As restrições para o `private` cláusula são da seguinte maneira:

- Uma variável com um tipo de classe que é especificado em um `private` cláusula deve ter um construtor padrão acessível, não ambígua.

- Uma variável especificada em uma `private` cláusula não deve ter um **const**-qualificado tipo, a menos que ele tem uma classe de tipo com um `mutable` membro.

- Uma variável especificada em um `private` cláusula não deve ter um tipo incompleto ou um tipo de referência.

- Variáveis que aparecem o `reduction` cláusula de uma **paralela** diretiva não pode ser especificada em uma `private` cláusula em uma diretiva de compartilhamento de trabalho que está associado a construção parallel.