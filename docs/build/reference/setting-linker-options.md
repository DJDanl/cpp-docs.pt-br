---
title: Definindo opções de vinculador
ms.date: 11/04/2016
helpviewer_keywords:
- files [C++], LINK
- input files [C++], linker
- linker [C++], ways to set options
- linker [C++], switches
- input files [C++]
- object/library modules
ms.assetid: e08fb487-0f2e-4f24-87db-232dbc8bd2e2
ms.openlocfilehash: 5b885ad5c86bc59029fc6a3a60ccee385703ab2d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50508934"
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