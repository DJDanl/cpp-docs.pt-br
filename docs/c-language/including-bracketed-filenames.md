---
title: Incluindo nomes de arquivo entre colchetes
ms.date: 11/04/2016
ms.assetid: 6a4e5411-c35e-48b8-90ef-b37ac324ed94
ms.openlocfilehash: 87de00814f58ed86ee33abdcf96dd210f418c5ba
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62233093"
---
# <a name="including-bracketed-filenames"></a>Incluindo nomes de arquivo entre colchetes

**ANSI 3.8.2** O método para localizar arquivos de origem incluíveis

Para as especificações de arquivo colocadas entre colchetes angulares, o pré-processador não pesquisa diretórios dos arquivos pai. Um arquivo "pai" é o arquivo que contém a diretiva [#include](../preprocessor/hash-include-directive-c-cpp.md). Em vez disso, ele começa procurando o arquivo nos diretórios especificados na linha de comando do compilador depois de /I. Se a opção /I não estiver presente ou falhar, o pré-processador usará a variável de ambiente INCLUDE para localizar os arquivos de inclusão entre colchetes angulares. A variável de ambiente INCLUDE pode conter vários caminhos separados por ponto e vírgula (**;**). Se mais de um diretório aparecer como parte da opção /I ou dentro da variável de ambiente INCLUDE, o pré-processador procurará por eles na ordem em que aparecem.

## <a name="see-also"></a>Confira também

[Pré-processando diretivas](../c-language/preprocessing-directives.md)
