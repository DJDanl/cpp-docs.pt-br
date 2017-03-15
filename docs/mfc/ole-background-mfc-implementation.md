---
title: "Plano de fundo OLE: implementa&#231;&#227;o MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/13/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "IMarshall"
  - "IMoniker"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe IMarshall"
  - "Interface IMoniker, MFC"
  - "Bibliotecas MFC, implementando"
  - "Interface OLE IMarshal"
  - "Interface OLE IMoniker"
  - "OLE IUnknown"
  - "implementação de biblioteca OLE MFC"
  - "OLE, arquivos compostos"
ms.assetid: 2b67016a-d78e-4d60-925f-c28ec8fb6180
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Plano de fundo OLE: implementa&#231;&#227;o MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Devido ao tamanho e a complexidade de API OLE bruto, chame diretamente para gravar aplicativos OLE pode ser muito demorado.  A meta da implementação da biblioteca de classes do Microsoft OLE é reduzir a quantidade de trabalho que você precisa tornar a gravação completa caracterizada, os aplicativos podem OLE\-.  
  
 Este artigo explica as partes da API OLE que não foram MFC interno implementado.  A discussão também explica como o que é mapeado implementados a seção de OLE [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  
  
##  <a name="_core_portions_of_ole_not_implemented_by_the_class_library"></a> Partes de OLE não implementadas pela biblioteca de classes  
 Alguns recursos e interfaces OLE não são fornecidos diretamente por MFC.  Se quiser usar esses recursos, você pode chamar a API OLE diretamente.  
  
 Interface de IMoniker  
 A interface de `IMoniker` é implementada pela biblioteca de classe \(por exemplo, a classe de `COleServerItem` \) mas não tiver sido expostos anteriormente ao programador.  Para obter mais informações sobre essa interface, consulte implementações OLE DB do moniker na seção de OLE [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  No entanto, consulte também a classe [CMonikerFile](../Topic/CMonikerFile%20Class.md) e [CAsyncMonikerFile](../mfc/reference/casyncmonikerfile-class.md).  
  
 IUnknown e interfaces de IMarshal  
 A interface de **IUnknown** é implementada pela biblioteca de classes mas não expõe ao programador.  A interface de **IMarshal** não é implementada pela biblioteca de classes mas é usada internamente.  Os servidores de automação compilados usando a biblioteca de classe já tem recursos internos marshaling.  
  
 Docfiles \(arquivos compostos\)  
 Os arquivos parcialmente compostos têm suporte pela biblioteca da classe.  Nenhuma das funções que manipulam diretamente arquivos compostos além de criação são suportadas.  O usa MFC classe **COleFileStream** para dar suporte à manipulação dos fluxos com funções de arquivos padrão.  Para obter mais informações, consulte o artigo [Contêiner: Arquivos compostos](../mfc/containers-compound-files.md).  
  
 Servidores em processo e manipuladores de objeto  
 Os servidores em processo e os manipuladores do objeto permitem a implementação de dados visuais de edição ou de objetos completo do Component Object Model \(COM\) em uma biblioteca de vínculo dinâmico\) nativa \(DLL\).  Para fazer isso, você pode implementar seu DLL chamando apis OLE diretamente.  No entanto, se você estiver escrevendo um servidor de automação e seu servidor não tem nenhuma interface do usuário, você pode usar AppWizard para fazer seu servidor a um servidor em processo e colocá\-las completamente em uma DLL.  Para obter mais informações sobre esses tópicos, consulte [Servidores de automação](../mfc/automation-servers.md).  
  
> [!TIP]
>  A maneira mais fácil de implementar um servidor de automação é colocá\-lo em uma DLL.  MFC O da suporte a essa abordagem.  
  
 Para obter mais informações sobre como as interfaces OLE DB OLE de ferramentas das classes do Microsoft, consulte a [38](../mfc/tn038-mfc-ole-iunknown-implementation.md)técnicas MFC notas, [39](../mfc/tn039-mfc-ole-automation-implementation.md), e [40](../mfc/tn040-mfc-ole-in-place-resizing-and-zooming.md).  
  
## Consulte também  
 [Plano de fundo OLE](../mfc/ole-background.md)   
 [Plano de fundo OLE: estratégias de implementação](../mfc/ole-background-implementation-strategies.md)