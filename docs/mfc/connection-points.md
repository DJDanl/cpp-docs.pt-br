---
title: Pontos de conexão
ms.date: 11/19/2018
f1_keywords:
- IConnectionPoint
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
ms.openlocfilehash: 6f934c4a5a24c5d54805a60e81cb0afdcdc2c14a
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57304733"
---
# <a name="connection-points"></a>Pontos de conexão

Este artigo explica como implementar pontos de conexão (anteriormente conhecidos como pontos de conexão OLE) usando as classes MFC `CCmdTarget` e `CConnectionPoint`.

No passado, o modelo de objeto de componente (COM) definido um mecanismo geral (`IUnknown::QueryInterface`*) que permitiu a objetos para implementar e expor a funcionalidade em interfaces. No entanto, um mecanismo correspondente que objetos expor sua capacidade de chamar interfaces específicas de permissão não foi definido. Ou seja, COM definido como entrados ponteiros para objetos faziam (ponteiros para interfaces do objeto), mas não tinha um modelo explícito para interfaces de saída (o objeto mantém a interfaces de outros objetos de ponteiros). COM agora tem um modelo, chamado de pontos de conexão, que dá suporte a essa funcionalidade.

Uma conexão tem duas partes: o objeto que está chamando a interface, chamada a origem e o objeto que implementa a interface, chamou o coletor. Um ponto de conexão é a interface exposta pela origem. Ao expor um ponto de conexão, uma fonte permite coletores estabelecer conexões a mesmo (a origem). A conexão por meio do mecanismo de ponto (o `IConnectionPoint` interface), um ponteiro para a interface de coletor é passado para o objeto de origem. Esse ponteiro fornece o código-fonte com acesso à implementação do coletor de um conjunto de funções de membro. Por exemplo, para disparar um evento implementado pelo coletor, o código-fonte pode chamar o método apropriado da implementação do coletor. A figura a seguir demonstra a conexão ponto que acabei de descrever.

![Implementado o ponto de conexão](../mfc/media/vc37lh1.gif "implementado o ponto de conexão") <br/>
Um ponto de Conexão implementado

MFC implementa esse modelo na [CConnectionPoint](../mfc/reference/cconnectionpoint-class.md) e [CCmdTarget](../mfc/reference/ccmdtarget-class.md) classes. As classes derivadas `CConnectionPoint` implementar o `IConnectionPoint` interface, usado para expor pontos de conexão a outros objetos. As classes derivadas `CCmdTarget` implementar o `IConnectionPointContainer` interface, que pode enumerar todos os pontos de conexão disponíveis de um objeto ou localizar um ponto de conexão específico.

Para cada ponto de conexão implementado na classe, você deve declarar uma parte de conexão que implementa o ponto de conexão. Se você implementar um ou mais pontos de conexão, você também deve declarar um mapa de conexão única em sua classe. Um mapa de conexão é uma tabela de pontos de conexão com suporte pelo controle ActiveX.

Os exemplos a seguir demonstram um mapa de conexão simples e um ponto de uma conexão. O primeiro exemplo declara o mapa de conexão e o ponto; o segundo exemplo implementa o mapa e o ponto. Observe que `CMyClass` deve ser um `CCmdTarget`-classe derivada. No primeiro exemplo, código é inserido na declaração de classe, sob o **protegidos** seção:

[!code-cpp[NVC_MFCConnectionPoints#1](../mfc/codesnippet/cpp/connection-points_1.h)]

O **BEGIN_CONNECTION_PART** e **END_CONNECTION_PART** macros declarar uma classe incorporada, `XSampleConnPt` (derivado de `CConnectionPoint`), que implementa essa conexão específica do ponto. Se você quiser substituir qualquer `CConnectionPoint` funções de membro ou adicionar funções de membro de sua preferência, declará-los entre essas duas macros. Por exemplo, o `CONNECTION_IID` macro substitui o `CConnectionPoint::GetIID` quando colocado entre essas duas macros de função de membro.

No segundo exemplo, o código é inserido no arquivo de implementação do controle (arquivo. cpp). Esse código implementa um mapa de conexão, que inclui o ponto de conexão, `SampleConnPt`:

[!code-cpp[NVC_MFCConnectionPoints#2](../mfc/codesnippet/cpp/connection-points_2.cpp)]

Se sua classe tem mais de uma conexão ponto, inserir adicionais **CONNECTION_PART** macros entre as **BEGIN_CONNECTION_MAP** e **END_CONNECTION_MAP** macros.

Por fim, adicione uma chamada para `EnableConnections` no construtor da classe. Por exemplo:

[!code-cpp[NVC_MFCConnectionPoints#3](../mfc/codesnippet/cpp/connection-points_3.cpp)]

Depois que esse código foi inserido, sua `CCmdTarget`-classe derivada expõe um ponto de conexão para o `ISampleSink` interface. A figura a seguir ilustra esse exemplo.

![Ponto de Conexão implementado pelo uso de MFC](../mfc/media/vc37lh2.gif "implementado pelo uso de MFC de ponto de Conexão") <br/>
Um ponto de Conexão implementado com MFC

Normalmente, os pontos de conexão dão suporte a "multicast" — a capacidade de fazer uma transmissão para vários coletores conectados para a mesma interface. O fragmento de exemplo a seguir demonstra como multicast iterando por cada coletor em um ponto de conexão:

[!code-cpp[NVC_MFCConnectionPoints#4](../mfc/codesnippet/cpp/connection-points_4.cpp)]

Este exemplo recupera o conjunto atual de conexões na `SampleConnPt` ponto de conexão com uma chamada para `CConnectionPoint::GetConnections`. Em seguida, itera através de conexões e chama `ISampleSink::SinkFunc` em cada conexão do Active Directory.

## <a name="see-also"></a>Consulte também

[MFC COM](../mfc/mfc-com.md)
