---
title: Recurso compilador Erro Fatal RC1015 | Microsoft Docs
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
ms.openlocfilehash: b7744242e44ecfc72ee57ab979969ad81b209e57
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33322816"
---
# <a name="resource-compiler-fatal-error-rc1015"></a>Erro fatal RC1015 (compilador de recurso)
não é possível abrir incluem 'arquivo'  
  
 O arquivo de inclusão especificado não existe, não pôde ser aberto ou não foi encontrado.  
  
 Certifique-se de que as configurações de ambiente são válidas e se o caminho correto para o arquivo é especificado. Certifique-se de que os identificadores de arquivos suficientes estejam disponíveis para o compilador de recurso. Se o arquivo estiver em uma unidade de rede, certifique-se de que você tem permissões para abrir o arquivo.  
  
 RC1015 pode ocorrer mesmo que o arquivo de inclusão existe em um diretório especificado como um diretório adicional de incluir nas propriedades de configuração -> recursos -> página de propriedades geral. Especifique o caminho completo para o arquivo de inclusão.  
  
 Para obter mais informações, consulte o artigo da Base de dados de Conhecimento Q326987: RC1015 erro quando usando o recurso de exibição se o caminho de inclusão é muito longo.