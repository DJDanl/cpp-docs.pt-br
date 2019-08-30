---
title: Página de propriedades Recursos Gerenciados
ms.date: 08/28/2019
f1_keywords:
- VC.Project.VCManagedResourceCompilerTool.ResourceFileName
- VC.Project.VCManagedResourceCompilerTool.OutputFileName
- VC.Project.VCManagedResourceCompilerTool.DefaultLocalizedResources
helpviewer_keywords:
- Managed Resources property page
ms.assetid: 80b80384-ee55-494d-9f0e-907bb98cfc19
ms.openlocfilehash: 14802996e63392bfb5fcc22096ef5f3d9db197c2
ms.sourcegitcommit: e10a5feea193c249ddc5a6faba48e7c6d8784e73
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/30/2019
ms.locfileid: "70177531"
---
# <a name="managed-resources-property-page"></a>Página de propriedades Recursos Gerenciados

A página de propriedades **recursos gerenciados** expõe as seguintes propriedades para o compilador de recurso gerenciado ResGen [. exe](/dotnet/framework/tools/resgen-exe-resource-file-generator) ao usar C++os recursos do .net em programas da/CLI:

- **Nome Lógico de Recurso**

   Especifica o *nome lógico* do arquivo .resources intermediário gerado. O nome lógico é o nome usado para carregar o recurso. Se nenhum nome lógico é especificado, o nome do arquivo de recurso (.resx) é usado como o nome lógico.

- **Nome do arquivo de saída**

   Especifica o nome do arquivo de saída final para o qual o arquivo de recurso (.resx) contribui.

- **Recursos Localizados Padrão**

   Especifica se o arquivo .resx fornecido contribui para os recursos padrão ou para uma .dll satélite.

Para obter informações sobre como acessar a página de propriedades de **recursos gerenciados** , consulte [definir C++ as propriedades do compilador e de compilação no Visual Studio](../working-with-project-properties.md).

## <a name="see-also"></a>Consulte também

[Usando o RC (a linha de comando do RC)](/windows/win32/menurc/using-rc-the-rc-command-line-)<br>
[C++referência de página de propriedades do projeto](property-pages-visual-cpp.md)<br>
[/ASSEMBLYRESOURCE (inserir um recurso gerenciado)](assemblyresource-embed-a-managed-resource.md)
