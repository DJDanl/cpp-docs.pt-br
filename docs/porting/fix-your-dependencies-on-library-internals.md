---
title: Corrigir suas dependências de internos de biblioteca | Microsoft Docs
ms.custom: ''
ms.date: 05/24/2017
ms.technology:
- cpp-language
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- library internals in an upgraded Visual C++ project
- _Hash_seq in an upgraded Visual C++ project
ms.assetid: 493e0452-6ecb-4edc-ae20-b6fce2d7d3c5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 148db60c7a3b1ae3f71269feec8024f6ff22a118
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="fix-your-dependencies-on-library-internals"></a>Corrigir suas dependências de internos de biblioteca

A Microsoft publicou o código-fonte da Biblioteca padrão, da maior parte da biblioteca de tempo de execução do C e de outras bibliotecas da Microsoft em muitas versões do Visual Studio. A intenção é ajudá-lo a entender o comportamento da biblioteca e para depurar seu código. Um efeito colateral da publicação do código-fonte da biblioteca é que alguns valores internos, algumas estruturas de dados e funções são expostos, mesmo que não façam parte da interface de biblioteca. Eles normalmente têm nomes que começam com dois sublinhados ou um sublinhado seguido por uma letra maiúscula, nomes que o padrão do C++ reserva para implementações. Esses valores, essas estruturas e essas funções são detalhes de implementação que podem se alterar conforme as bibliotecas evoluem ao longo do tempo e, portanto, convém evitar quaisquer dependências neles. Se fizer isso, você corre o risco de ter problemas e de ter um código não portátil ao tentar migrar seu código para novas versões das bibliotecas.  

Na maioria dos casos, o documento de Novidades ou o de Alterações Significativas para cada versão do Visual Studio não menciona alterações de internos de biblioteca. Afinal, você não deveria ser afetado por esses detalhes de implementação. No entanto, algumas vezes a tentação de usar um código que você pode ver dentro da biblioteca é muito grande. Este tópico discute as dependências em CRT ou em internos de Biblioteca padrão que você possa ter utilizado e discute como atualizar seu código para remover essas dependências e torná-lo mais portátil ou migrar para novas versões da biblioteca.

## <a name="hashseq"></a>_Hash_seq  

A função de hash interna `std::_Hash_seq(const unsigned char *, size_t)`, usada para implementar `std::hash` em alguns tipos de cadeia de caracteres, era visível em versões recentes da Biblioteca padrão. Essa função implementava um [hash FNV-1a]( https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function) em uma sequência de caracteres.  
  
Para remover essa dependência, você tem duas opções.  

-   Se seu objetivo é colocar uma sequência `const char *` em um contêiner não ordenado usando o mesmo mecanismo de código hash como `basic_string`, você pode fazer isso usando a sobrecarga de modelo `std::hash` que recebe um `std::string_view`, que retorna esse código hash de uma maneira portátil. O código de biblioteca de cadeia de caracteres poderá ou não contar com o uso de um hash FNV-1a no futuro, portanto, esta é a melhor maneira de se evitar uma dependência em um algoritmo de hash específico. 
  
-   Se sua intenção é gerar um hash de FNV-1a sobre memória arbitrária, disponibilizamos esse código no GitHub, no repositório [VCSamples]( https://github.com/Microsoft/vcsamples), em um arquivo de cabeçalho autônomo, [fnv1a.hpp](https://github.com/Microsoft/VCSamples/tree/master/VC2015Samples/_Hash_seq), sob uma [licença do MIT](https://github.com/Microsoft/VCSamples/blob/master/license.txt). Também incluímos uma cópia aqui para sua conveniência. Você pode copiar esse código em um arquivo de cabeçalho, adicionar o cabeçalho a qualquer código afetado e, em seguida, localizar e substituir `_Hash_seq` por `fnv1a_hash_bytes`. Você obterá um comportamento idêntico para a implementação interna em `_Hash_seq`. 

```cpp  
/*
VCSamples
Copyright (c) Microsoft Corporation
All rights reserved. 
MIT License
Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED *AS IS*, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <stddef.h>

inline size_t fnv1a_hash_bytes(const unsigned char * first, size_t count) {
#if defined(_WIN64)
    static_assert(sizeof(size_t) == 8, "This code is for 64-bit size_t.");
    const size_t fnv_offset_basis = 14695981039346656037ULL;
    const size_t fnv_prime = 1099511628211ULL;

#else /* defined(_WIN64) */
    static_assert(sizeof(size_t) == 4, "This code is for 32-bit size_t.");
    const size_t fnv_offset_basis = 2166136261U;
    const size_t fnv_prime = 16777619U;
#endif /* defined(_WIN64) */

    size_t result = fnv_offset_basis;
    for (size_t next = 0; next < count; ++next)
        {   // fold in another byte
        result ^= (size_t)first[next];
        result *= fnv_prime;
        }
    return (result);
}
```  
  
## <a name="see-also"></a>Consulte também  
  
[Atualizando projetos de versões anteriores do Visual C++](upgrading-projects-from-earlier-versions-of-visual-cpp.md)  
[Visão geral de possíveis problemas de atualização (Visual C++)](overview-of-potential-upgrade-issues-visual-cpp.md)  
[Atualizar seu código para o CRT Universal](upgrade-your-code-to-the-universal-crt.md)  
