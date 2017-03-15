---
title: "No&#231;&#245;es b&#225;sicas de etapas e eventos de compila&#231;&#227;o personalizados | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "eventos de compilação [C++], ordem de eventos e etapas de compilação"
  - "etapas de compilação [C++]"
  - "etapas de compilação [C++], compilar eventos"
  - "compilações [C++], etapas de compilação personalizada"
  - "compilações [C++], eventos"
  - "etapas de compilação personalizada [C++]"
  - "etapas de compilação personalizada [C++], personalizando compilações"
  - "eventos [C++], compilar"
ms.assetid: beb2f017-3e9f-4b2c-9b57-2572fd2628e4
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# No&#231;&#245;es b&#225;sicas de etapas e eventos de compila&#231;&#227;o personalizados
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Dentro do ambiente de desenvolvimento do Visual C\+\+, há três formas básicas de personalização do processo de compilação:  
  
 **Etapas de criação personalizado**  
 Uma etapa de criação personalizado é uma regra de compilação associada a um projeto.  Uma etapa de criação personalizado pode especificar uma linha de comando para executar, qualquer entrada ou arquivos de saída adicionais, e uma mensagem a ser exibida.  Para obter mais informações, consulte [Como adicionar uma etapa de build personalizada a projetos MSBuild](../Topic/How%20to:%20Add%20a%20Custom%20Build%20Step%20to%20MSBuild%20Projects.md).  
  
 **Ferramentas personalizadas de compilação**  
 Uma ferramenta de criação personalizado é uma regra de compilação associada a um ou mais arquivos.  Uma etapa de criação personalizado pode passar arquivos de entrada a uma ferramenta de criação personalizado, que leva a um ou mais arquivos de saída.  Por exemplo, os arquivos de ajuda em um aplicativo MFC são compilados com uma ferramenta de criação personalizado.  Para obter mais informações, consulte [Como adicionar ferramentas de compilação personalizadas a projetos MSBuild](../build/how-to-add-custom-build-tools-to-msbuild-projects.md) e [Especificando ferramentas de compilação personalizadas](../ide/specifying-custom-build-tools.md).  
  
 **Compilar Eventos**  
 Os eventos de compilação permitem personalizar a criação de um projeto.  Há três eventos de compilação: *pré\-compilação*, *pré\-vinculação*, e *pós\-compilação*.  Um evento de compilação lhe permite especificar uma ação ocorrer em um momento específico no processo de criação.  Por exemplo, você pode usar um evento de compilação para registrar um arquivo com **regsvr32.exe** depois que o projeto é compilado.  Para obter mais informações, consulte [Especificando eventos de compilação](../ide/specifying-build-events.md).  
  
 [Solucionando problemas de personalizações da compilação](../ide/troubleshooting-build-customizations.md) pode ajudar a assegurar que a criação personalizado avançar para o e criar os eventos são executados como esperado.  
  
 O formato de saída de uma etapa de criação ou de um evento personalizado de compilação também pode aumentar a usabilidade de ferramenta.  Para obter mais informações, consulte [Formatando a saída de uma etapa de compilação personalizada ou evento de compilação](../ide/formatting-the-output-of-a-custom-build-step-or-build-event.md).  
  
 Eventos de compilação e execução das etapas de criação personalizado na seguinte ordem junto com outras etapas de criação:  
  
1.  Evento da construção  
  
2.  Ferramentas personalizadas de criação em arquivos individuais  
  
3.  MIDL  
  
4.  Compilador de recursos  
  
5.  O compilador C\/C\+\+  
  
6.  Evento do link  
  
7.  O vinculador ou bibliotecário \(conforme apropriado\)  
  
8.  Ferramenta manifesta  
  
9. BSCMake  
  
10. Etapa personalizado de compilação do projeto  
  
11. Evento de pós\-compilação  
  
 `custom build step on the project` e `post-build event` são executadas em sequência após o outro fim de processos de compilação.  
  
## Consulte também  
 [Compilando projetos do C\+\+ no Visual Studio](../ide/building-cpp-projects-in-visual-studio.md)   
 [Macros comuns para compilar comandos e propriedades](../ide/common-macros-for-build-commands-and-properties.md)   
 [Tool Build Order Dialog Box](http://msdn.microsoft.com/pt-br/6204c5b1-7ce9-4948-9ff6-0268642ee14c)