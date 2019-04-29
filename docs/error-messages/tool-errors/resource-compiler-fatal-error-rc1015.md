---
title: Erro fatal RC1015 (compilador de recurso)
ms.date: 11/04/2016
f1_keywords:
- RC1015
helpviewer_keywords:
- RC1015
ms.assetid: 23f187e1-5538-40b5-9042-edd2888f55c2
ms.openlocfilehash: f20101c2edc4da132c89dcda451c71af2304a13d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62297652"
---
# <a name="resource-compiler-fatal-error-rc1015"></a>Erro fatal RC1015 (compilador de recurso)

não é possível abrir incluem o arquivo 'filename'

O arquivo de inclusão especificado não existe, não pôde ser aberto ou não foi encontrado.

Certifique-se de que as configurações de ambiente são válidas e se o caminho correto para o arquivo está especificado. Certifique-se de que os identificadores de arquivos suficientes estejam disponíveis para o compilador de recurso. Se o arquivo estiver em uma unidade de rede, certifique-se de que você tenha permissões para abrir o arquivo.

RC1015 pode ocorrer mesmo que o arquivo de inclusão existe em um diretório especificado como um diretório adicional de incluir nas propriedades de configuração -> recursos -> página de propriedades geral; Especifique o caminho completo para o arquivo de inclusão.
