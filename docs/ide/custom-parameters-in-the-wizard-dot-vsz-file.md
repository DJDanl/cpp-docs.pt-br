---
title: "Par&#226;metros personalizados no arquivo .Vsz do assistente | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Macro ABSOLUTE_PATH"
  - "assistentes personalizados, Arquivo .vsz"
  - "Macro HTML_FILTER"
  - "Macro HTML_PATH"
  - "Macro IMAGE_FILTER"
  - "Macro IMAGES_PATH"
  - "Macro MISC_FILTER"
  - "Macro PRODUCT"
  - "Macro PRODUCT_INSTALLATION_DIR"
  - "Macro PROJECT_TEMPLATE_NAME"
  - "Macro PROJECT_TEMPLATE_PATH"
  - "Macro RELATIVE_PATH"
  - "Macro SCRIPT_COMMON_PATH"
  - "Macro SCRIPT_FILTER"
  - "Macro SCRIPT_PATH"
  - "Macro START_PATH"
  - "Macro TEMPLATE_FILTER"
  - "Macro TEMPLATES_PATH"
  - "Macro WIZARD_NAME"
  - "Macro WIZARD_UI"
ms.assetid: 560dd5c0-7cff-4974-b856-5ca25b0669b8
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Par&#226;metros personalizados no arquivo .Vsz do assistente
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Suas duas primeiras linhas, o arquivo vsz identifica a versão do assistente e o ProgID ou CLSID do Assistente para ser cocreated.  O arquivo vsz também pode incluir parâmetros de contexto opcional e parâmetros personalizados que são adicionados para a tabela de símbolos \(juntamente com os símbolos fornecidos na seção símbolo HTML\).  
  
 O <xref:Microsoft.VisualStudio.VsWizard.VsWizardClass.Execute%2A> método exibe o assistente, que leva a uma matriz de parâmetros personalizados definidos no arquivo vsz como seus parâmetros e o contexto.  
  
 Os seguintes símbolos usados com freqüência são especificados como parâmetros personalizados em ambos os  [arquivo vsz](../ide/dot-vsz-file-project-control.md) ou arquivos. htm e pode ser usado em arquivos HTML, script ou modelo do assistente.  
  
## Exemplo  
 Como as seguintes entradas do arquivo vsz indicarem, o assistente chamado MyProjWiz contém uma interface do usuário.  
  
```  
VSWIZARD 7.0  
Wizard=VsWizard.VsWizardEngine  
Param="WIZARD_NAME = MyProjWiz"  
Param="WIZARD_UI = TRUE"  
```  
  
### Símbolos de parâmetros personalizados no vsz do Assistente para arquivo  
  
|Símbolo|Definição|  
|-------------|---------------|  
|ABSOLUTE\_PATH|O local dos arquivos do assistente.|  
|HTML\_FILTER|Especificado no arquivo vsz.  Tipos de arquivos que são colocados na pasta arquivos HTML no  **Solution Explorer**.  Geralmente é especificado como "htm".|  
|HTML\_PATH|Especificado no arquivo vsz.  O local do Assistente de  [arquivos HTML](../ide/html-files.md).  Por padrão, ele é START\_PATH\\HTML\\*idioma* \(onde  *idioma* é a localidade especificada pelo registro do sistema\). **Note:**  Você pode especificar um idioma diferente, definindo a \<LangID\> Para obter o valor decimal de HKEY\_CURRENT\_USER\\Software\\Microsoft\\VisualStudio\\7.0\\General\\UILanguage.  Consulte  [a localização de um Assistente para vários idiomas](../ide/localizing-a-wizard-to-multiple-languages.md) para obter mais informações.  Para obter uma lista de valores decimais de idioma, consulte  [Assistente de suporte para outros idiomas](../ide/wizard-support-for-other-languages.md).|  
|IMAGE\_FILTER|Especificado no arquivo vsz.  Tipos de arquivos que são colocados na pasta arquivos de imagem no Solution Explorer.  Geralmente é especificado como "bmp; gif".|  
|IMAGES\_PATH|Especificado no arquivo vsz.  O local dos arquivos de imagem usados nos arquivos html.  Por padrão, ele é START\_PATH\\Images.|  
|MISC\_FILTER|Especificado no arquivo vsz.  Tipos de arquivos que são colocados na pasta diverso no Solution Explorer.  Geralmente é especificado como "vsz; vsdir; ico; vcproj; csproj; css; inf".|  
|PRODUTO|Por padrão, definido como o Visual C\+\+. No entanto, você pode definir esse valor para Visual Basic para criar os assistentes de Visual Basic e assim por diante.|  
|PRODUCT\_INSTALLATION\_DIR|O diretório listado no registro em HKEY\_LOCAL\_MACHINE\\SOFTWARE\\Microsoft\\VisualStudio\\7.0\\Setup\\ \<Product\> \\ ProductDir.|  
|PROJECT\_TEMPLATE\_NAME|Especificado no arquivo vsz.  O arquivo de modelo de projeto pelo seu assistente para criar projetos.  Geralmente é especificado como "txt".|  
|PROJECT\_TEMPLATE\_PATH|O diretório que contém o projeto  [arquivos de modelo](../ide/template-files.md).  Para Visual C\+\+, ele é PRODUCT\_INSTALLATION\_DIR\\VCWizards, por padrão.|  
|RELATIVE\_PATH|Se ABSOLUTE\_PATH não for encontrado, é considerado o RELATIVE\_PATH.  Este é o caminho relativo para o PRODUCT\_INSTALLATION\_DIR.  Para Visual C\+\+, o RELATIVE\_PATH é PRODUCT\_INSTALLATION\_DIR\\VCWizards.|  
|SCRIPT\_COMMON\_PATH|O nome do diretório em relação ao PRODUCT\_INSTALLATION\_DIR, onde se encontra o arquivo de script comuns.  Por exemplo, para Visual C\+\+, isso é VCWizards.|  
|SCRIPT\_FILTER|Especificado no arquivo vsz.  Tipos de arquivo ser colocados na pasta arquivos de Script no Solution Explorer.  Geralmente é especificado como "js" \(JScript\) ou "vbs" \(VBScript\).|  
|SCRIPT\_PATH|O local do Assistente de  [o arquivo de JScript](../ide/jscript-file.md).  Por padrão, ele é START\_PATH\\Scripts|  
|START\_PATH|Especificado no arquivo vsz.  Isso não é definido pelo usuário, mas usado internamente para identificar o RELATIVE\_PATH ou ABSOLUTE\_PATH.  O nome do assistente \(WIZARD\_NAME\) é anexado a este valor.|  
|TEMPLATE\_FILTER|Especificado no arquivo vsz.  Tipos de arquivos que são colocados na pasta arquivos de modelo no Solution Explorer.  Geralmente é especificado como "txt".|  
|TEMPLATES\_PATH|Especificado no arquivo vsz.  O local dos arquivos de modelo do assistente.  Por padrão, ele é START\_PATH\\Templates\\ \<LangID\>. **Note:**  Consulte HTML\_PATH para obter mais informações sobre o LangID.|  
|WIZARD\_NAME|Especifica o nome do assistente.  Localizada no vsz e usada pelo restante dos símbolos.|  
|WIZARD\_UI|Especificado no arquivo vsz.  Um valor booleano que indica se o assistente contém uma interface do usuário.  Especificar  **TRUE**  para uma interface de usuário ou  **FALSE**  para nenhuma interface do usuário.|  
  
## Consulte também  
 <xref:EnvDTE.IDTWizard.Execute%2A>   
 [Arquivos criados para o assistente](../ide/files-created-for-your-wizard.md)   
 [Assistente Personalizado](../ide/custom-wizard.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Projetando um assistente](../ide/designing-a-wizard.md)