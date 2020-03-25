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
ms.openlocfilehash: 16caacb77e052eebc8e2cd101990ee373535bd6e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80171145"
---
# <a name="reserved-words"></a>Palavras reservadas

As palavras a seguir são reservadas pelo vinculador. Esses nomes podem ser usados como argumentos em [instruções de definição de módulo](module-definition-dot-def-files.md) somente se o nome estiver entre aspas duplas ("").

||||
|-|-|-|
|**Apploader**<sup>1</sup>|**INITINSTANCE**<sup>2</sup>|**CARREGAMENTO**|
|**POLYBASE**|**IOPL**|**PESSOAL**|
|**AUTO-completar**|**Biblioteca**<sup>1</sup>|**Protmode**<sup>2</sup>|
|**EM conformidade com**|**LOADONCALL**<sup>1</sup>|**Puro**<sup>1</sup>|
|**DADO**|**Longnames**<sup>2</sup>|**LEITURA**|
|**DESCRIPTION**|**Móvel**<sup>1</sup>|**READWRITE**|
|**DEV386**|**Móvel**<sup>1</sup>|**Realmode**<sup>1</sup>|
|**Descartado**|**VÁRIOS**|**Ponteiro**|
|**DINÂMICO**|**NOME**|**Resident**<sup>1</sup>|
|**SOMENTE EXECUÇÃO**|**NewFiles**<sup>2</sup>|**AS**|
|**EXECUTEONLY**|**NODATA**<sup>1</sup>|**RETO**|
|**EXECUTEREAD**|**NOIOPL**<sup>1</sup>|**COMPARTILHADO**|
|**EXETYPE**|**NONAME**|**EXCLUSIVO**|
|**EXPORTS**|Não **conforme**<sup>1</sup>|**STACKSIZE**|
|**Corrigido**em<sup>1</sup>|**Não DESCARTÁvel**|**STUB**|
|**Funções**<sup>2</sup>|**NONE**|**VERSION**|
|**HEAPSIZE**|**Não compartilhado**|**WINDOWAPI**|
|**IMPORTAR**|**NOTWINDOWCOMPAT**<sup>1</sup>|**WINDOWCOMPAT**|
|**Impuro**<sup>1</sup>|**OBJETO**|**WINDOWS**|
|**Incluir**<sup>2</sup>|**Antigo**<sup>1</sup>||

<sup>1</sup> o vinculador emite um aviso ("ignorado") quando encontra esse termo. No entanto, a palavra ainda está reservada.

<sup>2</sup> o vinculador ignora essa palavra, mas não emite nenhum aviso.

## <a name="see-also"></a>Confira também

- [Referência de vinculador MSVC](linking.md)
- [Opções de vinculador MSVC](linker-options.md)
