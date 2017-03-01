---
title: "Aviso prj0049 () de compilação de projeto | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
dev_langs:
- C++
helpviewer_keywords:
- PRJ0049
ms.assetid: 8b38afa1-e080-4efd-ae89-776cfd044413
caps.latest.revision: 5
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
ms.openlocfilehash: c0946ac08a862acefe1c9048a6fae5b657637e4c
ms.lasthandoff: 02/25/2017

---
# <a name="project-build-warning-prj0049"></a>Aviso PRJ0049 no Build do Projeto
Destino referenciado '\<referência >' requer o .NET Framework \<MinFrameworkVersion > e não funcionará na estrutura de destino do projeto  
  
 Aplicativos criados usando [!INCLUDE[vs_orcas_long](../../atl/reference/includes/vs_orcas_long_md.md)] pode especificar qual versão do [!INCLUDE[dnprdnshort](../../error-messages/tool-errors/includes/dnprdnshort_md.md)] devem ter como destino. Se você adicionar uma referência a um assembly ou projeto depende de uma versão de [!INCLUDE[dnprdnshort](../../error-messages/tool-errors/includes/dnprdnshort_md.md)] é posterior à versão de destino, você receberá esse aviso em tempo de compilação.  
  
### <a name="to-correct-this-warning"></a>Para corrigir esse aviso  
  
1.  Escolha uma das seguintes opções:  
  
    -   Alterar o framework de destino do projeto **páginas de propriedade** caixa de diálogo para que seja posterior ou igual à versão do framework mínimo de todos os assemblies referenciados e projetos. Para obter mais informações, consulte [adicionando referências](../../ide/adding-references-in-visual-cpp-projects.md).  
  
    -   Remova a referência ao assembly ou projeto que tenha uma versão do framework mínimo é posterior a estrutura de destino. Esses itens serão marcados com um ícone de aviso do projeto **páginas de propriedade**.  
  
## <a name="see-also"></a>Consulte também  
 [Erros de compilação e avisos projeto (PRJxxxx)](../../error-messages/tool-errors/project-build-errors-and-warnings-prjxxxx.md)
