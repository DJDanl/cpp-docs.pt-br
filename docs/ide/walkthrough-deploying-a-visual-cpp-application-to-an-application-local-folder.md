---
title: Implantar um aplicativo do Visual C++ para uma pasta local do aplicativo | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: deploying Visual C++ applications
ms.assetid: 47a81c47-9dbe-47c6-96cc-fbb2fda5e6ad
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: ba12271fa4614b5ec0c7c70b3a7773152ebfec3c
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="walkthrough-deploying-a-visual-c-application-to-an-application-local-folder"></a>Instruções passo a passo: implantando um aplicativo do Visual C++ em uma pasta local do aplicativo
Descreve como implantar um aplicativo do Visual C++, copiando arquivos para a sua pasta.  
  
## <a name="prerequisites"></a>Pré-requisitos  
  
-   Um computador que tenha instalado o Visual Studio.  
  
-   Outro computador que não tenha as bibliotecas do Visual C++.  
  
### <a name="to-deploy-an-application-to-an-application-local-folder"></a>Para implantar um aplicativo para uma pasta local do aplicativo  
  
1.  Criar e compilar um aplicativo MFC, seguindo as etapas em [passo a passo: Implantando um Visual C++ aplicativo usando um projeto de instalação](../ide/walkthrough-deploying-a-visual-cpp-application-by-using-a-setup-project.md).  
  
2.  Copie os arquivos adequados da biblioteca MFC e C Run-Time (CRT) — por exemplo, para uma arquitetura x86 plataforma e suporte a Unicode, cópia mfc100u.dll e msvcr100.dll de \Program Files\Microsoft Visual Studio 10.0\VC\redist\x86\—and, em seguida, colagem-os na pasta \Release\ do seu projeto MFC. Para obter mais informações sobre outros arquivos que você terá que copiar, consulte [determinando quais DLLs devem ser redistribuídas](../ide/determining-which-dlls-to-redistribute.md).  
  
3.  Execute o aplicativo do MFC em um segundo computador que não tenha as bibliotecas do Visual C++.  
  
    1.  Copie o conteúdo da pasta \Release\ e colá-los na pasta do aplicativo no segundo computador.  
  
    2.  Execute o aplicativo no segundo computador.  
  
     O aplicativo é executado com êxito porque as bibliotecas do Visual C++ estão disponíveis na pasta local do aplicativo.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplos de implantação](../ide/deployment-examples.md)