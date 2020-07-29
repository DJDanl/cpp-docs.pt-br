---
title: Classes de armazenamento C
ms.date: 08/31/2018
helpviewer_keywords:
- static variables, lifetime
- storage classes
- lifetime, variables
- specifiers, storage class
- storage class specifiers, C storage classes
- storage duration
ms.assetid: 893fb929-f7a9-43dc-a0b3-29cb1ef845c1
ms.openlocfilehash: 4f793e8485628faf0a80445ce0414835e3b71d1f
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87217162"
---
# <a name="c-storage-classes"></a>Classes de armazenamento C

A "classe de armazenamento" de uma variável determina se o item tem um tempo de vida “global” ou “local”. C chama esse dois tempos de vida de “estático” e “automático”. Um item com um tempo de vida global existe e tem um valor durante toda a execução do programa. Todas as funções têm tempos de vida globais.

As variáveis automáticas, ou variáveis com tempo de vida local, recebem novos armazenamentos cada vez que o controle de execução é transmitido para o bloco no qual elas são definidas. Quando a execução retornar, as variáveis não terão mais valores significativos.

C fornece os seguintes especificadores de classe de armazenamento:

## <a name="syntax"></a>Sintaxe

*storage-class-specifier*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`auto`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`register`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`static`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`extern`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`typedef`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`__declspec (`***Extended-decl-Modifier-Seq* **`)`**  / \* Específico da Microsoft\*/

Exceto para **`__declspec`** , você pode usar apenas um *especificador de classe de armazenamento* no *especificador de declaração* em uma declaração. Se nenhuma especificação de classe de armazenamento for feita, as declarações de um bloco criarão objetos automáticos.

Os itens declarados com o **`auto`** **`register`** especificador ou têm tempos de vida locais. Os itens declarados com o **`static`** **`extern`** especificador ou têm tempos de vida globais.

Como **`typedef`** e **`__declspec`** são semanticamente diferentes dos outros quatro terminais de *classe de armazenamento* , eles são discutidos separadamente. Para obter informações específicas sobre o **`typedef`** , consulte [ `typedef` declarações](../c-language/typedef-declarations.md). Para obter informações específicas sobre o **`__declspec`** , consulte [atributos de classe de armazenamento estendidos](../c-language/c-extended-storage-class-attributes.md).

O posicionamento de declarações de variável e de função em arquivos de origem também afeta a classe e a visibilidade de armazenamento. As declarações fora de todas as definições de função devem aparecer no "nível externo". As declarações em definições de função aparecem no "nível interno".

O significado exato de cada especificador de classe de armazenamento depende de dois fatores:

- Se a declaração aparece no nível externo ou interno

- Se o item que está sendo declarado é uma variável ou uma função

[Especificadores de classe de armazenamento para declarações de nível externo](../c-language/storage-class-specifiers-for-external-level-declarations.md) e [Especificadores de classe de armazenamento para declarações de nível interno](../c-language/storage-class-specifiers-for-internal-level-declarations.md) descrevem os terminais *storage-class-specifier* em cada tipo de declaração e explicam o comportamento padrão quando o *storage-class-specifier* é omitido de uma variável. [Especificadores de classe de armazenamento com declarações de função](../c-language/storage-class-specifiers-with-function-declarations.md) discutem os especificadores de classe de armazenamento usados com as funções.

## <a name="see-also"></a>Confira também

[Declarações e tipos](../c-language/declarations-and-types.md)
