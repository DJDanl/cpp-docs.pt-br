---
title: Linha de comando aviso d9041 () | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- D9041
dev_langs:
- C++
helpviewer_keywords:
- D9041
ms.assetid: ada8815f-4246-4e25-b57d-a7f16fa107cc
caps.latest.revision: 3
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: e044b98fff8777a7ac8e1edb6a664659f764dbc7
ms.lasthandoff: 02/25/2017

---
# <a name="command-line-warning-d9041"></a>Aviso D9041 (linha de comando)
valor inválido 'value' para 'opção'; Supondo que o 'valor'; Adicionar ' /ANALYZE ' Opções de linha de comando ao especificar esse aviso  
  
 Um número de aviso de análise de código foi adicionado para o **/wd**, **/we**, **/wo**, ou **/wl** opção de linha de comando sem especificar o **/ANALYZE** opção de linha de comando. Para corrigir esse erro, adicione o **/ANALYZE** opção de linha de comando, ou remova o número inválido de aviso apropriado **/w** opção de linha de comando.  
  
## <a name="example"></a>Exemplo  
 O exemplo de linha de comando a seguir gera o aviso d9041 ():  
  
```  
cl /EHsc /LD /wd6001 filename.cpp  
```  
  
 Para corrigir o aviso, adicione o **/ANALYZE** opção de linha de comando. Se **/ANALYZE** não é tem suporte na sua versão do compilador, remover o número de aviso inválido do **/wd** opção.  
  
## <a name="see-also"></a>Consulte também  
 [Erros de linha de comando D8000 até D9999](../../error-messages/tool-errors/command-line-errors-d8000-through-d9999.md)   
 [Opções do Compilador](../../build/reference/compiler-options.md)
