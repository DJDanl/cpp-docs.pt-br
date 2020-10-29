---
title: 'Página de Propriedades de Etapa de Build Personalizado: geral'
description: Este artigo descreve as propriedades disponíveis na página etapa de compilação personalizada na caixa de diálogo páginas de propriedades.
ms.date: 10/27/2020
f1_keywords:
- VC.Project.VCCustomBuildStep.AdditionalInputs
- VC.Project.VCCustomBuildStep.CustomBuildAfterTargets
- VC.Project.VCCustomBuildStep.CustomBuildBeforeTargets
- VC.Project.VCCustomBuildStep.Outputs
- VC.Project.VCCustomBuildStep.Message
- VC.Project.VCCustomBuildStep.Command
helpviewer_keywords:
- project properties, custom build step
- custom build step (general)
ms.assetid: bd319741-0491-46c4-a428-7c61b4b46a02
ms.openlocfilehash: 53f2deef931821981b3301f44ba37660975fb811
ms.sourcegitcommit: 9c801a43ee0d4d84956b03fd387716c818705e0d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/28/2020
ms.locfileid: "92907577"
---
# <a name="custom-build-step-property-page-general"></a>Página de Propriedades de Etapa de Build Personalizado: geral

Para cada combinação de configuração de projeto e plataforma de destino em seu projeto, você pode especificar uma etapa personalizada a ser executada quando o projeto for compilado.

Para obter a versão do Linux desta página, confira [Propriedades de Etapa de Build Personalizada (Linux C++)](../../linux/prop-pages/custom-build-step-linux.md).

## <a name="general-page"></a>Página Geral

- **Linha de comando**

   O comando a ser executado pela etapa de compilação personalizada.

- **Descrição**

   Uma mensagem que será exibida quando a etapa de compilação personalizada for executada.

- **Saídas**

   O arquivo de saída gerado pela etapa de compilação personalizada. Essa configuração é necessária para que as compilações incrementais funcionem corretamente.

- **Dependências adicionais**

   Uma lista delimitada por ponto-e-vírgula de arquivos de entrada adicionais a ser usada para a etapa de compilação personalizada.

- **Executar depois e executar antes**

   Essas opções definem quando a etapa de compilação personalizada é executada no processo de compilação, em relação aos destinos listados. Os destinos listados com mais frequência são `BuildGenerateSources` , `BuildCompile` e `BuildLink` , porque representam as principais etapas do processo de compilação. Outros destinos listados com frequência são `Midl` , `CLCompile` e `Link` .

- **Tratar saída como conteúdo**

   Essa opção só é significativa para aplicativos Plataforma Universal do Windows ou Windows Phone, que incluem todos os arquivos de conteúdo no *`.appx`* pacote.

### <a name="to-specify-a-custom-build-step"></a>Para especificar uma etapa de compilação personalizada

1. Na barra de menus, escolha **Project**  >  **Propriedades** do projeto. Para obter mais informações, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Na caixa de diálogo **páginas de propriedades** , navegue até a página **configuração**  >  geral da **etapa de compilação personalizada**  >  **General** .

1. Modifique as configurações.

## <a name="see-also"></a>Confira também

[Referência de página de propriedades do projeto C++](property-pages-visual-cpp.md)
