---
title: "Implementando uma janela com CWindowImpl | Microsoft Docs"
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
  - "CWindowImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ATL, o windows"
  - "classes subclassing da janela de ATL"
  - "superclassing, ATL"
  - "windows [C++], ATL"
  - "windows [C++], subclassing"
  - "windows [C++], superclassing"
ms.assetid: 3fc40550-f1d6-4702-8b7c-4cf682b6a855
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Implementando uma janela com CWindowImpl
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para implementar uma janela, derive uma classe de `CWindowImpl`.  Em sua classe derivada, declare um mapa de mensagem e funções do manipulador de mensagem.  Agora você pode usar a classe em três diferentes maneiras:  
  
-   [Crie uma janela com base em uma classe do windows](#_atl_creating_a_window_based_on_a_new_windows_class)  
  
-   [Superclass uma classe existente do windows](#_atl_superclassing_an_existing_windows_class)  
  
-   [Subclasse uma janela existente](#_atl_subclassing_an_existing_window)  
  
##  <a name="_atl_creating_a_window_based_on_a_new_windows_class"></a> Criando uma janela com base em uma classe do windows  
 `CWindowImpl` contém a macro de [DECLARE\_WND\_CLASS](../Topic/DECLARE_WND_CLASS.md) para declarar informações de classe do windows.  Este macro implementa a função de `GetWndClassInfo` , que usa [CWndClassInfo](../atl/reference/cwndclassinfo-class.md) para definir informações de uma classe do windows.  Quando `CWindowImpl::Create` é chamado, essa classe do windows é registrada e uma nova janela é criada.  
  
> [!NOTE]
>  `CWindowImpl` passa **NULO** a macro de `DECLARE_WND_CLASS` , que significa que ATL gerará um nome de classe do windows.  Para especificar seu próprio nome, passe uma cadeia de caracteres a `DECLARE_WND_CLASS` em seu `CWindowImpl`\- classe derivada.  
  
## Exemplo  
 A seguir está um exemplo de uma classe que implementa uma janela com base em uma classe do windows:  
  
 [!code-cpp[NVC_ATL_Windowing#64](../atl/codesnippet/CPP/implementing-a-window-with-cwindowimpl_1.h)]  
  
 Para criar uma janela, crie uma instância de `CMyWindow` e então chame o método de **Criar** .  
  
> [!NOTE]
>  Para substituir as janelas de opção classe informações, implementam o método de `GetWndClassInfo` em sua classe derivada definindo os membros de `CWndClassInfo` para valores apropriados.  
  
##  <a name="_atl_superclassing_an_existing_windows_class"></a> Superclassing uma classe existente do windows  
 A macro de [DECLARE\_WND\_SUPERCLASS](../Topic/DECLARE_WND_SUPERCLASS.md) permite que você crie uma janela que os superclasses forms existentes classifiquem.  Especificar este macro em seu `CWindowImpl`\- classe derivada.  Como qualquer outra janela de ATL, as mensagens são tratadas por um mapa de mensagem.  
  
 Quando você usa `DECLARE_WND_SUPERCLASS`, uma classe do windows estará registrado.  Essa nova classe será a mesma como a classe existente você especifica, mas substituirá o procedimento de janela com `CWindowImpl::WindowProc` \(ou com sua função que substitui esse método\).  
  
## Exemplo  
 A seguir está um exemplo de uma classe que superclasses a classe padrão de edição:  
  
 [!code-cpp[NVC_ATL_Windowing#65](../atl/codesnippet/CPP/implementing-a-window-with-cwindowimpl_2.h)]  
  
 Para criar a janela superclassed de edição, crie uma instância de `CMyEdit` e então chame o método de **Criar** .  
  
##  <a name="_atl_subclassing_an_existing_window"></a> Subclassing uma janela existente  
 Subclasse para uma janela existente, uma classe derivada de `CWindowImpl` e declara um mapa de mensagem, como os dois casos anteriores.  Observe, entretanto, que você não especificar quaisquer informações da classe do windows, desde que você subclasse uma janela já existente.  
  
 Em vez de chamar **Criar**, chame `SubclassWindow` e passe a alça a janela existente que você deseja fazer subclassing.  Uma vez que a janela tem sido derivado, usará `CWindowImpl::WindowProc` \(ou sua função que substitui esse método\) para direcionar mensagens ao mapa de mensagem.  Para desanexar uma janela tem sido derivado do objeto, chame `UnsubclassWindow`.  O procedimento de janela original da janela será restaurado em.  
  
## Consulte também  
 [Implementando uma janela](../atl/implementing-a-window.md)