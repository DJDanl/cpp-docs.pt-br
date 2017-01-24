---
title: "Arquivo .Vsz (controle do projeto) | Microsoft Docs"
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
  - "Arquivos .vsz"
  - "assistentes personalizados, Arquivo .vsz"
  - "assistentes personalizados, arquivos de controle de projeto"
  - "Arquivos  [C++], criado por Assistente Personalizado"
  - "arquivos vsz"
ms.assetid: b8678fee-6795-46d1-9338-48b22d5e9207
caps.latest.revision: 12
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Arquivo .Vsz (controle do projeto)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O ponto de partida de cada assistente é o arquivo vsz.  O arquivo vsz é um arquivo de texto que determina o Assistente para ser chamado e as informações para passar para o assistente.  O arquivo contém um cabeçalho de duas linhas, seguido por vários parâmetros opcionais a serem passados para o assistente.  Para obter uma lista de parâmetros opcionais, consulte  [Predefinidos símbolos de assistente personalizada](../ide/custom-parameters-in-the-wizard-dot-vsz-file.md).  
  
 O exemplo a seguir mostra o cabeçalho em um arquivo vsz:  
  
```  
VSWIZARD 7.0  
Wizard=VsWizard.VsWizardEngine.10.0  
Param="WIZARD_NAME = My AppWizard"  
```  
  
-   A primeira linha do cabeçalho Especifica o número de versão do formato de arquivo de modelo.  Você pode especificar esse número como `6.0`, `7.0`, ou `7.1`.  Não há outros números são válidos e usando outros números resulta em um erro de "Formato inválido".  
  
-   Os conjuntos de linha segundo o  **Assistente** variável para o ProgID do assistente que é cocreated por Visual Studio.  Um ProgID é uma representação de seqüência de caracteres de um CLSID, como `VsWizard.VsWizardEngine.10.0`.  
  
     Se seu assistente tem uma interface de usuário, o ProgID especifica automaticamente o seu assistente para implementar <xref:Microsoft.VisualStudio.VsWizard.IVCWizCtlUI>.  Por padrão, os métodos dessa interface são usados na  [arquivos. htm](../ide/html-files.md) do seu projeto.  Você pode alterar o comportamento do seu assistente usando os métodos para esta interface nos arquivos. htm.  Consulte <xref:Microsoft.VisualStudio.VsWizard.VCWizCtl> para obter mais informações, que é o coclass para <xref:Microsoft.VisualStudio.VsWizard.IVCWizCtlUI>.  
  
-   Estas duas linhas a seguir é uma lista opcional de parâmetros que permitem que o arquivo vsz passar parâmetros personalizados adicionais para o assistente.  Cada valor é passado como um elemento da seqüência de caracteres em uma matriz de variantes do controle wizard <xref:Microsoft.VisualStudio.VsWizard.VsWizardClass.Execute%2A> método.  Por padrão, um assistente com uma interface de usuário produz os seguintes parâmetros de padrão:  
  
    ```  
    Param="START_PATH = <path to the wizard>"  
    Param="HTML_PATH = <path to the wizard's HTML file>"  
    Param="TEMPLATES_PATH = <path to the wizard's template file>"  
    Param="SCRIPT_PATH = <path to the wizard's script files>"  
    Param="IMAGES_PATH = <path to the wizard's images>"  
    ```  
  
     Se o assistente não tem uma interface de usuário, ele não tem um `IMAGES_PATH` parâmetro e em vez disso, contém os seguintes parâmetros:  
  
    ```  
    Param="WIZARD_UI = FALSE"  
    Param="SOURCE_FILTER = txt"  
    ```  
  
-   O arquivo vsz pode conter os seguintes parâmetros, especifique as funções encontradas na  [Common.js](../ide/customizing-cpp-wizards-with-common-jscript-functions.md) arquivo:  
  
    ```  
    Param="PREPROCESS_FUNCTION = CanAddATLClass"  
    Param="PREPROCESS_FUNCTION = CanAddMFCClass"  
    Param="PREPROCESS_FUNCTION = CanAddClass"  
    ```  
  
 As funções  [CanAddATLClass](../ide/canaddatlclass.md),  [CanAddMFCClass](../ide/canaddmfcclass.md), e  [CanAddClass](../ide/canaddclass.md) são chamados pelo Assistente para confirmar que o  [Modelo de código do Visual C\+\+](http://msdn.microsoft.com/pt-br/dd6452c2-1054-44a1-b0eb-639a94a1216b) está disponível.  Se uma função retorna  **false**, o assistente não é iniciado.  
  
 Você pode adicionar seu assistente para o painel de modelos na  **Novo projeto** caixa de diálogo no Visual Studio, colocando o arquivo vsz no diretório vcprojects.  Por padrão, o assistente personalizada grava o arquivo vsz nesse diretório.  
  
> [!NOTE]
>  Se você excluir os arquivos do assistente e diretórios, você também deve excluir o arquivo vsz do projeto, o arquivo de .vsdir e arquivo. ico do diretório vcprojects.  
  
## Consulte também  
 [Arquivos criados para o assistente](../ide/files-created-for-your-wizard.md)   
 [Assistente Personalizado](../ide/custom-wizard.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Visual C\+\+ Wizard Model](http://msdn.microsoft.com/pt-br/159395ac-33c7-47bf-ad42-4e1435ddc758)   
 [Adding Wizards to the Add Item and New Project Dialog Boxes by Using .Vsdir Files](../Topic/Adding%20Wizards%20to%20the%20Add%20Item%20and%20New%20Project%20Dialog%20Boxes%20by%20Using%20.Vsdir%20Files.md)   
 [Projetando um assistente](../ide/designing-a-wizard.md)