---
title: Gerenciador de visualização | Microsoft Docs
ms.custom: ''
ms.date: 06/28/2018
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
ms.openlocfilehash: fce4b036c6a6ae3692353ae02e7d36eb5ddfd1e1
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46398476"
---
# <a name="visualization-manager"></a>Gerenciador de visualização

O Gerenciador visual é um objeto que controla a aparência de todo o aplicativo. Ele atua como uma única classe em que você pode colocar todo o código de desenho para seu aplicativo. A biblioteca MFC inclui vários gerenciadores de visual. Você também pode criar seu próprio Gerenciador visual se você quiser criar uma exibição personalizada para seu aplicativo. As imagens a seguir mostram o mesmo aplicativo quando os diferentes gerentes visuais estão habilitados:

![MyApp conforme renderizado pelo CMFCVisualManagerWindows](../mfc/media/vmwindows.png "vmwindows") MyApp que usa o Gerenciador de visual CMFCVisualManagerWindows

![MyApp conforme renderizado pelo CMFCVisualManagerVS2005](../mfc/media/vmvs2005.png "vmvs2005") MyApp que usa o Gerenciador de visual CMFCVisualManagerVS2005

![MyApp conforme renderizado pelo CMFCVisualManagerOfficeXP](../mfc/media/vmofficexp.png "vmofficexp") MyApp que usa o Gerenciador de visual CMFCVisualManagerOfficeXP

![MyApp conforme renderizado pelo CMFCVisualManagerOffice2003](../mfc/media/vmoffice2003.png "vmoffice2003") MyApp que usa o Gerenciador de visual CMFCVisualManagerOffice2003

![MyApp conforme renderizado pelo CMFCVisualManagerOffice2007](../mfc/media/msoffice2007.png "msoffice2007") MyApp que usa o Gerenciador de visual CMFCVisualManagerOffice2007

Por padrão, o Gerenciador visual mantém o código de desenho para vários elementos de interface gráfica do usuário. Para fornecer elementos de interface do usuário personalizados, você precisa substituir os métodos de desenho relacionados do Gerenciador visual. Para obter a lista desses métodos, consulte [classe CMFCVisualManager](../mfc/reference/cmfcvisualmanager-class.md). Os métodos que você pode substituir para fornecer uma aparência personalizada são todos os métodos que começam com `OnDraw`.

Seu aplicativo pode ter apenas um `CMFCVisualManager` objeto. Para obter um ponteiro para o Gerenciador visual para seu aplicativo, chame a função estática [CMFCVisualManager::GetInstance](../mfc/reference/cmfcvisualmanager-class.md#getinstance). Como todos os gerenciadores de visual herdam de `CMFCVisualManager`, o `CMFCVisualManager::GetInstance` método receberá um ponteiro para o Gerenciador visual apropriado, mesmo se você criar um Gerenciador de visual personalizado.

Se você quiser criar um Gerenciador de visual personalizado, você deve derivá-lo de um gerente que já existe. A classe derive de padrão é `CMFCVisualManager`. No entanto, você pode usar um Gerenciador de visual diferente se lembra melhor o que você deseja para seu aplicativo. Por exemplo, se você quiser usar o `CMFCVisualManagerOffice2007` Gerenciador visual, mas queria apenas alterar a aparência de separadores, você pode derivar sua classe personalizada de `CMFCVisualManagerOffice2007`. Nesse cenário, você deve substituir apenas os métodos para desenhar separadores.

Há duas maneiras possíveis de usar um Gerenciador visual específico para seu aplicativo. É uma maneira de chamar o [CMFCVisualManager::](../mfc/reference/cmfcvisualmanager-class.md#setdefaultmanager) método e passar o Gerenciador visual apropriado como parâmetro. O exemplo de código a seguir mostra como você usaria o `CMFCVisualManagerVS2005` Gerenciador visual com esse método:

```cpp
CMFCVisualManager::SetDefaultManager (RUNTIME_CLASS (CMFCVisualManagerVS2005));
```

A outra maneira de usar um Gerenciador de visual em seu aplicativo é criá-lo manualmente. O aplicativo, em seguida, usará esse novo Gerenciador visual para todas as a renderização. No entanto, porque pode haver apenas um `CMFCVisualManager` objeto por aplicativo, você precisará excluir o Gerenciador visual atual antes de criar um novo. No exemplo a seguir `CMyVisualManager` é um Gerenciador de visual personalizado que é derivado de `CMFCVisualManager`. O método a seguir alterará o Gerenciador visual usado para exibir seu aplicativo, dependendo de um índice:

```cpp
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

## <a name="see-also"></a>Consulte também

[Elementos da Interface do usuário](../mfc/user-interface-elements-mfc.md)<br/>
[Classe CMFCVisualManager](../mfc/reference/cmfcvisualmanager-class.md)
