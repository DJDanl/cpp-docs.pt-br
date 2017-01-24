---
title: "Pontos de conex&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "IConnectionPoint"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CCmdTarget, e pontos de conexão"
  - "COM, pontos de conexão"
  - "pontos de conexão [C++]"
  - "conexões, pontos de conexão"
  - "Interface IConnectionPoint"
  - "interfaces, IConnectionPoint"
  - "MFC [C++], Suporte COM"
  - "MFC COM, pontos de conexão"
  - "Pontos de conexão OLE COM"
  - "coletores, pontos de conexão"
ms.assetid: bc9fd7c7-8df6-4752-ac8c-0b177442c88d
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Pontos de conex&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo explica como implementar os pontos de conexão \(anteriormente conhecido como pontos de conexão OLE\) que usam as classes `CCmdTarget` e `CConnectionPoint`MFC.  
  
 No passado, o Component Object Model \(COM\) definiu um mecanismo geral \(**IUnknown::QueryInterface**\) que permite que os objetos implementassem e expõe a funcionalidade em interfaces.  No entanto, um mecanismo correspondente que permite que os objetos expõe o recurso chamar interfaces específicas não foi definido.  Ou seja, COM definido como os ponteiros de entrada para objetos \(ponteiros às interfaces desse objeto\) foram manipulados, mas não tiver um modelo explícito para interfaces de saída \(ponteiros as propriedades do objeto com as interfaces de outros objetos\).  COM agora tem um modelo, pontos de conexão chamada, que da suporte a essa funcionalidade.  
  
 Uma conexão tem duas partes: o objeto que chama a interface, a chamada a origem, e do objeto que implementa a interface, chamadas o coletor.  Um ponto de conexão é a interface expostos pela origem.  Expõe um ponto de conexão, uma origem permite que os coletores estabeleçam conexões para se a origem \(\).  Por meio do mecanismo do ponto de conexão \(a interface de **IConnectionPoint** \), um ponteiro para a interface de coletor é passado para o objeto de origem.  Esse ponteiro fornece a origem com acesso à implementação do coletor de um conjunto de funções de membro.  Por exemplo, para acionar um evento implementado pelo coletor, a origem pode chamar o método de implementação do coletor.  A figura a seguir demonstra o ponto de conexão apenas descrito.  
  
 ![Ponto de conexão implementado](../mfc/media/vc37lh1.png "vc37LH1")  
Um ponto de conexão implementado  
  
 MFC O implementa esse modelo nas classes de [CConnectionPoint](../Topic/CConnectionPoint%20Class.md) e de [CCmdTarget](../Topic/CCmdTarget%20Class.md) .  As classes derivadas de **CConnectionPoint** implementam a interface de **IConnectionPoint** , usada para expor pontos de conexão para outros objetos.  As classes derivadas de `CCmdTarget` implementam a interface de **IConnectionPointContainer** , que pode enumerar todos os pontos de conexão disponíveis de um objeto ou encontrar um ponto de conexão específico.  
  
 Para cada ponto de conexão implementado em sua classe, você deve declarar uma parte da conexão que implementa o ponto de conexão.  Se você implementa um ou mais pontos de conexão, você deve declarar também um único mapa de conexão em sua classe.  Um mapa de conexão é uma tabela de pontos de conexão com suporte do controle ActiveX.  
  
 Os exemplos a seguir demonstram um mapa simples de conexão e um ponto de conexão.  O primeiro exemplo a seguir declara o mapa e o ponto de conexão; o segundo exemplo implementa o mapa e o ponto.  Observe que `CMyClass` deve ser `CCmdTarget`\- classe derivada.  No primeiro exemplo, o código é inserido na declaração de classe, na seção de **protected** :  
  
 [!code-cpp[NVC_MFCConnectionPoints#1](../mfc/codesnippet/CPP/connection-points_1.h)]  
  
 `BEGIN_CONNECTION_PART` e macros do **END\_CONNECTION\_PART** declaram uma classe inserido, `XSampleConnPt` \(derivado de `CConnectionPoint`\), que implementa esse ponto de conexão específico.  Se você quiser substituir qualquer função de membro de `CConnectionPoint` ou para adicionar funções de membro de conta própria, declarar\-los entre esses dois macros.  Por exemplo, a macro de `CONNECTION_IID` substitui a função de membro de `CConnectionPoint::GetIID` quando colocada entre esses dois macros.  
  
 No segundo exemplo, o código é inserido no arquivo de implementação de controle \(arquivo .cpp\).  Esse código implementa o mapa de conexão, que inclui o ponto de conexão, `SampleConnPt`:  
  
 [!code-cpp[NVC_MFCConnectionPoints#2](../mfc/codesnippet/CPP/connection-points_2.cpp)]  
  
 Se a classe tiver mais de um ponto de conexão, insira macros adicionais de `CONNECTION_PART` entre `BEGIN_CONNECTION_MAP` e macros do `END_CONNECTION_MAP` .  
  
 Por fim, adicione uma chamada a `EnableConnections` no construtor da classe.  Por exemplo:  
  
 [!code-cpp[NVC_MFCConnectionPoints#3](../mfc/codesnippet/CPP/connection-points_3.cpp)]  
  
 Uma vez que esse código foi inserido, o `CCmdTarget`\- a classe derivada expõe um ponto de conexão para a interface de **ISampleSink** .  A figura a seguir ilustra esse exemplo.  
  
 ![MFC de implementação de ponto de conexão](../mfc/media/vc37lh2.png "vc37LH2")  
Um ponto de conexão implementado com MFC  
  
 Em geral, os pontos de conexão oferecem suporte ao “multicasting” — a capacidade de transmitir a vários coletores conectados à mesma interface.  O seguinte fragmento de exemplo demonstra como seletiva iterar através de cada coletor em um ponto de conexão:  
  
 [!code-cpp[NVC_MFCConnectionPoints#4](../mfc/codesnippet/CPP/connection-points_4.cpp)]  
  
 Este exemplo recupera o conjunto atual de conexões no ponto de conexão de `SampleConnPt` com uma chamada a `CConnectionPoint::GetConnections`.  Em itera através de conexões e chama **ISampleSink::SinkFunc** em cada conexão ativa.  
  
## Consulte também  
 [MFC COM](../mfc/mfc-com.md)