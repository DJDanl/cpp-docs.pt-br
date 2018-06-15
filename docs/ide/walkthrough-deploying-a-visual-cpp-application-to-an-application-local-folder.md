---
title: Implantar um aplicativo do Visual C++ em uma pasta local do aplicativo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- deploying Visual C++ applications
ms.assetid: 47a81c47-9dbe-47c6-96cc-fbb2fda5e6ad
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9a02e585dc2b82c8b8ad675907e4205db6ad7279
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2018
ms.locfileid: "33337903"
---
# <a name="walkthrough-deploying-a-visual-c-application-to-an-application-local-folder"></a>Instruções passo a passo: implantando um aplicativo do Visual C++ em uma pasta local do aplicativo
Descreve como implantar um aplicativo do Visual C++ copiando arquivos para sua pasta.  
  
## <a name="prerequisites"></a>Pré-requisitos  
  
-   Um computador que tenha o Visual Studio instalado.  
  
-   Outro computador que não tenha as bibliotecas do Visual C++.  
  
### <a name="to-deploy-an-application-to-an-application-local-folder"></a>Para implantar um aplicativo em uma pasta local do aplicativo  
  
1.  Crie e compile um aplicativo MFC seguindo as etapas de [Passo a passo: Implantando um aplicativo do Visual C++ usando um projeto de instalação](../ide/walkthrough-deploying-a-visual-cpp-application-by-using-a-setup-project.md).  
  
2.  Copie os arquivos de biblioteca MFC e CRT (C Run-Time) apropriados – por exemplo, para uma plataforma x86 e suporte a Unicode, copie mfc100u.dll e msvcr100.dll de \Arquivos de Programas\Microsoft Visual Studio 10.0\VC\redist\x86\ – e, em seguida, cole-os na pasta \Release\ do projeto MFC. Para obter mais informações sobre outros arquivos que talvez você precise copiar, confira [Determinando quais DLLs devem ser redistribuídas](../ide/determining-which-dlls-to-redistribute.md).  
  
3.  Execute o aplicativo MFC em um segundo computador que não tenha as bibliotecas do Visual C++.  
  
    1.  Copie o conteúdo da pasta \Release\ e cole-o na pasta do aplicativo no segundo computador.  
  
    2.  Execute o aplicativo no segundo computador.  
  
     O aplicativo é executado com êxito porque as bibliotecas do Visual C++ estão disponíveis na pasta local do aplicativo.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplos de implantação](../ide/deployment-examples.md)