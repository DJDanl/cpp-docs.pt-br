---
title: MSBuild (Visual C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
f1_keywords:
- MSBuild
dev_langs:
- C++
helpviewer_keywords:
- MSBuild
ms.assetid: 7a1be7ff-0312-4669-adf2-5f5bf507d560
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4bdb48c71c244adc2df5beef9668e12ee47f2b48
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45703944"
---
# <a name="msbuild-visual-c"></a>MSBuild (Visual C++)

Você pode usar o **MSBuild** ferramenta para criar um aplicativo do prompt de comando do Visual C++. O processo de compilação é controlado pelas informações em um arquivo de projeto (. vcxproj) que você pode criar e editar. O arquivo de projeto Especifica opções de compilação com base na compilação estágios, condições e eventos.

## <a name="in-this-section"></a>Nesta seção

|Termo|Definição|
|----------|----------------|
|[Visão geral do MSBuild (Visual C++)](../build/msbuild-visual-cpp-overview.md)|Descreve como o Visual C++ usa a **MSBuild** sistema.|
|[Alterações no sistema de build](../build/build-system-changes.md)|Discute algumas das diferenças entre o sistema de compilação atual e a versão anterior.|
|[Instruções passo a passo: usando MSBuild para criar um projeto do Visual C++](../build/walkthrough-using-msbuild-to-create-a-visual-cpp-project.md)|Demonstra como criar um projeto do Visual C++ usando **MSBuild**.|
|[Como usar eventos de build em projetos do MSBuild](../build/how-to-use-build-events-in-msbuild-projects.md)|Demonstra como especificar uma ação que ocorre em um estágio particuler na compilação: antes de inicia a compilação; antes do início da etapa de link; ou, após a conclusão da compilação.|
|[Como adicionar uma etapa de build personalizada a projetos MSBuild](../build/how-to-add-a-custom-build-step-to-msbuild-projects.md)|Demonstra como adicionar um estágio definidas pelo usuário para a sequência de compilação.|
|[Como adicionar ferramentas de build personalizadas a projetos MSBuild](../build/how-to-add-custom-build-tools-to-msbuild-projects.md)|Demonstra como associar uma ferramenta de compilação de um arquivo específico.|
|[Como integrar ferramentas personalizadas a propriedades de projeto](../build/how-to-integrate-custom-tools-into-the-project-properties.md)|Demonstra como adicionar opções para uma ferramenta personalizada para as propriedades do projeto.|
|[Como modificar a estrutura de destino e o conjunto de ferramentas da plataforma](../build/how-to-modify-the-target-framework-and-platform-toolset.md)|Demonstra como compilar um projeto para várias estruturas ou conjuntos de ferramentas.|

## <a name="see-also"></a>Consulte também

[Compilar código C/C++ na linha de comando](../build/building-on-the-command-line.md)