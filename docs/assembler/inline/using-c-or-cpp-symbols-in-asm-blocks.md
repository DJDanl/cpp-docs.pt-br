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
ms.openlocfilehash: ecdd3b6b6916a5c9585678838d8e494a58e0508c
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87191190"
---
# <a name="using-c-or-c-symbols-in-__asm-blocks"></a>Usando símbolos de C ou C++ em blocos __asm

**Específico da Microsoft**

Um **`__asm`** bloco pode se referir a qualquer símbolo C ou C++ no escopo em que o bloco é exibido. (Os símbolos C e C++ são nomes de variáveis, nomes de função e rótulos; ou seja, nomes que não são constantes ou membros simbólicos **`enum`** . Você não pode chamar funções de membro do C++.)

Algumas restrições se aplicam ao uso de símbolos C e C++:

- Cada instrução de linguagem de assembly pode conter apenas um símbolo C ou C++. Vários símbolos podem aparecer na mesma instrução de assembly somente com expressões de **comprimento**, **tipo**e **tamanho** .

- As funções referenciadas em um **`__asm`** bloco devem ser declaradas (protótipos) anteriormente no programa. Caso contrário, o compilador não pode distinguir entre nomes de função e rótulos no **`__asm`** bloco.

- Um **`__asm`** bloco não pode usar nenhum símbolo C ou C++ com a mesma grafia que MASM palavras reservadas (independentemente do caso). As palavras reservadas do MASM incluem nomes de instrução como **Push** e registrar nomes como, por exemplo, si.

- As marcas de estrutura e União não são reconhecidas em **`__asm`** blocos.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Usando C ou C++ em blocos de __asm](../../assembler/inline/using-c-or-cpp-in-asm-blocks.md)<br/>
