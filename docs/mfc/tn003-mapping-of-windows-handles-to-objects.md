---
title: "TN003: mapeamento de identificadores do Windows para objetos | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.mapping"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "mapas de identificador"
  - "mapeamentos, manipuladores do Windows para objetos"
  - "TN003"
  - "manipuladores do Windows para objetos [C++]"
ms.assetid: fbea9f38-992c-4091-8dbc-f29e288617d6
caps.latest.revision: 15
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN003: mapeamento de identificadores do Windows para objetos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Essa observação descreve as rotinas de MFC que dão suporte a identificadores de objeto do windows do para objetos C\+\+.  
  
## O problema  
 Os objetos do windows geralmente são representados por vários objetos de [ALÇA](http://msdn.microsoft.com/library/windows/desktop/aa383751) os identificadores de objeto do windows da quebra automática das classes MFC com C\+\+ objeto.  O identificador que envolve funções da biblioteca MFC da classe permite localizar o objeto do C\+\+ que está encapsulando o objeto que tem um identificador específico.  No entanto, às vezes um objeto não tiver o objeto de wrapper c criando e essas hora do sistema cria um objeto temporário para atuar como o wrapper C\+\+.  
  
 O objeto que os mapas do identificador de uso são os seguintes:  
  
-   HWND \([CWnd](../Topic/CWnd%20Class.md) e `CWnd`\- classes derivadas\)  
  
-   HDC \([CDC](../Topic/CDC%20Class.md) e `CDC`\- classes derivadas\)  
  
-   HMENU \([CMenu](../mfc/reference/cmenu-class.md)\)  
  
-   HPEN \([CGdiObject](../mfc/reference/cgdiobject-class.md)\)  
  
-   HBRUSH \(`CGdiObject`\)  
  
-   HFONT \(`CGdiObject`\)  
  
-   HBITMAP \(`CGdiObject`\)  
  
-   HPALETTE \(`CGdiObject`\)  
  
-   HRGN \(`CGdiObject`\)  
  
-   HIMAGELIST \([CImageList](../Topic/CImageList%20Class.md)\)  
  
-   SOQUETE \([CSocket](../mfc/reference/csocket-class.md)\)  
  
 Um identificador atribuído a qualquer um desses objetos, você pode localizar o objeto de MFC que encapsula o identificador chamando o método estático `FromHandle`.  Por exemplo, em um HWND chamou `hWnd`, a linha a seguir retornará um ponteiro para `CWnd` que encapsula `hWnd`:  
  
```  
CWnd::FromHandle(hWnd)  
```  
  
 Se `hWnd` não tem um objeto específico de wrapper, `CWnd` temporário será criado para envolver `hWnd`.  Isso possibilita fazer um objeto válido C\+\+ de qualquer identificador.  
  
 Depois que você tiver um objeto de wrapper, você pode recuperar seu identificador de uma variável pública do membro da classe de invólucro.  No caso de `CWnd`, `m_hWnd` contém o HWND para esse objeto.  
  
## Anexando identificadores para objetos MFC  
 Dado um objeto recém\-criado alça\- de invólucro e um identificador para o objeto, você pode associar os dois chamando a função de `Attach` como neste exemplo:  
  
```  
CWnd myWnd;  
myWnd.Attach(hWnd);  
```  
  
 Isso torna uma entrada no mapa permanente que associa `myWnd` e `hWnd`.  A chamada `CWnd::FromHandle(hWnd)` retornará agora um ponteiro para `myWnd`.  Quando `myWnd` é excluído, o destruidor destruirá automaticamente `hWnd` chamando a função de [DestroyWindow](http://msdn.microsoft.com/library/windows/desktop/ms632682) do windows.  Se isso não for desejado, `hWnd` deve ser desanexado de `myWnd` antes de `myWnd` ser destruído \(normalmente deixando o escopo em que `myWnd` estiver definido\).  O método de `Detach` faz isso.  
  
```  
myWnd.Detach();  
```  
  
## Mais objetos temporários  
 Os objetos temporários são criados sempre que `FromHandle` é fornecido um identificador que não tem um objeto do wrapper.  Esses objetos temporários são desanexados de seu identificador e excluídos por funções de `DeleteTempMap` .  Por padrão [CWinThread::OnIdle](../Topic/CWinThread::OnIdle.md) chama automaticamente `DeleteTempMap` para cada classe que oferece suporte a mapas temporários do identificador.  Isso significa que você não pode assumir um ponteiro para um objeto temporário será válida após o ponto de saída da função onde o ponteiro foi obtido.  
  
## Objetos de invólucro e vários threads  
 Os objetos temporários e permanentes são mantidos em uma base por thread.  Isto é, um thread não pode acessar objetos de wrapper de C\+\+ de outro thread, independentemente de se é temporário ou permanente.  
  
 Para passar esses objetos de um thread para outro, envie sempre como seu tipo nativo de `HANDLE` .  Passe o objeto de wrapper c criando de um thread para outro fará com que frequência resultados inesperados.  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)