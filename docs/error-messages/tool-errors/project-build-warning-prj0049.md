---
title: Aviso PRJ0049 no Build do Projeto
ms.date: 11/04/2016
helpviewer_keywords:
- PRJ0049
ms.assetid: 8b38afa1-e080-4efd-ae89-776cfd044413
ms.openlocfilehash: e857a50215dc7516c0e2ec45a97638c76f40f43b
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80191738"
---
# <a name="project-build-warning-prj0049"></a>Aviso PRJ0049 no Build do Projeto

O destino referenciado '\<Reference > ' requer .NET Framework \<MinFrameworkVersion > e não será executado na estrutura de destino deste projeto

Os aplicativos criados usando o Visual Studio 2008 podem especificar qual versão do .NET Framework eles devem ter como destino. Se você adicionar uma referência a um assembly ou projeto que dependa de uma versão do .NET Framework posterior à versão de destino, você receberá esse aviso no momento da compilação.

### <a name="to-correct-this-warning"></a>Para corrigir este aviso

1. Escolha uma destas opções:

   - Altere a estrutura de destino na caixa de diálogo **páginas de propriedades** do projeto para que ela seja posterior ou igual à versão mínima da estrutura de todos os assemblies e projetos referenciados. Para obter mais informações, consulte [adicionando referências](../../build/adding-references-in-visual-cpp-projects.md).

   - Remova a referência ao assembly ou projeto que tem uma versão de estrutura mínima posterior à estrutura de destino. Esses itens serão marcados com um ícone de aviso nas **páginas de propriedades**do projeto.

## <a name="see-also"></a>Confira também

[Erros e avisos de build do projeto (PRJxxxx)](../../error-messages/tool-errors/project-build-errors-and-warnings-prjxxxx.md)
