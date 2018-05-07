---
title: Gerenciador de visualização | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Visualization Manager
ms.assetid: c9dd1365-27ac-42e5-8caa-1004525b4129
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 40d16e1373d347b4a715cd6f073211796913bd21
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="visualization-manager"></a>Gerenciador de visualização
O Gerenciador de visual é um objeto que controla a aparência de um aplicativo inteiro. Ele atua como uma única classe onde você pode colocar todo o código de desenho para seu aplicativo. A biblioteca do MFC inclui vários gerenciadores de visual. Se você quiser criar uma exibição personalizada para seu aplicativo, você também pode criar seu próprio Gerenciador de visual. As imagens a seguir mostram o mesmo aplicativo quando diferentes gerenciadores visuais estão habilitados:  
  
 ![MyApp quando processado por CMFCVisualManagerWindows](../mfc/media/vmwindows.png "vmwindows")  
MyApp que usa o Gerenciador de visual CMFCVisualManagerWindows  
  
 ![MyApp quando processado por CMFCVisualManagerVS2005](../mfc/media/vmvs2005.png "vmvs2005")  
MyApp que usa o Gerenciador de visual CMFCVisualManagerVS2005  
  
 ![MyApp quando processado por CMFCVisualManagerOfficeXP](../mfc/media/vmofficexp.png "vmofficexp")  
MyApp que usa o Gerenciador de visual CMFCVisualManagerOfficeXP  
  
 ![MyApp quando processado por CMFCVisualManagerOffice2003](../mfc/media/vmoffice2003.png "vmoffice2003")  
MyApp que usa o Gerenciador de visual CMFCVisualManagerOffice2003  
  
 ![MyApp quando processado por CMFCVisualManagerOffice2007](../mfc/media/msoffice2007.png "msoffice2007")  
MyApp que usa o Gerenciador de visual CMFCVisualManagerOffice2007  
  
 Por padrão, o Gerenciador de visual mantém o código de desenho de vários elementos de interface gráfica do usuário. Para fornecer elementos de interface do usuário personalizados, você precisa substituir os métodos de desenho relacionados do Gerenciador de visual. Para obter a lista desses métodos, consulte [CMFCVisualManager classe](../mfc/reference/cmfcvisualmanager-class.md). Os métodos que você pode substituir para fornecer uma aparência personalizada são todos os métodos que começam com `OnDraw`.  
  
 O aplicativo pode ter apenas um `CMFCVisualManager` objeto. Para obter um ponteiro para o Gerenciador de visual para o seu aplicativo, chame a função estática [CMFCVisualManager::GetInstance](../mfc/reference/cmfcvisualmanager-class.md#getinstance). Como todos os gerenciadores de visual herdam de `CMFCVisualManager`, o `CMFCVisualManager::GetInstance` método obter um ponteiro para o gerente visual, mesmo se você criar um Gerenciador de visual personalizado.  
  
 Se você quiser criar um Gerenciador de visual personalizado, ele deve ser derivado de um Gerenciador de visual que já existe. A classe padrão derivar é `CMFCVisualManager`. No entanto, você pode usar um Gerenciador de visual diferente se lembra melhor o que você deseja para seu aplicativo. Por exemplo, se você quiser usar o `CMFCVisualManagerOffice2007` visual gerente, mas queira apenas alterar a aparência dos separadores, você pode derivar de sua classe personalizada de `CMFCVisualManagerOffice2007`. Nesse cenário, você deve substituir apenas os métodos para desenhar separadores.  
  
 Há duas maneiras de usar um Gerenciador de visual específico para seu aplicativo. É uma maneira chamar o [CMFCVisualManager:: SetDefaultManager](../mfc/reference/cmfcvisualmanager-class.md#setdefaultmanager) método e o gerente de visual como um parâmetro de passagem. O exemplo de código a seguir mostra como você usaria o `CMFCVisualManagerVS2005` manager visual com este método:  
  
```  
CMFCVisualManager::SetDefaultManager (RUNTIME_CLASS (CMFCVisualManagerVS2005));
```  
  
 A outra maneira de usar um Gerenciador de visual em seu aplicativo é criá-lo manualmente. O aplicativo, em seguida, usará este novo Gerenciador de visual para todo o processamento. No entanto, como pode haver apenas um `CMFCVisualManager` objeto por aplicativo, você terá que excluir o Gerenciador de visual atual antes de criar um novo. No exemplo a seguir, `CMyVisualManager` é um Gerenciador de visual personalizado que é derivado de `CMFCVisualManager`. O método a seguir alterará o Gerenciador visual é usado para exibir seu aplicativo, dependendo de um índice:  
  
```  
void CMyApp::SetSkin (int index)  
{  
    if (CMFCVisualManager::GetInstance() != NULL)  
 {  
    delete CMFCVisualManager::GetInstance();

 }  
 
    switch (index)  
 {  
    case DEFAULT_STYLE: *// The following statement creates a new CMFCVisualManager  
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
  
## <a name="see-also"></a>Consulte também  
 [Elementos da Interface do usuário](../mfc/user-interface-elements-mfc.md)   
 [Classe CMFCVisualManager](../mfc/reference/cmfcvisualmanager-class.md)
