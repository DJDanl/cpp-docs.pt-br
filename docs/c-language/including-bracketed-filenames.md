---
title: Incluindo nomes de arquivo entre colchetes
ms.date: 11/04/2016
ms.assetid: 6a4e5411-c35e-48b8-90ef-b37ac324ed94
ms.openlocfilehash: ddca97f6e40a9a64d809cd39c2e810890844a0ec
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50555682"
---
# <a name="including-bracketed-filenames"></a>Incluindo nomes de arquivo entre colchetes

**ANSI 3.8.2** O método para localizar arquivos de origem incluíveis

Para as especificações de arquivo colocadas entre colchetes angulares, o pré-processador não pesquisa diretórios dos arquivos pai. Um arquivo "pai" é o arquivo que contém a diretiva [#include](../preprocessor/hash-include-directive-c-cpp.md). Em vez disso, ele começa procurando o arquivo nos diretórios especificados na linha de comando do compilador depois de /I. Se a opção /I não estiver presente ou falhar, o pré-processador usará a variável de ambiente INCLUDE para localizar os arquivos de inclusão entre colchetes angulares. A variável de ambiente INCLUDE pode conter vários caminhos separados por ponto e vírgula (**;**). Se mais de um diretório aparecer como parte da opção /I ou dentro da variável de ambiente INCLUDE, o pré-processador procurará por eles na ordem em que aparecem.

## <a name="see-also"></a>Consulte também

[Diretivas de pré-processamento](../c-language/preprocessing-directives.md)