---
title: Registrando classes de janela
ms.date: 11/04/2016
f1_keywords:
- WndProc
helpviewer_keywords:
- window classes [MFC], registering
- registry [MFC], registering classes
- AfxRegisterWndClass method [MFC]
- MFC, windows
- WinMain method [MFC], and registering window classes
- WndProc method [MFC]
- classes [MFC], registering window classes
- WinMain method [MFC]
- registering window classes [MFC]
ms.assetid: 30994bc4-a362-43da-bcc5-1bf67a3fc929
ms.openlocfilehash: c1fc6628b2b5e8e6fa657f4cf99be2256377a5b1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50540576"
---
# <a name="registering-window-classes"></a>Registrando classes de janela

Janela "classes" na programação tradicional para Windows definem as características de uma "class" (não uma classe do C++) do que qualquer número de janelas pode ser criado. Esse tipo de classe é um modelo ou um modelo para a criação do windows.

## <a name="window-class-registration-in-traditional-programs-for-windows"></a>Registro de classe de janela em programas tradicionais para Windows

Um programa tradicional do Windows, sem MFC, você processa todas as mensagens para uma janela em seu procedimento de janela"" ou "`WndProc`." Um `WndProc` está associado uma janela por meio de um processo de "registro da classe window". A janela principal é registrada no `WinMain` função, mas outras classes do windows podem ser registrado em qualquer lugar no aplicativo. Registro depende de uma estrutura que contém um ponteiro para o `WndProc` funcionar junto com as especificações para o cursor, o pincel do plano de fundo e assim por diante. A estrutura é passada como um parâmetro, junto com o nome de cadeia de caracteres da classe, em uma chamada anterior para o `RegisterClass` função. Portanto, uma classe de registro pode ser compartilhada por várias janelas.

## <a name="window-class-registration-in-mfc-programs"></a>Registro de classe de janela em programas MFC

Por outro lado, a maioria das atividades de registro de classe de janela é feito automaticamente em um programa de estrutura MFC. Se você estiver usando o MFC, você normalmente derivar uma classe de janela C++ de uma classe de biblioteca existente usando a sintaxe de C++ normal para herança de classe. A estrutura ainda usa tradicional "classes de registro" e fornece vários manipuladores padrão, registrado para você quando necessário. Você pode registrar as classes de registro adicionais por meio da chamada a [AfxRegisterWndClass](../mfc/reference/application-information-and-management.md#afxregisterwndclass) função global e, em seguida, passando a classe registrada para o `Create` a função de membro de `CWnd`. Conforme descrito aqui, o tradicional "classe de registro" no Windows não é deve ser confundido com uma classe C++.

Para obter mais informações, consulte [técnico Observação 1](../mfc/tn001-window-class-registration.md).

## <a name="see-also"></a>Consulte também

[Criando janelas](../mfc/creating-windows.md)

