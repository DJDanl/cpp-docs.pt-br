---
title: Noções básicas de etapas e eventos de compilação personalizados
ms.date: 08/29/2019
helpviewer_keywords:
- builds [C++], events
- custom build steps [C++], customizing builds
- events [C++], build
- custom build steps [C++]
- build steps [C++]
- build events [C++], order of events and build steps
- build steps [C++], build events
- builds [C++], custom build steps
ms.assetid: beb2f017-3e9f-4b2c-9b57-2572fd2628e4
ms.openlocfilehash: 386a12213814e3825ece8a81d61ac251c6793f43
ms.sourcegitcommit: e10a5feea193c249ddc5a6faba48e7c6d8784e73
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/30/2019
ms.locfileid: "70177317"
---
# <a name="understanding-custom-build-steps-and-build-events"></a>Noções básicas de etapas e eventos de compilação personalizados

No ambiente de desenvolvimento do Visual C++, há três formas básicas de personalizar o processo de build:

- **Etapas de Build Personalizadas**

   Uma etapa de build personalizada é uma regra de build associada a um projeto. Uma etapa de build personalizada pode especificar uma linha de comando a ser executada, arquivos adicionais de entrada ou de saída e uma mensagem a ser exibida. Para obter mais informações, confira [Como adicionar uma etapa de build personalizada a projetos do MSBuild](how-to-add-a-custom-build-step-to-msbuild-projects.md).

- **Ferramentas de Build Personalizadas**

   Uma ferramenta de build personalizada é uma regra de build associada a um ou mais arquivos. Uma etapa de build personalizada pode passar arquivos de entrada para uma ferramenta de build personalizada, o que resulta em um ou mais arquivos de saída. Por exemplo, os arquivos de Ajuda em um aplicativo MFC são criados com uma ferramenta de build personalizada. Para obter mais informações, confira [Como adicionar ferramentas de build personalizadas a projetos do MSBuild](how-to-add-custom-build-tools-to-msbuild-projects.md) e [Especificando ferramentas de build personalizadas](specifying-custom-build-tools.md).

- **Eventos de compilação**

   Os eventos de build permitem que você personalize o build de um projeto. Há três eventos de build: *pré-build*, *pré-vínculo* e *pós-build*. Um evento de build permite que você especifique uma ação que ocorrerá em um momento específico no processo de build. Por exemplo, você pode usar um evento de build para registrar um arquivo em **regsvr32.exe** após a conclusão do projeto de build. Para obter mais informações, confira [Especificando eventos de build](specifying-build-events.md).

O tópico [Solução de problemas de personalizações de build](troubleshooting-build-customizations.md) pode ajudá-lo a garantir que os eventos e as etapas de build personalizadas sejam executados conforme esperado.

O formato de saída de um evento ou de uma etapa de build personalizada também pode aprimorar a usabilidade da ferramenta. Para obter mais informações, consulte [Formatando a saída de uma etapa de build ou um evento de build personalizado](formatting-the-output-of-a-custom-build-step-or-build-event.md).

Para cada projeto em uma solução, os eventos de compilação e as etapas de compilação personalizadas são executadas na seguinte ordem, juntamente com outras etapas de compilação:

1. Evento Pré-Build

2. Ferramentas de build personalizadas em arquivos individuais

3. MIDL

4. Compilador de recurso

5. O compilador C/C++

6. evento Pré-link

7. Vinculador ou bibliotecário (conforme apropriado)

8. Ferramenta de Manifesto

9. BSCMake

10. Etapa de build personalizada no projeto

11. Evento Pós-Build

O `custom build step on the project` e um `post-build event` são executados sequencialmente após a conclusão de todos os outros processos de build.

## <a name="in-this-section"></a>Nesta seção

[Especificação de ferramentas de build personalizadas](specifying-custom-build-tools.md)<br/>
[Especificação de eventos de build](specifying-build-events.md)<br/>
[Solução de problemas de personalizações do build](troubleshooting-build-customizations.md)<br/>
[Formatação da saída de uma etapa de compilação personalizada ou evento de compilação](formatting-the-output-of-a-custom-build-step-or-build-event.md)

## <a name="see-also"></a>Confira também

[Projetos do Visual Studio – C++](creating-and-managing-visual-cpp-projects.md)<br>
[Macros comuns para comandos e propriedades de build](reference/common-macros-for-build-commands-and-properties.md)
