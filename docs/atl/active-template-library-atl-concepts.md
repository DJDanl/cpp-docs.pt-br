---
title: Conceitos do modelo ativo Library (ATL) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- ATL, about ATL
ms.assetid: a3960991-4d76-4da5-9568-3fa7fde53ff4
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c7cf2568005049cfabd9178ea4c8732a5a985954
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="active-template-library-atl-concepts"></a>Conceitos da Biblioteca de Modelo Ativa (ATL)
A biblioteca de modelo ativa (ATL) é um conjunto de classes C++ com base em modelo que lhe permitem criar objetos de modelo de objeto de componente (COM) pequeno e rápido. Ele tem suporte especial para os principais recursos de COM, incluindo as implementações de estoque, duas interfaces, interfaces de enumerador COM padrão, pontos de conexão, destacável interfaces e controles ActiveX.  
  
 Se você fizer muita programação ATL, você desejará saber mais sobre os atributos, um novo recurso do Visual C++ .NET que foi projetado para simplificar a programação COM. Para obter mais informações, consulte [atribuído programação](../windows/attributed-programming-concepts.md).  
  
## <a name="in-this-section"></a>Nesta seção  
 [Tutorial da ATL](../atl/active-template-library-atl-tutorial.md)  
 Leva você através da criação de um controle e demonstra alguns conceitos básicos ATL do processo.  
  
 [Introdução ao COM e à ATL](../atl/introduction-to-com-and-atl.md)  
 Apresenta os principais conceitos por trás do modelo COM (Component Object). Este artigo também explica ATL é e quando usá-lo.  
  
 [Princípios básicos de objetos COM da ATL](../atl/fundamentals-of-atl-com-objects.md)  
 Discute o relacionamento entre várias classes ATL e como essas classes são implementadas.  
  
 [Interfaces duplas e a ATL](../atl/dual-interfaces-and-atl.md)  
 Descreve duas interfaces de uma perspectiva ATL.  
  
 [Coleções e enumeradores da ATL](../atl/atl-collections-and-enumerators.md)  
 Descreve a implementação e a criação de coleções e enumeradores em ATL.  
  
 [Fundamentos do controle composto](../atl/atl-composite-control-fundamentals.md)  
 Fornece instruções passo a passo para criar um controle composto. Um controle composto é um tipo de controle ActiveX que pode conter outros controles ActiveX ou controles do Windows.  
  
 [Perguntas frequentes sobre contenção de controle da ATL](../atl/atl-control-containment-faq.md)  
 Abrange as perguntas fundamentais relacionadas à hospedagem de controles com ATL.  
  
 [Página de propriedades COM da ATL](../atl/atl-com-property-pages.md)  
 Mostra como especificar e implemente COM páginas de propriedade.  
  
 [Suporte da ATL para controles DHTML](../atl/atl-support-for-dhtml-controls.md)  
 Fornece instruções passo a passo para criar um controle DHTML.  
  
 [Pontos de conexão da ATL](../atl/atl-connection-points.md)  
 Explica o que são pontos de conexão e como o ATL implementá-las.  
  
 [Manipulação de eventos e a ATL](../atl/event-handling-and-atl.md)  
 Descreve as etapas que você precisa tomar para lidar com eventos COM uso da ATL [IDispEventImpl](../atl/reference/idispeventimpl-class.md) e [IDispEventSimpleImpl](../atl/reference/idispeventsimpleimpl-class.md) classes.  
  
 [ATL e o marshaler livre de threads](../atl/atl-and-the-free-threaded-marshaler.md)  
 Fornece detalhes sobre a opção do ATL simples objeto Assistente que permite que a classe de agregação marshaler livre de threads (FTM).  
  
 [Especificando o modelo de Threading do projeto](../atl/specifying-the-threading-model-for-a-project-atl.md)  
 Descreve as macros que estão disponíveis para controlar o desempenho de tempo de execução relacionado a threading no seu projeto.  
  
 [Classes de módulo da ATL](../atl/atl-module-classes.md)  
 Descreve as classes de módulo novo para ATL 7.0. Classes de módulo implementam a funcionalidade básica necessária por ATL.  
  
 [Serviços da ATL](../atl/atl-services.md)  
 Abrange a série de eventos que ocorrem quando um serviço é implementado. Também fala sobre alguns dos conceitos relacionados ao desenvolvimento de um serviço.  
  
 [Classes de janela da ATL](../atl/atl-window-classes.md)  
 Descreve como criar, superclasse e windows subclasse em ATL. As classes de janela ATL não são classes COM.  
  
 [Classes de coleção da ATL](../atl/atl-collection-classes.md)  
 Descreve como usar matrizes e mapeia em ATL.  
  
 [O componente de registro ATL (Registrar)](../atl/atl-registry-component-registrar.md)  
 Discute ATL script sintaxe e parâmetros substituíveis. Ele também explica como configurar um link estático para o registrador.  
  
 [Programando com código de tempo de execução C e da ATL](../atl/programming-with-atl-and-c-run-time-code.md)  
 Descreve os benefícios de vinculação estática ou dinamicamente para a biblioteca de tempo de execução do C (CRT).  
  
 [Programando com o CComBSTR](../atl/programming-with-ccombstr-atl.md)  
 Discute várias situações que exigem cuidado ao programar com `CComBSTR`.  
  
 [Referência de codificação](../atl/atl-encoding-reference.md)  
 Fornece funções e macros que oferecem suporte à codificação em uma variedade de padrões de Internet comuns como uuencode, hexadecimal e UTF8 em atlenc.h.  
  
 [Referência de utilitários](../atl/atl-utilities-reference.md)  
 Fornece o código para manipular as URLs e caminhos na forma de [CPathT](../atl/reference/cpatht-class.md) e [CUrl](../atl/reference/curl-class.md). Um pool de threads, [CThreadPool](../atl/reference/cthreadpool-class.md), podem ser usados em seus próprios aplicativos. Esse código pode ser encontrado em atlpath.h e atlutil.h.  
  
## <a name="related-sections"></a>Seções relacionadas  
 [Amostras ATL](../visual-cpp-samples.md)  
 Fornece descrições de links para os programas de exemplo do ATL.  
  
 [Criando um projeto ATL](../atl/reference/creating-an-atl-project.md)  
 Contém informações sobre o Assistente de projeto de ATL.  
  
 [Assistente de Controle da ATL](../atl/reference/atl-control-wizard.md)  
 Descreve como adicionar classes.  
  
 [Programação atribuída](../windows/attributed-programming-concepts.md)  
 Fornece uma visão geral sobre como usar atributos para simplificar a programação COM mais de uma lista de links para tópicos mais detalhados.  
  
 [Visão geral de classes da ATL](../atl/atl-class-overview.md)  
 Fornece informações de referência e links para as classes da ATL.

