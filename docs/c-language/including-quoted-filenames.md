---
title: Incluindo nomes de arquivo entre aspas
ms.date: 11/04/2016
ms.assetid: 789a047e-ea38-4c99-b71d-a2ad9c81daee
ms.openlocfilehash: 11beaa3a91f476348c57b12ab3febad7cb9c89fc
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50656710"
---
# <a name="including-quoted-filenames"></a>Incluindo nomes de arquivo entre aspas

**ANSI 3.8.2** O suporte para nomes entre aspas para arquivos de origem incluíveis

Se você indicar uma especificação de caminho completa e inequívoca para o arquivo de inclusão entre aspas duplas (" "), o pré-processador pesquisará apenas essa especificação de caminho e ignorará os diretórios padrão.

Para arquivos de inclusão especificados como [#include](../preprocessor/hash-include-directive-c-cpp.md) "path-spec", a pesquisa de diretórios começa com os diretórios do arquivo pai e continua pelos diretórios dos arquivos avô, se houver. Assim, a pesquisa começa em relação ao diretório que contém o arquivo de origem que está sendo processado. Se não houver nenhum arquivo avô e o arquivo não tiver sido encontrado, a pesquisa continuará como se o nome do arquivo estivesse entre colchetes angulares.

## <a name="see-also"></a>Consulte também

[Diretivas de pré-processamento](../c-language/preprocessing-directives.md)