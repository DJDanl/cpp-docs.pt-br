---
title: Página de propriedades de Recursos Gerenciados | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- VC.Project.VCManagedResourceCompilerTool.ResourceFileName
- VC.Project.VCManagedResourceCompilerTool.OutputFileName
- VC.Project.VCManagedResourceCompilerTool.DefaultLocalizedResources
dev_langs:
- C++
helpviewer_keywords:
- Managed Resources property page
ms.assetid: 80b80384-ee55-494d-9f0e-907bb98cfc19
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a2fe0896a8fbd8b8c0a8f68847ee138017eaa36b
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43215495"
---
# <a name="managed-resources-property-page"></a>Página de propriedades Recursos Gerenciados
Habilita as configurações do compilador de recurso.  
  
 A página de propriedades de **Recursos Gerenciados** contém as seguintes propriedades:  
  
 **Nome Lógico de Recurso**  
 Especifica o *nome lógico* do arquivo .resources intermediário gerado. O nome lógico é o nome usado para carregar o recurso. Se nenhum nome lógico é especificado, o nome do arquivo de recurso (.resx) é usado como o nome lógico.  
  
 **Nome do arquivo de saída**  
 Especifica o nome do arquivo de saída final para o qual o arquivo de recurso (.resx) contribui.  
  
 **Recursos Localizados Padrão**  
 Especifica se o arquivo .resx fornecido contribui para os recursos padrão ou para uma .dll satélite.  
  
 Para obter informações sobre como acessar a página de propriedades de **Recursos Gerenciados**, confira [Trabalhando com propriedades do projeto](../ide/working-with-project-properties.md).  
  
## <a name="see-also"></a>Consulte também  
 [Usando o RC (a linha de comando do RC)](https://msdn.microsoft.com/library/windows/desktop/aa381055)   
 [Páginas de propriedades](../ide/property-pages-visual-cpp.md)   
 [/ASSEMBLYRESOURCE (inserir um recurso gerenciado)](../build/reference/assemblyresource-embed-a-managed-resource.md)