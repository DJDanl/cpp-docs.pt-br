---
title: Palavras reservadas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- .def files [C++], reserved words
- def files [C++], reserved words
- linker [C++], reserved words
- reserved words [C++]
ms.assetid: 9b9f49e5-0739-45ab-a37e-81e3915ceb25
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 132bd8e5ba66cbf9486a6da4747994c667e2f6e7
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/01/2018
ms.locfileid: "34705654"
---
# <a name="reserved-words"></a>Palavras reservadas

As seguintes palavras são reservadas pelo vinculador. Esses nomes podem ser usados como argumentos em [instruções de definição de módulo](../../build/reference/module-definition-dot-def-files.md) somente se o nome é colocado entre aspas duplas ("").

||||
|-|-|-|
|**APPLOADER**<sup>1</sup>|**INITINSTANCE**<sup>2</sup>|**PRÉ-CARREGAMENTO**|
|**BASE**|**IOPL**|**PRIVADA**|
|**CÓDIGO**|**BIBLIOTECA**<sup>1</sup>|**PROTMODE**<sup>2</sup>|
|**EM CONFORMIDADE**|**LOADONCALL**<sup>1</sup>|**PURO**<sup>1</sup>|
|**DADOS**|**LONGNAMES**<sup>2</sup>|**READONLY**|
|**DESCRIÇÃO**|**PODEM SER MOVIDOS**<sup>1</sup>|**READWRITE**|
|**DEV386**|**MOVEABLE**<sup>1</sup>|**MODO REAL**<sup>1</sup>|
|**DESCARTÁVEIS**|**VÁRIOS**|**RESIDENTE**|
|**DINÂMICO**|**NOME**|**RESIDENTNAME**<sup>1</sup>|
|**SOMENTE PARA EXECUÇÃO**|**NEWFILES**<sup>2</sup>|**SEÇÕES**|
|**EXECUTEONLY**|**NODATA**<sup>1</sup>|**SEGMENTOS**|
|**EXECUTEREAD**|**NOIOPL**<sup>1</sup>|**COMPARTILHADO**|
|**EXETYPE**|**SEM NOME**|**ÚNICO**|
|**EXPORTS**|**NÃO CONFORMES**<sup>1</sup>|**STACKSIZE**|
|**FIXA**<sup>1</sup>|**NONDISCARDABLE**|**STUB**|
|**FUNÇÕES**<sup>2</sup>|**NENHUM**|**VERSÃO**|
|**HEAPSIZE**|**NÃO COMPARTILHADO**|**WINDOWAPI**|
|**IMPORTAÇÕES**|**NOTWINDOWCOMPAT**<sup>1</sup>|**WINDOWCOMPAT**|
|**IMPUROS**<sup>1</sup>|**OBJETOS**|**WINDOWS**|
|**INCLUIR**<sup>2</sup>|**ANTIGO**<sup>1</sup>||

<sup>1</sup> o vinculador emite um aviso ("ignorado") quando ele encontra esse termo. No entanto, a palavra é preservada.

<sup>2</sup> o vinculador ignora essa palavra mas emite sem aviso.

## <a name="see-also"></a>Consulte também

- [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)
- [Opções do vinculador](../../build/reference/linker-options.md)