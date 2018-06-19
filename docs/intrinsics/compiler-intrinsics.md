---
title: Intrínsecos do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- intrinsics, compiler
- compiler intrinsics
- cl.exe compiler, performance
- cl.exe compiler, intrinsics
ms.assetid: 48bb9929-7d78-4fd8-a092-ae3c9f971858
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c05a2843e5daff980d1c84d4d3f2185ac361144d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33339008"
---
# <a name="compiler-intrinsics"></a>Intrínsecos do compilador
A maioria das funções está contidas em bibliotecas, mas algumas funções são internas (ou seja, intrínsecas) para o compilador. Elas são chamadas de funções intrínsecas ou intrínsecos.  
  
## <a name="remarks"></a>Comentários  
 Se uma função for um intrínseco, o código para essa função será inserido geralmente embutido, evitando a sobrecarga de uma chamada de função e permitindo que instruções de máquina altamente eficientes sejam emitidas para a função. Um intrínseco geralmente é mais rápido do que o assembly embutido equivalente, porque o otimizador tem conhecimento interno de quantos intrínsecos se comportam, algumas otimizações que podem estar disponíveis não estarão disponíveis quando o assembly embutido for usado. Além disso, o otimizador pode expandir o intrínseco diferentemente, alinhar buffers de forma diferente ou fazer outros ajustes dependendo do contexto e dos argumentos da chamada.  
  
 O uso de intrínsecos afeta a portabilidade do código, pois os intrínsecos que estão disponíveis no Visual C++ podem não estar disponíveis se o código for compilado com outros compiladores, e alguns intrínsecos que podem estar disponíveis para algumas arquiteturas de destino não estarão disponíveis para todas as arquiteturas. No entanto, intrínsecos são geralmente mais portáteis do que o assembly embutido. Os intrínsecos são necessários em arquiteturas de 64 bits em que não há suporte para assembly embutido.  
  
 Alguns intrínsecos como `__assume` e `__ReadWriteBarrier`, fornecem informações ao compilador, o que afeta o comportamento do otimizador.  
  
 Alguns intrínsecos estão disponíveis apenas como intrínsecos e outros estão disponíveis nas implementações de intrínsecos e função. Você pode instruir o compilador para usar a implementação intrínseca em uma das duas maneiras, dependendo se quer habilitar apenas as funções específicas ou todos os intrínsecos. O primeiro modo é usar `#pragma intrinsic(` *intrínseco-nome-lista de função*`)`. O pragma pode ser usado para especificar um único intrínseco ou vários intrínsecos separados por vírgulas. O segundo é usar o [/Oi (gerar funções intrínsecas)](../build/reference/oi-generate-intrinsic-functions.md) opção de compilador, que disponibiliza todos os intrínsecos em uma determinada plataforma. Em **/Oi**, use `#pragma function(` *intrínseco-nome-lista de função* `)` para forçar uma chamada de função a ser usado em vez de um intrínseco. Se a documentação de um determinado intrínseco observa que a rotina só está disponível como um intrínseco, a implementação intrínseca é usada independentemente se **/Oi** ou `#pragma intrinsic` for especificado. Em todos os casos, **/Oi** ou `#pragma intrinsic` permite, mas não força o otimizador a usar intrínseca. O otimizador ainda pode chamar a função.  
  
 Algumas funções de biblioteca de C/C++ padrão estão disponíveis em implementações intrínsecas em algumas arquiteturas. Ao chamar uma função CRT, a implementação intrínseca será usada se **/Oi** for especificado na linha de comando.  
  
 Um arquivo de cabeçalho \<intrin.h >, está disponível que declara protótipos para funções intrínsecas comuns. Intrínsecos do fabricante específico estão disponíveis no \<immintrin.h > e \<ammintrin.h > arquivos de cabeçalho. Além disso, determinados cabeçalhos Windows declaram funções que mapeiam para um compilador intrínseco.  
  
 As seções a seguir listam todos os intrínsecos que estão disponíveis em várias arquiteturas. Para obter mais informações sobre como os intrínsecos funcionam no seu processador de destino específico, consulte a documentação de referência do fabricante.  
  
-   [Intrínsecos do ARM](../intrinsics/arm-intrinsics.md)  
  
-   [Lista de intrínsecos x86](../intrinsics/x86-intrinsics-list.md)  
  
-   [Lista de intrínsecos x64 (amd64)](../intrinsics/x64-amd64-intrinsics-list.md)  
  
-   [Intrínsecos disponíveis em todas as arquiteturas](../intrinsics/intrinsics-available-on-all-architectures.md)  
  
-   [Listagem alfabética de funções intrínsecas](../intrinsics/alphabetical-listing-of-intrinsic-functions.md)  
  
## <a name="see-also"></a>Consulte também  
 [Referência do Assembler ARM](../assembler/arm/arm-assembler-reference.md)   
 [Referência do Microsoft Macro Assembler](../assembler/masm/microsoft-macro-assembler-reference.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [Referência da biblioteca em tempo de execução C](../c-runtime-library/c-run-time-library-reference.md)