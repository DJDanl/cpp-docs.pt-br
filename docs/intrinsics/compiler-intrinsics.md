---
title: Intrínsecos do compilador
ms.date: 09/02/2019
helpviewer_keywords:
- intrinsics, compiler
- compiler intrinsics
- cl.exe compiler, performance
- cl.exe compiler, intrinsics
ms.assetid: 48bb9929-7d78-4fd8-a092-ae3c9f971858
ms.openlocfilehash: 7438c90eec8b1f88a4c1608953ce21772254f02c
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230526"
---
# <a name="compiler-intrinsics"></a>Intrínsecos do compilador

A maioria das funções está contidas em bibliotecas, mas algumas funções são internas (ou seja, intrínsecas) para o compilador. Elas são chamadas de funções intrínsecas ou intrínsecos.

## <a name="remarks"></a>Comentários

Se uma função for um intrínseco, o código para essa função será inserido geralmente embutido, evitando a sobrecarga de uma chamada de função e permitindo que instruções de máquina altamente eficientes sejam emitidas para a função. Um intrínseco geralmente é mais rápido do que o assembly embutido equivalente, porque o otimizador tem conhecimento interno de quantos intrínsecos se comportam, algumas otimizações que podem estar disponíveis não estarão disponíveis quando o assembly embutido for usado. Além disso, o otimizador pode expandir o intrínseco diferentemente, alinhar buffers de forma diferente ou fazer outros ajustes dependendo do contexto e dos argumentos da chamada.

O uso de intrínsecos afeta a portabilidade do código, pois os intrínsecos que estão disponíveis no Visual C++ podem não estar disponíveis se o código for compilado com outros compiladores, e alguns intrínsecos que podem estar disponíveis para algumas arquiteturas de destino não estarão disponíveis para todas as arquiteturas. No entanto, intrínsecos são geralmente mais portáteis do que o assembly embutido. Os intrínsecos são necessários em arquiteturas de 64 bits em que não há suporte para assembly embutido.

Alguns intrínsecos, como **`__assume`** e `__ReadWriteBarrier` , fornecem informações para o compilador, o que afeta o comportamento do otimizador.

Alguns intrínsecos estão disponíveis apenas como intrínsecos e outros estão disponíveis nas implementações de intrínsecos e função. Você pode instruir o compilador para usar a implementação intrínseca em uma das duas maneiras, dependendo se quer habilitar apenas as funções específicas ou todos os intrínsecos. A primeira maneira é usar a `#pragma intrinsic(` *lista intrínseca-function-name* `)` . O pragma pode ser usado para especificar um único intrínseco ou vários intrínsecos separados por vírgulas. A segunda é usar a opção de compilador [/Oi (gerar funções intrínsecas)](../build/reference/oi-generate-intrinsic-functions.md) , o que torna todos os intrínsecos em uma determinada plataforma disponíveis. Em **/Oi**, use `#pragma function(` *intrínseco-function-name-list* `)` para forçar uma chamada de função a ser usada em vez de uma intrínseca. Se a documentação de uma determinada nota intrínseca que a rotina só está disponível como intrínseca, a implementação intrínseca é usada independentemente de **/Oi** ou `#pragma intrinsic` ser especificado. Em todos os casos, **/Oi** ou `#pragma intrinsic` permite, mas não força, o otimizador a usar o intrínseco. O otimizador ainda pode chamar a função.

Algumas funções de biblioteca de C/C++ padrão estão disponíveis em implementações intrínsecas em algumas arquiteturas. Ao chamar uma função CRT, a implementação intrínseca será usada se **/Oi** for especificado na linha de comando.

Um arquivo de cabeçalho, \<intrin.h> , está disponível que declara protótipos para as funções intrínsecas comuns. Os intrínsecos específicos do fabricante estão disponíveis nos \<immintrin.h> \<ammintrin.h> arquivos de cabeçalho e. Além disso, determinados cabeçalhos Windows declaram funções que mapeiam para um compilador intrínseco.

As seções a seguir listam todos os intrínsecos que estão disponíveis em várias arquiteturas. Para obter mais informações sobre como os intrínsecos funcionam no seu processador de destino específico, consulte a documentação de referência do fabricante.

- [Intrínsecos ARM](../intrinsics/arm-intrinsics.md)

- [Intrínsecos do ARM64](../intrinsics/arm64-intrinsics.md)

- [Lista de intrínsecos x86](../intrinsics/x86-intrinsics-list.md)

- [Lista de intrínsecos x64 (amd64)](../intrinsics/x64-amd64-intrinsics-list.md)

- [Intrínsecos disponíveis em todas as arquiteturas](../intrinsics/intrinsics-available-on-all-architectures.md)

- [Listagem alfabética de funções intrínsecas](../intrinsics/alphabetical-listing-of-intrinsic-functions.md)

## <a name="see-also"></a>Confira também

[Referência do ARM Assembler](../assembler/arm/arm-assembler-reference.md)<br/>
[Referência do Microsoft Macro Assembler](../assembler/masm/microsoft-macro-assembler-reference.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Referência da biblioteca de tempo de execução C](../c-runtime-library/c-run-time-library-reference.md)
