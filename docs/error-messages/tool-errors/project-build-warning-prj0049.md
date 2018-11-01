---
title: Aviso PRJ0049 no Build do Projeto
ms.date: 11/04/2016
helpviewer_keywords:
- PRJ0049
ms.assetid: 8b38afa1-e080-4efd-ae89-776cfd044413
ms.openlocfilehash: a451b7fe7b2f7cd89f8898232badf0d3b7e9f138
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50447210"
---
# <a name="project-build-warning-prj0049"></a>Aviso PRJ0049 no Build do Projeto

Destino referenciado '\<referência >' requer o .NET Framework \<MinFrameworkVersion > e não funcionará na estrutura de destino deste projeto

Aplicativos criados usando o Visual Studio 2008 podem especificar qual versão do .NET Framework devem ter como destino. Se você adicionar uma referência a um assembly ou projeto que depende de uma versão do .NET Framework que é posterior à versão de destino, você receberá esse aviso em tempo de compilação.

### <a name="to-correct-this-warning"></a>Para corrigir este aviso

1. Escolha uma das seguintes opções:

   - Alterar a estrutura de destino do projeto **páginas de propriedade** caixa de diálogo para que seja posterior ou igual à versão mínima do framework de todos os assemblies referenciados e projetos. Para obter mais informações, consulte [adicionando referências](../../ide/adding-references-in-visual-cpp-projects.md).

   - Remova a referência ao assembly ou projeto que tem uma versão mínima do framework que é posterior a estrutura de destino. Esses itens serão marcados com um ícone de aviso do projeto **páginas de propriedade**.

## <a name="see-also"></a>Consulte também

[Erros e avisos de build do projeto (PRJxxxx)](../../error-messages/tool-errors/project-build-errors-and-warnings-prjxxxx.md)