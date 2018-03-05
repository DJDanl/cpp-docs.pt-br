---
title: Incluindo nomes de arquivo entre aspas | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: 789a047e-ea38-4c99-b71d-a2ad9c81daee
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 75b9e308fec394825b3113a716ead2c93e9bb290
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="including-quoted-filenames"></a>Incluindo nomes de arquivo entre aspas
**ANSI 3.8.2** O suporte para nomes entre aspas para arquivos de origem incluíveis  
  
 Se você indicar uma especificação de caminho completa e inequívoca para o arquivo de inclusão entre aspas duplas (" "), o pré-processador pesquisará apenas essa especificação de caminho e ignorará os diretórios padrão.  
  
 Para arquivos de inclusão especificados como [#include](../preprocessor/hash-include-directive-c-cpp.md) "path-spec", a pesquisa de diretórios começa com os diretórios do arquivo pai e continua pelos diretórios dos arquivos avô, se houver. Assim, a pesquisa começa em relação ao diretório que contém o arquivo de origem que está sendo processado. Se não houver nenhum arquivo avô e o arquivo não tiver sido encontrado, a pesquisa continuará como se o nome do arquivo estivesse entre colchetes angulares.  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas de pré-processamento](../c-language/preprocessing-directives.md)