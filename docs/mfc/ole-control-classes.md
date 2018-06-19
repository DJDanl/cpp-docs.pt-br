---
title: Classes de controle OLE | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.classes.ole
dev_langs:
- C++
helpviewer_keywords:
- ActiveX classes [MFC]
- custom controls [MFC], classes
- ActiveX controls [MFC], OLE control classes
- ActiveX control classes [MFC]
- OLE controls [MFC], classes
- OLE control classes [MFC]
- reusable component classes [MFC]
ms.assetid: 96495ec3-319e-4163-b839-1af0428ed9dd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5dcbda85c33bab37babe5da861067d25cf31e32c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33355344"
---
# <a name="ole-control-classes"></a>Classes de controle OLE
Essas são as classes principais usadas durante a gravação de controles OLE. O `COleControlModule` classe em um módulo de controle OLE é como o [CWinApp](../mfc/reference/cwinapp-class.md) classe em um aplicativo. Cada módulo implementa um ou mais controles OLE. Esses controles são representados por `COleControl` objetos. Esses controles se comunicar com seus contêineres usando `CConnectionPoint` objetos.  
  
 O `CPictureHolder` e `CFontHolder` classes encapsulam interfaces COM para imagens e fontes, enquanto o `COlePropertyPage` e `CPropExchange` classes ajudarão-lo a implementar as páginas de propriedade e persistência de propriedade para o seu controle.  
  
 [COleControlModule](../mfc/reference/colecontrolmodule-class.md)  
 Substitui o `CWinApp` classe para o módulo de controle OLE. Derivam de `COleControlModule` classe para desenvolver um objeto de módulo de controle OLE. Ele fornece funções de membro para inicializar o módulo do seu controle OLE.  
  
 [COleControl](../mfc/reference/colecontrol-class.md)  
 Derivam de `COleControl` classe para desenvolver um controle OLE. Derivado `CWnd`, essa classe herda todas as funcionalidades de um objeto de janela do Windows e outras funcionalidades de OLE específico, como o acionamento do evento e a capacidade de dar suporte a métodos e propriedades.  
  
 [CConnectionPoint](../mfc/reference/cconnectionpoint-class.md)  
 O `CConnectionPoint` classe define um tipo especial de interface usada para se comunicar com outros objetos OLE, chamados de ponto de conexão. Um ponto de conexão implementa uma interface de saída que é capaz de iniciar ações em outros objetos, como disparar eventos e notificações de alteração.  
  
 [CPictureHolder](../mfc/reference/cpictureholder-class.md)  
 Encapsula a funcionalidade de um objeto de imagem do Windows e o `IPicture` COM interface; usado para implementar a propriedade de imagem personalizada de um controle OLE.  
  
 [CFontHolder](../mfc/reference/cfontholder-class.md)  
 Encapsula a funcionalidade de um objeto de fonte do Windows e o `IFont` COM interface; usado para implementar a propriedade de fonte de estoque de um controle OLE.  
  
 [COlePropertyPage](../mfc/reference/colepropertypage-class.md)  
 Exibe as propriedades de uma OLE controlam em uma interface gráfica, semelhante a uma caixa de diálogo.  
  
 [CPropExchange](../mfc/reference/cpropexchange-class.md)  
 Oferece suporte à implementação de persistência de propriedade para controles OLE. Semelhante a [CDataExchange](../mfc/reference/cdataexchange-class.md) para caixas de diálogo.  
  
 [CMonikerFile](../mfc/reference/cmonikerfile-class.md)  
 Usa um identificador de origem ou uma representação de cadeia de caracteres que pode fazer em um identificador de origem e o associa forma síncrona no fluxo para o qual o identificador de origem é um nome.  
  
 [CAsyncMonikerFile](../mfc/reference/casyncmonikerfile-class.md)  
 Funciona da mesma forma que `CMonikerFile`; no entanto, ele associa o moniker assincronamente para o fluxo para o qual o identificador de origem é um nome.  
  
 [CDataPathProperty](../mfc/reference/cdatapathproperty-class.md)  
 Implementa uma OLE controla a propriedade que pode ser carregada de forma assíncrona.  
  
 [CCachedDataPathProperty](../mfc/reference/ccacheddatapathproperty-class.md)  
 Implementa uma OLE propriedade transferido de forma assíncrona e armazenados em cache em um arquivo de memória de controle.  
  
 [COleCmdUI](../mfc/reference/colecmdui-class.md)  
 Permite que um documento ativo receber comandos que se originam na interface do usuário do seu contêiner (por exemplo, FileNew, abrir, imprimir e assim por diante) e permite que um contêiner receber comandos que se originam na interface do usuário do documento ativo.  
  
 [COleSafeArray](../mfc/reference/colesafearray-class.md)  
 Funciona com matrizes de tipo arbitrário e dimensão.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)

