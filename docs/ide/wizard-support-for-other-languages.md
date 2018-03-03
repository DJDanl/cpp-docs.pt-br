---
title: Assistente de suporte para outros idiomas | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.appwiz.EastAsianLanguages
dev_langs:
- C++
helpviewer_keywords:
- wizards [C++], language support
- language support for MFC projects
- projects [C++], language support
ms.assetid: b653c673-0687-455c-885f-15d7e2f4149d
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8ef95c252621aa7f725098dfcd08c7b5b3620826
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="wizard-support-for-other-languages"></a>Suporte do assistente para outros idiomas
Quando você instala o Visual Studio, o aplicativo de instalação detecta a localidade listada no seu sistema e instala os modelos para essa localidade ou um modelo de idioma apropriado. Por exemplo, para localidades europeus ocidentais, a instalação instala o inglês, francês, italiano, espanhol e alemão. Esses idiomas aparecem no **idioma de recurso** lista o [tipo de aplicativo](../mfc/reference/application-type-mfc-application-wizard.md) página do Assistente de aplicativo MFC.  
  
## <a name="language-templates"></a>Modelos de idioma  
 Nem todos os modelos são instalados em todos os sistemas, porque os modelos são com ANSI codificação de base, e nem todos os recursos podem ser editados em todos os sistemas. Por exemplo, por padrão, você não pode editar recursos japonês em um sistema em francês.  
  
 Se você estiver usando o Windows 2000 ou posterior e você deseja criar um aplicativo MFC em outro idioma, você deve copiar o diretório do modelo para o idioma apropriado da mídia de instalação do Visual Studio (disco 1) para o seu sistema.  
  
> [!NOTE]
>  Para editar o projeto criado, você deve definir a localidade do sistema para a localidade apropriada para o idioma selecionado.  
  
 Os modelos são que cada atribuído a uma pasta no diretório \Microsoft 2003\Vc7\VCWizards\mfcappwiz\templates\ do Visual Studio .NET, conforme listado na tabela a seguir. Para acessar o modelo de idioma desejado, copie a pasta apropriada para o diretório \mfcappwiz\templates\ em seu computador. Depois que você copiou a pasta, o idioma será exibida no **idioma de recurso** lista o **tipo de aplicativo** página do Assistente de aplicativo MFC.  
  
### <a name="language-templates-provided-in-visual-studio-net"></a>Modelos de idioma fornecidos no Visual Studio .NET  
  
|Idioma|Modelo|  
|--------------|--------------|  
|Chinês (tradicional)|1028|  
|Chinês (simplificado)|2052|  
|Inglês|1033|  
|Francês|1036|  
|Alemão|1031|  
|Italiano|1040|  
|Japonês|1041|  
|Coreano|1042|  
|Espanhol|3082|  
  
## <a name="format-of-visual-c-wizard-generated-files"></a>Formato de arquivos Visual gerado pelo Assistente de C++  
 Os assistentes do Visual C++ irá gerar projetos em Unicode quando a versão de idioma do Visual Studio não coincide com a localidade do sistema. Por exemplo, quando a versão japonesa do Visual Studio é instalada em um computador que tem configurações regionais definidas como qualquer outro idioma exceto japonês, os assistentes do Visual C++ irá gerar projetos compostos de arquivos Unicode. Isso é comum em computadores configurados com pacotes do Windows multilíngues (MUI).  
  
 Esse comportamento difere dos sistemas configurar, de modo que a localidade do sistema é o mesmo que a versão de idioma do Visual Studio. Nesse caso, os arquivos de projeto serão criados em ANSI na página de código do sistema.  
  
## <a name="see-also"></a>Consulte também  
 [Tipos de arquivo criados para projetos do Visual C++](../ide/file-types-created-for-visual-cpp-projects.md)   
 [Criando e gerenciando projetos do Visual C++](../ide/creating-and-managing-visual-cpp-projects.md)