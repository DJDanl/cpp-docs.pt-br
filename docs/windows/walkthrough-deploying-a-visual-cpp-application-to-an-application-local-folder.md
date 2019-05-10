---
title: Implantar um aplicativo do Visual C++ em uma pasta local do aplicativo
ms.date: 04/23/2019
helpviewer_keywords:
- deploying Visual C++ applications
ms.assetid: 47a81c47-9dbe-47c6-96cc-fbb2fda5e6ad
ms.openlocfilehash: b05dcc47aa7c0b75943f0db69797b7bf6fb55df7
ms.sourcegitcommit: 18d3b1e9cdb4fc3a76f7a650c31994bdbd2bde64
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/29/2019
ms.locfileid: "64877331"
---
# <a name="walkthrough-deploying-a-visual-c-application-to-an-application-local-folder"></a>Passo a passo: Implantação de um aplicativo em Visual C++ em uma pasta do aplicativo local

Descreve como implantar um aplicativo do Visual C++ copiando arquivos para sua pasta.

## <a name="prerequisites"></a>Pré-requisitos

- Um computador que tenha o Visual Studio instalado.

- Outro computador que não tem as bibliotecas do Visual C++.

### <a name="to-deploy-an-application-to-an-application-local-folder"></a>Para implantar um aplicativo em uma pasta local do aplicativo

1. Criar e compilar um aplicativo do MFC, seguindo as etapas em [Passo a passo: Implantando um aplicativo em Visual C++ usando um projeto de instalação](walkthrough-deploying-a-visual-cpp-application-by-using-a-setup-project.md).

1. Copie os arquivos de biblioteca MFC e CRT (Tempo de Execução C) do diretório de instalação do Visual Studio na pasta \\VC\\redist\\*versão* e, em seguida, cole-os na pasta \Release\ do seu projeto MFC. Para obter mais informações sobre outros arquivos que talvez você precise copiar, confira [Determinando quais DLLs devem ser redistribuídas](determining-which-dlls-to-redistribute.md).

1. Execute o aplicativo MFC em um segundo computador que não tenha as bibliotecas do Visual C++.

   1. Copie o conteúdo da pasta \Release\ e cole-o na pasta do aplicativo no segundo computador.

   1. Execute o aplicativo no segundo computador.

   O aplicativo é executado com êxito porque as bibliotecas do Visual C++ estão disponíveis na pasta local do aplicativo.

## <a name="see-also"></a>Consulte também

[Exemplos de implantação](deployment-examples.md)<br/>
