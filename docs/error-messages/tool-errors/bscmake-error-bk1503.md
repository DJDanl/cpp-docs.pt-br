---
title: BSCMAKE erro BK1503 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- BK1503
dev_langs:
- C++
helpviewer_keywords:
- BK1503
ms.assetid: e6582344-b91e-486f-baf3-4f9028d83c3b
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 86f2b6d282857409cdb1e1d49e04775e9886cde4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="bscmake-error-bk1503"></a>Erro BK1503 (BSCMAKE)
não é possível gravar no arquivo 'filename' [: motivo]  
  
 BSCMAKE combina os arquivos. SBR gerados durante a compilação em um banco de dados do navegador. Se o banco de dados do navegador resultante exceder 64 MB, ou se o número de arquivos de entrada (. SBR) excede 4092, esse erro será emitido.  
  
 Se o problema é causado por arquivos de mais de 4092. SBR, você deve reduzir o número de arquivos de entrada. De dentro do Visual Studio, isso pode ser feito por [/FR](../../build/reference/fr-fr-create-dot-sbr-file.md) o projeto inteiro, em seguida, nova verificação em uma base de arquivo por arquivo.  
  
 Se o problema é causado por um arquivo. bsc maior que 64MB, reduzindo o número de arquivos. SBR como entrada irá diminuir o tamanho do arquivo. bsc resultante. Além disso, a quantidade de informações de pesquisa pode ser reduzida com o uso de /Em (Excluir Macro expandido símbolos), /El (excluir variáveis locais) e /Es (excluir arquivos do sistema).  
  
## <a name="see-also"></a>Consulte também  
 [Opções de BSCMAKE](../../build/reference/bscmake-options.md)