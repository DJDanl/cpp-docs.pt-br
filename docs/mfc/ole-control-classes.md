---
title: Classes de controle OLE
ms.date: 11/04/2016
helpviewer_keywords:
- ActiveX classes [MFC]
- custom controls [MFC], classes
- ActiveX controls [MFC], OLE control classes
- ActiveX control classes [MFC]
- OLE controls [MFC], classes
- OLE control classes [MFC]
- reusable component classes [MFC]
ms.assetid: 96495ec3-319e-4163-b839-1af0428ed9dd
ms.openlocfilehash: 5aa3899dca5a42cf789dc6dfd4701547495ec618
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84617760"
---
# <a name="ole-control-classes"></a>Classes de controle OLE

Essas são as classes primárias que você usa ao escrever controles OLE. A `COleControlModule` classe em um módulo de controle OLE é como a classe [CWinApp](reference/cwinapp-class.md) em um aplicativo. Cada módulo implementa um ou mais controles OLE; Esses controles são representados por `COleControl` objetos. Esses controles se comunicam com seus contêineres usando `CConnectionPoint` objetos.

As `CPictureHolder` `CFontHolder` classes e encapsulam interfaces com para imagens e fontes, enquanto as `COlePropertyPage` `CPropExchange` classes e ajudam você a implementar páginas de propriedade e persistência de propriedade para seu controle.

[COleControlModule](reference/colecontrolmodule-class.md)<br/>
Substitui a `CWinApp` classe do seu módulo de controle OLE. Derive da `COleControlModule` classe para desenvolver um objeto de módulo de controle OLE. Ele fornece funções de membro para inicializar o módulo do seu controle OLE.

[COleControl](reference/colecontrol-class.md)<br/>
Derive da `COleControl` classe para desenvolver um controle OLE. Derivado de `CWnd` , essa classe herda toda a funcionalidade de um objeto Window do Windows, além de uma funcionalidade adicional específica de OLE, como o acionamento de eventos e a capacidade de dar suporte a métodos e propriedades.

[CConnectionPoint](reference/cconnectionpoint-class.md)<br/>
A `CConnectionPoint` classe define um tipo especial de interface usado para se comunicar com outros objetos OLE, chamados de ponto de conexão. Um ponto de conexão implementa uma interface de saída que é capaz de iniciar ações em outros objetos, como acionar eventos e alterar notificações.

[CPictureHolder](reference/cpictureholder-class.md)<br/>
Encapsula a funcionalidade de um objeto de imagem do Windows e a `IPicture` interface com; usada para implementar a propriedade de imagem personalizada de um controle OLE.

[CFontHolder](reference/cfontholder-class.md)<br/>
Encapsula a funcionalidade de um objeto de fonte do Windows e a `IFont` interface com; usada para implementar a propriedade Font de stock de um controle OLE.

[COlePropertyPage](reference/colepropertypage-class.md)<br/>
Exibe as propriedades de um controle OLE em uma interface gráfica, semelhante a uma caixa de diálogo.

[CPropExchange](reference/cpropexchange-class.md)<br/>
Dá suporte à implementação de persistência de propriedade para seus controles OLE. Análogo a [CDataExchange](reference/cdataexchange-class.md) para caixas de diálogo.

[CMonikerFile](reference/cmonikerfile-class.md)<br/>
Usa um moniker ou uma representação de cadeia de caracteres que ele pode transformar em um moniker e o associa de forma síncrona ao fluxo para o qual o moniker é um nome.

[CAsyncMonikerFile](reference/casyncmonikerfile-class.md)<br/>
Funciona de forma semelhante a `CMonikerFile` ; no entanto, ele associa o moniker de forma assíncrona ao fluxo para o qual o moniker é um nome.

[CDataPathProperty](reference/cdatapathproperty-class.md)<br/>
Implementa uma propriedade de controle OLE que pode ser carregada de forma assíncrona.

[CCachedDataPathProperty](reference/ccacheddatapathproperty-class.md)<br/>
Implementa uma propriedade de controle OLE transferida de forma assíncrona e armazenada em cache em um arquivo de memória.

[COleCmdUI](reference/colecmdui-class.md)<br/>
Permite que um documento ativo receba comandos originados na interface do usuário do contêiner (como FileNew, abrir, imprimir e assim por diante) e permite que um contêiner receba comandos originados na interface do usuário do documento ativo.

[COleSafeArray](reference/colesafearray-class.md)<br/>
Funciona com matrizes de tipo e dimensão arbitrárias.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](class-library-overview.md)
