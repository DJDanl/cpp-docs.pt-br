---
title: RC1015 de Erro Fatal do compilador de recurso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- RC1015
dev_langs:
- C++
helpviewer_keywords:
- RC1015
ms.assetid: 23f187e1-5538-40b5-9042-edd2888f55c2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7a72cba53ebe9a286ac2e7cbbf2c41b78f4e4e08
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46100746"
---
# <a name="resource-compiler-fatal-error-rc1015"></a>Erro fatal RC1015 (compilador de recurso)

não é possível abrir incluem o arquivo 'filename'

O arquivo de inclusão especificado não existe, não pôde ser aberto ou não foi encontrado.

Certifique-se de que as configurações de ambiente são válidas e se o caminho correto para o arquivo está especificado. Certifique-se de que os identificadores de arquivos suficientes estejam disponíveis para o compilador de recurso. Se o arquivo estiver em uma unidade de rede, certifique-se de que você tenha permissões para abrir o arquivo.

RC1015 pode ocorrer mesmo que o arquivo de inclusão existe em um diretório especificado como um diretório adicional de incluir nas propriedades de configuração -> recursos -> página de propriedades geral; Especifique o caminho completo para o arquivo de inclusão.

Para obter mais informações, consulte o artigo da Base de dados de Conhecimento Q326987: RC1015 erro quando usando o recurso modo de exibição se o caminho de inclusão é muito longo.