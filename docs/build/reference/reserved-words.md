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
ms.openlocfilehash: 7d51f599dfb81dfa860e1bdba86c4372e80379fb
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57822438"
---
# <a name="reserved-words"></a>Palavras reservadas

As seguintes palavras são reservadas pelo vinculador. Esses nomes podem ser usados como argumentos em [instruções de definição de módulo](module-definition-dot-def-files.md) somente se o nome está entre aspas duplas ("").

||||
|-|-|-|
|**APPLOADER**<sup>1</sup>|**INITINSTANCE**<sup>2</sup>|**PRELOAD**|
|**BASE**|**IOPL**|**PRIVADO**|
|**CODE**|**LIBRARY**<sup>1</sup>|**PROTMODE**<sup>2</sup>|
|**EM CONFORMIDADE COM**|**LOADONCALL**<sup>1</sup>|**PURO**<sup>1</sup>|
|**DADOS**|**LONGNAMES**<sup>2</sup>|**READONLY**|
|**DESCRIÇÃO**|**MOVÍVEL**<sup>1</sup>|**READWRITE**|
|**DEV386**|**MOVEABLE**<sup>1</sup>|**MODO REAL**<sup>1</sup>|
|**DISCARDABLE**|**MULTIPLE**|**RESIDENTE**|
|**DYNAMIC**|**NOME**|**RESIDENTNAME**<sup>1</sup>|
|**EXECUTE-ONLY**|**NEWFILES**<sup>2</sup>|**SEÇÕES**|
|**EXECUTEONLY**|**NODATA**<sup>1</sup>|**SEGMENTOS**|
|**EXECUTEREAD**|**NOIOPL**<sup>1</sup>|**COMPARTILHADO**|
|**EXETYPE**|**NONAME**|**SINGLE**|
|**EXPORTS**|**NÃO CONFORMES**<sup>1</sup>|**STACKSIZE**|
|**FIXO**<sup>1</sup>|**NONDISCARDABLE**|**STUB**|
|**FUNÇÕES**<sup>2</sup>|**NONE**|**VERSION**|
|**HEAPSIZE**|**NÃO COMPARTILHADOS**|**WINDOWAPI**|
|**IMPORTAÇÕES**|**NOTWINDOWCOMPAT**<sup>1</sup>|**WINDOWCOMPAT**|
|**IMPUROS**<sup>1</sup>|**OBJECTS**|**WINDOWS**|
|**INCLUDE**<sup>2</sup>|**OLD**<sup>1</sup>||

<sup>1</sup> o vinculador emite um aviso ("ignorado") quando encontra esse termo. No entanto, a palavra é preservada.

<sup>2</sup> o vinculador ignora essa palavra, mas não emite nenhum aviso.

## <a name="see-also"></a>Consulte também

- [Referência de vinculador MSVC](linking.md)
- [Opções do vinculador MSVC](linker-options.md)