---
title: "Gerenciador de visualiza&#231;&#227;o | Microsoft Docs"
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
  - "Gerenciador de visualização"
ms.assetid: c9dd1365-27ac-42e5-8caa-1004525b4129
caps.latest.revision: 13
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Gerenciador de visualiza&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O gerenciador visual é um objeto que controla a aparência de um aplicativo inteiro.  Atua como uma única classe onde você pode colocar qualquer código de desenho para seu aplicativo.  A biblioteca MFC inclui vários gerenciadores visuais.  Você também pode criar seu próprio gerenciador visual se você deseja criar uma exibição personalizada para seu aplicativo.  As imagens a seguir mostram o mesmo aplicativo quando os gerenciadores visuais diferentes são habilitados:  
  
 ![MyApp renderizado por CMFCVisualManagerWindows](../Image/VMWindows.png "VMWindows")  
MyApp usando o gerenciador de visual de CMFCVisualManagerWindows  
  
 ![MyApp renderizado por CMFCVisualManagerVS2005](../mfc/media/vmvs2005.png "VMVS2005")  
MyApp usando o gerenciador do visual CMFCVisualManagerVS2005  
  
 ![MyApp renderizado por CMFCVisualManagerOfficeXP](../mfc/media/vmofficexp.png "VMOfficeXP")  
MyApp usando o gerenciador de visual de CMFCVisualManagerOfficeXP  
  
 ![MyApp renderizado por CMFCVisualManagerOffice2003](../mfc/media/vmoffice2003.png "VMOffice2003")  
MyApp usando o gerenciador do visual CMFCVisualManagerOffice2003  
  
 ![MyApp renderizado por CMFCVisualManagerOffice2007](../mfc/media/msoffice2007.png "MSOffice2007")  
MyApp usando o gerenciador do visual CMFCVisualManagerOffice2007  
  
 Por padrão, o gerenciador visual mantém o código de desenho para vários elementos da interface gráfica do usuário.  Para fornecer os elementos personalizados de interface do usuário, é necessário substituir os métodos relacionados de desenho do visual.  Para a lista desses métodos, consulte [Classe de CMFCVisualManager](../mfc/reference/cmfcvisualmanager-class.md).  Os métodos que você pode substituir para fornecer uma aparência personalizado são todos os métodos que começam com `OnDraw`.  
  
 Seu aplicativo pode ter somente um objeto de `CMFCVisualManager` .  Para obter um ponteiro para o gerenciador visual para seu aplicativo, chame a função estática [CMFCVisualManager::GetInstance](../Topic/CMFCVisualManager::GetInstance.md).  Como todos os gerenciadores visuais herdam de `CMFCVisualManager`, o método de `CMFCVisualManager::GetInstance` obterá um ponteiro para o gerenciador visual apropriado, mesmo se você criar um gerenciador visual personalizado.  
  
 Se você quiser criar um gerenciador visual personalizado, deverá derivá\-lo de um gerenciador visual que já existe.  A classe padrão para derivar de é `CMFCVisualManager`.  Entretanto, você pode usar um gerenciador visual melhor diferente se assemelha ao que você deseja para seu aplicativo.  Por exemplo, se você quiser usar o gerenciador do visual `CMFCVisualManagerOffice2007` , mas desejado para alterar apenas como os separadores de tabela, você pode derivar sua classe personalizada de `CMFCVisualManagerOffice2007`.  Neste cenário, você deve substituir apenas os métodos para desenhar separadores.  
  
 Há duas maneiras possíveis de usar um gerenciador visual específico para seu aplicativo.  Um modo é chamar o método de [CMFCVisualManager::SetDefaultManager](../Topic/CMFCVisualManager::SetDefaultManager.md) e passe o gerenciador visual apropriado como um parâmetro.  O exemplo de código mostra como você usaria o gerenciador do visual `CMFCVisualManagerVS2005` com esse método:  
  
```  
CMFCVisualManager::SetDefaultManager (RUNTIME_CLASS (CMFCVisualManagerVS2005));  
```  
  
 Outra maneira de usar um gerenciador visual em seu aplicativo for criá\-la manualmente.  O aplicativo usará esse gerenciador visual para qualquer renderização.  No entanto, pois pode haver somente um objeto de `CMFCVisualManager` pelo aplicativo, você precisará excluir o gerenciador visual atual antes de criar um novo.  No exemplo a seguir, `CMyVisualManager` é um gerenciador visual personalizado que é derivado de `CMFCVisualManager`.  O método seguinte será alterado se o gerenciador visual é usado para exibir o aplicativo, dependendo de um índice:  
  
```  
void CMyApp::SetSkin (int index)  
{  
   if (CMFCVisualManager::GetInstance() != NULL)  
   {  
      delete CMFCVisualManager::GetInstance();  
   }  
  
   switch (index)  
   {  
   case DEFAULT_STYLE:  
      // The following statement creates a new CMFCVisualManager  
      CMFCVisualManager::GetInstance();  
      break;  
  
   case CUSTOM_STYLE:  
      new CMyVisualManager;  
      break;  
  
   default:  
      CMFCVisualManager::GetInstance();  
      break;  
   }  
  
   CMFCVisualManager::GetInstance()->RedrawAll();  
}  
```  
  
## Consulte também  
 [Elementos da interface do usuário](../mfc/user-interface-elements-mfc.md)   
 [Classe de CMFCVisualManager](../mfc/reference/cmfcvisualmanager-class.md)