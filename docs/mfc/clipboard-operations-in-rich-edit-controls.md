---
title: "Opera&#231;&#245;es da &#193;rea de Transfer&#234;ncia em controles de edi&#231;&#227;o avan&#231;ada | Microsoft Docs"
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
  - "Área de Transferência, operações em CRichEditCtrl"
  - "operações de cópia em controles de edição avançada"
  - "Classe CRichEditCtrl, opções de Área de Transferência"
  - "Classe CRichEditCtrl, operação de colagem"
  - "operação de recorte na classe CRichEditCtrl"
  - "colando dados da Área de Transferência"
  - "controles de edição avançada, opções de Área de Transferência"
ms.assetid: 15ce66bc-2636-4a35-a2ae-d52285dc1af6
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Opera&#231;&#245;es da &#193;rea de Transfer&#234;ncia em controles de edi&#231;&#227;o avan&#231;ada
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Seu aplicativo pode colar o conteúdo da área de transferência em um controle de edição avançado \([CRichEditCtrl](../Topic/CRichEditCtrl%20Class.md)\) que usa o melhor formato disponível na área de transferência ou um formato específico da área de transferência.  Você também pode determinar se um controle de edição rico é capaz de colar um formato da área de transferência.  
  
 Você pode recortar ou copiar o conteúdo da seleção atual usando a função de membro de [Cópia](../Topic/CRichEditCtrl::Copy.md) ou de [Fatiando](../Topic/CRichEditCtrl::Cut.md) .  Da mesma forma, você pode colar o conteúdo da área de transferência em um controle de edição rico usando a função de membro de [Pasta](../Topic/CRichEditCtrl::Paste.md) .  O controle cole o primeiro formato disponível que reconhece, que é presumivelmente o formato mais descritivo.  
  
 Para colar um formato específico da área de transferência, você pode usar a função de membro de [PasteSpecial](../Topic/CRichEditCtrl::PasteSpecial.md) .  Essa função é útil para aplicativos com um comando especial da pasta que permite que o usuário selecionar o formato da área de transferência.  Você pode usar a função de membro de [CanPaste](../Topic/CRichEditCtrl::CanPaste.md) para determinar se um determinado formato é reconhecido pelo controle.  
  
 Você também pode usar `CanPaste` para determinar se qualquer formato disponível na área de transferência é reconhecido por um controle de edição sofisticado.  Essa função é útil no manipulador de `OnInitMenuPopup` .  Um aplicativo pode habilitar ou cinza o comando da pasta se o controle pode colar qualquer formato disponível.  
  
 Formatos sofisticada da área de transferência do registro de dois controles de edição: formato rich texto e formato chamado o texto e os objetos de RichEdit.  Um aplicativo pode registrar esses formatos usando a função de [RegisterClipboardFormat](http://msdn.microsoft.com/library/windows/desktop/ms649049) , especificando os valores de **CF\_RTF** e de **CF\_RETEXTOBJ** .  
  
## Consulte também  
 [Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)   
 [Controles](../mfc/controls-mfc.md)