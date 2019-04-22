---
title: Implantar um aplicativo do Visual C++ em uma pasta local do aplicativo
ms.date: 09/17/2018
helpviewer_keywords:
- deploying Visual C++ applications
ms.assetid: 47a81c47-9dbe-47c6-96cc-fbb2fda5e6ad
ms.openlocfilehash: 33edf4bb736fad62928e11dd0550af6640d411ac
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58786109"
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
