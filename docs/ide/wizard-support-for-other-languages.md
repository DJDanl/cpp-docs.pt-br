---
title: Suporte do assistente para outros idiomas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- vc.appwiz.EastAsianLanguages
dev_langs:
- C++
helpviewer_keywords:
- wizards [C++], language support
- language support for MFC projects
- projects [C++], language support
ms.assetid: b653c673-0687-455c-885f-15d7e2f4149d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c33858e02fd8bad03e03a963e940f215d528157d
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46395114"
---
# <a name="wizard-support-for-other-languages"></a>Suporte do assistente para outros idiomas

Quando você instala o Visual Studio, o aplicativo de instalação detecta a localidade listada no sistema e instala os modelos de idioma apropriados para essa localidade. Por exemplo, para localidades na Europa Ocidental, a instalação instala o inglês, o francês, o italiano, o espanhol e o alemão. Esses idiomas são exibidos na lista **Idioma de recurso** da página [Tipo de Aplicativo](../mfc/reference/application-type-mfc-application-wizard.md) do Assistente de Aplicativo MFC.

## <a name="language-templates"></a>Modelos de idioma

Nem todos os modelos são instalados em todos os sistemas, porque eles se baseiam na codificação ANSI, e nem todos os recursos podem ser editados em todos os sistemas. Por exemplo, por padrão, não é possível editar recursos em japonês em um sistema em francês.

Caso você esteja usando o Windows 2000 ou posterior e deseje criar um aplicativo MFC em outro idioma, precisará copiar o diretório do modelo do idioma apropriado por meio da mídia do Instalador do Visual Studio (Disco 1) para o sistema.

> [!NOTE]
>  Para editar o projeto criado, é necessário definir a localidade do sistema com a localidade apropriada do idioma selecionado.

Cada um dos modelos recebe uma pasta no diretório \Microsoft Visual Studio .NET 2003\Vc7\VCWizards\mfcappwiz\templates\, conforme listado na tabela a seguir. Para acessar o modelo de idioma desejado, copie a pasta apropriada para o diretório \mfcappwiz\templates\ no computador. Depois que você copiar a pasta, o idioma será exibido na lista **Idioma de recurso** da página **Tipo de Aplicativo** do Assistente de Aplicativo MFC.

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

## <a name="format-of-visual-c-wizard-generated-files"></a>Formato dos arquivos gerados por Assistente do Visual C++

Os assistentes do Visual C++ gerarão projetos em Unicode quando a versão de idioma instalado do Visual Studio não corresponder à localidade do sistema. Por exemplo, quando a versão japonesa do Visual Studio é instalada em um computador que tem configurações regionais definidas com qualquer outro idioma exceto o japonês, os assistentes do Visual C++ gerarão projetos compostos por arquivos Unicode. Isso é comum em computadores configurados com MUI Packs (pacotes multilíngues do Windows).

Esse comportamento é diferente dos sistemas configurado de modo que a localidade do sistema é a mesma da versão de idioma do Visual Studio. Nesse caso, os arquivos de projeto serão criados em ANSI na página de código do sistema.

## <a name="see-also"></a>Consulte também

[Tipos de arquivo criados para projetos do Visual C++](../ide/file-types-created-for-visual-cpp-projects.md)<br>
[Criando e gerenciando projetos do Visual C++](../ide/creating-and-managing-visual-cpp-projects.md)