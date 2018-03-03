---
title: "Pontos de Conexão | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- IConnectionPoint
dev_langs:
- C++
helpviewer_keywords:
- IConnectionPoint interface
- connections, connection points
- OLE COM connection points
- MFC COM, connection points
- COM, connection points
- interfaces, IConnectionPoint
- MFC, COM support
- connection points [MFC]
- CCmdTarget class [MFC], and connection points
- sinks, connection points
ms.assetid: bc9fd7c7-8df6-4752-ac8c-0b177442c88d
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0d8bbb131aa5d4ce1b12cba84c3928b80a8b2a7e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="connection-points"></a>Pontos de conexão
Este artigo explica como implementar pontos de conexão (anteriormente conhecidos como pontos de conexão OLE) usando as classes MFC `CCmdTarget` e `CConnectionPoint`.  
  
 No passado, o modelo de objeto de componente (COM) definido um mecanismo geral (**IUnknown:: QueryInterface**) que permitiu objetos implementar e expor a funcionalidade em interfaces. No entanto, um mecanismo correspondente que objetos expor sua capacidade para chamar interfaces específicas de permissão não foi definido. Ou seja, COM definido como entrados ponteiros para objetos foram manipulados (ponteiros para interfaces do objeto), mas ela não tinha um modelo explícito para interfaces de saída (o objeto contém as interfaces de outros objetos de ponteiros). COM agora tem um modelo, chamado de pontos de conexão, que oferece suporte a essa funcionalidade.  
  
 Uma conexão tem duas partes: o objeto chamar a interface, chamada de origem e o objeto que implementa a interface, chamado de coletor. Um ponto de conexão é a interface exposta pela origem. Ao expor um ponto de conexão, uma fonte permite coletores estabelecer conexões com o próprio (a origem). Por meio de conexão do ponto de mecanismo (o **IConnectionPoint** interface), um ponteiro para a interface de coletor é passado para o objeto de origem. Este ponteiro fornece a origem com acesso à implementação do coletor de um conjunto de funções de membro. Por exemplo, para disparar um evento implementado pelo coletor, a origem pode chamar o método apropriado de implementação do coletor. A figura a seguir demonstra a conexão ponto que acabamos de descrever.  
  
 ![Implementado o ponto de conexão](../mfc/media/vc37lh1.gif "vc37lh1")  
Um ponto de Conexão implementado  
  
 MFC implementa esse modelo no [CConnectionPoint](../mfc/reference/cconnectionpoint-class.md) e [CCmdTarget](../mfc/reference/ccmdtarget-class.md) classes. Classes derivadas de **CConnectionPoint** implementar o **IConnectionPoint** interface, usado para expor pontos de conexão a outros objetos. Classes derivadas de `CCmdTarget` implementar o **IConnectionPointContainer** interface, que pode enumerar todos os pontos de conexão disponíveis de um objeto ou localizar um ponto de conexão específico.  
  
 Para cada ponto de conexão implementado em sua classe, você deve declarar uma parte de conexão que implementa o ponto de conexão. Se você implementar um ou mais pontos de conexão, você deve declarar também um mapa de conexão única em sua classe. Um mapa de conexão é uma tabela de pontos de conexão com suporte pelo controle ActiveX.  
  
 Os exemplos a seguir demonstram um mapa de conexão simples e um ponto de uma conexão. O primeiro exemplo declara o mapa de conexão e o ponto; o segundo exemplo implementa o mapa e o ponto. Observe que `CMyClass` deve ser um `CCmdTarget`-classe derivada. No primeiro exemplo, o código é inserido na declaração da classe, sob o **protegido** seção:  
  
 [!code-cpp[NVC_MFCConnectionPoints#1](../mfc/codesnippet/cpp/connection-points_1.h)]  
  
 O `BEGIN_CONNECTION_PART` e **END_CONNECTION_PART** macros declarar uma classe incorporada, `XSampleConnPt` (derivado de `CConnectionPoint`), que implementa essa conexão determinado ponto. Se você quiser substituir qualquer `CConnectionPoint` funções de membro ou adicionar funções de membro de sua preferência, declará-los entre essas duas macros. Por exemplo, o `CONNECTION_IID` macro substitui o `CConnectionPoint::GetIID` quando colocada entre essas duas macros de função de membro.  
  
 No segundo exemplo, o código é inserido no arquivo de implementação do controle (arquivo. cpp). Esse código implementa o mapa de conexão, que inclui o ponto de conexão, `SampleConnPt`:  
  
 [!code-cpp[NVC_MFCConnectionPoints#2](../mfc/codesnippet/cpp/connection-points_2.cpp)]  
  
 Se sua classe tem mais de uma conexão ponto, inserir adicionais `CONNECTION_PART` macros entre o `BEGIN_CONNECTION_MAP` e `END_CONNECTION_MAP` macros.  
  
 Finalmente, adicione uma chamada para `EnableConnections` no construtor da classe. Por exemplo:  
  
 [!code-cpp[NVC_MFCConnectionPoints#3](../mfc/codesnippet/cpp/connection-points_3.cpp)]  
  
 Depois que esse código foi inserido, o `CCmdTarget`-classe derivada expõe um ponto de conexão para o **ISampleSink** interface. A figura a seguir ilustra esse exemplo.  
  
 ![Ponto de Conexão implementado pelo uso de MFC](../mfc/media/vc37lh2.gif "vc37lh2")  
Um ponto de Conexão implementado com MFC  
  
 Normalmente, os pontos de conexão oferecer suporte a "multicast" — a capacidade de difusão para vários coletores conectado à mesma interface. O fragmento de exemplo a seguir demonstra como multicast ao iterar por cada coletor em um ponto de conexão:  
  
 [!code-cpp[NVC_MFCConnectionPoints#4](../mfc/codesnippet/cpp/connection-points_4.cpp)]  
  
 Este exemplo recupera o conjunto atual de conexões no `SampleConnPt` ponto de conexão com uma chamada para `CConnectionPoint::GetConnections`. Ele itera por meio de conexões e chamadas **ISampleSink::SinkFunc** em cada conexão ativa.  
  
## <a name="see-also"></a>Consulte também  
 [MFC COM](../mfc/mfc-com.md)

