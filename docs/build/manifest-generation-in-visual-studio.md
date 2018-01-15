---
title: "Geração de manifesto no Visual Studio | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: manifests [C++]
ms.assetid: 0af60aa9-d223-42cd-8426-b3fc543a2a81
caps.latest.revision: "14"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 3d701d73103ee2c5ac72eb36d9919132f0578b1b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="manifest-generation-in-visual-studio"></a>Geração de manifesto no Visual Studio
Geração de um arquivo de manifesto para um projeto específico pode ser controlada no projeto **páginas de propriedade** caixa de diálogo. No **propriedades de configuração** , clique em **vinculador**, em seguida, **o arquivo de manifesto**, em seguida, **gerar manifesto**. Por padrão, as propriedades do projeto de novos projetos são definidas para gerar um arquivo de manifesto. No entanto é possível desabilitar a geração de manifesto para um projeto usando o **gerar manifesto** propriedade do projeto. Quando essa propriedade é definida como **Sim**, o manifesto para este projeto é gerado. Caso contrário, o vinculador ignora informações do assembly ao resolver dependências de código do aplicativo e não gera o manifesto.  
  
 O sistema de compilação no Visual Studio permite que o manifesto a ser inserida no arquivo binário final do aplicativo ou gerados como um arquivo externo. Esse comportamento é controlado pelo **Inserir manifesto** opção o **propriedades do projeto** caixa de diálogo. Para definir essa propriedade, abra o **ferramenta de manifesto** nó, em seguida, selecione **de entrada e saída**. Se o manifesto não é inserido, ele é gerado como um arquivo externo e salvo no mesmo diretório que o binário final. Se o manifesto é inserido, o Visual Studio insere os manifestos finais usando o seguinte processo:  
  
1.  Depois que o código-fonte é compilado em arquivos de objeto, o vinculador coleta informações de assembly dependente. Ao vincular o binário final, o vinculador gera um manifesto intermediário que é usado posteriormente para gerar o manifesto final.  
  
2.  Depois de terminar intermediário manifesto e vinculação, a ferramenta de manifesto será executada para mesclar um manifesto final e salvá-lo como um arquivo externo.  
  
3.  O projeto do sistema de compilação e detecta se o manifesto gerado pela ferramenta de manifesto contém informações diferentes de manifesto já inserido no binário.  
  
4.  Se o manifesto inserido no binário é diferente do manifesto gerado pela ferramenta de manifesto, ou o binário não contém um manifesto inserido, o Visual Studio invocará o vinculador mais uma vez para inserir o arquivo de manifesto externo dentro do binário como um recurso.  
  
5.  Se o manifesto inserido no binário é o mesmo que o manifesto gerado pela ferramenta de manifesto, a compilação continuará para as próximas etapas de compilação.  
  
 O manifesto é inserido no binário final como um recurso de texto e pode ser exibido, abrindo o binário final como um arquivo no Visual Studio. Para garantir que o manifesto aponta para as bibliotecas corretas, siga as etapas descritas em [Noções básicas sobre as dependências de um aplicativo do Visual C++](../ide/understanding-the-dependencies-of-a-visual-cpp-application.md) ou siga as sugestões descritas o [desoluçãodeproblemas](../build/troubleshooting-c-cpp-isolated-applications-and-side-by-side-assemblies.md) seção.  
  
## <a name="see-also"></a>Consulte também  
 [Como: inserir um manifesto dentro de um aplicativo C/C++](../build/how-to-embed-a-manifest-inside-a-c-cpp-application.md)   
 [Sobre Assemblies privada](http://msdn.microsoft.com/library/ff951638)   
 [Ferramenta de manifesto](http://msdn.microsoft.com/library/aa375649)   
 [Noções básicas sobre o Manifest Generation para programas do C/C++](../build/understanding-manifest-generation-for-c-cpp-programs.md)