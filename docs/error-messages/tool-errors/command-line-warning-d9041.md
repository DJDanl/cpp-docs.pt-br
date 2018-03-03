---
title: Linha de comando D9041 de aviso | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- D9041
dev_langs:
- C++
helpviewer_keywords:
- D9041
ms.assetid: ada8815f-4246-4e25-b57d-a7f16fa107cc
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 307d290bb525ee879f29853c6823d5b9565aba4b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="command-line-warning-d9041"></a>Aviso D9041 (linha de comando)
valor inválido 'value' para 'opção'; Supondo que o 'valor'; Adicione ' /ANALYZE ' às opções de linha de comando quando especificar este aviso  
  
 Um número de aviso de análise de código foi adicionado para o **/wd**, **/we**, **/wo**, ou **/wl** opção de linha de comando sem especificar o **/ANALYZE** opção de linha de comando. Para corrigir esse erro, adicione o **/ANALYZE** opção de linha de comando ou remova o número de aviso inválido apropriada **/w** opção de linha de comando.  
  
## <a name="example"></a>Exemplo  
 O exemplo de linha de comando a seguir gera um aviso D9041:  
  
```  
cl /EHsc /LD /wd6001 filename.cpp  
```  
  
 Para corrigir o aviso, adicione o **/ANALYZE** opção de linha de comando. Se **/ANALYZE** não é tem suporte em sua versão do compilador, remova o número de aviso inválido do **/wd** opção.  
  
## <a name="see-also"></a>Consulte também  
 [Erros de linha de comando D8000 até D9999](../../error-messages/tool-errors/command-line-errors-d8000-through-d9999.md)   
 [Opções do Compilador](../../build/reference/compiler-options.md)