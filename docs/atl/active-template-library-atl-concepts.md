---
title: "Conceitos da Biblioteca de Modelo Ativa (ATL) | Microsoft Docs"
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
  - "ATL, sobre ATL"
ms.assetid: a3960991-4d76-4da5-9568-3fa7fde53ff4
caps.latest.revision: 18
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Conceitos da Biblioteca de Modelo Ativa (ATL)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A biblioteca ativa \(ATL\) do modelo é um conjunto de classes modelo\- com base em C\+\+ que permitem que você criar objetos pequenos, rápidas do Component Object Model \(COM\).  Tem suporte especial para recursos chave COM, incluindo as implementações pré\-definidas, interfaces duais, interfaces padrão do enumerador de, COM pontos de conexão, interfaces de rasgo \- desligado, e controles ActiveX.  
  
 Se você fizer de programação de ATL, você desejará saber mais sobre atributos, um novo recurso no Visual C\+\+ .NET que é criado para simplificar a programação COM.  Para obter mais informações, consulte [programação atribuída](../windows/attributed-programming-concepts.md).  
  
## Nesta seção  
 [tutorial de ATL](../Topic/Active%20Template%20Library%20\(ATL\)%20Tutorial.md)  
 A através da criação de um controle e demonstra os fundamentos de qualquer ATL no processo.  
  
 [Introdução à e a ATL](../atl/introduction-to-com-and-atl.md)  
 Apresenta os conceitos chave do Component Object Model code\-behind \(COM\).  Este artigo também explica rapidamente o que é ATL e quando você deve usar o.  
  
 [fundamentos de objetos COM de ATL](../atl/fundamentals-of-atl-com-objects.md)  
 Descreve o relacionamento entre várias classes de ATL e como essas classes são implementadas.  
  
 [Interfaces duais e ATL](../atl/dual-interfaces-and-atl.md)  
 Descreve interfaces duais de uma perspectiva de ATL.  
  
 [coleções e enumeradores de ATL](../atl/atl-collections-and-enumerators.md)  
 Descreve a implementação e a criação das coleções e os enumeradores em ATL.  
  
 [Fundamentos controle composto](../Topic/ATL%20Composite%20Control%20Fundamentals.md)  
 Fornece instruções passo a passo para criar um controle composto.  Um controle composto é um tipo de controle ActiveX que pode conter outros controles ActiveX ou controles do windows.  
  
 [Retenção Perguntas Freqüentes de controle de ATL](../atl/atl-control-containment-faq.md)  
 Aborda as perguntas relacionadas fundamentais para hospedar controles com ATL.  
  
 [páginas de propriedades de ATL COM](../atl/atl-com-property-pages.md)  
 Mostra como especificar e implementar páginas de propriedades COM.  
  
 [Suporte de ATL para controles HTML dinâmico \(DHTML\)](../atl/atl-support-for-dhtml-controls.md)  
 Fornece instruções passo a passo para criar um controle DHTML.  
  
 [pontos de conexão de ATL](../atl/atl-connection-points.md)  
 Explica o que os pontos de conexão são e como ATL os implementa.  
  
 [Tratamento de evento e ATL](../Topic/Event%20Handling%20and%20ATL.md)  
 Descreve as etapas você precisa fazer para manipular eventos COM usando classes de [IDispEventImpl](../atl/reference/idispeventimpl-class.md) e de [IDispEventSimpleImpl](../atl/reference/idispeventsimpleimpl-class.md) de ATL.  
  
 [ATL e o Marshaler de livre](../Topic/ATL%20and%20the%20Free%20Threaded%20Marshaler.md)  
 Fornece detalhes sobre a opção do assistente simples de objeto de ATL que permite que sua classe agrega o marshaler de livre \(FTM\).  
  
 [Especificando o modelo de segmentação do projeto](../atl/specifying-the-threading-model-for-a-project-atl.md)  
 Descreve as macros disponíveis para controlar o desempenho de tempo de execução relativo ao threading em seu projeto.  
  
 [Classes de módulo de ATL](../Topic/ATL%20Module%20Classes.md)  
 Discute as classes de módulo para novos ATL 7,0.  As classes de módulo implementa a funcionalidade básica necessária por ATL.  
  
 [serviços de ATL](../atl/atl-services.md)  
 Cobre a série de eventos que ocorrem quando um serviço é implementado.  Também falando sobre alguns conceitos relacionados a desenvolver um serviço.  
  
 [Classes da janela de ATL](../Topic/ATL%20Window%20Classes.md)  
 Descreve como criar, superclass, e janelas de subclasse em ATL.  As classes da janela de ATL não são classes COM.  
  
 [Classes de coleção de ATL](../atl/atl-collection-classes.md)  
 Descreve como usar matrizes e mapas em ATL.  
  
 [O componente de Registro de ATL \(escrivão\)](../atl/atl-registry-component-registrar.md)  
 Descreve a sintaxe de script de ATL e parâmetros substituíveis.  Também explica como configurar um link para o escrivão estático.  
  
 [Programação com código de tempo de execução de ATL e de C](../atl/programming-with-atl-and-c-run-time-code.md)  
 Discute os benefícios de vincular estaticamente ou dinamicamente à biblioteca em tempo de execução de C \(CRT\).  
  
 [programação com CComBSTR](../atl/programming-with-ccombstr-atl.md)  
 Descreve várias situações que exigem cuidados ao programar com `CComBSTR`.  
  
 [Referência de codificação](../Topic/ATL%20Encoding%20Reference.md)  
 Fornece as funções e macros que oferecem suporte a codificação em um intervalo de padrões da Internet comuns como o uuencode, hexadecimal, e UTF8 no atlenc.h.  
  
 [Referência de utilitários](../Topic/ATL%20Utilities%20Reference.md)  
 Fornece código para caminhos e URL de tratamento na forma de [CPathT](../atl/reference/cpatht-class.md) e de [Som tipo wave](../atl/reference/curl-class.md).  Um pool de segmento, [CThreadPool](../Topic/CThreadPool%20Class.md), pode ser usado em seus próprios aplicativos.  Este código pode ser encontrado em atlpath.h e em atlutil.h.  
  
## Seções relacionadas  
 [exemplos de ATL](../top/visual-cpp-samples.md)  
 Fornece descrições de e links para compilar programas de exemplo ATL.  
  
 [criando um projeto de ATL](../atl/reference/creating-an-atl-project.md)  
 Contém informações sobre o assistente de projeto de ATL.  
  
 [Assistente de controle de ATL](../atl/reference/atl-control-wizard.md)  
 Descreve como adicionar classes.  
  
 [programação atribuída](../windows/attributed-programming-concepts.md)  
 Fornece uma visão geral sobre como usar atributos para simplificar COM que programa mais uma lista de links para os tópicos mais detalhados.  
  
 [Visão geral da classe de ATL](../atl/atl-class-overview.md)  
 Fornece informações de referência e links para classes de ATL.