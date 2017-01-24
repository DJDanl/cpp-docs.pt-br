---
title: "Suporte do assistente para outros idiomas | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.appwiz.EastAsianLanguages"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "suporte de idiomas para projetos MFC"
  - "projetos [C++], suporte de idiomas"
  - "assistentes [C++], suporte de idiomas"
ms.assetid: b653c673-0687-455c-885f-15d7e2f4149d
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Suporte do assistente para outros idiomas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando você instala o Visual Studio, o aplicativo de instalação detecta a localidade listada no seu sistema e instala os modelos de idioma apropriado para essa localidade.  Por exemplo, para localidades da Europa ocidentais, o programa de instalação instala inglês, francês, italiano, espanhol e alemão.  Esses idiomas aparecem a  **idioma de recurso** liste na  [Tipo de aplicativo](../Topic/Application%20Type,%20MFC%20Application%20Wizard.md) página do Assistente de aplicativo MFC.  
  
## Modelos de idioma  
 Nem todos os modelos são instalados em todos os sistemas, porque os modelos estão com a codificação ANSI de base, e nem todos os recursos podem ser editados em todos os sistemas.  Por exemplo, por padrão, você não pode editar recursos em japonês em um sistema francês.  
  
 Se você estiver usando o Windows 2000 ou posterior e você deseja criar um aplicativo MFC em outro idioma, você deve copiar o diretório de modelos para o idioma apropriado da mídia \(disco 1\) do instalador de Visual Studio ao seu sistema.  
  
> [!NOTE]
>  Para editar o projeto criado, você deve definir a localidade do sistema para a localidade apropriada para o idioma selecionado.  
  
 Os modelos são atribuídos a \\Microsoft Visual Studio uma pasta.NET 2003\\Vc7\\VCWizards\\mfcappwiz\\templates\\ directory, conforme listado na tabela a seguir.  Para acessar o modelo de idioma desejado, copie a pasta apropriada para o diretório \\mfcappwiz\\templates\\ no seu computador.  Depois que você copiou a pasta, o idioma aparecerá na  **idioma de recurso** liste na  **Tipo de aplicativo** página do Assistente de aplicativo MFC.  
  
### Modelos de idioma fornecidos no Visual Studio.NET  
  
|Linguagem|Modelo|  
|---------------|------------|  
|Chinês \(tradicional\)|1028|  
|Chinês \(Simplificado\)|2052|  
|Inglês|1033|  
|Francês|1036|  
|Alemão|1031|  
|Italiano|1040|  
|Japonês|1041|  
|Coreano|1042|  
|Espanhol|3082|  
  
## Formato dos arquivos de gerado pelo Assistente de C\+\+ Visual  
 Os assistentes do Visual C\+\+ irá gerar projetos em Unicode quando a versão de idioma instalado do Visual Studio não corresponde a localidade do sistema.  Por exemplo, quando a versão japonesa do Visual Studio é instalada em um computador que tenha as configurações regionais definidas para qualquer idioma diferente, por exemplo, japonês, os assistentes do Visual C\+\+ irá gerar projetos compostos de arquivos Unicode.  Isso é comum em computadores configurados com pacotes do Windows em vários idiomas \(MUI\).  
  
 Esse comportamento difere de sistemas configurar de modo que a localidade do sistema é o mesmo que a versão de idioma do Visual Studio.  Nesse caso, os arquivos de projeto serão criados em ANSI na página de código do sistema.  
  
## Consulte também  
 [Tipos de arquivo criados para projetos do Visual C\+\+](../ide/file-types-created-for-visual-cpp-projects.md)   
 [Criando e gerenciando projetos do Visual C\+\+](../ide/creating-and-managing-visual-cpp-projects.md)