---
title: "Como implementar o acompanhamento no c&#243;digo | Microsoft Docs"
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
  - "Classe CRectTracker, implementando controladores"
ms.assetid: baaeca2c-5114-485f-bf58-8807db1bc973
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como implementar o acompanhamento no c&#243;digo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para rastrear um item OLE, você deve tratar certos eventos relacionados ao item, como clique no item ou atualize a exibição do documento.  Em todos os casos, é suficiente para declarar um objeto temporário de [CRectTracker](../mfc/reference/crecttracker-class.md) e manipular o item por meio deste objeto.  
  
 Quando um usuário seleciona um item ou insere um objeto de um comando de menu, você deve inicializar o controlador com os estilos apropriados para representar o estado do item OLE.  A tabela a seguir descreve as convenções usadas pelo exemplo de OCLIENT.  Para obter mais informações sobre esses estilos, consulte `CRectTracker`.  
  
### Estilos do contêiner e estados de item OLE  
  
|Estilo exibido|Estado de item OLE|  
|--------------------|------------------------|  
|Pontilhada borda|O item está vinculado|  
|Contínua borda|O item é inserido no documento|  
|As alças de redimensionamento|O item selecionado no momento|  
|A borda chocada|O item está atualmente ativo in\-loco|  
|O padrão de hachura será interrompido o item|O servidor do item está aberto|  
  
 Você pode controlar essa inicialização que usa facilmente um procedimento que verifica o estado do item OLE e define os estilos apropriadas.  A função de **SetupTracker** localizada no exemplo de OCLIENT demonstra a inicialização do controlador.  Os parâmetros para essa função é o endereço do controlador, *pTracker*; um ponteiro para o item que está relacionada ao controlador, `pItem`de cliente; e um ponteiro para um retângulo, *pTrueRect*.  Para um mais o exemplo completo dessa função, consulte o exemplo [OCLIENT](../top/visual-cpp-samples.md)MFC OLE.  
  
 O exemplo de código de **SetupTracker** apresenta uma única função; as linhas da função são intercaladas com auditoria dos recursos da função:  
  
 [!code-cpp[NVC_MFCOClient#1](../mfc/codesnippet/CPP/how-to-implement-tracking-in-your-code_1.cpp)]  
  
 O controlador é inicializado definindo o tamanho mínimo e limpando o estilo do controlador.  
  
 [!code-cpp[NVC_MFCOClient#2](../mfc/codesnippet/CPP/how-to-implement-tracking-in-your-code_2.cpp)]  
  
 As seguintes linhas verificação para verificar se o item está selecionado no momento e se o item está vinculado ao documento ou inserido nele.  Redimensionar as alças posicionados no interior da borda são adicionados ao estilo, indicando que o item está selecionado no momento.  Se o item está vinculado ao documento, pontilhado o estilo da borda é usado.  Uma borda sólida é usada se o item é inserido.  
  
 [!code-cpp[NVC_MFCOClient#3](../mfc/codesnippet/CPP/how-to-implement-tracking-in-your-code_3.cpp)]  
  
 O seguinte código será interrompido o item com um padrão chocado se o item está atualmente aberto.  
  
 [!code-cpp[NVC_MFCOClient#4](../mfc/codesnippet/CPP/how-to-implement-tracking-in-your-code_4.cpp)]  
  
 Você pode chamar essa função sempre que o controlador tem que ser exibido.  Por exemplo, chamar essa função da função de `OnDraw` da sua classe da exibição.  Isso atualiza a aparência do controlador sempre que a exibição é repintada.  Para obter um exemplo completo, consulte a função de **CMainView::OnDraw** de exemplo [OCLIENT](../top/visual-cpp-samples.md)MFC OLE.  
  
 Em seu aplicativo, os eventos que exigem o código do controlador, como redimensionar, se movendo, ou a ocorrência que detecta, ocorrerão.  Essas ações geralmente indicam que uma tentativa está sendo feita capture ou mover o item.  Nesses casos, você precisará optar entre o que foi agarrado: um identificador redimensionar ou parte da borda entre os identificadores são redimensionados.  O manipulador de mensagens de `OnLButtonDown` é uma boa fonte para testar a posição do mouse em relação ao item.  Chame um a `CRectTracker::HitTest`.  Se o teste retorna algo além de **CRectTracker::hitOutside**, o item está sendo redimensionado ou movido.  Em virtude disso, você deve fazer uma chamada à função de membro de `Track` .  Consulte a função de **CMainView::OnLButtonDown** localizada no exemplo [OCLIENT](../top/visual-cpp-samples.md) MFC OLE para obter um exemplo completo.  
  
 A classe de `CRectTracker` o fornece várias formas diferentes de cursor usadas para indicar se um mover, redimensionar ou, a operação de arrastamento está ocorrendo.  Para tratar esse evento, verifique se o item sob o mouse está selecionado no momento.  Se for, faça uma chamada a `CRectTracker::SetCursor`, ou chame o manipulador padrão.  O exemplo a seguir é de exemplo [OCLIENT](../top/visual-cpp-samples.md)MFC OLE:  
  
 [!code-cpp[NVC_MFCOClient#5](../mfc/codesnippet/CPP/how-to-implement-tracking-in-your-code_5.cpp)]  
  
## Consulte também  
 [Controladores: implementando controladores no aplicativo OLE](../mfc/trackers-implementing-trackers-in-your-ole-application.md)