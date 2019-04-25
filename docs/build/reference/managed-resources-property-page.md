---
title: Página de propriedades Recursos Gerenciados
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCManagedResourceCompilerTool.ResourceFileName
- VC.Project.VCManagedResourceCompilerTool.OutputFileName
- VC.Project.VCManagedResourceCompilerTool.DefaultLocalizedResources
helpviewer_keywords:
- Managed Resources property page
ms.assetid: 80b80384-ee55-494d-9f0e-907bb98cfc19
ms.openlocfilehash: 394aac779fceb4d9d5918e4a5ad36eee8be896ea
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62321456"
---
# <a name="managed-resources-property-page"></a>Página de propriedades Recursos Gerenciados

Habilita as configurações do compilador de recurso.

A página de propriedades de **Recursos Gerenciados** contém as seguintes propriedades:

- **Nome Lógico de Recurso**

   Especifica o *nome lógico* do arquivo .resources intermediário gerado. O nome lógico é o nome usado para carregar o recurso. Se nenhum nome lógico é especificado, o nome do arquivo de recurso (.resx) é usado como o nome lógico.

- **Nome do arquivo de saída**

   Especifica o nome do arquivo de saída final para o qual o arquivo de recurso (.resx) contribui.

- **Recursos Localizados Padrão**

   Especifica se o arquivo .resx fornecido contribui para os recursos padrão ou para uma .dll satélite.

Para obter informações sobre como acessar o **recursos gerenciados** página de propriedades, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

## <a name="see-also"></a>Consulte também

[Usando o RC (a linha de comando do RC)](/windows/desktop/menurc/using-rc-the-rc-command-line-)<br>
[Referência de página de propriedades do projeto C++](property-pages-visual-cpp.md)<br>
[/ASSEMBLYRESOURCE (inserir um recurso gerenciado)](assemblyresource-embed-a-managed-resource.md)
