---
title: Usando símbolos de C ou C++ em blocos __asm
ms.date: 08/30/2018
helpviewer_keywords:
- __asm keyword [C++], syntax
- symbols, in __asm blocks
- Visual C, symbols in __asm blocks
- __asm keyword [C++], C/C++ elements in
- Visual C++, in __asm blocks
ms.assetid: 0758ffdc-dfe9-41c8-a5e1-fd395bcac328
ms.openlocfilehash: fd9f8b444d263818aca1b16260f70730d5350e7c
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80169104"
---
# <a name="using-c-or-c-symbols-in-__asm-blocks"></a>Usando símbolos de C ou C++ em blocos __asm

**Seção específica da Microsoft**

Um bloco de `__asm` pode se referir a C++ qualquer C ou símbolo no escopo em que o bloco é exibido. (C e C++ Symbols são nomes de variáveis, nomes de função e rótulos; ou seja, nomes que não são constantes simbólicas ou membros de `enum`. Você não pode C++ chamar funções de membro.)

Algumas restrições se aplicam ao uso de C e C++ Symbols:

- Cada instrução de linguagem de assembly pode conter apenas um C C++ ou símbolo. Vários símbolos podem aparecer na mesma instrução de assembly somente com expressões de **comprimento**, **tipo**e **tamanho** .

- As funções referenciadas em um bloco de `__asm` devem ser declaradas (protótipos) anteriormente no programa. Caso contrário, o compilador não pode distinguir entre nomes de função e rótulos no bloco de `__asm`.

- Um bloco de `__asm` não pode usar nenhum C++ C ou símbolo com a mesma grafia que MASM palavras reservadas (independentemente do caso). As palavras reservadas do MASM incluem nomes de instrução como **Push** e registrar nomes como, por exemplo, si.

- As marcas de estrutura e União não são reconhecidas em blocos de `__asm`.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Usando C ou C++ em blocos __asm](../../assembler/inline/using-c-or-cpp-in-asm-blocks.md)<br/>
