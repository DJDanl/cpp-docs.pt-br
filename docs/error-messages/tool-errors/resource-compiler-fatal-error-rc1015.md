---
title: Recurso compilador Erro Fatal RC1015 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- RC1015
dev_langs:
- C++
helpviewer_keywords:
- RC1015
ms.assetid: 23f187e1-5538-40b5-9042-edd2888f55c2
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: c466abac9b74c2f33f81f4b2ba771ffaf728ad94
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="resource-compiler-fatal-error-rc1015"></a>Erro fatal RC1015 (compilador de recurso)
não é possível abrir incluem 'arquivo'  
  
 O arquivo de inclusão especificado não existe, não pôde ser aberto ou não foi encontrado.  
  
 Certifique-se de que as configurações de ambiente são válidas e se o caminho correto para o arquivo é especificado. Certifique-se de que os identificadores de arquivo suficientes estão disponíveis para o compilador de recurso. Se o arquivo estiver em uma unidade de rede, certifique-se de que você tenha permissões para abrir o arquivo.  
  
 RC1015 pode ocorrer mesmo que o arquivo de inclusão existe em um diretório especificado como um diretório adicional incluem nas propriedades de configuração-> recursos-> página de propriedades geral; Especifique o caminho completo para o arquivo de inclusão.  
  
 Para obter mais informações, consulte o artigo da Base de dados de Conhecimento Q326987: RC1015 erro quando usando o recurso modo de exibição se o caminho de inclusão é muito longo.
