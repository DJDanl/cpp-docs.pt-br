---
title: Palavras reservadas
ms.date: 11/04/2016
f1_keywords:
- code
- CONFORMING
- DISCARDABLE
- Description
- base
- APPLOADER
- Data
- DYNAMIC
- DEV386
helpviewer_keywords:
- .def files [C++], reserved words
- def files [C++], reserved words
- linker [C++], reserved words
- reserved words [C++]
ms.assetid: 9b9f49e5-0739-45ab-a37e-81e3915ceb25
ms.openlocfilehash: 62893d4af1633bc2c89d2d6a0fa71309a0411ad5
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88836836"
---
# <a name="reserved-words"></a>Palavras reservadas

As palavras a seguir são reservadas pelo vinculador. Esses nomes podem ser usados como argumentos em [instruções de definição de módulo](module-definition-dot-def-files.md) somente se o nome estiver entre aspas duplas ("").

:::row:::
   :::column span="":::
      **`APPLOADER`**<sup>uma</sup>\
      **`BASE`**\
      **`CODE`**\
      **`CONFORMING`**\
      **`DATA`**\
      **`DESCRIPTION`**\
      **`DEV386`**\
      **`DISCARDABLE`**\
      **`DYNAMIC`**\
      **`EXECUTE-ONLY`**\
      **`EXECUTEONLY`**\
      **`EXECUTEREAD`**\
      **`EXETYPE`**\
      **`EXPORTS`**\
      **`FIXED`**<sup>uma</sup>
   :::column-end:::
   :::column span="":::
      **`FUNCTIONS`**<sup>2</sup>\
      **`HEAPSIZE`**\
      **`IMPORTS`**\
      **`IMPURE`**<sup>uma</sup>\
      **`INCLUDE`**<sup>2</sup>\
      **`INITINSTANCE`**<sup>2</sup>\
      **`IOPL`**\
      **`LIBRARY`**<sup>uma</sup>\
      **`LOADONCALL`**<sup>uma</sup>\
      **`LONGNAMES`**<sup>2</sup>\
      **`MOVABLE`**<sup>uma</sup>\
      **`MOVEABLE`**<sup>uma</sup>\
      **`MULTIPLE`**\
      **`NAME`**\
      **`NEWFILES`**<sup>2</sup>
   :::column-end:::
   :::column span="":::
      **`NODATA`**<sup>uma</sup>\
      **`NOIOPL`**<sup>uma</sup>\
      **`NONAME`**\
      **`NONCONFORMING`**<sup>uma</sup>\
      **`NONDISCARDABLE`**\
      **`NONE`**\
      **`NONSHARED`**\
      **`NOTWINDOWCOMPAT`**<sup>uma</sup>\
      **`OBJECTS`**\
      **`OLD`**<sup>uma</sup>\
      **`PRELOAD`**\
      **`PRIVATE`**\
      **`PROTMODE`**<sup>2</sup>\
      **`PURE`**<sup>uma</sup>\
      **`READONLY`**
   :::column-end:::
   :::column span="":::
      **`READWRITE`**\
      **`REALMODE`**<sup>uma</sup>\
      **`RESIDENT`**\
      **`RESIDENTNAME`**<sup>uma</sup>\
      **`SECTIONS`**\
      **`SEGMENTS`**\
      **`SHARED`**\
      **`SINGLE`**\
      **`STACKSIZE`**\
      **`STUB`**\
      **`VERSION`**\
      **`WINDOWAPI`**\
      **`WINDOWCOMPAT`**\
      **`WINDOWS`**
   :::column-end:::
:::row-end:::

<sup>1</sup> o vinculador emite um aviso ("ignorado") quando encontra esse termo. No entanto, a palavra ainda está reservada.

<sup>2</sup> o vinculador ignora essa palavra, mas não emite nenhum aviso.

## <a name="see-also"></a>Confira também

- [Referência de vinculador MSVC](linking.md)
- [Opções do vinculador MSVC](linker-options.md)
