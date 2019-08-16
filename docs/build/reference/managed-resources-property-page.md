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
ms.openlocfilehash: 97cf05f881949444879b0d48e3b3c2703a614985
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69498225"
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

Para obter informações sobre como acessar a página de propriedades de **recursos gerenciados** , consulte [definir C++ as propriedades do compilador e de compilação no Visual Studio](../working-with-project-properties.md).

## <a name="see-also"></a>Consulte também

[Usando o RC (a linha de comando do RC)](/windows/win32/menurc/using-rc-the-rc-command-line-)<br>
[C++referência de página de propriedades do projeto](property-pages-visual-cpp.md)<br>
[/ASSEMBLYRESOURCE (inserir um recurso gerenciado)](assemblyresource-embed-a-managed-resource.md)
