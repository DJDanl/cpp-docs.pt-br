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
ms.openlocfilehash: 2922a0a92a121d6838478daaf2c32f1c7a630d21
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2018
ms.locfileid: "33340353"
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
 [Usando o RC (a linha de comando do RC)](http://msdn.microsoft.com/library/windows/desktop/aa381055)   
 [Páginas de propriedades](../ide/property-pages-visual-cpp.md)   
 [/ASSEMBLYRESOURCE (inserir um recurso gerenciado)](../build/reference/assemblyresource-embed-a-managed-resource.md)