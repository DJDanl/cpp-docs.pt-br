---
title: "Tornando um objeto ATL n&#227;o cri&#225;vel | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "vc.appwiz.ATL.objects"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "projetos ATL, objetos não criáveis"
  - "objetos ATL não criáveis"
ms.assetid: 80d0bca2-dea0-4801-9a85-6243124437f6
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Tornando um objeto ATL n&#227;o cri&#225;vel
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Você pode alterar os atributos de um objeto COM base ATL\- para que um cliente não pode diretamente criar o objeto.  Em esse caso, o objeto deve ser retornado chama um método com outro objeto em vez de diretamente criado.  
  
### para fazer um objeto noncreatable  
  
1.  Remova [OBJECT\_ENTRY\_AUTO](../Topic/OBJECT_ENTRY_AUTO.md) para o objeto.  Se você desejar que o objeto para ser noncreatable mas o controle a ser registrado, substitua OBJECT\_ENTRY\_AUTO com [OBJECT\_ENTRY\_NON\_CREATEABLE\_EX\_AUTO](../Topic/OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO.md).  
  
2.  Adicione o atributo de [noncreatable](../../windows/noncreatable.md) a coclass no arquivo de .idl.  Por exemplo:  
  
    ```  
    [  
       uuid(A1992E3D-3CF0-11D0-826F-00A0C90F2851),  
       helpstring("MyObject"),  
      noncreatable  
    ]  
    coclass MyObject  
    {  
       [default] interface IMyInterface;  
    }  
    ```  
  
## Consulte também  
 [Assistente de Projeto ATL](../Topic/ATL%20Project%20Wizard.md)   
 [Tipos de projeto do Visual C\+\+](../../ide/visual-cpp-project-types.md)   
 [Criando projetos para desktop com Assistentes de Aplicativo](../../ide/creating-desktop-projects-by-using-application-wizards.md)   
 [Programando com código de tempo de execução ATL e C](../../atl/programming-with-atl-and-c-run-time-code.md)   
 [Fundamentos de objetos COM de ATL](../../atl/fundamentals-of-atl-com-objects.md)   
 [Configurações padrão do projeto ATL](../../atl/reference/default-atl-project-configurations.md)