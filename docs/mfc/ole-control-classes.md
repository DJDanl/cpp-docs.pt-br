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
ms.openlocfilehash: 47c28520d592c4bd49ab6cb40edbb2f5ddf59846
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79447639"
---
# <a name="ole-control-classes"></a>Classes de controle OLE

Essas são as classes primárias que você usa ao escrever controles OLE. A classe `COleControlModule` em um módulo de controle OLE é como a classe [CWinApp](../mfc/reference/cwinapp-class.md) em um aplicativo. Cada módulo implementa um ou mais controles OLE; Esses controles são representados por `COleControl` objetos. Esses controles se comunicam com seus contêineres usando objetos `CConnectionPoint`.

As classes `CPictureHolder` e `CFontHolder` encapsulam interfaces COM para imagens e fontes, enquanto as classes `COlePropertyPage` e `CPropExchange` ajudam você a implementar páginas de propriedades e persistência de propriedade para seu controle.

[COleControlModule](../mfc/reference/colecontrolmodule-class.md)<br/>
Substitui a classe `CWinApp` para o módulo de controle OLE. Derive da classe `COleControlModule` para desenvolver um objeto de módulo de controle OLE. Ele fornece funções de membro para inicializar o módulo do seu controle OLE.

[COleControl](../mfc/reference/colecontrol-class.md)<br/>
Derive da classe `COleControl` para desenvolver um controle OLE. Derivado de `CWnd`, essa classe herda toda a funcionalidade de um objeto Window do Windows, mais uma funcionalidade adicional específica de OLE, como o acionamento de eventos e a capacidade de dar suporte a métodos e propriedades.

[CConnectionPoint](../mfc/reference/cconnectionpoint-class.md)<br/>
A classe `CConnectionPoint` define um tipo especial de interface usado para se comunicar com outros objetos OLE, chamados de ponto de conexão. Um ponto de conexão implementa uma interface de saída que é capaz de iniciar ações em outros objetos, como acionar eventos e alterar notificações.

[CPictureHolder](../mfc/reference/cpictureholder-class.md)<br/>
Encapsula a funcionalidade de um objeto de imagem do Windows e a interface COM do `IPicture`; usado para implementar a propriedade de imagem personalizada de um controle OLE.

[CFontHolder](../mfc/reference/cfontholder-class.md)<br/>
Encapsula a funcionalidade de um objeto de fonte do Windows e a interface COM do `IFont`; usado para implementar a propriedade Font de ações de um controle OLE.

[COlePropertyPage](../mfc/reference/colepropertypage-class.md)<br/>
Exibe as propriedades de um controle OLE em uma interface gráfica, semelhante a uma caixa de diálogo.

[CPropExchange](../mfc/reference/cpropexchange-class.md)<br/>
Dá suporte à implementação de persistência de propriedade para seus controles OLE. Análogo a [CDataExchange](../mfc/reference/cdataexchange-class.md) para caixas de diálogo.

[CMonikerFile](../mfc/reference/cmonikerfile-class.md)<br/>
Usa um moniker ou uma representação de cadeia de caracteres que ele pode transformar em um moniker e o associa de forma síncrona ao fluxo para o qual o moniker é um nome.

[CAsyncMonikerFile](../mfc/reference/casyncmonikerfile-class.md)<br/>
Funciona de forma semelhante a `CMonikerFile`; no entanto, ele associa o moniker de forma assíncrona ao fluxo para o qual o moniker é um nome.

[CDataPathProperty](../mfc/reference/cdatapathproperty-class.md)<br/>
Implementa uma propriedade de controle OLE que pode ser carregada de forma assíncrona.

[CCachedDataPathProperty](../mfc/reference/ccacheddatapathproperty-class.md)<br/>
Implementa uma propriedade de controle OLE transferida de forma assíncrona e armazenada em cache em um arquivo de memória.

[COleCmdUI](../mfc/reference/colecmdui-class.md)<br/>
Permite que um documento ativo receba comandos originados na interface do usuário do contêiner (como FileNew, abrir, imprimir e assim por diante) e permite que um contêiner receba comandos originados na interface do usuário do documento ativo.

[COleSafeArray](../mfc/reference/colesafearray-class.md)<br/>
Funciona com matrizes de tipo e dimensão arbitrárias.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)
