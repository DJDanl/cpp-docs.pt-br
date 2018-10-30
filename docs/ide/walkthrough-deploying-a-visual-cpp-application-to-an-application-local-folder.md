---
title: Implantar um aplicativo do Visual C++ em uma pasta local do aplicativo | Microsoft Docs
ms.custom: ''
ms.date: 09/17/2018
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
ms.openlocfilehash: 3db193c0537869e4b99bc4c0c94cc79c70f5e827
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50060657"
---
# <a name="walkthrough-deploying-a-visual-c-application-to-an-application-local-folder"></a>Instruções passo a passo: implantando um aplicativo do Visual C++ em uma pasta local do aplicativo

Descreve como implantar um aplicativo do Visual C++ copiando arquivos para sua pasta.

## <a name="prerequisites"></a>Pré-requisitos

- Um computador que tenha o Visual Studio instalado.

- Outro computador que não tem as bibliotecas do Visual C++.

### <a name="to-deploy-an-application-to-an-application-local-folder"></a>Para implantar um aplicativo em uma pasta local do aplicativo

1. Crie e compile um aplicativo MFC seguindo as etapas de [Passo a passo: Implantando um aplicativo do Visual C++ usando um projeto de instalação](walkthrough-deploying-a-visual-cpp-application-by-using-a-setup-project.md).

1. Copie os arquivos de biblioteca MFC e CRT (Tempo de Execução C) do diretório de instalação do Visual Studio na pasta \\VC\\redist\\*versão* e, em seguida, cole-os na pasta \Release\ do seu projeto MFC. Para obter mais informações sobre outros arquivos que talvez você precise copiar, confira [Determinando quais DLLs devem ser redistribuídas](determining-which-dlls-to-redistribute.md).

1. Execute o aplicativo MFC em um segundo computador que não tenha as bibliotecas do Visual C++.

   1. Copie o conteúdo da pasta \Release\ e cole-o na pasta do aplicativo no segundo computador.

   1. Execute o aplicativo no segundo computador.

   O aplicativo é executado com êxito porque as bibliotecas do Visual C++ estão disponíveis na pasta local do aplicativo.

## <a name="see-also"></a>Consulte também

[Exemplos de implantação](deployment-examples.md)<br/>
