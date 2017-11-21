---
title: "Página de propriedades da etapa de compilação personalizada: Geral | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCCustomBuildStep.AdditionalInputs
- VC.Project.VCCustomBuildStep.CustomBuildAfterTargets
- VC.Project.VCCustomBuildStep.CustomBuildBeforeTargets
- VC.Project.VCCustomBuildStep.Outputs
- VC.Project.VCCustomBuildStep.Message
- VC.Project.VCCustomBuildStep.Command
dev_langs: C++
helpviewer_keywords:
- project properties, custom build step
- custom build step (general)
ms.assetid: bd319741-0491-46c4-a428-7c61b4b46a02
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 10fa52dbf477f970cee0695aba13ec2eb5cfd90c
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="custom-build-step-property-page-general"></a>Página de Propriedades de Etapa de Build Personalizado: geral
Para cada combinação de configuração de projeto e plataforma de destino em seu projeto, você pode especificar uma etapa personalizada a ser executada quando o projeto é compilado.  
  
## <a name="uielement-list"></a>Lista UIElement  
 **Linha de comando**  
 O comando a ser executado pela etapa de compilação personalizada.  
  
 **Descrição**  
 Uma mensagem que será exibida quando a etapa de compilação personalizada for executada.  
  
 **Saídas**  
 O arquivo de saída gerado pela etapa de compilação personalizada. Essa configuração é necessária para que as compilações incrementais funcionem corretamente.  
  
 **Dependências adicionais**  
 Uma lista delimitada por ponto-e-vírgula de arquivos de entrada adicionais a ser usada para a etapa de compilação personalizada.  
  
 **Depois de execução e execução antes de**  
 Essas opções definem quando a etapa de compilação personalizada é executada no processo de compilação, em relação aos destinos listados. Os destinos mais comumente listados são BuildGenerateSources, BuildCompile e BuildLink, porque representam as etapas principais no processo de compilação. Outros destinos frequentemente listados são Midl, CLCompile e Link.  
  
 Tratar saída como conteúdo  
 Essa opção só é significativa para aplicativos da Windows Store ou do Windows Phone, que incluem todos os arquivos de conteúdo no pacote .appx.  
  
### <a name="to-specify-a-custom-build-step"></a>Para especificar uma etapa de compilação personalizada  
  
1.  Na barra de menus, escolha **Projeto**, **Propriedades**. Para obter mais informações, consulte [trabalhar com propriedades do projeto](../ide/working-with-project-properties.md).  
  
2.  No **páginas de propriedade** caixa de diálogo, navegue até o **propriedades de configuração**, **etapa de compilação personalizada**, **geral** página.  
  
3.  Modifique as configurações.  
  
## <a name="see-also"></a>Consulte também  
 [Páginas de propriedade](../ide/property-pages-visual-cpp.md)