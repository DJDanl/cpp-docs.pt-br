---
title: Recurso compilador Erro Fatal RC1015 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: RC1015
dev_langs: C++
helpviewer_keywords: RC1015
ms.assetid: 23f187e1-5538-40b5-9042-edd2888f55c2
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 666221cf5c3e812cd856271ea97cf4966383ec20
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="resource-compiler-fatal-error-rc1015"></a>Erro fatal RC1015 (compilador de recurso)
não é possível abrir incluem 'arquivo'  
  
 O arquivo de inclusão especificado não existe, não pôde ser aberto ou não foi encontrado.  
  
 Certifique-se de que as configurações de ambiente são válidas e se o caminho correto para o arquivo é especificado. Certifique-se de que os identificadores de arquivos suficientes estejam disponíveis para o compilador de recurso. Se o arquivo estiver em uma unidade de rede, certifique-se de que você tem permissões para abrir o arquivo.  
  
 RC1015 pode ocorrer mesmo que o arquivo de inclusão existe em um diretório especificado como um diretório adicional de incluir nas propriedades de configuração -> recursos -> página de propriedades geral. Especifique o caminho completo para o arquivo de inclusão.  
  
 Para obter mais informações, consulte o artigo da Base de dados de Conhecimento Q326987: RC1015 erro quando usando o recurso de exibição se o caminho de inclusão é muito longo.