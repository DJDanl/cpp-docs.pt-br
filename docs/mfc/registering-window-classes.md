---
title: "Registrando classes de janela | Microsoft Docs"
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
  - "WndProc"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método AfxRegisterWndClass"
  - "classes [C++], registrando classes de janela"
  - "MFC, janelas"
  - "registrando classes de janela"
  - "registro, registrando classes"
  - "classes de janela, registrando"
  - "Método WinMain"
  - "Método WinMain, e registrando classes de janela"
  - "Método WndProc"
ms.assetid: 30994bc4-a362-43da-bcc5-1bf67a3fc929
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Registrando classes de janela
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A janela “classificar” na programação tradicional para o windows definem as características de uma classe “” \(não classe criando c\) que qualquer número do windows pode ser criado.  Esse tipo de classe é um modelo ou um modelo para criar o windows.  
  
## Registro da classe de janela em programas tradicionais para o windows  
 Em um programa tradicional no windows, sem MFC, você processa todas as mensagens em uma janela no procedimento “de janela” ou “em**WndProc**”. **WndProc** é associado a uma janela de “por meio de um processo de registro da classe janela”.  A janela principal é registrada na função de `WinMain` , mas outras classes do windows podem ser registradas em qualquer lugar no aplicativo.  O registro depende de uma estrutura que contém um ponteiro para a função de **WndProc** junto com as especificações do cursor, escova em segundo plano, e assim por diante.  A estrutura é passado como um parâmetro, junto com o nome da cadeia de caracteres da classe, em uma chamada anterior à função de **RegisterClass** .  Portanto, uma classe do registro pode ser compartilhada por várias janelas.  
  
## Registro da classe de janela em programas MFC  
 Em contraste, a maior parte da atividade de registro da classe da janela é estabelecida automaticamente em um programa\-quadro MFC.  Se você estiver usando o MFC, você normalmente a classe deriva da janela c criando de uma classe existente na biblioteca que usa a sintaxe normal C\+\+ para herança da classe.  A estrutura ainda usa “classes tradicionais,” registro e fornece vários padrões as registrado para você, quando necessário.  Você pode registrar classes adicionais do registro chamando [AfxRegisterWndClass](../Topic/AfxRegisterWndClass.md) função global e depois passando a classe registrada à função de membro de **Criar** de `CWnd`.  Como descrito aqui, a “classe tradicional registro” no windows não deve ser ofuscada com a classe c. criando  
  
 Para obter mais informações, consulte [Observação 1 técnica](../mfc/tn001-window-class-registration.md).  
  
## Consulte também  
 [Criando janelas](../Topic/Creating%20Windows.md)