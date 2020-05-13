---
title: Funções Naked
ms.date: 11/04/2016
helpviewer_keywords:
- naked functions
- functions [C++], naked
- prolog code
- epilog code
ms.assetid: 2543c8af-00d4-4a2a-8a87-e746da1f9929
ms.openlocfilehash: b752dd6fa378bc1275e8a7da90420aa2b8247e4e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62232807"
---
# <a name="naked-functions"></a>Funções Naked

**Específico da Microsoft**

O atributo de classe de armazenamento `naked` é uma extensão específica da Microsoft na linguagem C. Para funções declaradas com o atributo de classe de armazenamento `naked`, o compilador gera um código sem código de prólogo e de epílogo. Você pode usar esse recurso para escrever suas próprias sequências de código de prólogo/epílogo usando o código de assembler embutido. As funções naked são particularmente úteis para escrever drivers para dispositivo virtuais.

Como o atributo `naked` é relevante apenas para a definição de uma função e não é um modificador de tipo, as funções naked devem usar a sintaxe de atributo estendido, descrita em [Atributos de classe de armazenamento estendidos](../c-language/c-extended-storage-class-attributes.md).

O seguinte exemplo define uma função com o atributo `naked`:

```
__declspec( naked ) int func( formal_parameters )
{
   /* Function body */
}
```

Ou, alternativamente:

```
#define Naked   __declspec( naked )

Naked int func( formal_parameters )
{
   /* Function body */
}
```

O atributo `naked` afeta somente a natureza de geração de código do compilador para as sequências de prólogo e epílogo da função. Não afeta o código que é gerado pela chamada dessas funções. Assim, o atributo `naked` não é considerado parte do tipo de função, e os ponteiros da função não podem ter o atributo `naked`. Além disso, o atributo `naked` não pode ser aplicado a uma definição de dados. Por exemplo, o código a seguir gera erros:

```
__declspec( naked ) int i;  /* Error--naked attribute not */
                            /* permitted on data declarations. */
```

O atributo `naked` é relevante apenas à definição da função e não pode ser especificado no protótipo da função. Esta declaração gera um erro de compilador:

```
__declspec( naked ) int func();   /* Error--naked attribute not */
                     /* permitted on function declarations.    */   \
```

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Definições de função C](../c-language/c-function-definitions.md)
