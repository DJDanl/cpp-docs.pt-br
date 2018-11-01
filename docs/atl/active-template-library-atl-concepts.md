---
title: Conceitos da Biblioteca de Modelo Ativa (ATL)
ms.date: 11/04/2016
helpviewer_keywords:
- ATL, about ATL
ms.assetid: a3960991-4d76-4da5-9568-3fa7fde53ff4
ms.openlocfilehash: 9b8c293bc92071509607e8496a5601d0c6ef2018
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50523728"
---
# <a name="active-template-library-atl-concepts"></a>Conceitos da Biblioteca de Modelo Ativa (ATL)

A biblioteca ATL (Active Template) é um conjunto de classes C++ baseadas em modelos que permitem que você crie objetos de modelo de objeto de componente (COM) de pequeno e rápido. Ele possui suporte especial para os principais recursos do COM, incluindo implementações fixas, interfaces duplas, interfaces de enumerador COM padrão, os pontos de conexão, interfaces destacáveis e controles ActiveX.

Se você fizer muita programação ATL, você desejará saber mais sobre os atributos, um novo recurso do Visual C++ .NET que foi projetado para simplificar a programação COM. Para obter mais informações, consulte [atribuído programação](../windows/attributed-programming-concepts.md).

## <a name="in-this-section"></a>Nesta seção

[Tutorial da ATL](../atl/active-template-library-atl-tutorial.md)<br/>
Orienta a criação de um controle e demonstra alguns conceitos básicos ATL no processo.

[Introdução ao COM e à ATL](../atl/introduction-to-com-and-atl.md)<br/>
Apresenta os conceitos principais por trás da COM Component Object Model (). Este artigo explica também brevemente o que é a ATL e quando usá-lo.

[Princípios básicos de objetos COM da ATL](../atl/fundamentals-of-atl-com-objects.md)<br/>
Discute o relacionamento entre várias classes ATL e como essas classes são implementadas.

[Interfaces duplas e a ATL](../atl/dual-interfaces-and-atl.md)<br/>
Descreve interfaces duplas de uma perspectiva ATL.

[Coleções e enumeradores da ATL](../atl/atl-collections-and-enumerators.md)<br/>
Descreve a implementação e a criação de coleções e enumeradores na ATL.

[Fundamentos do controle composto](../atl/atl-composite-control-fundamentals.md)<br/>
Fornece instruções passo a passo para a criação de um controle de composição. Um controle de composição é um tipo de controle ActiveX que pode conter outros controles ActiveX ou controles do Windows.

[Perguntas frequentes sobre contenção de controle da ATL](../atl/atl-control-containment-faq.md)<br/>
Abrange as perguntas fundamentais relacionadas à hospedagem de controles com ATL.

[Página de propriedades COM da ATL](../atl/atl-com-property-pages.md)<br/>
Mostra como especificar e implementar as páginas de propriedades de COM.

[Suporte da ATL para controles DHTML](../atl/atl-support-for-dhtml-controls.md)<br/>
Fornece instruções passo a passo para criar um controle DHTML.

[Pontos de conexão da ATL](../atl/atl-connection-points.md)<br/>
Explica o que são pontos de conexão e como ATL implementa-los.

[Manipulação de eventos e a ATL](../atl/event-handling-and-atl.md)<br/>
Descreve as etapas que você precisa tomar para lidar com eventos de COM usando do ATL [IDispEventImpl](../atl/reference/idispeventimpl-class.md) e [IDispEventSimpleImpl](../atl/reference/idispeventsimpleimpl-class.md) classes.

[ATL e o marshaler livre de threads](../atl/atl-and-the-free-threaded-marshaler.md)<br/>
Fornece detalhes sobre a opção do ATL Simple Object Wizard que permite que sua classe agregar o marshaler livre (FTM).

[Especificando o modelo de Threading do projeto](../atl/specifying-the-threading-model-for-a-project-atl.md)<br/>
Descreve as macros que estão disponíveis para controlar o desempenho de tempo de execução relacionado ao threading em seu projeto.

[Classes de módulo da ATL](../atl/atl-module-classes.md)<br/>
Discute as classes de módulo novo para o ATL 7.0. Classes de módulo implementam a funcionalidade básica necessária por ATL.

[Serviços da ATL](../atl/atl-services.md)<br/>
Aborda a série de eventos que ocorrem quando um serviço é implementado. Também fala sobre alguns dos conceitos relacionados ao desenvolvimento de um serviço.

[Classes de janela da ATL](../atl/atl-window-classes.md)<br/>
Descreve como criar, superclasse e as janelas de subclasse na ATL. As classes de janela ATL não são classes COM.

[Classes de coleção da ATL](../atl/atl-collection-classes.md)<br/>
Descreve como usar matrizes e mapas em ATL.

[O componente de registro ATL (registrador)](../atl/atl-registry-component-registrar.md)<br/>
Discute o ATL script sintaxe e parâmetros substituíveis. Ele também explica como configurar um link estático para o registrador.

[Programando com código de tempo de execução C e da ATL](../atl/programming-with-atl-and-c-run-time-code.md)<br/>
Aborda os benefícios da vinculação estática ou dinamicamente para a biblioteca de tempo de execução do C (CRT).

[Programando com CComBSTR](../atl/programming-with-ccombstr-atl.md)<br/>
Discute várias situações que exigem cuidado ao programar com `CComBSTR`.

[Referência de codificação](../atl/atl-encoding-reference.md)<br/>
Fornece funções e macros que oferecer suporte à codificação de uma variedade de padrões de Internet comuns como uuencode, hexadecimal e UTF8 no atlenc.

[Referência de utilitários](../atl/atl-utilities-reference.md)<br/>
Fornece código para manipular URLs e caminhos na forma de [CPathT](../atl/reference/cpatht-class.md) e [CUrl](../atl/reference/curl-class.md). Um pool de threads [CThreadPool](../atl/reference/cthreadpool-class.md), pode ser usado em seus próprios aplicativos. Esse código pode ser encontrado em atlpath e atlutil.

## <a name="related-sections"></a>Seções relacionadas

[Exemplos de ATL](../visual-cpp-samples.md)<br/>
Fornece descrições de links para os programas de exemplo do ATL.

[Criando um projeto ATL](../atl/reference/creating-an-atl-project.md)<br/>
Contém informações sobre o Assistente de projeto de ATL.

[Assistente de Controle da ATL](../atl/reference/atl-control-wizard.md)<br/>
Discute como adicionar classes.

[Programação atribuída](../windows/attributed-programming-concepts.md)<br/>
Fornece uma visão geral sobre como usar atributos para simplificar a programação COM mais de uma lista de links para tópicos mais detalhados.

[Visão geral de classes da ATL](../atl/atl-class-overview.md)<br/>
Fornece informações de referência e links para as classes ATL.

