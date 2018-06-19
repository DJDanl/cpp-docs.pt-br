---
title: Aviso prj0049 no Build do projeto | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
dev_langs:
- C++
helpviewer_keywords:
- PRJ0049
ms.assetid: 8b38afa1-e080-4efd-ae89-776cfd044413
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8df6fcb8bc5d6517a46279e0bef5036db1e81241
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33319804"
---
# <a name="project-build-warning-prj0049"></a>Aviso PRJ0049 no Build do Projeto
Destino referenciado '\<referência >' requer o .NET Framework \<MinFrameworkVersion > e não funcionará na estrutura de destino deste projeto  
  
 Os aplicativos criados usando o Visual Studio 2008 podem especificar qual versão do [!INCLUDE[dnprdnshort](../../error-messages/tool-errors/includes/dnprdnshort_md.md)] devem ser voltados para eles. Se você adicionar uma referência a um assembly ou o projeto que depende de uma versão do [!INCLUDE[dnprdnshort](../../error-messages/tool-errors/includes/dnprdnshort_md.md)] que é posterior à versão de destino, você receberá esse aviso em tempo de compilação.  
  
### <a name="to-correct-this-warning"></a>Para corrigir este aviso  
  
1.  Escolha uma das seguintes opções:  
  
    -   Altere o framework de destino do projeto **páginas de propriedade** caixa de diálogo para que seja posterior ou igual à versão do framework mínimo de todos os assemblies referenciados e projetos. Para obter mais informações, consulte [adicionando referências](../../ide/adding-references-in-visual-cpp-projects.md).  
  
    -   Remova a referência ao assembly ou projeto que tem uma versão mínima do framework que seja posterior do framework de destino. Esses itens serão marcados com um ícone de aviso do projeto **páginas de propriedade**.  
  
## <a name="see-also"></a>Consulte também  
 [Erros e avisos de build do projeto (PRJxxxx)](../../error-messages/tool-errors/project-build-errors-and-warnings-prjxxxx.md)