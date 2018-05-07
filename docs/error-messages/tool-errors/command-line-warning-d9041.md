---
title: Linha de comando D9041 de aviso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- D9041
dev_langs:
- C++
helpviewer_keywords:
- D9041
ms.assetid: ada8815f-4246-4e25-b57d-a7f16fa107cc
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c22573d26e09e14789f4cbd64d68f4082125c2b3
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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