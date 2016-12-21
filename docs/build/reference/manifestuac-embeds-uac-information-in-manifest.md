---
title: "/MANIFESTUAC (insere informa&#231;&#245;es UAC no manifesto) | Microsoft Docs"
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
  - "VC.Project.VCLinkerTool.UACUIAccess"
  - "VC.Project.VCLinkerTool.UACExecutionLevel"
  - "VC.Project.VCLinkerTool.EnableUAC"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /MANIFESTUAC"
  - "opção de vinculador MANIFESTUAC"
  - "opção de vinculador -MANIFESTUAC"
ms.assetid: 2d243c39-fa13-493c-b56f-d0d972a1603a
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /MANIFESTUAC (insere informa&#231;&#245;es UAC no manifesto)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica se as informações do Controle de Conta de Usuário \(UAC\) estão inseridas no manifesto do programa.  
  
## Sintaxe  
  
```  
/MANIFESTUAC  
/MANIFESTUAC:NO  
/MANIFESTUAC:fragment  
/MANIFESTUAC:level=_level  
/MANIFESTUAC:uiAccess=_uiAccess  
```  
  
#### Parâmetros  
 `fragment`  
 Uma cadeia de caracteres que contém os valores de `level` e de `uiAccess` .  Para obter mais informações, consulte secionam que os comentários posteriormente neste tópico.  
  
 `_level`  
 Um *de asInvoker*, *highestAvailable*, ou *de requireAdministrator*.  Opções ao asInvoker.  Para obter mais informações, consulte secionam que os comentários posteriormente neste tópico.  
  
 `_uiAccess`  
 `true` se você quiser que o aplicativo ignorar níveis de proteção da interface do usuário e orientar a entrada para as janelas de alta permissão na área de trabalho; caso contrário, `false`.  O padrão é `false`.  Definir a `true` apenas para aplicativos de acessibilidade da interface do usuário.  
  
## Comentários  
 Se você especificar várias opções do \/MANIFESTUAC na linha de comando, a última inscrita terá precedência.  
  
 As opções de \/MANIFESTUAC:level são os seguintes:  
  
-   `asInvoker`: O aplicativo será executado com as mesmas permissões que o processo que o foi iniciado.  O aplicativo pode ser promovido a um nível de permissão superior **Executar como administrador**selecionando.  
  
-   highestAvailable: O aplicativo será executado com o nível de permissão do mais alto que possível.  Se o usuário que inicia o aplicativo é um membro do grupo administradores, essa opção é igual ao requireAdministrator.  Se o nível de permissão disponível o mais alto é mais alto que o nível do processo de abertura, o sistema solicitará credenciais.  
  
-   requireAdministrator: O aplicativo será executado com permissões de administrador.  O usuário que inicia o aplicativo deve ser um membro do grupo administradores.  Se o processo de abertura não estiver executando o com permissões administrativas, o sistema solicitará credenciais.  
  
 Você pode especificar o nível e os valores de uiAccess em uma etapa usando a opção de \/MANIFESTUAC:fragment .  O fragmento deve estar no seguinte formato:  
  
```  
"level=[ asInvoker | highestAvailable | requireAdministrator ] uiAccess=[ true | false ]"  
```  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Expanda o nó **Propriedades de Configuração**.  
  
3.  Expanda o nó **Vinculador**.  
  
4.  Selecione a página de propriedades de **Arquivo de Manifesto** .  
  
5.  Modifique **Habilitar Controle de Conta de Usuário \(UAC\)**, **Nível de Execução UAC**, e as propriedades de **Proteção de IU de Desvio de UAC** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.EnableUAC%2A>, <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.UACExecutionLevel%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.UACUIAccess%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)