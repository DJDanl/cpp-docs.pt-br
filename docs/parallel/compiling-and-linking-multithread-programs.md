---
title: Compilando e vinculando programas Multithread | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- compiling multithreaded programs
- multithreading [C++], linking programs
- threading [C++], linking programs
- multithreading [C++], compiled programs
- threading [C++], compiled programs
- compiling source code [C++], multithread programs
- linking [C++], multithread programs
ms.assetid: 27589afc-daf2-4f26-b868-a99de5c9dfec
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7d9dcb1d7cbda7eebcede4d25de276948d638034
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46412919"
---
# <a name="compiling-and-linking-multithread-programs"></a>Compilando e vinculando programas multithread

O programa de Bounce é introduzido no [programa de C Multithread de exemplo](sample-multithread-c-program.md).

Programas são compilados com multithread por padrão.

### <a name="to-compile-and-link-the-multithread-program-bouncec-from-within-the-development-environment"></a>Para compilar e vincular o programa multithread Bounce de dentro do ambiente de desenvolvimento

1. No menu **Arquivo**, clique em **Novo** e clique em **Projeto**.

1. No **tipos de projeto** painel, clique em **Win32**.

1. No **modelos** painel, clique em **aplicativo de Console Win32**e, em seguida, nomeie o projeto.

1. Adicione o arquivo que contém o código-fonte C para o projeto.

1. No **compilar** menu, compile o projeto clicando o **Build** comando.

### <a name="to-compile-and-link-the-multithread-program-bouncec-from-the-command-line"></a>Para compilar e vincular o programa multithread Bounce da linha de comando

1. Compilar e vincular o programa:

    ```
    CL BOUNCE.C
    ```

## <a name="see-also"></a>Consulte também

[Multithreading com C e Win32](multithreading-with-c-and-win32.md)