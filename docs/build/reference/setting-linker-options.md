---
title: Definindo opções de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- files [C++], LINK
- input files [C++], linker
- linker [C++], ways to set options
- linker [C++], switches
- input files [C++]
- object/library modules
ms.assetid: e08fb487-0f2e-4f24-87db-232dbc8bd2e2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d2fd99732c7f79b3c61ff5b31516b98a478ed4a8
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45713070"
---
# <a name="setting-linker-options"></a>Definindo opções de vinculador

Opções de vinculador podem ser definidas dentro ou fora do ambiente de desenvolvimento. O tópico de cada opção de vinculador discute como ela pode ser definida no ambiente de desenvolvimento. Ver [opções de vinculador](../../build/reference/linker-options.md) para obter uma lista completa.

Quando você executa o vínculo fora do ambiente de desenvolvimento, você pode especificar a entrada de uma ou mais formas:

- Sobre o [linha de comando](../../build/reference/linker-command-line-syntax.md)

- Usando [arquivos de comando](../../build/reference/link-command-files.md)

- No [variáveis de ambiente](../../build/reference/link-environment-variables.md)

Opções de processos primeiro LINK especificado na variável de ambiente LINK, seguido pelas opções na ordem em que elas são especificadas na linha de comando e nos arquivos de comando. Se uma opção é repetida com argumentos diferentes, o último processado terá precedência.

As opções se aplicam à compilação inteira; Não há opções podem ser aplicadas a arquivos de entrada específicos.

## <a name="see-also"></a>Consulte também

[Referência de build C/C++](../../build/reference/c-cpp-building-reference.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)