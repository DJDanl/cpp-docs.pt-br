---
title: Incluindo nomes de arquivo entre aspas
ms.date: 11/04/2016
ms.assetid: 789a047e-ea38-4c99-b71d-a2ad9c81daee
ms.openlocfilehash: 4083519d6f6b9b4d037b0c2998737f3a5062c6cf
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62232950"
---
# <a name="including-quoted-filenames"></a>Incluindo nomes de arquivo entre aspas

**ANSI 3.8.2** O suporte para nomes entre aspas para arquivos de origem incluíveis

Se você indicar uma especificação de caminho completa e inequívoca para o arquivo de inclusão entre aspas duplas (" "), o pré-processador pesquisará apenas essa especificação de caminho e ignorará os diretórios padrão.

Para arquivos de inclusão especificados como [#include](../preprocessor/hash-include-directive-c-cpp.md) "path-spec", a pesquisa de diretórios começa com os diretórios do arquivo pai e continua pelos diretórios dos arquivos avô, se houver. Assim, a pesquisa começa em relação ao diretório que contém o arquivo de origem que está sendo processado. Se não houver nenhum arquivo avô e o arquivo não tiver sido encontrado, a pesquisa continuará como se o nome do arquivo estivesse entre colchetes angulares.

## <a name="see-also"></a>Confira também

[Pré-processando diretivas](../c-language/preprocessing-directives.md)
