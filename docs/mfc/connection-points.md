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
ms.openlocfilehash: 1a8fc4742b8bf686edf75f3b98cc283b9bf9881b
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84620724"
---
# <a name="connection-points"></a>Pontos de conexão

Este artigo explica como implementar pontos de conexão (anteriormente conhecidos como pontos de conexão OLE) usando as classes do MFC `CCmdTarget` e o `CConnectionPoint` .

No passado, o COM (Component Object Model) definiu um mecanismo geral ( `IUnknown::QueryInterface` *) que permitia aos objetos implementar e expor a funcionalidade em interfaces. No entanto, um mecanismo correspondente que permitia que os objetos exponham sua capacidade de chamar interfaces específicas não foi definido. Ou seja, o COM definiu como os ponteiros de entrada para objetos (ponteiros para as interfaces desse objeto) foram manipulados, mas ele não tinha um modelo explícito para interfaces de saída (ponteiros que o objeto contém para as interfaces de outros objetos). COM agora tem um modelo, chamado pontos de conexão, que dá suporte a essa funcionalidade.

Uma conexão tem duas partes: o objeto que chama a interface, chamado de origem e o objeto que implementa a interface, chamado de coletor. Um ponto de conexão é a interface exposta pela origem. Ao expor um ponto de conexão, uma fonte permite que os coletores estabeleçam conexões a si mesmo (a origem). Por meio do mecanismo de ponto de conexão (a `IConnectionPoint` interface), um ponteiro para a interface do coletor é passado para o objeto de origem. Esse ponteiro fornece a fonte com acesso à implementação do coletor de um conjunto de funções de membro. Por exemplo, para acionar um evento implementado pelo coletor, a origem pode chamar o método apropriado de implementação do coletor. A figura a seguir demonstra o ponto de conexão que acabamos de descrever.

![Ponto de conexão implementado](../mfc/media/vc37lh1.gif "Ponto de conexão implementado") <br/>
Um ponto de conexão implementado

O MFC implementa esse modelo nas classes [CConnectionPoint](reference/cconnectionpoint-class.md) e [CCmdTarget](reference/ccmdtarget-class.md) . Classes derivadas de `CConnectionPoint` implementar a `IConnectionPoint` interface, usadas para expor pontos de conexão a outros objetos. Classes derivadas de `CCmdTarget` implementam a `IConnectionPointContainer` interface, que pode enumerar todos os pontos de conexão disponíveis de um objeto ou encontrar um ponto de conexão específico.

Para cada ponto de conexão implementado em sua classe, você deve declarar uma parte de conexão que implementa o ponto de conexão. Se você implementar um ou mais pontos de conexão, também deverá declarar um único mapa de conexão em sua classe. Um mapa de conexão é uma tabela de pontos de conexão com suporte pelo controle ActiveX.

Os exemplos a seguir demonstram um mapa de conexão simples e um ponto de conexão. O primeiro exemplo declara o mapa de conexão e o ponto; o segundo exemplo implementa o mapa e o ponto. Observe que `CMyClass` deve ser uma `CCmdTarget` classe derivada. No primeiro exemplo, o código é inserido na declaração de classe, sob a seção **protegida** :

[!code-cpp[NVC_MFCConnectionPoints#1](codesnippet/cpp/connection-points_1.h)]

As macros **BEGIN_CONNECTION_PART** e **END_CONNECTION_PART** declaram uma classe incorporada, `XSampleConnPt` (derivada de `CConnectionPoint` ), que implementa esse ponto de conexão específico. Se você quiser substituir qualquer `CConnectionPoint` função de membro ou adicionar funções de membro por conta própria, declare-as entre essas duas macros. Por exemplo, a `CONNECTION_IID` macro substitui a `CConnectionPoint::GetIID` função de membro quando colocada entre essas duas macros.

No segundo exemplo, o código é inserido no arquivo de implementação do controle (arquivo. cpp). Esse código implementa o mapa de conexão, que inclui o ponto de conexão, `SampleConnPt` :

[!code-cpp[NVC_MFCConnectionPoints#2](codesnippet/cpp/connection-points_2.cpp)]

Se sua classe tiver mais de um ponto de conexão, insira **CONNECTION_PART** macros adicionais entre as **BEGIN_CONNECTION_MAP** e **END_CONNECTION_MAP** macros.

Por fim, adicione uma chamada para `EnableConnections` no construtor da classe. Por exemplo:

[!code-cpp[NVC_MFCConnectionPoints#3](codesnippet/cpp/connection-points_3.cpp)]

Depois que esse código tiver sido inserido, sua `CCmdTarget` classe derivada expõe um ponto de conexão para a `ISampleSink` interface. A figura a seguir ilustra este exemplo.

![Ponto de conexão implementado usando MFC](../mfc/media/vc37lh2.gif "Ponto de conexão implementado usando MFC") <br/>
Um ponto de conexão implementado com MFC

Normalmente, os pontos de conexão dão suporte a "multicast" — a capacidade de difundir para vários coletores conectados à mesma interface. O fragmento de exemplo a seguir demonstra como multicast, Iterando por meio de cada coletor em um ponto de conexão:

[!code-cpp[NVC_MFCConnectionPoints#4](codesnippet/cpp/connection-points_4.cpp)]

Este exemplo recupera o conjunto atual de conexões no `SampleConnPt` ponto de conexão com uma chamada para `CConnectionPoint::GetConnections` . Em seguida, ele faz a iteração pelas conexões e chamadas `ISampleSink::SinkFunc` em todas as conexões ativas.

## <a name="see-also"></a>Consulte também

[MFC COM](mfc-com.md)
