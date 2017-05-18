---
title: BSCMAKE erro BK1503 | Documentos do Microsoft
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
caps.latest.revision: 7
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
ms.openlocfilehash: f99f0c8256816a1d9ee5a926e13488f6177a404b
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="bscmake-error-bk1503"></a>Erro BK1503 (BSCMAKE)
não é possível gravar no arquivo 'arquivo' [: motivo]  
  
 BSCMAKE combina os arquivos. SBR gerados durante a compilação em um banco de dados do navegador. Se o banco de dados resultante do navegador excede 64 MB, ou se o número de arquivos de entrada (SBR) exceder 4092, esse erro será emitido.  
  
 Se o problema for causado por mais de 4092 arquivos. SBR, você deve reduzir o número de arquivos de entrada. De dentro do Visual Studio, isso pode ser feito por [/FR](../../build/reference/fr-fr-create-dot-sbr-file.md) o projeto inteiro, em seguida, nova verificação arquivo por arquivo.  
  
 Se o problema é causado por um arquivo. bsc maior que 64MB, reduzindo o número de arquivos. SBR como entrada diminuirá o tamanho do arquivo. bsc resultante. Além disso, a quantidade de informações de pesquisa pode ser reduzida com o uso de /Em (Excluir Macro expandida símbolos), /El (excluir variáveis locais) e /Es (excluir arquivos do sistema).  
  
## <a name="see-also"></a>Consulte também  
 [Opções de BSCMAKE](../../build/reference/bscmake-options.md)
