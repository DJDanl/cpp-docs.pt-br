---
title: "Noções básicas sobre etapas de compilação personalizada e eventos de Build | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9abb7ff0b9a39656999e7a53b476056f7a5b1558
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="understanding-custom-build-steps-and-build-events"></a>Noções básicas de etapas e eventos de build personalizados
De dentro do ambiente de desenvolvimento do Visual C++, há três formas básicas para personalizar o processo de compilação:  
  
 **Etapas de compilação personalizada**  
 Uma etapa de compilação personalizada é uma regra de compilação associada a um projeto. Uma etapa de compilação personalizada pode especificar uma linha de comando a ser executado, nenhuma entrada adicional ou arquivos de saída e uma mensagem a ser exibida. Para obter mais informações, consulte [como: adicionar uma etapa de compilação personalizada a projetos MSBuild](../build/how-to-add-a-custom-build-step-to-msbuild-projects.md).  
  
 **Ferramentas de compilação personalizada**  
 Uma ferramenta de compilação personalizada é uma regra de compilação associada a um ou mais arquivos. Uma etapa de compilação personalizada pode transmitir arquivos de entrada para uma ferramenta de compilação personalizada, o que resulta em um ou mais arquivos de saída. Por exemplo, os arquivos de Ajuda em um aplicativo MFC são criados com uma ferramenta de compilação personalizada. Para obter mais informações, consulte [como: adicionar ferramentas de compilação de personalizada a projetos MSBuild](../build/how-to-add-custom-build-tools-to-msbuild-projects.md) e [especificando ferramentas de compilação personalizada](../ide/specifying-custom-build-tools.md).  
  
 **Eventos de Build**  
 Eventos de build permitem que você personalize a compilação do projeto. Há três eventos de compilação: *pré-compilação*, *pré-vínculo*, e *pós-compilação*. Um evento de compilação permite que você especifique uma ação para ocorrer em um momento específico no processo de compilação. Por exemplo, você pode usar um evento de compilação para registrar um arquivo com **regsvr32.exe** após o projeto de compilação. Para obter mais informações, consulte [especificando eventos de Build](../ide/specifying-build-events.md).  
  
 [Solucionando problemas de personalizações de compilação](../ide/troubleshooting-build-customizations.md) pode ajudar a garantir que as etapas de compilação personalizada e executados conforme esperado de eventos de build.  
  
 Etapa de compilação do formato de saída de um personalizado ou evento de compilação também pode aprimorar a usabilidade da ferramenta. Para obter mais informações, consulte [Formatando a saída de uma etapa de build ou um evento de build personalizado](../ide/formatting-the-output-of-a-custom-build-step-or-build-event.md).  
  
 Eventos de build e personalizada de compilação etapas executadas na ordem a seguir, junto com as outras etapas de compilação:  
  
1.  Evento de pré-compilação  
  
2.  As ferramentas em arquivos individuais de compilação personalizada  
  
3.  MIDL  
  
4.  Compilador de recurso  
  
5.  O compilador do C/C++  
  
6.  evento Pré-link  
  
7.  Vinculador ou bibliotecário (conforme apropriado)  
  
8.  Ferramenta de manifesto  
  
9. BSCMake  
  
10. Etapa de compilação personalizada no projeto  
  
11. Evento de pós-compilação  
  
 O `custom build step on the project` e um `post-build event` executar sequencialmente depois que todos os outros compilar processa concluir.  
  
## <a name="see-also"></a>Consulte também  
 [Compilando projetos do C++ no Visual Studio](../ide/building-cpp-projects-in-visual-studio.md)   
 [Macros comuns para compilar comandos e propriedades](../ide/common-macros-for-build-commands-and-properties.md)   
 [Caixa de diálogo de ordem de compilação de ferramenta](http://msdn.microsoft.com/en-us/6204c5b1-7ce9-4948-9ff6-0268642ee14c)