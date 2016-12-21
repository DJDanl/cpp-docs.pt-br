---
title: "Arrastar e soltar (OLE) | Microsoft Docs"
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
  - "arrastar e soltar [C++]"
  - "arrastar e soltar [C++], sobre arrastar e soltar OLE"
  - "suporte a operações arrastar e soltar do Gerenciador de Arquivos"
  - "Aplicativos OLE, arrastar e soltar"
  - "arrastar e soltar OLE"
  - "aplicativos de servidor OLE, arrastar e soltar"
ms.assetid: a4595350-ca06-4400-88a1-f0175c76b77b
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Arrastar e soltar (OLE)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O recurso de arrastar e soltar OLE é essencialmente um atalho para copiar e colar dados.  Quando você usa a área de transferência para copiar ou colar dados, um número de etapas são necessárias.  Selecione os dados, clique em **Recortar** ou **Copiar** no menu de **Editar** , vá para o arquivo de destino, na janela do ou do aplicativo, coloque o cursor no local desejado e, em **Colar** no menu de **Editar** .  
  
 Arraste ao OLE e soltar são diferentes do mecanismo de arrastar e soltar do gerenciador de arquivos, que só pode tratar nomes de arquivo e é criado especificamente para transmitir nomes de arquivo para aplicativos.  Arraste o OLE e remoção são muito mais gerais.  Permite que você arrasta e remove todos os dados que também podem ser colocados na área de transferência.  
  
 Quando você usa o OLE e arraste a remoção, você remover duas etapas do processo.  Selecione os dados da janela de origem \(da origem “drop”\), arraste\-a para o destino desejado \(do destino “drop”\) e remova\-a, liberando o botão do mouse em.  A operação elimina a necessidade de menus e mais rápido do que a cópia\/sequência da pasta.  O único requisito é que a origem de descarte e o destino de descarte devem ser abertos e pelo menos parcialmente visíveis na tela.  
  
 Usando o OLE e arraste a remoção, os dados podem ser transferidos de um local para outro dentro de um documento, entre documentos diferentes, ou entre aplicativos.  Pode ser implementado em um contêiner ou em um aplicativo de servidor, e qualquer aplicativo pode ser uma fonte drop, um destino de descarte, ou em ambos.  Se um aplicativo tiver a gota\- origem e suporte a gota\- destino implementados, arraste e remoção é habilitada entre janelas filho, ou em uma janela.  Esse recurso pode facilitar seu aplicativo muito ser usado.  
  
 Se você só quiser usar os recursos de arrastar e soltar OLE, consulte [Arraste e solte: Personalizar](../Topic/Drag%20and%20Drop:%20Customizing.md).  Você pode usar as técnicas explicadas naquele artigo para fazer origens de descarte os aplicativos de não OLE.  O artigo [Arraste e solte: Implementando um destino de descarte](../mfc/drag-and-drop-implementing-a-drop-target.md) descreve como implementar o suporte de gota\- destino para aplicativos OLE e não OLE.  Também será útil revisar os exemplos [OCLIENT](../top/visual-cpp-samples.md) e [HIERSVR](../top/visual-cpp-samples.md)MFC OLE.  
  
 Se você não tiver a família de [Objetos de dados e fontes de dados \(OLE\)](../mfc/data-objects-and-data-sources-ole.md) de artigos, talvez você queira fazer isso agora.  Esses artigos a seguir explicam os conceitos básicos de transferência de dados, e como implementá\-la em seus aplicativos.  
  
 Para obter mais informações sobre o arraste e solte, consulte:  
  
-   [Arraste e solte: Implementando uma origem drop](../mfc/drag-and-drop-implementing-a-drop-source.md)  
  
-   [Arraste e solte: Implementando um destino de descarte](../mfc/drag-and-drop-implementing-a-drop-target.md)  
  
-   [Arraste e solte: Personalizar](../Topic/Drag%20and%20Drop:%20Customizing.md)  
  
## Consulte também  
 [OLE](../mfc/ole-in-mfc.md)   
 [Objetos e origens de dados \(OLE\)](../mfc/data-objects-and-data-sources-ole.md)