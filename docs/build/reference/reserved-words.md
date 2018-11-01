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
ms.openlocfilehash: 360baf479f9100483fe694ca8860dfc1d7ebfe11
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50502460"
---
# <a name="reserved-words"></a>Palavras reservadas

As seguintes palavras são reservadas pelo vinculador. Esses nomes podem ser usados como argumentos em [instruções de definição de módulo](../../build/reference/module-definition-dot-def-files.md) somente se o nome está entre aspas duplas ("").

||||
|-|-|-|
|**APPLOADER**<sup>1</sup>|**INITINSTANCE**<sup>2</sup>|**PRÉ-CARREGAMENTO**|
|**BASE DE DADOS DE**|**IOPL**|**PRIVADO**|
|**CÓDIGO**|**BIBLIOTECA**<sup>1</sup>|**PROTMODE**<sup>2</sup>|
|**EM CONFORMIDADE COM**|**LOADONCALL**<sup>1</sup>|**PURO**<sup>1</sup>|
|**DADOS**|**LONGNAMES**<sup>2</sup>|**READONLY**|
|**DESCRIÇÃO**|**MOVÍVEL**<sup>1</sup>|**READWRITE**|
|**DEV386**|**MOVEABLE**<sup>1</sup>|**MODO REAL**<sup>1</sup>|
|**DESCARTÁVEL**|**VÁRIOS**|**RESIDENTE**|
|**DINÂMICO**|**NOME**|**RESIDENTNAME**<sup>1</sup>|
|**SOMENTE PARA EXECUÇÃO**|**NEWFILES**<sup>2</sup>|**SEÇÕES**|
|**EXECUTEONLY**|**NODATA**<sup>1</sup>|**SEGMENTOS**|
|**EXECUTEREAD**|**NOIOPL**<sup>1</sup>|**COMPARTILHADO**|
|**EXETYPE**|**NONAME**|**ÚNICO**|
|**EXPORTS**|**NÃO CONFORMES**<sup>1</sup>|**STACKSIZE**|
|**FIXO**<sup>1</sup>|**NONDISCARDABLE**|**STUB**|
|**FUNÇÕES**<sup>2</sup>|**NONE**|**VERSÃO**|
|**HEAPSIZE**|**NÃO COMPARTILHADOS**|**WINDOWAPI**|
|**IMPORTAÇÕES**|**NOTWINDOWCOMPAT**<sup>1</sup>|**WINDOWCOMPAT**|
|**IMPUROS**<sup>1</sup>|**OBJETOS**|**WINDOWS**|
|**INCLUIR**<sup>2</sup>|**ANTIGO**<sup>1</sup>||

<sup>1</sup> o vinculador emite um aviso ("ignorado") quando encontra esse termo. No entanto, a palavra é preservada.

<sup>2</sup> o vinculador ignora essa palavra, mas não emite nenhum aviso.

## <a name="see-also"></a>Consulte também

- [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)
- [Opções do vinculador](../../build/reference/linker-options.md)