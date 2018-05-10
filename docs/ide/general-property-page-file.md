---
title: Página de propriedade geral (arquivo) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- VC.Project.VCFileConfiguration.ExcludedFromBuild
- VC.Project.VCFileConfiguration.Tool
dev_langs:
- C++
ms.assetid: 26e3711e-9e7d-4e8d-bc4c-2474538efdad
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 523ac16a647116f4d18da7e516adb4f0e6bb7fc4
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="general-property-page-file"></a>Página de propriedade geral (arquivo)

Quando um arquivo é selecionado no **Solution Explorer**, o **geral** página de propriedade sob o **propriedades de configuração** nó contém as seguintes propriedades:

**Excluir da compilação**  
Especifica se o arquivo deve estar em compilação para a configuração atual.

Para acessar essa propriedade de forma programática, consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCFileConfiguration.ExcludedFromBuild%2A>.

**Ferramenta**  
A ferramenta que será usada para criar esse arquivo. Consulte [especificando ferramentas de compilação personalizada](../ide/specifying-custom-build-tools.md) para obter mais informações.

Para acessar essa propriedade de forma programática, consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCFileConfiguration.Tool%2A>.

Para obter informações sobre como acessar o **geral** página de propriedade sob o **propriedades de configuração** nó, consulte [trabalhar com propriedades do projeto](../ide/working-with-project-properties.md).

Para projetos de não-Windows, consulte [referência da página de propriedade do Linux C++](../linux/prop-pages-linux.md)<!-- or [C++ Cross Platform Property Page Reference](../linux/prop-pages-linux.md)-->.

## <a name="see-also"></a>Consulte também

[Páginas de propriedade](../ide/property-pages-visual-cpp.md)  