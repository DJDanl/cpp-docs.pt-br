---
title: Aviso PRJ0049 no Build do Projeto
ms.date: 11/04/2016
helpviewer_keywords:
- PRJ0049
ms.assetid: 8b38afa1-e080-4efd-ae89-776cfd044413
ms.openlocfilehash: 0252103757df1c5dc95c9691c6da1d3630d29772
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59035553"
---
# <a name="project-build-warning-prj0049"></a>Aviso PRJ0049 no Build do Projeto

Destino referenciado '\<referência >' requer o .NET Framework \<MinFrameworkVersion > e não funcionará na estrutura de destino deste projeto

Aplicativos criados usando o Visual Studio 2008 podem especificar qual versão do .NET Framework devem ter como destino. Se você adicionar uma referência a um assembly ou projeto que depende de uma versão do .NET Framework que é posterior à versão de destino, você receberá esse aviso em tempo de compilação.

### <a name="to-correct-this-warning"></a>Para corrigir este aviso

1. Escolha uma das seguintes opções:

   - Alterar a estrutura de destino do projeto **páginas de propriedade** caixa de diálogo para que seja posterior ou igual à versão mínima do framework de todos os assemblies referenciados e projetos. Para obter mais informações, consulte [adicionando referências](../../build/adding-references-in-visual-cpp-projects.md).

   - Remova a referência ao assembly ou projeto que tem uma versão mínima do framework que é posterior a estrutura de destino. Esses itens serão marcados com um ícone de aviso do projeto **páginas de propriedade**.

## <a name="see-also"></a>Consulte também

[Erros e avisos de build do projeto (PRJxxxx)](../../error-messages/tool-errors/project-build-errors-and-warnings-prjxxxx.md)