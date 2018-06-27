---
title: 'Plano de fundo OLE: Implementação de MFC | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- IMarshall
- IMoniker
dev_langs:
- C++
helpviewer_keywords:
- MFC libraries, implementing
- OLE MFC library implementation
- OLE IMarshal interface
- IMoniker interface, MFC
- IMarshall class [MFC]
- OLE, compound files
- OLE IMoniker interface
- OLE IUnknown
ms.assetid: 2b67016a-d78e-4d60-925f-c28ec8fb6180
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d77d603c198adad2ca2c827c355ff8f6808bff66
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36930320"
---
# <a name="ole-background-mfc-implementation"></a>tela de fundo OLE: implementação MFC
Por causa do tamanho e complexidade da bruto OLE API, chamá-lo diretamente para gravar aplicativos OLE pode ser muito demorado. O objetivo da implementação de biblioteca Microsoft Foundation Class de OLE é reduzir a quantidade de trabalho que você precisa fazer para escrever aplicativos compatíveis com OLE completo.  
  
 Este artigo explica as partes da API OLE que não foram implementadas dentro do MFC. A discussão também explica como o que é implementado mapeia para a seção OLE do SDK do Windows.  
  
##  <a name="_core_portions_of_ole_not_implemented_by_the_class_library"></a> Partes de OLE não implementada pela biblioteca de classe  
 Alguns recursos do OLE e interfaces não são fornecidos diretamente pelo MFC. Se você quiser usar esses recursos, você pode chamar a API OLE diretamente.  
  
 Interface IMoniker  
 O `IMoniker` interface é implementada pela biblioteca de classe (por exemplo, a `COleServerItem` classe) mas anteriormente não expostos para o programador. Para obter mais informações sobre essa interface, consulte OLE Moniker implementações na seção OLE do SDK do Windows. No entanto, também consulte classe [CMonikerFile](../mfc/reference/cmonikerfile-class.md) e [CAsyncMonikerFile](../mfc/reference/casyncmonikerfile-class.md).  
  
 IUnknown e Interfaces de IMarshal  
 O `IUnknown` interface é implementada pela biblioteca de classe, mas não é exposto para o programador. O `IMarshal` interface não é implementada pela biblioteca de classe, mas é usada internamente. Servidores de automação criadas usando a biblioteca de classe já tem recursos internos de empacotamento.  
  
 DOCFILES (arquivos compostos)  
 Arquivos compostos têm suporte parcial da biblioteca de classe. Nenhuma das funções que manipulam diretamente os arquivos compostos além da criação têm suporte. Classe do MFC usa `COleFileStream` para oferecer suporte a manipulação de fluxos com funções de arquivo padrão. Para obter mais informações, consulte o artigo [contêineres: arquivos compostos](../mfc/containers-compound-files.md).  
  
 Servidores em processo e manipuladores de objeto  
 Servidores em processo e manipuladores de objeto permitem a implementação de edição visual de dados ou objetos de modelo de objeto de componente (COM) completo em uma biblioteca de vínculo dinâmico (DLL). Para fazer isso, você pode implementar sua DLL chamando a API OLE diretamente. No entanto, se você estiver escrevendo um servidor de automação e o servidor não tem nenhuma interface do usuário, você pode usar AppWizard para tornar um servidor em processo de seu servidor e colocá-la completamente em uma DLL. Para obter mais informações sobre esses tópicos, consulte [servidores de automação](../mfc/automation-servers.md).  
  
> [!TIP]
>  É a maneira mais fácil de implementar um servidor de automação para colocá-lo em uma DLL. Essa abordagem oferece suporte a MFC.  
  
 Para obter mais informações sobre como as classes Microsoft Foundation OLE implementam interfaces OLE, consulte Observações técnicas MFC [38](../mfc/tn038-mfc-ole-iunknown-implementation.md), [39](../mfc/tn039-mfc-ole-automation-implementation.md), e [40](../mfc/tn040-mfc-ole-in-place-resizing-and-zooming.md).  
  
## <a name="see-also"></a>Consulte também  
 [Plano de fundo OLE](../mfc/ole-background.md)   
 [Tela de fundo OLE: estratégias de implementação](../mfc/ole-background-implementation-strategies.md)

