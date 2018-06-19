---
title: 'TN003: Mapeamento do Windows identificadores de objetos | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.mapping
dev_langs:
- C++
helpviewer_keywords:
- TN003
- handle maps
- Windows handles to objects [MFC]
- mappings [MFC], Windows handles to objects
ms.assetid: fbea9f38-992c-4091-8dbc-f29e288617d6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bc8658868c36008c5ed6b9db9747eb63ae37e4d2
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33382967"
---
# <a name="tn003-mapping-of-windows-handles-to-objects"></a>TN003: mapeamento de identificadores do Windows para objetos
Esta anotação descreve o MFC rotinas que dão suporte a mapeamento Windows identificadores de objetos C++ do objeto.  
  
## <a name="the-problem"></a>O problema  
 Objetos do Windows geralmente são representados por vários [tratar](http://msdn.microsoft.com/library/windows/desktop/aa383751) objetos classes MFC a encapsular identificadores de objeto do Windows com objetos C++. O identificador de quebra automática de funções da biblioteca de classes MFC permitem que você localizar o objeto de C++ que está encapsulando o objeto do Windows que tem um identificador específico. No entanto, às vezes, um objeto não tem um objeto wrapper de C++ e horários, o sistema cria um objeto temporário para atuar como o wrapper de C++.  
  
 Os objetos do Windows que usam mapas de identificador são da seguinte maneira:  
  
-   HWND ([CWnd](../mfc/reference/cwnd-class.md) e `CWnd`-classes derivadas)  
  
-   HDC ([CDC](../mfc/reference/cdc-class.md) e `CDC`-classes derivadas)  
  
-   HMENU ([CMenu](../mfc/reference/cmenu-class.md))  
  
-   HPEN ([CGdiObject](../mfc/reference/cgdiobject-class.md))  
  
-   HBRUSH (`CGdiObject`)  
  
-   HFONT (`CGdiObject`)  
  
-   HBITMAP (`CGdiObject`)  
  
-   HPALETTE (`CGdiObject`)  
  
-   HRGN (`CGdiObject`)  
  
-   HIMAGELIST ([CImageList](../mfc/reference/cimagelist-class.md))  
  
-   SOQUETE ([CSocket](../mfc/reference/csocket-class.md))  
  
 Dado um identificador para qualquer um desses objetos, você pode localizar o objeto MFC que encapsula o identificador chamando o método estático `FromHandle`. Por exemplo, dado um HWND chamado `hWnd`, a linha a seguir retorna um ponteiro para o `CWnd` que encapsula `hWnd`:  
  
```  
CWnd::FromHandle(hWnd)  
```  
  
 Se `hWnd` não tem um objeto wrapper específico, um temporário `CWnd` é criado para encapsular `hWnd`. Isso torna possível obter um objeto válido do C++ de qualquer identificador.  
  
 Depois que você tiver um objeto wrapper, você pode recuperar seu identificador de uma variável de membro público da classe wrapper. No caso de um `CWnd`, `m_hWnd` contém o HWND para esse objeto.  
  
## <a name="attaching-handles-to-mfc-objects"></a>Anexando identificadores de objetos MFC  
 Dado um objeto recém-criado de wrapper de identificador e um identificador para um objeto do Windows, você pode associar as duas chamando o `Attach` funcionar como neste exemplo:  
  
```  
CWnd myWnd;  
myWnd.Attach(hWnd);
```  
  
 Isso faz com que uma entrada na associação de mapa permanente `myWnd` e `hWnd`. Chamando `CWnd::FromHandle(hWnd)` agora irá retornar um ponteiro para `myWnd`. Quando `myWnd` é excluído, o destruidor automaticamente destruirá `hWnd` chamando o Windows [DestroyWindow](http://msdn.microsoft.com/library/windows/desktop/ms632682) função. Se isso não for desejado, `hWnd` deve ser desanexado de `myWnd` antes de `myWnd` é destruído (normalmente ao sair do escopo no qual `myWnd` foi definido). O `Detach` método faz isso.  
  
```  
myWnd.Detach();
```  
  
## <a name="more-about-temporary-objects"></a>Mais informações sobre objetos temporários  
 Objetos temporários são criados sempre que `FromHandle` recebe um identificador que ainda não tiver um objeto wrapper. Esses objetos temporários são desanexados de seu identificador e excluídos pelo `DeleteTempMap` funções. Por padrão [CWinThread::OnIdle](../mfc/reference/cwinthread-class.md#onidle) chama automaticamente `DeleteTempMap` para cada classe que dá suporte a mapas de identificador temporário. Isso significa que você não pode assumir que um ponteiro para um objeto temporário será válido após o ponto de saída da função de onde o ponteiro foi obtido.  
  
## <a name="wrapper-objects-and-multiple-threads"></a>Objetos wrapper e vários Threads  
 Objetos temporários e permanentes são mantidos em uma base por thread. Ou seja, um thread não pode acessar objetos de wrapper de C++ do outro thread, independentemente de ser temporária ou permanente.  
  
 Para passar esses objetos de um thread para outro, sempre enviá-los como seu nativo `HANDLE` tipo. Passando um objeto wrapper de C++ de um thread para outro geralmente causará resultados inesperados.  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

