---
title: "&#193;rea de Transfer&#234;ncia: adicionando outros formatos | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Área de Transferência, formatos"
  - "formatos de dados de Área de Transferência padronizados"
  - "formato personalizados"
  - "formato personalizados, colocando na Área de Transferência"
  - "formatos [C++], Área de Transferência"
  - "registrando formatos de dados de Área de Transferência personalizados"
ms.assetid: aea58159-65ed-4385-aeaa-3d9d5281903b
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# &#193;rea de Transfer&#234;ncia: adicionando outros formatos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico explica como expanda a lista de formatos com suporte, particularmente para suporte OLE.  O tópico [Área de transferência: Copiando e colando dados](../Topic/Clipboard:%20Copying%20and%20Pasting%20Data.md) descreve a implementação mínima necessária para dar suporte ao copiar e colar da área de transferência.  Se esse é tudo você implementa, os únicos formatos colocados na área de transferência é `CF_METAFILEPICT`, **CF\_EMBEDSOURCE**, **CF\_OBJECTDESCRIPTOR**e, possivelmente `CF_LINKSOURCE`.  A maioria dos aplicativos precisarão mais formatos na área de transferência desses três.  
  
##  <a name="_core_registering_custom_formats"></a> Registrando formatos personalizados  
 Para criar seus próprios formatos personalizados, siga o mesmo procedimento que você usaria quando registrando qualquer formato personalizado da área de transferência: passe o nome do formato à função de **RegisterClipboardFormat** e use o valor de retorno como a ID de formato  
  
##  <a name="_core_placing_formats_on_the_clipboard"></a> Colocando formatos na área de transferência  
 Para adicionar mais formatos para aqueles colocados na área de transferência, você deverá substituir a função de `OnGetClipboardData` da classe que podem ser derivadas de `COleClientItem` ou de `COleServerItem` \(dependendo se os dados a serem copiados são nativos\).  Nessa função, use o procedimento a seguir.  
  
#### Para colocar formatos na área de transferência  
  
1.  Crie um objeto `COleDataSource`.  
  
2.  Transmitir essa fonte de dados a uma função que adiciona seus formatos de dados nativos à lista de formatos com suporte `COleDataSource::CacheGlobalData`chamando.  
  
3.  Adicionar formatos padrão chamando `COleDataSource::CacheGlobalData` para cada formato padrão que você deseja dar suporte.  
  
 Essa técnica é usada no programa de exemplo OLE [HIERSVR](../top/visual-cpp-samples.md) MFC \(examine a função de membro de `OnGetClipboardData` da classe de **CServerItem** \).  A única diferença neste exemplo é que três etapa não é implementada como HIERSVR não da suporte a outros formatos padrão.  
  
### Que você deseja saber mais?  
  
-   [Objetos de dados OLE e fontes de dados e transferência de dados\)](../mfc/data-objects-and-data-sources-ole.md)  
  
-   [Arraste e solte OLE](../mfc/drag-and-drop-ole.md)  
  
-   [OLE](../mfc/ole-background.md)  
  
## Consulte também  
 [Área de Transferência: usando o mecanismo Área de Transferência OLE](../mfc/clipboard-using-the-ole-clipboard-mechanism.md)